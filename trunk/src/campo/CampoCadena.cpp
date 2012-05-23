/*
 * CampoCadena.cpp
 *
 *  Created on: May 22, 2012
 *      Author: matias_2
 */

#include "CampoCadena.h"

CampoCadena::CampoCadena() {
	// TODO Auto-generated constructor stub

}

CampoCadena::CampoCadena(string descripcion) {
	this->descripcion = descripcion;
}

CampoCadena::~CampoCadena() {
	// TODO Auto-generated destructor stub
}

string CampoCadena::getDescripcion() {
	return this->descripcion;
}

void CampoCadena::setDescripcion(string descripcion) {
	this->descripcion = descripcion;
}

ResultadoComparacion CampoCadena::comparar(Campo* otroCampo) {
	//Downcasting.
	CampoCadena* otraCampoCadena = dynamic_cast<CampoCadena*>(otroCampo);
	ResultadoComparacion resultado;

	if (!otraCampoCadena) {
		resultado = COMPARACION_NO_VALIDA;
		return resultado;
	}

	if (otraCampoCadena->getDescripcion() < this->getDescripcion()) {
		return MAYOR;
	} else if (otraCampoCadena->getDescripcion() > this->getDescripcion()) {
		return MENOR;
	} else {
		return IGUAL;
	}
}


