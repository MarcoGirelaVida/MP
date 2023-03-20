/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// AUTOR: MARCO GIRELA VIDA
// GRUPO: 1ºB
// FECHA: xx/03/2023
//
// RELACION DE PROBLEMAS 1
//
//  
// 
//
// Declaraciones en: 
//
// Fichero: 
//
/***************************************************************************/
/***************************************************************************/

#include "ProcesamientoArrayInt.h"
#include "GeneradorAleatorioEnteros.h"
#include <iostream>

using namespace std;

/***************************************************************************/
/***************************************************************************/
// Mezcla selectiva, guarda solo aquellos números que no se hayan repetido.
//
// Parámetros:
//		mezcla, dirección de memoria del inicio el vector resultado  
//		v1, dirección de memoria del inicio del primer vector a mezclar  
//		util_v1, número de casillas ocupadas en "v1"
//		v2, dirección de memoria del inicio del segundo vector a mezclar  
//		util_v2, número de casillas ocupadas en "v2"
// PRE: "v1" y "v2" están ordenados
// PRE: "mezcla" tiene suficiente memoria asignada
// PRE: util_v1, util_v2 >= 0

int MezclaVectoresSelectiva (int mezcla[], int v1[],
int util_v1, int v2[], int util_v2);

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

/***************************************************************************/
// Mezcla selectiva, guarda solo aquellos números que no se hayan repetido.
// 
// Parámetros:
//		mezcla, dirección de memoria del inicio el vector resultado  
//		v1, dirección de memoria del inicio del primer vector a mezclar  
//		util_v1, número de casillas ocupadas en "v1"
//		v2, dirección de memoria del inicio del segundo vector a mezclar  
//		util_v2, número de casillas ocupadas en "v2"
// PRE: "v1" y "v2" están ordenados
// PRE: "mezcla" tiene suficiente memoria asignada
// PRE: util_v1, util_v2 >= 0
/*
	EJEMPLO DE FUNCIONAMIENTO:
	Si en v1 hay un 8 y en v2 también, no se mete 8 en "mezcla".
	Si en v1 hay un 2 y en v2 no, se meterá un 2 en mezcla.
	Además, si en v1 hay {..., 8, 8, 8, ...} y en v2 no hay ningún 8,
	entonces solo se meterá UN 8 en "mezcla" (no los tres).
*/

int MezclaVectoresSelectiva (int mezcla[], int v1[],
int util_v1, int v2[], int util_v2)
{
	const int * const inicio_mezcla = mezcla;
	const int * const p_finalv1 = v1 + util_v1;
	const int * const p_finalv2 = v2 + util_v2;

	// El while terminará cuando alguno de los dos vectores se vacíe.
	while (v1 <= (int *) p_finalv1 ||
		   v2 <= (int *) p_finalv2 )
	{

		// Observe que, dado que ambos vectores avanzan "a la par";
		// el hecho de que uno sea menor que otro es criterio suficiente
		// para demostrar la unicidad de ese elemento.
		if (*v1 > *v2)
		{
			*mezcla = *v2;
			mezcla++;
			// He optado por esta peculiar notación del dowhile debido a que,
			// en ponderación, la considerable mejora de legibilidad
			// compensa la leve pérdida de "estandarización".

			// Estos do_while sirven para evitar copiar elementos repetidos
			// dentro del propio vector.
			do{v2++;} while (*v2 == *(v2+1) && v2 != p_finalv2);
		}
		else if (*v1 < *v2)
		{
			*mezcla = *v1;
			mezcla++;
			do{v1++;} while (*v1 == *(v1+1) && v1 != p_finalv1);
		}
		else
		{
			do{v1++;} while (*v1 == *(v1+1) && v1 != p_finalv1);
			do{v2++;} while (*v2 == *(v2+1) && v2 != p_finalv2);
		}
	}

	// A continuación relleno "mezcla" con el vector no vacío
	// (aquel con el mayor elemento más grande).
	// Nótese que he ignorado el caso en el que ambos p_finales son iguales
	// puesto que en tal caso, ambos "while" se ignararán y me ahorro un "elif"

	if (p_finalv1 > p_finalv2)
	{
		while (v1 < p_finalv1)
		{
			*mezcla = *v1;
			mezcla++;
			do{v1++;} while (*v1 == *(v1+1) && v1 != p_finalv1);
			cout << "Util_mezcla tmp es: " << mezcla - inicio_mezcla << endl << endl;
		}
	}
	else
	{
		while (v2 < p_finalv2)
		{
			*mezcla = *v2;
			mezcla++;
			do{v2++;} while (*v2 == *(v2+1) && v2 != p_finalv2);
			cout << "Util_mezcla tmp es: " << mezcla - inicio_mezcla << endl << endl;
		}
	}

	cout << "Util_mezcla final es: " << mezcla - inicio_mezcla << endl << endl;
	return (mezcla - inicio_mezcla);
}
