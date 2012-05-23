/*
 * Interface de la clase Formacion, que hereda de Campo y forma una de las dimensiones de Clave
 *
 *  Created on: 21/05/2012
 *      Author: ezequiel
 */

#ifndef FORMACION_H_
#define FORMACION_H_

#include "Campo.h"

class Formacion: public Campo {
private:
	int numero;

public:

	Formacion();

	/*
	 * Constructor de la clase Formacion
	 * Se pasa por parámetro el numero de formacion del tren
	 */
	Formacion(int numeroFormacion);

	/*
	 * Destructor de la clase Formacion
	 */
	virtual ~Formacion();

	int getNumeroFormacion();
	void setNumeroFormacion(int numero);

	/*
	 * Metodo virtual que compara este campo con otro pasado por parámetro.
	 * Como estándar, debe devolver 0 si son iguales y distinto de 0 si son distintos.
	 * Se puede considerar devolver -1 si el campo es menor que el pasado por parámetro
	 * y 1 si el campo es mayor que el pasado por parámetro
	 */
	ResultadoComparacion comparar(Campo* otroCampo);
};

#endif /* FORMACION_H_ */

