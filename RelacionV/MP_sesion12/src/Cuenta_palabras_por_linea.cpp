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

using namespace std;

int main()
{
    string linea;
    string palabra;
    int contador_lineas = 0;

    while (getline(cin,linea))
    {
        contador_lineas++;
        int contador_palabras = 0;

        istringstream iss;
        iss.str(linea);

        while (iss >> palabra)
        {
            contador_palabras++;
        }

        cout << "Linea  " << contador_lineas << ":  " <<\
                             contador_palabras << " palabras\n";
    }
    
}

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
