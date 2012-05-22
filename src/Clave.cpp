/*
 * Implementacion de la clase Clave
 *
 *  Created on: 12/05/2012
 *      Author: ezequiel
 */

#include "Clave.h"

/*
 * Constructor de la clase Clave, que inicializa todas sus dimensiones en NULL
 */
Clave::Clave() {
//	this->listaCampos = new Campo[this->cantDimensiones];
//	for(int i=0; i < this->cantDimensiones; i++){
//		this->listaCampos[i]=NULL;
//	}
}

/*
 * Constructor de la clase Clave, que inicializa los campos Linea y Formacion,
 * el resto de sus dimensiones en NULL
 */
Clave::Clave(string linea, int formacion) {
//	Campo* unaLinea = new Linea(linea);
//	Campo* unaFormacion = new Formacion(formacion);
//	this->listaCampos = new Campo[this->cantDimensiones];
//	this->listaCampos[0] = unaLinea;
//	this->listaCampos[1] = unaFormacion;
//	for(int i=2; i < this->cantDimensiones; i++){
//		this->listaCampos[i]=NULL;
//	}
}

Clave::~Clave() {
//	for(int i=0; i < this->cantDimensiones; i++){
//		if (this->listaCampos[i] != NULL){
//			delete this->listaCampos[i];
//		}
//	}
//	delete this->listaCampos;
}

void Clave::setLinea(string linea){
//	if (this->listaCampos[0] != NULL){
//		delete this->listaCampos[0];
//	}
//	this->listaCampos[0] = new Linea(linea);
}

void Clave::setFormacion(int formacion){
//	if (this->listaCampos[1] != NULL){
//		delete this->listaCampos[1];
//	}
//	this->listaCampos[1] = new Formacion(formacion);
}

void Clave::setFranjaHoraria(){
	//TODO agregar los parametros Fecha
}

void Clave::setFalla(string falla){
//	if (this->listaCampos[3] != NULL){
//		delete this->listaCampos[3];
//	}
//	this->listaCampos[3] = new Falla(falla);
}

void Clave::setAccidente(string accidente){
//	if (this->listaCampos[4] != NULL){
//		delete this->listaCampos[4];
//	}
//	this->listaCampos[4] = new Accidente(accidente);
}

/*
 * Se obtiene el campo correspondiente a la dimension requerida, siendo:
 * 		0: Linea
 * 		1: Formacion
 * 		2: FranjaHoraria
 * 		3: Falla
 * 		4: Accidente
 * Si se pasa un valor diferente a los mencionados anteriormente, devuelve un puntero NULL
 */
Campo* Clave::getCampo(int dimension) const{
//	Campo *unCampo = NULL;
//	if (0 <= dimension && dimension < this->cantDimensiones){
//		unCampo = this->listaCampos[dimension];
//	}
//	return unCampo;
	return NULL;
}

/*
 * Funcion que evalúa si esta clave es igual a otra pasada por parámetro.
 * Compara todos los campos y evuelve 0 si son iguales, o un valor distinto de 0 si
 * no son iguales
 */
int Clave::comparar(Clave otraClave){
	// TODO HACER
	return 0;
}

/*
 * Funcion que evalúa solo la dimensión de esta clave con otra pasada por parámetro
 * Compara el campo correspondiente a la dimension que se quiere evaluar y
 * devuelve 0 si son iguales, -1 si el campo es menor que el pasado por parametro y
 * 1 si el campo es mayor.
 */
int Clave::comparar(Clave otraClave, int dimesion){
	// TODO HACER
	return 0;
}
