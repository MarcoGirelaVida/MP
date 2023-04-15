/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// AUTOR: MARCO GIRELA VIDA
// GRUPO: 1ºB
// FECHA: 08/04/2023
//
// PROYECTO FASE 2
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
    Nombre = nullptr;
    Id_depto = nullptr;
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
    string id = tmp;
    id = FormatString(id, 6);

    //.......................................................................
    // Almaceno la clave secundaria en el string temporal
    tmp = "";

    while(linea[i] != delimitador)
    {
        tmp += linea[i];
        i++;
    }

    // Guardo la clave secundaria en el atributo de la clase
    string nombre = tmp;

    setId(id);
    setNombre(nombre);
}


/***************************************************************************/
// Métodos get

string Departamento :: getNombre()
{
    return ptrtos(Nombre);
}

string Departamento :: getId()
{
    return ptrtos(Id_depto);
}

/***************************************************************************/
// Métodos set

void Departamento :: setNombre(string nombre)
{
    stoptr(nombre, Nombre);
}

void Departamento :: setId(string id)
{
    stoptr(id, Id_depto);
}

/***************************************************************************/
// Método ToString

string Departamento :: ToString()
{   
    string cadena;

    cadena += ptrtos(Id_depto) + "    ";
    cadena += ptrtos(Nombre) + "\n";

    // LLamo al destructor puesto que no voy a usar más el objeto
    Departamento();

    return cadena;
}

/***************************************************************************/
// Destructor
Departamento :: ~Departamento()
{
    delete [] Nombre;
    Nombre = nullptr;
    delete [] Id_depto;
    Id_depto = nullptr;
}
/***************************************************************************/
/***************************************************************************/
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
