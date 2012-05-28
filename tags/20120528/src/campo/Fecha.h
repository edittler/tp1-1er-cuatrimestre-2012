/*
 * Fecha.h
 *
 *  Created on: May 23, 2012
 *      Author: matias_2
 */

#ifndef FECHA_H_
#define FECHA_H_
#include "iostream"
#include "ResultadoComparacion.h"

using namespace std;
using namespace comparacion;

class Fecha {
private:
	int fecha;

	//Metodos privados
	bool validarFecha(int fecha);

public:
	Fecha();
	Fecha(int dia, int mes, int anio);
	Fecha(Fecha &fecha);
	virtual ~Fecha();

	int getFechaInt();

	/*
	 * devuelve la fecha en formato string "dd/mm/aaaa"
	 */
	string getFechaString();

	/*
	 * Valida y seta la nueva fecha. En caso de no ser una fecha valida setea fecha
	 * en 01/01/2012;
	 */
	void setFecha(int dia, int mes, int anio);

	/*
	 * Compara dos fechas devolviendo MENOR, IGUAL,
	 */
	ResultadoComparacion comparar(Fecha* otraFecha);

};

#endif /* FECHA_H_ */
