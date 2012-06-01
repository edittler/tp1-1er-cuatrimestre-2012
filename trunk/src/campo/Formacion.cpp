/*
 * Implementacion de la clase Formacion, que hereda de Campo y forma una de las dimensiones
 * de Clave
 *
 *  Created on: 21/05/2012
 *      Author: ezequiel
 */

#include "Formacion.h"

Formacion::Formacion(){
	this->numero = 0;
}

Formacion::Formacion(Formacion& formacion){
	this->numero = formacion.numero;
}

Formacion::Formacion(int numeroFormacion) {
	this->numero = numeroFormacion;
}

Formacion::~Formacion() {

}

int Formacion::getNumeroFormacion() {
	return this->numero;
}

void Formacion::setNumeroFormacion(int numero) {
	this->numero = numero;
}

ResultadoComparacion Formacion::comparar(Campo* otroCampo) {
	if (otroCampo == NULL){
		return MAYOR;
	}

	Formacion* otraFormacion = dynamic_cast<Formacion*>(otroCampo);

	if (!otraFormacion) {
		return COMPARACION_NO_VALIDA;
	}

	if (this->getNumeroFormacion() > otraFormacion->getNumeroFormacion()) {
		return MAYOR;
	} else if(this->getNumeroFormacion() < otraFormacion->getNumeroFormacion()) {
		return MENOR;
	} else {
		return IGUAL;
	}
}

Byte * Formacion::obtenerRegistro (int *tam){
	Byte *registro = new Byte[sizeof(int)];
	*registro = this->numero;
	*tam = sizeof(int);
	return registro;
}

void Formacion::inicializarConRegistro(Byte * registro) {
	// Al estar compuesta solo de un numero la asignacion es directa
	numero = *registro;
}
