/*
 * Interface de la clase base Clave
 *
 * Esta implementación de clave almacenará 5 dimensiones para la solución del problema
 * de los trenes. El orden de los Campos en las dimensiones será:
 * 		0: Linea
 * 		1: Formacion
 * 		2: FranjaHoraria
 * 		3: Falla
 * 		4: Accidente
 *
 *  Created on: 12/05/2012
 *      Author: ezequiel
 */

#ifndef CLAVE_H_
#define CLAVE_H_

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include"campo/Campo.h"
#include"campo/Linea.h"
#include"campo/Formacion.h"
#include"campo/FranjaHoraria.h"
#include"campo/Falla.h"
#include"campo/Accidente.h"

using namespace std;

class Clave {
private:
	Campo **listaCampos;
	const static int cantDimensiones = 5;

public:
	/*
	 * Constructor de la clase Clave
	 * Inicializa la lista de campos con 5 posiciones en NULL
	 */
	Clave();

	/*
	 * Constructor de la clase Clave, que inicializa los campos Linea y Formacion,
	 * el resto de sus dimensiones en NULL
	 */
	Clave(string linea, int formacion);

	/*
	 * Destructor de la clase Clave
	 * Libera la lista de campos almacenada
	 */
	virtual ~Clave();

	void setLinea(string linea);

	void setFormacion(int formacion);

	void setFranjaHoraria(); //TODO agregar los parametros Fecha

	void setFalla(string falla);

	void setAccidente(string accidente);

	/*
	 * Se obtiene el campo correspondiente a la dimension requerida, siendo:
	 * 		0: Linea
	 * 		1: Formacion
	 * 		2: FranjaHoraria
	 * 		3: Falla
	 * 		4: Accidente
	 * 	Si se pasa un valor diferente a los mencionados anteriormente, devuelve un puntero NULL
	 */
	Campo* getCampo(int dimension) const;

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
