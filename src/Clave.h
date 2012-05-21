/*
 * Interface de la clase base Clave
 *
 *  Created on: 12/05/2012
 *      Author: ezequiel
 */

#ifndef CLAVE_H_
#define CLAVE_H_

#include "campo/Campo.h"

using namespace std;
using namespace campo;

class Clave {
private:
	Campo listaCampos;

public:
	/*
	 * Constructor de la clase Clave
	 * Inicializa la lista de campos con 5 posiciones en NULL
	 */
	Clave();

	/*
	* Destructor de la clase Clave
	* Libera la lista de campos almacenada
	*/
	virtual ~Clave();

	/*
	 * Funcion que evalúa si esta clave es igual a otra pasada por parámetro.
	 * Compara todos los campos y evuelve 0 si son iguales, o un valor distinto de 0 si
	 * no son iguales
	 */
	virtual int comparar(Clave otraClave);

	/*
	 * Funcion que evalúa solo la dimensión de esta clave con otra pasada por parámetro
	 * Compara el campo correspondiente a la dimension que se quiere evaluar y
	 * devuelve 0 si son iguales, -1 si el campo es menor que el pasado por parametro y
	 * 1 si el campo es mayor.
	 */
	virtual int comparar(Clave otraClave, int dimesion);

};

#endif /* CLAVE_H_ */
