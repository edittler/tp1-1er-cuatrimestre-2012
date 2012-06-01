/*
 * Byte_test.h
 *
 *      Author: ezequiel
 */

#ifndef BYTE_TEST_H_
#define BYTE_TEST_H_

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "../src/Byte.h"

using namespace std;
/*
void ByteTest(){

	cout << "Prueba Unitaria: Byte" << endl;

	Byte *cadena1 = new Byte(20);
	for(int i = 0; i < 20; i++){
		if ((i % 2) == 0) cadena1[i] = 'a';
		else cadena1[i] = 'b';
	}
	Byte *cadena2 = NULL; //puntero donde se almacenará el resultado
	obtenerPorcion(cadena1, cadena2, 0, 10);
	bool esIgual = true;
	int i=0;
	while (esIgual && (i < 10)){
		if (cadena1[i] != cadena2[i])
			esIgual = false;
	}

	if (esIgual) {
		cout << "Ok.....obtener porcion" << endl;
	} else {
		cout << "Fail...obtener porcion" << endl;
	}
}
*/
#endif /* BYTE_TEST_H_ */
