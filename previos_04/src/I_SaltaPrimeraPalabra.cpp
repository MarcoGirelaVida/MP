/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 1
//
// Programa sencillo que trabaja sobre una cadena de caracteres ``clásica''. 
// Lee  una cadena y la imprime saltándose la primera palabra y evitando 
// escribirla carácter a carácter.
// El programa tiene en cuenta que puede haber ninguna, una o más palabras.  
// Si hay más de una palabra, están separadas por caracteres separadores.
//
// Fichero: I_SaltaPrimeraPalabra.cpp
//
/***************************************************************************/
/***************************************************************************/
 
#include <iostream>
#include <cctype>
using namespace std;

/***************************************************************************/
/***************************************************************************/

int main(void)
{
	const int TOPE = 100; 
	char cad[TOPE];

	cout << "Introduzca una cadena: ";
	cin.getline(cad, TOPE);
	
	char * p = cad; // Apuntar al primer carácter
	
	// Saltar los separadores iniciales --> inicio de una palabra
	while (isspace(*p) && (*p != '\0')) p++;
	
	if (*p) {
		
		// Buscar el siguiente separador --> saltar la primera palabra
		while (!isspace(*p) && (*p != '\0')) p++;
	
		// Saltar separadores --> inicio de la segunda palabra
		while (isspace(*p) && (*p != '\0')) p++;
	
		if (*p != '\0')  cout << p;
		else cout << "SOLO HAY UNA PALABRA";
	}
	
	else cout << "NO HAY PALABRAS";
	
	cout << endl;

	return 0;
}

/***************************************************************************/
/***************************************************************************/