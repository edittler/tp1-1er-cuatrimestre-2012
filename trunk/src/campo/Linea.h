/*
 * Interface de la clase Linea, que hereda de Campo y forma una de las dimensiones de Clave
 *
 *  Created on: 21/05/2012
 *      Author: ezequiel
 */

#ifndef LINEA_H_
#define LINEA_H_

#include "CampoCadena.h"

class Linea: public CampoCadena {
public:

	Linea();

	/*
	 * Constructor copia de la clase Linea
	 */
	Linea(Linea& linea);

	/*
	 * Constructor de la clase Linea
	 * Se para el nombre de la linea por parámetro
	 */
	Linea(string nombreLinea);

	/*
	 * Destructor de la clase Linea
	 */
	virtual ~Linea();

	void inicializarConRegistro(Byte *);
};

#endif /* LINEA_H_ */
