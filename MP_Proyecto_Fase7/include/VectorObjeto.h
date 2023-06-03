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
    // Crea un objeto copia del objeto proporcionado como argumento ("otro")
    // Parámetros: otro (referencia), Objeto que sirve de modelo. 
    VectorObjeto(const VectorObjeto &otro);

    /************************************************************************/
    // Constructor
    // Recibe como parámetro un Objeto que servirá para inicializar
    // el vector con un único elemento.
    VectorObjeto(const Objeto &obj);
 
    /************************************************************************/
    //Constructor.Construye un objeto VectorObjeto a partir de la información guardada en un
    //fichero de texto llamado nombre.
    //Son válidas las mismas consideraciones que en el método de lectura: si el fichero
    //indicado no fuera del tipo esperado, el vector quedará vacío
    VectorObjeto (const string & nombre);
 
    /************************************************************************/
    // Destructor
    ~VectorObjeto();

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
    // Difiere de la sobrecarga = de la clase Objeto en que este método
    // comprueba que el objeto proporcionado no se encuentre en la cadena
    // Es el método que recomiendo usar a la hora de alterar los elementos del vector
    // PRE: 1 <= indice <= totalutilizados
    void setObjeto(int indice, const Objeto &obj);


    /***************************************************************************/
    // OPERATOR >>:
    // Lee del flujo de entrada los datos de un VectorObjeto
    // Parámetros: flujo (referencia), flujo de entrada desde el que se leen los datos
    //             v_obj (referencia), VectorObjeto en el que se guardan los datos
    // PRE: El formato de los datos debe ser el siguiente:
    //      - Palabra clave: "ObjetoES"
    //      - Objetoes (una por linea)
    //      - Comentarios, deben empezar por el caracter '#'
    //      - Fin de datos, se sobreentenderá por el fin del flujo de entrada
    friend istream & operator>> (istream &flujo, VectorObjeto &v_obj);

    /***************************************************************************/
    // OPERATOR <<:
    // Escribe en el flujo de salida los datos de un VectorProfesor
    // Parámetros: flujo (referencia), flujo de salida en el que se escriben los datos
    //             v_obj (referencia constante), VectorProfesor del que se leen los datos
    // PRE: El formato de los datos debe ser el siguiente:
    //      - Palabra clave: "ProfesorES"
    //      - Profesores (una por linea)
    //      - Comentarios, deben empezar por el caracter '#'
    //      - Fin de datos, se sobreentenderá por el fin del flujo de entrada
    friend ostream & operator<< (ostream &flujo, const VectorObjeto &v_obj);

    /***************************************************************************/
    // Método ToString
    // Devuelve un string con la serialización de los objetos del vector implícito
    string ToString() const;

    /***************************************************************************/
    //Método de escritura. Guarda un dato Objeto en un fichero de texto llamado nombre.
    //Notas:
    //• Si el vector está vacío no se crea el fichero.
    //• El vector no se modifica.
    void GuardarVectorObjeto (const string & nombre) const;

    /***************************************************************************/
    //Método de lectura. Lee un dato Objeto de un fichero de texto llamado nombre.
    //Notas:
    //• El vector siempre se modifica.
    //• Si el fichero indicado no fuera un fichero del tipo esperado, el vector quedará
    //vacío.
    void RecuperarVectorObjeto (const string & nombre);
 
    /***********************************************************************/
    // Sobrecarga del operador de asignación para copia profunda.
    // Realiza una copia profunda de los datos de otro en el objeto implícito.
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
    // Devuelve un int con el indice del VectorObjeto que
    // contiene al dato Objeto.
    // Si no está contenido, devuelve 0.
    friend int operator&& (const VectorObjeto &v_obj,\
                            const Objeto &obj);

    // Versión 3: [Objeto] && [VectorObjeto]
    // Devuelve un int con el indice del VectorObjeto que
    // contiene al dato Objeto.
    // Si no está contenido, devuelve 0.
    friend int operator&& (const Objeto &obj,\
                            const VectorObjeto &v_obj);

    // Versión 4: [VectorObjeto] && [string]
    // Devuelve un int con el indice del VectorObjeto que
    // contiene al dato Objeto cuyo campo clave coincide con el string.
    // Si no está contenido, devuelve 0.
    friend int operator&& (const VectorObjeto &v_obj,\
                            const string &cadena);

    // Versión 5: [string] && [VectorObjeto]
    // Devuelve un int con el indice del VectorObjeto que
    // contiene al dato Objeto cuyo campo clave coincide con el string.
    // Si no está contenido, devuelve 0.
    friend int operator&& (const string &cadena,\
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

    //Versión 4: [VectorObjeto] -= [int]
    //Elimina del objeto implícito el dato Objeto cuyo indice sea int
    //si Objeto no se encuentra en el objeto implícito no se hará nada 
    VectorObjeto & operator-= (const int & indice);


   /***************************************************************************/
    // INSERTAObjeto
    // Inserta Objeto en el vector
    // Parámetros: Objeto a insertar y posición en la que insertarlo
    // PRE: 1 <= indice <= Totalutilizados()
    // PRE: El Objeto no existe en el vector
    void InsertaObjeto(Objeto &obj, int indice);

    /***************************************************************************/
    // Elimina todos los Objetos del vector
    void EliminaTodos();

    /***************************************************************************/
    // EXTRAEObjeto
    // Extrae Objeto del vector
    // Elimina el Objeto indice del vector y lo devuelve
    // PRE: 1 <= indice <= Totalutilizados()
    Objeto ExtraeObjeto(int indice);

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

    /***************************************************************************/
    // ANIADEObjeto
    // Aniade Objeto al final del vector 
    // Dicho Objeto no puede estar repetido
    // Parámetros: obj (referencia), Objeto que se va a añadir.
    void AniadeObjeto(const Objeto &obj);

    /***************************************************************************/
    // Método BuscarDepto: Recibe una clave primaria y la busca en el vector
    // Si está, devuelve el índice donde está almacenado, sino, devuelve -1
    // Versión 1: Busca el Objeto dado un objeto Objeto
    int BuscarObjeto(const Objeto &obj) const;

    // Versión 2: Busca el Objeto según el campo clave
    int BuscarObjeto(const string &cadena) const;

    /***************************************************************************/
    // ELIMINAObjeto
    // Elimina Objeto del vector
    // Parámetros: indice, int que indica el índice del Objeto
    // PRE: 1 <= indice <= Totalutilizados()
    void EliminaObjeto(int indice);

    /***********************************************************************/
    // RESERVAMEMORIA
    // Pide memoria para guardar una copia de los datos de "otro"
    // Parámetros: otro (referencia), Objeto que sirve de modelo. 
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
    Objeto & Valor(const int indice) const;

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