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
// Declaraciones en: Adscripcion.h
//
// Fichero: Adscripcion.cpp
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>

#include "Adscripcion.h"

using namespace std;

/***************************************************************************/
// Constructor por defecto

Adscripcion :: Adscripcion()
{
    dniProfesor = "nulldniProfesor";
    idDepartamento = "nullidDepartamento";
}

/***************************************************************************/
// Constructor con argumentos

Adscripcion :: Adscripcion(string dni, string id)
{
    dniProfesor = dni;
    idDepartamento = id;
}

/***************************************************************************/
// Métodos get

string Adscripcion :: getDniProfesor()
{
    return dniProfesor;
}

string Adscripcion :: getIdDepartamento()
{
    return idDepartamento;
}

/***************************************************************************/
// Métodos set

void Adscripcion :: setDniProfesor(string dni)
{
    dniProfesor = dni;
}

void Adscripcion :: setIdDepartamento(string id)
{
    idDepartamento = id;
}

/***************************************************************************/
// Método ToString

string Adscripcion :: ToString()
{   
    string cadena
    
    cadena += "DNI del profesor: " + dniProfesor;
    cadena += " --> ";
    cadena += "ID del departamento: " + idDepartamento;

    return cadena;
}
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
