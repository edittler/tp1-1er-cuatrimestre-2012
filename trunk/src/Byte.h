/*
 * Byte.h
 *
 */

#ifndef BYTE_H_
#define BYTE_H_

#include <stdlib.h>
#include <iostream>

using namespace std;

typedef char Byte;

/* Es una funcion que recibe la cadena origen de bytes a copiar, un puntero (que debe
 * ser NULL, caso contrario se perderá la informacion sin liberar la memoria) donde se
 *  almacenará el resultado, el inicio a partir del cual se empezará a copiar y
 * el tamaño de la cadena de bytes a copiar
 */
void obtenerPorcion(Byte *, Byte **, int, int);

/* Función que concatena dos cadenas de bytes y almacena la cadena del resultado
 * en un puntero que se recibe por parametro (que debe ser NULL, caso contrario se
 * perderá la informacion sin liberar la memoria).
 */
void concatenar(Byte **, Byte *, int, Byte*, int);

Byte * convertirAByte(string unString);

Byte* intToBytesPointer(int paramInt);

int bytesToInt(Byte* bytes);

#endif /* BYTE_H_ */
