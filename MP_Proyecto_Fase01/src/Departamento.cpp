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

#include <iostream>

#include "Departamento.h"

using namespace std;

/***************************************************************************/
/***************************************************************************/
// Constructor por defecto

Departamento :: Departamento()
{
    nombre_dpto = "nullnombre_dpto";
    Id_dpto = "nullId_dpto";
}

/***************************************************************************/
// Constructor con argumentos

Departamento :: Departamento(string nombre, string id)
{
    nombre_dpto = nombre;
    Id_dpto = id;
}


/***************************************************************************/
// Métodos get

string Departamento :: getNombre()
{
    return nombre;
}

string Departamento :: getId()
{
    return Id_dpto;
}

/***************************************************************************/
// Métodos set

void Departamento :: setNombre(string nombre)
{
    nombre_dpto = nombre;
}

void Departamento :: setId(string id)
{
    Id_dpto = id;
}

/***************************************************************************/
// Método ToString

string Departamento :: ToString()
{
    string cadena = "( " + Id_dpto + " )" + "    " + nombre_dpto + "\n";

    return cadena;
}

/***************************************************************************/
/***************************************************************************/
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
