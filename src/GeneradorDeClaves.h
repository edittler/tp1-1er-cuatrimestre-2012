/*
 * Clase que genera las claves a partir de una lista de terminos.
 *
 *  Created on: 31/05/2012
 *      Author: Oscar Pinto
 */

#ifndef GENERADORDECLAVES_H_
#define GENERADORDECLAVES_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Parser.h"
#include "Clave.h"

class GeneradorDeClaves
{
public:
	void generarClave(list<string> campos, Clave *clave);
	GeneradorDeClaves();
	virtual ~GeneradorDeClaves();
private:
	list<string>::iterator it;
	list<string>::iterator itAux;
	list<string>::iterator itAux2;
	list<string>::iterator itAux3;
	Parser parser;
};

#endif /*GENERADORDECLAVES_H_*/
