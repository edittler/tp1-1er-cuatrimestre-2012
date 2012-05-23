/*
 * Implementacion de la clase NodoHoja, que hereda de Nodo
 *
 *  Created on: 21/05/2012
 *      Author: ezequiel
 */

#include "NodoHoja.h"

/*
 * Constructor de la clase NodoHoja
 * Inicializa la lista con capacidad para 2 claves, pero la deja vacía.
 */
NodoHoja::NodoHoja() {
	this->listaClaves = new Clave*[this->cantClaves];
	for (int i=0; i < this->cantClaves; i++){
		this->listaClaves[i] = NULL;
	}
}

/*
 * Constructor de la clase NodoHoja
 * Inicializa la lista con capacidad para 2 claves y almacena la que recibe por parametro.
 */
NodoHoja::NodoHoja(Clave *clave){
	this->listaClaves = new Clave*[this->cantClaves];
	this->listaClaves[0] = clave;
		for (int i=1; i < this->cantClaves; i++){
			this->listaClaves[i] = NULL;
		}
}

/*
 * Destructor de la clase NodoHoja. Debe liberar la memoria de la lista de claves.
 */
NodoHoja::~NodoHoja() {
	for(int i=0; i < this->cantClaves; i++){
		if (this->listaClaves[i] != NULL){
			delete this->listaClaves[i];
		}
	}
	delete this->listaClaves;
}

/*
 * Metodo para verificar si el nodo contiene la clave que se le pasa por parametro
 */
bool NodoHoja::contiene(Clave clave){
	bool tieneClave = false;
	int i = 0;
	while((!tieneClave) && (i < this->cantClaves)){
		if (this->listaClaves[i] != NULL){
			if (this->listaClaves[i]->comparar(clave) == IGUAL){
				tieneClave = true;
			}
		}
		i++;
	}
	return tieneClave;
}

/*
 * Metodo de inserccion de clave. Los valores de retorno son:
 * 		1: el nodo se actualizó
 * 		2: el nodo se desbordó
 * 		3: el nodo ya tiene la clave que se desea insertar
 */
int NodoHoja::insertar(Clave clave){
	// TODO
	return 0;
}

/*
 * Metodo de eliminacion de clave. Los valores de retorno son:
 * 		1: el nodo se actualizó
 * 		2: el nodo quedó con subflujo
 * 		3: no existe la clave que se quiere eliminar
 */
int NodoHoja::eliminar(Clave clave){
	// TODO
	return 0;
}

/*
 * Metodo que devuelve el campo que se encuentra en el medio (o el derecho, en caso
 * de cantidad par de Claves
 * ATENCION: Devuelve la direccion de memoria del campo, pero el NodoInterno debe realizar
 * una copia de su contenido para almacenarlo como atributo, para que sea persistente
 * en el tiempo el dato almacenado en el NodoInterno
 */
Campo* NodoHoja::getValorMedio(int dimension) const{
	// TODO
	return NULL;
}


/*
 * Metodo privado que ordena las claves del Nodo según la dimension con la que se
 * quiere ordenar.
 */
void NodoHoja::ordenarListaClaves(int dimension){
	// TODO
}
