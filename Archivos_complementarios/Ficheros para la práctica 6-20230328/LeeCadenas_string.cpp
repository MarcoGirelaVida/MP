/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// Ejercicio preparatorio de lectira de cadenas (string). 
//
// Lee un número indeterminado de cadenas, guardándolas en un objeto string. 
// El final de la lectura lo determina EOF. 
//
// Fichero: LeeCadenas_string.cpp 
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/***************************************************************************/
/***************************************************************************/

int main (void)
{
	// LECTURA CON STRING
	
	int cont_lineas_str = 0;
	
	string cadena_str;

	while (getline (cin, cadena_str)) {

		cont_lineas_str++; // Actualizar el contador

		cout << "----> cadena " << setw (3) << cont_lineas_str 
		     << " = |"  << cadena_str << "|" 
		     << " Longitud = " << cadena_str.length() << endl;
	} // while

	cout << endl; 
	cout << "Total lineas leidas = " << setw(3) << cont_lineas_str << endl; 	
	cout << endl; 

	return (0);
}

/***************************************************************************/
/***************************************************************************/
