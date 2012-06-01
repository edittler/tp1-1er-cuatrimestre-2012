/*
 * NodoInterno.cpp
 *
 *  Created on: 12/05/2012
 *      Author: ezequiel
 */

#include "kdNodoInterno.h"

/* Constructor de la clase NodoInterno
 * Inicializa todos sus atributos en null
 */
kdNodoInterno::kdNodoInterno() {
	this->atributo = NULL;
	this->hijoIzq = NULL;
	this->hijoDer = NULL;
}

/* Constructor de la clase NodoInterno
 * Inicializa con el atributo que recibe por parámetro y los los demas en NULL
 */
kdNodoInterno::kdNodoInterno(Campo* atributo){
	this->setAtributo(atributo);
	this->hijoIzq = NULL;
	this->hijoDer = NULL;
}

/* Constructor de la clase NodoInterno
 * Inicializa todos sus atributos con los argumentos recibidos por parámtetros.
 */
kdNodoInterno::kdNodoInterno(Campo* atributo, kdNodo* hijoIzq, kdNodo* hijoDer){
	this->setAtributo(atributo);
	this->setHijoIzq(hijoIzq);
	this->setHijoDer(hijoDer);
}

/* Destructor de la clase NodoInterno
 * Debe eliminar la memoria reservada por los punteros y establecerlos como NULL
 * Si los nodos hijos de este nodo se van a seguir usando, previo a la destruccion del objeto,
 * se deben establecer como NULL los hijos de este nodo para no cometer liberaciones de
 * memoria erroneas.
 */
kdNodoInterno::~kdNodoInterno() {
	delete this->atributo;
	delete this->hijoIzq;
	delete this->hijoDer;
}

/*
 * Función que devuelve si el nodo es hoja, que devuelve verdadero por defecto
 */
bool kdNodoInterno::esHoja(){
	return false;
}

/* Retorna el atributo que identifica al nodo
 */
Campo* kdNodoInterno::getAtributo() const{
	return this->atributo;
}

/* Modifica el atributo del nodo, estableciendo el que recibe por parámetro.
 */
void kdNodoInterno::setAtributo(Campo* atributo){
	if (this->atributo != NULL){
		delete this->atributo;
	}

	/* FIXME Provisoriamente se implementa la solucion de if anidados del
	 * metodo 'setAtributo'. Averiguar si se puede realizar una implementacion
	 * más feliz del problema.
	 */
	if (atributo == NULL){
		this->atributo = NULL;
	} else {
		/* Realiza un casteo dinamico de Linea. Si resulta positivo el casteo,
		 * realiza una copia del campo
		 */
		Linea *unaLinea = dynamic_cast<Linea*>(atributo);
		if (unaLinea != NULL) {
			this->atributo = new Linea(unaLinea->getDescripcion());
		} else {
			/* Realiza un casteo dinamico de Formacion. Si resulta positivo el casteo,
			 * realiza una copia del campo
			 */
			Formacion *unaFormacion = dynamic_cast<Formacion*>(atributo);
			if (unaFormacion != NULL) {
				this->atributo = new Formacion(unaFormacion->getNumeroFormacion());
			} else {
				/* Realiza un casteo dinamico de FranjaHoraria. Si resulta positivo el casteo,
				 * realiza una copia del campo
				 */
				FranjaHoraria *unaFranja = dynamic_cast<FranjaHoraria*>(atributo);
				if (unaFranja != NULL) {
					this->atributo = new FranjaHoraria(unaFranja->getFecha(), unaFranja->getHorario());
				} else {
					/* Realiza un casteo dinamico de Falla. Si resulta positivo el casteo,
					 * realiza una copia del campo
					 */
					Falla *unaFalla = dynamic_cast<Falla*>(atributo);
					if (unaFalla != NULL) {
						this->atributo = new Falla(unaFalla->getDescripcion());
					} else {
						/* Realiza un casteo dinamico de Accidente. Si resulta positivo el
						 * casteo, realiza una copia del campo
						 */
						Accidente *unAccidente = dynamic_cast<Accidente*>(atributo);
						if (unAccidente != NULL) {
							this->atributo = new Accidente(unAccidente->getDescripcion());
						} // Fin if Accidente
					} // Fin if Falla
				} // Fin if FranjaHoraria
			} // Fin if Formacion
		} // Fin if Linea
	}
}

/* Retorna la direccion de memoria del hijo izquierdo
 */
kdNodo* kdNodoInterno::getHijoIzq() const{
	return this->hijoIzq;
}

/* Edita el hijo izquierdo.
 * Si previamente el nodo interno ya tenia hijo izquierdo, se reemplaza la referencia de
 * memoria, pero no libera la memoria del hijo almacenado previamente.
 */
void kdNodoInterno::setHijoIzq(kdNodo* hijoIzquierdo){
	this->hijoIzq = hijoIzquierdo;
}

/* Retorna la direccion de memoria del hijo derecho
 */
kdNodo* kdNodoInterno::getHijoDer() const{
	return this->hijoDer;
}

/* Edita el hijo derecho.
 * Si previamente el nodo interno ya tenia hijo derecho, se reemplaza la referencia de
 * memoria, pero no libera la memoria del hijo almacenado previamente.
 */
void kdNodoInterno::setHijoDer(kdNodo* hijoDerecho){
	this->hijoDer = hijoDerecho;
}

/* Funcion que genera la cadena de bytes para almacenar la clase. Debe recibir por
 * referencia un int que pueda almacenar el tamaño de la cadena, para su guardado
 * posterior en el archivo.
 */
Byte * kdNodoInterno::obtenerRegistro (int *tam){
	Byte *registro = NULL;
	/* Si el atributo del campo esta en NULL, significa que el nodo interno no es
	 * valido, por lo que en su serializacion se debueve NULL
	 */
	if (this->atributo != NULL){
		// serializo la posicione de bloque del hijo izquierdo y el booleano si es hoja
		Byte* esHojaIzq = new Byte[sizeof(bool)];
		*esHojaIzq = (char) this->hijoIzqEsHoja;
		Byte* posIzq = new Byte[sizeof(int)];
		*posIzq = this->posBloqueIzq;
		Byte* tmpIzq;
		concatenar(&tmpIzq, esHojaIzq, sizeof(bool), posIzq, sizeof(int));
		delete esHojaIzq;
		delete posIzq;
		// serializo la posicione de bloque del hijo derecho y el booleano si es hoja
		Byte* esHojaDer = new Byte[sizeof(bool)];
		*esHojaDer = (char) this->hijoDerEsHoja;
		Byte* posDer = new Byte[sizeof(int)];
		*posDer = this->posBloqueDer;
		Byte* tmpDer;
		concatenar(&tmpDer, esHojaDer, sizeof(bool), posDer, sizeof(int));
		delete esHojaDer;
		delete posDer;
		// concateno la informacion sobre los hijos del nodo
		int tamDataHijo = sizeof(bool) + sizeof(int);
		Byte *tmpHijos;
		concatenar(&tmpHijos, tmpIzq, tamDataHijo, tmpDer, tamDataHijo);
		delete tmpIzq;
		delete tmpDer;
		// serializo el campo
		int tamCampo;
		Byte *campo = this->atributo->obtenerRegistro(&tamCampo);
		// concateno el nodo interno completo
		Byte *tmpFinal;
		concatenar(&tmpFinal, campo, tamCampo, tmpHijos, tamDataHijo*2);
		delete campo;
		delete tmpHijos;
		*tam = tamCampo + tamDataHijo*2; // tamaño completo del registro
		registro = tmpFinal;
	}
	return registro;
}

void kdNodoInterno::inicializarConRegistro(Byte * registro) {
	int inicio = 0;
	int tamReg = sizeof(bool);
	Byte * regIzqEsHoja;
	// obtengo si el hijo izq es hoja
	obtenerPorcion(registro, &regIzqEsHoja, inicio, tamReg);
	inicio += tamReg;
	hijoIzqEsHoja = *regIzqEsHoja;
	// obtengo la posicion del hijo izq
	tamReg = sizeof(int);
	Byte *regPosHijoIzq;
	obtenerPorcion(resultado, &regPosHijoIzq, inicio, tamReg);
	inicio += tamReg;
	posBloqueIzq = *regPosHijoIzq;
	// obtengo si el hijo der es hoja
	tamReg = sizeof(bool);
	Byte * regDerEsHoja;
	obtenerPorcion(resultado, &regDerEsHoja, inicio, tamReg);
	inicio += tamReg;
	hijoDerEsHoja = *regDerEsHoja;
	// obtengo la posicion del hijo der
	tamReg = sizeof(int);
	Byte * regPosHijoDer;
	obtenerPorcion(resultado, &regPosHijoDer, inicio, tamReg);
	inicio += tamReg;
	posBloqueDer = *regPosHijoDer;
	// obtengo el tam del campo
	Byte * regTamCampo;
	obtenerPorcion(resultado, &regTamCampo, inicio, tamReg);
	inicio += tamReg;
	int tamCampo = *regTamCampo;
	// obtengo el campo
	Byte * regCampo;
	obtenerPorcion(resultado, &regCampo, inicio, tamCampo);

}
