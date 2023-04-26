/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// AUTOR: MARCO GIRELA VIDA
// GRUPO: 1ºB
// FECHA: xx/04/2023
//
// RELACION DE PROBLEMAS 3
//
// Pruebas sobre la clase Cola
//
// Declaraciones en: Cola.h
//
// Fichero: Main_Cola.cpp
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include "Cola.h"
using namespace std;

int main()
{
    Cola c;
    int opcion;

    do
    {
        cout << "1. Añadir un valor\n";
        cout << "2. Extraer un valor\n";
        cout << "3. Consultar el elemento de la cabecera\n";
        cout << "4. Mostrar el estado de la cola\n";
        cout << "5. Salir\n";
        cout << "Elija una opción: ";
        cin >> opcion;

        switch (opcion)
        {

            case 1:
                int dato;
                cout << "Introduzca un valor: ";
                cin >> dato;
                c.Aniade(dato);
                break;

            case 2:
                    dato = c.sacavalor();
                    cout << "Valor extraído: " << dato << endl;
                break;

            case 3:
                    dato = c.Cabecera();
                    cout << "El valor de la cabecera es: " << dato << endl;

                break;

            case 4:
                if (c.EstaVacia())
                {
                    cout << "La cola está vacía" << endl;
                }
                else
                {
                    cout << "La cola tiene elementos" << endl;
                }
                break;

            case 5:
                break;

            default:
                cout << "Opción inválida" << endl;
                break;
        }
    }
    while (opcion != 5);
    
    return 0;
}
