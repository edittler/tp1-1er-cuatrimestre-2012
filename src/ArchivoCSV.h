/*
 * Archivo que contiene los campos a parsear
 *
 *  Created on: 31/05/2012
 *      Author: Oscar Pinto
 */

#ifndef ARCHIVOCSV_H_
#define ARCHIVOCSV_H_

#include <stdio.h>
#include <string>

using namespace std;

class ArchivoCSV
{
private:
	FILE *fd;
	bool archivoEstaAbierto();
public:
	bool abrirArchivo(const char *path);
	void cerrarArchivo();
	bool leerLinea(char *cadena);
	ArchivoCSV();
	virtual ~ArchivoCSV();
};

#endif /*ARCHIVOCSV_H_*/
