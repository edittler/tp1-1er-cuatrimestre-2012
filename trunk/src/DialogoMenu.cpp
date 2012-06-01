#include "DialogoMenu.h"
#include <iostream>
#include <stdlib.h>

DialogoMenu::DialogoMenu()
{
}

void DialogoMenu::iniciarDialogo() {

	do {

		dibujarMenu(&opcion);
		switch(opcion) {
			case '1': {
				string consultaFalla;
				cout << "Ingrese la falla" << endl;
				cin >> consultaFalla;
				//TODO armar el la clave y devolverla junto con el tipo de consulta
				break;
			}
			case '2': {
				string consultaAccidente;
				cout << "Ingrese el accidente" << endl;
				cin >> consultaAccidente;
				//TODO armar el la clave y devolverla junto con el tipo de consulta
				break;
			}
			case '3': {
				string consultaFalla;
				cout << "Ingrese el la falla" << endl;
				cin >> consultaFalla;
				string consultaFormacion;
				cout << "Ingrese el la formacion" << endl;
				cin >> consultaFormacion;
				//TODO armar el la clave y devolverla junto con el tipo de consulta
				break;
			}
			case '4': {
				string consultaAccidente;
				cout << "Ingrese el accidente" << endl;
				cin >> consultaAccidente;
				string consultaFormacion;
				cout << "Ingrese el la formacion" << endl;
				cin >> consultaFormacion;
				//TODO armar el la clave y devolverla junto con el tipo de consulta
				break;
			}
			case '5': {
				cout << "Las siguientes son todas las fallas reportadas:" << endl;
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

DialogoMenu::~DialogoMenu()
{
}
