/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// Ejercicio preparatorio de lectira de cadenas (clásicas). 
//
// Lee un número indeterminado de cadenas, guardándolas en una cadena 
// clásica. El final de la lectura lo determina EOF. 
//
// Fichero: LeeCadenas_clasica.cpp 
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

/***************************************************************************/
/***************************************************************************/

int main (void)
{
	// LECTURA CON CADENA CLASICA
	
	int cont_lineas_clas = 0;
	
	const int MAX_CAD = 100;
	char cadena_clas[MAX_CAD];

	while (cin.getline(cadena_clas, MAX_CAD)) {

		cont_lineas_clas++; // Actualizar el contador

		cout << "----> cadena " << setw (3) << cont_lineas_clas 
		     << " = |"  << cadena_clas << "|" 
		     << " Longitud = " << strlen(cadena_clas) << endl;
	} // while

	cout << endl; 
	cout << "Total lineas leidas = " << setw(3) << cont_lineas_clas << endl; 	
	cout << endl; 

	return (0);
}

/***************************************************************************/
/***************************************************************************/
