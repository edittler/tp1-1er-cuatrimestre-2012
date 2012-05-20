/*
 * Formacion.h
 *
 *  Created on: 19/05/2012
 *      Author: Alejandro Daza
 */

#ifndef FORMACION_H_
#define FORMACION_H_

#include "Campo.h"

class Formacion: public Campo {
private:
	int numFormacion;
public:
	Formacion(int);
	int getFormacion();
	virtual ~Formacion();
};

#endif /* FORMACION_H_ */
