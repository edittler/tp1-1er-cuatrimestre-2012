/*
 * Formacion.cpp
 *
 *  Created on: 19/05/2012
 *      Author: Alejandro Daza
 */

#include "Formacion.h"

Formacion::Formacion(int formacion) {

	this->numFormacion = formacion;

}

int Formacion::getFormacion() {

	return numFormacion;
}

Formacion::~Formacion() {
	// TODO Auto-generated destructor stub
}

