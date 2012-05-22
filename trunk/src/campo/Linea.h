/*
 * Interface de la clase Linea, que hereda de Campo y forma una de las dimensiones de Clave
 *
 *  Created on: 21/05/2012
 *      Author: ezequiel
 */

#ifndef LINEA_H_
#define LINEA_H_

#include <string>
#include "Campo.h"

class Linea: public Campo {
private:
	string nombre; // Nombre de la linea

public:

	/*
	 * Constructor de la clase Linea
	 * Se para el nombre de la linea por parámetro
	 */
	Linea(string nombreLinea);

	/*
	 * Destructor de la clase Linea
	 */
	virtual ~Linea();

	/*
	 * Metodo virtual que compara este campo con otro pasado por parámetro.
	 * Como estándar, debe devolver 0 si son iguales y distinto de 0 si son distintos.
	 * Se puede considerar devolver -1 si el campo es menor que el pasado por parámetro
	 * y 1 si el campo es mayor que el pasado por parámetro
	 */
	virtual int comparar(Campo* otroCampo);
};

#endif /* LINEA_H_ */
