/*
 * Interface de la clase NodoHoja, que hereda de Nodo
 *
 *  Created on: 21/05/2012
 *      Author: ezequiel
 */

#ifndef NODOHOJA_H_
#define NODOHOJA_H_

#include "kdNodo.h"
#include "Clave.h"
#include "campo/ResultadoComparacion.h"

using namespace comparacion;

class kdNodoHoja: public kdNodo {
private:
	/* El atributo estatico especifica cuantas claves se pueden almacenar dentro
	 * del NodoHoja.
	 * Se usará el valor 2 para probar el funcionamiento del arbol.
	 * Luego especificamos un valor correcto.
	 */
	int cantClaves;	// Almacena la cantidad de claves que contiene el nodo
	Clave** listaClaves; // Contenedor de las claves

public:
	const static int capacidadNodo = 2; // Define el tamaño del nodo
	/*
	 * Constructor de la clase NodoHoja
	 * Inicializa la lista con capacidad para 2 claves, pero la deja vacía.
	 */
	kdNodoHoja();

	/*
	 * Constructor de la clase NodoHoja
	 * Inicializa la lista con capacidad para 2 claves y almacena la que recibe por parametro.
	 */
	kdNodoHoja(Clave clave);

	/*
	 * Destructor de la clase NodoHoja. Debe liberar la memoria de la lista de claves.
	 */
	virtual ~kdNodoHoja();

	/*
	 * Función que devuelve si el nodo es hoja, que devuelve verdadero por defecto
	 */
	virtual bool esHoja();

	/*
	 * Metodo para verificar si el nodo contiene la clave que se le pasa por parametro
	 */
	bool contiene(const Clave clave);

	/*
	 * Metodo de inserccion de clave. Los valores de retorno son:
	 * 		0: el nodo no se actualizó (puede que esté con sobreflujo y no fue solucionado anteriormente)
	 * 		1: el nodo se actualizó
	 * 		2: el nodo se desbordó
	 * 		3: el nodo ya tiene la clave que se desea insertar
	 *
	 * 	Cuando se desborda, la clave es almacenada en un lugar extra para que el padre
	 * 	pida obtener el valor medio y obtener ordenadamente cada clave para poder dividirlo
	 * 	facilmente.
	 */
	int insertar(Clave clave);

	/*
	 * Metodo de eliminacion de clave. Los valores de retorno son:
	 * 		1: el nodo se actualizó
	 * 		2: el nodo quedó con subflujo
	 * 		3: no existe la clave que se quiere eliminar
	 */
	int eliminar(const Clave clave);

	/* Funcion booleana para conocer el estado de sobreflujo del nodo hoja.
	 * El nodo tiene SOBREFLUJO cuando la cantidad de claves almacenadas
	 * excede a la capacidad del nodo.
	 */
	bool tieneSobreflujo();

	/* Funcion booleana para conocer el estado de subflujo del nodo hoja.
	 * El nodo tiene SUBFLUJO cuando la cantidad de claves almacenadas
	 * es menor que la mitad de la capacidad maxima del nodo.
	 */
	bool tieneSubflujo();

	/* Metodo que solo devuelve un campo válido si el nodo se encuentra desbordado
	 * Metodo que devuelve el campo que se encuentra en el medio (o el derecho, en caso
	 * de cantidad par de Claves
	 * ATENCION: Devuelve la direccion de memoria del campo, pero el NodoInterno debe realizar
	 * una copia de su contenido para almacenarlo como atributo, para que sea persistente
	 * en el tiempo el dato almacenado en el NodoInterno
	 */
	Campo* getValorMedio(int dimension);

	Clave* getClave(int i);

	Clave* getClave(Clave clave);

private:
	/*
	 * Metodo privado que ordena las claves del Nodo según la dimension con la que se
	 * quiere ordenar.
	 */
	void ordenarListaClaves(int dimension);

	void swap (int i, int j);

	void restablecerZonaDesborde();

};

#endif /* NODOHOJA_H_ */
