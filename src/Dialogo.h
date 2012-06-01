#ifndef DIALOGO_H_
#define DIALOGO_H_

#include "stdlib.h"
#include "string.h"
#include "stdio.h"
#include "iostream"

using namespace std;

class Dialogo
{
public:
	Dialogo();
	virtual ~Dialogo();
	virtual void iniciarDialogo() = 0;
	void limpiarPantalla();
};

#endif /*DIALOGO_H_*/
