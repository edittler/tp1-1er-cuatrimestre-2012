/*
 * Interface de la clase ClaveLinea
 *
 *  Created on: 12/05/2012
 *      Author: ezequiel
 */

#ifndef CLAVELINEA_H_
#define CLAVELINEA_H_

#include "Clave.h"
#include <string>

using namespace std;

class ClaveLinea: public Clave {
/*
 * Atributos privados de la clase ClaveLinea
 */
private:
	string nombreLinea;

public:
    /*
	 * Constructor de la clase ClaveLinea
	 */
	ClaveLinea(string nombreLineaNueva);

	/*
	 * Destructor de la clase ClaveLinea
	 */
	virtual ~ClaveLinea();

	/*
	 * Funcion que evalúa si esta clave es igual a otra pasada por parámetro
	 */
	virtual bool esIgual(Clave otraClave);

	/*
	 * Funcion que evalúa si esta clave es igual a otra pasada por parámetro
	 */
	virtual bool esMenor(Clave otraClave);

	/*
	 * Funcion con la cual se obtiene el nombre de la linea
	 */
    string getNombreLinea();

    void setNombreLinea(string nuevoNombre);
};

#endif /* CLAVELINEA_H_ */
