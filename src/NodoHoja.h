/*
 * Interface de la clase NodoHoja, que hereda de Nodo
 *
 *  Created on: 21/05/2012
 *      Author: ezequiel
 */

#ifndef NODOHOJA_H_
#define NODOHOJA_H_

#include "Nodo.h"

class NodoHoja: public Nodo {
private:
	/* El atributo estatico especifica cuantas claves se pueden almacenar dentro
	 * del NodoHoja.
	 * Se usará el valor 2 para probar el funcionamiento del arbol.
	 * Luego especificamos un valor correcto.
	 */
	const static int cantClaves = 2;

	Clave** listaClaves;

public:
	NodoHoja();
	virtual ~NodoHoja();
};

#endif /* NODOHOJA_H_ */
