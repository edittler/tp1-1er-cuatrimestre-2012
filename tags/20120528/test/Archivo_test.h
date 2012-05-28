/*
 * Archivo_test.h
 *
 *  Created on: 25/05/2012
 *      Author: Alejandro Daza
 */

#ifndef ARCHIVO_TEST_H_
#define ARCHIVO_TEST_H_

#include "../src/Archivo.h"
#include <iostream>

using namespace std;

void ArchivoTest() {

	cout << "Clase Archivo test" << endl;

	cout << "Prueba: escribir, 1er bloque" << endl;

	Archivo archivo = Archivo("escribir.bin");
	char p1nombre[] = "Alejandro";
	PosBloque p1bloque;
	// escribo un bloque de memoria de tamaño 10 y recibo el bloque donde se insertó
	p1bloque = archivo.escribir(p1nombre, 10);
	cout << "Se insertó en bloque: " << p1bloque << endl;

	cout << "Prueba: leer, 1er bloque" << endl;

	char * p2nombre;
	int tam;
	// leo el bloque de memoria que se insertó en la posición anterior
	archivo.leer(p1bloque, &p2nombre, &tam);
		cout << "El tamanio es: " << tam << endl;
		int i;
		for (i=0; i<tam; i++) {
			cout << p2nombre[i];
		}
		cout << endl;

	cout << "Prueba: escribir, 2do bloque" << endl;

	char p3apellido[] = "Daza";
	PosBloque p3bloque;
	p3bloque = archivo.escribir(p3apellido, 5);
	cout << "Se insertó en bloque: " << p3bloque << endl;

	cout << "Prueba: leer, 2do bloque" << endl;

	char * p4apellido;
	// leo el bloque de memoria que se insertó en la posición anterior
	archivo.leer(p3bloque, &p4apellido, &tam);
	cout << "El tam es: " << tam << endl;
	for (i=0; i<tam; i++) {
		cout << p4apellido[i];
	}
	cout << endl;

	cout <<"Prueba: leer, 1er bloque, de nuevo" << endl;
	char *p5nombre;
	archivo.leer(p1bloque, &p5nombre, &tam);
	cout << "El tam es: " << tam << endl;
	for (i=0; i<tam; i++) {
		cout << p5nombre[i];
	}
	cout << endl;

	cout <<"Prueba: liberarBloque, libero el 1er bloque" << endl;
	// libero un bloque porque ya no lo necesito, debería liberar el bloque 0 y la próxima vez que escriba escribir en el 0 y no en el 2
	archivo.liberarBloque(p1bloque);

	char p6nombre[] = "Albert Einstein";
	PosBloque p6bloque;
	p6bloque = archivo.escribir(p6nombre, 16);

	cout << "Se libero el bloque: " << p6bloque << endl;
	cout << "Prueba: escribir, sobre bloque liberado" << endl;

	cout << "Se insertó en bloque: " << p6bloque << endl;

	cout << "Prueba: escribir, con bloque liberado escrito" << endl;

	char p7nombre[] = "Donald";
	PosBloque p7bloque;
	p7bloque = archivo.escribir(p7nombre, 7);
	cout << "Se insertó en bloque: " << p7bloque << endl;

}



#endif /* ARCHIVO_TEST_H_ */
