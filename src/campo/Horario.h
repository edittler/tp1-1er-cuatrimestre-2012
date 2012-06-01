/*
 * Horario.h
 *
 *  Created on: May 24, 2012
 *      Author: matias_2
 */

#ifndef HORARIO_H_
#define HORARIO_H_

#include <iostream>
#include "../Byte.h"
#include "ResultadoComparacion.h"

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
	Horario(Horario& horario);
	Horario(int comienzo, int fin);
	virtual ~Horario();

	string getIntervaloString();
	string getComienzoString();
	string getFinString();

	void setHorario(int comienzo, int fin);

	ResultadoComparacion comparar(Horario* otroHorario);

	/* Funcion que genera la cadena de bytes para almacenar la Formacion. Debe recibir por
	 * referencia un int que pueda almacenar el tamaño de la cadena, para su guardado
	 * posterior en el archivo.
	 */
	Byte * obtenerRegistro (int *tam);

	void inicializarConRegistro(Byte *);

};

#endif /* HORARIO_H_ */
