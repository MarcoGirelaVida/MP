/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 1
//
// En este programa se presenta una funci�n que recibe un vector de n�meros 
// enteros y dos valores enteros (posiciones de los extremos de un intervalo 
// sobre ese vector) y devuelve un puntero al elemento mayor.
//
// 	int * PosMayor (int *pv, int izda, int dcha);
//
// Esa funci�n se usa en un programa que recibe argumentos de la l�nea de 
// �rdenes, e inicializa un vector de manera aleatoria. 
//
// Fichero: I_PosMayor.cpp
// 
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>

#include "ProcesamientoArrayInt.h"

using namespace std;

/***************************************************************************/
// Prototipos

int * PosMayor (int *pv, int izda, int dcha);
int * PosMayor (int *pv, int num_datos);

/***************************************************************************/
/***************************************************************************/

int main (int argc, char **argv)
{
	// Capacidad del array
	const int TOPE = 100; 

	// Valores aleatorios
	const int MIN_ALEAT = 1;
	const int MAX_ALEAT = 200;

	// NUmeros de valores que se muestran en cada linea
	const int NUM_DATOS_LINEA = 20; 

	//.......................................................................
	// Comprobaci�n argumentos 

	if (argc>4) {
		cerr << "Error: demasiados argumentos" << endl;
		cerr << "Uso: " << argv[0] << " [num_datos] [pos_izda] [pos_dcha]";
		cerr << endl << endl;
		exit(1);
	}
	
	// Valores por defecto

	int usados = TOPE;
	int izda = 0;
	int dcha = TOPE-1;

	// Otros valores 

	if (argc > 1) { // Al menos 1 arg. real

		usados = atoi(argv[1]); // actualizar "usados" con argv[1] 
		dcha = usados-1;        // actualizar "dcha".

		if (argc > 2) { // Al menos 2 args. reales

			dcha = atoi(argv[2]); // actualizar "dcha" con argv[2]. 
								  // "izda" es 0 (valor por defecto)
	
			if (argc > 3) {	// 3 args. reales
				izda = atoi(argv[2]); // actualizar "izda" y "dcha"
				dcha = atoi(argv[3]); // con argv[2] y argv[3]
			}
		}
	}

	// Comprobar la validez de "usados"
	if (usados <= 0 || usados > TOPE)  {
		cerr << "Error: numero de casillas (" << usados << ") incorrecto. "; 
		cerr << "Debe ser 0 < casillas <= " << TOPE << endl << endl;
		exit(2);
	}
	// Comprobar la validez de "izda"
	if (izda < 0 || izda >= usados)  {
		cerr << "Error: extremo izquierdo (" << izda << ") incorrecto. "; 
		cerr << "Debe ser 0 <= izda < " << usados << endl << endl;
		exit(3);
	}
	// Comprobar la validez de "dcha"
	if (dcha < 0 || dcha >= usados)  {
		cerr << "Error: extremo derecho (" << dcha << ") incorrecto. "; 
		cerr << "Debe ser 0 <= dcha < " << usados << endl << endl;
		exit(3);
	}
	// Forzar a que izda<=dcha
	if (izda > dcha)  {
		Intercambia (&izda, &dcha);
	}

	cout << endl; 
	cout << "Se va a crear un array de " << usados << " datos." << endl;
	cout << "Se va aprocesar entre posiciones "<< izda << " y "<< dcha << endl; 
	cout << endl; 

	// Fin comprobaci�n argumentos
	//.......................................................................
	
	// Vector de datos 

	int vector[TOPE];
	
	// Iniciar el vector aleatoriamente y mostralo

	RellenaVector (vector, usados, MIN_ALEAT, MAX_ALEAT);
	MuestraVector ("Vector original: ", vector, usados, NUM_DATOS_LINEA);
	 
	//.......................................................................
	
	// Declaraci�n de los datos que contendr�n el resultado 
	
	int *punt_al_mayor; // Direcci�n de memoria del mayor valor
	int  pos_mayor;		// Posici�n en el vector

	// Observe que se cumplen las precondiciones de la funci�n PosMayor()

	punt_al_mayor = PosMayor (vector, izda, dcha); 
	pos_mayor = punt_al_mayor - vector; 

	cout << endl; 
	cout << "El mayor valor (posiciones " << izda << " - " 
		 << dcha << ") es " << *punt_al_mayor << endl;
	cout << "Esta en la posicion " << pos_mayor << endl;
	cout << endl; 


	punt_al_mayor = PosMayor (vector+izda, dcha-izda+1); 
	pos_mayor = punt_al_mayor - vector; 

	cout << endl; 
	cout << "El mayor valor (posiciones " << izda << " - " 
		 << dcha << ") es " << *punt_al_mayor << endl;
	cout << "Esta en la posicion " << pos_mayor << endl;
	cout << endl; 


	punt_al_mayor = PosMayor (vector, usados); 
	pos_mayor = punt_al_mayor - vector; 

	cout << endl; 
	cout << "El mayor valor del vector es " << *punt_al_mayor << endl;
	cout << "Esta en la posicion " << pos_mayor << endl;
	cout << endl; 

	return 0;
}


/***************************************************************************/
/***************************************************************************/
// Calcula el mayor elemento de un vector dada la direcci�n de memoria 
// inicial del vector y las posiciones (�ndices)  entre las que buscar.
// Devuelve un puntero ese elemento.
//
// Par�metros: 	
//			pv, Direcci�n del primer elemento del vector.
//			izda, primera casilla de b�squeda.
//			dcha, �ltima casilla de b�squeda.
// Devuelve: la direcci�n de memoria del mayor n�mero entero, desde la 
//			direcci�n de memoria pv+izda hasta pv+dcha. 
// PRE: "pv" referencia a una zona de memoria reservada y las posiciones 
//			pv+izda y pv+dcha est�n dentro de esa zona reservada.

int * PosMayor (int *pv, int izda, int dcha)
{
	return (PosMayor (pv+izda, dcha-izda+1));
}

/***************************************************************************/
/***************************************************************************/
// Calcula el mayor elemento de un vector dada una direcci�n de memoria 
// y el n�mero de casillas a explorar a partir de ella. 
// Devuelve un puntero ese elemento.
//
// Par�metros: 	
//			pv, Direcci�n del primer elemento del vector.
//			num_datos, n�mero de casillas para la b�asqueda.
// Devuelve: la direcci�n de memoria del mayor n�mero entero, desde la 
//			direcci�n de memoria pv. 
// PRE: "pv" referencia a una zona de memoria reservada 
//		num_datos > 0

int * PosMayor (int *pv, int num_datos)
{
	int *p;			// Puntero local, para desplazarnos sobre el vector
	int *fin;		// Puntero local, marca el final de la zona de b�squeda
	int *pos_mayor; // Posicion (de memoria) del mayor valor

	fin = pv+num_datos; // �ltima casilla de inter�s
	pos_mayor = pv; 	// El primer elemento ser� el primer mayor   
	p = pv+1;  // Primera casilla para la comparaci�n (siguiente a "pv")

	while (p < fin) {
	
		if (*p > *pos_mayor) 
			pos_mayor = p;
		
		p++;
	}
		 
	return (pos_mayor);
}
/***************************************************************************/
/***************************************************************************/
