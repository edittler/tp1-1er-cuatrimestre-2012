/*
 * Interface de la clase base Nodo
 *
 *  Created on: 12/05/2012
 *      Author: ezequiel
 */

#ifndef NODO_H_
#define NODO_H_

class kdNodo {
private:
	int id;

public:

	/*
	 * Contructor por defecto.
	 */
	kdNodo();

	/*
	 * Constructor de la clase Nodo, que debe inicializarse con el ID correspondiente
	 */
	kdNodo(int ID);

	/*
	 * Destructor de la clase Nodo
	 */
	virtual ~kdNodo();

	int getId() const;

	void setId(int id);

	virtual bool esHoja() = 0;

};

#endif /* NODO_H_ */
