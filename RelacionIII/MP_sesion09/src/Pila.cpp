/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// AUTOR: MARCO GIRELA VIDA
// GRUPO: 1ºB
// FECHA: xx/04/2023
//
// RELACION DE PROBLEMAS 3
//
//  
// 
//
// Declaraciones en: 
//
// Fichero: 
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>

#include "Pila.h"

using namespace std;

/***************************************************************************/
/*---------------------------CONSTRUCTORES/DESTRUCTOR----------------------*/
/***************************************************************************/
// Constructor sin argumentos, que crea una cola vacía.
    Pila :: Pila()
    {
        pila = Secuencia();
    }

/***************************************************************************/
// Constructor de copia
    Pila :: Pila(const Pila &otra)
    {
        pila = Secuencia(otra.pila);
    }

/***************************************************************************/
// Destructor
    Pila :: ~Pila()
    {
        pila.~Secuencia();
        //¿Esto se puede hacer?, es que no se como liberar la memoria de la Pila
    }

/***************************************************************************/
/*-----------------------------MÉTODOS PÚBLICOS------------------------*/
/***************************************************************************/
// Sobrecarga del operador de asignación
    Pila & Pila :: operator = (const Pila &otra)
    {
        Pila copia_pila(otra);
        return  copia_pila;
    }
/***************************************************************************/
// Método de consulta para saber si la pila está vacía
    bool Pila :: EstaVacia(void) const
    {
        return  pila.EstaVacia();
    }

/***************************************************************************/
// Método para añadir un valor. La cola se modifica
    void Pila :: aniade(TipoBaseSecuencia const &valor)
    {
        // Gracias a la clase secuencia, se redimensiona solo
        pila.Aniade(valor);
    }

/***************************************************************************/
// Método para sacar un valor. Obtiene el elemento extraido.
    TipoBaseSecuencia Pila :: sacavalor(void)
    {
        TipoBaseSecuencia valor = Cabecera();
        pila.Elimina(pila.TotalUtilizados() - 1);

        return valor;
    }

/***************************************************************************/
// Método para consultar el elemento que está en la cabecera de la pila
    TipoBaseSecuencia Pila :: Cabecera(void) const
    {
        return pila.Valor(pila.TotalUtilizados() - 1);
    }
