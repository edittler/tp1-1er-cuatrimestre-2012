#ifndef PANTALLAINSTALACION_H_
#define PANTALLAINSTALACION_H_

#include "Dialogo.h"
#include "ArchivoCSV.h"
#include "string"
#include "iostream"

class DialogoInstalacion : public Dialogo
{
public:
	DialogoInstalacion(ArchivoCSV *archivoCSV);
	virtual ~DialogoInstalacion();
	void iniciarDialogo();
private:
	string nombreArchivo;
	ArchivoCSV *archivoCSV;
};

#endif /*PANTALLAINSTALACION_H_*/
