/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// AUTOR: MARCO GIRELA VIDA
// GRUPO: 1ºB
// FECHA: xx/05/2023
//
// RELACION DE PROBLEMAS 4
//
// Fichero: VectorProfesor.h
/*****************************************************************************/

#ifndef VECTOR_Profesor
#define VECTOR_Profesor

#include "Profesor.h"

using namespace std;

/***************************************************************************/
/***************************************************************************/
class VectorProfesor
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
    Profesor * vector_privado; // Puntero a un vector de Profesors
    int total_utilizados; // Número de Profesors almacenados
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

    VectorProfesor(int la_capacidad=TAMANIO);

    /************************************************************************/
    // Constructor de copia
    // Crea un Profesor copia del Profesor proporcionado como argumento ("otro")
    // Parámetros: otro (referencia), Profesor que sirve de modelo. 
    VectorProfesor(const VectorProfesor &otro);

    /************************************************************************/
    // Constructor
    // Recibe como parámetro un Profesor que servirá para inicializar
    // el vector con un único elemento.
    VectorProfesor(const Profesor &obj);
 
    /************************************************************************/
    //Constructor.Construye un Profesor VectorProfesor a partir de la información guardada en un
    //fichero de texto llamado nombre.
    //Son válidas las mismas consideraciones que en el método de lectura: si el fichero
    //indicado no fuera del tipo esperado, el vector quedará vacío
    VectorProfesor (const string & nombre);
 
    /************************************************************************/
    // Destructor
    ~VectorProfesor();

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
    // Sustituye el elemento "indice" del vector por el Profesor proporcionado
    // Difiere de la sobrecarga = de la clase Profesor en que este método
    // comprueba que el Profesor proporcionado no se encuentre en la cadena
    // Es el método que recomiendo usar a la hora de alterar los elementos del vector
    // PRE: 1 <= indice <= totalutilizados
    void setProfesor(int indice, const Profesor &obj);


    /***************************************************************************/
    // OPERATOR >>:
    // Lee del flujo de entrada los datos de un VectorProfesor
    // Parámetros: flujo (referencia), flujo de entrada desde el que se leen los datos
    //             v_obj (referencia), VectorProfesor en el que se guardan los datos
    // PRE: El formato de los datos debe ser el siguiente:
    //      - Palabra clave: "ProfesorES"
    //      - Profesores (una por linea)
    //      - Comentarios, deben empezar por el caracter '#'
    //      - Fin de datos, se sobreentenderá por el fin del flujo de entrada
    friend istream & operator>> (istream &flujo, VectorProfesor &v_obj);

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
    friend ostream & operator<< (ostream &flujo, const VectorProfesor &v_obj);

    /***************************************************************************/
    // Método ToString
    // Devuelve un string con la serialización de los Profesors del vector implícito
    string ToString() const;

    /***************************************************************************/
    //Método de escritura. Guarda un dato Profesor en un fichero de texto llamado nombre.
    //Notas:
    //• Si el vector está vacío no se crea el fichero.
    //• El vector no se modifica.
    void GuardarVectorProfesor (const string & nombre) const;

    /***************************************************************************/
    //Método de lectura. Lee un dato Profesor de un fichero de texto llamado nombre.
    //Notas:
    //• El vector siempre se modifica.
    //• Si el fichero indicado no fuera un fichero del tipo esperado, el vector quedará
    //vacío.
    void RecuperarVectorProfesor (const string & nombre);
 
    /***********************************************************************/
    // Sobrecarga del operador de asignación para copia profunda.
    // Realiza una copia profunda de los datos de otro en el Profesor implícito.
    // Parámetros: otro (referencia), Profesor que sirve de modelo. 
    VectorProfesor &operator=(const VectorProfesor &otro);

    /***********************************************************************/
    // Sobrecarga del [].
    // Parámetros: indice del elemento a consultar (total_utilizados => indice > 0 ). 
    Profesor & operator[](int indice) const;

    /***********************************************************************/
    // Sobrecarga del [].
    // Parámetros: indice del elemento a modificar (total_utilizados => indice > 0 ). 
    Profesor & operator[](int indice);

    /***********************************************************************/
    // Sobrecarga del ().
    // Parámetros: indice del elemento a consultar (total_utilizados => indice > 0 ). 
    Profesor & operator()(int indice) const;

    /***********************************************************************/
    // Sobrecarga del ().
    // Parámetros: indice del elemento a modificar (total_utilizados => indice > 0 ). 
    Profesor & operator()(int indice) ;

    /***************************************************************************/
    // Sobrecarga de operador +
    // Versión 1: VectorProfesor + VectorProfesor
    // Concatena dos datos VectorProfesor en uno nuevo. Los valo-
    // res del segundo se añaden (en el mismo orden) en una copia del primero.
    // Parámetros: otro (referencia), VectorProfesor que se añade.
    // no se añadirá Profesor a VectorProfesor si ya está dentro
    friend VectorProfesor operator+ (const VectorProfesor &uno, \
                                        const VectorProfesor &otro);

    //Versión 2: [VectorProfesor] + [Profesor]
    //Añade un dato Profesor al final de una copia del VectorProfesor.
    // no se añadirá Profesor a VectorProfesor si ya está dentro
    friend VectorProfesor operator+ (const VectorProfesor &v_obj, \
                                        const Profesor &obj);
    
    //Versión 3: [Profesor] + [VectorProfesor]
    // Inserta el dato Profesor al principio de una copia del
    // VectorProfesor.
    // no se añadirá Profesor a VectorProfesor si ya está dentro
    friend VectorProfesor operator+ (const Profesor &obj, \
                                           const VectorProfesor &v_obj);

    /***************************************************************************/
    //Versioperatorón 1: [VectorProfesor] - [VectorProfesor]
    //Elimina de una copia del Profesor implícito los datos Profesor cuyo
    //campo clave esté presente en los datos Profesor
    //del Profesor explícito.
    //si Profesor no se encuentra en el Profesor implícito no se hará nada 
    VectorProfesor operator- (const VectorProfesor &v_obj) const;

    //Versión 2: [VectorProfesor] - [Profesor]
    //Elimina de una copia del VectorProfesor el dato
    //Profesor cuyo campo clave sea igual al del
    //valor incluido en el Profesor Profesor.
    //si Profesor no se encuentra en el Profesor implícito no se hará nada 
    VectorProfesor operator- (const Profesor &obj) const;

    //Versión 3: [VectorProfesor] - [string]
    //Elimina de una copia del VectorProfesor el dato
    //Profesor cuyo campo clave sea igual al string dado.
    //si Profesor no se encuentra en el Profesor implícito no se hará nada 
    VectorProfesor operator- (const string &obj) const;

    /***************************************************************************/
    // Operator *
    //Versión 1: [VectorProfesor] * [VectorProfesor]
    //Devuelve un nuevo VectorProfesor que contiene to-
    //dos los datos Profesor comunes entre los dos VectorProfesor
    VectorProfesor operator* (const VectorProfesor &V_obj) const;

    /***************************************************************************/
    // Operator &&
    //Versión 1: [VectorProfesor] && [VectorProfesor]
    //Devuelve true si el primer VectorProfesor contiene todos los
    //datos que están en el segundo VectorProfesor.
    friend bool operator&& (const VectorProfesor &v_obj1,\
                            const VectorProfesor &v_obj2);

    // Versión 2: [VectorProfesor] && [Profesor]
    // Devuelve un int con el indice del VectorProfesor que
    // contiene al dato Profesor.
    // Si no está contenido, devuelve 0.
    friend int operator&& (const VectorProfesor &v_obj,\
                            const Profesor &obj);

    // Versión 3: [Profesor] && [VectorProfesor]
    // Devuelve un int con el indice del VectorProfesor que
    // contiene al dato Profesor.
    // Si no está contenido, devuelve 0.
    friend int operator&& (const Profesor &obj,\
                            const VectorProfesor &v_obj);

    // Versión 4: [VectorProfesor] && [string]
    // Devuelve un int con el indice del VectorProfesor que
    // contiene al dato Profesor cuyo campo clave coincide con el string.
    // Si no está contenido, devuelve 0.
    friend int operator&& (const VectorProfesor &v_obj,\
                            const string &cadena);

    // Versión 5: [string] && [VectorProfesor]
    // Devuelve un int con el indice del VectorProfesor que
    // contiene al dato Profesor cuyo campo clave coincide con el string.
    // Si no está contenido, devuelve 0.
    friend int operator&& (const string &cadena,\
                            const VectorProfesor &v_obj);
    /***************************************************************************/
    // Operator +=
    // Versión 1: [VectorProfesor] += [VectorProfesor]
    // Todos los valores del Profesor explícito se añaden (en el mismo orden en
    // el que están en el Profesor explícito) al Profesor implícito 
    // no se añadirá Profesor a VectorProfesor si ya está dentro
    VectorProfesor & operator+= (const VectorProfesor & v_obj);

    // Versión 2: [VectorProfesor] += [Profesor]
    //Añade un dato Profesor al final del Profesor implícito.
    // no se añadirá Profesor a VectorProfesor si ya está dentro
    VectorProfesor & operator+= (const Profesor & obj);

    /***************************************************************************/
    // Operador -=:
    // Versión 1: [VectorProfesor] -= [VectorProfesor]
    //Elimina del Profesor implícito los datos Profesor que
    // esté presente en los datos Profesor del Profesor
    //explícito.
    //si Profesor no se encuentra en el Profesor implícito no se hará nada 
    VectorProfesor & operator-= (const VectorProfesor & v_obj);

    //Versión 2: [VectorProfesor] -= [Profesor]
    //Elimina del Profesor implícito el dato Profesor
    //si Profesor no se encuentra en el Profesor implícito no se hará nada 
    VectorProfesor & operator-= (const Profesor & obj);

    //Versión 3: [VectorProfesor] -= [string]
    //Elimina del Profesor implícito el dato Profesor cuyo campo clave
    //sea igual al string dado
    //si Profesor no se encuentra en el Profesor implícito no se hará nada 
    VectorProfesor & operator-= (const string & obj);

    //Versión 4: [VectorProfesor] -= [int]
    //Elimina del Profesor implícito el dato Profesor cuyo indice sea int
    //si Profesor no se encuentra en el Profesor implícito no se hará nada 
    VectorProfesor & operator-= (const int & indice);


   /***************************************************************************/
    // INSERTAProfesor
    // Inserta Profesor en el vector
    // Parámetros: Profesor a insertar y posición en la que insertarlo
    // PRE: 1 <= indice <= Totalutilizados()
    // PRE: El Profesor no existe en el vector
    void InsertaProfesor(Profesor &obj, int indice);

    /***************************************************************************/
    // Elimina todos los Profesors del vector
    void EliminaTodos();

    /***************************************************************************/
    // EXTRAEProfesor
    // Extrae Profesor del vector
    // Elimina el Profesor indice del vector y lo devuelve
    // PRE: 1 <= indice <= Totalutilizados()
    Profesor ExtraeProfesor(int indice);

private:
    /*************************************************************************/
    //----------------------------MÉTODOS PRIVADOS----------------------------//
    /*************************************************************************/
    // COPIARDATOS
    // Copiar datos desde otro Profesor de la clase
    // Parámetros: otro (referencia), Profesor que sirve de modelo. 
    //
    // PRE: Se ha reservado memoria para los datos
    void CopiarDatos(const VectorProfesor &otro);

    /***************************************************************************/
    // ANIADEProfesor
    // Aniade Profesor al final del vector 
    // Dicho Profesor no puede estar repetido
    // Parámetros: obj (referencia), Profesor que se va a añadir.
    void AniadeProfesor(const Profesor &obj);

    /***************************************************************************/
    // Método BuscarDepto: Recibe una clave primaria y la busca en el vector
    // Si está, devuelve el índice donde está almacenado, sino, devuelve -1
    // Versión 1: Busca el Profesor dado un Profesor Profesor
    int BuscarProfesor(const Profesor &obj) const;

    // Versión 2: Busca el Profesor según el campo clave
    int BuscarProfesor(const string &cadena) const;

    /***************************************************************************/
    // ELIMINAProfesor
    // Elimina Profesor del vector
    // Parámetros: indice, int que indica el índice del Profesor
    // PRE: 1 <= indice <= Totalutilizados()
    void EliminaProfesor(int indice);

    /***********************************************************************/
    // RESERVAMEMORIA
    // Pide memoria para guardar una copia de los datos de "otro"
    // Parámetros: otro (referencia), Profesor que sirve de modelo. 
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
    Profesor & Valor(const int indice) const;

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