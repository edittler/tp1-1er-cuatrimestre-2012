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


	/*** I N S E R C I O N E S ***/
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

	/*** B U S Q U E D A S ***/

	ArbolKD* arbol2 = new ArbolKD();
	//seteo clave 1
	Clave* c1 = new Clave("Linea1", 1);
	c1->setFalla("Puertas rotas");
	c1->setFranjaHoraria(new FranjaHoraria(new Fecha(2,1,2012), new Horario(1000, 1200)));
	c1->setAccidente("Accidente nro1");
	arbol2->insertar(c1);

	//seteo clave2
	Clave* c2 = new Clave("Linea2", 2);
	c2->setFalla("Ventanas rotas");
	c2->setFranjaHoraria(new FranjaHoraria(new Fecha(2,1,2012), new Horario(1000, 1200)));
	c2->setAccidente("Accidente nro9");
	arbol2->insertar(c2);

	//seteo clave3
	Clave* c3 = new Clave("Linea3", 3);
	c3->setFalla("Puertas rotas");
	c3->setFranjaHoraria(new FranjaHoraria(new Fecha(2,3,2012), new Horario(1000, 1200)));
	c3->setAccidente("Accidente nro1");
	arbol2->insertar(c3);

	//seteo clave4
	Clave* c4 = new Clave("Linea2", 2);
	c4->setFalla("Nuevamente Ventanas rotas");
	c4->setFranjaHoraria(new FranjaHoraria(new Fecha(2,5,2012), new Horario(1000, 1200)));
	c4->setAccidente("Accidente nro2");
	arbol2->insertar(c4);

	cout << "Busquedas: validar que sean las mismas salidas que los comentarios del codigo." << endl;
	cout << "Busqueda trenes(lineas) con falla:" << endl;
	arbol2->getTrenesConFalla(new Falla("Puertas rotas"), new Fecha(1,1,2012), new Fecha(5,1,2012)); //Linea1
	cout << "Busqueda trenes(lineas) con accidentes:" << endl;
	arbol2->getTrenesConAccidente(new Accidente("Accidente nro9"), new Fecha(1,1,2012), new Fecha(5,1,2012)); //Linea2
	cout << "Busqueda Fallas de formacion:" << endl;
	arbol2->getFallasDeFormacion(new Formacion(2), NULL, NULL); // Ventanas Rotas, Nuevamente Ventanas Rotas
	cout << "Busqueda accidedentes de formacion:" << endl;
	arbol2->getAccidenteDeFormacion(new Formacion(2), NULL, NULL); // Accidente nro9, Accidente nro2
	cout << "Busqueda accidentes de formacion con fecha inicio pero fecha fin = NULL:" << endl;
	arbol2->getAccidenteDeFormacion(new Formacion(2), new Fecha(1,1,2000), NULL); // Accidente nro9, Accidente nro2
	cout << endl;
	cout << "** End ArbolKDTest **" << endl;
	cout << endl;
}



#endif /* ARBOLKD_TEST_H_ */
