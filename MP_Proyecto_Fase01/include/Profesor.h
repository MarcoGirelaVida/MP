/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// AUTOR: MARCO GIRELA VIDA
// GRUPO: 1ºB
// FECHA: 08/04/2023
//
// PROYECTO FASE 1
//
// Fichero: Profesor.h
/*****************************************************************************/

#ifndef PROFESOR_H
#define PROFESOR_H

#include <string>
#include "Fecha.h"

using namespace std;

/***************************************************************************/
/***************************************************************************/
class Profesor
{

private:

    string dni;
    string nombre;
    string apellidos;
    Fecha fechanacimento;

public:

/***************************************************************************/
// Constructor por defecto

    Profesor();

/***************************************************************************/
// Constructor con argumentos

    Profesor(string arg_dni, string arg_nombre,
            string arg_apellidos, string arg_fechanacimiento);

/***************************************************************************/
// Métodos get

    string getDni();
    string getNombre();
    string getApellidos();
    string getFechaNacimiento();

/***************************************************************************/
// Métodos set

    void setDni(string arg_dni);
    void setNombre(string arg_nombre);
    void setApellidos(string arg_apellidos);
    void setFechaNacimiento(string arg_fechanacimiento);

/***************************************************************************/
// Método ToString

    string ToString();

};

#endif