/*
 * Implementacion de la clase Accidente, que hereda de Campo y forma una de las dimensiones
 * de Clave
 *
 *  Created on: 21/05/2012
 *      Author: ezequiel
 */

#include "Accidente.h"

/*
 * Constructor de la clase Accidente
 * Recibe el tipo de Accidente como string por parámetro
 */
Accidente::Accidente(string tipoAccidente) {
	// TODO Auto-generated constructor stub

}

/*
 * Destructor de la clase Accidente
 */
Accidente::~Accidente() {
	// TODO Auto-generated destructor stub
}

/*
 * Metodo virtual que compara este campo con otro pasado por parámetro.
 * Como estándar, debe devolver 0 si son iguales y distinto de 0 si son distintos.
 * Se puede considerar devolver -1 si el campo es menor que el pasado por parámetro
 * y 1 si el campo es mayor que el pasado por parámetro
 */
int Accidente::comparar(Campo* otroCampo){
	// TODO Implementar
	return 0;
}
