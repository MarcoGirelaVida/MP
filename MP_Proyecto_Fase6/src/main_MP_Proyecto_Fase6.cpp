/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
// 
// Fichero: main_MP_Proyecto_Fase6.cpp
//
// Función main del proyecto. 
//
// Proyecto. FASE 06. 
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

#include "VectorDepartamento.h"
#include "VectorProfesor.h"
#include "VectorEncargo.h"
#include "VectorAdscripcion.h"

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


	//................................................................
	// DEPARTAMENTOS

	VectorDepartamento departamentos ("./datos/departamentos.txt");

	cout << endl; 
	cout << Cabecera ("DEPARTAMENTOS:");
	cout << endl; 	
	cout << departamentos.ToString() << endl;
	cout << endl; 

	departamentos.GuardarVectorDepartamento ("./datos/copia_departamentos.txt");

	VectorDepartamento copia_departamentos ("./datos/copia_departamentos.txt");

	cout << endl; 
	cout << Cabecera ("COPIA DEPARTAMENTOS:");
	cout << endl; 	
	cout << copia_departamentos.ToString() << endl;
	cout << endl; 

	Departamento dep ("ABCD", "Nuevo Departamento");
	departamentos += dep; 

	cout << endl; 
	cout << Cabecera ("DEPARTAMENTOS TRAS ADICION");
	cout << endl; 	
	cout << departamentos.ToString() << endl;
	cout << endl; 

	departamentos.RecuperarVectorDepartamento("./datos/departamentos.txt");

	cout << endl; 
	cout << Cabecera ("DEPARTAMENTOS ORIGINAL");
	cout << endl; 	
	cout << departamentos.ToString() << endl;
	cout << endl; 


	//................................................................
	// PROFESORES

	VectorProfesor profesores ("./datos/profesores.txt");

	cout << endl; 
	cout << Cabecera ("PROFESORES:");
	cout << endl; 	
	cout << profesores.ToString() << endl;
	cout << endl; 

	profesores.GuardarVectorProfesor ("./datos/copia_profesores.txt");

	VectorProfesor copia_profesores ("./datos/copia_profesores.txt");

	cout << endl; 
	cout << Cabecera ("COPIA PROFESORES:");
	cout << endl; 	
	cout << copia_profesores.ToString() << endl;
	cout << endl; 

	Profesor prof ("xxxxxxxxx", "Nombre", "Apellidos");
	profesores += prof; 

	cout << endl; 
	cout << Cabecera ("PROFESORES TRAS ADICION");
	cout << endl; 	
	cout << profesores.ToString() << endl;
	cout << endl; 

	profesores.RecuperarVectorProfesor("./datos/profesores.txt");

	cout << endl; 
	cout << Cabecera ("PROFESORES ORIGINAL");
	cout << endl; 	
	cout << profesores.ToString() << endl;
	cout << endl; 


	//................................................................
	// ENCARGOS

	VectorEncargo encargos ("./datos/encargos.txt");

	cout << endl; 
	cout << Cabecera ("ENCARGOS:");
	cout << endl; 	
	cout << encargos.ToString() << endl;
	cout << endl; 

	encargos.GuardarVectorEncargo ("./datos/copia_encargos.txt");

	VectorEncargo copia_encargos ("./datos/copia_encargos.txt");

	cout << endl; 
	cout << Cabecera ("COPIA ENCARGOS:");
	cout << endl; 	
	cout << copia_encargos.ToString() << endl;
	cout << endl; 

	Encargo encargo (0, 0.0);
	encargos += encargo; 

	cout << endl; 
	cout << Cabecera ("ENCARGOS TRAS ADICION");
	cout << endl; 	
	cout << encargos.ToString() << endl;
	cout << endl; 

	encargos.RecuperarVectorEncargo ("./datos/encargos.txt");

	cout << endl; 
	cout << Cabecera ("ENCARGOS ORIGINAL");
	cout << endl; 	
	cout << encargos.ToString() << endl;
	cout << endl; 

	
	//................................................................
	// ADSCRIPCIONES

	VectorAdscripcion adscripciones ("./datos/adscripciones.txt");

	cout << endl; 
	cout << Cabecera ("ADSCRIPCIONES:");
	cout << endl; 	
	cout << adscripciones.ToString() << endl;
	cout << endl; 

	adscripciones.GuardarVectorAdscripcion ("./datos/copia_adscripciones.txt");

	VectorAdscripcion copia_adscripciones ("./datos/copia_adscripciones.txt");

	cout << endl; 
	cout << Cabecera ("COPIA ADSCRIPCIONES:");
	cout << endl; 	
	cout << copia_adscripciones.ToString() << endl;
	cout << endl; 

	Adscripcion adscripcion ("xxxxxxxxx", "WXYZ");
	adscripciones += adscripcion; 

	cout << endl; 
	cout << Cabecera ("ADSCRIPCIONES TRAS ADICION");
	cout << endl; 	
	cout << adscripciones.ToString() << endl;
	cout << endl; 

	adscripciones.RecuperarVectorAdscripcion ("./datos/adscripciones.txt");

	cout << endl; 
	cout << Cabecera ("ADSCRIPCIONES ORIGINAL");
	cout << endl; 	
	cout << adscripciones.ToString() << endl;
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
