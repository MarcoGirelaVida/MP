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
        int categoria;  // Categoría del profesor (valor entre 1 y 5)
        double creditos; // Créditos asociados a la categoría

    public:
/***************************************************************************/
// Constructor por defecto

        Encargo();

/***************************************************************************/
// Constructor con argumentos

        Encargo(string linea, char delimitador);

/***************************************************************************/
// Métodos get

        int getCategoria() const;
        int getCreditos() const;

/***************************************************************************/
// Métodos set

        void setCategoria(int cat);
        void setCreditos(double cred);

/***************************************************************************/
// Método ToString

        string ToString();

/***************************************************************************/
// Método clona

        void Clona(const Encargo &origen);

};
#endif