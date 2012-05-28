#pragma once

#include <fstream> // header para el manejo de archivos en c++
#include <string>

using namespace std;

/*

Clase Archivo

Esta clase soporta acceso relativo para lecturas y asignaci�n autom�tica de
bloques para escritura a archivo.

*/

typedef char Byte;
typedef int PosBloque; // posici�n en archivo de un bloque de datos


class Archivo
{
private:
	char* nombreArchivo;
	char* nombreArchivoEspaciosLibres;
	int tamBloque;
	int cantBloquesLibres;
	int cantBloques;

	void escribirBloque(PosBloque, Byte *, int);
	PosBloque obtenerBloqueLibre();

	char * aCharP(string);
public:
	

	Archivo(string);
	~Archivo(void);

	// Escribe en el archivo un arreglo de bytes de tama�o dado por un int,
	// devuelve la posici�n del bloque donde se insert� el arreglo de bytes.
	PosBloque escribir(Byte *, int);


	// lee de archivo un bloque especificado por la posici�n PosBloque, devuelve 
	// el contenido en un arreglo de bytes.
	void leer(PosBloque, Byte **, int *);

	void liberarBloque(PosBloque);

	void actualizar(PosBloque, Byte *, int);

	int obtenerTamBloque();
};

