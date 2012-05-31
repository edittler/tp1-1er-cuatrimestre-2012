/*
 * Clave_test.h
 *
 *  Created on: May 25, 2012
 *      Author: matias_2
 */

#ifndef CLAVE_TEST_H_
#define CLAVE_TEST_H_

#include "../src/Clave.h"

void ClaveTest() {
	cout << "Prueba Unitaria: Clase Clave." << endl;

	Clave* clave1 = new Clave("Tren al cielo", 666);

	if (clave1->getCampo(0)->comparar(new Linea("Tren al cielo")) == IGUAL) {
		cout << "Ok.....getCampo(dimension)" << endl;
	} else {
		cout << "Fail...getCampo(dimension)" << endl;
	}

	Falla* falla = new Falla("Vagon comedor no disponible.");
	clave1->setFalla("Vagon comedor no disponible.");

	if (clave1->getCampo(3)->comparar(falla) == IGUAL) {
		cout << "Ok.....setFalla" << endl;
	} else {
		cout << "Fail...setFalla" << endl;
	}

	Clave* clave2 =  new Clave ("Tren al cielo", 666);
	Clave* clave3 = new Clave (*clave2);
	if (clave3->comparar(clave2) == IGUAL) {
		cout << "Ok.....comparar clave igual" << endl;
	} else {
		cout << "Fail...comparar clave igual" << endl;
	}

	delete clave1;
	clave1 = NULL;

	if (clave2->comparar(clave1) == COMPARACION_NO_VALIDA) {
		cout << "Ok.....comparar con clave nula (comparacion no valida)" << endl;
	} else {
		cout << "Fail...comparar con clave nula (comparacion no valida)" << endl;
	}

	clave2->setFalla("Sin luces externas");
	if (clave3->comparar(clave2) == COMPARACION_NO_VALIDA) {
		cout << "Ok.....comparar clave casi igual (comparacion no valida)" << endl;
	} else {
		cout << "Fail...comparar clave casi igual (comparacion no valida)" << endl;
	}

	cout << endl;

	delete clave2;
	delete clave3;
	delete falla;
}

#endif /* CLAVE_TEST_H_ */
