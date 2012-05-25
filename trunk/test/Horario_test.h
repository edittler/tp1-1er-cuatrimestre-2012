#include "../src/campo/Horario.h"

void HorarioTest() {
	cout << "Prueba unitaria: Clase Horario" <<endl;


	Horario* horario1 = new Horario();

	horario1->setHorario(2400, 2068);
	if (horario1->getComienzoString() == "0:0" && horario1->getFinString() == "0:0") {
		cout << "Ok.....validar horario" <<endl;
	} else {
		cout << "Fail...validar horario" <<endl;
	}

	horario1->setHorario(2030, 2130);
	if (horario1->getComienzoString() == "20:30") {
		cout << "Ok.....getComienzoString" <<endl;
	} else {
		cout << "Fail...getComienzoString" <<endl;
	}

	if (horario1->getFinString() == "21:30") {
		cout << "Ok.....getFinString" <<endl;
	} else {
		cout << "Fail...getFinString" <<endl;
	}

	if (horario1->getIntervaloString() == "20:30 - 21:30") {
		cout << "Ok.....getIntervaloString" <<endl;
	} else {
		cout << "Fail...getIntervaloString" <<endl;
	}

	Horario* horario2 = new Horario(2130, 2200);
	if (horario1->comparar(horario2) == MENOR) {
		cout << "Ok.....comparacion menor" <<endl;
	} else {
		cout << "Fail...comparacion menor" <<endl;
	}

	if (horario2->comparar(horario1) == MAYOR) {
		cout << "Ok.....comparacion mayor" <<endl;
	} else {
		cout << "Fail...comparacion mayor" <<endl;
	}

	if (horario1->comparar(horario1) == IGUAL) {
		cout << "Ok.....comparacion igual" <<endl;
	} else {
		cout << "Fail...comparacion igual" <<endl;
	}

	cout << endl;
}
