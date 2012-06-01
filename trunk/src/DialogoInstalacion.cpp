#include "DialogoInstalacion.h"

DialogoInstalacion::DialogoInstalacion(ArchivoCSV *archivoCSV)
{
	this->archivoCSV = archivoCSV;
}

void DialogoInstalacion::iniciarDialogo() {
	cout << "Bienvenido al sistema de consultas de ferrocarriles" << endl;
	cout << "Ingrese el nombre del archivo contenedor de los datos a analizar" << endl;
	cin >> nombreArchivo;
	archivoCSV->abrirArchivo(nombreArchivo.c_str());
}

DialogoInstalacion::~DialogoInstalacion()
{
}
