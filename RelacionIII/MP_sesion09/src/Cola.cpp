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

#include "Cola.h"

using namespace std;

/***************************************************************************/
/*---------------------------CONSTRUCTORES/DESTRUCTOR----------------------*/
/***************************************************************************/
// Constructor sin argumentos, que crea una cola vacía.
    Cola :: Cola()
    {
        cola = Secuencia();
    }

/***************************************************************************/
// Constructor de copia
    Cola :: Cola(const Cola &otra)
    {
        cola = Secuencia(otra.cola);
    }

/***************************************************************************/
// Destructor
    Cola :: ~Cola()
    {
        cola.~Secuencia();
        //¿Esto se puede hacer?, es que no se como liberar la memoria de la cola
    }

/***************************************************************************/
/*-----------------------------MÉTODOS PÚBLICOS------------------------*/
/***************************************************************************/
// Sobrecarga del operador de asignación
    Cola & Cola :: operator = (const Cola &otra)
    { 
        // Si la cola destino es distinta de la  origen
        if (this != &otra)
        {
            cola.Clona (otra.cola);
        }

        return *this;
    }

/***************************************************************************/
// Método de consulta para saber si la cola está vacía
    bool Cola :: EstaVacia(void) const
    {
        return  cola.EstaVacia();
    }

/***************************************************************************/
// Método para añadir un valor. La cola se modifica
    void Cola :: Aniade(TipoBaseSecuencia const &valor)
    {
        // Gracias a la clase secuencia, la cola se redimensiona automaticamente
        // antes de llenarse
        cola.Aniade(valor);
    }

/***************************************************************************/
// Método para sacar un valor. Obtiene el elemento extraido.
    TipoBaseSecuencia Cola :: sacavalor(void)
    {
        TipoBaseSecuencia valor = cola.Valor(0);
        cola.Elimina(0);

        return valor;
    }

/***************************************************************************/
// Método para consultar el elemento que está en la cabecera de la cola
    TipoBaseSecuencia Cola :: Cabecera(void) const
    {
        return cola.Valor(cola.TotalUtilizados() - 1);
    }