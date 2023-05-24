/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// AUTOR: MARCO GIRELA VIDA
// GRUPO: 1ºB
// RELACION DE PROBLEMAS 6
//
//
// flujo_inchero: MensajesOculto-2.cpp
//
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <Matriz2D.h>
#include "Secuencia_string.h"

using namespace std;

/***************************************************************************/
int main(int argc, char * argv[])
{
    // Asociación de flujos de entrada a fichero

    // Flujo de entrada del fichero de texto base
    ifstream fi; 
    fi.open(argv[1]);
    if (!fi)
    {
        cerr << "Error: no pudo abrirse " << argv[1] << endl;
        exit (1);
    }

    // Flujo de entrada de la ubicación de las palabras
    ifstream fi2; 
    fi2.open(argv[1]);
    if (!fi2)
    {
        cerr << "Error: no pudo abrirse " << argv[1] << endl;
        exit (1);
    }

    //.......................................................................//
    // Almaceno los datos del fichero2 en una matriz 2D para poder manipularlos
    string fila, palabra;
    int contador_palabras = 0;
    Matriz2D base_datos_palabras = Matriz2D();

    while (fi2 >> fila >> palabra)
    {
        //Creo una secuencia para almacenar la localización de la palabra i
        // El cuarto elemento es para almacenar la palabra secreta asociada
        Secuencia localizador_palabra(3);
        localizador_palabra.Valor(1) = contador_palabras;
        localizador_palabra.Valor(2) = stoi(fila);
        localizador_palabra.Valor(3) = stoi(palabra);

        base_datos_palabras.Aniade(localizador_palabra);
        contador_palabras++;
    }
    
    // Reordeno la matriz de menor a mayor basandome en la columna 2
    // Para poder leer el fichero 1 secuencialmente
    base_datos_palabras.OrdenaMatrizMenorMayor(2);
    // Cierro el fichero 2, pues ya no lo necesito más
    fi2.close();

    //.......................................................................//
    // Busco las palabras secretas en el fichero 2
    Secuencia_string frase_secreta(contador_palabras);

    for (int i = 1; i <= contador_palabras; i++)
    {
        getline(fi, fila);
        istringstream iss(fila);

        for (int j = 0; j < base_datos_palabras(i,3); j++)
        {
            iss >> palabra;
        }

        frase_secreta.Valor(base_datos_palabras(i,1)+1) = palabra;
    }
    
    // Muestro la frase secreta
    cout << "La frase secreta es: " << frase_secreta.ToString() << endl;

    return 0;
}