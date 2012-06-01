/*
 * Horario.cpp
 *
 *  Created on: May 24, 2012
 *      Author: matias_2
 */

#include <sstream>
#include "Horario.h"

Horario::Horario() {
	this->horarioComienzo = 0;
	this->horarioFin = 0;
}

Horario::Horario(Horario& horario) {
	this->horarioComienzo = horario.horarioComienzo;
	this->horarioFin = horario.horarioFin;
}

Horario::Horario(int comienzo, int fin) {
	this->setHorario(comienzo, fin);
}

Horario::~Horario() {

}

bool Horario::validarHorario(int horario) {
	int hora = horario / 100;
	int min = horario % 100;

	if (hora < 0 || hora > 23) {
		return false;
	}

	if (min < 0 || min > 59) {
		return false;
	}

	return true;
}

string Horario::getIntervaloString() {
	stringstream s;
	s << this->getComienzoString() << " - " << this->getFinString();
	return s.str();
}

string Horario::getComienzoString() {
	stringstream s;
	s << this->horarioComienzo / 100 << ":" << this->horarioComienzo % 100;
	return s.str();
}

string Horario::getFinString() {
	stringstream s;
	s << this->horarioFin / 100 << ":" << this->horarioFin % 100;
	return s.str();
}

void Horario::setHorario(int comienzo, int fin) {

	if (this->validarHorario(comienzo) && this->validarHorario(fin)) {
		this->horarioComienzo = comienzo;
		this->horarioFin = fin;
	} else {
		this->horarioComienzo = 0;
		this->horarioFin = 0;
	}
}

ResultadoComparacion Horario::comparar(Horario* otroHorario) {
	if (otroHorario == NULL) {
		return MAYOR;
	}

	if (this->horarioComienzo > otroHorario->horarioComienzo) {
		return MAYOR;
	} else if (this->horarioComienzo < otroHorario->horarioComienzo) {
		return MENOR;
	} else if (this->horarioFin > otroHorario->horarioFin) {
		return MAYOR;
	} else if (this->horarioFin < otroHorario->horarioFin) {
		return MENOR;
	} else {
		return IGUAL;
	}
}

Byte * Horario::obtenerRegistro (int *tam){
	// serializo la hora de comienzo
	Byte *horaComienzo = new Byte[sizeof(int)];
	*horaComienzo = this->horarioComienzo;
	// serializo la hora de final
	Byte *horaFinal = new Byte[sizeof(int)];
	*horaFinal = this->horarioFin;
	// concateno las dos horas en un temporal
	Byte *tmp;
	concatenar(&tmp, horaComienzo, 4, horaFinal, 4);
	delete horaComienzo;
	delete horaFinal;
	/* Ahora genero el tamaño que va a tener el campo y realizo la ultima
	 * concatenacion.
	 */
	Byte *size = new Byte[sizeof(int)];
	*size = sizeof(int)*2; // tamaño que tiene solo el campo Horario
	*tam = sizeof(int)*3; // Almaceno el tamaño total para que lo utilize la clase externa.
	Byte *registro = new Byte[*tam];
	concatenar(&registro, size, sizeof(int), tmp, sizeof(int)*2);
	delete size;
	delete tmp;
	return registro;
}

void Horario::inicializarConRegistro(Byte * registro) {
	//obtengo la hora comienzo
	Byte * regHoraComienzo;
	int inicio = 0;
	int tamReg = sizeof(int);
	obtenerPorcion(registro, &regHoraComienzo, inicio, tamReg);
	horarioComienzo = *regHoraComienzo;
	//obtengo la hora final
	inicio += tamReg;
	Byte * regHoraFinal;
	obtenerPorcion(registro, &regHoraFinal, inicio, tamReg);
	horarioFin = *regHoraFinal;
}
