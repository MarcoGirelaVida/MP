/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// AUTOR: MARCO GIRELA VIDA
// GRUPO: 1ºB
// FECHA: 08/04/2023
//
// PROYECTO FASE 1
//
// Fichero: Adscripcion.h
/*****************************************************************************/

#ifndef ADSCRIPCION_H
#define ADSCRIPCION_H

#include <string>

using namespace std;

/***************************************************************************/
/***************************************************************************/
// Clase "Adscripcion"
class Adscripcion
{

    private:
        char * DNI = nullptr;
        char * Id_depto = nullptr;

    public:
    
/***************************************************************************/
// Constructor por defecto

        Adscripcion();

/***************************************************************************/
// Constructor con argumentos

        Adscripcion(string linea, char delimitador = '*');

/***************************************************************************/
// Métodos get

        string getDniProfesor() const;

        string getIdDepartamento() const;

/***************************************************************************/
// Métodos set

        void setDniProfesor(string dni = "");

        void setIdDepartamento(string id = "");

/***************************************************************************/
// Método ToString

        string ToString();

/***************************************************************************/
// Método Clona

        void Clona(Adscripcion & origen);

/***************************************************************************/
// Destructor

        ~Adscripcion();

};
#endif