/*
 * Implementacion de la clase Accidente, que hereda de Campo y forma una de las dimensiones
 * de Clave
 *
 *  Created on: 21/05/2012
 *      Author: ezequiel
 */

#include "Accidente.h"

Accidente::Accidente() : CampoCadena() {

}

Accidente::Accidente(string tipoAccidente) : CampoCadena(tipoAccidente){

}

Accidente::~Accidente() {

}
