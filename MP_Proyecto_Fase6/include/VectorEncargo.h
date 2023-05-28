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
    // Crea un Encargo copia del Encargo proporcionado como argumento ("otro")
    // Parámetros: otro (referencia), Encargo que sirve de modelo. 
    VectorEncargo(const VectorEncargo &otro);

    /************************************************************************/
    // Constructor
    // Recibe como parámetro un Encargo que servirá para inicializar
    // el vector con un único elemento.
    VectorEncargo(const Encargo &obj);
 
    /************************************************************************/
    //Constructor.Construye un Encargo VectorEncargo a partir de la información guardada en un
    //fichero de texto llamado nombre.
    //Son válidas las mismas consideraciones que en el método de lectura: si el fichero
    //indicado no fuera del tipo esperado, el vector quedará vacío
    VectorEncargo (const string & nombre);
 
    /************************************************************************/
    // Destructor
    ~VectorEncargo();

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
    // Sustituye el elemento "indice" del vector por el Encargo proporcionado
    // Difiere de la sobrecarga = de la clase Encargo en que este método
    // comprueba que el Encargo proporcionado no se encuentre en la cadena
    // Es el método que recomiendo usar a la hora de alterar los elementos del vector
    // PRE: 1 <= indice <= totalutilizados
    void setEncargo(int indice, const Encargo &obj);


    /***************************************************************************/
    // OPERATOR >>:
    // Lee del flujo de entrada los datos de un VectorEncargo
    // Parámetros: flujo (referencia), flujo de entrada desde el que se leen los datos
    //             v_obj (referencia), VectorEncargo en el que se guardan los datos
    // PRE: El formato de los datos debe ser el siguiente:
    //      - Palabra clave: "EncargoES"
    //      - Encargoes (una por linea)
    //      - Comentarios, deben empezar por el caracter '#'
    //      - Fin de datos, se sobreentenderá por el fin del flujo de entrada
    friend istream & operator>> (istream &flujo, VectorEncargo &v_obj);

    /***************************************************************************/
    // OPERATOR <<:
    // Escribe en el flujo de salida los datos de un VectorEncargo
    // Parámetros: flujo (referencia), flujo de salida en el que se escriben los datos
    //             v_obj (referencia constante), VectorEncargo del que se leen los datos
    // PRE: El formato de los datos debe ser el siguiente:
    //      - Palabra clave: "EncargoES"
    //      - Encargoes (una por linea)
    //      - Comentarios, deben empezar por el caracter '#'
    //      - Fin de datos, se sobreentenderá por el fin del flujo de entrada
    friend ostream & operator<< (ostream &flujo, const VectorEncargo &v_obj);

    /***************************************************************************/
    // Método ToString
    // Devuelve un string con la serialización de los Encargos del vector implícito
    string ToString() const;

    /***************************************************************************/
    //Método de escritura. Guarda un dato Encargo en un fichero de texto llamado nombre.
    //Notas:
    //• Si el vector está vacío no se crea el fichero.
    //• El vector no se modifica.
    void GuardarVectorEncargo (const string & nombre) const;

    /***************************************************************************/
    //Método de lectura. Lee un dato Encargo de un fichero de texto llamado nombre.
    //Notas:
    //• El vector siempre se modifica.
    //• Si el fichero indicado no fuera un fichero del tipo esperado, el vector quedará
    //vacío.
    void RecuperarVectorEncargo (const string & nombre);
 
    /***********************************************************************/
    // Sobrecarga del operador de asignación para copia profunda.
    // Realiza una copia profunda de los datos de otro en el Encargo implícito.
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
    // Sobrecarga de operador +
    // Versión 1: VectorEncargo + VectorEncargo
    // Concatena dos datos VectorEncargo en uno nuevo. Los valo-
    // res del segundo se añaden (en el mismo orden) en una copia del primero.
    // Parámetros: otro (referencia), VectorEncargo que se añade.
    // no se añadirá Encargo a VectorEncargo si ya está dentro
    friend VectorEncargo operator+ (const VectorEncargo &uno, \
                                        const VectorEncargo &otro);

    //Versión 2: [VectorEncargo] + [Encargo]
    //Añade un dato Encargo al final de una copia del VectorEncargo.
    // no se añadirá Encargo a VectorEncargo si ya está dentro
    friend VectorEncargo operator+ (const VectorEncargo &v_obj, \
                                        const Encargo &obj);
    
    //Versión 3: [Encargo] + [VectorEncargo]
    // Inserta el dato Encargo al principio de una copia del
    // VectorEncargo.
    // no se añadirá Encargo a VectorEncargo si ya está dentro
    friend VectorEncargo operator+ (const Encargo &obj, \
                                           const VectorEncargo &v_obj);

    /***************************************************************************/
    //Versioperatorón 1: [VectorEncargo] - [VectorEncargo]
    //Elimina de una copia del Encargo implícito los datos Encargo cuyo
    //campo clave esté presente en los datos Encargo
    //del Encargo explícito.
    //si Encargo no se encuentra en el Encargo implícito no se hará nada 
    VectorEncargo operator- (const VectorEncargo &v_obj) const;

    //Versión 2: [VectorEncargo] - [Encargo]
    //Elimina de una copia del VectorEncargo el dato
    //Encargo cuyo campo clave sea igual al del
    //valor incluido en el Encargo Encargo.
    //si Encargo no se encuentra en el Encargo implícito no se hará nada 
    VectorEncargo operator- (const Encargo &obj) const;

    //Versión 3: [VectorEncargo] - [string]
    //Elimina de una copia del VectorEncargo el dato
    //Encargo cuyo campo clave sea igual al string dado.
    //si Encargo no se encuentra en el Encargo implícito no se hará nada 
    VectorEncargo operator- (const string &obj) const;

    /***************************************************************************/
    // Operator *
    //Versión 1: [VectorEncargo] * [VectorEncargo]
    //Devuelve un nuevo VectorEncargo que contiene to-
    //dos los datos Encargo comunes entre los dos VectorEncargo
    VectorEncargo operator* (const VectorEncargo &V_obj) const;

    /***************************************************************************/
    // Operator &&
    //Versión 1: [VectorEncargo] && [VectorEncargo]
    //Devuelve true si el primer VectorEncargo contiene todos los
    //datos que están en el segundo VectorEncargo.
    friend bool operator&& (const VectorEncargo &v_obj1,\
                            const VectorEncargo &v_obj2);

    // Versión 2: [VectorEncargo] && [Encargo]
    // Devuelve un int con el indice del VectorEncargo que
    // contiene al dato Encargo.
    // Si no está contenido, devuelve 0.
    friend int operator&& (const VectorEncargo &v_obj,\
                            const Encargo &obj);

    // Versión 3: [Encargo] && [VectorEncargo]
    // Devuelve un int con el indice del VectorEncargo que
    // contiene al dato Encargo.
    // Si no está contenido, devuelve 0.
    friend int operator&& (const Encargo &obj,\
                            const VectorEncargo &v_obj);

    // Versión 4: [VectorEncargo] && [string]
    // Devuelve un int con el indice del VectorEncargo que
    // contiene al dato Encargo cuyo campo clave coincide con el int.
    // Si no está contenido, devuelve 0.
    friend int operator&& (const VectorEncargo &v_obj,\
                            const string &numero);

    // Versión 5: [string] && [VectorEncargo]
    // Devuelve un int con el indice del VectorEncargo que
    // contiene al dato Encargo cuyo campo clave coincide con el string.
    // Si no está contenido, devuelve 0.
    friend int operator&& (const string &numero,\
                            const VectorEncargo &v_obj);
    /***************************************************************************/
    // Operator +=
    // Versión 1: [VectorEncargo] += [VectorEncargo]
    // Todos los valores del Encargo explícito se añaden (en el mismo orden en
    // el que están en el Encargo explícito) al Encargo implícito 
    // no se añadirá Encargo a VectorEncargo si ya está dentro
    VectorEncargo & operator+= (const VectorEncargo & v_obj);

    // Versión 2: [VectorEncargo] += [Encargo]
    //Añade un dato Encargo al final del Encargo implícito.
    // no se añadirá Encargo a VectorEncargo si ya está dentro
    VectorEncargo & operator+= (const Encargo & obj);

    /***************************************************************************/
    // Operador -=:
    // Versión 1: [VectorEncargo] -= [VectorEncargo]
    //Elimina del Encargo implícito los datos Encargo que
    // esté presente en los datos Encargo del Encargo
    //explícito.
    //si Encargo no se encuentra en el Encargo implícito no se hará nada 
    VectorEncargo & operator-= (const VectorEncargo & v_obj);

    //Versión 2: [VectorEncargo] -= [Encargo]
    //Elimina del Encargo implícito el dato Encargo
    //si Encargo no se encuentra en el Encargo implícito no se hará nada 
    VectorEncargo & operator-= (const Encargo & obj);

    //Versión 3: [VectorEncargo] -= [string]
    //Elimina del Encargo implícito el dato Encargo cuyo campo clave
    //sea igual al string dado
    //si Encargo no se encuentra en el Encargo implícito no se hará nada 
    VectorEncargo & operator-= (const string & obj);

    //Versión 4: [VectorEncargo] -= [int]
    //Elimina del Encargo implícito el dato Encargo cuyo indice sea int
    //si Encargo no se encuentra en el Encargo implícito no se hará nada 
    VectorEncargo & operator-= (const int & indice);


   /***************************************************************************/
    // INSERTAEncargo
    // Inserta Encargo en el vector
    // Parámetros: Encargo a insertar y posición en la que insertarlo
    // PRE: 1 <= indice <= Totalutilizados()
    // PRE: El Encargo no existe en el vector
    void InsertaEncargo(Encargo &obj, int indice);

    /***************************************************************************/
    // Elimina todos los Encargos del vector
    void EliminaTodos();

    /***************************************************************************/
    // EXTRAEEncargo
    // Extrae Encargo del vector
    // Elimina el Encargo indice del vector y lo devuelve
    // PRE: 1 <= indice <= Totalutilizados()
    Encargo ExtraeEncargo(int indice);

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

    /***************************************************************************/
    // ANIADEEncargo
    // Aniade Encargo al final del vector 
    // Dicho Encargo no puede estar repetido
    // Parámetros: obj (referencia), Encargo que se va a añadir.
    void AniadeEncargo(const Encargo &obj);

    /***************************************************************************/
    // Método BuscarDepto: Recibe una clave primaria y la busca en el vector
    // Si está, devuelve el índice donde está almacenado, sino, devuelve -1
    // Versión 1: Busca el Encargo dado un Encargo Encargo
    int BuscarEncargo(const Encargo &obj) const;

    // Versión 2: Busca el Encargo según el campo clave
    int BuscarEncargo(const int &numero) const;

    /***************************************************************************/
    // ELIMINAEncargo
    // Elimina Encargo del vector
    // Parámetros: indice, int que indica el índice del Encargo
    // PRE: 1 <= indice <= Totalutilizados()
    void EliminaEncargo(int indice);

    /***********************************************************************/
    // RESERVAMEMORIA
    // Pide memoria para guardar una copia de los datos de "otro"
    // Parámetros: otro (referencia), Encargo que sirve de modelo. 
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
    Encargo & Valor(const int indice) const;

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