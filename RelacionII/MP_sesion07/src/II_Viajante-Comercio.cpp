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
/***************************************************************************/
// Devuelve el número de la ciudad de destino (columna) con el menor precio
// dada una ciudad de salida (fila).
// Garantiza que dicha ciudad de llegada sea distinta a la ciudad de salida
// y que no esté contenida en el vector ruta (ciudades ya visitadas)

int menorprecio(const Matriz2D & precios, int ciudad_salida,
				int *ruta, int visitadas);

/***************************************************************************/
/***************************************************************************/
int main()
{
    //INPUT: Solicito el número de ciudades
	int nciudades;
	do
    {
		cout << endl;
		cout << "Introduzca num. de ciudades a recorrer: ";
		cin >> nciudades; 
	}   while (nciudades <= 0);

    //INPUT: Solicito la ciudad desde donde se parte
    int ciudad_inicial;
    do
    {
        cout << endl;
        cout << "Introduzca la ciudad desde la que se parte: ";
        cin >> ciudad_inicial;
    }   while (ciudad_inicial <= 0 || ciudad_inicial > nciudades);
    cout << endl;

	// .....................................................................
	//DECLARACION: Creación de una matriz cuadrada donde se almacenará la
    //relación de precios entre los distintos viajes.
	Matriz2D precios = CreaMatriz (nciudades, nciudades);

    // Dos bucles anidados para recorrer la matriz
    for (int fil = 0; fil < nciudades; fil++){
        for (int col = 0; col < nciudades; col++)
        {
            //FILTRO:
            //Cuando la ciudad i es la misma que la ciudad j, el precio es 0
            if (fil == col) {precios.datos[fil][col] = 0;}

            //INPUT:
            //En caso contrario solicito el precio de la ciudad i a la ciudad j
            else
            {
                do
                {
                    cout << endl;
                    cout << "Precio por trayecto C" <<fil+1
                    << " -> C" <<col+1<< ": ";
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
    //PROCESAMIENTO: Calculo cuál es la ruta más barata.

    //Declaro un vector donde se almacenará la ruta más barata
    int * ruta = new int [nciudades];
    // Lo inicializo con la ciudad inicial
    ruta[0] = ciudad_inicial-1;
    //Inicializo el precio total a 0
    int precio_total = 0;

    for (int next_city=1; next_city < nciudades; next_city++)
    {
        int prev_city = next_city-1; // En ingles porque es más corto

        // Almaceno la columna que contiene el menor precio de la fila i
        ruta[next_city] = menorprecio (precios, ruta[ruta[prev_city]],
                                        ruta, next_city);

        precio_total += precios.datos[ruta[prev_city]][ruta[next_city]];
    }

    // Añado el precio de ir desde la última ciudad a la inicial
    precio_total += precios.datos[ruta[nciudades-1]][ruta[0]];


/***************************************************************************/
    //OUTPUT: Muestro la ruta más barata y su precio

    cout << "La ruta más barata es: " << endl;
    for (int i = 0; i < nciudades; i++)
    {
        cout << "Ciudad " << ruta[i] + 1 << " --> ";
    }
    cout << "Ciudad inicial " << ruta[0] + 1;
    cout << endl;

    cout << "El precio de la ruta es: " << precio_total << endl;

/***************************************************************************/
    //DESTRUCCION: Libero la memoria dinámica reservada para la matriz
    DestruyeMatriz (precios);
    delete [] ruta;

    return 0;
}
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

/***************************************************************************/
/***************************************************************************/
// Devuelve el número de la ciudad de destino (columna) con el menor precio
// dada una ciudad de salida (fila).
// Garantiza que dicha ciudad de llegada sea distinta a la ciudad de salida
// y que no esté contenida en el vector ruta (ciudades ya visitadas)

int menorprecio(const Matriz2D & precios, int ciudad_salida,
				int *ruta, int visitadas)
{
	int ciudad_llegada = 0;
	int	menorprecio = precios.datos[ciudad_salida][0];

    // Voy columna por columna comparando precios
	for (int col = 0; col < precios.cols; col++)
	{
		// Compruebo que no esté comparando una ciudad ya visitada
		// O que ciudad_llegada = ciudad_salida, en tal caso, paso al siguiente
		bool siguiente = false;

		for (int i = 0; i < visitadas && !siguiente; i++)
		{
			if (ruta[i] == col || col == ciudad_salida)
				siguiente = true;
		}

		// Si no ha habido ningún problema, calculo el menor
		if (!siguiente)
		{
            // Si el precio de ir a la ciudad n "col" es menor que menorprecio
            // O si menorprecio=0 actualizo el menorprecio y ciudad_llegada
			if(precios.datos[ciudad_salida][col] < menorprecio || !menorprecio)
			{
				ciudad_llegada = col;
				menorprecio = precios.datos[ciudad_salida][col];
			}
		}
	}

	return ciudad_llegada;
}
