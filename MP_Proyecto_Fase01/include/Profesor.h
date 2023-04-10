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

    string DNI;
    string Nombre;
    string Apellidos;
    Fecha FechaNacimiento;
    int Categoria;

public:

/***************************************************************************/
// Constructor por defecto

    Profesor();

/***************************************************************************/
// Constructor con argumentos

    Profesor(string linea, char delimitador);

/***************************************************************************/
// Métodos get

    string getDni();
    string getNombre();
    string getApellidos();
    string getFechaNacimiento();
    int getCategoria();

/***************************************************************************/
// Métodos set

    void setDni(string arg_DNI);
    void setNombre(string arg_Nombre);
    void setApellidos(string arg_Apellidos);
    void setFechaNacimiento(string arg_fechanacimiento);
    void setCategoria(int arg_categoria);

/***************************************************************************/
// Método ToString

    string ToString();

};

#endif