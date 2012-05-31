/*
 * ArbolKD.cpp
 *
 *  Created on: 19/05/2012
 *      Author: matias_2
 */

#include "ArbolKD.h"

ArbolKD::ArbolKD() {
	this->raiz = new kdNodoHoja();
}

ArbolKD::~ArbolKD() {
	delete this->raiz;
}

int ArbolKD::insertar(Clave* nuevaClave) {

	if (raizEsHoja()) {
		kdNodoHoja* nodoRaiz = dynamic_cast<kdNodoHoja*>(this->raiz);
		int resultado = nodoRaiz->insertar(*nuevaClave);
		if (resultado == 2) { //nodo raiz desbordado
			kdNodoHoja* nuevoHoja = new kdNodoHoja();
			kdNodoInterno* nuevoInterno = new kdNodoInterno();
			this->actualizarPorDesborde(nuevoInterno, nodoRaiz, nuevoHoja, 1);
			//Actualizo referencias a los nuevos nodos hojas.
			nuevoInterno->setHijoDer(nodoRaiz);
			nuevoInterno->setHijoIzq(nuevoHoja);
			this->raiz = nuevoInterno;
			return 1;
		}
		return resultado;
	} else {
		return this->insertarRecursivo(this->raiz, nuevaClave, 1);
	}
}

int ArbolKD::insertarRecursivo(kdNodo* nodo, Clave* clave, int iteracion) {

	//control de corte para la recursividad.
	if (nodo->esHoja()) {
		kdNodoHoja* nodoHoja = dynamic_cast<kdNodoHoja*>(nodo);
		return nodoHoja->insertar(*clave);
	}

	int resultado;
	bool porDerecha;
//	TODO variable en la cuale se cargan el nodo hijo correspondiendo
	kdNodo* nodoHijo;
	kdNodoInterno* nodoInterno = dynamic_cast<kdNodoInterno*>(nodo);
	ResultadoComparacion comparacion = clave->comparar(nodoInterno->getAtributo());

	//segun comparacion avanza a derecha o izquierda.
	switch (comparacion) {
		case MENOR:
		case MAYOR:
			//TODO Aca deberia cargar nodo hijo derecho y pasarlo como parametro
			nodoHijo = nodoInterno->getHijoDer();
			resultado = this->insertarRecursivo(nodoHijo, clave, ++iteracion);
			porDerecha = true;
			break;
		case IGUAL:
			//TODO Aca deberia cargar nodo hijo Izquierdo
			nodoHijo = nodoInterno->getHijoIzq();
			resultado = this->insertarRecursivo(nodoHijo, clave, ++iteracion);
			porDerecha = false;
			break;
		case COMPARACION_NO_VALIDA:
			//no deberia entrar nunca..
			break;
	}

	//resuelve desborde en caso de que halla.
	switch (resultado) {
		case 2: {//el nodo se desbordo

			kdNodoHoja* nodoHojaDesbordado = dynamic_cast<kdNodoHoja*>(nodoHijo);

			//creo nuevo nodo hoja. TODO pregunta: Aca se asignaria el nuevo ID???
			kdNodoHoja* nuevoNodoHojaDerecha = new kdNodoHoja();

			kdNodoInterno* nuevoInterno = new kdNodoInterno();

			this->actualizarPorDesborde(nuevoInterno, nuevoNodoHojaDerecha, nodoHojaDesbordado, iteracion);

			//Actualiza referencia a nuevo nodo interno del padre.
			if (porDerecha) {
				nodoInterno->setHijoDer(nuevoInterno);
			} else {
				nodoInterno->setHijoIzq(nuevoInterno);
			}

			//TODO fin de insercion, grabar nuevoNodoHojaDerecha, nodoHojaDesbordado y nuevoInterno.
			// nodoInterno (padre) debe grabarse tmb?

			return 1;
		}
		case 1: //el nodo se actualizo
			//TODO si se actualizo se deberia guardar.
			return 2;
		case 3: //el nodo ya contenia la clave que se quiere ingresar.
			return 3;
	}

	return 0;
}

void ArbolKD::actualizarPorDesborde(kdNodoInterno* nuevoInterno, kdNodoHoja* hojaDesbordado, kdNodoHoja* nuevoHojaDerecha, int iteracion) {

	//obtengo la dimension del campo por la cual se debe ordenar.
	//TODO chequear que haga obtenga bien al dimensionReferencia.
	int dimensionReferencia = this->roundRobin(iteracion);

	//get valor medio de nodo hijo desbordado segun el campo a ordenar.
	Campo* valorMedio = hojaDesbordado->getValorMedio(dimensionReferencia);

	//creo nuevo nodo hoja. TODO pregunta: Aca se asignaria el nuevo ID???
//	kdNodoHoja* nuevoNodoHojaDerecha = new kdNodoHoja();

	//divido nodo hoja segun valor medio.
	for (int j = 0; j < kdNodoHoja::capacidadNodo; j++) {
		Clave* clave =hojaDesbordado->getClave(j);

		//TODO: Pregunta? Al estar el nodo desbordado, se que contiene el max de nodos posibles, haria falta chequear
		// que alguna clave es NULL?? La validacion esta hecha, es redundante, se podria eliminar. leer VER.
		if (clave != NULL) {
			//VER eliminar dos renglones siguientes en caso de eliminar validacion.
			Campo* campo = clave->getCampo(j);
			if ( !campo || campo->comparar(valorMedio) != MENOR) {
			// VER dejar este if en caso de eliminar validacion.
			//if (clave->getCampo(j)->comparar(valorMedio) != MENOR) {
				if (campo->comparar(valorMedio) != MENOR) {
					hojaDesbordado->eliminar(*clave);
					nuevoHojaDerecha->insertar(*clave); // el nodo hoja esta vacio, la insercion no da desborde nunca.
				}

			}
		}
	}

	//Creo nuevo nodo Interno, seteo sus nodo hijos.
//	kdNodoInterno* nuevoInterno = new kdNodoInterno(valorMedio);
	nuevoInterno->setAtributo(valorMedio);
	nuevoInterno->setHijoDer(nuevoHojaDerecha);
	nuevoInterno->setHijoIzq(hojaDesbordado);

}

Clave* ArbolKD::busquedaPuntual(Clave* clave) {
	return this->busquedaRecursiva(this->raiz, clave, 1);
}

Clave* ArbolKD::busquedaRecursiva(kdNodo* nodo, Clave* claveBuscada, int iteracion) {

	//control de corte para la recursividad.
	if (nodo->esHoja()) {
		kdNodoHoja* nodoHoja = dynamic_cast<kdNodoHoja*>(nodo);
		if (nodoHoja->contiene(*claveBuscada)) {
			return nodoHoja->getClave(*claveBuscada);
		}
		return NULL;
	}

	kdNodoInterno* nodoInterno = dynamic_cast<kdNodoInterno*>(nodo);
	ResultadoComparacion resultado = claveBuscada->comparar(nodoInterno->getAtributo());

	switch (resultado) {
		case IGUAL:
		case MAYOR:
			//TODO Aca deberia cargar nodo hijo derecho y pasarlo como parametro
			return this->busquedaRecursiva(nodoInterno->getHijoDer(), claveBuscada, ++iteracion);
		case MENOR:
			//TODO Aca deberia cargar nodo hijo derecho y pasarlo como parametro
			return this->busquedaRecursiva(nodoInterno->getHijoIzq(), claveBuscada, ++iteracion);
		case COMPARACION_NO_VALIDA:
			//no deberia entrar nunca...
			break;
	}

	return NULL;
}

Falla* ArbolKD::getFallas() {
	//TODO implementar
	return NULL;
}

Formacion* ArbolKD::getFormaciones() {
	//TODO implementar
	return NULL;
}

Linea* ArbolKD::getLineas() {
	//TODO implementar
	return NULL;
}

Accidente* ArbolKD::getAccidentes() {
	//TODO implementar
	return NULL;
}

Campo* ArbolKD::getCampoPorFecha(Fecha* comienzo, Fecha* fin) {
	//TODO implementar
	return NULL;
}

bool ArbolKD::raizEsHoja(){
	return this->raiz->esHoja();
}

int ArbolKD::roundRobin(int iteracion) {
	return Clave::cantDimensiones % iteracion;
}
