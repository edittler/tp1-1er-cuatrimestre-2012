/*
 * Parser.h
 *
 *  Created on: May 30, 2012
 *      Author: Oscar Pinto
 */
#ifndef PARSER_H_
#define PARSER_H_

#include "iostream"
#include "list"

using namespace std;

class Parser
{
private:
	const char *cadena;
	char *separador;
public:

	Parser();
	void parsear(char *cadena, const char *separador, list<string> &terminos);
	virtual ~Parser();
};

#endif /*PARSER_H_*/
