#ifndef DIALOGOMENU_H_
#define DIALOGOMENU_H_

#include "Dialogo.h"
#include "GeneradorDeClaves.h"
#include "ArbolKD.h"
#include "Clave.h"
#include <iostream>

class DialogoMenu: public Dialogo
{
public:
	DialogoMenu(ArbolKD *arbol);
	virtual ~DialogoMenu();
	void iniciarDialogo();

private:
	char opcion;
	void dibujarMenu(char *opcion);
	void dialogoRangoDeFechas(Fecha *fechaInicial, Fecha *fechaFinal);
	void dialogoIngresarFechas(Fecha *fechaInicial, Fecha *fechaFinal);
	void leerFecha(int &dia, int &mes, int &anio);
	void limpiarFechas();
	GeneradorDeClaves generadorDeClaves;
	ArbolKD *arbolKD;
	Fecha *fechaInicial;
	Fecha *fechaFinal;
};

#endif /*DIALOGOMENU_H_*/
