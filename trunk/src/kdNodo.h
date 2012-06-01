/*
 * Interface de la clase base Nodo
 *
 *  Created on: 12/05/2012
 *      Author: ezequiel
 */

#ifndef NODO_H_
#define NODO_H_

#include "Byte.h"

class kdNodo {

public:

	/*
	 * Contructor por defecto.
	 */
	kdNodo();

	/*
	 * Destructor de la clase Nodo
	 */
	virtual ~kdNodo();

	int getId() const;

	void setId(int id);

	virtual bool esHoja() = 0;

	/* Funcion que genera la cadena de bytes para almacenar la clase. Debe recibir por
	 * referencia un int que pueda almacenar el tamaño de la cadena, para su guardado
	 * posterior en el archivo.
	 */
	virtual Byte * obtenerRegistro (int *tam) = 0;

	virtual void inicializarConRegistro(Byte * registro) = 0;

};

#endif /* NODO_H_ */
