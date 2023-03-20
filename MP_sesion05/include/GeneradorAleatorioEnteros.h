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
// Declaraci�n de la clase GeneradorAleatorioEnteros
//
// Fichero: GeneradorAleatorioEnteros.h
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

#ifndef GENERADOR_ALEATORIO_ENTEROS
#define GENERADOR_ALEATORIO_ENTEROS

#include<cstdlib>
#include<cctype>

#include <random>  
#include <chrono>  

using namespace std;

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

class GeneradorAleatorioEnteros
{  
private:
	
   mt19937 generador_mersenne;    // Mersenne twister
   uniform_int_distribution<int>  distribucion_uniforme;
   
public:
	
	/************************************************************************/	
	// Constructor sin argumentos: 
	// Inicializa el generador para proporcionar nums. aleatorios entre 0 y 1

	GeneradorAleatorioEnteros();
   
  	/************************************************************************/  
	// Constructor con argumentos: 
	// Inicializa el generador para proporcionar nums. aleatorios entre "min" 
	// y "max"
	
	GeneradorAleatorioEnteros(int min, int max);
   
	/************************************************************************/
	// Devuelve un nuevo n�mero aleatorio

	int Siguiente();

	/************************************************************************/

private: 

    /************************************************************************/
	// M�todos privados de la clase
    /************************************************************************/

	long long Nanosec();

   /************************************************************************/ 

};

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

#endif
