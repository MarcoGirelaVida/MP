/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 1
//
// Este programa rellena aleatoriamente dos vectores de enteros, los ordena 
// y los mezcla. 
// 
// El programa pide el número de casillas que se van a rellenar con números 
// aleatorios (cada vector por separado). 
//
// Fichero: I_OrdenayMezclaVectores.cpp
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

	// Capacidad de los array
	const int TOPE = 100;     

	int usados_v1; // 0 <= usados_v1 <= TOPE
	int usados_v2; // 0 <= usados_v2 <= TOPE
	int usados_v3; // 0 <= usados_v2 <= 2*TOPE

	
	//.......................................................................
	// Lectura y filtrado de los valores críticos
	
	do {
		cout << endl; 
		cout << "Primer vector--> Num. de casillas que se van a rellenar ";
		cout << "(1 -" << TOPE << ") = "; 
		cin >> usados_v1;
	} while ((usados_v1<=0) || (usados_v1>TOPE));

	do {
		cout << endl; 
		cout << "Segundo vector--> Num. de casillas que se van a rellenar ";
		cout << "(1 -" << TOPE << ") = "; 
		cin >> usados_v2;
	} while ((usados_v2<=0) || (usados_v2>TOPE));


	//.......................................................................
	// Vectores de datos: se rellenará con valores aleatorios 

	int v1[TOPE]; 
	int v2[TOPE];

	int v3[2*TOPE]; // Vector resultado: contendrá la mezcla de v1 y v2

	// Rellenar los vectores v1 y v2 con valores aleatorios entre MIN_ALEAT 
	// y MAX_ALEAT

	RellenaVector (v1, usados_v1, MIN_ALEAT, MAX_ALEAT);
	MuestraVector ("Vector 1: ", v1, usados_v1, 20);
 
  	RellenaVector (v2, usados_v2, MIN_ALEAT, MAX_ALEAT);   
	MuestraVector ("Vector 2: ", v2, usados_v2, 20);


	//.......................................................................
	// Ordenar vectores y mostrarlos 

	OrdenaSeleccion (v1, usados_v1);  
	MuestraVector ("v1 ordenado: ", v1, usados_v1, 20);
	
	OrdenaIntercambio (v2, usados_v2);  
	MuestraVector ("v2 ordenado: ", v2, usados_v2, 20);

    MezclaVectoresSimple (v3, v1, usados_v1, v2, usados_v2); 
	usados_v3 = usados_v1 + usados_v2;
	

	//.......................................................................
	// Mostrar resultado 

	MuestraVector ("v3 (mezcla de v1 y v2): ", v3, usados_v3, 20);

	//.......................................................................

	return 0;
}

/***************************************************************************/
/***************************************************************************/