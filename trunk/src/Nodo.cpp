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
Nodo::Nodo() {}

/*
 * Constructor de la clase Nodo, que debe inicializarse con el ID correspondiente
 */
Nodo::Nodo(int ID) {
	this->id = ID;
}

/*
 * Destructor de la clase Clave
 */
Nodo::~Nodo() {
	// TODO Auto-generated destructor stub
}

int Nodo::getId() const {
	return id;
}

void Nodo::setId(int id) {
	this->id = id;
}
