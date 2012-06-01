/*
 * Implementacion de la clase NodoHoja, que hereda de Nodo
 *
 *  Created on: 21/05/2012
 *      Author: ezequiel
 */

#include "kdNodoHoja.h"

/*
 * Constructor de la clase NodoHoja
 * Inicializa la lista con capacidad para 2 claves, pero la deja vacía.
 */
kdNodoHoja::kdNodoHoja() {
	this->cantClaves = 0;
	this->listaClaves = new Clave*[(this->capacidadNodo + 1)];
	/*
	 * Creo la lista de claves con capacidad para 1 clave más para poder ordenar las
	 * claves cuando éste se desborda.
	 */
	for (int i=0; i < (this->capacidadNodo + 1); i++){
		this->listaClaves[i] = NULL;
	}
}

/*
 * Constructor de la clase NodoHoja
 * Inicializa la lista con capacidad para 2 claves y almacena la que recibe por parametro.
 */
kdNodoHoja::kdNodoHoja(Clave clave){
	this->listaClaves = new Clave*[(this->capacidadNodo + 1)];
	/*
	 * Creo la lista de claves con capacidad para 1 clave más para poder ordenar las
	 * claves cuando éste se desborda.
	 */
	this->cantClaves = 1; // Establesco que la cantidad de claves almacenadas es 1
	Clave *unaClave = new Clave(clave);
	this->listaClaves[0] = unaClave;
		for (int i=1; i < (this->capacidadNodo + 1); i++){
			this->listaClaves[i] = NULL;
		}
}

/*
 * Destructor de la clase NodoHoja. Debe liberar la memoria de la lista de claves.
 */
kdNodoHoja::~kdNodoHoja() {
	for(int i=0; i < (this->capacidadNodo + 1); i++){
		if (this->listaClaves[i] != NULL){
			delete this->listaClaves[i];
		}
	}
	delete this->listaClaves;
}

/*
 * Función que devuelve si el nodo es hoja, que devuelve verdadero por defecto
 */
bool kdNodoHoja::esHoja(){
	return true;
}

/*
 * Metodo para verificar si el nodo contiene la clave que se le pasa por parametro
 */
bool kdNodoHoja::contiene(Clave clave){
	bool tieneClave = false;
	int i = 0;
	while((!tieneClave) && (i <= this->capacidadNodo)){
		if (this->listaClaves[i] != NULL){
			if (this->listaClaves[i]->comparar(&clave) == IGUAL){
				tieneClave = true;
			}
		}
		i++;
	}
	return tieneClave;
}

/*
 * Metodo de inserccion de clave. Los valores de retorno son:
 * 		0: el nodo no se actualizó (puede que esté con sobreflujo y no fue solucionado anteriormente)
 * 		1: el nodo se actualizó
 * 		2: el nodo se desbordó
 * 		3: el nodo ya tiene la clave que se desea insertar
 *
 * 	Cuando se desborda, la clave es almacenada en un lugar extra para que el padre
 * 	pida obtener el valor medio y obtener ordenadamente cada clave para poder dividirlo
 * 	facilmente.
 */
int kdNodoHoja::insertar(Clave clave){
	// Si el nodo tiene sobreflujo, no se actualiza. Retorna el valor 0
	if(this->tieneSobreflujo()){
		return 0;
	}
	// Si el nodo ya tiene la clave a insertar, retorna el valor 3
	if(this->contiene(clave)){
		return 3;
	}
	// Ahora analizo los otros 2 casos
	int valorRetorno;
	/* Si la cantidad de claves que contiene el nodo es igual a la capacidad,
	 * el nodo se desborda, por lo que se retorna el valor 2.
	 * Sin embargo, la clave se almacena en el lugar extra para su posterior
	 * ordenamiento y entrega del valor medio para que el nodo padre lo divida.
	 */
	Clave *unaClave = new Clave(clave);
	if (this->cantClaves == this->capacidadNodo){
		this->listaClaves[this->capacidadNodo] = unaClave;
		this->cantClaves++;
		valorRetorno = 2;
	} else {
		bool insertoClave = false;
		int i = 0;
		while ((!insertoClave) && (i < this->capacidadNodo)){
			// Si hay una posicion NULL en el vector, inserto la clave
			if (this->listaClaves[i] == NULL){
				this->listaClaves[i] = unaClave;
				insertoClave = true;	// cambio el valor del booleano
				this->cantClaves++;	// Incremento el contador de claves almacenadas
				valorRetorno = 1; // Devuelvo 1, que significa que el nodo se actualizó
			}
			i++;
		} // Fin while
	}
	return valorRetorno;
}

/*
 * Metodo de eliminacion de clave. Los valores de retorno son:
 * 		1: el nodo se actualizó
 * 		2: el nodo quedó con subflujo
 * 		3: no existe la clave que se quiere eliminar
 */
int kdNodoHoja::eliminar(Clave clave){
	int valorRetorno;
	if ( ! this->contiene(clave)){
		valorRetorno = 3;	// Devuelvo 3, que significa que la clave no existe
	} else {
		bool eliminoClave = false;
		int i = 0;
		while ((!eliminoClave) && (i <= this->capacidadNodo)){
			if (this->listaClaves[i] != NULL){
				if (this->listaClaves[i]->comparar(&clave) == IGUAL){	// Si las claves son iguales, debo eliminar la almacenada en el nodo.
					delete this->listaClaves[i];	// Elimino la memoria reservada
					this->listaClaves[i] = NULL;	// Establezco como NULL al puntero
					this->cantClaves--; // Decremento el contador de cantidad de claves almacenadas
					this->restablecerZonaDesborde(); // Si el nodo estuvo debordado, vacio la zona de desborde.
					eliminoClave = true;	// Establezco como verdadero que se eliminó la clave
				}
			}
			i++;	// Incremento i
		}
		/* Ahora debo analizar si el nodo no quedó con subflujo.
		 * En caso afirmativo, se debe retornar el valor 2.
		 */
		if (this->tieneSubflujo()){
			valorRetorno = 2;
		} else {
			// Si no hay subflujo, hay que devolver 1, que el nodo se actualizo con exito
			valorRetorno = 1;
		}
	}
	return valorRetorno;
}

/* Funcion booleana para conocer el estado de sobreflujo del nodo hoja.
 * El nodo tiene SOBREFLUJO cuando la cantidad de claves almacenadas
 * excede a la capacidad del nodo.
 */
bool kdNodoHoja::tieneSobreflujo(){
	return (this->cantClaves > this->capacidadNodo);
}

/* Funcion booleana para conocer el estado de subflujo del nodo hoja.
 * El nodo tiene SUBFLUJO cuando la cantidad de claves almacenadas
 * es menor que la mitad de la capacidad maxima del nodo.
 */
bool kdNodoHoja::tieneSubflujo(){
	/* Para valores impares de la capacidad del nodo, se trunca el valor de la mitad y
	 * ése será la cantidad mínima de claves que debe contener.
	 */
	int capacidadMinima = (this->capacidadNodo)/2;
	if ((capacidadMinima % 1) != 0){
		capacidadMinima = capacidadMinima - (capacidadMinima % 1);
	}
	return (this->cantClaves < capacidadMinima);
}

/* Metodo que solo devuelve un campo válido si el nodo se encuentra desbordado o con sobreflujo
 * Metodo que devuelve el campo que se encuentra en el medio (o el derecho, en caso
 * de cantidad par de Claves)
 * ATENCION: Devuelve la direccion de memoria del campo, pero el NodoInterno debe realizar
 * una copia de su contenido para almacenarlo como atributo, para que sea persistente
 * en el tiempo el dato almacenado en el NodoInterno
 */
Campo* kdNodoHoja::getValorMedio(int dimension){
	/* Verifico si el nodo tiene sobreflujo. Sino, no es necesario entregar el valor medio
	 * el retorno NULL
	 */
	if (!(this->cantClaves > this->capacidadNodo)){
		return NULL;
	}

	/* Previamente hay que ordenar el vector de claves por la dimension que recibe
	 * por parámetro.
	 */
	this->ordenarListaClaves(dimension);

	/* En este problema, el valor "medio" es el que se usará como atributo indentificador
	 * en el nodo interno.
	 * Si la capacidad del nodo es PAR, el valor "medio" se encontrará en la clave cuya
	 * posicion es (capacidad+2)/2 +1
	 * Si la capacidad del nodo es IMPAR, el valor "medio" se encontrará en la clave cuya
	 * posicion es (capacidad+1)/2 +1
	 */
	int posicionMedio;
	if ((this->capacidadNodo % 2) == 0){
		// La capacidad del nodo es PAR
		posicionMedio = ((this->capacidadNodo + 2)/2);
	} else {
		// La capacidad del nodo es IMPAR
		posicionMedio = ((this->capacidadNodo + 1)/2);
	}

	/* FIXME Antes de retornar, se debe verificar que la clave de 1 posicion anterior a
	 * la clave que contiene el valor "medio" no tenga el mismo valor que el "medio".
	 * En ese caso, se debe recorrer la lista de claves hacia la derecha hasta encontrar
	 * una clave con un valor "medio" distinto a los demas.
	 * En caso de que no sea posible obtener un valor "medio" se debe optar por ordenar
	 * con la siguiente dimension.
	 */
	switch (dimension) {
		case 0: {
			Linea* linea = dynamic_cast<Linea*>(this->listaClaves[posicionMedio]->getCampo(dimension));
			if (!linea) {
				break;
			}
			return new Linea(*linea);
		}
		case 1: {
			Formacion* formacion = dynamic_cast<Formacion*>(this->listaClaves[posicionMedio]->getCampo(dimension));
			if (!formacion) {
				break;
			}
			return new Formacion(*formacion);
		}
		case 2: {
			FranjaHoraria* franja = dynamic_cast<FranjaHoraria*>(this->listaClaves[posicionMedio]->getCampo(dimension));
			if (!franja) {
				break;
			}
			return new FranjaHoraria(*franja);
		}
		case 3: {
			Falla* falla = dynamic_cast<Falla*>(this->listaClaves[posicionMedio]->getCampo(dimension));
			if (!falla) {
				break;
			}
			return new Falla(*falla);
		}
		case 4: {
			Accidente* accidente = dynamic_cast<Accidente*>(this->listaClaves[posicionMedio]->getCampo(dimension));
			if (!accidente) {
				break;
			}
			return new Accidente(*accidente);
		}
	}
	return NULL;
}

Clave* kdNodoHoja::getClave(int i) {
	Clave *clave = NULL;
	if ((i >= 0) && (i <= this->capacidadNodo)){
		clave = this->listaClaves[i];
	}
	return clave;
}

Clave* kdNodoHoja::getClave(Clave clave){
	if (! this->contiene(clave)){
		return NULL;
	}
	bool encontroClave = false;
	int i = 0;
	Clave *unaClave = NULL;
	while ((!encontroClave) && (i < this->capacidadNodo)){
		if (this->listaClaves[i]->comparar(&clave) == IGUAL){
			unaClave = this->listaClaves[i];
			encontroClave = true;	// Establezco como verdadero que se encontro la clave
		}
		i++;	// Incremento i
	}
	return unaClave;
}

/* Funcion que genera la cadena de bytes para almacenar la clase. Debe recibir por
 * referencia un int que pueda almacenar el tamaño de la cadena, para su guardado
 * posterior en el archivo.
 */
Byte * kdNodoHoja::obtenerRegistro (int *tam){
	// TODO Hacer
	return NULL;
}

/*
 * Metodo privado que ordena las claves del Nodo según la dimension con la que se
 * quiere ordenar.
 */
void kdNodoHoja::ordenarListaClaves(int dimension){
	/* Implemento un bubble sort, dado que no se almacenarán mas de 5 o 6 claves por nodo,
	 * y porque es un metodo sencillo de implementar.
	 */
	bool noIntercambio = false;	// Bandera que verifica si se realizo un intercambio en un ciclo
	int N = this->capacidadNodo + 1;
	int i = 1;
	Campo *tmp1, *tmp2;
	while ((!noIntercambio) && (i < N)){
		noIntercambio = true;
		for (int j=0; j < (N-i); j++){
			tmp1 = this->listaClaves[j]->getCampo(dimension);
			tmp2 = this->listaClaves[j + 1]->getCampo(dimension);
			// Verifico si tmp1 no es nulo, para no tener error de manejo de objetos no instanciados
			if (tmp1 != NULL){
				ResultadoComparacion comparacion = tmp1->comparar(tmp2);
				if (comparacion == MAYOR){
					swap (j, j+1);
					noIntercambio = false;
				}
			}
		}
	}
}

void kdNodoHoja::restablecerZonaDesborde(){
	if ((this->cantClaves <= this->capacidadNodo) && (this->listaClaves[this->capacidadNodo] != NULL)){
		bool restablecio = false;
		int i=0;
		while ((!restablecio) && (i < this->capacidadNodo)){
			if (this->listaClaves[i] == NULL){
				this->listaClaves[i] = this->listaClaves[this->capacidadNodo];
				this->listaClaves[this->capacidadNodo] = NULL;
				restablecio = true;
			}
			i++;
		}
	}
}

void kdNodoHoja::swap (int i, int j){
	Clave *tmp = this->listaClaves[i];
	this->listaClaves[i] = this->listaClaves[j];
	this->listaClaves[j] = tmp;
}
