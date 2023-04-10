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
// Declaraciones en: Profesor.h
//
// Fichero: Profesor.cpp
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>

#include "Profesor.h"

using namespace std;

/***************************************************************************/
/***************************************************************************/
// Constructor por defecto

Profesor :: Profesor()
{
    dni = "nullDNI";
    nombre = "nullnombre";
    apellidos = "nullapellidos";
    fechanacimiento = Fecha();

}

/***************************************************************************/
// Constructor con argumentos

Profesor :: Profesor(string arg_dni, string arg_nombre,
                    string arg_apellidos, string arg_fechanacimiento)
{
    dni = arg_dni;
    nombre = arg_nombre;
    apellidos = arg_apellidos;
    fechanacimiento = fechanamiento.setFecha(arg_fechanacimiento));
}

/***************************************************************************/
// Métodos get

string Profesor :: getDni()
{
    return dni;
}

string Profesor :: getNombre()
{
    return nombre;
}

string Profesor :: getApellidos()
{
    return apellidos;
}

string Profesor :: getFechaNacimiento()
{
    return fechanacimiento;
}


/***************************************************************************/
// Métodos set

void Profesor :: setDni(string arg_dni)
{
    dni = arg_dni;
}

void Profesor :: setNombre(string arg_nombre)
{
    nombre = arg_nombre;
}

void Profesor :: setApellidos(string arg_apellidos)
{
    apellidos = arg_apellidos;
}

void Profesor :: setFechaNacimiento(string arg_fechanacimiento)
{
    fechanacimiento = arg_fechanacimiento;
}

/***************************************************************************/
// Método ToString

string Profesor :: ToString()
{
    string cadena;
    cadena += "DNI: " + dni;
    cadena += " Nombre: " + nombre;
    cadena += " Apellidos: " + apellidos;
    cadena += " Fecha de nacimiento: " + fechanacimiento;

    return cadena;
}

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
