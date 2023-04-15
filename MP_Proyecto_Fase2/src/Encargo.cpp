/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// AUTOR: MARCO GIRELA VIDA
// GRUPO: 1ºB
// FECHA: 08/04/2023
//
// PROYECTO FASE 1
//
//  
// 
//
// Declaraciones en: Encargo.h
//
// Fichero: Encargo.cpp
//
/***************************************************************************/
/***************************************************************************/

#include <cstring>
#include <iostream>

#include "Encargo.h"
#include "utils.h"

using namespace std;

/***************************************************************************/
// Constructor por defecto

Encargo :: Encargo()
{
    categoria = 0;
    creditos = 0;
}

/***************************************************************************/
// Constructor con argumentos


Encargo :: Encargo(string linea, char delimitador)
{
        string tmp = "";
        int i = 0;
        
        // Leo el primer elemento del string (categoria)
        while(linea[i] != delimitador)
        {
            tmp += linea[i];
            i++;
        }
        i++;

        // Almaceno tmp en el atributo categoria de la clase
        categoria = stoi(tmp);
        tmp = "";
    
        // Leo el segundo elemento del string (creditos)
        while(linea[i] != delimitador)
        {
            tmp += linea[i];
            i++;
        }
    
        // Almaceno tmp en el atributo creditos de la clase
        creditos = stod(tmp);
}

/***************************************************************************/
// Métodos get

int Encargo :: getCategoria()
{
    return categoria;
}
int Encargo :: getCreditos()
{
    return creditos;
}

/***************************************************************************/
// Métodos set

void Encargo :: setCategoria(int cat)
{
    if (cat < 1 || cat > 5)
    {
        cerr << "Error: La categoria debe estar entre 1 y 5" << endl;
        exit(1);
    }
    
    categoria = cat;
}

void Encargo :: setCreditos(double cred)
{
    if (cred < 0)
    {
        cerr << "Error: Los creditos deben ser positivos" << endl;
        exit(1);
    }
    creditos = cred;
}

/***************************************************************************/
// Método ToString

string Encargo :: ToString()
{
    // Formateo los decimales
    string cred = FormatDouble(creditos,4,2);

    string cadena;
    cadena += " " + to_string(categoria) + " ";
    cadena += FormatString(cred, 5 ,TipoAlineacion::AlinDerecha);
    cadena += "\n";

    return cadena;
}

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
