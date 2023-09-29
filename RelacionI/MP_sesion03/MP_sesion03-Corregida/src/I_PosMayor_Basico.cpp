/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 1
//
// En este programa se presenta una función que recibe un vector de números 
// enteros y dos valores enteros (posiciones de los extremos de un intervalo 
// sobre ese vector) y devuelve un puntero al elemento mayor.
//
// 	int * PosMayor (int *pv, int izda, int dcha);
//
// Esa función se usa en un programa que rellena aleatoriamente el un vector 
// (completamente o una parte, pero siempre desde el principio) y que calcula 
// el mayor valor entre dos posiciones dadas. 
// 
// El programa pide:
//
// 1.- el número de casillas que se van a rellenear con números aleatorios, 
// 2.- las posiciones entre las que se va a calcular el mayor valor. 
//
// Fichero: I_PosMayor_Basico.cpp
// 
/***************************************************************************/

#include <iostream>
#include <iomanip>

#include "ProcesamientoArrayInt.h"

using namespace std;

/***************************************************************************/
// Prototipos

int * PosMayor (int *pv, int izda, int dcha);

/***************************************************************************/
/***************************************************************************/

int main (void)
{
	// Valores extremos a guardar en el array
	const int MIN_ALEAT =   1;     
	const int MAX_ALEAT = 200;     	 

	// Capacidad del array
	const int TOPE = 100;     

	// 0 <= usados <= TOPE
	int usados;  

	// 0 <= izda <= dcha <= usados
	int izda;
	int dcha;
	
	//.......................................................................
	// Lectura y filtrado de los valores críticos
	
	do {
		cout << endl; 
		cout << "Num. de casillas que se van a rellenar (1 -"<< TOPE << ") = "; 
		cin >> usados;
	} while ((usados<=0) || (usados>TOPE));

	cout << "Posiciones entre las que se realiza la busqueda: " << endl; 

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

	// Fin lectura y filtrado de los valores críticos
	//.......................................................................
	
	// Vector de datos 

	int vector[TOPE];

	// Rellenar el vector con valores aleatorios entre MIN_ALEAT y MAX_ALEAT

	RellenaVector (vector, usados, MIN_ALEAT, MAX_ALEAT);
   
	MuestraVector ("Vector original: ", vector, usados, 20);
	 
	//.......................................................................
	
	// Declaración de los datos que contendrán el resultado 
	
	int *punt_al_mayor; // Dirección de memoria del mayor
	int  pos_mayor;		// Posición en el vector

	// Observe que se cumplen las precondiciones de la función PosMayor()

	punt_al_mayor = PosMayor (vector, izda, dcha); 
	pos_mayor = punt_al_mayor - vector; 

	cout << endl; 
	cout << "Solucion directa." << endl;  
	cout << "El mayor valor (posiciones " << izda << " - " 
		 << dcha << ") es " << *punt_al_mayor 
	     << " y esta en la posicion " << pos_mayor << endl;
	cout << endl; 
	cout << "................................................." << endl; 	
	cout << endl; 

	//.......................................................................
	// Otras pruebas: 
	
	int *punt_mayor_todo;
	int  pos_mayor_todo;

	if (usados==1) { // Caso trivial: el vector solo tiene un valor

		punt_mayor_todo = vector;
		pos_mayor_todo = 0;
	}
	else {		

		// Calcular el mayor de la primera mitad 
		
		int * punt_al_mayor_1 = PosMayor (vector, 0, usados/2-1); 
		int pos_mayor_1 = punt_al_mayor_1 - vector; 

		cout << "El mayor de la primera mitad (posiciones 0 - "
			 << usados/2-1 << ") es " << *punt_al_mayor_1 
		     << " y esta en la posicion " << pos_mayor_1 << endl;

		// Calcular el mayor de la segunda mitad 

		int * punt_al_mayor_2  = PosMayor (vector, usados/2, usados-1); 
		int pos_mayor_2 = punt_al_mayor_2 - vector; 

		cout << "El mayor de la segunda mitad (posiciones " 
	         << usados/2 << " - " << usados-1 << ") es " << *punt_al_mayor_2 
		     << " y esta en la posicion " << pos_mayor_2 << endl;


		// Calcular el mayor de todo el array 

		if  (*punt_al_mayor_1>*punt_al_mayor_2) {

			punt_mayor_todo = punt_al_mayor_1;
			pos_mayor_todo = punt_al_mayor_1 - vector;
		}

		else {

			punt_mayor_todo = punt_al_mayor_2;
			pos_mayor_todo = punt_al_mayor_2 - vector;

		}
	}

	cout << endl; 
	cout << "Solucion seleccionada entre las dos mitades." << endl;  
	cout << "El mayor valor del vector (posiciones 0 - " 
		 << usados-1 << ") es " << *punt_mayor_todo 
	     << " y esta en la posicion " << pos_mayor_todo << endl;
	cout << endl; 


	//.......................................................................

	return 0;
}

/***************************************************************************/
/***************************************************************************/
// Calcula el mayor elemento de un vector entre dos posiciones.
// Devuelve un puntero ese elemento.
//
// Recibe: 	pv, Dirección del primer elemento del vector.
//			izda, primera casilla de bÃºsqueda.
//			dcha, Ãºltima casilla de bÃºsqueda.
// Devuelve: la dirección de memoria del mayor nÃºmero entero, desde la 
//			dirección de memoria pv+izda hasta pv+dcha. 
// PRE: "pv" referencia a una zona de memoria reservada y las posiciones 
//			pv+izda y pv+dcha estÃ¡n dentro de esa zona reservada.

int * PosMayor (int *pv, int izda, int dcha)
{
	int *p;			// Puntero local, para desplazarnos sobre el vector
	int *fin;		// Puntero local, marca el final de la zona de bÃºsqueda

	int  mayor;     // Mayor valor 
	int *pos_mayor; // Posicion (de memoria) del mayor valor

	p   = pv+izda;  	// Primera casilla de interÃ©s
	fin = pv+dcha;  	// Ãšltima casilla de interÃ©s
	
	mayor = *p; 	// El primer elemento serÃ¡ el primer mayor   
	pos_mayor = p;  

	while (p <= fin) {
	
		if (*p > mayor) {
			mayor = *p;
			pos_mayor = p;
		}
		p++;
	}
		 
	return (pos_mayor);
}

/***************************************************************************/
/***************************************************************************/