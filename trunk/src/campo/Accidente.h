/*
 * Interface de la clase Accidente, que hereda de Campo y forma una de las dimensiones
 * de Clave
 *
 *  Created on: 21/05/2012
 *      Author: ezequiel
 */

#ifndef ACCIDENTE_H_
#define ACCIDENTE_H_

#include "CampoCadena.h"

class Accidente: public CampoCadena {
public:

	Accidente();

	/*
	 * Constructor copia de la clase Accidente
	 */
	Accidente(Accidente& accidente);

	/*
	 * Constructor de la clase Accidente
	 * Recibe el tipo de Accidente como string por parámetro
	 */
	Accidente(string tipoAccidente);

	/*
	 * Destructor de la clase Accidente
	 */
	virtual ~Accidente();

};

#endif /* ACCIDENTE_H_ */
