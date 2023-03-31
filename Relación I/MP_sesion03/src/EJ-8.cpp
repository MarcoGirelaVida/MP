///////////////////////////////////////////////////////////////////////
/*
    METODOLOGIA DE LA PROGRAMACION
    GRADO EN INGENIER�A INFORMATICA

    AUTOR: MARCO GIRELA VIDA
    GRUPO: B

    PRACTICA 3 - EJERCICIO 8
*/
///////////////////////////////////////////////////////////////////////

#include <iostream>
#include "ProcesamientoArrayInt.h"

using namespace std;

///////////////////////////////////////////////////////////////////////

int main() {
    const int TOPE = 100;
    int v1[TOPE], v2[TOPE], res[2*TOPE];
    int tam_v1, tam_v2, tam_res;
    int pos_inic, pos_fin;
    int eleccion;

/*********************************************************************/
// Nótese que las funciones de INPUT ya han sido anteriormente utilizadas
// en el ej-6, por lo que serían perfectas candidatas a modularización,
// no obstante debido a que contienen órdenes de cin, cout no lo he hecho,
// (En FP me dijeron que no había que meter cin, cout en funciones)

    // INPUT: Pedimos el número de casillas a rellenar.
    cout << "Introduce el número de casillas que deseas rellenar en v1 y 2: ";
    cin >> tam_v1 >> tam_v2;
    while (!datovalido(tam_v1,1,TOPE-1) || !datovalido(tam_v2,1,TOPE-1))
    {
        cout << "Número de casillas inválido, introdúzcalo de nuevo. \n";
        cout << "Introduce el número de casillas que deseas rellenar: ";
        cin >> tam_v1 >> tam_v2;
    }
        //Defino tam_res como la suma de los tamaños del vector 1 y 2.
    tam_res = tam_v1 + tam_v2;

    // INPUT: Solicito el rango en el que se ordenará.
    cout << "Introduce las posiciones entre las que se va a reordenar: ";
    cin >> pos_inic >> pos_fin;
    while(!datovalido(pos_inic,1,TOPE)||!datovalido(pos_fin,1,TOPE)|| \
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
    RellenaVector(v1, tam_v1, 0, 100);
    RellenaVector(v2, tam_v2, 0, 100);


    // PROCESAMIENTO: Ordeno el vector acorde a la elección del usuario
    if(eleccion==1)
    {
        OrdenaSeleccion(v1, pos_inic, pos_fin);
        OrdenaSeleccion(v2, pos_inic, pos_fin);
    }
    else if (eleccion==2)
    {
        OrdenaInsercion(v1, pos_inic, pos_fin);
        OrdenaInsercion(v2, pos_inic, pos_fin);
    }
    else
    {
        OrdenaIntercambio(v1, pos_inic, pos_fin);
        OrdenaIntercambio(v2, pos_inic, pos_fin);
    }
    
    // PROCESAMIENTO: Mezclo ambos vectores llamando a la función "mezclar vectores"

/*********************************************************************/

    //OUTPUT: Muestro cómo ha quedado el vector ordenado.
    imprimirVector(res, tam_res);

}

///////////////////////////////////////////////////////////////////////