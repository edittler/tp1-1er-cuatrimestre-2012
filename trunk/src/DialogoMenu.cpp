#include "DialogoMenu.h"
#include <iostream>
#include <stdlib.h>
#include <ctype.h>

DialogoMenu::DialogoMenu(ArbolKD *arbol) {
	this->arbolKD = arbol;
	fechaInicial = NULL;
	fechaFinal = NULL;
}

void DialogoMenu::iniciarDialogo() {



	do {

		dibujarMenu(&opcion);
		switch(opcion) {
			case '1': {
				string consultaFalla;
				cout << "Ingrese la falla" << endl;
				cin >> consultaFalla;
				dialogoRangoDeFechas(fechaInicial, fechaFinal);
				//arbolKD->getTrenesConFalla(new Falla(consultaFalla), fechaInicial, fechaFinal);
				limpiarFechas();
				break;
			}
			case '2': {
				string consultaAccidente;
				cout << "Ingrese el accidente" << endl;
				cin >> consultaAccidente;
				dialogoRangoDeFechas(fechaInicial, fechaFinal);
				//arbolKD->getTrenesConAccidente(new Accidente(consultaAccidente), fechaInicial, fechaFinal);
				limpiarFechas();
				break;
			}
			case '3': {
				int consultaFormacion;
				cout << "Ingrese el la formacion" << endl;
				cin >> consultaFormacion;
				dialogoRangoDeFechas(fechaInicial, fechaFinal);
				//arbolKD->getFallasDeFormacion(new Formacion(consultaFormacion), fechaInicial, fechaFinal);
				limpiarFechas();
				break;
			}
			case '4': {
				int consultaFormacion;
				cout << "Ingrese el la formacion" << endl;
				cin >> consultaFormacion;
				dialogoRangoDeFechas(fechaInicial, fechaFinal);
				//arbolKD->getAccidenteDeFormacion(new Formacion(consultaFormacion), fechaInicial, fechaFinal);
				limpiarFechas();
				break;
			}
			case '5': {
				//TODO llamar al metodo del KD que muestra esto
				break;
			}
			case '6': {
				cout << "Las siguientes son todas las formaciones registradas:" << endl;
				//TODO llamar al metodo del KD que muestra esto
				break;
			}
			case '7': {
				cout << "Las siguientes son todas las lineas registradas:" << endl;
				//TODO llamar al metodo del KD que muestra esto
				break;
			}
			case '8': {
				cout << "Los siguientes son todas los accidentes reportados:" << endl;
				//TODO llamar al metodo del KD que muestra esto
				break;
			}
			case '9': {
				break;
			}
			default :{
				cout << "Opcion no valida. Intentelo nuevamente" << endl;
				cin >> opcion;
				break;
			}
		}

	} while (opcion != '9');

}

void DialogoMenu::dibujarMenu(char *opcion) {
	limpiarPantalla();
	cout << "Elija una opcion" << endl;
	cout << "[1]Consultar todos los trenes que tienen cierta falla" << endl;
	cout << "[2]Consultar todos los trenes con cierto accidente" << endl;
	cout << "[3]Consultar todas las fallas de una formacion determinada" << endl;
	cout << "[4]Consultar todos los accidentes de una formacion determinada" << endl;
	cout << "[5]Consultar todas las fallas" << endl;
	cout << "[6]Consultar todas las formaciones" << endl;
	cout << "[7]Consultar todas las lineas" << endl;
	cout << "[8]Consultar todos los accidentes" << endl;
	cout << "[9]Salir" << endl;
	cin >> *opcion;
}

void DialogoMenu::dialogoRangoDeFechas(Fecha *fechaInicial, Fecha *fechaFinal) {
	char opcion;
	bool continuar = true;
	while(continuar) {
		cout << "¿Desea ingresar un rango de fechas? (s/n)" << endl;
		cin >> opcion;
		switch(toupper(opcion)) {
			case 'S': {
				fechaInicial = new Fecha();
				fechaFinal = new Fecha();
				dialogoIngresarFechas(fechaInicial, fechaFinal);
				continuar = false;
				break;
			}
			case 'N': {
				limpiarFechas();
				continuar = false;
				break;
			}
			default : {
				cout << "Opcion no valida. Debe ingresar 's' o 'n'" << endl;
				break;
			}
		}
	}
}

void DialogoMenu::dialogoIngresarFechas(Fecha *fechaInicial, Fecha *fechaFinal) {
	int dia,mes,anio;

	cout << "Ingresando la fecha inicial:" << endl;
	leerFecha(dia, mes, anio);
	fechaInicial->setFecha(dia, mes, anio);

	cout << "Ingresando la fecha final" << endl;
	leerFecha(dia, mes, anio);
	fechaFinal->setFecha(dia, mes, anio);
}

void DialogoMenu::leerFecha(int &dia, int &mes, int &anio) {
	cout << "Ingrese el dia: ";
	cin >> dia;
	cout << " -- ";
	cout << "Ingrese el mes: ";
	cin >> mes;
	cout << " -- ";
	cout << "Ingrese el año: ";
	cin >> anio;
	cout << endl;
	cout << "Fecha Ingresada: " << dia << "/" << mes << "/" << anio << endl;
}

void DialogoMenu::limpiarFechas() {
	if(fechaInicial != NULL)
		delete fechaInicial;
	if(fechaFinal != NULL)
		delete fechaFinal;
}

DialogoMenu::~DialogoMenu()
{
}
