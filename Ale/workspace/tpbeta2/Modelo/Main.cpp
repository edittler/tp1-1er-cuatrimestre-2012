#include <iostream>
#include "Formacion.h"

int main () {

	Formacion formacion = Formacion(128);

	int numero = formacion.getFormacion();

	std::cout << numero;
	std::cout << sizeof(formacion);
	std::cout << sizeof(numero);

	return 0;
}
