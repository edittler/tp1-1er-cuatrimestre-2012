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
	this->cantClaves = 0;
	this->listaClaves = new Clave*[(this->capacidadNodo + 1)];
	/*
	 * Creo la lista de claves con capacidad para 1 clave más para poder ordenar las
	 * claves cuando éste se desborda.
	 */
	for (int i=0; i < this->capacidadNodo; i++){
		this->listaClaves[i] = NULL;
	}
}

/*
 * Constructor de la clase NodoHoja
 * Inicializa la lista con capacidad para 2 claves y almacena la que recibe por parametro.
 */
NodoHoja::NodoHoja(Clave clave){
	this->listaClaves = new Clave*[(this->capacidadNodo + 1)];
	/*
	 * Creo la lista de claves con capacidad para 1 clave más para poder ordenar las
	 * claves cuando éste se desborda.
	 */
	this->cantClaves = 1;
	Clave *unaClave = new Clave(clave);
	this->listaClaves[0] = unaClave;
		for (int i=1; i < this->capacidadNodo; i++){
			this->listaClaves[i] = NULL;
		}
}

/*
 * Destructor de la clase NodoHoja. Debe liberar la memoria de la lista de claves.
 */
NodoHoja::~NodoHoja() {
	for(int i=0; i < (this->capacidadNodo + 1); i++){
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
	while((!tieneClave) && (i < this->capacidadNodo)){
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
	int valorRetorno;
	if (this->contiene(clave)){
		valorRetorno = 3;	// Devuelvo 3, que significa que la clave ya se encuentra en el nodo
	} else {
		if (this->cantClaves == this->capacidadNodo){
			/* Si la cantidad de claves que contiene el nodo es igual a la capacidad
			 * el nodo se desborda, por lo que se retorna el valor 2
			 */
			valorRetorno = 2;
		} else {
			Clave *unaClave = new Clave(clave);
			bool insertoClave = false;
			int i = 0;
			while ((!insertoClave) && (i < this->capacidadNodo)){
				// Si hay una posicion NULL en el vector, inserto la clave
				if (this->listaClaves[i] == NULL){
					this->listaClaves[i] = unaClave;
					insertoClave = true;	// cambio el valor del booleano
					this->cantClaves++;
					valorRetorno = 1; // Devuelvo 1, que significa que el nodo se actualizó
				}
				i++;
			} // Fin while
		}
	}
	return valorRetorno;
}

/*
 * Metodo de eliminacion de clave. Los valores de retorno son:
 * 		1: el nodo se actualizó
 * 		2: el nodo quedó con subflujo
 * 		3: no existe la clave que se quiere eliminar
 */
int NodoHoja::eliminar(Clave clave){
	int valorRetorno;
	if ( ! this->contiene(clave)){
		valorRetorno = 3;	// Devuelvo 3, que significa que la clave no existe
	} else {
		bool eliminoClave = false;
		int i = 0;
		while ((!eliminoClave) && (i < this->capacidadNodo)){
			if (this->listaClaves[i]->comparar(clave) == IGUAL){	// Si las claves son iguales, debo eliminar la almacenada en el nodo.
				delete this->listaClaves[i];	// Elimino la memoria reservada
				this->listaClaves[i] = NULL;	// Establezco como NULL al puntero
				eliminoClave = true;	// Establezco como verdadero que se eliminó la clave
			}
			i++;	// Incremento i
		}
		// Ahora debo analizar si el nodo no quedó con subflujo
		// TODO Agregar codigo if con subflujo

		// Si no hay subflujo, hay que devolver 1, que el nodo se actualizo con exito
		valorRetorno = 1;
	}
	return valorRetorno;
}

/*
 * Metodo que devuelve el campo que se encuentra en el medio (o el derecho, en caso
 * de cantidad par de Claves
 * ATENCION: Devuelve la direccion de memoria del campo, pero el NodoInterno debe realizar
 * una copia de su contenido para almacenarlo como atributo, para que sea persistente
 * en el tiempo el dato almacenado en el NodoInterno
 */
Campo* NodoHoja::getValorMedio(int dimension) const{
	// TODO Analizar si esto lo hace la clase NodoHoja o ArbolKD
	return NULL;
}


/*
 * Metodo privado que ordena las claves del Nodo según la dimension con la que se
 * quiere ordenar.
 */
void NodoHoja::ordenarListaClaves(int dimension){
	// TODO Analizar si esto lo hace la clase NodoHoja o ArbolKD
}
