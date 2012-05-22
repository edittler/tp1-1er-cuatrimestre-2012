/*
 * Interface de la clase Accidente, que hereda de Campo y forma una de las dimensiones
 * de Clave
 *
 *  Created on: 21/05/2012
 *      Author: ezequiel
 */

#ifndef ACCIDENTE_H_
#define ACCIDENTE_H_

#include <string>
#include "Campo.h"

class Accidente: public Campo {
private:
	string tipo; // Tipo de accidente
public:

	/*
	 * Constructor de la clase Accidente
	 * Recibe el tipo de Accidente como string por parámetro
	 */
	Accidente(string tipoAccidente);

	/*
	 * Destructor de la clase Accidente
	 */
	virtual ~Accidente();

	/*
	 * Metodo virtual que compara este campo con otro pasado por parámetro.
	 * Como estándar, debe devolver 0 si son iguales y distinto de 0 si son distintos.
	 * Se puede considerar devolver -1 si el campo es menor que el pasado por parámetro
	 * y 1 si el campo es mayor que el pasado por parámetro
	 */
	virtual int comparar(Campo* otroCampo);

};

#endif /* ACCIDENTE_H_ */
