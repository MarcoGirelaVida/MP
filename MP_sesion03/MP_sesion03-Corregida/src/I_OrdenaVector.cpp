/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 1
//
// En este programa se ordena un vector usando los algoritmos clásicos.
// 
// El programa pide:
//
// 1.- el número de casillas que se van a rellenear con números aleatorios, 
// 2.- las posiciones entre las que se va a ordenar el vector. 
//
// Fichero: I_OrdenaVector.cpp
// 
/***************************************************************************/

#include <iostream>
#include <iomanip>

#include "ProcesamientoArrayInt.h"

using namespace std;

/***************************************************************************/
/***************************************************************************/

int main (void)
{

	// Valores extremos a guardar en el array
	const int MIN_ALEAT =   1;     
	const int MAX_ALEAT = 200;     

	// Capacidad del array
	const int TOPE = 100;     

	int usados; // 0 <= usados <= TOPE
	int izda; 	
	int dcha;   // 0 <= izda <= dcha <= usados
	
	//.......................................................................
	// Lectura y filtrado de los valores críticos
	
	do {
		cout << endl; 
		cout << "Num. de casillas que se van a rellenar (1 -" << TOPE << ") = "; 
		cin >> usados;
	} while ((usados<=0) || (usados>TOPE));


	cout << "Posiciones entre las que se realiza la ordenacion: " << endl; 

	do {
		cout << "Primera posicion (0 - " << usados-1 << ") = "; 
		cin >> izda;
	} while ((izda<0) || (izda>=usados));

	do {
		cout << "Segunda posicion (0 - " << usados-1 << ") = "; 
		cin >> dcha;
	} while ((dcha<0) || (dcha>=usados));


	// Ajuste de las posiciones 
	
	if (izda>dcha) Intercambia (&izda, &dcha);

	cout << endl; 
	cout << "Se va a crear un array de " << usados << " datos." << endl;
	cout << "Se va aprocesar entre posiciones "<< izda << " y "<< dcha << endl; 
	cout << endl; 


	//.......................................................................
	// Vector de datos: se rellenará con valores aleatorios  
	
	int vector[TOPE];

	// Rellenar el vector con valores aleatorios entre MIN_ALEAT y MAX_ALEAT

	RellenaVector (vector, usados, MIN_ALEAT, MAX_ALEAT);
	
	MuestraVector ("Vector original: ", vector, usados, 20);
	 
	 
	//.......................................................................
	// Copias del vector de datos 

	int vector1[TOPE];
	int vector2[TOPE];
	int vector3[TOPE];

	for (int i=0; i<usados; i++) 
		vector1[i] = vector2[i] = vector3[i] = vector[i];


	//.......................................................................
	// Ordenar vector y mostrar resultado

	cout << "ORDENACION POR SELECCION" << endl; 
	cout << "------------------------" << endl; 	
	OrdenaSeleccion (vector1, izda, dcha);  
	MuestraVector ("Vector ordenado: ", vector1, usados, 20);

	cout << "ORDENACION POR INSERCION" << endl; 
	cout << "------------------------" << endl; 	
	OrdenaInsercion (vector2, izda, dcha);  
	MuestraVector ("Vector ordenado: ", vector2, usados, 20);

	cout << "ORDENACION POR INTERCAMBIO" << endl; 
	cout << "--------------------------" << endl; 	
	OrdenaIntercambio (vector3, izda, dcha);  
	MuestraVector ("Vector ordenado: ", vector3, usados, 20);

	//.......................................................................

	return 0;
}

/***************************************************************************/
/***************************************************************************/