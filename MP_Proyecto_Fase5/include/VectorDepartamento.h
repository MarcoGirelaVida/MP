/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// AUTOR: MARCO GIRELA VIDA
// GRUPO: 1ºB
// FECHA: xx/05/2023
//
// RELACION DE PROBLEMAS 4
//
// Fichero: VectorDepartamento.h
/*****************************************************************************/

#ifndef VECTOR_Departamento
#define VECTOR_Departamento

#include <iostream>
#include <string>
#include "Departamento.h"

using namespace std;

/***************************************************************************/
/***************************************************************************/
class VectorDepartamento
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
    Departamento * vector_privado; // Puntero a un vector de Departamentos
    int total_utilizados; // Número de Departamentos almacenados
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

    VectorDepartamento(int la_capacidad=TAMANIO);

    /************************************************************************/
    // Constructor de copia
    // Parámetros: otro (referencia), Departamento que sirve de modelo. 
    VectorDepartamento(const VectorDepartamento &otro);

    /************************************************************************/
    // Destructor
    ~VectorDepartamento();

    /*************************************************************************/
    //----------------------------MÉTODOS------------------------------------//
    /*************************************************************************/
    // Métodos de acceso a los campos de la clase
    int Totalutilizados() const;
    int Capacidad() const;
    int EstaVacia() const;

    /*************************************************************************/
    // Métodos get
    Departamento getDepartamento(int indice) const;

    /***************************************************************************/
    // Métodos set
    void setDepartamento(int indice, Departamento &obj);

    /***************************************************************************/
    // Método ToString
    string Serializar() const;

    /***********************************************************************/
	// Sobrecarga del operador de asignación para copia profunda.
	// Parámetros: otro (referencia), Departamento que sirve de modelo. 
    VectorDepartamento &operator=(const VectorDepartamento &otro);

    /***********************************************************************/
    // Sobrecarga del [].
    // Parámetros: indice del elemento a consultar (total_utilizados => indice > 0 ). 
    Departamento & operator[](int indice) const;

    /***********************************************************************/
    // Sobrecarga del [].
    // Parámetros: indice del elemento a modificar (total_utilizados => indice > 0 ). 
    Departamento & operator[](int indice);

    /***********************************************************************/
    // Sobrecarga del ().
    // Parámetros: indice del elemento a consultar (total_utilizados => indice > 0 ). 
    Departamento & operator()(int indice) const;

    /***********************************************************************/
    // Sobrecarga del ().
    // Parámetros: indice del elemento a modificar (total_utilizados => indice > 0 ). 
    Departamento & operator()(int indice) ;

    /***************************************************************************/
    // Método BuscarDepto: Recibe una clave primaria y la busca en el vector
    // Si está, devuelve el índice donde está almacenado, sino, devuelve -1
    int BuscarDepto(Departamento dep) const;

    /***************************************************************************/
    // Aniade Departamento al final del vector
    void AniadeDepartamento(Departamento &obj);

    /***************************************************************************/
    // Inserta Departamento en el vector
    void InsertaDepartamento(Departamento &obj, int indice);

    /***************************************************************************/
    // Elimina Departamento del vector
    void EliminaDepartamento(int indice);

    /***************************************************************************/
    // Elimina todos los Departamentos del vector
    void EliminaTodos();

    /***************************************************************************/
    // Extrae Departamento del vector
    Departamento ExtraeDepartamento(int indice);

    /***************************************************************************/
    // Iguala capacidad a total_utilizados (no recomendable, mejor usar redimensionar)
    void Reajustar();
    
private:
    /*************************************************************************/
    //----------------------------MÉTODOS PRIVADOS----------------------------//
    /*************************************************************************/
    // COPIARDATOS
    // Copiar datos desde otro Departamento de la clase
    // Parámetros: otro (referencia), Departamento que sirve de modelo. 
    //
    // PRE: Se ha reservado memoria para los datos
    void CopiarDatos(const VectorDepartamento &otro);

    /***********************************************************************/
    // RESERVAMEMORIA
    // Pide memoria para guardar una copia de los datos de "otro"
    // Parámetros: otro (referencia), Departamento que sirve de modelo. 
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

    /***********************************************************************/
    // VALOR: Devuelve el valor de la Adscripcion en la posición "indice"
    // Puede funcionar como lvalue y como rvalue
    // PRE: 0 <= indice < total_utilizados
    Departamento & Valor(int indice) const;

    /***********************************************************************/
    // comprobacion_indice: Comprueba si el índice es válido
    // PRE: 0 <= indice < total_utilizados
    void comprobacion_indice(int indice) const;
};

#endif