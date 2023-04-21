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

    char * DNI = nullptr;
    char * Nombre = nullptr;
    char * Apellidos = nullptr;
    Fecha FechaNacimiento;
    int Categoria;

public:

/***************************************************************************/
// Constructor por defecto

    Profesor();

/***************************************************************************/
// Constructor con argumentos

    Profesor(string linea, char delimitador = '*');

/***************************************************************************/
// Métodos get

    string getDni() const;
    string getNombre() const;
    string getApellidos() const;
    string getFechaNacimiento() const;
    int getCategoria() const;

/***************************************************************************/
// Métodos set

    void setDni(string arg_DNI = "");
    void setNombre(string arg_Nombre = "");
    void setApellidos(string arg_Apellidos = "");
    void setFechaNacimiento(string arg_fechanacimiento = "");
    void setCategoria(int arg_categoria);

/***************************************************************************/
// Método Clona
    
    void Clona (const Profesor & origen);

/***************************************************************************/
// Método ToString

    string ToString(bool mes_string = false) const;

// Destructor
    ~Profesor();
};
#endif