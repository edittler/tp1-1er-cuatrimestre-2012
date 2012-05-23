/*
 * Implementacion de la clase FranjaHoraria, que hereda de Campo y forma una de las dimensiones
 * de Clave
 *
 *  Created on: 21/05/2012
 *      Author: ezequiel
 */

#include "FranjaHoraria.h"
#include "Campo.h"


FranjaHoraria::FranjaHoraria() {

}

FranjaHoraria::~FranjaHoraria() {

}

string FranjaHoraria::getFechaString() {
//	stringstream s;
//	s << this->fecha;
//	return s;
	return "";
}

int FranjaHoraria::getFecha() {
	return 0;
}

void FranjaHoraria::setFecha(string fecha) {

}

void FranjaHoraria::setFecha(int fecha) {

}

string FranjaHoraria::getHorarioString() {
	return "";
}

int FranjaHoraria::getHorario() {
	return this->horario;
}

ResultadoComparacion FranjaHoraria::comparar(Campo* otroCampo){
	// TODO Implementar
	return IGUAL;
}
