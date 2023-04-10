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

#include <cstring>

#include "Adscripcion.h"

using namespace std;

/***************************************************************************/
// Constructor por defecto

Adscripcion :: Adscripcion()
{
    DNI = "nullDNI";
    Id_depto = "nullId_depto";
}

/***************************************************************************/
// Constructor con argumentos

Adscripcion :: Adscripcion(string linea, char delimitador)
{
    string tmp = "";
    int i = 0;
    
    // Leo el primer elemento del string (dni)
    while(linea[i] != delimitador)
    {
        tmp += linea[i];
        i++;
    }

    // Guardo tmp en el atributo dni de la clase
    DNI = tmp;
    tmp = "";

    i++;

    //.....................................................................
    // Leo el segundo elemento del string (id_dtpo)

    while(linea[i] != delimitador)
    {
        tmp += linea[i];
        i++;
    }

    // Guardo tmp en el atributo id_dpto de la clase
    Id_depto = tmp;

}

/***************************************************************************/
// Métodos get

string Adscripcion :: getDniProfesor()
{
    return DNI;
}

string Adscripcion :: getIdDepartamento()
{
    return Id_depto;
}

/***************************************************************************/
// Métodos set

void Adscripcion :: setDniProfesor(string dni)
{
    DNI = dni;
}

void Adscripcion :: setIdDepartamento(string id)
{
    Id_depto = id;
}

/***************************************************************************/
// Método ToString

string Adscripcion :: ToString()
{   
    string cadena;
    
    cadena += DNI;
    cadena += " ";
    cadena += Id_depto + "\n";

    return cadena;
}
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
