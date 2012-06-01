#include "Archivo.h"
#include <iostream>
using namespace std;

#define N 2

Archivo::Archivo(string nombreArchivoNuevo)
{
//	nombreArchivo = nombreArchivoNuevo;
//	nombreArchivoEspaciosLibres.append("EspaciosLibres");
//	nombreArchivoEspaciosLibres.append(nombreArchivoNuevo);
	nombreArchivo = convertirAByte(nombreArchivoNuevo);
	string temp;
	temp.append("EspaciosLibres");
	temp.append(nombreArchivoNuevo);
	nombreArchivoEspaciosLibres = convertirAByte(temp);
	tamBloque = 512*4; // tama�o en bytes de un bloque 
	cantBloquesLibres = 0;
	cantBloques = 0;
}


Archivo::~Archivo(void)
{
}

void Archivo::escribirBloque(PosBloque bloqueEscritura, Byte * bloqueMemoria, int tam) {
	ofstream oarchivo;
	oarchivo.open(nombreArchivo, ios::out | ios::binary | ios::app);
	if (oarchivo.is_open()) {
		if (tam <= tamBloque-4) {
			oarchivo.seekp(bloqueEscritura, ios::beg); // posiciona el puntero del stream en el bloque indicado
			Byte * tamRegistro;
			tamRegistro =  new Byte[4];
			*tamRegistro = tam;
			oarchivo.write(tamRegistro, 4);
			oarchivo.seekp(bloqueEscritura+4, ios::beg);
			oarchivo.write(bloqueMemoria, tam); // escribe la informaci�n en el bloque
			Byte * relleno;
			relleno = new Byte[tamBloque-tam-4];
			int i;
			for (i=0; i<tamBloque-tam-4; i++) {
				relleno[i] = '0';
			}
			oarchivo.seekp(bloqueEscritura+tam+4, ios::beg);
			oarchivo.write(relleno, tamBloque-tam-4);
			oarchivo.close();
		}
		else {
			// lanzar error el bloque de memoria es mayor al bloque de archivo
		}
		
	}
	else {
		//lanzar excepcion de error al abrir archivo
	}
}

PosBloque Archivo::escribir(Byte * bloqueMemoria, int tam) {
	PosBloque bloqueInsercion = Archivo::obtenerBloqueLibre();
	Archivo::escribirBloque(bloqueInsercion, bloqueMemoria, tam);
	cantBloques++;
	return bloqueInsercion;

}

void Archivo::actualizar(PosBloque bloqueEscritura, Byte * bloqueMemoria, int tam) {
	
	Archivo::escribirBloque(bloqueEscritura, bloqueMemoria, tam);
}

void Archivo::leer(PosBloque bloqueLectura, Byte ** bloqueMemoria, int * tamanio) {

	ifstream iarchivo;
	iarchivo.open(nombreArchivo, ios::in | ios::binary);
	if (iarchivo.is_open()) {
		Byte * tamRegistro;
		tamRegistro = new Byte[4];
		iarchivo.seekg(bloqueLectura, ios::beg);
		iarchivo.read(tamRegistro, 4);
		*tamanio = *tamRegistro;
		*bloqueMemoria = new char [*tamanio]; // reservo memoria para el bloque a leer
		iarchivo.seekg(bloqueLectura+4, ios::beg);
		iarchivo.read(*bloqueMemoria, *tamanio);
		iarchivo.close();
	}
	else {
		//lanzar excepcion de error al abrir archivo
	}
}

void Archivo::liberarBloque(PosBloque bloqueLibre) {
	ofstream oarchivo;
	oarchivo.open(nombreArchivoEspaciosLibres, ios::out | ios::binary | ios::app);
	if (oarchivo.is_open()) {
		Byte * registro;
		registro = new Byte[4]; // registro de 4 bytes, que es el tama�o del tipo PosBloque
		*registro = bloqueLibre;
		oarchivo.seekp(cantBloquesLibres*4, ios::beg);
		oarchivo.write(registro, 4);
		oarchivo.close();
		cantBloquesLibres++;
		cantBloques--;
	}
	else {
		//lanzar excepcion de error al abrir archivo
	}
}

PosBloque Archivo::obtenerBloqueLibre() {
	if (cantBloquesLibres==0) {
		PosBloque bloqueLibre = cantBloques*tamBloque;
		return bloqueLibre;
	}
	else {
		ifstream iarchivo;
		iarchivo.open(nombreArchivoEspaciosLibres, ios::in | ios::binary);
		if (iarchivo.is_open()) {
			Byte * registro;
			registro = new Byte[4];
			iarchivo.seekg((cantBloquesLibres-1)*4, ios::beg);
			iarchivo.read(registro, 4);
			iarchivo.close();
			cantBloquesLibres--;
			PosBloque bloqueLibre = *registro;
			return bloqueLibre;
		}
		else {
			//lanzar excepcion de error al abrir archivo
		}
	}
	//PosBloque bloque;
	return 0;
}

int Archivo::obtenerTamBloque() {
	return tamBloque-sizeof(int);
}

