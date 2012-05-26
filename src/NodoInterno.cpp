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
	// TODO Auto-generated constructor stub

}

/* Constructor de la clase NodoInterno
 * Inicializa con el atributo que recibe por parámetro y los los demas en NULL
 */
NodoInterno::NodoInterno(Campo* atributo){
	// TODO constructor con 1 parametro
}

/* Constructor de la clase NodoInterno
 * Inicializa todos sus atributos con los argumentos recibidos por parámtetros.
 */
NodoInterno::NodoInterno(Campo* atributo, Nodo* hijoIzq, Nodo* hijoDer){
	// TODO constructor con 3 parametros
}

/* Destructor de la clase NodoInterno
 * Debe eliminar la memoria reservada por los punteros y establecerlos como NULL
 */
NodoInterno::~NodoInterno() {
	// TODO Auto-generated destructor stub
}

/* Retorna el atributo que identifica al nodo
 */
Campo* NodoInterno::getAtributo(){
	// TODO getAtributo
	return NULL;
}

/* Modifica el atributo del nodo, estableciendo el que recibe por parámetro.
 */
void NodoInterno::setAtributo(Campo* atributo){
	// TODO setAtributo
}

/* Retorna la direccion de memoria del hijo izquierdo
 */
Nodo* NodoInterno::getHijoIzq() const{
	// TODO getHijoIzq
	return NULL;
}

/* Retorna el identificador del nodo hijo izquierdo
 */
int NodoInterno::getIDHijoIzq(){
	// TODO getIDHijoIzq
	return 0;
}

/* Edita el hijo izquierdo.
 * Si previamente el nodo interno ya tenia hijo izquierdo, libera la memoria y
 * carga el nuevo hijo
 */
void NodoInterno::setHijoIzq(Nodo* hijoIzq){
	// TODO setHijoIzq
}

/* Retorna la direccion de memoria del hijo derecho
 */
Nodo* NodoInterno::getHijoDer() const{
	// TODO getHijoDer
	return NULL;
}

/* Retorna el identificador del nodo hijo derecho
 */
int NodoInterno::getIDHijoDer(){
	// TODO getIDhijoDer
	return 0;
}

/* Edita el hijo derecho.
 * Si previamente el nodo interno ya tenia hijo derecho, libera la memoria y
 * carga el nuevo hijo
 */
void NodoInterno::setHijoDer(Nodo* hijoIzq){
	// TODO setHijoIzq
}
