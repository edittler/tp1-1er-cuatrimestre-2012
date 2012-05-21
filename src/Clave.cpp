/*
 * Implementacion de la clase Clave
 *
 *  Created on: 12/05/2012
 *      Author: ezequiel
 */

#include "Clave.h"

Clave::Clave() {
	this->listaCampos = new Campo[this->cantDimensiones];
	for(int i=0; i < this->cantDimensiones; i++){
		this->listaCampos[i]=NULL;
	}
}

Clave::~Clave() {
	for(int i=0; i < this->cantDimensiones; i++){
		if (this->listaCampos[i]!=NULL){
			delete this->listaCampos[i];
		}
	}
	delete this->listaCampos;
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

