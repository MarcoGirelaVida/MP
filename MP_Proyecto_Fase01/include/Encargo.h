/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// AUTOR: MARCO GIRELA VIDA
// GRUPO: 1ºB
// FECHA: 08/04/2023
//
// PROYECTO FASE 1
//
// Fichero: Encargo.h
/*****************************************************************************/

#ifndef ENCARGO_H
#define ENCARGO_H

#include <string>

using namespace std;

/***************************************************************************/
/***************************************************************************/

class Encargo
{
    private:
        string codigo;
        string descripcion;
        string fecha;
        string dniProfesor;
        string idDepartamento;

    public:
/***************************************************************************/
// Constructor por defecto

        Encargo();

/***************************************************************************/
// Constructor con argumentos

        Encargo(string cod, string desc, string fecha, string dni, string id);

/***************************************************************************/
// Métodos get

        string getCodigo();
        string getDescripcion();
        string getFecha();
        string getDniProfesor();
        string getIdDepartamento();

/***************************************************************************/
// Métodos set

        void setCodigo(string cod);
        void setDescripcion(string desc);
        void setFecha(string fecha);
        void setDniProfesor(string dni);
        void setIdDepartamento(string id);

/***************************************************************************/
// Método ToString

        string ToString();

};
#endif