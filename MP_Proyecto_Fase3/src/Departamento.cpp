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
    setNombre();
    setId();
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
// Métodos get, dado que no quiero modificarlos, los declaro como const

string Departamento :: getNombre() const
{
    return Nombre;
}

string Departamento :: getId() const
{
    return Id_depto;
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

string Departamento :: ToString() const
{   
    string cadena = "";

    if (Id_depto && Nombre)
    {
        cadena += (string) Id_depto + "    ";
        cadena += (string) Nombre + "\n";
    }

    return cadena;
}

/***************************************************************************/
// Método Clona

void Departamento :: Clona(Departamento & origen)
{
    setId(origen.getId());
    setNombre(origen.getNombre());
}

/***************************************************************************/
// Destructor
Departamento :: ~Departamento()
{
    if (Nombre) delete [] Nombre;
    Nombre = nullptr;

    if (Id_depto) delete [] Id_depto;
    Id_depto = nullptr;
}
/***************************************************************************/
/***************************************************************************/
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
