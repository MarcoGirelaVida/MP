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
#include "GeneradorAleatorioEnteros.h"

using namespace std;



///////////////////////////////////////////////////////////////////////
// Devuelve un puntero al mayor val de un intervalo contenido en un vec.
// PRE:
//      pv: puntero a una casilla de un vector dado;
//      izda: límite inferior a partir de pv desde el que se quiere buscar.
//      dcha: límite superior a partir de pv desde el que se quiere buscar.

int * PosMayor(int v[], int izda, int dcha)
{
// Inicializo el vector 'pMayor' a la primera dirección a partir de la
// que quiero buscar el mayor.

    int * pMayor = &v[izda];

/*  
A lo largo del fragmento solicitado comparo el contenido de cada de
dirección con el del mayor valor hasta el momento (almacenado en el
puntero 'pMayor').
Si el contenido comparado es mayor que el contenido de pMayor, este
se actualiza.
*/
    for (int i = izda; i <= dcha; i++)
    {
        if (v[i] > *pMayor)
        {
            pMayor = &v[i];
        }
    }
    return pMayor;
}   

/*
Nótese que he hecho uso de la sintaxis de corchetes puesto que la
encuentro más intuitiva, no obstante podría haberlo hecho con sintaxis
de asteriscos y hubiera quedado de la siguiente manera:

int* PosMayor(int* v, int izda, int dcha)
{
    int* pMayor = v + izda;
    for (int i = izda; i <= dcha; i++)
    {
        if (*(v + i) > *pMayor)
        {
            pMayor = v + i;
        }
    }
    return pMayor;
}

*/

/*********************************************************************/
// Rellena un vector con Nºs aleatorios dado rango en el que se generen. 
// PRE:
//      p[]: Un puntero al inicio del vector que queremos rellenar
//      num_datos: Número de datos que queremos rellenar
//      min_aleat: Mínimo a partir del que se generan los números aleatorios
//      max_aleat: Máxima a partir del que se generan los números aleatorios.

void RellenaVector(int p[], int num_datos, int min_aleat, int max_aleat)
{
    GeneradorAleatorioEnteros generador(min_aleat, max_aleat);

    for (int i = 0; i < num_datos; i++)
    {
        p[i] = generador.Siguiente();
    }
}



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
    while(izda < 0|| izda >= util_v || dcha < 0|| dcha >= util_v || izda > dcha)
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