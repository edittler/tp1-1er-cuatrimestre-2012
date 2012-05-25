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

//	// instancio campos de la clave.
//	Linea* linea = new Linea("Tren Fantasma");
//	Formacion* formacion = new Formacion(150);
//	FranjaHoraria* franja = new FranjaHoraria(new Fecha(25, 5, 2012), new Horario(1700, 1800));
//	Accidente* accidente = new Accidente("Delirio social.");

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
	Clave* clave3 = new Clave ("Tren al cielo", 666);
	if (clave3->comparar(*clave2) == IGUAL) {
		cout << "Ok.....comparar clave" << endl;
	} else {
		cout << "Fail...comparar clave" << endl;
	}

	cout << endl;
}


#endif /* CLAVE_TEST_H_ */
