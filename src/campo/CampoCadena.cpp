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

/* Funcion que genera la cadena de bytes para almacenar la Formacion. Debe recibir por
 * referencia un int que pueda almacenar el tamaño de la cadena, para su guardado
 * posterior en el archivo.
 */
Byte * CampoCadena::obtenerRegistro(int *tam){
	//Obtengo el tamaño de la cadena y lo serializo
	int tamDescripcion = this->descripcion.size()+1; //agrego 1 para incluir el caracter nulo
	Byte *sizeString = new Byte[sizeof(int)];
	*sizeString =  tamDescripcion;
	// Serializo la descripcion
	Byte *string = convertirAByte(this->descripcion);
	// Defino el tamaño de 'sizeString'+'string' y lo serializo
	int tamRegistro = (int)sizeof(int) + tamDescripcion;
	Byte *sizeRegistro = new Byte[sizeof(int)];
	*sizeRegistro =  tamRegistro;
	// Defino el tamaño total que va a tener la serializacion
	*tam = sizeof(int)*3 + tamDescripcion;
	// concateno los integer
	Byte *tmp;
	concatenar(&tmp, sizeRegistro, 4, sizeString, 4);
	// concateno el tmp con la descripcion
	Byte *registro;
	concatenar(&registro, tmp, 8, string, tamDescripcion);
	// elimino los punteros internos
	delete sizeString;
	delete string;
	delete tmp;
	//retorno
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
