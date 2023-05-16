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
    string flujo;
    int contador_lineas = 0;

    while (getline(cin,flujo))
    {
        contador_lineas++;
        int contador_palabras = 0;

        istringstream iss;
        iss.str(flujo);

        while (iss >> flujo)
        {
            contador_palabras++;
        }

        cout << "Linea  " << contador_lineas << ":  " <<\
                             contador_palabras << " palabras\n";
    }
    
}

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
