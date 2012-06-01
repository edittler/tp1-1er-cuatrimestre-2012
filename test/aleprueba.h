/*
 * aleprueba.h
 *
 *  Created on: 31/05/2012
 *      Author: dude
 */

#ifndef ALEPRUEBA_H_
#define ALEPRUEBA_H_

#include "../src/Byte.h"
#include <iostream>

using namespace std;

void aletest() {

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
}


#endif /* ALEPRUEBA_H_ */
