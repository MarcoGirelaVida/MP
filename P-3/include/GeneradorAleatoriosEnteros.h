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

#ifndef GENERADOR_ALEATORIO_ENTEROS_H
#define GENERADOR_ALEATORIO_ENTEROS_H

/*********************************************************************/

#include <random>
#include <chrono>

/*********************************************************************/

class GeneradorAleatorioEnteros {
private:
    std::mt19937 generador_mersenne;
    std::uniform_int_distribution<int> distribucion_uniforme;

    long long Nanosec();

public:
    GeneradorAleatorioEnteros();
    GeneradorAleatorioEnteros(int min, int max);

    int Siguiente();
};

#endif