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
// Declaraciones en: Adscripcion.h
//
// Fichero: Adscripcion.cpp
//
/***************************************************************************/
/***************************************************************************/

#include <cstring>
#include "utils.h"
#include "Adscripcion.h"

using namespace std;

/***************************************************************************/
// Constructor por defecto

Adscripcion :: Adscripcion()
{
    DNI = nullptr;
    Id_depto = nullptr;
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
    string dni = tmp;
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
    string id = tmp;

    setDniProfesor(dni);
    setIdDepartamento(id);
}

/***************************************************************************/
// Métodos get

string Adscripcion :: getDniProfesor()
{
    return ptrtos(DNI);
}

string Adscripcion :: getIdDepartamento()
{
    return ptrtos(Id_depto);
}

/***************************************************************************/
// Métodos set

void Adscripcion :: setDniProfesor(string dni)
{
    stoptr(dni, DNI);
}

void Adscripcion :: setIdDepartamento(string id)
{
    stoptr(id, Id_depto);
}

/***************************************************************************/
// Método ToString

string Adscripcion :: ToString()
{   
    string cadena;
    
    cadena += ptrtos(DNI);
    cadena += " ";
    cadena += ptrtos(Id_depto) + "\n";

    // Llamo al destructor porque por ahora, solo necesito mostrar el string
    // y no vuelvo a usar los datos almacenados
    Adscripcion();

    return cadena;
}

/***************************************************************************/
// Destructor

Adscripcion :: ~Adscripcion()
{
    delete [] DNI;
    DNI = nullptr;
    delete [] Id_depto;
    Id_depto = nullptr;
}

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
