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
// Declaraciones en: Departamento.h
//
// Fichero: Departamento.cpp
//
/***************************************************************************/
/***************************************************************************/

#include <cstring>
#include <string>
#include <iostream>

#include "Departamento.h"
#include "utils.h"

using namespace std;

/***************************************************************************/
/***************************************************************************/
// Constructor por defecto

Departamento :: Departamento()
{
    Nombre = "nullNombre";
    Id_depto = "nullId_depto";
}

/***************************************************************************/
// Constructor con argumentos: recibe un string con los datos del departamento
// y un char con el delimitador que separa la clave primaria y secundaria.

Departamento :: Departamento(string linea, char delimitador)
{
    string tmp = "";
    int i = 0;

    // Almaceno la clave primaria en el string temporal
    tmp += "(";

    while(linea[i] != delimitador)
    {
        tmp += linea[i];
        i++;
    }

    tmp += ")";
    i++;

    // Reformateo el string temporal y lo guardo en el atributo de la clase
    Id_depto = tmp;
    Id_depto = FormatString(Id_depto, 6);

    //.......................................................................
    // Almaceno la clave secundaria en el string temporal
    tmp = "";

    while(linea[i] != delimitador)
    {
        tmp += linea[i];
        i++;
    }

    // Guardo la clave secundaria en el atributo de la clase
    Nombre = tmp;

}


/***************************************************************************/
// Métodos get

string Departamento :: getNombre()
{
    return Nombre;
}

string Departamento :: getId()
{
    return Id_depto;
}

/***************************************************************************/
// Métodos set

void Departamento :: setNombre(string nombre)
{
    Nombre = nombre;
}

void Departamento :: setId(string id)
{
    Id_depto = id;
}

/***************************************************************************/
// Método ToString

string Departamento :: ToString()
{   
    string cadena;

    cadena += Id_depto + "    ";
    cadena += Nombre + "\n";

    return cadena;
}

/***************************************************************************/
/***************************************************************************/
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
