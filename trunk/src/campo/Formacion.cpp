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
	/* Genero espacio para 2 integer. El primero almacena la longitud del registro que
	 * contendrá la clase Formación y el segundo es el que almacenará el campo propiamente
	 * dicho (el integer).
	 */
	Byte *size = new Byte[sizeof(int)];
	*size = 4;
	Byte *integer = new Byte[sizeof(int)];
	*integer = this->numero;
	*tam = sizeof(int)*2; // tamaño total del registro a devolver
	Byte *registro = new Byte[*tam];
	concatenar(&registro, size, 4, integer, 4);
	delete size;
	delete integer;
	return registro;
}

void Formacion::inicializarConRegistro(Byte * registro) {
	// Al estar compuesta solo de un numero la asignacion es directa
	numero = *registro;
}
