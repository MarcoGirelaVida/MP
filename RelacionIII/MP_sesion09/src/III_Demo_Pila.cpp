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
// Pruebas sobre el la clase Pila
//
// Declaraciones en: Pila.h
//
// Fichero: Main_Pila.cpp
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include "Pila.h"
using namespace std;

int main()
{
    Pila p;
    int opcion;
    
    do
    {
        cout << "1. Añadir un valor\n";
        cout << "2. Extraer un valor\n";
        cout << "3. Consultar el elemento del tope\n";
        cout << "4. Mostrar el estado de la pila\n";
        cout << "5. Salir\n";
        cout << "Elija una opción: ";
        cin >> opcion;

        switch (opcion)
        {
            case 1:
                int dato;
                cout << "Introduzca un valor: ";
                cin >> dato;
                p.aniade(dato);
                break;

            case 2:
                    dato = p.sacavalor();
                    cout << "Valor extraído: " << dato << endl;
                break;

            case 3:
                    dato = p.Cabecera();
                    cout << "El valor del tope es: " << dato << endl;
                break;

            case 4:
                if (p.EstaVacia())
                {
                    cout << "La pila está vacía" << endl;
                }
                else
                {
                    cout << "La pila tiene elementos" << endl;
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
