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
// Fichero: SecuenciaEnteros_basico.cpp
//
/***************************************************************************/

#include <iostream>
#include <string>
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

    /***********************************************************************/
    // Devuelve el número de casillas ocupadas

    int TotalUtilizados (void)
    {
        return (total_utilizados);
    }

    /***********************************************************************/
    // Devuelve el número de casillas disponibles

    int Capacidad (void)
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
    // Devuelve el elemento de la casilla "indice"
    // PRE: 0 <= indice < total_utilizados

    int Elemento (int indice)
    {
        return (vector_privado[indice]);
    }

    /***********************************************************************/
    // Eliminar el carácter de la posición dada por "indice".
    // Realiza un borrado físico (desplazamiento y sustitución).
    // PRE: 0 <= indice < total_utilizados

    void Elimina (int indice)
    {
        if ((indice >= 0) && (indice < total_utilizados)) {

            int tope = total_utilizados-1; // posic. del último

            for (int i = indice ; i < tope ; i++)
                vector_privado[i] = vector_privado[i+1];

            total_utilizados--;
        }
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

/***************************************************************************/
/***************************************************************************/

int main (void)
{

    const int MIN_VALOR =  1;
    const int MAX_VALOR = 10;

    SecuenciaEnteros sec; 

    // Rellenar secuencia

    for (int valor=MIN_VALOR; valor<=MAX_VALOR; valor++)
        sec.Aniade (valor);

    // Mostrar secuencia


    cout << endl; 
    cout << sec.ToString () << endl;
    cout << "Num. valores en la secuencia = " << sec.TotalUtilizados() << endl;     
    cout << endl; 

    return 0;
}

/***************************************************************************/
/***************************************************************************/