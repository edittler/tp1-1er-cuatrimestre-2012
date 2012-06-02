#include "GeneradorDeClaves.h"

GeneradorDeClaves::GeneradorDeClaves()
{

}
/**
 * Asume la lista trae los campos en el siguiente orden:
 * 1- Linea
 * 2- Franja Horaria
 * 3- Falla
 * 4- Accidente
 * 5- Formaicion
 */
void GeneradorDeClaves::generarClave(list<string> campos, Clave *clave) {

	it = campos.begin();


	//**El primer campo es una linea----
	 string nombreLineaFerroviaria = (*it);
	it++;
	//**---------------------------------



	//**El segundo campo es una franja horaria----------
	Fecha *fecha = new Fecha();
	Horario *horario =  new Horario();
	FranjaHoraria *franjaHoraria = new FranjaHoraria();


	//Separo fecha y horario
	list<string> fechaYHorario;
	string campo = *it;
	char *campoChar = new char[campo.length() + 1];
	strcpy(campoChar, campo.c_str());
	parser.parsear(campoChar, ",", fechaYHorario);

	//separo dia mes y año
	//el primer registro es la fecha
	itAux = fechaYHorario.begin();
	list<string> diaMesAnio;
	campo = *itAux;
		char *campoChar2 = new char[campo.length() + 1];
		strcpy(campoChar2, campo.c_str());
	parser.parsear(campoChar2, "/", diaMesAnio);
	itAux2 = diaMesAnio.begin();
	//Armo el campo Fecha
	int dia = atoi((*itAux2).c_str());
	itAux2++;
	int mes = atoi((*itAux2).c_str());
	itAux2++;
	int anio = atoi((*itAux2).c_str());
	fecha->setFecha(dia, mes, anio);

	//Separo los horarios
	itAux++;
	list<string> horaIniciaHoraFin;
	campo = *itAux;
		char *campoChar3 = new char[campo.length() + 1];
		strcpy(campoChar3, campo.c_str());
	parser.parsear(campoChar3, "-", horaIniciaHoraFin);
	itAux2 = horaIniciaHoraFin.begin();
	int horaInicial = atoi((*itAux2).c_str());
	itAux2++;
	int horaFinal = atoi((*itAux2).c_str());
	horario->setHorario(horaInicial, horaFinal);

	//Armo la franja Horaria
	franjaHoraria->setFecha(fecha);
	franjaHoraria->setHorario(horario);

	it++;
	//**--------------------------------------------------


	//**El tercer campo es una falla
	string descFalla = (*it);
	it++;
	//----------------------------------


	//**El cuarto campo es un accidente
		string descAccidente = (*it);
		it++;
	//----------------------------------


	//**El quinto campo es una formacion
		int formacion = atoi((*it).c_str());
	//----------------------------------------


	//Armo la clave
	clave->setAccidente(descAccidente);
	clave->setFalla(descFalla);
	clave->setFormacion(formacion);
	clave->setFranjaHoraria(franjaHoraria);
	clave->setLinea(nombreLineaFerroviaria);

	delete []campoChar;
	delete []campoChar2;
	delete []campoChar3;

}

GeneradorDeClaves::~GeneradorDeClaves()
{
}
