/*
 * ArbolKD_test.h
 *
 *  Created on: May 26, 2012
 *      Author: matias_2
 */

#ifndef ARBOLKD_TEST_H_
#define ARBOLKD_TEST_H_

#include "../src/ArbolKD.h"

void ArbolKDTest() {

	cout << "Prueba Unitaria: Clase ArbolKD" << endl;

	ArbolKD* arbol = new ArbolKD();

	Clave* clave1 = new Clave("Linea1", 1000);
	Clave* clave2 = new Clave("Linea2", 2000);
	Clave* clave3 = new Clave("Linea3", 3000);
	Clave* clave4 = new Clave("Linea1", 4000);
	Clave* clave5 = new Clave("Linea2", 5000);
	Clave* clave6 = new Clave("Linea2", 6000);

	arbol->insertar(clave1);
	if (arbol->busquedaPuntual(clave1)->comparar(clave1) == IGUAL) {
		cout << "Ok.....Insercion 1er nivel." << endl;
	} else {
		cout << "Fail.....Insercion 1er nivel." << endl;
	}

	arbol->insertar(clave2);
	arbol->insertar(clave3);
	if (arbol->busquedaPuntual(clave3)->comparar(clave3) == IGUAL) {
		cout << "Ok.....Insercion 2do nivel." << endl;
	} else {
		cout << "Fail.....Insercion 2do nivel." << endl;
	}

	arbol->insertar(clave4);

	if (arbol->busquedaPuntual(clave4)->comparar(clave4) == IGUAL) {
		cout << "Ok.....Insercion 3er nivel." << endl;
	} else {
		cout << "Fail.....Insercion 3er nivel." << endl;
	}

	arbol->insertar(clave5);
	if (arbol->busquedaPuntual(clave5)->comparar(clave5) == IGUAL) {
		cout << "Ok.....Insercion BIS 3er nivel." << endl;
	} else {
		cout << "Fail.....Insercion BIS 3er nivel." << endl;
	}

	arbol->insertar(clave6);
	if (arbol->busquedaPuntual(clave6)->comparar(clave6) == IGUAL) {
		cout << "Ok.....Insercion 4er nivel." << endl;
	} else {
		cout << "Fail.....Insercion 4er nivel." << endl;
	}
	cout << "** End ArbolKDTest **" << endl;
}



#endif /* ARBOLKD_TEST_H_ */
