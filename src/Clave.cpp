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
	this->listaCampos = new Campo*[this->cantDimensiones];
	for(int i=0; i < this->cantDimensiones; i++){
		this->listaCampos[i]=NULL;
	}
}

/*
 * Constructor de la clase Clave
 * Inicializa sus campos copiando los de la otra clave.
 */
Clave::Clave(Clave &otraClave){
	this->listaCampos = new Campo*[this->cantDimensiones];
	this->copiar(otraClave);
}

/*
 * Constructor de la clase Clave, que inicializa los campos Linea y Formacion,
 * el resto de sus dimensiones en NULL
 */
Clave::Clave(string linea, int formacion) {
	Campo *unaLinea = new Linea(linea);
	Campo *unaFormacion = new Formacion(formacion);
	this->listaCampos = new Campo*[this->cantDimensiones];
	this->listaCampos[0] = unaLinea;
	this->listaCampos[1] = unaFormacion;
	for(int i=2; i < this->cantDimensiones; i++){
		this->listaCampos[i]=NULL;
	}
}

Clave::~Clave() {
	for(int i=0; i < this->cantDimensiones; i++){
		if (this->listaCampos[i] != NULL){
			delete this->listaCampos[i];
		}
	}
	delete this->listaCampos;
}

void Clave::setLinea(string linea){
	if (this->listaCampos[0] != NULL){
		delete this->listaCampos[0];
	}
	this->listaCampos[0] = new Linea(linea);
}

void Clave::setFormacion(int formacion){
	if (this->listaCampos[1] != NULL){
		delete this->listaCampos[1];
	}
	this->listaCampos[1] = new Formacion(formacion);
}

void Clave::setFranjaHoraria(){
	//TODO agregar los parametros Fecha
}

void Clave::setFalla(string falla){
	if (this->listaCampos[3] != NULL){
		delete this->listaCampos[3];
	}
	this->listaCampos[3] = new Falla(falla);
}

void Clave::setAccidente(string accidente){
	if (this->listaCampos[4] != NULL){
		delete this->listaCampos[4];
	}
	this->listaCampos[4] = new Accidente(accidente);
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
Campo *Clave::getCampo(int dimension) const{
	Campo *unCampo = NULL;
	if (0 <= dimension && dimension < this->cantDimensiones){
		unCampo = this->listaCampos[dimension];
	}
	return unCampo;
}

/*
 * Funcion que evalúa si esta clave es igual a otra pasada por parámetro.
 * Compara todos los campos y evuelve 0 si son iguales, o un valor distinto de 0 si
 * no son iguales
 */
ResultadoComparacion Clave::comparar(Clave otraClave){
	for (int i = 0; i < this->cantDimensiones; i++) {
		if (this->listaCampos[i] != NULL) {
			if (this->listaCampos[i]->comparar(otraClave.listaCampos[i]) != IGUAL) {
				return COMPARACION_NO_VALIDA;
			}
		} else if(otraClave.listaCampos[i] != NULL) {
			return COMPARACION_NO_VALIDA;
		}
	}
	return IGUAL;
}

/*
 * Funcion que evalúa solo la dimensión de esta clave con otra pasada por parámetro
 * Compara el campo correspondiente a la dimension que se quiere evaluar y
 * devuelve 0 si son iguales, -1 si el campo es menor que el pasado por parametro y
 * 1 si el campo es mayor.
 */
ResultadoComparacion Clave::comparar(Clave otraClave, int dimension){
	ResultadoComparacion resultComparacion = this->listaCampos[dimension]->comparar(otraClave.listaCampos[dimension]);
	return resultComparacion;
}

//TODO ver en Clave.h
ResultadoComparacion Clave::comparar(Campo* otraCampo) {
	// TODO  Hacer
	//ResultadoComparacion resultComparacion = this->listaCampos[dimension]->comparar(otraCampo);
	return COMPARACION_NO_VALIDA;
}


/*
 * Funcion que copia el contenido de la clave pasada por parametro a su clave.
 */
void Clave::copiar(Clave otraClave){
	Campo *unCampo;

	if (otraClave.getCampo(0) == NULL){
		this->listaCampos[0] = NULL;
	} else {
		unCampo = new Linea();	// Creo el campo Linea
		unCampo->copiar(otraClave.getCampo(0));	// Cargo el campo Linea de otraClave
//		this->listaCampos[0] = unCampo;	// Almaceno el campo en la clave
	}

	if (otraClave.getCampo(1) == NULL){
		this->listaCampos[1] = NULL;
	} else {
	unCampo = new Formacion();	// Creo el campo Formacion
	unCampo->copiar(otraClave.getCampo(1));	// Cargo el campo Formacion de otraClave
	this->listaCampos[1] = unCampo;	// Almaceno el campo de la clave
	}

	if (otraClave.getCampo(2) == NULL){
		this->listaCampos[2] = NULL;
	} else {
	unCampo = new FranjaHoraria();	// Creo el campo FranjaHoraria
	unCampo->copiar(otraClave.getCampo(2));	// Cargo el campo FranjaHoraria de otraClave
	this->listaCampos[2] = unCampo;	// Almaceno el campo de la clave
	}

	if (otraClave.getCampo(3) == NULL){
		this->listaCampos[3] = NULL;
	} else {
	unCampo = new Falla();	// Creo el campo Falla
	unCampo->copiar(otraClave.getCampo(3));	// Cargo el campo Falla de otraClave
	this->listaCampos[3] = unCampo;	// Almaceno el campo de la clave
	}

	if (otraClave.getCampo(4) == NULL){
		this->listaCampos[4] = NULL;
	} else {
	unCampo = new Formacion();	// Creo el campo Accidente
	unCampo->copiar(otraClave.getCampo(4));	// Cargo el campo Accidente de otraClave
	this->listaCampos[4] = unCampo;	// Almaceno el campo de la clave
	}
}
