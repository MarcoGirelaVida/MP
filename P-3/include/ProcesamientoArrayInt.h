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

#include <iostream>
#include <random> 
#include <chrono>  

using namespace std;

/*********************************************************************/
// Muestra un vector dado 
// PRE: vector y longuitud que se quiere mostrar
void imprimirVector(int *v, int n);

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

/*********************************************************************/
// Comprueba la validez de un dato a corde a unos parametros dados
// PRE:
//      pv: puntero a una casilla de un vector dado;
//      izda: límite inferior a partir del que se puede definir.
//      dcha: límite superior a partir del que se puede definir.
bool datovalido(int dato, int izda, int dcha);


/*********************************************************************/
// Clase para la generación de enteros aleatorios, copiada de prado, 
// nada que explicar.

class GeneradorAleatorioEnteros
{  
private:
	
	mt19937 generador_mersenne;    // Mersenne twister
	uniform_int_distribution<int>  distribucion_uniforme;
	
	/************************************************************************/
	
	long long Nanosec(){
		return (chrono::high_resolution_clock::now().time_since_epoch().count());
	}
	
	/************************************************************************/ 
	
public:
	
	/************************************************************************/
		
	GeneradorAleatorioEnteros() : GeneradorAleatorioEnteros(0, 1) 
	{ }
	
	/************************************************************************/  
	GeneradorAleatorioEnteros(int min, int max) {
	
		const int A_DESCARTAR = 70000;
		// ACM TOMS Volume 32 Issue 1, March 2006
		
		auto semilla = Nanosec();
		generador_mersenne.seed(semilla);
		generador_mersenne.discard(A_DESCARTAR);
		distribucion_uniforme = uniform_int_distribution<int> (min, max);
	}
	
	/************************************************************************/
	
	int Siguiente(){
	  return (distribucion_uniforme(generador_mersenne));
	}
	
	/************************************************************************/

};

#endif // GENERADORALEATORIOENTEROS_H