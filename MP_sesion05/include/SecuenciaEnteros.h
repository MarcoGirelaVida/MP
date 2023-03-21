/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// AUTOR: MARCO GIRELA VIDA
// GRUPO: 1ºB
// FECHA: xx/03/2023
//
// RELACION DE PROBLEMAS 1
//
// Declaraci�n de la clase SecuenciaEnteros_basico
//
// Fichero: SecuenciaEnteros_basico.h
//
/***************************************************************************/

#ifndef SECUENCIA_ENTEROS
#define SECUENCIA_ENTEROS

#include <iostream>
#include <string>
#include <cstring>
#include "GeneradorAleatorioEnteros.h"
#include "SecuenciaEnteros.h"
using namespace std;


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

class SecuenciaEnteros
{
private:

    static const int TAMANIO = 100; // Núm.casillas disponibles
    int vector_privado[TAMANIO];

    // PRE: 0 <= total_utilizados <= TAMANIO

    int total_utilizados; // Núm.casillas ocupadas

public:

    /***********************************************************************/
    // Constructor sin argumentos

    SecuenciaEnteros ();
    /*******************************************************/
    // Construye una secuencia con "n_datos" valores
    // PRE: 0 <= n_datos <= TAMANIO
    // PRE: A partir de "p" hay "n_datos" valores

    SecuenciaEnteros (int * p, int num_casillas);

    /*******************************************************/
    // Construye una secuencia con "n_datos" valores iguales
    // PRE: 0 <= n_datos <= TAMANIO

    SecuenciaEnteros (int n_datos, int valor=0);

    /*******************************************************/
    // Construye una secuencia con "n_datos" valores aleatorios
    // PRE: 0 <= n_datos <= TAMANIO

    SecuenciaEnteros (int n_datos, int min_aleat, int max_aleat);

    /***********************************************************************/
    // Devuelve el número de casillas ocupadas

    int TotalUtilizados ();

    /***********************************************************************/
    // Devuelve el número de casillas disponibles

    int Capacidad ();

    /***********************************************************************/
    // Añade un elemento ("nuevo") al vector.
    // PRE: total_utilizados < TAMANIO
    // 		La adición se realiza si hay alguna casilla disponible.
    // 		El nuevo elemento se coloca al final del vector.
    // 		Si no hay espacio, no se hace nada.

    void Aniade (int nuevo);

    /***********************************************************************/
    // Eliminar el carácter de la posición dada por "indice".
    // Realiza un borrado físico (desplazamiento y sustitución).
    // PRE: 0 <= indice < total_utilizados

    void Elimina (int indice);

    /***********************************************************************/
    // Inserta el carácter c en la posición dada por "indice".
    // Realiza un borrado físico (desplazamiento y sustitución).
    // PRE: 0 <= indice < total_utilizados

    void Inserta (int indice, int num);

    /*******************************************************/
    // Devuelve una ref. al elemento de la casilla "indice"
    // PRE: 0 <= indice < total_utilizados
    int & Valor (int indice);

    /*******************************************************/
    // Devuelve true si la secuencia implícita es igual a "otra"
    bool EsIgualA (const SecuenciaEnteros & otra);
 
    /***********************************************************************/
    // Compone un string con todos los valores que están
    // almacenados en la secuencia y lo devuelve.

    string ToString();

	/***********************************************************************/
};


#endif
