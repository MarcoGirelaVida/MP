/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// AUTOR: MARCO GIRELA VIDA
// GRUPO: 1ºB
// FECHA: xx/04/2023
//
// Funciones útiles para el proyecto I pertenecientes a libutils.a
// 
// Declaraciones en: utils.h
//
// Fichero: utils.cpp
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include <string>
#include <cstring>

#include "utils.h"

using namespace std;

/***************************************************************************/
/***************************************************************************/
//Convierte el dato numero a un string con num_casillas casillas, que con-
//tiene el valor textual de numero. Si num_casillas es mayor que el número de
//dígitos de entero se rellena (por la izquierda) con el carácter relleno.
// PRE: num_casillas >= num_digitos
string FormatInt (int numero, int num_casillas, char relleno)
{
    string strnumero = to_string(numero);
    int num_digitos = strnumero.size();

    if (num_casillas < num_digitos)
    {
        cerr << "Error: num_casillas < num_digitos" << endl;
        exit(1);
    }

    //Si num_casillas es mayor que el num_digitos
    //se rellena por la izquierda con relleno.
    if (num_digitos < num_casillas)
    {
        // (Se puede hacer con memmove pero la función insert es más elegante)
        strnumero.insert(0, num_casillas - num_digitos, relleno);
    }

    return strnumero;
}

/***************************************************************************/
/***************************************************************************/
//Convierte el dato numero a un string que contiene el valor textual de numero
//de acuerdo con el formato indicado según los valores de num_casillas y
//num_dec. Si hiciera falta, rellena los huecos con el carácter relleno.
//NOTAS:
//1. Si el número de casillas solicitado es mayor que el que se necesita, se
//completa el inicio de la parte entera con relleno.
//2. Si el número de decimales requerido es cero, NO se muestra el punto.
//3. Si el número de decimales requerido es mayor que el que se necesita se
//completa con ceros.

string FormatDouble (double numero, int num_casillas,
                    int num_dec, char relleno)
{
    string str_numero = to_string(numero);
    int parte_int = (int)numero;
    int parte_dec = str_numero.size() - parte_int - 1;
    int num_digitos = num_dec + parte_int + 1;

    // Si num_dec es 0, no se muestra el punto
    if (num_dec == 0)
    {
        str_numero = to_string(parte_int);
        num_digitos--;
    }
    // Si num_dec es menor que parte_dec, se rellena el sobrante con ceros
    else if (parte_dec < num_dec)
    {
        str_numero.insert(str_numero.size(),num_dec-parte_dec,'0');
    }
    
    // Si num_digitos es < num_casillas relleno por la izquierda con relleno
    if (num_digitos < num_casillas)
    {
        str_numero.insert(0, num_casillas - num_digitos, relleno);
    }

    return str_numero;
}

/***************************************************************************/
/***************************************************************************/
//Convierte el dato string la_cadena a un string con num_casillas casi-
//llas, rellenando (si procede, por la izquierda) con el carácter relleno.
//alineacion indica el ajuste o justificación de la_cadena en el espacio indi-
//cado por num_casillas.
// PRE: num_casillas >= longitud de la_cadena
string FormatString (string la_cadena, int num_casillas,
TipoAlineacion alineacion, char relleno)
{
    int longitud = la_cadena.length();

    // Compruebo si num_casillas es menor que la longitud de la cadena
    if (num_casillas < longitud)
    {
        cerr << "Error: num_casillas < longitud" << endl;
        exit(1);
    }

    // Relleno si así se require, según la alineación
    if (num_casillas > longitud)
    {
        switch (alineacion)
        {
            case TipoAlineacion::AlinIzquierda:
                la_cadena.insert(longitud, num_casillas - longitud, relleno);
                break;

            case TipoAlineacion::AlinCentro:
            {
                la_cadena.insert(longitud, (num_casillas - longitud)/2, relleno);
                int sobrante = num_casillas - la_cadena.size();
                la_cadena.insert(0, sobrante, relleno);
                break;
            }

            case TipoAlineacion::AlinDerecha:
                la_cadena.insert(0, num_casillas - longitud, relleno);
                break;
        }
    }

    return la_cadena;
}

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
