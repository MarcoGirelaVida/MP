/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// AUTOR: MARCO GIRELA VIDA
// GRUPO: 1ºB
// FECHA: xx/05/2023
//
// RELACION DE PROBLEMAS 4
//
// Fichero: VectorEncargo.h
/*****************************************************************************/

#ifndef VECTOR_Encargo
#define VECTOR_Encargo

#include <iostream>
#include <string>
#include "Encargo.h"

using namespace std;

/***************************************************************************/
/***************************************************************************/
class VectorEncargo
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
    Encargo * vector_privado; // Puntero a un vector de Encargos
    int total_utilizados; // Número de Encargos almacenados
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

    VectorEncargo(int la_capacidad=TAMANIO);

    /************************************************************************/
    // Constructor de copia
    // Parámetros: otro (referencia), Encargo que sirve de modelo. 
    VectorEncargo(const VectorEncargo &otro);

    /************************************************************************/
    // Destructor
    ~VectorEncargo();

    /*************************************************************************/
    //----------------------------MÉTODOS------------------------------------//
    /*************************************************************************/
    // Métodos de acceso a los campos de la clase
    int Totalutilizados() const;
    int Capacidad() const;
    int EstaVacia() const;

    /*************************************************************************/
    // Métodos get
    Encargo getEncargo(int indice) const;

    /***************************************************************************/
    // Métodos set
    void setEncargo(int indice, Encargo &obj);

    /***************************************************************************/
    // Método ToString
    void Serializar() const;

    /***********************************************************************/
	// Sobrecarga del operador de asignación para copia profunda.
	// Parámetros: otro (referencia), Encargo que sirve de modelo. 
    VectorEncargo &operator=(const VectorEncargo &otro);

    /***********************************************************************/
    // Sobrecarga del [].
    // Parámetros: indice del elemento a consultar (total_utilizados => indice > 0 ). 
    Encargo & operator[](int indice) const;

    /***********************************************************************/
    // Sobrecarga del [].
    // Parámetros: indice del elemento a modificar (total_utilizados => indice > 0 ). 
    Encargo & operator[](int indice);

    /***********************************************************************/
    // Sobrecarga del ().
    // Parámetros: indice del elemento a consultar (total_utilizados => indice > 0 ). 
    Encargo & operator()(int indice) const;

    /***********************************************************************/
    // Sobrecarga del ().
    // Parámetros: indice del elemento a modificar (total_utilizados => indice > 0 ). 
    Encargo & operator()(int indice) ;

    /***************************************************************************/
    // Aniade Encargo al final del vector
    void AniadeEncargo(Encargo &obj);

    /***************************************************************************/
    // Inserta Encargo en el vector
    void InsertaEncargo(Encargo &obj, int indice);

    /***************************************************************************/
    // Elimina Encargo del vector
    void EliminaEncargo(int indice);

    /***************************************************************************/
    // Elimina todos los Encargos del vector
    void EliminaTodos();

    /***************************************************************************/
    // Extrae Encargo del vector
    Encargo ExtraeEncargo(int indice);

    /***************************************************************************/
    // Iguala capacidad a total_utilizados (no recomendable, mejor usar redimensionar)
    void Reajustar();
    
private:
    /*************************************************************************/
    //----------------------------MÉTODOS PRIVADOS----------------------------//
    /*************************************************************************/
    // COPIARDATOS
    // Copiar datos desde otro Encargo de la clase
    // Parámetros: otro (referencia), Encargo que sirve de modelo. 
    //
    // PRE: Se ha reservado memoria para los datos
    void CopiarDatos(const VectorEncargo &otro);

    /***********************************************************************/
    // RESERVAMEMORIA
    // Pide memoria para guardar una copia de los datos de "otro"
    // Parámetros: otro (referencia), Encargo que sirve de modelo. 
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