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

#include <cstring>

#include "Fecha.h"

using namespace std;

/***************************************************************************/
// Constructor por defecto

Fecha :: Fecha()
{
    dia = 0;
    mes = 0;
    anyo = 0;
}

/***************************************************************************/
// Constructor con argumentos

Fecha :: Fecha(int d, int m, int a)
{
    dia = d;
    mes = m;
    anyo = a;
}

/***************************************************************************/
// Métodos get

int Fecha :: getDia()
{
    return dia;
}

int Fecha :: getMes()
{
    return mes;
}

int Fecha :: getAnyo()
{
    return anyo;
}

/***************************************************************************/
// Métodos set

void Fecha :: setDia(int d)
{
    dia = d;
}

void Fecha :: setMes(int m)
{
    mes = m;
}

void Fecha :: setAnyo(int a)
{
    anyo = a;
}

// Transforma una fecha en formato string a un objeto Fecha
void Fecha :: setFecha(string arg_fecha)
{
    int d, m, a;
    string tmp;
    int i = 0;

    // Leo el primer elemento del string (dia)
    while(arg_fecha[i] != '/')
    {
        tmp += arg_fecha[i];
        i++;
    }
    d = stoi(tmp);
    tmp = "";

    i++;

    // Leo el segundo elemento del string (mes)
    while(arg_fecha[i] != '/')
    {
        tmp += arg_fecha[i];
        i++;
    }
    m = stoi(tmp);
    tmp = "";

    i++;

    // Leo el tercer elemento del string (anyo)
    while(i < arg_fecha.length())
    {
        tmp += arg_fecha[i];
        i++;
    }
    a = stoi(tmp);
    tmp = "";

    // Asigno los valores leidos a los atributos de la clase
    setDia(d);
    setMes(m);
    setAnyo(a);
}

/***************************************************************************/
// Método ToString

string Fecha :: ToString()
{
    string fecha;
    
    fecha += to_string(dia) + "/";
    fecha += to_string(mes) + "/";
    fecha += to_string(anyo);

    return fecha;
}
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
