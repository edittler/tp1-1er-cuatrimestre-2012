/*
 * Implementacion de la clase Linea, que hereda de Campo y forma una de las dimensiones de Clave
 *
 *  Created on: 21/05/2012
 *      Author: ezequiel
 */

#include "Linea.h"
#include "Campo.h"

Linea::Linea() : CampoCadena() {

}

Linea::Linea(Linea& linea) : CampoCadena(linea) {

}

Linea::Linea(string nombreLinea) : CampoCadena(nombreLinea){
}

Linea::~Linea() {

}

ResultadoComparacion Linea::comparar(Campo* otroCampo) {
	if (otroCampo == NULL){
		return MAYOR;
	}

	Linea* otraCampoCadena = dynamic_cast<Linea*>(otroCampo);

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


