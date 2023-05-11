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

#ifndef VECTOR_Objeto
#define VECTOR_Objeto

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
    Objeto * vector_privado; // Puntero a un vector de Objetos
    int total_utilizados; // Número de Objetos almacenados
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
    // Parámetros: otro (referencia), Objeto que sirve de modelo. 
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
    Objeto getObjeto(int indice) const;

    /***************************************************************************/
    // Métodos set
    void setObjeto(int indice, Objeto &obj);

    /***************************************************************************/
    // Método ToString
    string Serializar() const;

    /***********************************************************************/
	// Sobrecarga del operador de asignación para copia profunda.
	// Parámetros: otro (referencia), Objeto que sirve de modelo. 
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
    // Sobrecarga de operador +
    // Versión 1: VectorObjeto + VectorObjeto
    // Concatena dos datos VectorObjeto en uno nuevo. Los valo-
    // res del segundo se añaden (en el mismo orden) en una copia del primero.
    // Parámetros: otro (referencia), VectorObjeto que se añade.
    // no se añadirá Objeto a VectorObjeto si ya está dentro
    friend VectorObjeto operator+ (const VectorObjeto &uno, \
                                        const VectorObjeto &otro);

    //Versión 2: [VectorObjeto] + [Objeto]
    //Añade un dato Objeto al final de una copia del VectorObjeto.
    // no se añadirá Objeto a VectorObjeto si ya está dentro
    friend VectorObjeto operator+ (const VectorObjeto &v_obj, \
                                        const Objeto &obj);
    
    //Versión 3: [Objeto] + [VectorObjeto]
    // Inserta el dato Objeto al principio de una copia del
    // VectorObjeto.
    // no se añadirá Objeto a VectorObjeto si ya está dentro
    friend VectorObjeto operator+ (const Objeto &obj, \
                                           const VectorObjeto &v_obj);

    /***************************************************************************/
    //Versioperatorón 1: [VectorObjeto] - [VectorObjeto]
    //Elimina de una copia del objeto implícito los datos Objeto cuyo
    //campo clave esté presente en los datos Objeto
    //del objeto explícito.
    //si Objeto no se encuentra en el objeto implícito no se hará nada 
    VectorObjeto operator- (const VectorObjeto &v_obj) const;

    //Versión 2: [VectorObjeto] - [Objeto]
    //Elimina de una copia del VectorObjeto el dato
    //Objeto cuyo campo clave sea igual al del
    //valor incluido en el objeto Objeto.
    //si Objeto no se encuentra en el objeto implícito no se hará nada 
    VectorObjeto operator- (const Objeto &obj) const;

    //Versión 3: [VectorObjeto] - [string]
    //Elimina de una copia del VectorObjeto el dato
    //Objeto cuyo campo clave sea igual al string dado.
    //si Objeto no se encuentra en el objeto implícito no se hará nada 
    VectorObjeto operator- (const string &obj) const;

    /***************************************************************************/
    // Operator *
    //Versión 1: [VectorObjeto] * [VectorObjeto]
    //Devuelve un nuevo VectorObjeto que contiene to-
    //dos los datos Objeto comunes entre los dos VectorObjeto
    VectorObjeto operator* (const VectorObjeto &V_obj) const;

    /***************************************************************************/
    // Operator &&
    //Versión 1: [VectorObjeto] && [VectorObjeto]
    //Devuelve true si el primer VectorObjeto contiene todos los
    //datos que están en el segundo VectorObjeto.
    friend bool operator&& (const VectorObjeto &v_obj1,\
                            const VectorObjeto &v_obj2);

    // Versión 2: [VectorObjeto] && [Objeto]
    //Devuelve true si VectorObjeto contiene al dato
    friend bool operator&& (const VectorObjeto &v_obj,\
                            const Objeto &obj);

    // Versión 3: [Objeto] && [VectorObjeto]
    //Devuelve true si VectorObjeto contiene al dato
    friend bool operator&& (const Objeto &obj,\
                            const VectorObjeto &v_obj);

    // Versión 4: [VectorObjeto] && [string]
    // Devuelve true si VectorObjeto contiene al dato
    // Objeto cuyo campo clave coincide con el string
    friend bool operator&& (const VectorObjeto &v_obj,\
                            const string &cadena);

    // Versión 5: [string] && [VectorObjeto]
    // Devuelve true si VectorObjeto contiene al dato
    // Objeto cuyo campo clave coincide con el string
    friend bool operator&& (const string &cadena,\
                            const VectorObjeto &v_obj);
    /***************************************************************************/
    // Operator +=
    // Versión 1: [VectorObjeto] += [VectorObjeto]
    // Todos los valores del objeto explícito se añaden (en el mismo orden en
    // el que están en el objeto explícito) al objeto implícito 
    // no se añadirá Objeto a VectorObjeto si ya está dentro
    VectorObjeto & operator+= (const VectorObjeto & v_obj);

    // Versión 2: [VectorObjeto] += [Objeto]
    //Añade un dato Objeto al final del objeto implícito.
    // no se añadirá Objeto a VectorObjeto si ya está dentro
    VectorObjeto & operator+= (const Objeto & obj);

    /***************************************************************************/
    // Operador -=:
    // Versión 1: [VectorObjeto] -= [VectorObjeto]
    //Elimina del objeto implícito los datos Objeto que
    // esté presente en los datos Objeto del objeto
    //explícito.
    //si Objeto no se encuentra en el objeto implícito no se hará nada 
    VectorObjeto & operator-= (const VectorObjeto & v_obj);

    //Versión 2: [VectorObjeto] -= [Objeto]
    //Elimina del objeto implícito el dato Objeto
    //si Objeto no se encuentra en el objeto implícito no se hará nada 
    VectorObjeto & operator-= (const Objeto & obj);

    //Versión 3: [VectorObjeto] -= [string]
    //Elimina del objeto implícito el dato Objeto cuyo campo clave
    //sea igual al string dado
    //si Objeto no se encuentra en el objeto implícito no se hará nada 
    VectorObjeto & operator-= (const string & obj);

    /***************************************************************************/
    // Método BuscarObjeto: Recibe una clave primaria y la busca en el vector
    // Si está, devuelve el índice donde está almacenado, sino, devuelve -1
    // Versión 1: Busca el Objeto dado un objeto Objeto
    int BuscarObjeto(const Objeto &obj) const;

    // Versión 2: Busca el Objeto según el campo clave
    int BuscarObjeto(const string &cadena) const;

    /***************************************************************************/
    // Aniade Objeto al final del vector
    void AniadeObjeto(const Objeto &obj);

    /***************************************************************************/
    // Inserta Objeto en el vector
    void InsertaObjeto(Objeto &obj, int indice);

    /***************************************************************************/
    // Elimina Objeto del vector
    void EliminaObjeto(int indice);

    /***************************************************************************/
    // Elimina todos los Objetos del vector
    void EliminaTodos();

    /***************************************************************************/
    // Extrae Objeto del vector
    Objeto ExtraeObjeto(int indice);

    /***************************************************************************/
    // Iguala capacidad a total_utilizados (no recomendable, mejor usar redimensionar)
    void Reajustar();
    
private:
    /*************************************************************************/
    //----------------------------MÉTODOS PRIVADOS----------------------------//
    /*************************************************************************/
    // COPIARDATOS
    // Copiar datos desde otro Objeto de la clase
    // Parámetros: otro (referencia), Objeto que sirve de modelo. 
    //
    // PRE: Se ha reservado memoria para los datos
    void CopiarDatos(const VectorObjeto &otro);

    /***********************************************************************/
    // RESERVAMEMORIA
    // Pide memoria para guardar una copia de los datos de "otro"
    // Parámetros: otro (referencia), Objeto que sirve de modelo. 
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
    Objeto & Valor(const int indice) const;

    /***********************************************************************/
    // comprobacion_indice: Comprueba si el índice es válido
    // PRE: 0 <= indice < total_utilizados
    void comprobacion_indice_totalutilizados(const int indice) const;

    /***********************************************************************/
    // comprobacion_indice: Comprueba si el índice es válido
    // PRE: 0 <= indice < capacidad
    void comprobacion_indice_capacidad(const int indice) const;

    bool indice_valido_usados(const int indice) const;

    bool indice_valido_capacidad(const int indice) const;
};

#endif