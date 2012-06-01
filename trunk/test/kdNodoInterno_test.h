/*
 * kdNodoInterno.h
 *
 *  Created on: Jun 1, 2012
 *      Author: matias_2
 */

#ifndef KDNODOINTERNO_H_
#define KDNODOINTERNO_H_

#include "../src/kdNodoInterno.h"

void kdNodoInternoTest() {

	kdNodoInterno* nodoInterno = new kdNodoInterno(new Linea("Linea1"));

	int* tam = new int();
	Byte* registro = nodoInterno->obtenerRegistro(tam);
	nodoInterno->setAtributo(new Linea("Linea99"));
	//ignoro primer 4 bytes.
	Byte * regTamano;
	Byte * regTemp;
	obtenerPorcion(registro, &regTamano, 0, sizeof(int));
	int tamRegTamano = *regTamano;
	obtenerPorcion(registro, &regTemp, sizeof(int), tamRegTamano);
	//recupero registro ignorando primeros 4 bytes.
	nodoInterno->inicializarConRegistro(regTemp);
	if (dynamic_cast<Linea*>(nodoInterno->getAtributo())->getDescripcion() == "Linea1") {
		cout << "Ok.....obtener - inicializar registro" << endl;
	} else {
		cout << "Fail...obtener - inicializar registro" << endl;
	}
}


#endif /* KDNODOINTERNO_H_ */
