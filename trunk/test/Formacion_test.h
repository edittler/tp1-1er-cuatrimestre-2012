/*
 * Formacion_test.h
 *
 *  Created on: May 22, 2012
 *      Author: matias_2
 */

#ifndef FORMACION_TEST_H_
#define FORMACION_TEST_H_

#include "iostream"
#include "../src/campo/Formacion.h"
#include "../src/campo/Falla.h"

void FormacionTest() {

	std::cout << "Prueba Unitaria: Clase Formacion." << endl;

	Formacion* formacion1 = new Formacion(1000);
	Formacion* formacion2 = new Formacion(9999);

	if (formacion1->comparar(formacion2) == MENOR) {
		std::cout << "Ok.....comparacion menor" << endl;
	} else {
		std::cout << "Fail...comparacion menor" << endl;
	}

	if (formacion2->comparar(formacion1) == MAYOR) {
		std::cout << "Ok.....comparacion mayor" << endl;
	} else {
		std::cout << "Fail...comparacion mayor" << endl;
	}

	Formacion* formacion3 = new Formacion(*formacion2);
	if (formacion3->comparar(formacion2) == IGUAL) {
		std::cout << "Ok.....comparacion igual y constructor copia" << endl;
	} else {
		std::cout << "Fail...comparacion igual y constructor copia" << endl;
	}

	delete formacion2;
	formacion2 = NULL;

	if (formacion1->comparar(formacion2) == MAYOR) {
		std::cout << "Ok.....comparacion mayor con null" << endl;
	} else {
		std::cout << "Fail...comparacion mayor con null" << endl;
	}

	Falla* falla = new Falla("No anda wifi de vagones");
	if (formacion1->comparar(falla) == COMPARACION_NO_VALIDA) {
		std::cout << "Ok.....comparacion no valida" << endl;
	} else {
		std::cout << "Fail...comparacion no valida" << endl;
	}

	int* tam = new int();
	Formacion* formacion4 = new Formacion(1000);
	Byte* registro = formacion4->obtenerRegistro(tam);
	formacion4->setNumeroFormacion(3);
	//ignoro primer 4 bytes.
	Byte * regTamano;
	Byte * regTemp;
	obtenerPorcion(registro, &regTamano, 0, sizeof(int));
	int tamRegTamano = bytesToInt(regTamano);
	obtenerPorcion(registro, &regTemp, sizeof(int), tamRegTamano);
	//recupero registro ignorando primeros 4 bytes.
	formacion4->inicializarConRegistro(regTemp);
	if (formacion4->getNumeroFormacion() == 1000) {
		cout << "Ok.....obtener - inicializar registro" << endl;
	} else {
		cout << "Fail...obtener - inicializar registro" << endl;
	}

	delete falla;
	delete formacion1;
	delete formacion2;
	delete formacion3;
	delete formacion4;
	delete tam;
	delete registro;
	delete regTamano;
	delete regTemp;

}


#endif /* FORMACION_TEST_H_ */
