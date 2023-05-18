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
// Declaraciones en: VectorAdscripcion.h
//
// Fichero: VectorAdscripcion.cpp
//
/***************************************************************************/
/***************************************************************************/

#include "VectorAdscripcion.h"

using namespace std;

/*************************************************************************/
//-------------------------CONSTRUCTORES---------------------------------//
/*************************************************************************/
/***********************************************************************/
// Constructor
// Si se llama sin argumentos crea una secuencia con capacidad = TAMANIO.
// Si se llama con un argumento, su valor será la capacidad inicial. 
// POST: La secuencia creada estará vacía (EstaVacia()== true)
VectorAdscripcion :: VectorAdscripcion(int la_capacidad)
        : capacidad(0), total_utilizados(0), vector_privado(nullptr)
{
    ReservaMemoria(la_capacidad);
}

/************************************************************************/
// Constructor de copia
// Crea un Adscripcion copia del Adscripcion proporcionado como argumento ("otro")
// Parámetros: otro (referencia), Adscripcion que sirve de modelo. 
VectorAdscripcion :: VectorAdscripcion(const VectorAdscripcion &otro)
        : capacidad(0), total_utilizados(0), vector_privado(nullptr)
{
    (*this) = otro;
}

/************************************************************************/
// Constructor
// Recibe como parámetro un Adscripcion que servirá para inicializar
// el vector con un único elemento.
VectorAdscripcion :: VectorAdscripcion(const Adscripcion &obj)
        : capacidad(0), total_utilizados(0), vector_privado(nullptr)
{   
    ReservaMemoria(TAMANIO);
    AniadeAdscripcion(obj);
}

/************************************************************************/
// Destructor
VectorAdscripcion :: ~VectorAdscripcion()
{
    EliminaTodos();
}

/*************************************************************************/
//----------------------------MÉTODOS------------------------------------//
/*************************************************************************/
// Métodos de acceso a los campos de la clase
// Totalutilizados: Devuelve el número de elementos utilizados
int VectorAdscripcion :: Totalutilizados() const
{
    return total_utilizados;
}

// Capacidad: Devuelve la capacidad actual del vector
int VectorAdscripcion :: Capacidad() const
{
    return capacidad;
}

// EstaVacia: Devueve true si totalutilizados es 0 y false en caso contrario
int VectorAdscripcion :: EstaVacia() const
{
    return (Totalutilizados() == 0);
}

/***************************************************************************/
// Métodos set
// Sustituye el elemento "indice" del vector por el Adscripcion proporcionado
// Difiere de la sobrecarga = de la clase Adscripcion en que este método
// comprueba que el Adscripcion proporcionado no se encuentre en la cadena
// Es el método que recomiendo usar a la hora de alterar los elementos del vector
// PRE: 1 <= indice <= totalutilizados
void VectorAdscripcion :: setAdscripcion(int indice, const Adscripcion &obj)
{
    if ((*this) && obj)
    {
        cerr << "Error: El Adscripcion ya existe" << endl;
        exit(1);
    }

    (*this)[indice] = obj;
}

/***************************************************************************/
// Método ToString
// Devuelve un string con la serialización de los Adscripcions del vector implícito
string VectorAdscripcion :: ToString() const
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
// Realiza una copia profunda de los datos de otro en el Adscripcion implícito.
// Parámetros: otro (referencia), Adscripcion que sirve de modelo. 
VectorAdscripcion & VectorAdscripcion :: operator=(const VectorAdscripcion &otro)
{ 
    CopiarDatos(otro);
    return *this;
}

/***********************************************************************/
// Sobrecarga del [].
// Parámetros: indice del elemento a consultar (total_utilizados => indice => 1)
Adscripcion & VectorAdscripcion :: operator[](int indice) const
{
    comprobacion_indice_totalutilizados(indice);
    return Valor(indice-1);
}

/***********************************************************************/
// Sobrecarga del ().
// Parámetros: indice del elemento a modificar (total_utilizados => indice > 0)
Adscripcion & VectorAdscripcion :: operator[](int indice)
{
    comprobacion_indice_capacidad(indice);
    return Valor(indice-1);
}

/***********************************************************************/
// Sobrecarga del ().
// Parámetros: indice del elemento a consultar (total_utilizados => indice > 0)
Adscripcion & VectorAdscripcion :: operator()(int indice) const
{
    return (*this)[indice];
}

/***********************************************************************/
// Sobrecarga del ().
// Parámetros: indice del elemento a modificar (total_utilizados => indice > 0)
Adscripcion & VectorAdscripcion :: operator()(int indice)
{
    return (*this)[indice];
}

/***************************************************************************/
// Sobrecarga de operador +
// Versión 1: VectorAdscripcion + VectorAdscripcion
// Concatena los datos VectorAdscripcion en uno nuevo. Los valo-
// res del segundo se añaden (en el mismo orden) en una copia del primero.
// Parámetros: otro (referencia), VectorAdscripcion que se añade.
// no se añadirá Adscripcion a VectorAdscripcion si ya está dentro
VectorAdscripcion operator+ (const VectorAdscripcion &uno, \
                              const VectorAdscripcion &otro)
{
    VectorAdscripcion copia(uno);

    for (int i = 1; i <= otro.Totalutilizados(); i++)
    {
        copia += otro[i];
    }

    return copia;
}

//Versión 2: [VectorAdscripcion] + [Adscripcion]
//Añade un dato Adscripcion al final de una copia del VectorAdscripcion.
// no se añadirá Adscripcion a VectorAdscripcion si ya está dentro
VectorAdscripcion operator+ (const VectorAdscripcion &v_obj, \
                              const Adscripcion &obj)
{
    VectorAdscripcion copia(v_obj);
    copia += obj;
    return copia;
}

// Versión 3: [Adscripcion] + [VectorAdscripcion]
// Inserta el dato Adscripcion al principio de una copia del
// VectorAdscripcion.
// no se añadirá Adscripcion a VectorAdscripcion si ya está dentro
VectorAdscripcion operator+ (const Adscripcion &obj, \
                              const VectorAdscripcion &v_obj)
{
    return v_obj + obj;
}

/***************************************************************************/
//Versioperatorón 1: [VectorAdscripcion] - [VectorAdscripcion]
//Elimina de una copia del Adscripcion implícito los datos Adscripcion cuyo
//campo clave esté presente en los datos Adscripcion
//del Adscripcion explícito.
//si Adscripcion no se encuentra en el Adscripcion implícito no se hará nada 
VectorAdscripcion VectorAdscripcion :: operator-
                                    (const VectorAdscripcion &v_obj) const
{
    VectorAdscripcion copia(*this);
    copia -= v_obj;

    return copia;
}

//Versión 2: [VectorAdscripcion] - [Adscripcion]
//Elimina de una copia del VectorAdscripcion el dato
//Adscripcion cuyo campo clave sea igual al del
//valor incluido en el Adscripcion Adscripcion.
//si Adscripcion no se encuentra en el Adscripcion implícito no se hará nada 
VectorAdscripcion VectorAdscripcion :: operator-
                                            (const Adscripcion &obj) const
{
    VectorAdscripcion copia(*this);

    copia -= obj;

    return copia;
}

//Versión 3: [VectorAdscripcion] - [string]
//Elimina de una copia del VectorAdscripcion el dato
//Adscripcion cuyo campo clave sea igual al string dado.
//si Adscripcion no se encuentra en el Adscripcion implícito no se hará nada 
VectorAdscripcion VectorAdscripcion :: operator- (const string &cadena) const
{
    VectorAdscripcion copia(*this);

    copia -= cadena;

    return copia;
}

/***************************************************************************/
// Operator *
//Versión 1: [VectorAdscripcion] * [VectorAdscripcion]
//Devuelve un nuevo VectorAdscripcion que contiene to-
//dos los datos VectorAdscripcion comunes entre los dos VectorAdscripcion
VectorAdscripcion VectorAdscripcion :: operator*
                                    (const VectorAdscripcion &v_obj) const
{
    VectorAdscripcion comunes;

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
//Versión 1: [VectorAdscripcion] && [VectorAdscripcion]
//Devuelve true si el primer VectorAdscripcion contiene todos los
//datos que están en el segundo VectorAdscripcion.
bool operator&& (const VectorAdscripcion &v_obj1,\
                        const VectorAdscripcion &v_obj2)
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

// Versión 2: [VectorAdscripcion] && [Adscripcion]
// Devuelve un int con el indice del VectorAdscripcion que
// contiene al dato Adscripcion.
// Si no está contenido, devuelve 0.
int operator&& (const VectorAdscripcion &v_obj,\
                        const Adscripcion &obj)
{
    return v_obj.BuscarAdscripcion(obj);
}
// Versión 3: [Adscripcion] && [VectorAdscripcion]
// Devuelve un int con el indice del VectorAdscripcion que
// contiene al dato Adscripcion.
// Si no está contenido, devuelve 0.
int operator&& (const Adscripcion &obj,\
                        const VectorAdscripcion &v_obj)
{
    return v_obj && obj;
}

// Versión 4: [VectorAdscripcion] && [string]
// Devuelve un int con el indice del VectorAdscripcion que
// contiene al dato Adscripcion cuyo campo clave coincide con el string.
// Si no está contenido, devuelve 0.
int operator&& (const VectorAdscripcion &v_obj,\
                        const string &cadena)
{
    return v_obj.BuscarAdscripcion(cadena);
}

// Versión 5: [string] && [VectorAdscripcion]
// Devuelve un int con el indice del VectorAdscripcion que
// contiene al dato Adscripcion cuyo campo clave coincide con el string.
// Si no está contenido, devuelve 0.
int operator&& (const string &cadena,\
                        const VectorAdscripcion &v_obj)
{
    return v_obj && cadena;
}
/***************************************************************************/
// Operator +=
// Versión 1: [VectorAdscripcion] += [VectorAdscripcion]
// Todos los valores del Adscripcion explícito se añaden (en el mismo orden en
// el que están en el Adscripcion explícito) al Adscripcion implícito 
// no se añadirá Adscripcion a VectorAdscripcion si ya está dentro
VectorAdscripcion & VectorAdscripcion :: operator+= (const VectorAdscripcion & v_obj)
{
   *this = *this + v_obj;
    
    return *this;
}

// Versión 2: [VectorAdscripcion] += [Adscripcion]
//Añade un dato Adscripcion al final del Adscripcion implícito.
// no se añadirá Adscripcion a VectorAdscripcion si ya está dentro
VectorAdscripcion & VectorAdscripcion :: operator+= (const Adscripcion & obj)
{
    (*this).AniadeAdscripcion(obj);
    return (*this);
}

/***************************************************************************/
// Operador -=:
// Versión 1: [VectorAdscripcion] -= [VectorAdscripcion]
//Elimina del Adscripcion implícito los datos Adscripcion que
// esté presente en los datos Adscripcion del Adscripcion
//explícito.
//si Adscripcion no se encuentra en el Adscripcion implícito no se hará nada 
VectorAdscripcion & VectorAdscripcion :: operator-= (const VectorAdscripcion & v_obj)
{

    for (int i = 1; i <= v_obj.Totalutilizados(); i++)
    {
        (*this) -= v_obj[i];
    }

    return *this;
}

//Versión 2: [VectorAdscripcion] -= [Adscripcion]
//Elimina del Adscripcion implícito el dato Adscripcion
//si Adscripcion no se encuentra en el Adscripcion implícito no se hará nada 
VectorAdscripcion & VectorAdscripcion :: operator-= (const Adscripcion & obj)
{
    (*this) -= ((*this) && obj);

    return *this;
}

//Versión 3: [VectorAdscripcion] -= [string]
//Elimina del Adscripcion implícito el dato Adscripcion cuyo campo clave
//sea igual al string dado
//si Adscripcion no se encuentra en el Adscripcion implícito no se hará nada 
VectorAdscripcion & VectorAdscripcion :: operator-= (const string & obj)
{
    (*this) -= ((*this) && obj);

    return *this;
}

//Versión 4: [VectorAdscripcion] -= [int]
//Elimina del Adscripcion implícito el dato Adscripcion cuyo indice sea int
//si Adscripcion no se encuentra en el Adscripcion implícito no se hará nada 
VectorAdscripcion & VectorAdscripcion :: operator-= (const int & indice)
{
    if (indice_valido_usados(indice))
    {
        EliminaAdscripcion(indice);
    }

    return *this;
}


/***************************************************************************/
// INSERTAAdscripcion
// Inserta Adscripcion en el vector
// Parámetros: Adscripcion a insertar y posición en la que insertarlo
// PRE: 1 <= indice <= Totalutilizados()
// PRE: El Adscripcion no existe en el vector
void VectorAdscripcion :: InsertaAdscripcion(Adscripcion &obj, int indice)
{
    // Realmente el método set ya hace esta comprobación, pero hasta llegar a
    // el se altera por completo el vector, asi que hago la comprobación por dos
    if ((*this) && obj)
    {
        cerr << "Error: Se ha intentado insertar un Adscripcion que ya existe"\
             << endl;
        exit(1);
    }
    
    total_utilizados++;

    // Le hago hueco al elemento para introducirlo
    for (int i = Totalutilizados(); i >= indice; i--)
    {
        (*this)[i] = (*this)[i-1];
    }

    setAdscripcion(indice, obj);

    Redimensionar();

}


/***************************************************************************/
// Elimina todos los Adscripcions del vector
void VectorAdscripcion :: EliminaTodos()
{
    LiberarMemoria();
}

/***************************************************************************/
// EXTRAEAdscripcion
// Extrae Adscripcion del vector
// Elimina el Adscripcion indice del vector y lo devuelve
// PRE: 1 <= indice <= Totalutilizados()
Adscripcion VectorAdscripcion :: ExtraeAdscripcion(int indice)
{
    Adscripcion obj((*this)[indice]);

    (*this) -= (*this)[indice];

    return obj;
}

/*************************************************************************/
//----------------------------MÉTODOS PRIVADOS----------------------------//
/*************************************************************************/
// COPIARDATOS
// Copiar datos desde otro Adscripcion de la clase
// Parámetros: otro (referencia), Adscripcion que sirve de modelo. 
//
// PRE: Se ha reservado memoria para los datos
void VectorAdscripcion :: CopiarDatos(const VectorAdscripcion &otro)
{
    if (this != &otro)
    {
        EliminaTodos();
        ReservaMemoria(otro.Capacidad());

        for (int i = 1; i <= otro.Totalutilizados(); i++)
        {
            setAdscripcion(i, otro[i]);
            //(*this)[i] = otro[i]; <-- Más elegante, pero no hace comprobación
        }

        total_utilizados = otro.Totalutilizados();
    }

    // Redimensiono para no estár "ajustado" entre capacidad y total_utilizados
    //Redimensionar();
}

/***************************************************************************/
// BUSCARAdscripcion
// Método BuscarAdscripcion: Recibe un Adscripcion y lo busca en el vector
// Si está, devuelve el índice donde está almacenado, sino, devuelve 0
// Versión 1: Busca el Adscripcion dado un Adscripcion Adscripcion
int VectorAdscripcion :: BuscarAdscripcion(const Adscripcion &obj) const
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

// Versión 2: Busca el Adscripcion según el campo clave ********
int VectorAdscripcion :: BuscarAdscripcion(const string &cadena) const
{
    int indice = 0;
    for (int i = 1; i <= Totalutilizados(); i++)
    {
        if ((*this)[i].getDniProfesor() == cadena)
        {
            indice = i;
        }
    }

    return indice;
}

/***************************************************************************/
// ANIADEAdscripcion
// Aniade Adscripcion al final del vector 
// Dicho Adscripcion no puede estar repetido
// Parámetros: obj (referencia), Adscripcion que se va a añadir.
void VectorAdscripcion :: AniadeAdscripcion(const Adscripcion &obj)
{
    total_utilizados++;
    // SetAdscripcion comprueba si está repetido
    setAdscripcion(Totalutilizados(), obj);

    Redimensionar();
}

/***************************************************************************/
// ELIMINAAdscripcion
// Elimina Adscripcion del vector
// Parámetros: indice, int que indica el índice del Adscripcion
// PRE: 1 <= indice <= Totalutilizados()
void VectorAdscripcion :: EliminaAdscripcion(int indice)
{
    if(indice_valido_usados(indice))
    {
        while (indice < Totalutilizados())
        {
            (*this)[indice] = (*this)[indice+1];
            indice++;
        }

        total_utilizados--;
        Redimensionar();
    }
}

/***********************************************************************/
// RESERVAMEMORIA
// Pide memoria para guardar una copia de los datos de "otro"
// Parámetros: num_casillas: Número de casillas que se desean reservar. 
// PRE: num_casillas > 0
void VectorAdscripcion :: ReservaMemoria(const int num_casillas)
{
    if (num_casillas < 0)
    {
        cerr << "Error: El número de casillas debe ser mayor que 0" << endl;
        exit(1);
    }
    
	vector_privado = new Adscripcion[num_casillas]; 
	capacidad = num_casillas; 
}

/***********************************************************************/
// LIBERARMEMORIA
// Libera la memoria dinámica reservada para el vector
void VectorAdscripcion :: LiberarMemoria()
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
void VectorAdscripcion :: Reajustar()
{
    if (Totalutilizados() < Capacidad())
    {
        capacidad = Totalutilizados();
        // Copio el vector en uno temporal
        Adscripcion *tmp = new Adscripcion[Totalutilizados()];

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
void VectorAdscripcion :: Redimensionar (void)
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
        Adscripcion * tmp = new Adscripcion[capacidad];

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
Adscripcion & VectorAdscripcion :: Valor(int indice) const
{
    return vector_privado[indice];
}

/***********************************************************************/
// comprobacion_indice: Comprueba si el índice es válido
// En caso que lo sea, devuelve un mensaje de error y termina el programa
// PRE: 1 <= indice <= total_utilizados
void VectorAdscripcion :: comprobacion_indice_totalutilizados(const int indice) const
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
void VectorAdscripcion :: comprobacion_indice_capacidad(const int indice) const
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
bool VectorAdscripcion ::  indice_valido_usados(const int indice) const
{
    return (indice >= 1 && indice <= Totalutilizados());
}

/***********************************************************************/
// Indice_valido_capacidad: Comprueba si el índice es válido
// Devuelve true si el índice está entre 1 y capacidad
// Devuelve false en caso contrario
bool VectorAdscripcion ::  indice_valido_capacidad(const int indice) const
{
    return (indice >= 1 && indice <= Capacidad());
}
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

