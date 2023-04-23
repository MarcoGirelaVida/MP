/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// AUTOR: MARCO GIRELA VIDA
// GRUPO: 1ºB
// FECHA: 08/04/2023
//
// PROYECTO FASE 1
//
// Fichero: utils.h
/*****************************************************************************/

#ifndef UTILS_PROYECTOI
#define UTILS_PROYECTOI

#include <string>

using namespace std;

// Posibles tipos de alineaciones, por defecto será AlinIzquierda
enum class TipoAlineacion {AlinIzquierda, AlinCentro, AlinDerecha};

/***************************************************************************/
/***************************************************************************/
//Convierte el dato numero a un string con num_casillas casillas, que con-
//tiene el valor textual de numero. Si num_casillas es mayor que el número de
//dígitos de entero se rellena (por la izquierda) con el carácter relleno.
string FormatInt (int numero, int num_casillas, char relleno=' ');

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
                    int num_dec, char relleno=' ');

/***************************************************************************/
/***************************************************************************/
//Convierte el dato string la_cadena a un string con num_casillas casi-
//llas, rellenando (si procede, por la izquierda) con el carácter relleno.
//alineacion indica el ajuste o justificación de la_cadena en el espacio indi-
//cado por num_casillas.
string FormatString (string la_cadena, int num_casillas,
TipoAlineacion alineacion = TipoAlineacion::AlinIzquierda,
char relleno=' ');

/***************************************************************************/
/***************************************************************************/
// Método stoptr: Pasa un string a un puntero char
// Recibe una referencia a un string y una referencia a un puntero char

void stoptr(string &str, char * &atributo);


#endif