/*
 * kdNodoHoja_test.h
 *
 *  Created on: 28/05/2012
 *      Author: Alejandro Daza
 */

#ifndef KDNODOHOJA_TEST_H_
#define KDNODOHOJA_TEST_H_

#include "../src/kdNodoHoja.h"
#include "../src/Clave.h"
#include "../src/campo/FranjaHoraria.h"
#include <iostream>
using namespace std;

void kdNodoHojaTest() {

	kdNodoHoja p1nodo = kdNodoHoja();
	cout << "Prueba Unitaria: Clase kdNodoHoja" << endl;

	// Prueba insertar

	cout << "test insertar:" << endl;

	Clave * p1clave1 = new Clave();
	p1clave1->setLinea("Sarmiento");
	Horario * p1horario1 = new Horario(0000, 0030);
	Fecha * p1fecha1 = new Fecha(21, 2, 2012);
	FranjaHoraria * p1franja1 = new FranjaHoraria(p1fecha1, p1horario1);
	p1clave1->setFranjaHoraria(p1franja1);
	p1clave1->setFalla("cierran 50%");
	p1clave1->setAccidente("incendio");
	p1clave1->setFormacion(256);

	int p1insertar = p1nodo.insertar(*p1clave1);
	if (p1insertar == 1) {
		cout << "ok....insertar 1ra clave, actualizo 1" << endl;
	}
	else {
		cout << "fallo....insertar 1ra clave, actualizo 1" << endl;
	}

	Clave * p1clave5 = new Clave();
	p1clave5->setLinea("Sarmiento");
	Horario * p1horario5 = new Horario(0000, 0030);
	Fecha * p1fecha5 = new Fecha(21, 2, 2012);
	FranjaHoraria * p1franja5 = new FranjaHoraria(p1fecha5, p1horario5);
	p1clave5->setFranjaHoraria(p1franja5);
	p1clave5->setFalla("cierran 50%");
	p1clave5->setAccidente("incendio");
	p1clave5->setFormacion(256);

	p1insertar = p1nodo.insertar(*p1clave5);
		if (p1insertar == 3) {
			cout << "ok....insertar 2da clave, repeticion 3" << endl;
		}
		else {
			cout << "fallo....insertar 2da clave, repeticion 3" << " devolvio: " << p1insertar << endl;
		}


	Clave * p1clave2 = new Clave();
	p1clave2->setLinea("Roca");
	Horario * p1horario2 = new Horario(1930, 2000);
	Fecha * p1fecha2 = new Fecha(3, 4, 2012);
	FranjaHoraria * p1franja2 = new FranjaHoraria(p1fecha2, p1horario2);
	p1clave2->setFranjaHoraria(p1franja2);
	p1clave2->setFalla("cierran 80%");
	p1clave2->setAccidente("incendio");
	p1clave2->setFormacion(300);

	p1insertar = p1nodo.insertar(*p1clave2);
		if (p1insertar == 1) {
			cout << "ok....insertar 3ra clave, actualizo 1" << endl;
		}
		else {
			cout << "fallo....insertar 3ra clave, actualizo 1" << endl;
		}

	Clave * p1clave3 = new Clave();
	p1clave3->setLinea("Mitre");
	Horario * p1horario3 = new Horario(1930, 2000);
	Fecha * p1fecha3 = new Fecha(3, 8, 2012);
	FranjaHoraria * p1franja3 = new FranjaHoraria(p1fecha3, p1horario3);
	p1clave3->setFranjaHoraria(p1franja3);
	p1clave3->setFalla("cierran 80%");
	p1clave3->setAccidente("incendio");
	p1clave3->setFormacion(400);

	p1insertar = p1nodo.insertar(*p1clave3);
		if (p1insertar == 2) {
			cout << "ok....insertar 4ta clave, desborde 2" << endl;
		}
		else {
			cout << "fallo....insertar 4ta clave, desborde 2" << endl;
		}

	Clave * p1clave4 = new Clave();
	p1clave4->setLinea("Mitre");
	Horario * p1horario4 = new Horario(1930, 2000);
	Fecha * p1fecha4 = new Fecha(3, 9, 2012);
	FranjaHoraria * p1franja4 = new FranjaHoraria(p1fecha4, p1horario4);
	p1clave4->setFranjaHoraria(p1franja4);
	p1clave4->setFalla("cierran 80%");
	p1clave4->setAccidente("incendio");
	p1clave4->setFormacion(256);

	p1insertar = p1nodo.insertar(*p1clave4);
	if (p1insertar == 0) {
		cout << "ok....insertar 5ta clave, sobreflujo 0" << endl;
	}
	else {
		cout << "fallo....insertar 5ta clave, sobreflujo 0" << endl;
	}

	// Prueba getValorMedio
	cout << "test getValorMedio:" << endl;
	Formacion * p3formacionmedio = dynamic_cast<Formacion *>(p1nodo.getValorMedio(1));
	int p3medio = p3formacionmedio->getNumeroFormacion();
	if (p3medio == 400) {
		cout << "ok....getValorMedio" << endl;
	}
	else {
		cout << "fallo....getValorMedio " << "devolvio: " << p3medio << " deberia devolver 400" << endl;
	}

	// Prueba eliminar

	cout << "test eliminar:" << endl;

	Clave * p2clave1 = new Clave();
	p2clave1->setLinea("Sarmientoo");
	Horario * p2horario1 = new Horario(0000, 0030);
	Fecha * p2fecha1 = new Fecha(21, 2, 2012);
	FranjaHoraria * p2franja1 = new FranjaHoraria(p2fecha1, p2horario1);
	p2clave1->setFranjaHoraria(p2franja1);
	p2clave1->setFalla("cierran 50%");
	p2clave1->setAccidente("incendio");
	p2clave1->setFormacion(256);

	int p2insertar = p1nodo.eliminar(*p2clave1);
	if (p2insertar == 3) {
		cout << "ok....eliminar clave, no existe 3" << endl;
	}
	else {
		cout << "fallo....eliminar clave, no existe 3" << endl;
	}

	p2insertar = p1nodo.eliminar(*p1clave1);
	if (p2insertar == 1) {
		cout << "ok....eliminar 1ra clave, exito 1" << endl;
	}
	else {
		cout << "fallo....eliminar 1ra clave, exito 1" << endl;
	}

	p2insertar = p1nodo.eliminar(*p1clave2);
	if (p2insertar == 1) {
		cout << "ok....eliminar 2da clave, exito 1" << endl;
	}
	else {
		cout << "fallo....eliminar 2da clave, exito 1" << endl;
	}

	p2insertar = p1nodo.eliminar(*p1clave3);
	cout << p2insertar;
	if (p2insertar == 2) {
		cout << "ok....eliminar 3ra clave, subflujo 2" << endl;
	}
	else {
		cout << "fallo....eliminar 3ra clave, subflujo 2" << endl;
	}

	Clave* clave = new Clave("Linea1", 1000);
	kdNodoHoja* nodoHoja = new kdNodoHoja(*clave);
	int* tam = new int();
	Byte* registro = nodoHoja->obtenerRegistro(tam);
	clave->setLinea("linea3");
	//ignoro primer 4 bytes.
	Byte * regTamano;
	Byte * regTemp;
	obtenerPorcion(registro, &regTamano, 0, sizeof(int));
	int tamRegTamano = *regTamano;
	obtenerPorcion(registro, &regTemp, sizeof(int), tamRegTamano);
	//recupero registro ignorando primeros 4 bytes.
	clave->inicializarConRegistro(regTemp);
	if (dynamic_cast<Linea*>(clave->getCampo(0))->getDescripcion() == "linea3") {
		cout << "Ok.....obtener - inicializar registro" << endl;
	} else {
		cout << "Fail...obtener - inicializar registro" << endl;
	}
}


#endif /* KDNODOHOJA_TEST_H_ */
