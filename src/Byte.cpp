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
void obtenerPorcion(Byte * origen, Byte ** resultado, int inicio, int tam) {
	*resultado = new Byte[tam];
	int i;
	int j = 0;
	for (i=inicio; i<(inicio+tam); i++) {
		(*resultado)[j] = origen[i];
		j++;
	}
}

/* Función que concatena dos cadenas de bytes y almacena la cadena del resultado
 * en un puntero que se recibe por parametro (que debe ser NULL, caso contrario se
 * perderá la informacion sin liberar la memoria).
 */
void concatenar(Byte ** resultado, Byte * registro1, int tam1, Byte* registro2, int tam2) {
	*resultado = new Byte[tam1+tam2];
	int i;
	for (i = 0; i < tam1; i++) {
		(*resultado)[i] = registro1[i];
	}
	for (i = 0; i < tam2; i++) {
		(*resultado)[i+tam1] = registro2[i];
	}
}

Byte * convertirAByte(string unString){
	int tam = unString.size();
	Byte * bytes = new Byte[tam];
	int i;
	for (i=0; i<tam; i++) {
		bytes[i] = unString[i];
	}
	return bytes;
}
