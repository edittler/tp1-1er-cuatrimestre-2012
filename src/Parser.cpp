#include <stdio.h>
#include <string.h>
#include "Parser.h"

Parser::Parser() {
}

Parser::~Parser() {
}

void Parser::parsear(char *cadena, const char *separador, list<string> &terminos) {
	terminos.clear();
	char *termino;
	termino = strtok(cadena, separador);
	while(termino != NULL) {
		terminos.push_back(termino);
		termino = strtok (NULL, separador);
	}
}
