/*
 * ArbolKD.h
 *
 *  Created on: 19/05/2012
 *      Author: Alejandro Daza
 */

#ifndef ARBOLKD_H_
#define ARBOLKD_H_

class ArbolKD {
public:
	NodoHoja nodoRaizHoja;
	NodoInterno nodoRaizInterno;
	ArbolKD();
	virtual ~ArbolKD();
	void insertarDato(Clave);
private:
	bool raizEsHoja;
	bool nodoRaizEsHoja();
};

#endif /* ARBOLKD_H_ */
