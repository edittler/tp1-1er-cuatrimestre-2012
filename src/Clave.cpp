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
	// Copio el campo Linea
	if (otraClave.getCampo(0) == NULL){
		this->listaCampos[0] = NULL;
	} else {
		// Verifico si es campo Linea con un casteo dinamico
		Linea* unaLinea = dynamic_cast<Linea*>(otraClave.listaCampos[0]);
		if (unaLinea) {
			// Si el casteo fallo, establezco como null el puntero de Linea
			this->listaCampos[0] = NULL;
		} else {
			Linea* otraLinea = new Linea(unaLinea->getDescripcion());	// Creo el campo Linea
			this->listaCampos[0] = otraLinea;	// Almaceno el campo en la clave
		}
	}
	// Copio el campo Formacion
	if (otraClave.getCampo(1) == NULL){
		this->listaCampos[1] = NULL;
	} else {
		// Verifico si es campo Formacion con un casteo dinamico
		Formacion* unaFormacion = dynamic_cast<Formacion*>(otraClave.listaCampos[1]);
		if (unaFormacion) {
			this->listaCampos[1] = NULL;
		} else {
			Formacion* otraFormacion = new Formacion(unaFormacion->getNumeroFormacion());	// Creo el campo Formacion
			this->listaCampos[1] = otraFormacion;	// Almaceno el campo de la clave
		}
	}
	// Copio el campo FranjaHoraria
	if (otraClave.getCampo(2) == NULL){
		this->listaCampos[2] = NULL;
	} else {
		// Verifico si es campo FranjaHoraria con un casteo dinamico
		FranjaHoraria* unaFranjaHoraria = dynamic_cast<FranjaHoraria*>(otraClave.listaCampos[2]);
		if (unaFranjaHoraria) {
			this->listaCampos[2] = NULL;
		} else {
			FranjaHoraria *otraFranjaHoraria = new FranjaHoraria(unaFranjaHoraria->getFecha(), unaFranjaHoraria->getHorario());	// Creo el campo FranjaHoraria
			this->listaCampos[2] = otraFranjaHoraria;	// Almaceno el campo de la clave
		}
	}
	// Copio el campo Falla
	if (otraClave.getCampo(3) == NULL){
		this->listaCampos[3] = NULL;
	} else {
		// Verifico si es campo FranjaHoraria con un casteo dinamico
		Falla* unaFalla = dynamic_cast<Falla*>(otraClave.listaCampos[3]);
		if (unaFalla) {
			this->listaCampos[3] = NULL;
		} else {
			Falla *otraFalla = new Falla(unaFalla->getDescripcion());	// Creo el campo Falla
			this->listaCampos[3] = otraFalla;	// Almaceno el campo de la clave
		}
	}
	// Copio el campo Accidente
	if (otraClave.getCampo(4) == NULL){
		this->listaCampos[4] = NULL;
	} else {
		// Verifico si es campo Accidente con un casteo dinamico
		Accidente* unAccidente = dynamic_cast<Accidente*>(otraClave.listaCampos[4]);
		if (unAccidente) {
			this->listaCampos[4] = NULL;
		} else {
			Accidente *otroAccidente = new Accidente(unAccidente->getDescripcion());	// Creo el campo Accidente
			this->listaCampos[4] = otroAccidente;	// Almaceno el campo de la clave
		}
	}
}
