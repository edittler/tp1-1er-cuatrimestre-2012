#include "ArchivoCSV.h"

ArchivoCSV::ArchivoCSV()
{
	fd = NULL;
}

bool ArchivoCSV::abrirArchivo(const char *path) {
	fd = fopen(path, "r");
	return fd;
}

void ArchivoCSV::cerrarArchivo() {
	if(fd) {
		fclose(fd);
		fd = NULL;
	}
}

bool ArchivoCSV::archivoEstaAbierto() {
	return fd;
}

bool ArchivoCSV::leerLinea(char *cadena) {
	if(fd) {
	if(fgets(cadena, 100, fd) != NULL)
		return true;
	}
	return false;
}

ArchivoCSV::~ArchivoCSV()
{
	this->cerrarArchivo();
}
