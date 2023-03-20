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
// Definici�n de la clase GeneradorAleatorioEnteros
//
// Fichero: GeneradorAleatorioEnteros.cpp
//
/*
	Sirve para generar n�meros aleatorios enteros en un rango de valores.
	
	Hay crear un objeto de esta clase. Se dispone de dos constructores: 
	
	1) GeneradorAleatorioEnteros();
	   Se van a generar �nicamente valotres binarios (ceros y unos).

	2) GeneradorAleatorioEnteros(int min, int max);
		El segundo tiene dos par�metros, "min" y "max" que delimitan el 
		rango correspondiente. 

	Una vez creado un objeto de la clase, la ejecuci�n sobre �l del m�todo 
	
		int Siguiente()
	
	devolver� un valor aleatorio en el rango especificado en el constructor.
*/
/***************************************************************************/
/***************************************************************************/

#include "GeneradorAleatorioEnteros.h"  

using namespace std;

/************************************************************************/	
// Constructor sin argumentos: 
// Inicializa el generador para proporcionar nums. aleatorios entre 0 y 1

GeneradorAleatorioEnteros :: GeneradorAleatorioEnteros()
	:GeneradorAleatorioEnteros(0, 1)
{
}

/************************************************************************/  
// Constructor con argumentos: 
// Inicializa el generador para proporcionar nums. aleatorios entre "min" 
// y "max"

GeneradorAleatorioEnteros :: GeneradorAleatorioEnteros(int min, int max) 
{
	const int A_DESCARTAR = 70000;
	// ACM TOMS Volume 32 Issue 1, March 2006

	auto semilla = Nanosec();
	generador_mersenne.seed(semilla);
	generador_mersenne.discard(A_DESCARTAR);
	distribucion_uniforme = uniform_int_distribution<int> (min, max);
}

/************************************************************************/
// Devuelve un nuevo n�mero aleatorio

int GeneradorAleatorioEnteros :: Siguiente()
{
	return (distribucion_uniforme(generador_mersenne));
}
/************************************************************************/

/************************************************************************/
// M�TODOS PRIVADOS
/************************************************************************/

long long GeneradorAleatorioEnteros :: Nanosec()
{
  return (chrono::high_resolution_clock::now().
          time_since_epoch().count());
}

/************************************************************************/ 
