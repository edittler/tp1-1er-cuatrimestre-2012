/*
 * CampoCadena.cpp
 *
 *  Created on: May 22, 2012
 *      Author: matias_2
 */

#include "CampoCadena.h"

CampoCadena::CampoCadena() {

}

CampoCadena::CampoCadena(CampoCadena &campoCadena) {
	this->descripcion = campoCadena.descripcion;
}

CampoCadena::CampoCadena(string descripcion) {
	this->descripcion = descripcion;
}

CampoCadena::~CampoCadena() {

}

string CampoCadena::getDescripcion() {
	return this->descripcion;
}

void CampoCadena::setDescripcion(string descripcion) {
	this->descripcion = descripcion;
}

ResultadoComparacion CampoCadena::comparar(Campo* otroCampo) {
	if (otroCampo == NULL){
		return MAYOR;
	}

	CampoCadena* otraCampoCadena = dynamic_cast<CampoCadena*>(otroCampo);

	if (!otraCampoCadena) {
		return COMPARACION_NO_VALIDA;
	}

	if (otraCampoCadena->getDescripcion() < this->getDescripcion()) {
		return MAYOR;
	} else if (otraCampoCadena->getDescripcion() > this->getDescripcion()) {
		return MENOR;
	} else {
		return IGUAL;
	}
}

/* Funcion que genera la cadena de bytes para almacenar la Formacion. Debe recibir por
 * referencia un int que pueda almacenar el tamaño de la cadena, para su guardado
 * posterior en el archivo.
 */
Byte * CampoCadena::obtenerRegistro(int *tam){
	Byte *sizeString = new Byte[sizeof(int)];
	int tamDescripcion = this->descripcion.size();
	*sizeString =  tamDescripcion;
	Byte *string = convertirAByte(this->descripcion);
	int tamRegistro = 2*sizeof(int) + tamDescripcion;
	Byte *sizeRegistro = new Byte[sizeof(int)];
	*sizeRegistro = 4;
	Byte *tmp;
	concatenar(&tmp, sizeRegistro, 4, sizeString, 4);
	Byte *registro = new Byte[tamRegistro];
	concatenar(&registro, tmp, 8, string, tamDescripcion);
	*tam = sizeof(int);
	delete sizeString;
	delete string;
	delete tmp;
	return registro;
}

void CampoCadena::inicializarConRegistro(Byte * registro) {
	// los primeros 4 bytes corresponden a la longitud del string
	Byte * regTamDescripcion;
	int inicio = 0;
	int tamRegTamDescripcion = sizeof(int);
	obtenerPorcion(registro, &regTamDescripcion, inicio, tamRegTamDescripcion);
	int tamDescripcion = *regTamDescripcion;
	// conocida la longitud del string, procedo a leer esa cantidad de bytes
	Byte * regDescripcion;
	inicio = tamRegTamDescripcion; //incremento la posicion de lectura
	obtenerPorcion(registro, &regDescripcion, inicio, tamDescripcion);
	// dado que string y char * o en su defecto Byte * son el mismo tipo,
	// la asignacion es directa
	descripcion = regDescripcion; // inicializo descripcion
}
