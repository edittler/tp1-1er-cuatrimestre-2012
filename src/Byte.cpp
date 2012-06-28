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
void concatenar(Byte** resultado, Byte* registro1, int tam1, Byte* registro2, int tam2) {
	int tamTot = tam1 + tam2;
	*resultado = new Byte[tamTot];
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
	Byte * bytes = new Byte[tam+1];
	int i;
	for (i=0; i<tam; i++) {
		bytes[i] = unString[i];
	}
	bytes[tam] = '\0';
	return bytes;
}

Byte* intToBytes(int unInt)
{
	Byte* byte =  new Byte[sizeof(int)];
	byte[0] =  unInt & 0x000000ff;
	byte[1] = (unInt & 0x0000ff00) >> 8;
	byte[2] = (unInt & 0x00ff0000) >> 16;
	byte[3] = (unInt & 0xff000000) >> 24;
	return byte;
}

int bytesToInt(Byte* bytes) {
	int entero = 0;
	unsigned char temp;
	for(int i=0; i<4; i++){
		temp = bytes[i];
		entero = entero + (temp << (8*i));
	}
	return entero;
}
