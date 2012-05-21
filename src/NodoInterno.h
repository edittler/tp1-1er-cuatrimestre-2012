/*
 * NodoInterno.h
 *
 *  Created on: 12/05/2012
 *      Author: ezequiel
 */

#ifndef NODOINTERNO_H_
#define NODOINTERNO_H_

#include "Nodo.h"
#include "Clave.h"

class NodoInterno: public Nodo {
/*
 * Atributos privados de la clase
 */
private:
	int nivel;
	Clave atributo;
	Nodo* hijoIzq;
	Nodo* HijoDer;

public:
	/*
	* Constructor de la clase NodoInterno
	* Inicializa todos sus atributos en null
	*/
	NodoInterno();

	/*
	* Destructor de la clase NodoInterno
	*/
	virtual ~NodoInterno();
};

#endif /* NODOINTERNO_H_ */
