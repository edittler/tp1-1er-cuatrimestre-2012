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

void ByteTest(){

	cout << "Prueba Unitaria: Byte" << endl;

	Byte a[] = "pajaro";
	Byte b[] = "pepe";
	Byte *c;
	obtenerSuma(&c, a, 6, b, 5);
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;

	Byte *d;
	obtenerPorcion(c, &d, 5, 3);
	cout << d << endl;

	delete c;
	delete d;
}

#endif /* BYTE_TEST_H_ */
