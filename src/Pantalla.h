#ifndef PANTALLA_H_
#define PANTALLA_H_

#include "Dialogo.h"

class Pantalla
{
public:
	Pantalla();
	virtual ~Pantalla();
	void ejecutarDialogo(Dialogo *dialogo);
};

#endif /*PANTALLA_H_*/
