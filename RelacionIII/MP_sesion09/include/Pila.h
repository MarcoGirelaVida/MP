/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// AUTOR: MARCO GIRELA VIDA
// GRUPO: 1ºB
// FECHA: xx/04/2023
//
// RELACION DE PROBLEMAS 3
//
// Fichero: .h
/*****************************************************************************/

#ifndef PILA
#define PILA

#include "Secuencia.h"
using namespace std;

class Pila
{

private:
    Secuencia pila;

public:

/***************************************************************************/
// Constructor sin argumentos, que crea una cola vacía.
    Pila();

/***************************************************************************/
// Constructor de copia
    Pila(const Pila &otra);

/***************************************************************************/
// Destructor
    ~Pila();

/***************************************************************************/
/***************************************************************************/
// Sobrecarga del operador de asignación
    Pila & operator=(const Pila &otra);

/***************************************************************************/
// Método de consulta para saber si la pila está vacía
    bool EstaVacia(void) const;

/***************************************************************************/
// Método para añadir un valor. La cola se modifica
    void aniade(TipoBaseSecuencia const &valor);

/***************************************************************************/
// Método para sacar un valor. Obtiene el elemento extraido.
    TipoBaseSecuencia sacavalor(void);

/***************************************************************************/
// Método para consultar el elemento que está en la cabecera de la pila
    TipoBaseSecuencia cabecera(void) const;
};

#endif