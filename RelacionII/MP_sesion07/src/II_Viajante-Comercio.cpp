/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// AUTOR: MARCO GIRELA VIDA
// GRUPO: 1ºB
// FECHA: xx/04/2023
//
// RELACION DE PROBLEMAS 2
//
//  
// 
//
// Fichero: II_Viajante-Comercio.cpp
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>

#include "Matriz2D.h"

using namespace std;

/***************************************************************************/
int main()
{
    //INPUT: Solicito el número de ciudades
	int TAM_M;
	do
    {
		cout << endl;
		cout << "Introduzca num. de ciudades a recorrer: ";
		cin >> TAM_M; 
	}   while (TAM_M <= 0);

    //INPUT: Solicito la ciudad desde donde se parte
    int ciudad_inicial;
    do
    {
        cout << endl;
        cout << "Introduzca la ciudad desde la que se parte: ";
        cin >> ciudad_inicial;
    }   while (ciudad_inicial <= 0 || ciudad_inicial > TAM_M);
    cout << endl;

	// .....................................................................
	//DECLARACION: Creación de una matriz cuadrada donde se almacenará la
    //relación de precios entre los distintos viajes.
	Matriz2D precios = CreaMatriz (TAM_M, TAM_M);

    // Dos bucles anidados para recorrer la matriz
    for (int fil = 0; fil < TAM_M; fil++){
        for (int col = 0; col < TAM_M; col++)
        {
            //FILTRO: Cuando la ciudad i es la misma que la ciudad j, el precio es 0
            if (fil == col) {precios.datos[fil][col] = 0;}

            //INPUT: En caso contrario solicito el precio de la ciudad i a la ciudad j
            else
            {
                do
                {
                    cout << endl;
                    cout << "Precio por trayecto C" <<fil+1<< " -> C" <<col+1<< ": ";
                    cin >> precios.datos[fil][col];
                }
                while (precios.datos[fil][col] <= 0);
            }
        }
    }
    cout << endl << endl;
    
    // .....................................................................
    // OUTPUT: Muestro los precios asociados a cada viaje
	cout << "Relación de precios entre ciudades: ";
	cout << ToString (precios, "Ciudad", 1);

/***************************************************************************/
    //PROCESAMIENTO: Calculo cual es la ruta más barata.

    //Declaro un vector donde se almacenará la ruta más barata
    int * ruta = new int [TAM_M];
    ruta[0] = ciudad_inicial-1; // Lo inicializo con la ciudad inicial

    //Inicializo el precio a 0
    int precio = 0;

    for(int i=1; i<TAM_M; i++)
    {
        // Almaceno la columna que contiene el menor precio de la fila i
        ruta[i] = menorenfila(precios, ruta[i-1], ruta, i);
        precio += precios.datos[ruta[i-1]][ruta[i]];
    }

    // Añado el precio de ir desde la última ciudad a la inicial
    precio += precios.datos[ruta[TAM_M]][ruta[0]];

/***************************************************************************/
    //OUTPUT: Muestro la ruta más barata y su precio

    cout << "La ruta más barata es: " << endl;
    for (int i = 0; i < TAM_M; i++)
    {
        cout << "Ciudad " << ruta[i] + 1 << " --> ";
    }
    cout << "Ciudad inicial " << ruta[0] + 1;
    cout << endl;

    cout << "El precio de la ruta es: " << precio << endl;

/***************************************************************************/
    //DESTRUCCION: Libero la memoria dinámica reservada para la matriz
    DestruyeMatriz (precios);
    delete [] ruta;

    return 0;
}
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////