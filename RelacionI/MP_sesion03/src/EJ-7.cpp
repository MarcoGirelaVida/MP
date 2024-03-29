///////////////////////////////////////////////////////////////////////
/*
    METODOLOGIA DE LA PROGRAMACION
    GRADO EN INGENIER�A INFORMATICA

    AUTOR: MARCO GIRELA VIDA
    GRUPO: B

    PRACTICA 3 - EJERCICIO 7
*/
///////////////////////////////////////////////////////////////////////

#include <iostream>
#include "ProcesamientoArrayInt.h"

using namespace std;

///////////////////////////////////////////////////////////////////////

int main() {
    const int TOPE = 100;
    int vector[TOPE];
    int util_v, pos_inic, pos_fin;
    int eleccion;

/*********************************************************************/
// Nótese que las funciones de INPUT ya han sido anteriormente utilizadas
// en el ej-6, por lo que serían perfectas candidatas a modularización,
// no obstante debido a que contienen órdenes de cin, cout no lo he hecho,
// (En FP me dijeron que no había que meter cin, cout en funciones)

    // INPUT: Pedimos el número de casillas a rellenar.
    cout << "Introduce el número de casillas que deseas rellenar: ";
    cin >> util_v;
    while (util_v < 0 || util_v > TOPE)
    {
        cout << "Número de casillas inválido, introdúzcalo de nuevo. \n";
        cout << "Introduce el número de casillas que deseas rellenar: ";
        cin >> util_v;
    }

    // INPUT: Solicito el rango en el que se ordenará.
    cout << "Introduce las posiciones entre las que se va a reordenar: ";
    cin >> pos_inic >> pos_fin;
    while(!datovalido(pos_inic,1,util_v)||!datovalido(pos_fin,1,util_v)|| \
    pos_inic>pos_fin)
    {
        cout << "Posiciones inválidas, introdúzcalo de nuevo." << endl;
        cout << "Introduce las posiciones entre las que se va a reordenar ";
        cin >> pos_inic >> pos_fin;
    }

    // INPUT: Solicito el tipo de ordenación que se usará.
    cout << "Introduce el tipo de ordenación (1:selec 2:inser 3:inter): ";
    cin >> eleccion;
    while(eleccion<1 || eleccion>3)
    {
        cout << "Elección inválida, introdúzcala de nuevo." << endl;
        cout << "Introduce las posiciones entre las que se va a reordenar ";
        cin >> eleccion;
    }

/*********************************************************************/

    // PROCESAMIENTO: Llamo "RellenaVector" para rellenarlo.
    RellenaVector(vector, util_v, 0, 100);


    // PROCESAMIENTO: Ordeno el vector acorde a la previa elección del usuario
    if(eleccion==1)
    {
        OrdenaSeleccion(vector, pos_inic, pos_fin);
    }
    else if (eleccion==2)
    {
        OrdenaInsercion(vector, pos_inic, pos_fin);
    }
    else
    {
        OrdenaIntercambio(vector, pos_inic, pos_fin);
    }
    
    

/*********************************************************************/

    //OUTPUT: Muestro cómo ha quedado el vector ordenado.
    imprimirVector(vector, util_v);

}

///////////////////////////////////////////////////////////////////////