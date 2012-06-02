/*****************************************************************************
#include <stdio.h>
#include "Pantalla.h"
#include "ArchivoCSV.h"
#include "DialogoInstalacion.h"
#include "DialogoMenu.h"
#include "ArbolKD.h"

using namespace std;

void limpiarLinea(char *linea);

int main() {
	ArbolKD *arbol = new ArbolKD();
	Pantalla *pantalla = new Pantalla;
	ArchivoCSV *archivoCSV = new ArchivoCSV();
	Parser *parser = new Parser();
	GeneradorDeClaves *generadorDeClaves = new GeneradorDeClaves();
	char *lineaDelArchivo;
	list<string> camposParseados;
	Clave *claveGenerada;
************************************************************************************/

	//-----------------------------------------------------
	//-----Proceso de instalacion
	//-----------------------------------------------------
/*	pantalla->ejecutarDialogo(new DialogoInstalacion(archivoCSV));

	lineaDelArchivo = new char[100];
	while(archivoCSV->leerLinea(lineaDelArchivo)) {
		parser->parsear(lineaDelArchivo, ";", camposParseados);
		claveGenerada = new Clave();
		generadorDeClaves->generarClave(camposParseados, claveGenerada);
		arbol->insertar(claveGenerada);
		limpiarLinea(lineaDelArchivo);
	}
	******************************************************************************************/

	//-----------------------------------------------------
	//-----Proceso de consultas
	//-----------------------------------------------------
/*	pantalla->ejecutarDialogo(new DialogoMenu(arbol));

	return 0;

}

void limpiarLinea(char *linea) {
	if(linea != NULL)
		delete []linea;
	linea = new char[100];
}
*****************************************/



