/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// AUTOR: MARCO GIRELA VIDA
// GRUPO: 1ºB
// FECHA: xx/05/2023
//
// RELACION DE PROBLEMAS 4
//
//  
// 
//
// Declaraciones en: VectorEncargo.h
//
// Fichero: VectorEncargo.cpp
//
/***************************************************************************/
/***************************************************************************/

#include "VectorEncargo.h"

using namespace std;

/*************************************************************************/
//-------------------------CONSTRUCTORES---------------------------------//
/*************************************************************************/
/***********************************************************************/
// Constructor
// Si se llama sin argumentos crea una secuencia con capacidad = TAMANIO.
// Si se llama con un argumento, su valor será la capacidad inicial. 
// POST: La secuencia creada estará vacía (EstaVacia()== true)
VectorEncargo :: VectorEncargo(int la_capacidad)
        : capacidad(0), total_utilizados(0), vector_privado(nullptr)
{
    ReservaMemoria(la_capacidad);
}

/************************************************************************/
// Constructor de copia
// Crea un Encargo copia del Encargo proporcionado como argumento ("otro")
// Parámetros: otro (referencia), Encargo que sirve de modelo. 
VectorEncargo :: VectorEncargo(const VectorEncargo &otro)
        : capacidad(0), total_utilizados(0), vector_privado(nullptr)
{
    (*this) = otro;
}

/************************************************************************/
// Constructor
// Recibe como parámetro un Encargo que servirá para inicializar
// el vector con un único elemento.
VectorEncargo :: VectorEncargo(const Encargo &obj)
        : capacidad(0), total_utilizados(0), vector_privado(nullptr)
{   
    ReservaMemoria(TAMANIO);
    AniadeEncargo(obj);
}

/************************************************************************/
// Destructor
VectorEncargo :: ~VectorEncargo()
{
    LiberarMemoria();
}

/*************************************************************************/
//----------------------------MÉTODOS------------------------------------//
/*************************************************************************/
// Métodos de acceso a los campos de la clase
// Totalutilizados: Devuelve el número de elementos utilizados
int VectorEncargo :: Totalutilizados() const
{
    return total_utilizados;
}

// Capacidad: Devuelve la capacidad actual del vector
int VectorEncargo :: Capacidad() const
{
    return capacidad;
}

// EstaVacia: Devueve true si totalutilizados es 0 y false en caso contrario
int VectorEncargo :: EstaVacia() const
{
    return (Totalutilizados() == 0);
}

/***************************************************************************/
// Métodos set
// Sustituye el elemento "indice" del vector por el Encargo proporcionado
// Difiere de la sobrecarga = de la clase Encargo en que este método
// comprueba que el Encargo proporcionado no se encuentre en la cadena
// Es el método que recomiendo usar a la hora de alterar los elementos del vector
// PRE: 1 <= indice <= totalutilizados
void VectorEncargo :: setEncargo(int indice, const Encargo &obj)
{
    //cerr << "El objeto a añadir está contenido: " << posicion << endl;

    if ((*this) && obj)
    {
        cerr << "Error: El Encargo ya existe" << endl;
        exit(1);
    }

    (*this)[indice] = obj;
}

/***************************************************************************/
// Método ToString
// Devuelve un string con la serialización de los Encargos del vector implícito
string VectorEncargo :: ToString() const
{
    string cad;

    for (int i = 1; i <= Totalutilizados(); i++)
    {
        int numero = i;
        string cadena_inicial = to_string(numero) + ".- ";
        cad += (*this)[i].ToString(cadena_inicial) + "\n";
    }

    return cad;
}

/***********************************************************************/
// Sobrecarga del operador de asignación para copia profunda.
// Realiza una copia profunda de los datos de otro en el Encargo implícito.
// Parámetros: otro (referencia), Encargo que sirve de modelo. 
VectorEncargo & VectorEncargo :: operator=(const VectorEncargo &otro)
{ 
    CopiarDatos(otro);
    return *this;
}

/***********************************************************************/
// Sobrecarga del [].
// Parámetros: indice del elemento a consultar (total_utilizados => indice => 1)
Encargo & VectorEncargo :: operator[](int indice) const
{
    comprobacion_indice_totalutilizados(indice);
    return Valor(indice-1);
}

/***********************************************************************/
// Sobrecarga del ().
// Parámetros: indice del elemento a modificar (total_utilizados => indice > 0)
Encargo & VectorEncargo :: operator[](int indice)
{
    comprobacion_indice_capacidad(indice);
    return Valor(indice-1);
}

/***********************************************************************/
// Sobrecarga del ().
// Parámetros: indice del elemento a consultar (total_utilizados => indice > 0)
Encargo & VectorEncargo :: operator()(int indice) const
{
    return (*this)[indice];
}

/***********************************************************************/
// Sobrecarga del ().
// Parámetros: indice del elemento a modificar (total_utilizados => indice > 0)
Encargo & VectorEncargo :: operator()(int indice)
{
    return (*this)[indice];
}

/***************************************************************************/
// Sobrecarga de operador +
// Versión 1: VectorEncargo + VectorEncargo
// Concatena los datos VectorEncargo en uno nuevo. Los valo-
// res del segundo se añaden (en el mismo orden) en una copia del primero.
// Parámetros: otro (referencia), VectorEncargo que se añade.
// no se añadirá Encargo a VectorEncargo si ya está dentro
VectorEncargo operator+ (const VectorEncargo &uno, \
                              const VectorEncargo &otro)
{
    VectorEncargo copia(uno);

    for (int i = 1; i <= otro.Totalutilizados(); i++)
    {
        copia += otro[i];
    }

    return copia;
}

//Versión 2: [VectorEncargo] + [Encargo]
//Añade un dato Encargo al final de una copia del VectorEncargo.
// no se añadirá Encargo a VectorEncargo si ya está dentro
VectorEncargo operator+ (const VectorEncargo &v_obj, \
                              const Encargo &obj)
{
    VectorEncargo copia(v_obj);
    copia += obj;
    return copia;
}

// Versión 3: [Encargo] + [VectorEncargo]
// Inserta el dato Encargo al principio de una copia del
// VectorEncargo.
// no se añadirá Encargo a VectorEncargo si ya está dentro
VectorEncargo operator+ (const Encargo &obj, \
                              const VectorEncargo &v_obj)
{
    return v_obj + obj;
}

/***************************************************************************/
//Versioperatorón 1: [VectorEncargo] - [VectorEncargo]
//Elimina de una copia del Encargo implícito los datos Encargo cuyo
//campo clave esté presente en los datos Encargo
//del Encargo explícito.
//si Encargo no se encuentra en el Encargo implícito no se hará nada 
VectorEncargo VectorEncargo :: operator-
                                    (const VectorEncargo &v_obj) const
{
    VectorEncargo copia(*this);
    copia -= v_obj;

    return copia;
}

//Versión 2: [VectorEncargo] - [Encargo]
//Elimina de una copia del VectorEncargo el dato
//Encargo cuyo campo clave sea igual al del
//valor incluido en el Encargo Encargo.
//si Encargo no se encuentra en el Encargo implícito no se hará nada 
VectorEncargo VectorEncargo :: operator-
                                            (const Encargo &obj) const
{
    VectorEncargo copia(*this);

    copia -= obj;

    return copia;
}

//Versión 3: [VectorEncargo] - [string]
//Elimina de una copia del VectorEncargo el dato
//Encargo cuyo campo clave sea igual al string dado.
//si Encargo no se encuentra en el Encargo implícito no se hará nada 
VectorEncargo VectorEncargo :: operator- (const string &cadena) const
{
    VectorEncargo copia(*this);

    copia -= cadena;

    return copia;
}

/***************************************************************************/
// Operator *
//Versión 1: [VectorEncargo] * [VectorEncargo]
//Devuelve un nuevo VectorEncargo que contiene to-
//dos los datos VectorEncargo comunes entre los dos VectorEncargo
VectorEncargo VectorEncargo :: operator*
                                    (const VectorEncargo &v_obj) const
{
    VectorEncargo comunes;

    for (int i = 1; i <= Totalutilizados(); i++)
    {
        if (v_obj && (*this)[i])
        {
            comunes += (*this)[i];
        }
    }
    
    return comunes;
}

/***************************************************************************/
// Operator &&
//Versión 1: [VectorEncargo] && [VectorEncargo]
//Devuelve true si el primer VectorEncargo contiene todos los
//datos que están en el segundo VectorEncargo.
bool operator&& (const VectorEncargo &v_obj1,\
                        const VectorEncargo &v_obj2)
{
    bool estan_todos = true;

    if (v_obj1.Totalutilizados() < v_obj2.Totalutilizados())
    {
        estan_todos = false;
    }

    for (int i = 1; i <= v_obj2.Totalutilizados() && estan_todos; i++)
    {
        if (!(v_obj1 && v_obj2[i]))
        {
            estan_todos = false;
        }
    }
    
    return estan_todos;
}

// Versión 2: [VectorEncargo] && [Encargo]
// Devuelve un int con el indice del VectorEncargo que
// contiene al dato Encargo.
// Si no está contenido, devuelve 0.
int operator&& (const VectorEncargo &v_obj,\
                        const Encargo &obj)
{
    return v_obj.BuscarEncargo(obj);
}
// Versión 3: [Encargo] && [VectorEncargo]
// Devuelve un int con el indice del VectorEncargo que
// contiene al dato Encargo.
// Si no está contenido, devuelve 0.
int operator&& (const Encargo &obj,\
                        const VectorEncargo &v_obj)
{
    return v_obj && obj;
}

// Versión 4: [VectorEncargo] && [string]
// Devuelve un int con el indice del VectorEncargo que
// contiene al dato Encargo cuyo campo clave coincide con el string.
// Si no está contenido, devuelve 0.
int operator&& (const VectorEncargo &v_obj,\
                        const int &numero)
{
    return v_obj.BuscarEncargo(numero);
}

// Versión 5: [string] && [VectorEncargo]
// Devuelve un int con el indice del VectorEncargo que
// contiene al dato Encargo cuyo campo clave coincide con el string.
// Si no está contenido, devuelve 0.
int operator&& (const int &numero,\
                        const VectorEncargo &v_obj)
{
    return v_obj && numero;
}
/***************************************************************************/
// Operator +=
// Versión 1: [VectorEncargo] += [VectorEncargo]
// Todos los valores del Encargo explícito se añaden (en el mismo orden en
// el que están en el Encargo explícito) al Encargo implícito 
// no se añadirá Encargo a VectorEncargo si ya está dentro
VectorEncargo & VectorEncargo :: operator+= (const VectorEncargo & v_obj)
{
   *this = *this + v_obj;
    
    return *this;
}

// Versión 2: [VectorEncargo] += [Encargo]
//Añade un dato Encargo al final del Encargo implícito.
// no se añadirá Encargo a VectorEncargo si ya está dentro
VectorEncargo & VectorEncargo :: operator+= (const Encargo & obj)
{
    (*this).AniadeEncargo(obj);
    return (*this);
}

/***************************************************************************/
// Operador -=:
// Versión 1: [VectorEncargo] -= [VectorEncargo]
//Elimina del Encargo implícito los datos Encargo que
// esté presente en los datos Encargo del Encargo
//explícito.
//si Encargo no se encuentra en el Encargo implícito no se hará nada 
VectorEncargo & VectorEncargo :: operator-= (const VectorEncargo & v_obj)
{

    for (int i = 1; i <= v_obj.Totalutilizados(); i++)
    {
        (*this) -= v_obj[i];
    }

    return *this;
}

//Versión 2: [VectorEncargo] -= [Encargo]
//Elimina del Encargo implícito el dato Encargo
//si Encargo no se encuentra en el Encargo implícito no se hará nada 
VectorEncargo & VectorEncargo :: operator-= (const Encargo & obj)
{
    (*this) -= ((*this) && obj);

    return *this;
}

//Versión 3: [VectorEncargo] -= [string]
//Elimina del Encargo implícito el dato Encargo cuyo campo clave
//sea igual al string dado
//si Encargo no se encuentra en el Encargo implícito no se hará nada 
VectorEncargo & VectorEncargo :: operator-= (const string & obj)
{
    (*this) -= ((*this) && obj);

    return *this;
}

//Versión 4: [VectorEncargo] -= [int]
//Elimina del Encargo implícito el dato Encargo cuyo indice sea int
//si Encargo no se encuentra en el Encargo implícito no se hará nada 
VectorEncargo & VectorEncargo :: operator-= (const int & indice)
{
    if (indice_valido_usados(indice))
    {
        EliminaEncargo(indice);
    }

    return *this;
}


/***************************************************************************/
// INSERTAEncargo
// Inserta Encargo en el vector
// Parámetros: Encargo a insertar y posición en la que insertarlo
// PRE: 1 <= indice <= Totalutilizados()
// PRE: El Encargo no existe en el vector
void VectorEncargo :: InsertaEncargo(Encargo &obj, int indice)
{
    // Realmente el método set ya hace esta comprobación, pero hasta llegar a
    // el se altera por completo el vector, asi que hago la comprobación por dos
    if ((*this) && obj)
    {
        cerr << "Error: Se ha intentado insertar un Encargo que ya existe"\
             << endl;
        exit(1);
    }
    
    total_utilizados++;

    // Le hago hueco al elemento para introducirlo
    for (int i = Totalutilizados(); i >= indice; i--)
    {
        (*this)[i] = (*this)[i-1];
    }

    setEncargo(indice, obj);

    Redimensionar();

}


/***************************************************************************/
// Elimina todos los Encargos del vector
void VectorEncargo :: EliminaTodos()
{
    LiberarMemoria();

    // Redimensionar hace que se ajuste capacidad al tamaño mínimo
    Redimensionar();
}

/***************************************************************************/
// EXTRAEEncargo
// Extrae Encargo del vector
// Elimina el Encargo indice del vector y lo devuelve
// PRE: 1 <= indice <= Totalutilizados()
Encargo VectorEncargo :: ExtraeEncargo(int indice)
{
    Encargo obj((*this)[indice]);

    (*this) -= (*this)[indice];

    return obj;
}

/*************************************************************************/
//----------------------------MÉTODOS PRIVADOS----------------------------//
/*************************************************************************/
// COPIARDATOS
// Copiar datos desde otro Encargo de la clase
// Parámetros: otro (referencia), Encargo que sirve de modelo. 
//
// PRE: Se ha reservado memoria para los datos
void VectorEncargo :: CopiarDatos(const VectorEncargo &otro)
{
    if (this != &otro)
    {
        LiberarMemoria();
        ReservaMemoria(otro.Capacidad());

        for (int i = 1; i <= otro.Totalutilizados(); i++)
        {
            setEncargo(i, otro[i]);
            //(*this)[i] = otro[i]; <-- Más elegante, pero no hace comprobación
        }

        total_utilizados = otro.Totalutilizados();
    }

    // Redimensiono para no estár "ajustado" entre capacidad y total_utilizados
    //Redimensionar();
}

/***************************************************************************/
// BUSCAREncargo
// Método BuscarEncargo: Recibe un Encargo y lo busca en el vector
// Si está, devuelve el índice donde está almacenado, sino, devuelve 0
// Versión 1: Busca el Encargo dado un Encargo Encargo
int VectorEncargo :: BuscarEncargo(const Encargo &obj) const
{
    int indice = 0;

    for (int i = 1; i <= Totalutilizados(); i++)
    {
        if ((*this)[i] == obj)
        {
            indice = i;
        }
    }

    return indice;
}

// Versión 2: Busca el Encargo según el campo clave ********
int VectorEncargo :: BuscarEncargo(const int &numero) const
{
    int indice = 0;
    for (int i = 1; i <= Totalutilizados(); i++)
    {
        if ((*this)[i].getCategoria() == numero)
        {
            indice = i;
        }
    }

    return indice;
}

/***************************************************************************/
// ANIADEEncargo
// Aniade Encargo al final del vector 
// Dicho Encargo no puede estar repetido
// Parámetros: obj (referencia), Encargo que se va a añadir.
void VectorEncargo :: AniadeEncargo(const Encargo &obj)
{
    total_utilizados++;

    // SetEncargo comprueba si está repetido
    setEncargo(Totalutilizados(), obj);

    Redimensionar();
}

/***************************************************************************/
// ELIMINAEncargo
// Elimina Encargo del vector
// Parámetros: indice, int que indica el índice del Encargo
// PRE: 1 <= indice <= Totalutilizados()
void VectorEncargo :: EliminaEncargo(int indice)
{
    if(indice_valido_usados(indice))
    {
        // "Desplazar" los valores desde la casilla siguiente a "indice" 
        // hasta el final una posición a la izquierda
		memmove (&(*this)[indice-1], &(*this)[indice], 
                 (Totalutilizados()-indice)*sizeof(Encargo));

        total_utilizados--;
        Redimensionar();
    }
}

/***********************************************************************/
// RESERVAMEMORIA
// Pide memoria para guardar una copia de los datos de "otro"
// Parámetros: num_casillas: Número de casillas que se desean reservar. 
// PRE: num_casillas > 0
void VectorEncargo :: ReservaMemoria(const int num_casillas)
{
    if (num_casillas < 0)
    {
        cerr << "Error: El número de casillas debe ser mayor que 0" << endl;
        exit(1);
    }
    
	vector_privado = new Encargo[num_casillas]; 
	capacidad = num_casillas; 
}

/***********************************************************************/
// LIBERARMEMORIA
// Libera la memoria dinámica reservada para el vector
void VectorEncargo :: LiberarMemoria()
{
    if (!EstaVacia())
	{ 
		delete [] vector_privado;

		vector_privado = nullptr;
		capacidad = 0; 
		total_utilizados = 0;
	}
}

/***************************************************************************/
// REAJUSTAR
// Iguala capacidad a total_utilizados (no recomendable, mejor usar redimensionar,
// (Más que nada para no tener total_utilizados siempre "pegado" a capacidad)
void VectorEncargo :: Reajustar()
{
    if (Totalutilizados() < Capacidad())
    {
        capacidad = Totalutilizados();
        // Copio el vector en uno temporal
        Encargo *tmp = new Encargo[Totalutilizados()];

        // Borro el original
        delete [] vector_privado;

        // Lo igualo al temporal
        vector_privado = tmp;
    }
}

/***********************************************************************/
// REDIMENSIONAR
// Redimensiona el vector dinámico y copia los datos en el nuevo almacén.  
//
// Pedirá memoria adicional si el número de casillas usadas es superior 
// al "PROC_PETICION" de la capacidad actual. El número de casillas 
// adicionales será el "PORC_CRECIMIENTO" de la capacidad actual
/* 
	Una consecuencia de la eliminación podría ser la reducción de la 
	capacidad de la secuencia. Esto ocurrirá cuando el número de casillas 
	usadas es inferior al "PROC_REDUCCION" de la capacidad actual.

	El número de casillas finales no será fijo, sino que será un "PORC_EXTRA" 
	superior a la ocupación de la secuencia después de la eliminación. 
*/
void VectorEncargo :: Redimensionar (void)
{
    bool haceralgo = true;

    if (total_utilizados < PORC_REDUCCION*capacidad/100)
    {
        int casillas_extra = PORC_EXTRA*capacidad/100;

        capacidad = total_utilizados + casillas_extra;
    }

    else if (total_utilizados > PORC_PETICION*capacidad/100)
    {
        int casillas_adicionales = (PORC_CRECIMIENTO*capacidad)/100;

        int minimo = MIN_CRECIMIENTO;
        capacidad += max(casillas_adicionales,minimo);
    }

    else
    {
        haceralgo = false;
    }

    // Si la capacidad es 0, la pongo a TAMANIO
    if (!capacidad)
    {
        capacidad = TAMANIO;
    }

    if (haceralgo)
    {
        #ifdef DEBUG_SECUENCIA
        cout << endl;
        cout << "REDIMENSIONADO HASTA --> " << capacidad << " CASILLAS" << endl;
        cout << endl;
        #endif

        // Pedir memoria para el nuevo almacen 
        // Versión Antigua: (por si acaso)
        Encargo * tmp = new Encargo[capacidad];

        for (int i = 1; i <= Totalutilizados() && Totalutilizados(); i++)
        {
            tmp[i-1] = (*this)[i];
        }

        delete [] vector_privado;
        vector_privado = tmp;
    }
}

/***********************************************************************/
// VALOR: Devuelve el valor de la Adscripcion en la posición "indice"
// Puede funcionar como lvalue y como rvalue
// Es el único método que usa y debe usar el índice "real" (desde 0)
// PRE: 0 <= indice < total_utilizados
Encargo & VectorEncargo :: Valor(int indice) const
{
    return vector_privado[indice];
}

/***********************************************************************/
// comprobacion_indice: Comprueba si el índice es válido
// En caso que lo sea, devuelve un mensaje de error y termina el programa
// PRE: 1 <= indice <= total_utilizados
void VectorEncargo :: comprobacion_indice_totalutilizados(const int indice) const
{
    if (!indice_valido_usados(indice))
    {
        cerr << "Error en sobrecargo [] const: índice fuera de rango" << endl;
        cerr << "El índice debe estar entre 1 y " << Totalutilizados() << endl;
        cerr << "El índice introducido es: " << indice << endl;
        exit(1);
    }
}

/***********************************************************************/
// comprobacion_indice: Comprueba si el índice es válido
// En caso que lo sea, devuelve un mensaje de error y termina el programa
// PRE: 1 <= indice <= capacidad
void VectorEncargo :: comprobacion_indice_capacidad(const int indice) const
{
    if (!indice_valido_capacidad(indice))
    {
        cerr << "Error en sobrecarga [] no-const: índice fuera de rango" << endl;
        cerr << "El índice debe estar entre 1 y " << Capacidad() << endl;
        cerr << "El índice introducido es: " << indice << endl;
        exit(1);
    }
}

/***********************************************************************/
// Indice_valido_usados: Comprueba si el índice es válido
// Devuelve true si el índice está entre 1 y total_utilizados
// Devuelve false en caso contrario
bool VectorEncargo ::  indice_valido_usados(const int indice) const
{
    return (indice >= 1 && indice <= Totalutilizados());
}

/***********************************************************************/
// Indice_valido_capacidad: Comprueba si el índice es válido
// Devuelve true si el índice está entre 1 y capacidad
// Devuelve false en caso contrario
bool VectorEncargo ::  indice_valido_capacidad(const int indice) const
{
    return (indice >= 1 && indice <= Capacidad());
}
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

