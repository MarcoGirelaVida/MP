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
        int dia = 0;
        int mes = 0;
        int anyo = 0;

        string Mes_toString() const;

    public:
/***************************************************************************/
// Constructor por defecto

        Fecha();

/***************************************************************************/
// Constructor con argumentos

        Fecha(int d, int m, int a);

/***************************************************************************/
// Métodos get

        int getDia() const;
        int getMes() const;
        int getAnyo() const;

/***************************************************************************/
// Métodos set

        void setDia(int d);
        void setMes(int m);
        void setAnyo(int a);
        void setFecha(string arg_fecha);

/***************************************************************************/
// Método clona

        void Clona(const Fecha & origen);

/***************************************************************************/
// Método ToString

        string ToString(bool mes_string = false) const;
};
#endif