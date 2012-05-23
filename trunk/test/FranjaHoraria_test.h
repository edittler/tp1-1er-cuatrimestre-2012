/*
 * FranjaHoraria_test.h
 *
 *  Created on: May 22, 2012
 *      Author: matias_2
 */

#ifndef FRANJAHORARIA_TEST_H_
#define FRANJAHORARIA_TEST_H_

#include "../src/campo/FranjaHoraria.h"

void FranjaHoraria_test() {

	cout << "Prueba unitaria: Clase FranjaHoraria" <<endl;

	FranjaHoraria* franja1 = new FranjaHoraria();

	franja1->setFecha(20120521);
	franja1->setHorario(20302130);

	cout << "Fecha String:" << franja1->getFechaString() << endl;

}


#endif /* FRANJAHORARIA_TEST_H_ */
