/*
 * Implementacion de la clase Formacion, que hereda de Campo y forma una de las dimensiones
 * de Clave
 *
 *  Created on: 21/05/2012
 *      Author: ezequiel
 */

#include "Formacion.h"

/*
 * Constructor de la clase Formacion
 * Se pasa por parámetro el numero de formacion del tren
 */
Formacion::Formacion(int numeroFormacion) {
	// TODO Auto-generated constructor stub

}

Formacion::~Formacion() {
	// TODO Auto-generated destructor stub
}

/*
 * Metodo virtual que compara este campo con otro pasado por parámetro.
 * Como estándar, debe devolver 0 si son iguales y distinto de 0 si son distintos.
 * Se puede considerar devolver -1 si el campo es menor que el pasado por parámetro
 * y 1 si el campo es mayor que el pasado por parámetro
 */
int Formacion::comparar(Campo* otroCampo){
	// TODO Implementar
	return 0;
}
