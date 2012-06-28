/*
 * Implementacion de la clase FranjaHoraria, que hereda de Campo y forma una de las dimensiones
 * de Clave
 *
 *  Created on: 21/05/2012
 *      Author: ezequiel
 */

#include "FranjaHoraria.h"

FranjaHoraria::FranjaHoraria() {
	this->fecha = new Fecha();
	this->horario = new Horario();
}

FranjaHoraria::FranjaHoraria(FranjaHoraria& franja) {
	this->fecha = new Fecha(*franja.getFecha());
	this->horario = new Horario(*franja.getHorario());
}

FranjaHoraria::FranjaHoraria(Fecha* fecha, Horario* horario) {
	if (fecha != NULL) {
		this->fecha = new Fecha(*fecha);
	} else {
		this->fecha = NULL;
	}

	if (horario != NULL) {
		this->horario = new Horario(*horario);
	} else {
		this->horario = NULL;
	}
}

FranjaHoraria::~FranjaHoraria() {
	delete this->fecha;
	delete this->horario;
}

Fecha* FranjaHoraria::getFecha() {
	return this->fecha;
}

void FranjaHoraria::setFecha(Fecha* fecha) {
	if (this->fecha != NULL) {
		delete this->fecha;
	}
	this->fecha = fecha;
}

Horario* FranjaHoraria::getHorario() {
	return this->horario;
}

void FranjaHoraria::setHorario(Horario* horario) {
	if (this->horario != NULL) {
		delete this->horario;
	}
	this->horario = horario;
}

ResultadoComparacion FranjaHoraria::comparar(Campo* otroCampo){
	if (otroCampo == NULL){
		return MAYOR;
	}

	FranjaHoraria* otraFranjaHoraria = dynamic_cast<FranjaHoraria*>(otroCampo);

	if (!otraFranjaHoraria) {
		return COMPARACION_NO_VALIDA;
	}

	if (this->fecha->comparar(otraFranjaHoraria->getFecha()) == MAYOR) {
		return MAYOR;
	} else if (this->fecha->comparar(otraFranjaHoraria->getFecha()) == MENOR) {
		return MENOR;
	} else if (this->horario->comparar(otraFranjaHoraria->getHorario()) == MAYOR) {
		return MAYOR;
	} else if (this->horario->comparar(otraFranjaHoraria->getHorario()) == MENOR) {
		return MENOR;
	} else {
	return IGUAL;
	}
}

/* Funcion que genera la cadena de bytes para almacenar la FranjaHoraria. Debe recibir por
 * referencia un int que pueda almacenar el tamaño de la cadena, para su guardado
 * posterior en el archivo.
 */
Byte * FranjaHoraria::obtenerRegistro (int *tam){
	// Obtengo la serializacion de la fecha y su tamaño
	int tamFecha;
	Byte *regFecha = this->fecha->obtenerRegistro(&tamFecha);
	// Obtengo la serialización de la hora y su tamaño
	int tamHora;
	Byte *regHora = this->horario->obtenerRegistro(&tamHora);
	// Obtengo el tamaño de ambos campos y los concateno
	int tamReg = tamFecha + tamHora;
	Byte *tmp;
	concatenar(&tmp, regFecha, tamFecha, regHora, tamHora);
	delete regFecha;
	delete regHora;

	// Calculo el tamaño total de la serializacion, y concateno junto con el tamaño de los campos
	Byte *tamRegistro = intToBytes(tamReg);
	*tam = tamReg + sizeof(int);
	Byte *registro;
	concatenar(&registro, tamRegistro, sizeof(int), tmp, tamReg);
	delete tmp;
	delete tamRegistro;
	return registro;
}

void FranjaHoraria::inicializarConRegistro(Byte * registro) {
	// obtengo el tamanio del registro fecha
	Byte * tamRegFecha;
	int inicio = 0;
	int tamReg = sizeof(int);
	obtenerPorcion(registro, &tamRegFecha, inicio, tamReg);
	inicio += tamReg;
	tamReg = *tamRegFecha;
	//obtengo el registro fecha
	Byte * regFecha;
	obtenerPorcion(registro, &regFecha, inicio, tamReg);
	inicio += tamReg;
	tamReg = sizeof(int);
	//inicializo la fecha
	fecha->inicializarConRegistro(regFecha);
	//obtengo el tam del registro horario
	Byte * tamRegHorario;
	obtenerPorcion(registro, &tamRegHorario, inicio, tamReg);
	inicio += tamReg;
	tamReg = *tamRegHorario;
	//obtengo el registro hora
	Byte * regHorario;
	obtenerPorcion(registro, &regHorario, inicio, tamReg);
	//inicializo el horario
	horario->inicializarConRegistro(regHorario);
}
