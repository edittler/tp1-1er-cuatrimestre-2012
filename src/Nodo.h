/*
 * Interface de la clase base Nodo
 *
 *  Created on: 12/05/2012
 *      Author: ezequiel
 */

#ifndef NODO_H_
#define NODO_H_

class Nodo {
private:
	int id;

public:

	/*
	 * Contructor por defecto.
	 */
	Nodo();

	/*
	 * Constructor de la clase Nodo, que debe inicializarse con el ID correspondiente
	 */
	Nodo(int ID);

	/*
	 * Destructor de la clase Nodo
	 */
	virtual ~Nodo();

	int getId() const;

	void setId(int id);

};

#endif /* NODO_H_ */
