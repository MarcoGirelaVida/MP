/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 3
//
// Examen ordinario 2017/2018 (1)
//
// Fichero: III_Demo-Metropolitano.cpp
//
/***************************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

#include "InfoParada.h"
#include "Linea.h"
#include "RedMetro.h"

using namespace std; 

/***************************************************************************/
/***************************************************************************/

int main (void)
{

	RedMetro red1; // La red está inicialmente vacía

	red1.FromText(); // Se lee la red de cin


	cout << endl;
	cout << "-------------------------------" << endl;
	cout << endl;

	MuestraRed ("Red: red1", red1);
	cout << "\tPuntuacion: " << red1.ValorCalidad() << endl;
	cout << endl;


	cout << endl;
	cout << "-------------------------------" << endl;
	cout << endl;


	cout << endl;
	cout << "-------------------------------" << endl;
	cout << endl;

	cout << "Informacion sobre la operatividad de la red" << endl;
	cout << endl;

	for (int l=1; l<=red1.GetNumLineas(); l++) {

		cout << "\tLinea " << setw(3) << l << ": ";

		Linea linea_l = red1.GetLinea (l); 

 		if (linea_l.EstaTotalmenteOperativa()) 
			cout << "totalmente operativa." << endl; 
		else 
			cout << "tiene paradas no operativas." << endl; 
 
	}

	cout << endl;
	cout << "-------------------------------" << endl;
	cout << endl;


	cout << "Parada mejor conectada de la red" << endl;
	cout << endl;

	cout << "\tEl indice de la parada mejor conectada es: " 
         << red1.MejorConectada() << endl;

	cout << endl;
	cout << "-------------------------------" << endl;


	cout << "Serializando red:" << endl << endl;

	cout << red1.ToString() << endl;	
	cout << endl;


	return (0);
}

/***************************************************************************/
/***************************************************************************/
