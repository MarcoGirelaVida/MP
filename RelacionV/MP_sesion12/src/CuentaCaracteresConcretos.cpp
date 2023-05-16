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
    // Valor por defecto es \0, esto lo hago para que en 
    // el condicional, si el caracter es cero (por defecto)
    // se cuenten todos los caracteres
    char caracter_a_contar = '\0';
    int contador_caracter = 0;
    char flujo;

    if (argc > 1)
    {
        caracter_a_contar = *argv[1];
    }
    
    while (cin.get(flujo))
    {
        if (flujo == caracter_a_contar || !caracter_a_contar)
        {
            contador_caracter++;
        }
    }
    
    cout << "Hay: " << contador_caracter << " caracteres " << caracter_a_contar << endl;
    return 0;
}