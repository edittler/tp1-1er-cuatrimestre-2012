#include "../src/campo/Fecha.h"

void FechaTest() {
	cout << "Prueba unitaria: Clase Fecha" <<endl;

	Fecha* fecha1 = new Fecha();

	fecha1->setFecha(99,1,2012);
	if (fecha1->getFechaInt() == 20120101) {
		cout << "Ok.....validar fecha" <<endl;
	} else {
		cout << "Fail...validar fecha" <<endl;
	}

	fecha1->setFecha(25, 5, 2012);
	if (fecha1->getFechaInt() == 20120525) {
		cout << "Ok.....set/get fecha" <<endl;
	} else {
		cout << "Fail...set/get fecha" <<endl;
	}

	if (fecha1->getFechaString() == "25/5/2012") {
		cout << "Ok.....get fecha string" <<endl;
	} else {
		cout << "Fail...get fecha string" <<endl;
	}

	Fecha* fecha2 = new Fecha(20, 5, 2013);

	if (fecha1->comparar(fecha2) == MENOR) {
		cout << "Ok.....comparacion menor" <<endl;
	} else {
		cout << "Fail...comparacion menor" <<endl;
	}

	if (fecha2->comparar(fecha1) == MAYOR) {
		cout << "Ok.....comparacion mayor" <<endl;
	} else {
		cout << "Fail...comparacion mayor" <<endl;
	}

	fecha1->setFecha(20, 5, 2013);
	if (fecha2->comparar(fecha1) == IGUAL) {
		cout << "Ok.....comparacion igual" <<endl;
	} else {
		cout << "Fail...comparacion igual" <<endl;
	}

	cout << endl;

}
