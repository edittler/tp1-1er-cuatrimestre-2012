/*
 * CampoCadena.cpp
 *
 *  Created on: May 22, 2012
 *      Author: matias_2
 */

#include "CampoCadena.h"

CampoCadena::CampoCadena() {

}

CampoCadena::CampoCadena(CampoCadena &campoCadena) {
	this->descripcion = campoCadena.descripcion;
}

CampoCadena::CampoCadena(string descripcion) {
	this->descripcion = descripcion;
}

CampoCadena::~CampoCadena() {

}

string CampoCadena::getDescripcion() {
	return this->descripcion;
}

void CampoCadena::setDescripcion(string descripcion) {
	this->descripcion = descripcion;
}

ResultadoComparacion CampoCadena::comparar(Campo* otroCampo) {
	if ((this == NULL) && (otroCampo == NULL)){
		return IGUAL;
	}

	/* FIXME corregir "this" para que tome que su mismo objeto es null y pueda comparar
	 * con otro objeto null. Ver tests para ver como debería funcionar
	 */

	CampoCadena* otraCampoCadena = dynamic_cast<CampoCadena*>(otroCampo);

	if (!otraCampoCadena) {
		return COMPARACION_NO_VALIDA;
	}

	if (otraCampoCadena->getDescripcion() < this->getDescripcion()) {
		return MAYOR;
	} else if (otraCampoCadena->getDescripcion() > this->getDescripcion()) {
		return MENOR;
	} else {
		return IGUAL;
	}
}
