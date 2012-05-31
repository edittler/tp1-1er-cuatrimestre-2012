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

	int resultado;

	if (raizEsHoja()) {
		kdNodoHoja* nodoRaiz = dynamic_cast<kdNodoHoja*>(this->raiz);
		resultado = nodoRaiz->insertar(*nuevaClave);

		switch (resultado) {
			case 2: {
				kdNodoHoja* nuevoHoja = new kdNodoHoja();
				kdNodoInterno* nuevoInterno = new kdNodoInterno();
				this->actualizarPorDesborde(nuevoInterno, nodoRaiz, nuevoHoja, 1);
				this->raiz = nuevoInterno;
				//TODO Grabar nodoRaiz, this->raiz == nuevoInterno, nuevoHoja.
				return 1;
			}
			case 1:
				//TODO Grabar this->raiz == nodoRaiz
				return 1;
			default:
				return resultado;
		}

//		if (resultado == 2) { //nodo raiz desbordado
//			kdNodoHoja* nuevoHoja = new kdNodoHoja();
//			kdNodoInterno* nuevoInterno = new kdNodoInterno();
//			this->actualizarPorDesborde(nuevoInterno, nodoRaiz, nuevoHoja, 1);
//			this->raiz = nuevoInterno;
//			//TODO Grabar nodoRaiz, this->raiz == nuevoInterno, nuevoHoja.
//			return 1;
//		}
//		return resultado;

	} else {
		resultado = this->insertarRecursivo(this->raiz, nuevaClave, 1);
		if (resultado == 1) {
			//TODO grabar this->raiz.
			return 0;
		}
		return resultado;
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
	kdNodo* nodoHijo;
	kdNodoInterno* nodoInterno = dynamic_cast<kdNodoInterno*>(nodo);
	ResultadoComparacion comparacion = clave->comparar(nodoInterno->getAtributo());

	//segun comparacion avanza a derecha o izquierda.
	switch (comparacion) {
		case IGUAL:
		case MAYOR:
			//TODO Aca deberia cargar nodo hijo derecho y pasarlo como parametro
			nodoHijo = nodoInterno->getHijoDer();
			resultado = this->insertarRecursivo(nodoHijo, clave, ++iteracion);
			porDerecha = true;
			break;
		case MENOR:
			//TODO Aca deberia cargar nodo hijo Izquierdo y pasarlo como parametro
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

			kdNodo* nodoSigueDesborde = this->actualizarPorDesborde(nuevoInterno, nuevoNodoHojaDerecha, nodoHojaDesbordado, iteracion);

			//Actualiza referencia a nuevo nodo interno del padre.
			if (porDerecha) {
				nodoInterno->setHijoDer(nuevoInterno);
			} else {
				nodoInterno->setHijoIzq(nuevoInterno);
			}

			//TODO fin de insercion, grabar nuevoNodoHojaDerecha, nodoHojaDesbordado.

			//si algun nodo hijo sigue con overflow
			//TODO ver que se cumpla recursividad.
//			if (!nodoSigueDesborde) {
//				return this->insertarRecursivo(nodoSigueDesborde, clave, ++iteracion);
//			}
			return 1;
		}
		default:
		case 1: //el nodo se actualizo
			//TODO guarda nodoHijo.
			return 0;
		case 3: //el nodo ya contenia la clave que se quiere ingresar.
			return 3;
	}
}

kdNodo* ArbolKD::actualizarPorDesborde(kdNodoInterno* nuevoInterno, kdNodoHoja* hojaDesbordado, kdNodoHoja* nuevoHojaDerecha, int iteracion) {

	//obtengo la dimension del campo por la cual se debe ordenar.
	int dimensionReferencia = this->roundRobin(iteracion);

	//get valor medio de nodo hijo desbordado segun el campo a ordenar.
	Campo* valorMedio = hojaDesbordado->getValorMedio(dimensionReferencia);

	cout << " ---------- debug" << endl;
	cout << "valorMedio: " << valorMedio << endl;
	cout << "Casteo linea: "<< dynamic_cast<Linea*>(valorMedio)->getDescripcion() << endl;

	//divido nodo hoja segun valor medio.
	for (int j = 0; j < (kdNodoHoja::capacidadNodo + 1); j++) {
		Clave* clave =hojaDesbordado->getClave(j);
		if (clave != NULL) {
			Campo* campo = clave->getCampo(dimensionReferencia);
			ResultadoComparacion res = campo->comparar(valorMedio);
			if (campo != NULL && ( res == MAYOR || res == IGUAL)) {
				nuevoHojaDerecha->insertar(*clave);
				hojaDesbordado->eliminar(*clave);
			}
		}
	}

	cout << " ---------- debug" << endl;
	cout << "valorMedio: " << valorMedio << endl;
	cout << "Casteo linea: "<< dynamic_cast<Linea*>(valorMedio)->getDescripcion() << endl;

	//Creo nuevo nodo Interno, seteo sus nodo hijos.
	nuevoInterno->setAtributo(valorMedio);
	//TODO set ID/Ref_a_bloque
	nuevoInterno->setHijoDer(nuevoHojaDerecha);
	nuevoInterno->setHijoIzq(hojaDesbordado);

	//valida si algun hijo sigue desborado
	if (hojaDesbordado->tieneSobreflujo()) {
		return hojaDesbordado;
	} else if (nuevoHojaDerecha->tieneSobreflujo()) {
		return nuevoHojaDerecha;
	}
	return NULL;
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
