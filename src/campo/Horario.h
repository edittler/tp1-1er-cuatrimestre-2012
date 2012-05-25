/*
 * Horario.h
 *
 *  Created on: May 24, 2012
 *      Author: matias_2
 */

#ifndef HORARIO_H_
#define HORARIO_H_

#include "ResultadoComparacion.h"
#include "iostream"

using namespace std;
using namespace comparacion;

class Horario {
private:
	int horarioComienzo;
	int horarioFin;

	//Metodos privados.
	bool validarHorario(int horario);

public:
	Horario();
	Horario(int comienzo, int fin);
	virtual ~Horario();

	string getIntervaloString();
	string getComienzoString();
	string getFinString();

	void setHorario(int comienzo, int fin);

	ResultadoComparacion comparar(Horario* otroHorario);

};

#endif /* HORARIO_H_ */
