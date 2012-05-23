#pragma once

#include <fstream> // header para el manejo de archivos en c++
#include <string>

using namespace std;

/*

Clase Archivo

Esta clase soporta acceso relativo para lecturas y asignación automática de
bloques para escritura a archivo.

*/

typedef char Byte;
typedef int PosBloque; // posición en archivo de un bloque de datos


class Archivo
{
private:
	string nombreArchivo;
	string nombreArchivoEspaciosLibres;
	int tamBloque;
	int cantBloquesLibres;
	int cantBloques;

	void escribirBloque(PosBloque, Byte *, int);
	PosBloque obtenerBloqueLibre();
public:
	

	Archivo(string);
	~Archivo(void);

	// Escribe en el archivo un arreglo de bytes de tamaño dado por un int,
	// devuelve la posición del bloque donde se insertó el arreglo de bytes.
	PosBloque escribir(Byte *, int);


	// lee de archivo un bloque especificado por la posición PosBloque, devuelve 
	// el contenido en un arreglo de bytes.
	void leer(PosBloque, Byte **, int *);

	void liberarBloque(PosBloque);

	void actualizar(PosBloque, Byte *, int);

	int obtenerTamBloque();
};

