/*
 * Interface de la clase NodoInterno, que hereda de Nodo
 *
 *  Created on: 12/05/2012
 *      Author: ezequiel
 */

#ifndef NODOINTERNO_H_
#define NODOINTERNO_H_

#include "Nodo.h"
#include "Clave.h"

class NodoInterno: public Nodo {
/*
 * Atributos privados de la clase
 */
private:
	Campo* atributo;
	Nodo* hijoIzq;
	Nodo* HijoDer;
	int IDizq;
	int IDder;

public:
	/* Constructor de la clase NodoInterno
	 * Inicializa todos sus atributos en null
	 */
	NodoInterno();

	/* Constructor de la clase NodoInterno
	 * Inicializa con el atributo que recibe por parámetro y los los demas en NULL
	 */
	NodoInterno(Campo* atributo);

	/* Constructor de la clase NodoInterno
	 * Inicializa todos sus atributos con los argumentos recibidos por parámtetros.
	 */
	NodoInterno(Campo* atributo, Nodo* hijoIzq, Nodo* hijoDer);

	/* Destructor de la clase NodoInterno
	 * Debe eliminar la memoria reservada por los punteros y establecerlos como NULL
	 */
	virtual ~NodoInterno();

	/* Retorna el atributo que identifica al nodo
	 */
	Campo* getAtributo();

	/* Modifica el atributo del nodo, estableciendo el que recibe por parámetro.
	 */
	void setAtributo(Campo* atributo);

	/* Retorna la direccion de memoria del hijo izquierdo
	 */
	Nodo* getHijoIzq() const;

	/* Retorna el identificador del nodo hijo izquierdo
	 */
	int getIDHijoIzq();

	/* Edita el hijo izquierdo.
	 * Si previamente el nodo interno ya tenia hijo izquierdo, libera la memoria y
	 * carga el nuevo hijo
	 */
	void setHijoIzq(Nodo* hijoIzq);

	/* Retorna la direccion de memoria del hijo derecho
	 */
	Nodo* getHijoDer() const;

	/* Retorna el identificador del nodo hijo derecho
	 */
	int getIDHijoDer();

	/* Edita el hijo derecho.
	 * Si previamente el nodo interno ya tenia hijo derecho, libera la memoria y
	 * carga el nuevo hijo
	 */
	void setHijoDer(Nodo* hijoIzq);

};

#endif /* NODOINTERNO_H_ */
