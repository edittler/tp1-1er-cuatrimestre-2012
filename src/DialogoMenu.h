#ifndef DIALOGOMENU_H_
#define DIALOGOMENU_H_

#include "Dialogo.h"
#include <iostream>

class DialogoMenu: public Dialogo
{
public:
	DialogoMenu();
	virtual ~DialogoMenu();
	void iniciarDialogo();

private:
	char opcion;
	void dibujarMenu(char *opcion);
};

#endif /*DIALOGOMENU_H_*/
