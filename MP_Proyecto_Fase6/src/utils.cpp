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
/*
    if (num_casillas < num_digitos)
    {
        cerr << "Error: num_casillas < num_digitos" << endl;
        exit(1);
    }
*/
    //Si num_casillas es mayor que el num_digitos
    //se rellena por la izquierda con relleno.
    if (num_digitos < num_casillas)
    {
        for (int i = 0; i < num_casillas-num_digitos; i++)
        {
            strnumero = relleno + strnumero;
        }
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
    // Número en formato string
    string str_numero = to_string(numero);

    // Bucle para eliminar los ceros a la izquierda generados por el to_string
    int i = str_numero.size() - 1;
    while (str_numero[i]=='0')
    {
        str_numero.erase(i);
        i--;
    }

    // Numero de dígitos de la parte entera/decimal
    int cifras_parte_int = to_string((int)numero).size();
    int cifras_parte_dec = str_numero.size() - cifras_parte_int - 1;

    // Número de dígitos del número
    int num_digitos = num_dec + cifras_parte_int + 1;

    //...............................................................
    // Si num_dec es 0, no se muestra el punto
    if (num_dec == 0)
    {
        str_numero = to_string((int)numero);
        num_digitos--;
    }

    //...............................................................
    // Si num_dec es menor que cifras_parte_dec, se rellena con ceros
    else if (cifras_parte_dec < num_dec)
    {
        for (int i = 0; i < num_dec-cifras_parte_dec; i++)
        {
            str_numero += "0";
        } 
    }
    
    //...............................................................
    // Si num_digitos es < num_casillas relleno por la izquierda con relleno
    if (num_digitos < num_casillas)
    {
        for (int i = 0; i < num_casillas-num_digitos; i++)
        {
            str_numero = relleno + str_numero;
        }
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
    int longitud = la_cadena.size();
/*
    // Compruebo si num_casillas es menor que la longitud de la cadena
    if (num_casillas < longitud)
    {
        cerr << "Error: num_casillas < longitud" << endl;
        exit(1);
    }
*/
    //...............................................................
    // Relleno si así se require, según la alineación
    if (num_casillas > longitud)
    {
        switch (alineacion)
        {
            // Si se elige AlinIzquierda, se rellena por la derecha
            case TipoAlineacion::AlinIzquierda:
            {
                for (int i = 0; i < num_casillas-longitud; i++)
                {
                    la_cadena += relleno;
                }

                break;
            }

            // Si se elige AlinCentro, se rellena por la izquierda y derecha
            case TipoAlineacion::AlinCentro:
            {
                for (int i = 0; i < (num_casillas - longitud)/2; i++)
                {
                    la_cadena = relleno + la_cadena;
                }
                
                int sobrante = num_casillas - la_cadena.size();

                for (int i = 0; i < sobrante; i++)
                {
                    la_cadena += relleno;
                }

                break;
            }

            // Si se elige AlinDerecha, se rellena por la izquierda
            case TipoAlineacion::AlinDerecha:
            {
                for (int i = 0; i < num_casillas-longitud; i++)
                {
                    la_cadena = relleno + la_cadena;
                }

                break;
            }
        }
    }

    return la_cadena;
}

/***************************************************************************/
/***************************************************************************/
// Método stoptr: Pasa un string a un puntero char
// Recibe una referencia a un string y una referencia a un puntero char

void stoptr(string &str, char * &atributo)
{
    if (atributo != nullptr)
    {
        delete [] atributo;
        atributo = nullptr;
    }

    atributo = new char [str.size() + 1];

    for (int i = 0; i < str.size(); i++)
    {
        atributo[i] = str[i];
    }

    atributo[str.size()] = '\0';
}

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
