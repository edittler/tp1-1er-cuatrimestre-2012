/*
 * NodoInterno.cpp
 *
 *  Created on: 12/05/2012
 *      Author: ezequiel
 */

#include "NodoInterno.h"

/* Constructor de la clase NodoInterno
 * Inicializa todos sus atributos en null
 */
NodoInterno::NodoInterno() {
	this->atributo = NULL;
	this->hijoIzq = NULL;
	this->hijoDer = NULL;
	this->IDizq = 0;
	this->IDder = 0;
}

/* Constructor de la clase NodoInterno
 * Inicializa con el atributo que recibe por parámetro y los los demas en NULL
 */
NodoInterno::NodoInterno(Campo* atributo){
	this->setAtributo(atributo);
	this->hijoIzq = NULL;
	this->hijoDer = NULL;
	this->IDizq = 0;
	this->IDder = 0;
}

/* Constructor de la clase NodoInterno
 * Inicializa todos sus atributos con los argumentos recibidos por parámtetros.
 */
NodoInterno::NodoInterno(Campo* atributo, Nodo* hijoIzq, Nodo* hijoDer){
	this->setAtributo(atributo);
	this->setHijoIzq(hijoIzq);
	this->setHijoDer(hijoDer);
}

/* Destructor de la clase NodoInterno
 * Debe eliminar la memoria reservada por los punteros y establecerlos como NULL
 * Si los nodos hijos de este nodo se van a seguir usando, previo a la destruccion del objeto,
 * se deben establecer como NULL los hijos de este nodo para no cometer liberaciones de
 * memoria erroneas.
 */
NodoInterno::~NodoInterno() {
	delete this->atributo;
	delete this->hijoIzq;
	delete this->hijoDer;
}

/* Retorna el atributo que identifica al nodo
 */
Campo* NodoInterno::getAtributo() const{
	return this->atributo;
}

/* Modifica el atributo del nodo, estableciendo el que recibe por parámetro.
 */
void NodoInterno::setAtributo(Campo* atributo){
	if (this->atributo != NULL){
		delete this->atributo;
	}
	// FIXME Hay que realizar un casteo, inicializar un campo correspondiente y almacenar
	// Campo* unCampo = new Campo(atributo);
}

/* Retorna la direccion de memoria del hijo izquierdo
 */
Nodo* NodoInterno::getHijoIzq() const{
	return this->hijoIzq;
}

/* Retorna el identificador del nodo hijo izquierdo
 */
int NodoInterno::getIDHijoIzq(){
	return this->IDizq;
}

/* Edita el hijo izquierdo.
 * Si previamente el nodo interno ya tenia hijo izquierdo, se reemplaza la referencia de
 * memoria, pero no libera la memoria del hijo almacenado previamente.
 */
void NodoInterno::setHijoIzq(Nodo* hijoIzquierdo){
	this->hijoIzq = hijoIzquierdo;
	if (this->hijoIzq != NULL){
		this->IDizq = this->hijoIzq->getId();
	} else {
		this->IDizq = 0;
	}
}

/* Retorna la direccion de memoria del hijo derecho
 */
Nodo* NodoInterno::getHijoDer() const{
	return this->hijoDer;
}

/* Retorna el identificador del nodo hijo derecho
 */
int NodoInterno::getIDHijoDer(){
	return this->IDder;
}

/* Edita el hijo derecho.
 * Si previamente el nodo interno ya tenia hijo derecho, se reemplaza la referencia de
 * memoria, pero no libera la memoria del hijo almacenado previamente.
 */
void NodoInterno::setHijoDer(Nodo* hijoDerecho){
	this->hijoDer = hijoDerecho;
	if (this->hijoDer != NULL){
		this->IDder = this->hijoDer->getId();
	} else {
		this->IDder = 0;
	}
}
