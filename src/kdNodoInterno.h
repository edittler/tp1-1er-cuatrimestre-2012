/*
 * Interface de la clase NodoInterno, que hereda de Nodo
 *
 *  Created on: 12/05/2012
 *      Author: ezequiel
 */

#ifndef NODOINTERNO_H_
#define NODOINTERNO_H_

#include "kdNodo.h"
#include "Clave.h"

class kdNodoInterno: public kdNodo {
/*
 * Atributos privados de la clase
 */
private:
	Campo* atributo;
	kdNodo* hijoIzq;
	kdNodo* hijoDer;
	int posBloqueIzq;
	int posBloqueDer;
	bool hijoIzqEsHoja;
	bool hijoDerEsHoja;

public:
	/* Constructor de la clase NodoInterno
	 * Inicializa todos sus atributos en null
	 */
	kdNodoInterno();

	/* Constructor de la clase NodoInterno
	 * Inicializa con el atributo que recibe por parámetro y los los demas en NULL
	 */
	kdNodoInterno(Campo* atributo);

	/* Constructor de la clase NodoInterno
	 * Inicializa todos sus atributos con los argumentos recibidos por parámtetros.
	 */
	kdNodoInterno(Campo* atributo, kdNodo* hijoIzq, kdNodo* hijoDer);

	/* Destructor de la clase NodoInterno
	 * Debe eliminar la memoria reservada por los punteros y establecerlos como NULL
	 * Si los nodos hijos de este nodo se van a seguir usando, previo a la destruccion del
	 * objeto, se deben establecer como NULL los hijos de este nodo para no cometer
	 * liberaciones de memoria erroneas.
	 */
	virtual ~kdNodoInterno();

	/*
	 * Función que devuelve si el nodo es hoja, que devuelve falso por defecto
	 */
	virtual bool esHoja();

	/* Retorna el atributo que identifica al nodo
	 */
	Campo* getAtributo() const;

	/* Modifica el atributo del nodo, estableciendo el que recibe por parámetro.
	 */
	void setAtributo(Campo* atributo);

	/* Retorna la direccion de memoria del hijo izquierdo
	 */
	kdNodo* getHijoIzq() const;

	/* Edita el hijo izquierdo.
	 * Si previamente el nodo interno ya tenia hijo izquierdo, se reemplaza la referencia de
	 * memoria, pero no libera la memoria del hijo almacenado previamente.
	 */
	void setHijoIzq(kdNodo* hijoIzquierdo);

	/* Retorna la direccion de memoria del hijo derecho
	 */
	kdNodo* getHijoDer() const;

	/* Edita el hijo derecho.
	 * Si previamente el nodo interno ya tenia hijo derecho, se reemplaza la referencia de
	 * memoria, pero no libera la memoria del hijo almacenado previamente.
	 */
	void setHijoDer(kdNodo* hijoDerecho);

	/* Funcion que genera la cadena de bytes para almacenar la clase. Debe recibir por
	 * referencia un int que pueda almacenar el tamaño de la cadena, para su guardado
	 * posterior en el archivo.
	 */
	virtual Byte * obtenerRegistro (int *tam);

	void inicializarConRegistro(Byte * registro);

};

#endif /* NODOINTERNO_H_ */
