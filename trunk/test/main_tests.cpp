/*
 * main.cpp
 *
 *  Created on: May 22, 2012
 *      Author: matias_2
 */

#include "Byte_test.h"
#include "Archivo_test.h"
#include "CampoCadena_test.h"
#include "Formacion_test.h"
#include "FranjaHoraria_test.h"
#include "Fecha_test.h"
#include "Horario_test.h"
#include "Clave_test.h"
#include "kdNodoHoja_test.h"
#include "ArbolKD_test.h"
#include "GeneracionClaves_test.h"
#include "kdNodoInterno_test.h"

int main_tests() {

	ArchivoTest();
	ByteTest();
	CampoCadenaTest();
	FormacionTest();
	FranjaHorariaTest();
	FechaTest();
	HorarioTest();
	ClaveTest();
	kdNodoHojaTest();
	kdNodoInternoTest();
	ArbolKDTest();
	GeneracionClavesTest();


	return 0;
}




