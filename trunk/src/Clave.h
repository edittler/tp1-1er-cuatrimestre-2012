/*
 * Interface de la clase base Clave
 *
 *  Created on: 12/05/2012
 *      Author: ezequiel
 */

#ifndef CLAVE_H_
#define CLAVE_H_

class Clave {
public:
	/*
	* Constructor de la clase Clave
	*/
	Clave();

	/*
	* Destructor de la clase Clave
	*/
	virtual ~Clave();

	/*
	 * Funcion que evalúa si esta clave es igual a otra pasada por parámetro
	 * (debe ser implementada por las clases herederas)
	 */
	virtual bool esIgual(Clave otraClave);

	/*
	 * Funcion que evalúa si esta clave es igual a otra pasada por parámetro
	 * (debe ser implementada por las clases herederas)
	 */
	virtual bool esMenor(Clave otraClave);

};

#endif /* CLAVE_H_ */
