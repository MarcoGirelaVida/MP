/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// AUTOR: MARCO GIRELA VIDA
// GRUPO: 1ºB
// FECHA: xx/05/2023
//
// RELACION DE PROBLEMAS 4
//
// Fichero: VectorObjeto.h
/*****************************************************************************/

#ifndef VECTOR_OBJETO
#define VECTOR_OBJETO

#include <iostream>
#include <string>
#include "Objeto.h"

using namespace std;

/***************************************************************************/
/***************************************************************************/
class VectorObjeto
{

private:

    // Núm.casillas disponibles (capacidad) por defecto
    static const int TAMANIO = 5; 

	// Si el porcentaje de casillas usadas > PORC_PETICION --> Crecimiento
    static const int PORC_PETICION = 75; 
	// La capacidad aumenta PORC_CRECIMIENTO sobre la capacida actual
    static const int PORC_CRECIMIENTO = 10; 
	// El valor mínimo de casillas para el crecimiento será MIN_CRECIMIENTO
    static const int MIN_CRECIMIENTO = 5; 

	// Si el porcentaje de casillas usadas < PORC_REDUCCION --> Decrecimiento
    static const int PORC_REDUCCION = 50; 
	// La capacidad queda PORC_EXTRA sobre la ocupación actual
    static const int PORC_EXTRA = 20; 

    /*************************************************************************/
    //-------------------------ATRIBUTOS------------------------------------//
    /*************************************************************************/
    // ATRIBUTOS
    Objeto * vector_privado; // Puntero a un vector de objetos
    int total_utilizados; // Número de objetos almacenados
    int capacidad; // Tamaño del vector
    
public:

    /*************************************************************************/
    //-------------------------CONSTRUCTORES---------------------------------//
    /*************************************************************************/
    /***********************************************************************/
    // Constructor
	// Si se llama sin argumentos crea una secuencia con capacidad = TAMANIO.
	// Si se llama con un argumento, su valor será la capacidad inicial. 
	// POST: La secuencia creada estará vacía (EstaVacia()== true)

    VectorObjeto(int la_capacidad=TAMANIO);

    /************************************************************************/
    // Constructor de copia
    // Parámetros: otro (referencia), objeto que sirve de modelo. 
    VectorObjeto(const VectorObjeto &otro);

    /************************************************************************/
    // Destructor
    ~VectorObjeto();

    /*************************************************************************/
    //----------------------------MÉTODOS------------------------------------//
    /*************************************************************************/
    // Métodos de acceso a los campos de la clase
    int Totalutilizados() const;
    int Capacidad() const;
    int EstaVacia() const;

    /*************************************************************************/
    // Métodos get
    objeto getObjeto(int indice) const;

    /***************************************************************************/
    // Métodos set
    void setObjeto(int indice, Objeto &obj);

    /***************************************************************************/
    // Método ToString
    void Serializar() const;

    /***********************************************************************/
	// Sobrecarga del operador de asignación para copia profunda.
	// Parámetros: otro (referencia), objeto que sirve de modelo. 
    VectorObjeto &operator=(const VectorObjeto &otro);

    /***********************************************************************/
    // Sobrecarga del [].
    // Parámetros: indice del elemento a consultar (total_utilizados => indice > 0 ). 
    Objeto & operator[](int indice) const;

    /***********************************************************************/
    // Sobrecarga del [].
    // Parámetros: indice del elemento a modificar (total_utilizados => indice > 0 ). 
    Objeto & operator[](int indice);

    /***********************************************************************/
    // Sobrecarga del ().
    // Parámetros: indice del elemento a consultar (total_utilizados => indice > 0 ). 
    Objeto & operator()(int indice) const;

    /***********************************************************************/
    // Sobrecarga del ().
    // Parámetros: indice del elemento a modificar (total_utilizados => indice > 0 ). 
    Objeto & operator()(int indice) ;

    /***************************************************************************/
    // Aniade Objeto al final del vector
    void AniadeObjeto(Objeto &obj);

    /***************************************************************************/
    // Inserta Objeto en el vector
    void InsertaObjeto(Objeto &obj, int indice);

    /***************************************************************************/
    // Elimina Objeto del vector
    void EliminaObjeto(int indice);

    /***************************************************************************/
    // Elimina todos los objetos del vector
    void EliminaTodos();

    /***************************************************************************/
    // Extrae Objeto del vector
    Objeto ExtraeObjeto(int indice = Totalutilizados()-1);

    /***************************************************************************/
    // Iguala capacidad a total_utilizados (no recomendable, mejor usar redimensionar)
    void Reajustar()
    
private:
    /*************************************************************************/
    //----------------------------MÉTODOS PRIVADOS----------------------------//
    /*************************************************************************/
    // COPIARDATOS
    // Copiar datos desde otro objeto de la clase
    // Parámetros: otro (referencia), objeto que sirve de modelo. 
    //
    // PRE: Se ha reservado memoria para los datos
    void CopiarDatos(const VectorObjeto &otro);

    /***********************************************************************/
    // RESERVAMEMORIA
    // Pide memoria para guardar una copia de los datos de "otro"
    // Parámetros: otro (referencia), objeto que sirve de modelo. 
    void ReservaMemoria(const int num_casillas);

    /***********************************************************************/
    // LIBERARMEMORIA
    void LiberarMemoria();

    /***********************************************************************/
    // REDIMENSIONAR
	// Redimensiona el vector dinámico y copia los datos en el nuevo almacén.  
	//
	// Pedirá memoria adicional si el número de casillas usadas es superior 
	// al "PROC_PETICION" de la capacidad actual. El número de casillas 
	// adicionales será el "PORC_CRECIMIENTO" de la capacidad actual.
    /* 
	Una consecuencia de la eliminación podría ser la reducción de la 
	capacidad de la secuencia. Esto ocurrirá cuando el número de casillas 
	usadas es inferior al "PROC_REDUCCION" de la capacidad actual.

	El número de casillas finales no será fijo, sino que será un "PORC_EXTRA" 
	superior a la ocupación de la secuencia después de la eliminación. 
    */
	void Redimensionar (void);

};

#endif