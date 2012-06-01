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
		Clave* busquedaPuntual(Clave* clave);

		Falla* getFallas();
		Formacion* getFormaciones();
		Linea* getLineas();
		Accidente* getAccidentes();

		void getTrenesConFalla(Falla* falla, Fecha* inicio, Fecha* fin, Campo** listaResultado);
		void getTrenesConAccidente(Accidente* accidente, Fecha* comienzo, Fecha* fin, Campo** listaResultado);
		void getFallasDeFormacion(Formacion* formacion, Fecha* comienzo, Fecha* fin, Campo** listaResultado);
		void getAccidenteDeFormacion(Formacion* formacion, Fecha* comienzo, Fecha* fin, Campo** listaResultado);

private:
	bool raizEsHoja();
	int insertarRecursivo(kdNodo* nodo, Clave* clave, int iteracion);
//	int eliminarRecursivo(Nodo* nodo, Clave* claveVacia, Clave* claveAEliminar, int modoInvocacion);
	Clave* busquedaRecursiva(kdNodo* nodo, Clave* claveBuscada, int iteracion);

	/*
	 * Actualiza nodo interno y ambos nodos hijos por desborde y los graba.
	 */
	void actualizarPorDesborde(kdNodoInterno* nodoInterno, kdNodoHoja* hojaDesbordado, int iteracion);

	/*
	 * @listaResultado: lista donde se guardaran los resultados
	 * @nodo: necesario para el metodo recursivo.
	 * @campoBuscado: campo segun el que se quiere buscar (Ej: Falla, Formacion)
	 * @campoReferente: indice del campo del cual se quiere buscar la informacion.
	 * @fechaComienzo - fechaFin: rango de fechas. Si no se requieren pueden dejarse en NULL.
	 */
	void getCampoPorFechaRecursivo(Campo** listaResultado, kdNodo* nodo, int campoBuscado, Campo* campoReferente, Fecha* fechaComienzo, Fecha* fechaFin);

	/*
	 * Devuelve dimension por la cual se ordeno a cierta iteracion de recorrido.
	 */
	int roundRobin(int iteracion);

};

#endif /* ARBOLKD_H_ */
