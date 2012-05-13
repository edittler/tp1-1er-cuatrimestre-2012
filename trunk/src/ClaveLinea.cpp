/*
 * Implementacion de la clase ClaveLinea
 *
 *  Created on: 12/05/2012
 *      Author: ezequiel
 */

#include "ClaveLinea.h"

ClaveLinea::ClaveLinea(string nombreLineaNueva) {
    this->nombreLinea = nombreLineaNueva;
}

ClaveLinea::~ClaveLinea() {
	// TODO Auto-generated destructor stub
}

/*
 * Funcion que evalúa si esta clave es igual a otra pasada por parámetro
 */
virtual bool ClaveLinea::esIgual(Clave otraClave){
	// Casteo la clave como ClaveLinea. Debería validar antes de hacer el casteo
	ClaveLinea unaClave = (ClaveLinea) otraClave;
	string nombreOtraLinea = unaClave.getNombreLinea();
	bool esIgual = this->nombreLinea == nombreOtraLinea;
	return esIgual;
}

/*
 * Funcion que evalúa si esta clave es igual a otra pasada por parámetro
 */
virtual bool ClaveLinea::esMenor(Clave otraClave){
	// Casteo la clave como ClaveLinea. Debería validar antes de hacer el casteo
	ClaveLinea unaClave = (ClaveLinea) otraClave;
	string nombreOtraLinea = unaClave.getNombreLinea();
	bool esMenor = (this->nombreLinea < nombreOtraLinea);
	return esMenor;
}

/*
 * Funcion con la cual se obtiene el nombre de la linea
 */
string ClaveLinea::getNombreLinea(){
	return this->nombreLinea;
}

/*
 * Funcion con la cual se modifica el nombre de la linea
 */
void ClaveLinea::setNombreLinea(string nuevoNombre){
	this->nombreLinea=nuevoNombre;
}
