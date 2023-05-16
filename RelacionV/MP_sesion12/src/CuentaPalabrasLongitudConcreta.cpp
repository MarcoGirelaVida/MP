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
#include <string>

using namespace std;

int main(int argc, char * argv[])
{
    // Valor por defecto es 0
    int longitud_palabra = 0;
    int contador_palabras = 0;
    string flujo;

    if (argc > 1)
    {
        longitud_palabra = atoi(argv[1]);
    }

    while (cin >> flujo)
    {
        if (flujo.size() == longitud_palabra)
        {
            contador_palabras++;
            cout << flujo << endl;
        }
    }
    
    cout << "Hay: " << contador_palabras\
         << " palabras de longitud: " << longitud_palabra << endl;


    return 0;
}