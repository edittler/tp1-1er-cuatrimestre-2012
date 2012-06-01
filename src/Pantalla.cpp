#include "Pantalla.h"

Pantalla::Pantalla()
{
}

void Pantalla::ejecutarDialogo(Dialogo *dialogo) {
	dialogo->iniciarDialogo();
}

Pantalla::~Pantalla()
{
}
