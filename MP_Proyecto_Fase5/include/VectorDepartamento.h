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
#include <cstring>
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
    // Crea un objeto copia del objeto proporcionado como argumento ("otro")
    // Parámetros: otro (referencia), Departamento que sirve de modelo. 
    VectorDepartamento(const VectorDepartamento &otro);

    /************************************************************************/
    // Constructor
    // Recibe como parámetro un Departamento que servirá para inicializar
    // el vector con un único elemento.
    VectorDepartamento(const Departamento &obj);

    /************************************************************************/
    // Destructor
    ~VectorDepartamento();

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
    // Difiere de la sobrecarga = de la clase Departamento en que este método
    // comprueba que el objeto proporcionado no se encuentre en la cadena
    // Es el método que recomiendo usar a la hora de alterar los elementos del vector
    // PRE: 1 <= indice <= totalutilizados
    void setDepartamento(int indice, const Departamento &obj);

    /***************************************************************************/
    /***************************************************************************/
    // Método ToString
    // Devuelve un string con la serialización de los objetos del vector implícito
    string ToString() const;

    /***********************************************************************/
    // Sobrecarga del operador de asignación para copia profunda.
    // Realiza una copia profunda de los datos de otro en el objeto implícito.
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
    // Sobrecarga de operador +
    // Versión 1: VectorDepartamento + VectorDepartamento
    // Concatena dos datos VectorDepartamento en uno nuevo. Los valo-
    // res del segundo se añaden (en el mismo orden) en una copia del primero.
    // Parámetros: otro (referencia), VectorDepartamento que se añade.
    // no se añadirá Departamento a VectorDepartamento si ya está dentro
    friend VectorDepartamento operator+ (const VectorDepartamento &uno, \
                                        const VectorDepartamento &otro);

    //Versión 2: [VectorDepartamento] + [Departamento]
    //Añade un dato Departamento al final de una copia del VectorDepartamento.
    // no se añadirá Departamento a VectorDepartamento si ya está dentro
    friend VectorDepartamento operator+ (const VectorDepartamento &v_obj, \
                                        const Departamento &obj);
    
    //Versión 3: [Departamento] + [VectorDepartamento]
    // Inserta el dato Departamento al principio de una copia del
    // VectorDepartamento.
    // no se añadirá Departamento a VectorDepartamento si ya está dentro
    friend VectorDepartamento operator+ (const Departamento &obj, \
                                           const VectorDepartamento &v_obj);

    /***************************************************************************/
    //Versioperatorón 1: [VectorDepartamento] - [VectorDepartamento]
    //Elimina de una copia del objeto implícito los datos Departamento cuyo
    //campo clave esté presente en los datos Departamento
    //del objeto explícito.
    //si Departamento no se encuentra en el objeto implícito no se hará nada 
    VectorDepartamento operator- (const VectorDepartamento &v_obj) const;

    //Versión 2: [VectorDepartamento] - [Departamento]
    //Elimina de una copia del VectorDepartamento el dato
    //Departamento cuyo campo clave sea igual al del
    //valor incluido en el objeto Departamento.
    //si Departamento no se encuentra en el objeto implícito no se hará nada 
    VectorDepartamento operator- (const Departamento &obj) const;

    //Versión 3: [VectorDepartamento] - [string]
    //Elimina de una copia del VectorDepartamento el dato
    //Departamento cuyo campo clave sea igual al string dado.
    //si Departamento no se encuentra en el objeto implícito no se hará nada 
    VectorDepartamento operator- (const string &obj) const;

    /***************************************************************************/
    // Operator *
    //Versión 1: [VectorDepartamento] * [VectorDepartamento]
    //Devuelve un nuevo VectorDepartamento que contiene to-
    //dos los datos Departamento comunes entre los dos VectorDepartamento
    VectorDepartamento operator* (const VectorDepartamento &V_obj) const;

    /***************************************************************************/
    // Operator &&
    //Versión 1: [VectorDepartamento] && [VectorDepartamento]
    //Devuelve true si el primer VectorDepartamento contiene todos los
    //datos que están en el segundo VectorDepartamento.
    friend bool operator&& (const VectorDepartamento &v_obj1,\
                            const VectorDepartamento &v_obj2);

    // Versión 2: [VectorDepartamento] && [Departamento]
    // Devuelve un int con el indice del VectorDepartamento que
    // contiene al dato Departamento.
    // Si no está contenido, devuelve 0.
    friend int operator&& (const VectorDepartamento &v_obj,\
                            const Departamento &obj);

    // Versión 3: [Departamento] && [VectorDepartamento]
    // Devuelve un int con el indice del VectorDepartamento que
    // contiene al dato Departamento.
    // Si no está contenido, devuelve 0.
    friend int operator&& (const Departamento &obj,\
                            const VectorDepartamento &v_obj);

    // Versión 4: [VectorDepartamento] && [string]
    // Devuelve un int con el indice del VectorDepartamento que
    // contiene al dato Departamento cuyo campo clave coincide con el string.
    // Si no está contenido, devuelve 0.
    friend int operator&& (const VectorDepartamento &v_obj,\
                            const string &cadena);

    // Versión 5: [string] && [VectorDepartamento]
    // Devuelve un int con el indice del VectorDepartamento que
    // contiene al dato Departamento cuyo campo clave coincide con el string.
    // Si no está contenido, devuelve 0.
    friend int operator&& (const string &cadena,\
                            const VectorDepartamento &v_obj);
    /***************************************************************************/
    // Operator +=
    // Versión 1: [VectorDepartamento] += [VectorDepartamento]
    // Todos los valores del objeto explícito se añaden (en el mismo orden en
    // el que están en el objeto explícito) al objeto implícito 
    // no se añadirá Departamento a VectorDepartamento si ya está dentro
    VectorDepartamento & operator+= (const VectorDepartamento & v_obj);

    // Versión 2: [VectorDepartamento] += [Departamento]
    //Añade un dato Departamento al final del objeto implícito.
    // no se añadirá Departamento a VectorDepartamento si ya está dentro
    VectorDepartamento & operator+= (const Departamento & obj);

    /***************************************************************************/
    // Operador -=:
    // Versión 1: [VectorDepartamento] -= [VectorDepartamento]
    //Elimina del objeto implícito los datos Departamento que
    // esté presente en los datos Departamento del objeto
    //explícito.
    //si Departamento no se encuentra en el objeto implícito no se hará nada 
    VectorDepartamento & operator-= (const VectorDepartamento & v_obj);

    //Versión 2: [VectorDepartamento] -= [Departamento]
    //Elimina del objeto implícito el dato Departamento
    //si Departamento no se encuentra en el objeto implícito no se hará nada 
    VectorDepartamento & operator-= (const Departamento & obj);

    //Versión 3: [VectorDepartamento] -= [string]
    //Elimina del objeto implícito el dato Departamento cuyo campo clave
    //sea igual al string dado
    //si Departamento no se encuentra en el objeto implícito no se hará nada 
    VectorDepartamento & operator-= (const string & obj);

    //Versión 4: [VectorDepartamento] -= [int]
    //Elimina del objeto implícito el dato Departamento cuyo indice sea int
    //si Departamento no se encuentra en el objeto implícito no se hará nada 
    VectorDepartamento & operator-= (const int & indice);


   /***************************************************************************/
    // INSERTADEPARTAMENTO
    // Inserta Departamento en el vector
    // Parámetros: Departamento a insertar y posición en la que insertarlo
    // PRE: 1 <= indice <= Totalutilizados()
    // PRE: El Departamento no existe en el vector
    void InsertaDepartamento(Departamento &obj, int indice);

    /***************************************************************************/
    // Elimina todos los Departamentos del vector
    void EliminaTodos();

    /***************************************************************************/
    // EXTRAEDEPARTAMENTO
    // Extrae Departamento del vector
    // Elimina el Departamento indice del vector y lo devuelve
    // PRE: 1 <= indice <= Totalutilizados()
    Departamento ExtraeDepartamento(int indice);

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

    /***************************************************************************/
    // ANIADEDEPARTAMENTO
    // Aniade Departamento al final del vector 
    // Dicho Departamento no puede estar repetido
    // Parámetros: obj (referencia), Departamento que se va a añadir.
    void AniadeDepartamento(const Departamento &obj);

    /***************************************************************************/
    // Método BuscarDepto: Recibe una clave primaria y la busca en el vector
    // Si está, devuelve el índice donde está almacenado, sino, devuelve -1
    // Versión 1: Busca el departamento dado un objeto departamento
    int BuscarDepartamento(const Departamento &obj) const;

    // Versión 2: Busca el departamento según el campo clave
    int BuscarDepartamento(const string &cadena) const;

    /***************************************************************************/
    // ELIMINADEPARTAMENTO
    // Elimina Departamento del vector
    // Parámetros: indice, int que indica el índice del Departamento
    // PRE: 1 <= indice <= Totalutilizados()
    void EliminaDepartamento(int indice);

    /***********************************************************************/
    // RESERVAMEMORIA
    // Pide memoria para guardar una copia de los datos de "otro"
    // Parámetros: otro (referencia), Departamento que sirve de modelo. 
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
    Departamento & Valor(const int indice) const;

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