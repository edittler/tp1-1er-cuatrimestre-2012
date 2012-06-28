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
//	cout << "tam1: " << tam1 << ", tam2: " << tam2 << endl;
	for (i = 0; i < tam1; i++) {
		(*resultado)[i] = registro1[i];
//		cout << "registro1|" << i << ": "<<registro1[i] << endl;
//		cout << "*(resultado)" << i << ": " << (*resultado)[i] << endl;
	}
//	cout << "pasado a 2do registro" << endl;
	for (i = 0; i < tam2; i++) {
		(*resultado)[i+tam1] = registro2[i];
//		cout << "registro2|" << i << ": "<<registro2[i] << endl;
//		cout << "*(resultado)" << i <<"+" << tam1 << ": " << (*resultado)[i+tam1] << endl;
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

Byte* intToBytesPointer(int paramInt)
{
	Byte* byte =  new Byte[sizeof(int)];
	byte[0] =  paramInt & 0x000000ff;
	byte[1] = (paramInt & 0x0000ff00) >> 8;
	byte[2] = (paramInt & 0x00ff0000) >> 16;
	byte[3] = (paramInt & 0xff000000) >> 24;
	return byte;
}
