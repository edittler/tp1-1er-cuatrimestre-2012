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
//	Clave* clave4 = new Clave();
//	Clave* clave5 = new Clave();
//	Clave* clave6 = new Clave();



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

	Linea* l = dynamic_cast<Linea*>(arbol->busquedaPuntual(clave1)->getCampo(0));
	Formacion* f = dynamic_cast<Formacion*>(arbol->busquedaPuntual(clave1)->getCampo(1));
	cout << "Linea: " << l->getDescripcion() << endl;
	cout << "Formacion: " <<  f->getNumeroFormacion() << endl;

	cout << "** End ARbolKDTest **" << endl;
}



#endif /* ARBOLKD_TEST_H_ */
