/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 2
//
// Fichero: Demo-Basico_VectorDinamico.cpp
//
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>

#include "VectorDinamico_basico.h"

using namespace std; 

/***************************************************************************/
/***************************************************************************/

int main (void)
{

	// ......................................................................
	// Crear un vector dinámico
	
	VectorDinamico v = CreaVectorDinamico (); 

	// Se han reservado TAM_INICIAL casillas y se están usando 0.
	

	// ......................................................................
	// Leer valores y guardarlos en el vector dinámico. 
	// El redimensionamiento se produce cuando no hay espacio para otro dato. 
	// La función "AniadeVectorDinamico" es la que se encarga del 
	// redimensionamiento cuando sea necesario.
	
	const int TAM_CAD = 20;
	char  valor[TAM_CAD];

	// Primera lectura
	cout << "Introducir un valor (FIN para finalizar): "; 
	cin.getline (valor, TAM_CAD);

	while (strcmp(valor, "FIN")) {

		int el_valor = atoi (valor); 

		// Añadir "valor". Si no cabe se redimensiona 

		AniadeVectorDinamico (v, el_valor);

		// Nueva lectura
		cout << "Introducir un valor (FIN para finalizar): "; 
		cin.getline (valor, TAM_CAD);
	}

	// ......................................................................
	// Muestra el vector

	cout << endl;
	cout << ToString (v);
	cout << endl;

	// ......................................................................
	// Reajusta y muestra el vector

	ReajustaVectorDinamico (v);

	cout << endl;
	cout << ToString (v);
	cout << endl;

	// ......................................................................
	// Liberar memoria
	
	cout << "Liberando memoria y finalizando" << endl;
	cout << endl;

	LiberaVectorDinamico (v);
	
	return 0;
}

/***************************************************************************/
/***************************************************************************/
