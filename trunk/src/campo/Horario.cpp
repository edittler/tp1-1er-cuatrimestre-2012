/*
 * Horario.cpp
 *
 *  Created on: May 24, 2012
 *      Author: matias_2
 */

#include "sstream"
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


