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

int main (int argc, char **argv)
{
    cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales


	if (argc != 2) {

		cerr << "Error: Formato incorrecto." << endl;
		cerr << "Uso: " << argv[0] << "<tipo_prueba>" << endl;
		cerr << endl; 
		exit(1);
	}

	int tipo_prueba = atoi(argv[1]); 

	if (tipo_prueba < 1 || tipo_prueba > 4) {

		cerr << "Error: tipo de prueba incorrecto ." << endl;
		cerr << "   0 <= " << tipo_prueba << " <= 4" << endl; 
		cerr << endl; 
		exit(2);
	}

	switch (tipo_prueba) {

		case (1) : {
			
			//................................................................
			// DEPARTAMENTOS

			// Crear vector dinámico de objetos "Departamento" (vacío). 
			VectorDepartamento departamentos; 

			// Lectura del vector completo 
		 	cin >> departamentos; 

			cout << endl; 
			cout << Cabecera ("DEPARTAMENTOS:");
			cout << endl; 
			cout << "Capacidad = " << setw(3) 
			     << departamentos.Capacidad() << ". ";
			cout << "Totalutilizados = " << setw(3) <<  departamentos.Totalutilizados() << endl;
			cout << departamentos.ToString() << endl;
			cout << endl; 

			cout << endl; 
			cout << "Ejecutando cout << departamentos" << endl; 
			cout << endl; 
			cout << departamentos << endl; 
			cout << endl; 

			break; 
		}

		case (2) : {

			//................................................................
			// PROFESORES

			// Crear vector dinámico de objetos "Profesor" (vacío). 
			VectorProfesor profesores; 

			// Lectura del vector completo 
			cin >> profesores;

			cout << endl; 
			cout << Cabecera ("PROFESORES:");
			cout << endl; 
			cout << "Capacidad = " << setw(3) 
			     << profesores.Capacidad() << ". ";
			cout << "Totalutilizados = " << setw(3) <<  profesores.Totalutilizados() << endl;
			cout << profesores.ToString() << endl;
			cout << endl; 

			cout << endl; 
			cout << "Ejecutando cout << profesores" << endl; 
			cout << endl; 
			cout << profesores << endl; 
			cout << endl; 

			break; 
		}

		case (3) : {

			//................................................................
			// ENCARGOS

			// Crear vector dinámico de objetos "Encargo" (vacío). 
			VectorEncargo encargos; 

			// Lectura del vector completo 
		 	cin >> encargos; 

			cout << endl; 
			cout << Cabecera ("ENCARGOS:");
			cout << endl; 
			cout << "Capacidad = " << setw(3) 
			     << encargos.Capacidad() << ". ";
			cout << "Totalutilizados = " << setw(3) <<  encargos.Totalutilizados() << endl;
			cout << encargos.ToString() << endl;
			cout << endl; 

			cout << endl; 
			cout << "Ejecutando cout << encargos" << endl; 
			cout << endl; 
			cout << encargos << endl; 
			cout << endl; 

			break; 

		}

		case (4) : {

			//................................................................
			// ADSCRIPCIONES

			// Crear vector dinámico de objetos "Adscripcion" (vacío). 
			VectorAdscripcion adscripciones; 

			// Lectura del vector completo 
		 	cin >> adscripciones; 

			cout << endl; 
			cout << Cabecera ("ADSCRIPCIONES:");
			cout << endl; 
			cout << "Capacidad = " << setw(3) 
			     << adscripciones.Capacidad() << ". ";
			cout << "Totalutilizados = " << setw(3) <<  adscripciones.Totalutilizados() << endl;
			cout << adscripciones.ToString() << endl;
			cout << endl; 

			cout << endl; 
			cout << "Ejecutando cout << adscripciones" << endl; 
			cout << endl; 
			cout << adscripciones << endl; 
			cout << endl; 

			break; 
		}
	}

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
