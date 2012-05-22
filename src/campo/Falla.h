/*
 * Interface de la clase Falla, que hereda de Campo y forma una de las dimensiones
 * de Clave
 *
 *  Created on: 21/05/2012
 *      Author: ezequiel
 */

#ifndef FALLA_H_
#define FALLA_H_

#include <string>
#include "Campo.h"

class Falla: public Campo {
private:
	string tipo; // Tipo de falla

public:

	/*
	 * Constructor de la clase Falla
	 * Se pasa el tipo de falla como string por parámetro
	 */
	Falla(string tipoFalla);

	/*
	 * Destructor de la clase Falla
	 */
	virtual ~Falla();

	/*
	 * Metodo virtual que compara este campo con otro pasado por parámetro.
	 * Como estándar, debe devolver 0 si son iguales y distinto de 0 si son distintos.
	 * Se puede considerar devolver -1 si el campo es menor que el pasado por parámetro
	 * y 1 si el campo es mayor que el pasado por parámetro
	 */
	virtual int comparar(Campo* otroCampo);
};

#endif /* FALLA_H_ */
