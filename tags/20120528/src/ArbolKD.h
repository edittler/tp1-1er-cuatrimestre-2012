/*
 * ArbolKD.h
 *
 *  Created on: 19/05/2012
 *      Author: Alejandro Daza
 */

#ifndef ARBOLKD_H_
#define ARBOLKD_H_

#include "kdNodoInterno.h"
#include "kdNodoHoja.h"

using namespace std;

class ArbolKD {
private:
	kdNodo *raiz;

public:
	ArbolKD();
	virtual ~ArbolKD();
	int insertar(Clave);

private:
	bool raizEsHoja();

};

#endif /* ARBOLKD_H_ */
