/*
 * CampoCadena.h
 *
 *  Created on: May 22, 2012
 *      Author: matias_2
 */

#ifndef CAMPOCADENA_H_
#define CAMPOCADENA_H_

#include "Campo.h"
#include "iostream"

using namespace std;

class CampoCadena: public Campo {
private:
	string descripcion;

public:
	CampoCadena();
	CampoCadena(CampoCadena &campoCadena);
	CampoCadena(string descripcion);
	virtual ~CampoCadena();

	string getDescripcion();
	void setDescripcion(string descripcion);

	ResultadoComparacion comparar(Campo* otroCampo);

	void inicializarConRegistro(Byte *);
};

#endif /* CAMPOCADENA_H_ */
