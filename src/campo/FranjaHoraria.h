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

class FranjaHoraria: public Campo {
public:

	/*
	 * Constructor de la clase FranjaHoraria
	 */
	FranjaHoraria();

	/*
	 * Destructor de la clase FranjaHoraria
	 */
	virtual ~FranjaHoraria();

	/*
	 * Metodo virtual que compara este campo con otro pasado por parámetro.
	 * Como estándar, debe devolver 0 si son iguales y distinto de 0 si son distintos.
	 * Se puede considerar devolver -1 si el campo es menor que el pasado por parámetro
	 * y 1 si el campo es mayor que el pasado por parámetro
	 */
	virtual int comparar(Campo* otroCampo);
};

#endif /* FRANJAHORARIA_H_ */
