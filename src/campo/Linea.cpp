/*
 * Implementacion de la clase Linea, que hereda de Campo y forma una de las dimensiones de Clave
 *
 *  Created on: 21/05/2012
 *      Author: ezequiel
 */

#include "Linea.h"
#include "Campo.h"

Linea::Linea() : CampoCadena() {

}

Linea::Linea(Linea& linea) : CampoCadena(linea) {

}

Linea::Linea(string nombreLinea) : CampoCadena(nombreLinea){
}

Linea::~Linea() {

}

void Linea::inicializarConRegistro(Byte * registro) {
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
