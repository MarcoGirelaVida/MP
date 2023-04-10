/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// AUTOR: MARCO GIRELA VIDA
// GRUPO: 1ºB
// FECHA: 08/04/2023
//
// PROYECTO FASE 1
//
// Fichero: Fecha.h
/*****************************************************************************/

#ifndef FECHA_H
#define FECHA_H
#include <string>

using namespace std;

/***************************************************************************/
/***************************************************************************/
// Clase "Fecha"
class Fecha
{
    private:
        int dia;
        int mes;
        int anyo;

    public:
/***************************************************************************/
// Constructor por defecto

        Fecha();

/***************************************************************************/
// Constructor con argumentos

        Fecha(int d, int m, int a);

/***************************************************************************/
// Métodos get

        int getDia();
        int getMes();
        int getAnyo();

/***************************************************************************/
// Métodos set

        void setDia(int d);
        void setMes(int m);
        void setAnyo(int a);

/***************************************************************************/
// Método ToString

        string ToString();
};
#endif