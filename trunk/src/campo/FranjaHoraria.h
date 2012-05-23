/*
 * Interface de la clase FranjaHoraria, que hereda de Campo y forma una de las dimensiones
 * de Clave
 *
 *  Created on: 21/05/2012
 *      Author: ezequiel
 */

#ifndef FRANJAHORARIA_H_
#define FRANJAHORARIA_H_

#include "Campo.h"
#include "iostream"

using namespace std;

class FranjaHoraria: public Campo {
private:
	int fecha;
	int horario;

	bool validarFecha(int fecha);
	bool validarFecha(string fecha);

	bool validarHorario(int horario);
	bool validarHorario(string horario);

public:

	/*
	 * Constructor de la clase FranjaHoraria
	 */
	FranjaHoraria();

	/*
	 * Destructor de la clase FranjaHoraria
	 */
	virtual ~FranjaHoraria();

	string getFechaString();
	int getFecha();

	void setFecha(int fecha);
	void setFecha(string fecha);

	string getHorarioString();
	int getHorario();

	void setHorario(int horario);
	void setHorario(string horario);

	/*
	 * Metodo virtual que compara este campo con otro pasado por parámetro.
	 * Como estándar, debe devolver 0 si son iguales y distinto de 0 si son distintos.
	 * Se puede considerar devolver -1 si el campo es menor que el pasado por parámetro
	 * y 1 si el campo es mayor que el pasado por parámetro
	 */
	ResultadoComparacion comparar(Campo* otroCampo);
};

#endif /* FRANJAHORARIA_H_ */
