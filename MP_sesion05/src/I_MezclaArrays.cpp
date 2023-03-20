/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// AUTOR: MARCO GIRELA VIDA
// GRUPO: 1ºB
// FECHA: 20/03/2023
//
// RELACION DE PROBLEMAS 1
//
// Se crean y rellenan aleatoriamente dos vectores de acuerdo a unos
// parámetros dados por el usuario, posteriormente se ordenan y
// por último se crea un vector mezcla donde se guardan aquellos valores
// únicos de v1 o v2.
// 
// Fichero: I_MezclaArrays.cpp
//
/***************************************************************************/
/***************************************************************************/

#include "ProcesamientoArrayInt.h"
#include "GeneradorAleatorioEnteros.h"
#include <iostream>

using namespace std;

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

int main(int argc, char **argv)
{
	const int TOPE = 100;			// Num. de casillas del vector 
	int v1[TOPE];
    int v2[TOPE];

	const int MIN_ALEAT = 0;    // Mínimo valor aleatorio permitido
	const int MAX_ALEAT = 200;	// Máximo valor aleatorio permitido

	// Numeros de valores que se muestran en cada linea
	const int NUM_DATOS_LINEA = 20; 

	/***************************************************************************/
	/***************************************************************************/
	// Comprobación argumentos 

	if (argc>4) {
		cerr << "Error: demasiados argumentos" << endl << endl;
		exit(1);
	}
	
	// Valores por defecto
	// Observe que no he hecho un "util_v1 y 2" debido a que 
	// ambos van y deben usar el mismo tamaño (usados)
	int usados = TOPE;
	int min_aleat = MIN_ALEAT;
	int max_aleat = MAX_ALEAT;


	// Otros valores 

	if (argc > 1) {

		usados = atoi(argv[1]); // "usados" será argv[1] 
	
		if (argc > 2) {

			max_aleat = atoi(argv[2]); // actualizar "max_aleat". 
									   // "min_aleat" es MIN_ALEAT
			if (argc > 3) {	

				max_aleat = atoi(argv[2]); // actualizar "max_aleat" y 
				min_aleat = atoi(argv[3]); // "min_aleat"

				// Intercambiar los valores de "max_aleat" y "min_aleat"
				// si fuera necesario

				if (min_aleat > max_aleat) 
					Intercambia(&min_aleat, &max_aleat);
			}
		}
	}

	// Comprobar la validez de "usados"
	if (usados <= 0 || usados > TOPE)  {
		cerr << "Error: numero de casillas (" << usados << ") incorrecto. "; 
		cerr << "Debe ser 0 < casillas <= " << TOPE << endl << endl;
		exit(2);
	}

	cout << endl; 
	cout << "Se va a crear un array de " << usados << " datos." << endl;
	cout << "Los datos estarán comprendidos entre "<< min_aleat << " y " 
         << max_aleat << " (incluidos)" << endl; 
	cout << endl; 

	// Fin comprobación argumentos
	/***************************************************************************/
	/***************************************************************************/

	// PROCESAMIENTO: Rellenar los vectores con numeros aleatorios 
	RellenaVector (v1, usados, min_aleat, max_aleat);
	RellenaVector (v2, usados, min_aleat, max_aleat);

	// OUTPUT: Muestra los vectores originales

	MuestraVector ("Vector original 1: ", v1, usados, NUM_DATOS_LINEA);
	MuestraVector ("Vector original 2: ", v2, usados, NUM_DATOS_LINEA);

	//.......................................................................
	// PROCESAMIENTO: Se ordenan los vectores por burbuja (Orden clásico)

	OrdenaSeleccion (v1, usados);
	OrdenaSeleccion (v2, usados);


	// OUTPUT: Se muestran los vectores ordenados
	MuestraVector ("Vector ordenado 1: ", v1,usados,NUM_DATOS_LINEA);
	MuestraVector ("Vector ordenado 2: ", v2,usados,NUM_DATOS_LINEA);   

	//.......................................................................
	// DECLARACIÓN: Declaración del vector "mezcla" (mezcla clásica de v1 y v2)
	// NOTA: He decidido hacer la declaración de mezcla y TAM_MEZCLA a esta
	// altura del código porque he considerado que facilitaba la legibilidad
	// Además de que evito tener memoria "muerta" durante los pasos anteriores.

	const int TAM_MEZCLA = usados * 2;
	int mezcla[TAM_MEZCLA];
	
	// PROCESAMIENTO: Relleno mezcla con la mezcla clásica de v1 y v2
	MezclaVectoresSimple(mezcla, v1, usados, v2, usados);

	// OUTPUT: Mostrar el producto de la primera mezcla
	MuestraVector ("Mezcla no-selectiva (clasica): ", 
		           mezcla, usados,NUM_DATOS_LINEA); 

	//.......................................................................
	// PROCESAMIENTO: Ordenacion de mezcla por el nuevo método
	int util_mezcla = MezclaVectoresSelectiva (mezcla, v1, usados, v2, usados);

	// OUTPUT: Mostrar el vector ordenado
	MuestraVector ("Mezcla selectiva (nuevas): ", 
		           mezcla, util_mezcla, NUM_DATOS_LINEA);  


	return 0;
}

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
