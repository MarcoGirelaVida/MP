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
    // Lectura de las dimensiones de la matriz

	int TAM_M;

	do
    {
		cout << endl;
		cout << "Introduzca num. de ciudades a recorrer: ";
		cin >> TAM_M; 
	}
    while (TAM_M <= 0);

	cout << endl << endl;

	// .....................................................................
	// Creación de una matriz y rellenar sus casillas  
	Matriz2D m = CreaMatriz (TAM_M, TAM_M);

    // Dos bucles anidados para recorrer la matriz
    for (int fil = 0; fil < TAM_M; fil++)
    {
        for (int col = 0; col < TAM_M; col++)
        {
            // Cuando la ciudad i es la misma que la ciudad j, el precio es 0
            if (fil == col)
            {
                m.datos[fil][col] = 0;
            }
            //En caso contrario solicito el precio de la ciudad i a la ciudad j
            else
            {
                do
                {
                    cout << endl;
                    cout << "Introduzca el precio de la ciudad " << fil
                    << " a la ciudad " << col << ": ";
                    cin >> m.datos[fil][col];
                }
                while (m.datos[fil][col] <= 0);
            }
        }
    }
    
	cout << "Relación de precios entre ciudades: ";
	cout << ToString (m, "Ciudad");

}
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////