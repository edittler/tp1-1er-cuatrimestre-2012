/*
 * Interface de la clase base Nodo
 *
 *  Created on: 12/05/2012
 *      Author: ezequiel
 */

#ifndef NODO_H_
#define NODO_H_

class NodoKD {
private:
	int id;

public:

	/*
	 * Contructor por defecto.
	 */
	NodoKD();

	/*
	 * Constructor de la clase Nodo, que debe inicializarse con el ID correspondiente
	 */
	NodoKD(int ID);

	/*
	 * Destructor de la clase Nodo
	 */
	virtual ~NodoKD();

	int getId() const;

	void setId(int id);

};

#endif /* NODO_H_ */
