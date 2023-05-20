/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// AUTOR: MARCO GIRELA VIDA
// GRUPO: 1ºB
// FECHA: 15/05/2023
//
// RELACION DE PROBLEMAS 5
//
//
// Fichero: 
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include <sstream> 
#include <string>

using namespace std;

int main()
{
    string flujo;
    int contador_lineas = 1;

    // Leo la primera linea, que solo debe contener "MATRIZ2D"
    getline(cin,flujo);
    if (flujo != "MATRIZ2D")
    {
        cerr << "Error: formato erroneo" << endl;
        cerr << "La primera linea debe ser única y contener solo MATRIZ2D\n";
        exit(1);
    }

    // Leo la segunda linea y almaceno el contenido en el flujo iss
    getline(cin,flujo);
    istringstream iss;
    iss.str(flujo);

    // Leo el número de filas
    // Si no da ningún argumento da excepción
    int fils = 0;
    if(iss >> flujo)
        // La función stoi dará excepción si no es un int
        fils = stoi(flujo);

    else{
        cerr << "Error: ningún argumento en la segunda linea, deben ser 2\n";
        exit(1);
    }

    // Leo el número de columnas
    // Si da solo un argumento da excepción
    int cols = 0;
    if(iss >> flujo)
        cols = stoi(flujo);

    else{
        cerr << "Error: solo 1 argumento en la segunda linea, deben ser 2\n";
        exit(1);
    }

    // Si da más de dos argumentos en la segunda linea, da excepción
    if (iss >> flujo)
    {
        cerr << "Error: Más de dos argumentos en la segunda linea, deben ser 2"
             << endl;
        exit(1);
    }
    
    // Creo la matriz con los parámetros indicados
    int ** matriz;
    matriz = new int*[fils];
    for(int i = 0; i < fils; ++i)
        matriz[i] = new int[cols];

    // Leo las palabras restantes y las almaceno como elementos de la matriz.
    for (int i = 0; i < fils; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (cin >> flujo)
            {
                matriz[i][j] = stoi(flujo);
            }
            else
            {
                cerr << "Error: No se han proporcionado suficientes elementos"
                     << endl;
                exit(1);
            }  
        }
    }

    if(cin >> flujo)
    {
        cerr << "Error: Demasiados elementos proporcionados" << endl;
        exit(1);
    }
    else
        cout << "Enhorabuena!, Su matriz ha sido almacenada con éxito" << endl;
}
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
