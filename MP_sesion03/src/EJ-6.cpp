///////////////////////////////////////////////////////////////////////
/*
    METODOLOGIA DE LA PROGRAMACION
    GRADO EN INGENIER�A INFORMATICA

    AUTOR: MARCO GIRELA VIDA
    GRUPO: B

    PRACTICA 3 - EJERCICIO 6
*/
/*	
Escribir una función que recibe un vector de números enteros y dos
valores enteros.
La función devuelve un puntero al elemento mayor dentro de ese intervalo.

La función tendrá como prototipo:
int * PosMayor (int *pv, int izda, int dcha);

donde pv contiene la dirección de memoria de una casilla del vector e
izda y dcha son los extremos del intervalo entre los que se realiza
la búsqueda del elemento mayor.

Considere la siguiente declaración:
const int TOPE = 100;
int vector [TOPE];

Escriba un programa que rellene aleatoriamente el vector (completamente
o una parte,
pero siempre desde el principio) y que calcule el mayor valor
entre dos posicionesdadas. El programa pedirá:
    a) el número de casillas que se van a rellenear con números aleatorios,
    b) las posiciones entre las que se va a calcular el mayor valor.

Considere todas las situaciones de error que puedan ocurrir y busque
soluciones razonables antes que abortar la ejecución del programa.
Nota: Modularice la solución con funciones
*/
///////////////////////////////////////////////////////////////////////



#include <iostream>
#include "ProcesamientoArrayInt.h"

using namespace std;

///////////////////////////////////////////////////////////////////////
int main()
{
    // DECLARACIÓN
    const int TOPE = 100;
    int vector[TOPE];
    int util_v, izda, dcha;

/*********************************************************************/

    // INPUT: Pedimos el número de casillas a rellenar.
    cout << "Introduce el número de casillas que deseas rellenar: ";
    cin >> util_v;
    while (util_v < 0 || util_v > TOPE)
    {
        cout << "Número de casillas inválido, introdúzcalo de nuevo. \n";
        cout << "Introduce el número de casillas que deseas rellenar: ";
        cin >> util_v;
    }

    // INPUT: Solicito el rango en el que se buscará el mayor valor.
    cout << "Introduce las posiciones entre las que se va a calcular" 
    "el mayor valor: ";
    cin >> izda >> dcha;
    while(izda<0||izda>=util_v||dcha< 0||dcha>=util_v||izda>dcha)
    {
        cout << "Posiciones inválidas, introdúzcalo de nuevo." << endl;
        cout << "Introduce las posiciones entre las que se va a calcular"
        "el mayor valor: ";
        cin >> izda >> dcha;
    }

/*********************************************************************/

    // PROCESAMIENTO: Llamo "RellenaVector" para rellenarlo.
    RellenaVector(vector, util_v, 0, 100);

    // PROCESAMIENTO: Llamo "pMayor" para buscar el mayor del intervalo.
    int *pMayor = PosMayor(vector, izda, dcha);

/*********************************************************************/

    // OUTPUT: Muestro el mayor valor.
    cout << "El mayor valor en el intervalo [" << izda << ", " << dcha
     << "] es: "<< *pMayor << endl;

}

///////////////////////////////////////////////////////////////////////