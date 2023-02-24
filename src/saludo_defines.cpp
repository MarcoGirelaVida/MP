/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// Fichero: saludo_defines.cpp
//
/***************************************************************************/

#include <iostream>
using namespace std; 

//#define INGLES
#define ESPANIOL

int main (void) {

	#ifdef INGLES
	cout << "Hello, world!" << endl;
	#endif

	#ifdef ESPANIOL
	cout << "¡hola, mundo!" << endl;
	#endif

	return 0; 
}
