/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// AUTOR: MARCO GIRELA VIDA
// GRUPO: 1ºB
// FECHA: xx/05/2023
//
// RELACION DE PROBLEMAS 4
//
// Fichero: VectorAdscripcion.h
/*****************************************************************************/

#ifndef VECTOR_Adscripcion
#define VECTOR_Adscripcion

#include <iostream>
#include <string>
#include "Adscripcion.h"

using namespace std;

/***************************************************************************/
/***************************************************************************/
class VectorAdscripcion
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
    Adscripcion * vector_privado; // Puntero a un vector de Adscripcions
    int total_utilizados; // Número de Adscripcions almacenados
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

    VectorAdscripcion(int la_capacidad=TAMANIO);

    /************************************************************************/
    // Constructor de copia
    // Crea un objeto copia del objeto proporcionado como argumento ("otro")
    // Parámetros: otro (referencia), Adscripcion que sirve de modelo. 
    VectorAdscripcion(const VectorAdscripcion &otro);

    /************************************************************************/
    // Constructor
    // Recibe como parámetro un Adscripcion que servirá para inicializar
    // el vector con un único elemento.
    VectorAdscripcion(const Adscripcion &obj);

    /************************************************************************/
    // Destructor
    ~VectorAdscripcion();

    /*************************************************************************/
    //----------------------------MÉTODOS------------------------------------//
    /*************************************************************************/
    // Métodos de acceso a los campos de la clase
    // Totalutilizados: Devuelve el número de elementos utilizados
    int Totalutilizados() const;
    // Capacidad: Devuelve la capacidad actual del vector
    int Capacidad() const;
    // EstaVacia: Devueve true si totalutilizados es 0 y false en caso contrario
    int EstaVacia() const;

   /***************************************************************************/
    // Métodos set
    // Sustituye el elemento "indice" del vector por el objeto proporcionado
    // Difiere de la sobrecarga = de la clase Adscripcion en que este método
    // comprueba que el objeto proporcionado no se encuentre en la cadena
    // Es el método que recomiendo usar a la hora de alterar los elementos del vector
    // PRE: 1 <= indice <= totalutilizados
    void setAdscripcion(int indice, const Adscripcion &obj);

    /***************************************************************************/
    /***************************************************************************/
    // Método ToString
    // Devuelve un string con la serialización de los objetos del vector implícito
    string ToString() const;

    /***********************************************************************/
    // Sobrecarga del operador de asignación para copia profunda.
    // Realiza una copia profunda de los datos de otro en el objeto implícito.
    // Parámetros: otro (referencia), Adscripcion que sirve de modelo. 
    VectorAdscripcion &operator=(const VectorAdscripcion &otro);

    /***********************************************************************/
    // Sobrecarga del [].
    // Parámetros: indice del elemento a consultar (total_utilizados => indice > 0 ). 
    Adscripcion & operator[](int indice) const;

    /***********************************************************************/
    // Sobrecarga del [].
    // Parámetros: indice del elemento a modificar (total_utilizados => indice > 0 ). 
    Adscripcion & operator[](int indice);

    /***********************************************************************/
    // Sobrecarga del ().
    // Parámetros: indice del elemento a consultar (total_utilizados => indice > 0 ). 
    Adscripcion & operator()(int indice) const;

    /***********************************************************************/
    // Sobrecarga del ().
    // Parámetros: indice del elemento a modificar (total_utilizados => indice > 0 ). 
    Adscripcion & operator()(int indice) ;

    /***************************************************************************/
    // Sobrecarga de operador +
    // Versión 1: VectorAdscripcion + VectorAdscripcion
    // Concatena dos datos VectorAdscripcion en uno nuevo. Los valo-
    // res del segundo se añaden (en el mismo orden) en una copia del primero.
    // Parámetros: otro (referencia), VectorAdscripcion que se añade.
    // no se añadirá Adscripcion a VectorAdscripcion si ya está dentro
    friend VectorAdscripcion operator+ (const VectorAdscripcion &uno, \
                                        const VectorAdscripcion &otro);

    //Versión 2: [VectorAdscripcion] + [Adscripcion]
    //Añade un dato Adscripcion al final de una copia del VectorAdscripcion.
    // no se añadirá Adscripcion a VectorAdscripcion si ya está dentro
    friend VectorAdscripcion operator+ (const VectorAdscripcion &v_obj, \
                                        const Adscripcion &obj);
    
    //Versión 3: [Adscripcion] + [VectorAdscripcion]
    // Inserta el dato Adscripcion al principio de una copia del
    // VectorAdscripcion.
    // no se añadirá Adscripcion a VectorAdscripcion si ya está dentro
    friend VectorAdscripcion operator+ (const Adscripcion &obj, \
                                           const VectorAdscripcion &v_obj);

    /***************************************************************************/
    //Versioperatorón 1: [VectorAdscripcion] - [VectorAdscripcion]
    //Elimina de una copia del objeto implícito los datos Adscripcion cuyo
    //campo clave esté presente en los datos Adscripcion
    //del objeto explícito.
    //si Adscripcion no se encuentra en el objeto implícito no se hará nada 
    VectorAdscripcion operator- (const VectorAdscripcion &v_obj) const;

    //Versión 2: [VectorAdscripcion] - [Adscripcion]
    //Elimina de una copia del VectorAdscripcion el dato
    //Adscripcion cuyo campo clave sea igual al del
    //valor incluido en el objeto Adscripcion.
    //si Adscripcion no se encuentra en el objeto implícito no se hará nada 
    VectorAdscripcion operator- (const Adscripcion &obj) const;

    //Versión 3: [VectorAdscripcion] - [string]
    //Elimina de una copia del VectorAdscripcion el dato
    //Adscripcion cuyo campo clave sea igual al string dado.
    //si Adscripcion no se encuentra en el objeto implícito no se hará nada 
    VectorAdscripcion operator- (const string &obj) const;

    /***************************************************************************/
    // Operator *
    //Versión 1: [VectorAdscripcion] * [VectorAdscripcion]
    //Devuelve un nuevo VectorAdscripcion que contiene to-
    //dos los datos Adscripcion comunes entre los dos VectorAdscripcion
    VectorAdscripcion operator* (const VectorAdscripcion &V_obj) const;

    /***************************************************************************/
    // Operator &&
    //Versión 1: [VectorAdscripcion] && [VectorAdscripcion]
    //Devuelve true si el primer VectorAdscripcion contiene todos los
    //datos que están en el segundo VectorAdscripcion.
    friend bool operator&& (const VectorAdscripcion &v_obj1,\
                            const VectorAdscripcion &v_obj2);

    // Versión 2: [VectorAdscripcion] && [Adscripcion]
    // Devuelve un int con el indice del VectorAdscripcion que
    // contiene al dato Adscripcion.
    // Si no está contenido, devuelve 0.
    friend int operator&& (const VectorAdscripcion &v_obj,\
                            const Adscripcion &obj);

    // Versión 3: [Adscripcion] && [VectorAdscripcion]
    // Devuelve un int con el indice del VectorAdscripcion que
    // contiene al dato Adscripcion.
    // Si no está contenido, devuelve 0.
    friend int operator&& (const Adscripcion &obj,\
                            const VectorAdscripcion &v_obj);

    // Versión 4: [VectorAdscripcion] && [string]
    // Devuelve un int con el indice del VectorAdscripcion que
    // contiene al dato Adscripcion cuyo campo clave coincide con el string.
    // Si no está contenido, devuelve 0.
    friend int operator&& (const VectorAdscripcion &v_obj,\
                            const string &cadena);

    // Versión 5: [string] && [VectorAdscripcion]
    // Devuelve un int con el indice del VectorAdscripcion que
    // contiene al dato Adscripcion cuyo campo clave coincide con el string.
    // Si no está contenido, devuelve 0.
    friend int operator&& (const string &cadena,\
                            const VectorAdscripcion &v_obj);
    /***************************************************************************/
    // Operator +=
    // Versión 1: [VectorAdscripcion] += [VectorAdscripcion]
    // Todos los valores del objeto explícito se añaden (en el mismo orden en
    // el que están en el objeto explícito) al objeto implícito 
    // no se añadirá Adscripcion a VectorAdscripcion si ya está dentro
    VectorAdscripcion & operator+= (const VectorAdscripcion & v_obj);

    // Versión 2: [VectorAdscripcion] += [Adscripcion]
    //Añade un dato Adscripcion al final del objeto implícito.
    // no se añadirá Adscripcion a VectorAdscripcion si ya está dentro
    VectorAdscripcion & operator+= (const Adscripcion & obj);

    /***************************************************************************/
    // Operador -=:
    // Versión 1: [VectorAdscripcion] -= [VectorAdscripcion]
    //Elimina del objeto implícito los datos Adscripcion que
    // esté presente en los datos Adscripcion del objeto
    //explícito.
    //si Adscripcion no se encuentra en el objeto implícito no se hará nada 
    VectorAdscripcion & operator-= (const VectorAdscripcion & v_obj);

    //Versión 2: [VectorAdscripcion] -= [Adscripcion]
    //Elimina del objeto implícito el dato Adscripcion
    //si Adscripcion no se encuentra en el objeto implícito no se hará nada 
    VectorAdscripcion & operator-= (const Adscripcion & obj);

    //Versión 3: [VectorAdscripcion] -= [string]
    //Elimina del objeto implícito el dato Adscripcion cuyo campo clave
    //sea igual al string dado
    //si Adscripcion no se encuentra en el objeto implícito no se hará nada 
    VectorAdscripcion & operator-= (const string & obj);

    //Versión 4: [VectorAdscripcion] -= [int]
    //Elimina del objeto implícito el dato Adscripcion cuyo indice sea int
    //si Adscripcion no se encuentra en el objeto implícito no se hará nada 
    VectorAdscripcion & operator-= (const int & indice);


   /***************************************************************************/
    // INSERTAAdscripcion
    // Inserta Adscripcion en el vector
    // Parámetros: Adscripcion a insertar y posición en la que insertarlo
    // PRE: 1 <= indice <= Totalutilizados()
    // PRE: El Adscripcion no existe en el vector
    void InsertaAdscripcion(Adscripcion &obj, int indice);

    /***************************************************************************/
    // Elimina todos los Adscripcions del vector
    void EliminaTodos();

    /***************************************************************************/
    // EXTRAEAdscripcion
    // Extrae Adscripcion del vector
    // Elimina el Adscripcion indice del vector y lo devuelve
    // PRE: 1 <= indice <= Totalutilizados()
    Adscripcion ExtraeAdscripcion(int indice);

private:
    /*************************************************************************/
    //----------------------------MÉTODOS PRIVADOS----------------------------//
    /*************************************************************************/
    // COPIARDATOS
    // Copiar datos desde otro Adscripcion de la clase
    // Parámetros: otro (referencia), Adscripcion que sirve de modelo. 
    //
    // PRE: Se ha reservado memoria para los datos
    void CopiarDatos(const VectorAdscripcion &otro);

    /***************************************************************************/
    // ANIADEAdscripcion
    // Aniade Adscripcion al final del vector 
    // Dicho Adscripcion no puede estar repetido
    // Parámetros: obj (referencia), Adscripcion que se va a añadir.
    void AniadeAdscripcion(const Adscripcion &obj);

    /***************************************************************************/
    // Método BuscarDepto: Recibe una clave primaria y la busca en el vector
    // Si está, devuelve el índice donde está almacenado, sino, devuelve -1
    // Versión 1: Busca el Adscripcion dado un objeto Adscripcion
    int BuscarAdscripcion(const Adscripcion &obj) const;

    // Versión 2: Busca el Adscripcion según el campo clave
    int BuscarAdscripcion(const string &cadena) const;

    /***************************************************************************/
    // ELIMINAAdscripcion
    // Elimina Adscripcion del vector
    // Parámetros: indice, int que indica el índice del Adscripcion
    // PRE: 1 <= indice <= Totalutilizados()
    void EliminaAdscripcion(int indice);

    /***********************************************************************/
    // RESERVAMEMORIA
    // Pide memoria para guardar una copia de los datos de "otro"
    // Parámetros: otro (referencia), Adscripcion que sirve de modelo. 
    void ReservaMemoria(const int num_casillas);

    /***********************************************************************/
    // LIBERARMEMORIA
    // Libera la memoria dinámica reservada para el vector
    void LiberarMemoria();

    /***************************************************************************/
    // Iguala capacidad a total_utilizados (no recomendable, mejor usar redimensionar)
    void Reajustar();
    
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
    // Es el único método que usa y debe usar el índice "real" (desde 0)
    // PRE: 0 <= indice < total_utilizados
    Adscripcion & Valor(const int indice) const;

    /***********************************************************************/
    // comprobacion_indice: Comprueba si el índice es válido
    // En caso que lo sea, devuelve un mensaje de error y termina el programa
    // PRE: 1 <= indice <= total_utilizados
    void comprobacion_indice_totalutilizados(const int indice) const;

    /***********************************************************************/
    // comprobacion_indice: Comprueba si el índice es válido
    // En caso que lo sea, devuelve un mensaje de error y termina el programa
    // PRE: 1 <= indice <= capacidad
    void comprobacion_indice_capacidad(const int indice) const;

    /***********************************************************************/
    // Indice_valido_usados: Comprueba si el índice es válido
    // Devuelve true si el índice está entre 1 y total_utilizados
    // Devuelve false en caso contrario
    bool indice_valido_usados(const int indice) const;

    /***********************************************************************/
    // Indice_valido_capacidad: Comprueba si el índice es válido
    // Devuelve true si el índice está entre 1 y capacidad
    // Devuelve false en caso contrario
    bool indice_valido_capacidad(const int indice) const;
};

#endif