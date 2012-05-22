/*
 * Interface de la clase NodoHoja, que hereda de Nodo
 *
 *  Created on: 21/05/2012
 *      Author: ezequiel
 */

#ifndef NODOHOJA_H_
#define NODOHOJA_H_

#include "Nodo.h"
#include "Clave.h"

class NodoHoja: public Nodo {
private:
	/* El atributo estatico especifica cuantas claves se pueden almacenar dentro
	 * del NodoHoja.
	 * Se usará el valor 2 para probar el funcionamiento del arbol.
	 * Luego especificamos un valor correcto.
	 */
	const static int cantClaves = 2;

	Clave** listaClaves;

public:
	/*
	 * Constructor de la clase NodoHoja
	 * Inicializa la lista con capacidad para 2 claves, pero la deja vacía.
	 */
	NodoHoja();

	/*
	 * Constructor de la clase NodoHoja
	 * Inicializa la lista con capacidad para 2 claves y almacena la que recibe por parametro.
	 */
	NodoHoja(Clave *clave);

	/*
	 * Destructor de la clase NodoHoja. Debe liberar la memoria de la lista de claves.
	 */
	virtual ~NodoHoja();

	/*
	 * Metodo para verificar si el nodo contiene la clave que se le pasa por parametro
	 */
	bool contiene(Clave clave);

	/*
	 * Metodo de inserccion de clave. Los valores de retorno son:
	 * 		1: el nodo se actualizó
	 * 		2: el nodo se desbordó
	 * 		3: el nodo ya tiene la clave que se desea insertar
	 */
	int insertar(Clave clave);

	/*
	 * Metodo de eliminacion de clave. Los valores de retorno son:
	 * 		1: el nodo se actualizó
	 * 		2: el nodo quedó con subflujo
	 * 		3: no existe la clave que se quiere eliminar
	 */
	int eliminar(Clave clave);

	/*
	 * Metodo que devuelve el campo que se encuentra en el medio (o el derecho, en caso
	 * de cantidad par de Claves
	 * ATENCION: Devuelve la direccion de memoria del campo, pero el NodoInterno debe realizar
	 * una copia de su contenido para almacenarlo como atributo, para que sea persistente
	 * en el tiempo el dato almacenado en el NodoInterno
	 */
	Campo* getValorMedio(int dimension) const;

private:
	/*
	 * Metodo privado que ordena las claves del Nodo según la dimension con la que se
	 * quiere ordenar.
	 */
	void ordenarListaClaves(int dimension);

};

#endif /* NODOHOJA_H_ */
