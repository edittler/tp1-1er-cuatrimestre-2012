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
				kdNodoInterno* nuevoInterno = new kdNodoInterno();
				this->actualizarPorDesborde(nuevoInterno, nodoRaiz, 1);
				this->raiz = nuevoInterno;
				return 1;
			}
			case 1:
				//TODO Grabar this->raiz == nodoRaiz
				return 1;
			default:
				return resultado;
		}
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
			resultado = this->insertarRecursivo(nodoHijo, clave, iteracion + 1);
			porDerecha = true;
			break;
		case MENOR:
			//TODO Aca deberia cargar nodo hijo Izquierdo y pasarlo como parametro
			nodoHijo = nodoInterno->getHijoIzq();
			resultado = this->insertarRecursivo(nodoHijo, clave, iteracion + 1);
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
			kdNodoInterno* nuevoInterno = new kdNodoInterno();

			this->actualizarPorDesborde(nuevoInterno, nodoHojaDesbordado, iteracion);

			//Actualiza referencia a nuevo nodo interno del padre.
			if (porDerecha) {
				//TODO set ID-Ref_a_bloque
				nodoInterno->setHijoDer(nuevoInterno);
			} else {
				//TODO set ID-Ref_a_bloque
				nodoInterno->setHijoIzq(nuevoInterno);
			}
			//TODO grabar nodoInterno.

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

void ArbolKD::actualizarPorDesborde(kdNodoInterno* nuevoInterno, kdNodoHoja* hojaDesbordado, int iteracion) {

	kdNodoHoja* nuevoHojaDerecha = new kdNodoHoja();

	//obtengo la dimension del campo por la cual se debe ordenar.
	int dimensionReferencia = this->roundRobin(iteracion);

	//get valor medio de nodo hijo desbordado segun el campo a ordenar.
	Campo* valorMedio = hojaDesbordado->getValorMedio(dimensionReferencia);

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

	//Creo nuevo nodo Interno, seteo sus nodo hijos.
	nuevoInterno->setAtributo(valorMedio);
	//TODO set ID/Ref_a_bloque
	nuevoInterno->setHijoDer(nuevoHojaDerecha);
	nuevoInterno->setHijoIzq(hojaDesbordado);

	//valida si algun hijo sigue desborado
	kdNodoInterno* nuevoNodoInterno = new kdNodoInterno();
	if (hojaDesbordado->tieneSobreflujo()) {
		this->actualizarPorDesborde(nuevoNodoInterno, hojaDesbordado, iteracion + 1);
		//TODO set ID-Ref_a_bloque
		nuevoInterno->setHijoIzq(nuevoNodoInterno);
		//TODO grabar nuevoInterno, nuevoHojaDerecha
	} else if (nuevoHojaDerecha->tieneSobreflujo()) {
		this->actualizarPorDesborde(nuevoNodoInterno, nuevoHojaDerecha, iteracion + 1);
		//TODO set ID-Ref_a_bloque
		nuevoInterno->setHijoDer(nuevoNodoInterno);
		//TODO grabar nuevoInterno, hojaDesbordado
	} else {
	//TODO grabar hojaDesbordado, nuevoInterno, nuevoHojaDerecha
	//ESTA SECCION DE ACA ES FUNDAMENTAL!!!!!
	// CUANDO LOS DEMAS METODOS VUELVAN DEL DESBORDE YA CONOCEN SUS POSICIONES DE ESCRITURA POR ESTA SECCION
	//int tamReg;
	//Byte * regHojaDesbordado = hojaDesbordado->obtenerRegistro(&tamReg);
	//PosBloque posHojaDesbordado = this->archivoNodosHoja.escribir(regHojaDesbordado, tamReg);
	//Byte * regNuevoHojaDerecha = nuevoHojaDerecha->obtenerRegistro(&tamReg);
	//PosBloque posNuevoHojaDerecha = this->archivoNodosHoja.escribir(regNuevoHojaDerecha, tamReg);
	//nuevoInterno->setHijoIzqEsHoja(true);
	//nuevoInterno->setPosHijoIzq(posHojaDesbordado);
	//nuevoInterno->setHijoDerEsHoja(true);
	//nuevoInterno->setPosHijoDer(posNuevoHojaDerecha);
	//nuevoInterno NO SE ESCRIBE LO TIENE QUE HACER EL INVOCADOR, PARA QUE LUEGO ALMACENA LA REF DE ESCRITURA
	}
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

void ArbolKD::getTrenesConFalla(Falla* falla, Fecha* comienzo, Fecha* fin) {
	this->getCampoPorFechaRecursivo(this->raiz, 0, falla, comienzo, fin);
}

void ArbolKD::getTrenesConAccidente(Accidente* accidente, Fecha* comienzo, Fecha* fin) {
	this->getCampoPorFechaRecursivo(this->raiz, 0, accidente, comienzo, fin);
}

void ArbolKD::getFallasDeFormacion(Formacion* formacion, Fecha* comienzo, Fecha* fin) {
	this->getCampoPorFechaRecursivo(this->raiz, 3, formacion, comienzo, fin);
}

void ArbolKD::getAccidenteDeFormacion(Formacion* formacion, Fecha* comienzo, Fecha* fin) {
	this->getCampoPorFechaRecursivo(this->raiz, 4, formacion, comienzo, fin);
}

void ArbolKD::getCampoPorFechaRecursivo(kdNodo* nodo, int campoBuscado, Campo* campoReferente, Fecha* fechaComienzo, Fecha* fechaFin) {
	//TODO implementar

	//control de corte para la recursividad
	if (nodo->esHoja()) {
		kdNodoHoja* nodoHoja = dynamic_cast<kdNodoHoja*>(nodo);
		for (int i = 0; i < kdNodoHoja::capacidadNodo; ++i) {
			Clave* clave = nodoHoja->getClave(i);
			if (clave != NULL) {
				//comparo segun el campo referente que estoy buscando.
				if (clave->comparar(campoReferente) == IGUAL) {
					//comparo fechas para ver si esta en el rango.
					ResultadoComparacion comienzo = clave->getCampo(2)->comparar(new FranjaHoraria(fechaComienzo, NULL));
					ResultadoComparacion fin = clave->getCampo(2)->comparar(new FranjaHoraria(fechaFin, NULL));
					if (fechaFin == NULL || ((comienzo == IGUAL || comienzo == MAYOR) && (fin == IGUAL || fin == MENOR))) {
						switch (campoBuscado) {
							case 0: //Linea
								cout << "Linea: " << dynamic_cast<CampoCadena*>(clave->getCampo(campoBuscado))->getDescripcion() << endl;
								break;
							case 3: //Falla
								cout << "Falla: " << dynamic_cast<CampoCadena*>(clave->getCampo(campoBuscado))->getDescripcion() << endl;
								break;
							case 4: //Accidente
								cout << "Accidente: " << dynamic_cast<CampoCadena*>(clave->getCampo(campoBuscado))->getDescripcion() << endl;
								break;
							default:
								cout << "" << endl;
								break;
						}
					}
				}
			}
		}
		return;
	}

	kdNodoInterno* nodoInterno = dynamic_cast<kdNodoInterno*>(nodo);
	ResultadoComparacion resultado = campoReferente->comparar(nodoInterno->getAtributo());

	switch (resultado) {
		case MENOR:
			//TODO cargar nodo Izquierdo y pasarlo por parametro
			getCampoPorFechaRecursivo(nodoInterno->getHijoIzq(), campoBuscado, campoReferente, fechaComienzo, fechaFin);
			break;
		case IGUAL:
		case MAYOR:
			//TODO cargar nodo Derecho y pasarlo por parametro
			getCampoPorFechaRecursivo(nodoInterno->getHijoDer(), campoBuscado, campoReferente, fechaComienzo, fechaFin);
			break;
		case COMPARACION_NO_VALIDA:
			//TODO cargar nodo Izquierdo y pasarlo por parametro
			getCampoPorFechaRecursivo(nodoInterno->getHijoIzq(), campoBuscado, campoReferente, fechaComienzo, fechaFin);
			//TODO cargar nodo Derecho y pasarlo por parametro
			getCampoPorFechaRecursivo(nodoInterno->getHijoDer(), campoBuscado, campoReferente, fechaComienzo, fechaFin);
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
