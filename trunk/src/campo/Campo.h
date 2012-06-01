/*
 * Interface de la clase base Campo, que define cada dimension de la Clave multidimensional.
 *
 *  Created on: 21/05/2012
 *      Author: ezequiel
 */

#ifndef CAMPO_H_
#define CAMPO_H_

#include "iostream"
#include "ResultadoComparacion.h"
#include "Byte.h"

using namespace comparacion;

class Campo {
public:

	/*
	 * Constructor de la clase Campo
	 */
	Campo();

	/*
	 * Destructor de la clase Campo
	 */
	virtual ~Campo();

	/*
	 * Metodo virtual que compara este campo con otro pasado por parámetro.
	 * Como estándar, debe devolver 0 si son iguales y distinto de 0 si son distintos.
	 * Se puede considerar devolver -1 si el campo es menor que el pasado por parámetro
	 * y 1 si el campo es mayor que el pasado por parámetro
	 */
	virtual ResultadoComparacion comparar(Campo* otroCampo) = 0;
	virtual void inicializarConRegistro(Byte *) = 0;
};

#endif /* CAMPO_H_ */
