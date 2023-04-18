/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// AUTOR: MARCO GIRELA VIDA
// GRUPO: 1ºB
// FECHA: 08/04/2023
//
// PROYECTO FASE 1
//
// Fichero: Departamento.h
/*****************************************************************************/

#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H

#include <string>

using namespace std;

/***************************************************************************/
/***************************************************************************/
// Clase "Departamento"

class Departamento
{

private:
    char * Nombre = nullptr;
    char * Id_depto = nullptr;

public:
/***************************************************************************/
// Constructor por defecto

    Departamento();

/***************************************************************************/
// Constructor con argumentos

    Departamento(string linea, char delimitador = '*');

/***************************************************************************/
// Métodos get

    string getNombre() const;

    string getId() const;

/***************************************************************************/
// Métodos set

    void setNombre(string nombre);

    void setId(string id);

/***************************************************************************/
// Método ToString

    string ToString() const;

/***************************************************************************/
// Método Clona

    void Clona(Departamento & origen);

/***************************************************************************/
// Destructor

    ~Departamento();
};

#endif