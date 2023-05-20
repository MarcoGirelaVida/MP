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

using namespace std;

int main()
{
    string cadena;
    int contador_lineas_total = 0;
    int contador_lineas_vacias = 0;
    int contador_lineas_novacias = 0;

    while (getline(cin,cadena))
    {
        contador_lineas_total++;

        if (cadena.size())
            contador_lineas_novacias ++;
        else
            contador_lineas_vacias++;
        
        //cout << cadena << endl;
    }

    cout << endl;
    cout << "Lineas total: " << contador_lineas_total << endl;
    cout << "Lineas vacias: " << contador_lineas_vacias << endl;
    cout << "Lineas no vacias: " << contador_lineas_novacias << endl;
    
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
