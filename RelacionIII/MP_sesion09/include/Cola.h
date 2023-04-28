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

#ifndef COLA
#define COLA

#include "Secuencia.h"
using namespace std;

class Cola
{

private:
    Secuencia cola;

public:
/***************************************************************************/
/*---------------------------CONSTRUCTORES/DESTRUCTOR----------------------*/
/***************************************************************************/
// Constructor sin argumentos, que crea una cola vacía.
    Cola();

/***************************************************************************/
// Constructor de copia
    Cola(const Cola &otra);

/***************************************************************************/
// Destructor
    ~Cola();

/***************************************************************************/
/*-----------------------------MÉTODOS PÚBLICOS------------------------*/
/***************************************************************************/
// Sobrecarga del operador de asignación
    Cola &operator = (const Cola &otra);

/***************************************************************************/
// Método de consulta para saber si la cola está vacía
    bool EstaVacia(void) const;

/***************************************************************************/
// Método para añadir un valor. La cola se modifica
    void Aniade(TipoBaseSecuencia const &valor);

/***************************************************************************/
// Método para sacar un valor. Obtiene el elemento extraido.
    TipoBaseSecuencia sacavalor(void);

/***************************************************************************/
// Método para consultar el elemento que está en la cabecera de la cola
    TipoBaseSecuencia Cabecera(void) const;

};

#endif