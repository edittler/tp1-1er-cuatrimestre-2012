/*
 * Clase base abstracta Nodo
 *
 *  Created on: 12/05/2012
 *      Author: ezequiel
 */

#ifndef NODO_H_
#define NODO_H_

class Nodo {
public:
	/*
	 * Constructor de la clase Nodo
	 */
	Nodo();

	/*
	 * Destructor de la clase Nodo
	 */
	virtual ~Nodo();

	/*
	 * Método para insertar un registro al arbol el cual pertenece el nodo
	 * Aclaracion: al agregar cons = 0 hago que la funcion sea virtual pura y
	 * así la clase es abstracta.
	 */
	virtual int insertar(Nodo nodo);
};

#endif /* NODO_H_ */
