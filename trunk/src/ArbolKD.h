/*
 * ArbolKD.h
 *
 *  Created on: 19/05/2012
 *      Author: matias_2
 */

#ifndef ARBOLKD_H_
#define ARBOLKD_H_

#include "kdNodoInterno.h"
#include "kdNodoHoja.h"
#include "kdNodo.h"

using namespace std;

class ArbolKD {
private:
	kdNodo *raiz;

public:
	ArbolKD();
	virtual ~ArbolKD();
	//	NodoInterno* getNodosPorNivel();

		int insertar(Clave*);
	//	int eliminar(int modoInvocacion, Clave* clave);
		Clave* busquedaPuntual(Clave* clave);

		Falla* getFallas();
		Formacion* getFormaciones();
		Linea* getLineas();
		Accidente* getAccidentes();

		Campo* getCampoPorFecha(Fecha* comienzo, Fecha* fin);

	private:
		bool raizEsHoja();
		int insertarRecursivo(kdNodo* nodo, Clave* clave, int iteracion);
	//	int eliminarRecursivo(Nodo* nodo, Clave* claveVacia, Clave* claveAEliminar, int modoInvocacion);
		Clave* busquedaRecursiva(kdNodo* nodo, Clave* claveBuscada, int iteracion);

		/*
		 * Actualiza nodo interno y ambos nodos hijos por desborde.
		 * @return false si al actualizar algun nodo hijo sigue con desborde (caso particular si se utiliza un criterio de organizacion
		 * 			     para el cual las claves del nodo desbordado son todas iguales)
		 * @return true
		 */
		kdNodo* actualizarPorDesborde(kdNodoInterno* nodoInterno, kdNodoHoja* hojaDesbordado, kdNodoHoja* nuevoHoja, int iteracion);

		/*
		 * Devuelve dimension por la cual se ordeno a cierta iteracion de recorrido.
		 */
		int roundRobin(int iteracion);

};

#endif /* ARBOLKD_H_ */
