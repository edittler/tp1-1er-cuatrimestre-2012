/*
 * Interface de la clase NodoInterno, que hereda de Nodo
 *
 *  Created on: 12/05/2012
 *      Author: ezequiel
 */

#ifndef NODOINTERNO_H_
#define NODOINTERNO_H_

#include "NodoKD.h"
#include "Clave.h"

class NodoInterno: public NodoKD {
/*
 * Atributos privados de la clase
 */
private:
	Campo* atributo;
	NodoKD* hijoIzq;
	NodoKD* hijoDer;
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
	NodoInterno(Campo* atributo, NodoKD* hijoIzq, NodoKD* hijoDer);

	/* Destructor de la clase NodoInterno
	 * Debe eliminar la memoria reservada por los punteros y establecerlos como NULL
	 * Si los nodos hijos de este nodo se van a seguir usando, previo a la destruccion del
	 * objeto, se deben establecer como NULL los hijos de este nodo para no cometer
	 * liberaciones de memoria erroneas.
	 */
	virtual ~NodoInterno();

	/* Retorna el atributo que identifica al nodo
	 */
	Campo* getAtributo() const;

	/* Modifica el atributo del nodo, estableciendo el que recibe por parámetro.
	 */
	void setAtributo(Campo* atributo);

	/* Retorna la direccion de memoria del hijo izquierdo
	 */
	NodoKD* getHijoIzq() const;

	/* Retorna el identificador del nodo hijo izquierdo
	 */
	int getIDHijoIzq();

	/* Edita el hijo izquierdo.
	 * Si previamente el nodo interno ya tenia hijo izquierdo, se reemplaza la referencia de
	 * memoria, pero no libera la memoria del hijo almacenado previamente.
	 */
	void setHijoIzq(NodoKD* hijoIzquierdo);

	/* Retorna la direccion de memoria del hijo derecho
	 */
	NodoKD* getHijoDer() const;

	/* Retorna el identificador del nodo hijo derecho
	 */
	int getIDHijoDer();

	/* Edita el hijo derecho.
	 * Si previamente el nodo interno ya tenia hijo derecho, se reemplaza la referencia de
	 * memoria, pero no libera la memoria del hijo almacenado previamente.
	 */
	void setHijoDer(NodoKD* hijoDerecho);

};

#endif /* NODOINTERNO_H_ */
