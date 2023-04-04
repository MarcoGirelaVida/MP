/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// MARCO GIRELA VIDA
//
// RELACION DE PROBLEMAS 1
//
// Programa que, dada una cadena de caracteres, cuenta el número de palabras
// de la misma y almacena la inicial de cada palabra en un array de punteros.
// 
//
// Fichero: I_EncuentraInicioPalabras.cpp
//
/***************************************************************************/
/***************************************************************************/

#include "MiCadenaClasica.h"
#include <iostream>

using namespace std;


int main()
{
// DECLARACIÓN DE VARIABLES

    const int MAX_CARACTERES = 100;
    const int MAX_PALABRAS = 20;
    char la_cadena[MAX_CARACTERES];
    char * las_palabras[MAX_PALABRAS];
    int n_palabras;


// INPUT: Pido la cadena a procesar
    do{

        cout << "Introduzca la cadena a procesar: " << endl;
        cin.getline(la_cadena, MAX_CARACTERES);

    }while(longitud_cadena(la_cadena) == 0);

    cout << endl << endl;
    


// PROCESAMIENTO: Llamo a la función encuentra_palabras
     
    n_palabras = encuentra_palabras(las_palabras, la_cadena);



// COMPROBACIÓN: Compruebo que el usuario no haya superado las 20 palabras max
// En caso de haberlas superado, advierto de las posibles consecuencias.

    if( encuentra_palabras(las_palabras, la_cadena) == 20 )
    {
        cout << "ERROR: Se alcanzaron las palabras máximas, si escribió ";
        cout << "más de 20 estas NO se tendrán en cuenta." << endl;
    }


// OUTPUT: Muestro el número de palabras y las iniciales
    if (n_palabras == 0)
    {
        cout << "La cadena introducida no contiene palabras";
    }
    else
    {
        cout << "Nº Palabras= " << n_palabras << endl;
        cout << endl << endl;


        cout << "Las iniciales son: " << endl << endl;

        for (int i=0; i < n_palabras; i++)
            cout << *(*(las_palabras+i)) << " ";
        
        cout << endl << endl;
    }


    return (0);
}