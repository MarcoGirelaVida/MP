/*********************************************************************/
// METODOLOG�A DE LA PROGRAMACI�N
// GRADO EN INGENIER�A INFORM�TICA
//
// AUTOR: MARCO GIRELA VIDA
// GRUPO: B
//
// PR�CTICA 3
/*	
	Funciones convenientes para el procesamiento de arrays de enteros.
*/
/*********************************************************************/

#ifndef INTARRAYMANG
#define INTARRAYMANG

/*********************************************************************/
// Muestra un vector dado 
// PRE: 

void MuestraVector (const char *msg, int *p, int n_datos, int datos_linea);

/*********************************************************************/
// Rellena un vector con números aleatorios dado rango en el que se generen los mismos 
// PRE:
//      p[]: Un puntero al inicio del vector que queremos rellenar
//      num_datos: Número de datos que queremos rellenar
//      min_aleat: Mínimo a partir del que se generan los números aleatorios
//      max_aleat: Máxima a partir del que se generan los números aleatorios.

void RellenaVector(int p[], int num_datos, int min_aleat, int max_aleat);

/*********************************************************************/
//
// PRE:

void OrdenaSeleccion (int *v, int pos_inic, int pos_fin);

/*********************************************************************/
//
// PRE:

void OrdenaInsercion (int *v, int pos_inic, int pos_fin);

/*********************************************************************/
//
// PRE:

void OrdenaIntercambio (int *v, int pos_inic, int pos_fin);

/*********************************************************************/
// Devuelve un puntero al mayor valor de un intervalo dado contenido en un vector.
// PRE:
//      pv: puntero a una casilla de un vector dado;
//      izda: límite inferior a partir de pv desde el que se quiere buscar.
//      dcha: límite superior a partir de pv desde el que se quiere buscar.

int * PosMayor(int * pv, int izda, int dcha);

#endif