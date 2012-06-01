/*
 * Implementacion de la clase Accidente, que hereda de Campo y forma una de las dimensiones
 * de Clave
 *
 *  Created on: 21/05/2012
 *      Author: ezequiel
 */

#include "Accidente.h"

Accidente::Accidente() : CampoCadena() {

}

Accidente::Accidente(Accidente& accidente) : CampoCadena(accidente) {

}

Accidente::Accidente(string tipoAccidente) : CampoCadena(tipoAccidente){

}

Accidente::~Accidente() {

}

ResultadoComparacion Accidente::comparar(Campo* otroCampo) {
	if (otroCampo == NULL){
		return MAYOR;
	}

	Accidente* otraCampoCadena = dynamic_cast<Accidente*>(otroCampo);

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

