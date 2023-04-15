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
// Declaraciones en: Profesor.h
//
// Fichero: Profesor.cpp
//
/***************************************************************************/
/***************************************************************************/

#include <cstring>
#include <iostream>

#include "Profesor.h"
#include "Fecha.h"
#include "utils.h"

using namespace std;

/***************************************************************************/
/***************************************************************************/
// Constructor por defecto

Profesor :: Profesor()
{
    DNI = nullptr;
    Nombre = nullptr;
    Apellidos = nullptr;
    FechaNacimiento = Fecha();
    Categoria = 0;
}


/***************************************************************************/
// Constructor con argumentos

Profesor :: Profesor(string linea, char delimitador)
{

    string dni, nombre, apellidos, fechanacimiento, categoria;
    string tmp = "";
    int i = 0;

    // Leo el DNI
    while(linea[i] != delimitador)
    {
        tmp += linea[i];
        i++;
    }

    // Almaceno el DNI en un string temporal
    dni = tmp;
    tmp = "";

    i++;

    //.......................................................................
    // Leo el nombre
    while(linea[i] != delimitador)
    {
        tmp += linea[i];
        i++;
    }

    // Almaceno el nombre en un string temporal
    nombre = tmp;
    tmp = "";

    i++;

    //.......................................................................
    // Leo los apellidos
    while(linea[i] != delimitador)
    {
        tmp += linea[i];
        i++;
    }

    // Almaceno los apellidos en un string temporal
    apellidos = tmp;
    tmp = "";

    i++;

    //.......................................................................
    // Leo la fecha de nacimiento
    while(linea[i] != delimitador)
    {
        tmp += linea[i];
        i++;
    }

    
    // Almaceno la fecha en un string temporal
    fechanacimiento = tmp;
    tmp = "";

    i++;

    //.......................................................................
    // Leo la categoria
    while(linea[i] != delimitador)
    {
        tmp += linea[i];
        i++;
    }

    // Almaceno la categoria en un string temporal
    categoria = tmp;
    tmp = "";

    i++;
   
    //.......................................................................
    // Asigno los valores leidos a los atributos de la clase
    setDni(dni);
    setNombre(nombre);
    setApellidos(apellidos);
    setFechaNacimiento(fechanacimiento);
    setCategoria(stoi(categoria));
}

/***************************************************************************/
/***************************************************************************/
// Métodos get: Devuelven el valor de los atributos

string Profesor :: getDni()
{
    return ptrtos(DNI);
}

string Profesor :: getNombre()
{
    return ptrtos(Nombre);
}

string Profesor :: getApellidos()
{
    return ptrtos(Apellidos);
}

string Profesor :: getFechaNacimiento()
{
    return FechaNacimiento.ToString();
}

int Profesor :: getCategoria()
{
    return Categoria;
}

/***************************************************************************/
/***************************************************************************/
// Métodos set: Modifican el valor de los atributos

void Profesor :: setDni(string arg_DNI)
{
    if (arg_DNI.length() != 9)
    {
        cout << "Error: El DNI debe tener 9 caracteres" << endl;
        exit(1);
    }
    
    stoptr(arg_DNI, DNI);
}

void Profesor :: setNombre(string arg_nombre)
{
    stoptr(arg_nombre, Nombre);
}

void Profesor :: setApellidos(string arg_Apellidos)
{
    stoptr(arg_Apellidos, Apellidos);
}

void Profesor :: setFechaNacimiento(string arg_FechaNacimiento)
{
    //La comprobación de la validez de este argumento ya se hace en clase Fecha
    FechaNacimiento.setFecha(arg_FechaNacimiento);
}

void Profesor :: setCategoria(int arg_Categoria)
{
    if (arg_Categoria < 1 || arg_Categoria > 5)
    {
        cerr << "Error: La categoria debe estar entre 1 y 5" << endl;
        exit(1);
    }
    
    Categoria = arg_Categoria;
}

/***************************************************************************/
/***************************************************************************/
// Método ToString: Devuelve una cadena con los valores de los atributos

string Profesor :: ToString()
{
    string cadena;
    cadena += ptrtos(DNI) + " ";
    cadena += FormatString((ptrtos(Apellidos) + ", " + ptrtos(Nombre)),32);
    cadena += FechaNacimiento.ToString();
    cadena += "   " + to_string(Categoria);
    cadena += "\n";

    return cadena;
}
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////