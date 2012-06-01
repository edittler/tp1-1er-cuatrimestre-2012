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
			//TODO set ID/Ref_a_bloque
			if (porDerecha) {
				nodoInterno->setHijoDer(nuevoInterno);
			} else {
				nodoInterno->setHijoIzq(nuevoInterno);
			}

			//TODO fin de insercion, grabar nuevoNodoHojaDerecha, nodoHojaDesbordado.

			//si algun nodo hijo sigue con overflow
			//TODO ver que se cumpla recursividad.
			if (!nodoSigueDesborde) {
//				return this->insertarRecursivo(nodoSigueDesborde, clave, ++iteracion);
			}
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

void ArbolKD::getTrenesConFalla(Falla* falla, Fecha* comienzo, Fecha* fin, Campo** listaResultado) {
	this->getCampoPorFechaRecursivo(listaResultado, this->raiz, 0, falla, comienzo, fin);
}

void ArbolKD::getTrenesConAccidente(Accidente* accidente, Fecha* comienzo, Fecha* fin, Campo** listaResultado) {
	this->getCampoPorFechaRecursivo(listaResultado, this->raiz, 0, accidente, comienzo, fin);
}

void ArbolKD::getFallasDeFormacion(Formacion* formacion, Fecha* comienzo, Fecha* fin, Campo** listaResultado) {
	this->getCampoPorFechaRecursivo(listaResultado, this->raiz, 3, formacion, comienzo, fin);
}

void ArbolKD::getAccidenteDeFormacion(Formacion* formacion, Fecha* comienzo, Fecha* fin, Campo** listaResultado) {
	this->getCampoPorFechaRecursivo(listaResultado, this->raiz, 4, formacion, comienzo, fin);
}

void ArbolKD::getCampoPorFechaRecursivo(Campo** listaResultado, kdNodo* nodo, int campoBuscado, Campo* campoReferente, Fecha* fechaComienzo, Fecha* fechaFin) {
	//TODO implementar

	//control de corte para la recursividad
	if (nodo->esHoja()) {
		kdNodoHoja* nodoHoja = dynamic_cast<kdNodoHoja*>(nodo);
		for (int i = 0; i < kdNodoHoja::capacidadNodo; ++i) {
			Clave* clave = nodoHoja->getClave(i);
			if (clave != NULL) {
				//comparo segun el campo referente que estoy buscando.
				if (campoReferente->comparar(clave->getCampo(campoBuscado)) == IGUAL) {
					//comparo fechas para ver si esta en el rango.
					//TODO probar que pasa si las fechas son NULL
					ResultadoComparacion comienzo = clave->getCampo(2)->comparar(new FranjaHoraria(fechaComienzo, NULL));
					ResultadoComparacion fin = clave->getCampo(2)->comparar(new FranjaHoraria(fechaFin, NULL));
					if ((comienzo == IGUAL || comienzo == MAYOR) && (fin == IGUAL || fin == MENOR)) {
						//add to listaResultado
					}
				}
			}
		}
	}

	kdNodoInterno* nodoInterno = dynamic_cast<kdNodoInterno*>(nodo);
	ResultadoComparacion resultado = campoReferente->comparar(nodoInterno->getAtributo());

	switch (resultado) {
		case MENOR:
			//TODO cargar nodo Izquierdo y pasarlo por parametro
			getCampoPorFechaRecursivo(listaResultado, nodoInterno->getHijoIzq(), campoBuscado, campoReferente, fechaComienzo, fechaFin);
			break;
		case IGUAL:
		case MAYOR:
			//TODO cargar nodo Derecho y pasarlo por parametro
			getCampoPorFechaRecursivo(listaResultado, nodoInterno->getHijoDer(), campoBuscado, campoReferente, fechaComienzo, fechaFin);
			break;
		case COMPARACION_NO_VALIDA:
			//TODO cargar nodo Izquierdo y pasarlo por parametro
			getCampoPorFechaRecursivo(listaResultado, nodoInterno->getHijoIzq(), campoBuscado, campoReferente, fechaComienzo, fechaFin);
			//TODO cargar nodo Derecho y pasarlo por parametro
			getCampoPorFechaRecursivo(listaResultado, nodoInterno->getHijoDer(), campoBuscado, campoReferente, fechaComienzo, fechaFin);
			break;
		default:
			break;
	}

}

bool ArbolKD::raizEsHoja(){
	return this->raiz->esHoja();
}

int ArbolKD::roundRobin(int iteracion) {
	return Clave::cantDimensiones % iteracion;
}
