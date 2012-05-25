/*
 * FranjaHoraria_test.h
 *
 *  Created on: May 22, 2012
 *      Author: matias_2
 */

#ifndef FRANJAHORARIA_TEST_H_
#define FRANJAHORARIA_TEST_H_

#include "../src/campo/FranjaHoraria.h"

void FranjaHorariaTest() {

	cout << "Prueba unitaria: Clase FranjaHoraria" <<endl;

	Fecha* fecha1 = new Fecha(25, 5, 2012);
	Horario* horario1 = new Horario(2030, 2130);

	FranjaHoraria* franja1 = new FranjaHoraria(fecha1, horario1);

	Fecha* fecha2 = new Fecha(20, 5, 2012);
	Horario* horario2 = new Horario(0000, 0100);
	FranjaHoraria* franja2 = new FranjaHoraria(fecha2, horario2);

	if (franja1->comparar(franja2) == MAYOR) {
		std::cout << "Ok.....comparacion mayor" << endl;
	} else {
		std::cout << "Fail...comparacion mayor" << endl;
	}

	if (franja2->comparar(franja1) == MENOR) {
		std::cout << "Ok.....comparacion menor" << endl;
	} else {
		std::cout << "Fail...comparacion menor" << endl;
	}

	if (franja1->comparar(franja1) == IGUAL) {
		std::cout << "Ok.....comparacion igual" << endl;
	} else {
		std::cout << "Fail...comparacion igual" << endl;
	}

	Falla* falla = new Falla();
	if (franja1->comparar(falla) == COMPARACION_NO_VALIDA) {
		std::cout << "Ok.....comparacion no valida" << endl;
	} else {
		std::cout << "Fail...comparacion no valida" << endl;
	}

	cout << endl;
}


#endif /* FRANJAHORARIA_TEST_H_ */
