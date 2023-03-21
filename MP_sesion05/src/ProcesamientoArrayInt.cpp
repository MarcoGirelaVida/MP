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
// Fichero: ProcesamientoArrayInt.cpp
//
/***************************************************************************/
 
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>

#include "GeneradorAleatorioEnteros.h"
#include "ProcesamientoArrayInt.h"

using namespace std;

/***************************************************************************/
/***************************************************************************/
// Muestra el contenido de un vector de datos int con los datos alineados.   
// Con más precisión, muestra la parte comprendida desde el elemento cuya 
// dirección es "p" que tiene "n_datos" elementos). 
// Se muestra con el encabezamiento dado por "msg" y en cada línea se 
// imprimen, alineados, "datos_linea" datos. 
//
// Parámetros:
//		mensaje, "título" que encabeza la presentación
// 		p, n_datos de memoria del inicio el vector  
//		n_datos, número de casillas ocupadas del vector
//		datos_linea, número de valores que se muestran en  cada línea

void MuestraVector (string mensaje, int *p, int n_datos, int datos_linea)
{
	cout << mensaje << endl;

	for (int i=0; i<n_datos; i++) 
		cout <<setw(4)<< *(p+i) << ((((i+1)%datos_linea)==0)?"\n":" ");

	cout << endl << endl;
}

/***************************************************************************/
/***************************************************************************/
// Rellena un vector de datos int con "n_datos" números aleatorios.  
// Se rellenarán las primeras "n_datos" casillas a partir de la dirección 
// dada en "p". 
// Los valores están comprendidos entre "min_aleat" y "max_aleat". 
//
// Parámetros:
//		p, dirección de memoria donde se empieza a rellenar. 
//		num_datos, número de casillas a rellenar.
//		min_aleat y max_aleat, mínimo y máximo valor aleatorio.  
// PRE: num_datos >= 0
// PRE: min_aleat <= max_aleat

void RellenaVector (int *p, int num_datos,  const int min_aleat, 
	                 const int max_aleat)
{
	// Rellenar el vector con valores aleatorios entre "min" y "max" 
	GeneradorAleatorioEnteros generador (min_aleat, max_aleat);

	for (int i=0; i<num_datos; i++) 
      *(p+i) = generador.Siguiente();
}

/***************************************************************************/
/***************************************************************************/
// Ordenación por selección
// 
// Parámetros:
//		v, dirección de memoria del primer elemento del subvector a ordenar
//		pos_inic, pos_fin, posiciones entre las que ordenar.
// PRE: pos_inic <= pos_fin
// PRE: pos_inic y pos_fin son correctas

void OrdenaSeleccion (int *v, int pos_inic, int pos_fin)
{
	OrdenaSeleccion (v+pos_inic, pos_fin-pos_inic+1);
}

/***************************************************************************/
/***************************************************************************/
// Ordenación por inserción
// 
// Parámetros:
//		v, dirección de memoria del primer elemento del subvector a ordenar
//		pos_inic, pos_fin, posiciones entre las que ordenar.
// PRE: pos_inic <= pos_fin
// PRE: pos_inic y pos_fin son correctas

void OrdenaInsercion (int *v, int pos_inic, int pos_fin)
{
	OrdenaInsercion (v+pos_inic, pos_fin-pos_inic+1);
}

/***************************************************************************/
/***************************************************************************/
// Ordenación por intercambio
// 
// Parámetros:
//		v, dirección de memoria del primer elemento del subvector a ordenar
//		pos_inic, pos_fin, posiciones entre las que ordenar.
// PRE: pos_inic <= pos_fin
// PRE: pos_inic y pos_fin son correctas

void OrdenaIntercambio (int *v, int pos_inic, int pos_fin)
{
	OrdenaIntercambio (v+pos_inic, pos_fin-pos_inic+1);
}

/***************************************************************************/
/***************************************************************************/
// Ordenación por intercambio mejorado
// 
// Parámetros:
//		v, dirección de memoria del primer elemento del subvector a ordenar
//		pos_inic, pos_fin, posiciones entre las que ordenar.
// PRE: pos_inic <= pos_fin
// PRE: pos_inic y pos_fin son correctas

void OrdenaIntercambioMejorado (int *v, int pos_inic, int pos_fin)
{
	OrdenaIntercambioMejorado (v+pos_inic, pos_fin-pos_inic+1);
}

/***************************************************************************/
/***************************************************************************/
// Ordenación por selección
// 
// Parámetros:
//		v, dirección de memoria del primer elemento del subvector a ordenar
//		tamanio, número de elementos del subvector a ordenar. 
// PRE: tamanio >= 0

void OrdenaSeleccion (int *v, int tamanio) 
{
	for (int izda = 0; izda < tamanio; izda++) {

		// Calcular el mínimo entre "izda" y "total_utilizados"-1

		int minimo = v[izda]; // Valor del mínimo
		int pos_min = izda;   // Posición del mínimo

		for (int i = izda + 1; i < tamanio; i++)

			if (v[i] < minimo){ // Nuevo mínimo
			    minimo = v[i];
			    pos_min = i;
			 }

		// Intercambiar los valores guardados en "izda" y "pos_min"  

		Intercambia (&v[izda], &v[pos_min]);
   }
}

/***************************************************************************/
/***************************************************************************/
// Ordenación por inserción
//
// Parámetros:
//		v, dirección de memoria del primer elemento del subvector a ordenar
//		tamanio, número de elementos del subvector a ordenar. 
// PRE: tamanio >= 0

void OrdenaInsercion (int *v, int tamanio) 
{
	for (int izda = 1; izda < tamanio; izda++){

		// "a_insertar" es el valor que se va a insertar en el 
		// subvector izquierdo. Este subvector está ordenado y 
		// comprende las posiciones entre 0 e "izda"-1

		int a_insertar = v[izda]; 

		// Se busca la posición en la zona ordenada


		int i = izda; 
		while (i > 0 && a_insertar < v[i-1]) {

			v[i] = v[i-1]; // Desplazar a la derecha los 
						    // valores mayores que "a_insertar"
			i--;
		}

		v[i] = a_insertar; // Copiar -insertar- en el hueco
	}
}


/***************************************************************************/
/***************************************************************************/
// Ordenación por intercambio
//
// Parámetros:
//		v, dirección de memoria del primer elemento del subvector a ordenar
//		tamanio, número de elementos del subvector a ordenar. 
// PRE: tamanio >= 0

void OrdenaIntercambio (int *v, int tamanio) 
{
	for (int izda = 0; izda < tamanio; izda++)

		for (int i = tamanio-1 ; i > izda; i--)

			if (v[i] < v[i-1]) // Intercambiar 

				Intercambia (&v[i], &v[i-1]);
}


/***************************************************************************/
/***************************************************************************/
// Ordenación por intercambio mejorado
//
// Parámetros:
//		v, dirección de memoria del primer elemento del subvector a ordenar
//		tamanio, número de elementos del subvector a ordenar. 
// PRE: tamanio >= 0

void OrdenaIntercambioMejorado (int *v, int tamanio) 
{
	bool cambio = true; // Para entrar

	int izda = 0; 

	while (izda < tamanio && cambio) {

		// En cada pasada iniciamos "cambio" a false. 
		// Se pondrá true si y solo si hay algún intercambio

		cambio = false;

		for (int i = tamanio-1; i > izda; i--)

			if (v[i] < v[i-1]) { // Intercambiar 

				Intercambia (&v[i], &v[i-1]);

				cambio = true; // Se ha hecho un intercambio
			}

		izda++;
	}
}

/***************************************************************************/
/***************************************************************************/
// Mezcla dos vectores.
// Parámetros:
//		mezcla, dirección de memoria del inicio el vector resultado  
//		v1, dirección de memoria del inicio del primer vector a mezclar  
//		util_v1, número de casillas ocupadas en "v1"
//		v2, dirección de memoria del inicio del segundo vector a mezclar  
//		util_v2, número de casillas ocupadas en "v2"
// PRE: "v1" y "v2" están ordenados
// PRE: "mezcla" tiene suficiente memoria asignada
// PRE: util_v1, util_v2 >= 0

void MezclaVectoresSimple (int *mezcla, int *v1, int util_v1, int *v2, int util_v2)
{
	// Colocar punteros al inicio de los vectores
	int * p1 = v1;
	int * p2 = v2;
	int * p3 = mezcla;

	// Marcar el final de los vectores a mezclar
	int * end1 = v1+util_v1;
	int * end2 = v2+util_v2;

	// mientras queden en los dos vectores

	while ((p1<end1) && (p2<end2)) {
		
		if (*p1 < *p2) {
			*p3 = *p1;   // copiar de v1
			p1++;
			
		}
		else {
			*p3 = *p2;   // copiar de v2
			p2++;
		}

		p3++;
	}

	// copiar lo que quede en v1

	while (p1<end1){

		*p3 = *p1;
		p1++;

		p3++;
	} 
	
	// copiar lo que quede en v2

	while (p2<end2){

		*p3 = *p2;
		p2++;

		p3++;
	}
}

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
	int * pv1 = v1;
	int * pv2 = v2;
	int * pmez = mezcla;
	//const int * const inicio_mezcla = mezcla;
	const int * const p_finalv1 = v1 + util_v1;
	const int * const p_finalv2 = v2 + util_v2;

	// El while terminará cuando alguno de los dos vectores se vacíe.
	while (pv1 <= (int *) p_finalv1 &&
		   pv2 <= (int *) p_finalv2)
	{

		// Observe que, dado que ambos vectores avanzan "a la par";
		// el hecho de que uno sea menor que otro es criterio suficiente
		// para demostrar la unicidad de ese elemento.
		if (*pv1 > *pv2)
		{
			*pmez = *pv2;
			pmez++;
			// He optado por esta peculiar notación del dowhile debido a que,
			// en ponderación, la considerable mejora de legibilidad
			// compensa la leve pérdida de "estandarización".

			// Estos do_while sirven para evitar copiar elementos repetidos
			// dentro del propio vector.
			while (*pv2 == *(pv2+1) && pv2 != p_finalv2) {pv2++;}
			pv2++;
		}
		else if (*pv1 < *pv2)
		{
			*pmez = *pv1;
			pmez++;
			while (*pv1 == *(pv1+1) && pv1 != p_finalv1) {pv1++;}
			pv1++;
		}
		else
		{
			while (*pv1 == *(pv1+1) && pv1 != p_finalv1) {pv1++;}
			pv1++;
			while (*pv2 == *(pv2+1) && pv2 != p_finalv2) {pv2++;}
			pv2++;
		}
	}

	// A continuación relleno "mezcla" con el vector no vacío
	// (aquel con el mayor elemento más grande).
	// Nótese que he ignorado el caso en el que ambos p_finales son iguales
	// puesto que en tal caso, ambos "while" se ignararán y me ahorro un "elif"

	if (p_finalv1 > p_finalv2)
	{
		while (pv1 < p_finalv1)
		{
			*pmez = *pv1;
			pmez++;
			while (*pv1 == *(pv1+1) && pv1 != p_finalv1) {pv1++;}
			pv1++;
		}
	}
	else
	{
		while (pv2 < p_finalv2)
		{
			*pmez = *pv2;
			pmez++;
			while (*pv2 == *(pv2+1) && pv2 != p_finalv2) {pv2++;}
			pv2++;
		}
	}

	return (pmez - mezcla);
}

/***************************************************************************/
/***************************************************************************/
// Mezcla dos vectores de forma selectiva o no selectiva (ver 
// funcinamiento de ambas funciones encima de esta).
//
// Parámetros:
//		mezcla, dirección de memoria del inicio el vector resultado  
//		v1, dirección de memoria del inicio del primer vector a mezclar  
//		util_v1, número de casillas ocupadas en "v1"
//		v2, dirección de memoria del inicio del segundo vector a mezclar  
//		util_v2, número de casillas ocupadas en "v2"
//		util_mezcla proporciona el número de casillas útiles de mezcla
//		selectiva indica a la función si debe realizar una mezcla selectiva 
//		o no. El valor por defecto es no.
// PRE: "v1" y "v2" están ordenados
// PRE: "mezcla" tiene suficiente memoria asignada
// PRE: util_v1, util_v2 >= 0
// PRE: "selectiva" debe ser un valor válido (si/no)

void MezclaVectores (int mezcla[], int &util_mezcla,
					int v1[], int util_v1, int v2[], int util_v2,
					const char * selectiva)
{
	if (strcmp(selectiva, "SI") || strcmp(selectiva, "si") ||
		strcmp(selectiva, "sI") || strcmp(selectiva, "Si"))
	{
		cout << "se ha entrado" << endl;
		util_mezcla = MezclaVectoresSelectiva (mezcla, v1, util_v1,
													   v2, util_v2);
	}
	
	util_mezcla = util_v1 + util_v2;
	MezclaVectoresSimple(mezcla, v1, util_v1, v2, util_v2);
}

/***************************************************************************/
/***************************************************************************/
// Intercambia los valores cuyas direcciones están en "p1" y "p2"


void Intercambia (int * p1, int * p2)
{
	int tmp = * p1;
	*p1 = *p2;
	*p2 = tmp;
}

/***************************************************************************/
/***************************************************************************/
