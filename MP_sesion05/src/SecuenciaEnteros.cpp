/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// AUTOR: MARCO GIRELA VIDA
// GRUPO: 1ºB
// FECHA: 20/03/2023
//
// RELACION DE PROBLEMAS 1
//
// Fichero: SecuenciaEnteros.cpp
//
/***************************************************************************/

#include <iostream>
#include <string>
#include <cstring>
#include "GeneradorAleatorioEnteros.h"
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

    SecuenciaEnteros (void) : total_utilizados (0)
    {}

    /*******************************************************/
    // Construye una secuencia con "n_datos" valores
    // PRE: 0 <= n_datos <= TAMANIO
    // PRE: A partir de "p" hay "n_datos" valores

    SecuenciaEnteros (int * p, int num_casillas) : total_utilizados(0)
    {
        for (int i = 0; i < num_casillas; i++)
        {
            *(vector_privado + i) = *(p + i);
            total_utilizados++;
        }
    }

    /*******************************************************/
    // Construye una secuencia con "n_datos" valores iguales
    // PRE: 0 <= n_datos <= TAMANIO

    SecuenciaEnteros (int n_datos, int valor=0) : total_utilizados(0)
    {
        for(int i=0; i < n_datos; i++)
        {
            *(vector_privado + i) = valor;
            total_utilizados++;
        }
    }

    /*******************************************************/
    // Construye una secuencia con "n_datos" valores aleatorios
    // PRE: 0 <= n_datos <= TAMANIO

    SecuenciaEnteros (int n_datos, int min_aleat, int max_aleat) : total_utilizados(0)
    {
        // Rellenar el vector con valores aleatorios entre "min" y "max" 
	    GeneradorAleatorioEnteros generador (min_aleat, max_aleat);

	    for (int i=0; i<n_datos; i++) 
             *(vector_privado+i) = generador.Siguiente();
    }

    /***********************************************************************/
    // Devuelve el número de casillas ocupadas

    int TotalUtilizados (void) const
    {
        return (total_utilizados);
    }

    /***********************************************************************/
    // Devuelve el número de casillas disponibles

    int Capacidad (void) const
    {
        return (TAMANIO);
    }

    /***********************************************************************/
    // Añade un elemento ("nuevo") al vector.
    // PRE: total_utilizados < TAMANIO
    // 		La adición se realiza si hay alguna casilla disponible.
    // 		El nuevo elemento se coloca al final del vector.
    // 		Si no hay espacio, no se hace nada.

    void Aniade (int nuevo)
    {
        if (total_utilizados < TAMANIO){
            vector_privado[total_utilizados] = nuevo;
            total_utilizados++;
        }
    }

    /***********************************************************************/
    // Eliminar el carácter de la posición dada por "indice".
    // Realiza un borrado físico (desplazamiento y sustitución).
    // PRE: 0 <= indice < total_utilizados

    void Elimina (int indice)
    {
        int * p_index = vector_privado + indice;

        if ((indice >= 0) && (indice < total_utilizados))
        {
            memmove((void *)p_index, (const void *) p_index+1, (total_utilizados-indice-1)*sizeof(int));
            total_utilizados--;
        }
    }
 
    /***********************************************************************/
    // Inserta el carácter c en la posición dada por "indice".
    // Realiza un borrado físico (desplazamiento y sustitución).
    // PRE: 0 <= indice < total_utilizados

    void Inserta (char c, int indice)
    {
        int * p_index = vector_privado + indice;

        if ((indice >= 0) && (indice < total_utilizados))
        {
            total_utilizados++;
            memmove((void *)p_index + 1, (const void *) p_index, (total_utilizados-indice)*sizeof(int));
            *p_index = c;
        }
    }

    /*******************************************************/
    // Devuelve una ref. al elemento de la casilla "indice"
    // PRE: 0 <= indice < total_utilizados
    int & Valor (int indice)
    {
        if ((indice >= 0) && (indice < total_utilizados))
        {
            return *(vector_privado+indice);
        }
    }

    /*******************************************************/
    // Devuelve true si la secuencia implícita es igual a "otra"
    // ATENCIÓN: La función debería ser de tipo const, no obstante
    // llama a la función VALOR, que no lo es, por lo que no puedo.
    bool EsIgualA (const SecuenciaEnteros & otra)
    {
        bool es = true;

        // Hago una comprobación rápida para comprobar que 
        // ambas tienen la misma lóngitud.
        // Si no es así, no son iguales.
        if ( otra.TotalUtilizados() == total_utilizados)
        {
            es = false;
        }

        for (int i = 0; i < total_utilizados && es; i++)
        {
            // Sé que no es una buena práctica, no obstante dado que el método "Valor"
            // no es "const", era necesario hacer casting de otra a otra_noconst.
            SecuenciaEnteros& otra_noconst = const_cast<SecuenciaEnteros&>(otra);
            if ( otra_noconst.Valor(i) == Valor(i))
            {
                es = false;
            }
        }
        
        return es;
    }

    /***********************************************************************/
    // Compone un string con todos los valores que están
    // almacenados en la secuencia y lo devuelve.

    string ToString()
    {
        string cadena = "{";

		if (total_utilizados > 0) {

	        for (int i=0; i<total_utilizados-1; i++)

	        	cadena = cadena + to_string(vector_privado[i])+", ";

			// Añadie el último seguido de '}'
	        cadena = cadena + to_string(vector_privado[total_utilizados-1]);
		}

        cadena = cadena + "}";

        return (cadena);
    }

	/***********************************************************************/
};

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////