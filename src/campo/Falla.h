/*
 * Interface de la clase Falla, que hereda de Campo y forma una de las dimensiones
 * de Clave
 *
 *  Created on: 21/05/2012
 *      Author: ezequiel
 */

#ifndef FALLA_H_
#define FALLA_H_

#include "CampoCadena.h"

class Falla: public CampoCadena {
public:

	/*
	 * Constructor por defecto
	 */
	Falla();

	/*
	 * Constructor copia de la clase Falla
	 */
	Falla(Falla& falla);

	/*
	 * Constructor de la clase Falla
	 * Se pasa el tipo de falla como string por parámetro
	 */
	Falla(string tipoFalla);

	/*
	 * Destructor de la clase Falla
	 */
	virtual ~Falla();

	void inicializarConRegistro(Byte *);

};

#endif /* FALLA_H_ */
