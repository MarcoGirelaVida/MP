/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
// 
// Fichero: main_MP_Proyecto_Fase2.cpp
//
// Función main del proyecto. 
//
// Proyecto. FASE 02. 
//
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

	// DEPARTAMENTOS

	cout << Cabecera ("DEPARTAMENTOS:");

	getline(cin, linea); // Lectura adelantada

	while (linea != TERMINADOR) {
		
		cont_departamentos++; // Un departamento más (no se leyó TERMINADOR)	
			
		Departamento un_departamento (linea);

		cout << un_departamento.ToString() << endl; 

		Departamento copia_un_departamento;
		
		cout << "DEPARTAMENTO VACIO: " << copia_un_departamento.ToString() << endl; 

		copia_un_departamento.Clona (un_departamento);
		cout << "Clonado: " << copia_un_departamento.ToString() << endl; 


		// Leer la siguiente linea 
		getline(cin, linea); 
		
	} // while (linea != TERMINADOR)
	

	cout << "Total Departamentos = "<< setw(3) << cont_departamentos << endl; 
	cout << endl; 


	// PROFESORES
	 
	cout << Cabecera ("PROFESORES:");

	getline(cin, linea); // Lectura adelantada

	while (linea != TERMINADOR) {
		
		cont_profesores++; // Un profesor más (no se leyó TERMINADOR)	
			
		Profesor un_profesor (linea);

		cout << un_profesor.ToString(true) << endl; 

		Profesor copia_un_profesor;

		cout << "PROFESOR VACIO: " << copia_un_profesor.ToString() << endl; 

		copia_un_profesor.Clona (un_profesor);
		cout << "Clonado: " << copia_un_profesor.ToString() << endl; 
		
		// Leer la siguiente linea 
		getline(cin, linea); 
		
	} // while (linea != TERMINADOR)
	

	cout << "Total Profesores = "<< setw(3) << cont_profesores << endl; 
	cout << endl; 


	// CATEGORIAS
	 
	cout << Cabecera ("ENCARGOS:");

	getline(cin, linea); // Lectura adelantada

	while (linea != TERMINADOR) {
		
		cont_encargos++; // Un encargo más (no se leyó TERMINADOR)	
			
		Encargo un_encargo (linea);

		cout << un_encargo.ToString() << endl; 

		// Leer la siguiente linea 
		getline(cin, linea); 
		
	} // while (linea != TERMINADOR)
	

	cout << "Total Encargos = "<< setw(3) << cont_encargos << endl; 
	cout << endl; 
	

	// ADSCRIPCIONES
	 
	cout << Cabecera ("ADSCRIPCION DE PROFESORES A DEPARTAMENTOS:");

	getline(cin, linea); // Lectura adelantada

	while (linea != TERMINADOR) {
		
		cont_adscripciones++; // Una adscripción más (no se leyó TERMINADOR)	
			
		Adscripcion una_adscripcion (linea);

		cout << una_adscripcion.ToString() << endl; 

		Adscripcion copia_una_adscripcion;

		cout << "ADSCRIPCION VACIO: " << copia_una_adscripcion.ToString() << endl; 

		copia_una_adscripcion.Clona (una_adscripcion);
		cout << "Clonado: " << copia_una_adscripcion.ToString() << endl; 


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
