/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 1
//
// Fichero: I_MezclaSencillaVectores.cpp
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/***************************************************************************/
// Muestra el contenido de un vector, con los datos alineados  
// Parámetros:
// 	p, dirección de memoria del inicio el vector.  
//	num_datos, número de casillas ocupadas del vector.
//	num_datos_linea, número de valores que se muestran en cada línea. 

void MuestraVector (int *p, int num_datos, int num_datos_linea)
{
	for (int i=0; i<num_datos; i++) {

		char separador = (((i+1)%num_datos_linea)==0) ? '\n':' ';
		cout <<setw(4)<< *(p+i) << separador;
	}
}

/***************************************************************************/

/***************************************************************************/
/***************************************************************************/

int main (void)
{
	const int MAX_LINE = 10; // Num. maximo de enteros por linea


	//......................................................................
	// Código "impuesto" en el enunciado 

	const int TOPE = 100;	 // Num. de casillas del vector 

	// Arrays ordenados, preparados para la mezcla

	int v1 [TOPE] = {2, 3, 8, 22, 44, 88, 99, 100, 101, 255, 665};
	int v2 [TOPE] = {1, 3, 4, 5, 6, 25, 87, 89, 99, 100, 500, 1000};

	int util_v1=11, util_v2=12;   // 0 <= util_v1, util_v2 < TOPE
	

	// Array resultado de la mezcla. 

	int res [2*TOPE];

	int util_res = util_v1+util_v2;  
	// El número de casillas de "res" será la suma del número de casillas 
	// útiles de "v1" y de "v2". 
	// En cualquier caso, siempre se cumple que 0 <= util_res < 2*TOPE

	// Fin del código "impuesto" en el enunciado 
	//......................................................................


	//***********************************************************************
	// Mostrar arrays que se van a mezclar
	//***********************************************************************

	cout << "v1:" << endl;
	MuestraVector (v1, util_v1, MAX_LINE);

	cout << "v2:" << endl;
	MuestraVector (v2, util_v2, MAX_LINE);


	//***********************************************************************
	// MEZCLA
	//***********************************************************************

	// Colocar punteros al inicio de los tres vectores

	int * p1 = v1;
	int * p2 = v2;
	int * p3 = res;

	// Colocar los punteros centinela en los vectores v1 y v2

	int * end1 = v1+util_v1;
	int * end2 = v2+util_v2;


	// Mientras queden datos por procesar en LOS DOS vectores

	while ((p1<end1) && (p2<end2)) {
		
		if (*p1 < *p2) { // El valor en v1 es menor que el que está en v2
			*p3 = *p1;   // copiar en "res" el valor de v1 (apuntado por p1)
 			p1++;        // Para la siguiente comparación adelantar p1
			
		}
		else {  // El valor en v1 NO es menor que el que está en v2
			*p3 = *p2;   // copiar en "res" el valor de v2 (apuntado por p2)
			p2++;		 // Para la siguiente comparación adelantar p2
		}

		p3++; // Adelantar p3 para copiar el siguiente valor seleccionado
	}


	// Uno de los dos vectores se ha procesado completamente. 
	// Tenemos que copiar los que no han sido procesado del otro vector. 

	// Si se ha procesado v2, copiar lo que quede en v1

	while (p1<end1){

		*p3 = *p1;	// copiar en "res" el valor de v1 (apuntado por p1)

		p1++;	// Adelantar p1 y p3 
		p3++;
	} 
	
	// Si se ha procesado v1, copiar lo que quede en v2

	while (p2<end2){

		*p3 = *p2;	// copiar en "res" el valor de v2 (apuntado por p2)

		p2++;	// Adelantar p2 y p3 
		p3++;
	}


	//***********************************************************************
	// Mostrar resultado
	//***********************************************************************

	cout << "Resultado de la mezcla:" << endl;
	MuestraVector (res, util_res, MAX_LINE);


	return 0;
}
