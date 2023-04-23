/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
// 
// Fichero: main_MP_Proyecto_Fase3.cpp
//
// Función main del proyecto. 
//
// Proyecto. FASE 03. 
//
/***************************************************************************/
/***************************************************************************/

#define DEBUG_DEPARTAMENTOS
#define DEBUG_PROFESORES
#define DEBUG_ADSCRIPCIONES

/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>

#include "Fecha.h"
#include "Departamento.h"
#include "Profesor.h"
#include "Encargo.h"
#include "Adscripcion.h"

#include "utils.h"

using namespace std;


/***************************************************************************/
/***************************************************************************/

string Cabecera (const char * titulo);

/***************************************************************************/
/***************************************************************************/

int main()
{
    cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales

	int cont_departamentos = 0;
	int cont_profesores = 0;
	int cont_encargos = 0;
	int cont_adscripciones = 0;


	// Terminador para los datos leidos/escritos 
	const string TERMINADOR = "FIN";

	// Cada linea del fichero se lee en un dato string. 
	string linea;


	//......................................................................
	// DEPARTAMENTOS

	cout << Cabecera ("DEPARTAMENTOS:");

	getline(cin, linea); // Lectura adelantada

	while (linea != TERMINADOR) {
		
		cont_departamentos++; // Un departamento más (no se leyó TERMINADOR)	
			

		Departamento un_departamento (linea);

		cout << "Leido: " << un_departamento.ToString() << endl; 


		#ifdef DEBUG_DEPARTAMENTOS

		Departamento tmp; 
		cout << "TMP (VACIO): " << tmp.ToString() << endl; 

		Departamento copia = un_departamento;
		cout << "CONST.COPIA: " << copia.ToString() << endl; 

		tmp = un_departamento;
		cout << "TMP (ASIG) : " << tmp.ToString() << endl; 
		
		#endif


		// Leer la siguiente linea 
		getline(cin, linea); 
		
	} // while (linea != TERMINADOR)
	

	cout << "Total Departamentos = "<< setw(3) << cont_departamentos << endl; 
	cout << endl; 



	//......................................................................
	// PROFESORES

	
	cout << Cabecera ("PROFESORES:");

	getline(cin, linea); // Lectura adelantada

	while (linea != TERMINADOR) {
		
		cont_profesores++; // Un profesor más (no se leyó TERMINADOR)	
			

		Profesor un_profesor (linea);

		cout << "Leido: " << un_profesor.ToString() << endl; 



		#ifdef DEBUG_PROFESORES

		Profesor tmp; 
		cout << "TMP (VACIO): " << tmp.ToString() << endl; 

		Profesor copia = un_profesor;
		cout << "CONST.COPIA: " << copia.ToString() << endl; 

		tmp = un_profesor;
		cout << "TMP (ASIG) : " << tmp.ToString() << endl; 
		
		#endif


		// Leer la siguiente linea 
		getline(cin, linea); 
		
	} // while (linea != TERMINADOR)
	

	cout << "Total Profesores = "<< setw(3) << cont_profesores << endl; 
	cout << endl; 



	//......................................................................
	// CATEGORIAS
	 

	cout << Cabecera ("ENCARGOS:");

	getline(cin, linea); // Lectura adelantada

	while (linea != TERMINADOR) {
		
		cont_encargos++; // Un encargo más (no se leyó TERMINADOR)	
			

		Encargo un_encargo (linea);

		cout << "Leido: " << un_encargo.ToString() << endl; 


		// Leer la siguiente linea 
		getline(cin, linea); 
		
	} // while (linea != TERMINADOR)
	

	cout << "Total Encargos = "<< setw(3) << cont_encargos << endl; 
	cout << endl; 
	


	//......................................................................
	// ADSCRIPCIONES
	  

	cout << Cabecera ("ADSCRIPCION DE PROFESORES A DEPARTAMENTOS:");

	getline(cin, linea); // Lectura adelantada

	while (linea != TERMINADOR) {
		
		cont_adscripciones++; // Una adscripción más (no se leyó TERMINADOR)	


		Adscripcion una_adscripcion (linea);

		cout << "Leido: " << una_adscripcion.ToString() << endl; 


		#ifdef DEBUG_ADSCRIPCIONES

		Adscripcion tmp; 
		cout << "TMP (VACIO): " << tmp.ToString() << endl; 
		
		Adscripcion copia = una_adscripcion;
		cout << "CONST.COPIA: " << copia.ToString() << endl; 

		tmp = una_adscripcion;
		cout << "TMP (ASIG) : " << tmp.ToString() << endl; 
		
		#endif


		// Leer la siguiente linea 
		getline(cin, linea); 
		
	} // while (linea != TERMINADOR)
	

	cout << "Total Adscripciones = "<< setw(3) << cont_adscripciones << endl; 
	cout << endl; 


	return 0;
}

/***************************************************************************/
/***************************************************************************/

string Cabecera (const char * titulo)
{
	const int TAM_GUIONES = 70; 
	char guiones[TAM_GUIONES]; 

	memset (guiones, '-', TAM_GUIONES-1); 
	guiones[TAM_GUIONES-1] = '\0'; 

	string cad_guiones (guiones); 

	string cad;

	cad = cad + cad_guiones + "\n";
	cad = cad + titulo + "\n";
	cad = cad + cad_guiones + "\n";

	return cad; 
}

/***************************************************************************/
/***************************************************************************/
