/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// AUTOR: MARCO GIRELA VIDA
// GRUPO: 1ºB
// FECHA: 08/04/2023
//
// PROYECTO FASE 1
//
//  
// 
//
// Declaraciones en: Fecha.h
//
// Fichero: Fecha.cpp
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>

#include "Fecha.h"

using namespace std;

/***************************************************************************/
// Constructor por defecto

Fecha()
{
    dia = 0;
    mes = 0;
    anyo = 0;
}

/***************************************************************************/
// Constructor con argumentos

Fecha(int d, int m, int a)
{
    dia = d;
    mes = m;
    anyo = a;
}

/***************************************************************************/
// Métodos get

int getDia()
{
    return dia;
}

int getMes()
{
    return mes;
}

int getAnyo()
{
    return anyo;
}

/***************************************************************************/
// Métodos set

void setDia(int d)
{
    dia = d;
}

void setMes(int m)
{
    mes = m;
}

void setAnyo(int a)
{
    anyo = a;
}

// Transforma una fecha en formato string a un objeto Fecha
void setFecha(string arg_fecha)
{
    int d, m, a;
    string tmp;
    int i = 0;

    while(arg_fecha[i] != '/')
    {
        tmp += arg_fecha[i];
        i++;
    }
    d = stoi(tmp);
    tmp = "";

    i++;

    while(arg_fecha[i] != '/')
    {
        tmp += arg_fecha[i];
        i++;
    }
    m = stoi(tmp);
    tmp = "";

    i++;

    while(i < arg_fecha.length())
    {
        tmp += arg_fecha[i];
        i++;
    }
    a = stoi(tmp);
    tmp = "";

    setDia(d);
    setMes(m);
    setAnyo(a);
}

/***************************************************************************/
// Método ToString

string ToString()
{
    string fecha;
    
    fecha += to_string(dia) + "/";
    fecha += to_string(mes) + "/";
    fecha += to_string(anyo);

    return fecha;
}
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
