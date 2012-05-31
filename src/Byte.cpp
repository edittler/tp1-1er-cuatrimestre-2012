/*
 * Byte.cpp
 *
 */

#include "Byte.h"

/* Es una funcion que recibe la cadena origen de bytes a copiar, un puntero (que debe
 * ser NULL, caso contrario se perderá la informacion sin liberar la memoria) donde se
 *  almacenará el resultado, el inicio a partir del cual se empezará a copiar y
 * el tamaño de la cadena de bytes a copiar
 */
void obtenerPorcion(const Byte *origen, Byte *resultado, int inicio, int tam) {
	resultado = new Byte[tam];
	int posOrigen = inicio;
	for (int i = 0; i < tam; i++) {
		resultado[0] = origen[posOrigen];
		posOrigen++;
	}
}

/* Función que concatena dos cadenas de bytes y almacena la cadena del resultado
 * en un puntero que se recibe por parametro (que debe ser NULL, caso contrario se
 * perderá la informacion sin liberar la memoria).
 */
void concatenar(Byte *resultado, Byte *registro1, int tam1, Byte*registro2, int tam2) {
	resultado = new Byte[tam1+tam2];
	int i;
	for (i = 0; i < tam1; i++) {
		resultado[i] = registro1[i];
	}
	for (i = tam1; i < tam1+tam2; i++) {
		resultado[i] = registro2[i];
	}
}
