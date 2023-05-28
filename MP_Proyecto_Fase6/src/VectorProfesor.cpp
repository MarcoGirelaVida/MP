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
// Declaraciones en: VectorProfesor.h
//
// Fichero: VectorProfesor.cpp
//
/***************************************************************************/
/***************************************************************************/

#include "VectorProfesor.h"

using namespace std;

/*************************************************************************/
//-------------------------CONSTRUCTORES---------------------------------//
/*************************************************************************/
/***********************************************************************/
// Constructor
// Si se llama sin argumentos crea una secuencia con capacidad = TAMANIO.
// Si se llama con un argumento, su valor será la capacidad inicial. 
// POST: La secuencia creada estará vacía (EstaVacia()== true)
VectorProfesor :: VectorProfesor(int la_capacidad)
        : capacidad(0), total_utilizados(0), vector_privado(nullptr)
{
    ReservaMemoria(la_capacidad);
}

/************************************************************************/
// Constructor de copia
// Crea un Profesor copia del Profesor proporcionado como argumento ("otro")
// Parámetros: otro (referencia), Profesor que sirve de modelo. 
VectorProfesor :: VectorProfesor(const VectorProfesor &otro)
        : capacidad(0), total_utilizados(0), vector_privado(nullptr)
{
    (*this) = otro;
}

/************************************************************************/
// Constructor
// Recibe como parámetro un Profesor que servirá para inicializar
// el vector con un único elemento.
VectorProfesor :: VectorProfesor(const Profesor &obj)
        : capacidad(0), total_utilizados(0), vector_privado(nullptr)
{   
    ReservaMemoria(TAMANIO);
    AniadeProfesor(obj);
}
  
/************************************************************************/
//Constructor.Construye un Profesor VectorProfesor a partir de la información guardada en un
//fichero de texto llamado nombre.
//Son válidas las mismas consideraciones que en el método de lectura: si el fichero
//indicado no fuera del tipo esperado, el vector quedará vacío
VectorProfesor :: VectorProfesor(const string & nombre)
        : capacidad(0), total_utilizados(0), vector_privado(nullptr)
{
    RecuperarVectorProfesor(nombre);
}
 
/************************************************************************/
// Destructor
VectorProfesor :: ~VectorProfesor()
{
    LiberarMemoria();
}

/*************************************************************************/
//----------------------------MÉTODOS------------------------------------//
/*************************************************************************/
// Métodos de acceso a los campos de la clase
// Totalutilizados: Devuelve el número de elementos utilizados
int VectorProfesor :: Totalutilizados() const
{
    return total_utilizados;
}

// Capacidad: Devuelve la capacidad actual del vector
int VectorProfesor :: Capacidad() const
{
    return capacidad;
}

// EstaVacia: Devueve true si totalutilizados es 0 y false en caso contrario
int VectorProfesor :: EstaVacia() const
{
    return (Totalutilizados() == 0);
}

/***************************************************************************/
// Métodos set
// Sustituye el elemento "indice" del vector por el Profesor proporcionado
// Difiere de la sobrecarga = de la clase Profesor en que este método
// comprueba que el Profesor proporcionado no se encuentre en la cadena
// Es el método que recomiendo usar a la hora de alterar los elementos del vector
// PRE: 1 <= indice <= totalutilizados
void VectorProfesor :: setProfesor(int indice, const Profesor &obj)
{
    if ((*this) && obj)
    {
        cerr << "Error: El Profesor ya existe" << endl;
        exit(1);
    }

    (*this)[indice] = obj;
}

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
istream & operator>> (istream &flujo, VectorProfesor &v_obj)
{
    string linea;
    Profesor obj;
    getline(flujo, linea);

    if (linea != "PROFESORES")
    {
        cerr << "Error: No se ha encontrado lo palabra clave" << endl;
        exit(1);
    }

    // Mientras no se encuentre el fin de los datos o un comentario
    // se almacenan los datos
    while(flujo >> obj)
    {
        v_obj += obj;
    }

    return flujo;
}

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
ostream & operator<< (ostream &flujo, const VectorProfesor &v_obj)
{
    for (int i = 1; i <= v_obj.Totalutilizados(); i++)
    {
        flujo << to_string(i) << ".- " << v_obj[i] << endl;
    }

    return flujo;
}

/***************************************************************************/
// Método ToString
// Devuelve un string con la serialización de los Profesors del vector implícito
string VectorProfesor :: ToString() const
{
    string cad;

    for (int i = 1; i <= Totalutilizados(); i++)
    {
        int numero = i;
        string cadena_inicial = to_string(numero) + ".- ";
        cad += (*this)[i].ToString(true, cadena_inicial) + "\n";
    }

    return cad;
}

/***************************************************************************/
//Método de escritura. Guarda un dato Profesor en un fichero de texto llamado nombre.
//Notas:
//• Si el vector está vacío no se crea el fichero.
//• El vector no se modifica.
void VectorProfesor :: GuardarVectorProfesor (const string & nombre) const
{
    if (!EstaVacia())
    {
        ofstream fo(nombre);

        if (!fo)
        {
            cerr << "Error: No se pudo crear o abrir el archivo: " << nombre
                 << endl;
            exit(1);
        }
        
        fo << "PROFESORES" << endl;
        for (int i = 1; i <= Totalutilizados(); i++)
        {
            fo << (*this)[i].ToString(true, "", '*') << endl;
        }
        
    }
}

/***************************************************************************/
//Método de lectura. Lee un dato Profesor de un fichero de texto llamado nombre.
//Notas:
//• El vector siempre se modifica.
//• Si el fichero indicado no fuera un fichero del tipo esperado, el vector quedará
//vacío.
void VectorProfesor :: RecuperarVectorProfesor (const string & nombre)
{
    ifstream fi(nombre);

    if (!fi)
    {
        cerr << "Error: No se pudo abrir el archivo: " << nombre << endl;
        exit(1);
    }

    (*this).EliminaTodos();
    
    fi >> (*this);
}
 
/***********************************************************************/
// Sobrecarga del operador de asignación para copia profunda.
// Realiza una copia profunda de los datos de otro en el Profesor implícito.
// Parámetros: otro (referencia), Profesor que sirve de modelo. 
VectorProfesor & VectorProfesor :: operator=(const VectorProfesor &otro)
{ 
    CopiarDatos(otro);
    return *this;
}

/***********************************************************************/
// Sobrecarga del [].
// Parámetros: indice del elemento a consultar (total_utilizados => indice => 1)
Profesor & VectorProfesor :: operator[](int indice) const
{
    comprobacion_indice_totalutilizados(indice);
    return Valor(indice-1);
}

/***********************************************************************/
// Sobrecarga del ().
// Parámetros: indice del elemento a modificar (total_utilizados => indice > 0)
Profesor & VectorProfesor :: operator[](int indice)
{
    comprobacion_indice_capacidad(indice);
    return Valor(indice-1);
}

/***********************************************************************/
// Sobrecarga del ().
// Parámetros: indice del elemento a consultar (total_utilizados => indice > 0)
Profesor & VectorProfesor :: operator()(int indice) const
{
    return (*this)[indice];
}

/***********************************************************************/
// Sobrecarga del ().
// Parámetros: indice del elemento a modificar (total_utilizados => indice > 0)
Profesor & VectorProfesor :: operator()(int indice)
{
    return (*this)[indice];
}

/***************************************************************************/
// Sobrecarga de operador +
// Versión 1: VectorProfesor + VectorProfesor
// Concatena los datos VectorProfesor en uno nuevo. Los valo-
// res del segundo se añaden (en el mismo orden) en una copia del primero.
// Parámetros: otro (referencia), VectorProfesor que se añade.
// no se añadirá Profesor a VectorProfesor si ya está dentro
VectorProfesor operator+ (const VectorProfesor &uno, \
                              const VectorProfesor &otro)
{
    VectorProfesor copia(uno);

    for (int i = 1; i <= otro.Totalutilizados(); i++)
    {
        copia += otro[i];
    }

    return copia;
}

//Versión 2: [VectorProfesor] + [Profesor]
//Añade un dato Profesor al final de una copia del VectorProfesor.
// no se añadirá Profesor a VectorProfesor si ya está dentro
VectorProfesor operator+ (const VectorProfesor &v_obj, \
                              const Profesor &obj)
{
    VectorProfesor copia(v_obj);
    copia += obj;
    return copia;
}

// Versión 3: [Profesor] + [VectorProfesor]
// Inserta el dato Profesor al principio de una copia del
// VectorProfesor.
// no se añadirá Profesor a VectorProfesor si ya está dentro
VectorProfesor operator+ (const Profesor &obj, \
                              const VectorProfesor &v_obj)
{
    return v_obj + obj;
}

/***************************************************************************/
//Versioperatorón 1: [VectorProfesor] - [VectorProfesor]
//Elimina de una copia del Profesor implícito los datos Profesor cuyo
//campo clave esté presente en los datos Profesor
//del Profesor explícito.
//si Profesor no se encuentra en el Profesor implícito no se hará nada 
VectorProfesor VectorProfesor :: operator-
                                    (const VectorProfesor &v_obj) const
{
    VectorProfesor copia(*this);
    copia -= v_obj;

    return copia;
}

//Versión 2: [VectorProfesor] - [Profesor]
//Elimina de una copia del VectorProfesor el dato
//Profesor cuyo campo clave sea igual al del
//valor incluido en el Profesor Profesor.
//si Profesor no se encuentra en el Profesor implícito no se hará nada 
VectorProfesor VectorProfesor :: operator-
                                            (const Profesor &obj) const
{
    VectorProfesor copia(*this);

    copia -= obj;

    return copia;
}

//Versión 3: [VectorProfesor] - [string]
//Elimina de una copia del VectorProfesor el dato
//Profesor cuyo campo clave sea igual al string dado.
//si Profesor no se encuentra en el Profesor implícito no se hará nada 
VectorProfesor VectorProfesor :: operator- (const string &cadena) const
{
    VectorProfesor copia(*this);

    copia -= cadena;

    return copia;
}

/***************************************************************************/
// Operator *
//Versión 1: [VectorProfesor] * [VectorProfesor]
//Devuelve un nuevo VectorProfesor que contiene to-
//dos los datos VectorProfesor comunes entre los dos VectorProfesor
VectorProfesor VectorProfesor :: operator*
                                    (const VectorProfesor &v_obj) const
{
    VectorProfesor comunes;

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
//Versión 1: [VectorProfesor] && [VectorProfesor]
//Devuelve true si el primer VectorProfesor contiene todos los
//datos que están en el segundo VectorProfesor.
bool operator&& (const VectorProfesor &v_obj1,\
                        const VectorProfesor &v_obj2)
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

// Versión 2: [VectorProfesor] && [Profesor]
// Devuelve un int con el indice del VectorProfesor que
// contiene al dato Profesor.
// Si no está contenido, devuelve 0.
int operator&& (const VectorProfesor &v_obj,\
                        const Profesor &obj)
{
    return v_obj.BuscarProfesor(obj);
}
// Versión 3: [Profesor] && [VectorProfesor]
// Devuelve un int con el indice del VectorProfesor que
// contiene al dato Profesor.
// Si no está contenido, devuelve 0.
int operator&& (const Profesor &obj,\
                        const VectorProfesor &v_obj)
{
    return v_obj && obj;
}

// Versión 4: [VectorProfesor] && [string]
// Devuelve un int con el indice del VectorProfesor que
// contiene al dato Profesor cuyo campo clave coincide con el string.
// Si no está contenido, devuelve 0.
int operator&& (const VectorProfesor &v_obj,\
                        const string &cadena)
{
    return v_obj.BuscarProfesor(cadena);
}

// Versión 5: [string] && [VectorProfesor]
// Devuelve un int con el indice del VectorProfesor que
// contiene al dato Profesor cuyo campo clave coincide con el string.
// Si no está contenido, devuelve 0.
int operator&& (const string &cadena,\
                        const VectorProfesor &v_obj)
{
    return v_obj && cadena;
}
/***************************************************************************/
// Operator +=
// Versión 1: [VectorProfesor] += [VectorProfesor]
// Todos los valores del Profesor explícito se añaden (en el mismo orden en
// el que están en el Profesor explícito) al Profesor implícito 
// no se añadirá Profesor a VectorProfesor si ya está dentro
VectorProfesor & VectorProfesor :: operator+= (const VectorProfesor & v_obj)
{
   *this = *this + v_obj;
    
    return *this;
}

// Versión 2: [VectorProfesor] += [Profesor]
//Añade un dato Profesor al final del Profesor implícito.
// no se añadirá Profesor a VectorProfesor si ya está dentro
VectorProfesor & VectorProfesor :: operator+= (const Profesor & obj)
{
    (*this).AniadeProfesor(obj);
    return (*this);
}

/***************************************************************************/
// Operador -=:
// Versión 1: [VectorProfesor] -= [VectorProfesor]
//Elimina del Profesor implícito los datos Profesor que
// esté presente en los datos Profesor del Profesor
//explícito.
//si Profesor no se encuentra en el Profesor implícito no se hará nada 
VectorProfesor & VectorProfesor :: operator-= (const VectorProfesor & v_obj)
{

    for (int i = 1; i <= v_obj.Totalutilizados(); i++)
    {
        (*this) -= v_obj[i];
    }

    return *this;
}

//Versión 2: [VectorProfesor] -= [Profesor]
//Elimina del Profesor implícito el dato Profesor
//si Profesor no se encuentra en el Profesor implícito no se hará nada 
VectorProfesor & VectorProfesor :: operator-= (const Profesor & obj)
{
    (*this) -= ((*this) && obj);

    return *this;
}

//Versión 3: [VectorProfesor] -= [string]
//Elimina del Profesor implícito el dato Profesor cuyo campo clave
//sea igual al string dado
//si Profesor no se encuentra en el Profesor implícito no se hará nada 
VectorProfesor & VectorProfesor :: operator-= (const string & obj)
{
    (*this) -= ((*this) && obj);

    return *this;
}

//Versión 4: [VectorProfesor] -= [int]
//Elimina del Profesor implícito el dato Profesor cuyo indice sea int
//si Profesor no se encuentra en el Profesor implícito no se hará nada 
VectorProfesor & VectorProfesor :: operator-= (const int & indice)
{
    if (indice_valido_usados(indice))
    {
        EliminaProfesor(indice);
    }

    return *this;
}


/***************************************************************************/
// INSERTAProfesor
// Inserta Profesor en el vector
// Parámetros: Profesor a insertar y posición en la que insertarlo
// PRE: 1 <= indice <= Totalutilizados()
// PRE: El Profesor no existe en el vector
void VectorProfesor :: InsertaProfesor(Profesor &obj, int indice)
{
    // Realmente el método set ya hace esta comprobación, pero hasta llegar a
    // el se altera por completo el vector, asi que hago la comprobación por dos
    if ((*this) && obj)
    {
        cerr << "Error: Se ha intentado insertar un Profesor que ya existe"\
             << endl;
        exit(1);
    }
    
    total_utilizados++;

    // Le hago hueco al elemento para introducirlo
    for (int i = Totalutilizados(); i >= indice; i--)
    {
        (*this)[i] = (*this)[i-1];
    }

    // Inserto el elemento
    (*this)[indice] = obj;

    Redimensionar();

}


/***************************************************************************/
// Elimina todos los Profesors del vector
void VectorProfesor :: EliminaTodos()
{
    LiberarMemoria();

    // Redimensionar hace que se ajuste capacidad al tamaño mínimo
    Redimensionar();
}

/***************************************************************************/
// EXTRAEProfesor
// Extrae Profesor del vector
// Elimina el Profesor indice del vector y lo devuelve
// PRE: 1 <= indice <= Totalutilizados()
Profesor VectorProfesor :: ExtraeProfesor(int indice)
{
    Profesor obj((*this)[indice]);

    (*this) -= (*this)[indice];

    return obj;
}

/*************************************************************************/
//----------------------------MÉTODOS PRIVADOS----------------------------//
/*************************************************************************/
// COPIARDATOS
// Copiar datos desde otro Profesor de la clase
// Parámetros: otro (referencia), Profesor que sirve de modelo. 
//
// PRE: Se ha reservado memoria para los datos
void VectorProfesor :: CopiarDatos(const VectorProfesor &otro)
{
    if (this != &otro)
    {
        LiberarMemoria();
        ReservaMemoria(otro.Capacidad());

        for (int i = 1; i <= otro.Totalutilizados(); i++)
        {
            (*this)[i] = otro[i];
        }

        total_utilizados = otro.Totalutilizados();
    }

    // Redimensiono para no estár "ajustado" entre capacidad y total_utilizados
    //Redimensionar();
}

/***************************************************************************/
// BUSCARProfesor
// Método BuscarProfesor: Recibe un Profesor y lo busca en el vector
// Si está, devuelve el índice donde está almacenado, sino, devuelve 0
// Versión 1: Busca el Profesor dado un Profesor Profesor
int VectorProfesor :: BuscarProfesor(const Profesor &obj) const
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

// Versión 2: Busca el Profesor según el campo clave ********
int VectorProfesor :: BuscarProfesor(const string &cadena) const
{
    int indice = 0;
    for (int i = 1; i <= Totalutilizados(); i++)
    {
        if ((*this)[i].getDni() == cadena)
        {
            indice = i;
        }
    }

    return indice;
}

/***************************************************************************/
// ANIADEProfesor
// Aniade Profesor al final del vector 
// Dicho Profesor no puede estar repetido
// Parámetros: obj (referencia), Profesor que se va a añadir.
void VectorProfesor :: AniadeProfesor(const Profesor &obj)
{
    if ((*this) && obj)
    {
        cerr << "Error: El Profesor ya existe" << endl;
        exit(1);
    }

    total_utilizados++;

    (*this)[Totalutilizados()] = obj;

    Redimensionar();
}

/***************************************************************************/
// ELIMINAProfesor
// Elimina Profesor del vector
// Parámetros: indice, int que indica el índice del Profesor
// PRE: 1 <= indice <= Totalutilizados()
void VectorProfesor :: EliminaProfesor(int indice)
{
    if(indice_valido_usados(indice))
    {
        // "Desplazar" los valores desde la casilla siguiente a "indice" 
        // hasta el final una posición a la izquierda
		memmove (&(*this)[indice-1], &(*this)[indice], 
                 (Totalutilizados()-indice)*sizeof(Profesor));

        total_utilizados--;
        Redimensionar();
    }
}

/***********************************************************************/
// RESERVAMEMORIA
// Pide memoria para guardar una copia de los datos de "otro"
// Parámetros: num_casillas: Número de casillas que se desean reservar. 
// PRE: num_casillas > 0
void VectorProfesor :: ReservaMemoria(const int num_casillas)
{
    if (num_casillas < 0)
    {
        cerr << "Error: El número de casillas debe ser mayor que 0" << endl;
        exit(1);
    }
    
	vector_privado = new Profesor[num_casillas]; 
	capacidad = num_casillas; 
}

/***********************************************************************/
// LIBERARMEMORIA
// Libera la memoria dinámica reservada para el vector
void VectorProfesor :: LiberarMemoria()
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
void VectorProfesor :: Reajustar()
{
    if (Totalutilizados() < Capacidad())
    {
        capacidad = Totalutilizados();
        // Copio el vector en uno temporal
        Profesor *tmp = new Profesor[Totalutilizados()];

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
void VectorProfesor :: Redimensionar (void)
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
        Profesor * tmp = new Profesor[capacidad];

        for (int i = 1; i <= Totalutilizados() && Totalutilizados(); i++)
        {
            tmp[i-1] = (*this)[i];
        }

        delete [] vector_privado;
        vector_privado = tmp;
    }
}

/***********************************************************************/
// VALOR: Devuelve el valor de la Profesor en la posición "indice"
// Puede funcionar como lvalue y como rvalue
// Es el único método que usa y debe usar el índice "real" (desde 0)
// PRE: 0 <= indice < total_utilizados
Profesor & VectorProfesor :: Valor(int indice) const
{
    return vector_privado[indice];
}

/***********************************************************************/
// comprobacion_indice: Comprueba si el índice es válido
// En caso que lo sea, devuelve un mensaje de error y termina el programa
// PRE: 1 <= indice <= total_utilizados
void VectorProfesor :: comprobacion_indice_totalutilizados(const int indice) const
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
void VectorProfesor :: comprobacion_indice_capacidad(const int indice) const
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
bool VectorProfesor ::  indice_valido_usados(const int indice) const
{
    return (indice >= 1 && indice <= Totalutilizados());
}

/***********************************************************************/
// Indice_valido_capacidad: Comprueba si el índice es válido
// Devuelve true si el índice está entre 1 y capacidad
// Devuelve false en caso contrario
bool VectorProfesor ::  indice_valido_capacidad(const int indice) const
{
    return (indice >= 1 && indice <= Capacidad());
}
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

