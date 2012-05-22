/*
 * Implementacion de la clase Linea, que hereda de Campo y forma una de las dimensiones de Clave
 *
 *  Created on: 21/05/2012
 *      Author: ezequiel
 */

#include "Linea.h"
#include "Campo.h"

Linea::Linea(string nombreLinea) {
	// TODO Auto-generated constructor stub

}

Linea::~Linea() {
	// TODO Auto-generated destructor stub
}

/*
 * Metodo virtual que compara este campo con otro pasado por parámetro.
 * Como estándar, debe devolver 0 si son iguales y distinto de 0 si son distintos.
 * Se puede considerar devolver -1 si el campo es menor que el pasado por parámetro
 * y 1 si el campo es mayor que el pasado por parámetro
 */
int Linea::comparar(Campo* otroCampo){
	// TODO Implementar
	return 0;
}
