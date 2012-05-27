/*
 * Implementacion de la clase base Nodo
 *
 *  Created on: 12/05/2012
 *      Author: ezequiel
 */

#include "kdNodo.h"

/*
 * Contructor por defecto.
 */
kdNodo::kdNodo() {}

/*
 * Constructor de la clase Nodo, que debe inicializarse con el ID correspondiente
 */
kdNodo::kdNodo(int ID) {
	this->id = ID;
}

/*
 * Destructor de la clase Clave
 */
kdNodo::~kdNodo() {

}

int kdNodo::getId() const {
	return id;
}

void kdNodo::setId(int id) {
	this->id = id;
}
