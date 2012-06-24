#include<string>
#include<list>
#include <cstring>
#include <stdio.h>
#include "../src/Parser.h"
#include "../src/ArchivoCSV.h"
#include "../src/GeneradorDeClaves.h"

using namespace std;

void GeneracionClavesTest() {

	cout << "Pruebas Unitarias: Generacion Claves"<< endl;

	ArchivoCSV *archivo = new ArchivoCSV();
	Parser *parser = new Parser();
	char cadena[100];
	list<string> campos;
	GeneradorDeClaves *generador = new GeneradorDeClaves();
	Clave *clave1 = new Clave();
	Clave *clave2 = new Clave();
	Clave *clave3 = new Clave();

	archivo->abrirArchivo("claves.txt");

	campos.clear();
	archivo->leerLinea(cadena);
	parser->parsear(cadena, ";", campos);
	generador->generarClave(campos, clave1);

	campos.clear();
	archivo->leerLinea(cadena);
	parser->parsear(cadena, ";", campos);
	generador->generarClave(campos, clave2);

	campos.clear();
	archivo->leerLinea(cadena);
	parser->parsear(cadena, ";", campos);
	generador->generarClave(campos, clave3);


	//Comparaciones de Claves

	//Se generaron con campos diferentes => son diferentes
	if (clave2->comparar(clave1) == IGUAL) {
			cout << "Ok.....comparar clave igual" << endl;
		} else {
			cout << "Fail...comparar clave igual" << endl;
		}

	//Se generaron con campos iguales => son iguales
	if (clave3->comparar(clave2) == IGUAL) {
				cout << "Ok.....comparar clave igual" << endl;
			} else {
				cout << "Fail...comparar clave igual" << endl;
			}


	archivo->cerrarArchivo();

	delete archivo;
	delete parser;
	delete clave1;
	delete clave2;
	delete clave3;
	delete generador;

	cout << endl;

}
