/*
 * Archivo_test.h
 *
 *  Created on: May 25, 2012
 *      Author: matias_2
 */

#ifndef ARCHIVO_TEST_H_
#define ARCHIVO_TEST_H_

#include "../src/Archivo.h"

void ArchivoTest() {

	cout << "Prueba Unitaria: Clase Archivo." << endl;

	Archivo* archivo = new Archivo("datos.bin");
	Byte bloqueMemoria[] = "Bjarne Stroustrup";
	PosBloque bloqueEscrito = archivo->escribir(bloqueMemoria, 18);

	Byte * contenido;
	int tam;
	archivo->leer(bloqueEscrito, &contenido, &tam);

	//TODO hacer comparacion entre Byte* y string.
//	if (contenido == "Bjarne Stroustrup") {
//		cout << "Ok.....leer/escribir" << endl;
//	} else {
//		cout << "Fail...leer/escribir" << endl;
//	}

	cout << contenido << " == " << "Bjarne Stroustrup" << endl;

	delete archivo;
	cout << endl;
}


#endif /* ARCHIVO_TEST_H_ */
