/*
 * Implementacion de la clase base Nodo
 *
 *  Created on: 12/05/2012
 *      Author: ezequiel
 */

#include "Nodo.h"

/*
 * Contructor por defecto.
 */
NodoKD::NodoKD() {}

/*
 * Constructor de la clase Nodo, que debe inicializarse con el ID correspondiente
 */
NodoKD::NodoKD(int ID) {
	this->id = ID;
}

/*
 * Destructor de la clase Clave
 */
NodoKD::~NodoKD() {

}

int NodoKD::getId() const {
	return id;
}

void NodoKD::setId(int id) {
	this->id = id;
}
