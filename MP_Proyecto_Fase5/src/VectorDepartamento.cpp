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
// Declaraciones en: VectorDepartamento.h
//
// Fichero: VectorDepartamento.cpp
//
/***************************************************************************/
/***************************************************************************/

#include "VectorDepartamento.h"

using namespace std;

/*************************************************************************/
//-------------------------CONSTRUCTORES---------------------------------//
/*************************************************************************/
/***********************************************************************/
// Constructor
// Si se llama sin argumentos crea una secuencia con capacidad = TAMANIO.
// Si se llama con un argumento, su valor será la capacidad inicial. 
// POST: La secuencia creada estará vacía (EstaVacia()== true)
VectorDepartamento :: VectorDepartamento(int la_capacidad)
        : capacidad(0), total_utilizados(0), vector_privado(nullptr)
{
    ReservaMemoria(la_capacidad);
}

/************************************************************************/
// Constructor de copia
// Parámetros: otro (referencia), Departamento que sirve de modelo. 
VectorDepartamento :: VectorDepartamento(const VectorDepartamento &otro)
        : capacidad(0), total_utilizados(0), vector_privado(nullptr)
{
    (*this) = otro;
}

/************************************************************************/
// Constructor
// Recibe como parámetro un Departamento que servirá para inicializar
// el vector con un único elemento.
VectorDepartamento :: VectorDepartamento(const Departamento &obj)
        : capacidad(0), total_utilizados(0), vector_privado(nullptr)
{   
    ReservaMemoria(TAMANIO);
    AniadeDepartamento(obj);
}

/************************************************************************/
// Destructor
VectorDepartamento :: ~VectorDepartamento()
{
    EliminaTodos();
}

/*************************************************************************/
//----------------------------MÉTODOS------------------------------------//
/*************************************************************************/
// Métodos de acceso a los campos de la clase
int VectorDepartamento :: Totalutilizados() const
{
    return total_utilizados;
}

int VectorDepartamento :: Capacidad() const
{
    return capacidad;
}

int VectorDepartamento :: EstaVacia() const
{
    return (Totalutilizados() == 0);
}

/***************************************************************************/
// Métodos set
void VectorDepartamento :: setDepartamento(int indice, Departamento &obj)
{
    if ((*this) && obj)
    {
        cerr << "Error: El Departamento ya existe" << endl;
        exit(1);
    }

    (*this)[indice] = obj;
}

/***************************************************************************/
// Método ToString
string VectorDepartamento :: Serializar() const
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
// Parámetros: otro (referencia), Departamento que sirve de modelo. 
VectorDepartamento & VectorDepartamento :: operator=(const VectorDepartamento &otro)
{ 
    CopiarDatos(otro);
    return *this;
}

/***********************************************************************/
// Sobrecarga del [].
// Parámetros: indice del elemento a consultar (total_utilizados => indice > 0 ). 
Departamento & VectorDepartamento :: operator[](int indice) const
{
    comprobacion_indice_totalutilizados(indice);
    return Valor(indice-1);
}

/***********************************************************************/
// Sobrecarga del ().
// Parámetros: indice del elemento a modificar (total_utilizados => indice > 0 ). 
Departamento & VectorDepartamento :: operator[](int indice)
{
    comprobacion_indice_capacidad(indice);
    return Valor(indice-1);
}

/***********************************************************************/
// Sobrecarga del ().
// Parámetros: indice del elemento a consultar (total_utilizados => indice > 0 ). 
Departamento & VectorDepartamento :: operator()(int indice) const
{
    return (*this)[indice];
}

/***********************************************************************/
// Sobrecarga del ().
// Parámetros: indice del elemento a modificar (total_utilizados => indice > 0 ). 
Departamento & VectorDepartamento :: operator()(int indice)
{
    return (*this)[indice];
}

/***************************************************************************/
// Sobrecarga de operador +
// Versión 1: VectorDepartamento + VectorDepartamento
// Concatena los datos VectorDepartamento en uno nuevo. Los valo-
// res del segundo se añaden (en el mismo orden) en una copia del primero.
// Parámetros: otro (referencia), VectorDepartamento que se añade.
// no se añadirá Departamento a VectorDepartamento si ya está dentro
VectorDepartamento operator+ (const VectorDepartamento &uno, \
                              const VectorDepartamento &otro)
{
    VectorDepartamento copia(uno);

    for (int i = 1; i <= otro.Totalutilizados(); i++)
    {
        copia += otro[i];
    }

    return copia;
}

//Versión 2: [VectorDepartamento] + [Departamento]
//Añade un dato Departamento al final de una copia del VectorDepartamento.
// no se añadirá Departamento a VectorDepartamento si ya está dentro
VectorDepartamento operator+ (const VectorDepartamento &v_obj, \
                              const Departamento &obj)
{
    VectorDepartamento copia(v_obj);
    copia += obj;
    return copia;
}

// Versión 3: [Departamento] + [VectorDepartamento]
// Inserta el dato Departamento al principio de una copia del
// VectorDepartamento.
// no se añadirá Departamento a VectorDepartamento si ya está dentro
VectorDepartamento operator+ (const Departamento &obj, \
                              const VectorDepartamento &v_obj)
{
    return v_obj + obj;
}

/***************************************************************************/
//Versioperatorón 1: [VectorDepartamento] - [VectorDepartamento]
//Elimina de una copia del objeto implícito los datos Departamento cuyo
//campo clave esté presente en los datos Departamento
//del objeto explícito.
//si Departamento no se encuentra en el objeto implícito no se hará nada 
VectorDepartamento VectorDepartamento :: operator-
                                    (const VectorDepartamento &v_obj) const
{
    VectorDepartamento copia(*this);
    copia -= v_obj;

    return copia;
}

//Versión 2: [VectorDepartamento] - [Departamento]
//Elimina de una copia del VectorDepartamento el dato
//Departamento cuyo campo clave sea igual al del
//valor incluido en el objeto Departamento.
//si Departamento no se encuentra en el objeto implícito no se hará nada 
VectorDepartamento VectorDepartamento :: operator-
                                            (const Departamento &obj) const
{
    VectorDepartamento copia(*this);

    copia -= obj;

    return copia;
}

//Versión 3: [VectorDepartamento] - [string]
//Elimina de una copia del VectorDepartamento el dato
//Departamento cuyo campo clave sea igual al string dado.
//si Departamento no se encuentra en el objeto implícito no se hará nada 
VectorDepartamento VectorDepartamento :: operator- (const string &cadena) const
{
    VectorDepartamento copia(*this);

    copia -= cadena;

    return copia;
}

/***************************************************************************/
// Operator *
//Versión 1: [VectorDepartamento] * [VectorDepartamento]
//Devuelve un nuevo VectorDepartamento que contiene to-
//dos los datos VectorDepartamento comunes entre los dos VectorDepartamento
VectorDepartamento VectorDepartamento :: operator*
                                    (const VectorDepartamento &v_obj) const
{
    VectorDepartamento comunes;

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
//Versión 1: [VectorDepartamento] && [VectorDepartamento]
//Devuelve true si el primer VectorDepartamento contiene todos los
//datos que están en el segundo VectorDepartamento.
bool operator&& (const VectorDepartamento &v_obj1,\
                        const VectorDepartamento &v_obj2)
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

// Versión 2: [VectorDepartamento] && [Departamento]
//Devuelve true si VectorDepartamento contiene al dato
int operator&& (const VectorDepartamento &v_obj,\
                        const Departamento &obj)
{
    return v_obj.BuscarDepartamento(obj);
}

// Versión 3: [Departamento] && [VectorDepartament	// No entiendo qué se supone que tiene que hacer este constructoro]
//Devuelve true si VectorDepartamento contiene al dato
int operator&& (const Departamento &obj,\
                        const VectorDepartamento &v_obj)
{
    return v_obj && obj;
}

// Versión 4: [VectorDepartamento] && [string]
// Devuelve true si VectorDepartamento contiene al dato
// Departamento cuyo campo clave coincide con el string
int operator&& (const VectorDepartamento &v_obj,\
                        const string &cadena)
{
    return v_obj.BuscarDepartamento(cadena);
}

// Versión 5: [string] && [VectorDepartamento]
// Devuelve true si VectorDepartamento contiene al dato
// Departamento cuyo campo clave coincide con el string
int operator&& (const string &cadena,\
                        const VectorDepartamento &v_obj)
{
    return v_obj && cadena;
}
/***************************************************************************/
// Operator +=
// Versión 1: [VectorDepartamento] += [VectorDepartamento]
// Todos los valores del objeto explícito se añaden (en el mismo orden en
// el que están en el objeto explícito) al objeto implícito 
// no se añadirá Departamento a VectorDepartamento si ya está dentro
VectorDepartamento & VectorDepartamento :: operator+= (const VectorDepartamento & v_obj)
{
   *this = *this + v_obj;
    
    return *this;
}

// Versión 2: [VectorDepartamento] += [Departamento]
//Añade un dato Departamento al final del objeto implícito.
// no se añadirá Departamento a VectorDepartamento si ya está dentro
VectorDepartamento & VectorDepartamento :: operator+= (const Departamento & obj)
{
    (*this).AniadeDepartamento(obj);
    return (*this);
}

/***************************************************************************/
// Operador -=:
// Versión 1: [VectorDepartamento] -= [VectorDepartamento]
//Elimina del objeto implícito los datos Departamento que
// esté presente en los datos Departamento del objeto
//explícito.
//si Departamento no se encuentra en el objeto implícito no se hará nada 
VectorDepartamento & VectorDepartamento :: operator-= (const VectorDepartamento & v_obj)
{

    for (int i = 1; i <= v_obj.Totalutilizados(); i++)
    {
        (*this) -= v_obj[i];
    }

    return *this;
}

//Versión 2: [VectorDepartamento] -= [Departamento]
//Elimina del objeto implícito el dato Departamento
//si Departamento no se encuentra en el objeto implícito no se hará nada 
VectorDepartamento & VectorDepartamento :: operator-= (const Departamento & obj)
{
    (*this) -= ((*this) && obj);

    return *this;
}

//Versión 3: [VectorDepartamento] -= [string]
//Elimina del objeto implícito el dato Departamento cuyo campo clave
//sea igual al string dado
//si Departamento no se encuentra en el objeto implícito no se hará nada 
VectorDepartamento & VectorDepartamento :: operator-= (const string & obj)
{
    (*this) -= ((*this) && obj);

    return *this;
}

//Versión 4: [VectorDepartamento] -= [int]
//Elimina del objeto implícito el dato Departamento cuyo indice sea int
//si Departamento no se encuentra en el objeto implícito no se hará nada 
VectorDepartamento & VectorDepartamento :: operator-= (const int & indice)
{
    if (indice_valido_usados(indice))
    {
        EliminaDepartamento(indice);
    }

    return *this;
}


/***************************************************************************/
// Inserta Departamento en el vector
// PRE: 1 <= indice <= Totalutilizados()
// PRE: El Departamento no existe en el vector
void VectorDepartamento :: InsertaDepartamento(Departamento &obj, int indice)
{
    if ((*this) && obj)
    {
        cerr << "Error: Se ha intentado insertar un Departamento que ya existe"\
             << endl;
        exit(1);
    }
    
    total_utilizados++;

    for (int i = Totalutilizados(); i >= indice; i--)
    {
        (*this)[i] = (*this)[i-1];
    }

    (*this)[indice] = obj;

    Redimensionar();

}


/***************************************************************************/
// Elimina todos los Departamentos del vector
void VectorDepartamento :: EliminaTodos()
{
    LiberarMemoria();
}

/***************************************************************************/
// Extrae Departamento del vector
// PRE: 1 <= indice <= Totalutilizados()
Departamento VectorDepartamento :: ExtraeDepartamento(int indice)
{
    Departamento obj((*this)[indice]);

    (*this) -= (*this)[indice];

    return obj;
}

/*************************************************************************/
//----------------------------MÉTODOS PRIVADOS----------------------------//
/*************************************************************************/
// COPIARDATOS
// Copiar datos desde otro Departamento de la clase
// Parámetros: otro (referencia), Departamento que sirve de modelo. 
void VectorDepartamento :: CopiarDatos(const VectorDepartamento &otro)
{
    if (this != &otro)
    {
        EliminaTodos();
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
// Método BuscarDepartamento: Recibe un Departamento y lo busca en el vector
// Si está, devuelve el índice donde está almacenado, sino, devuelve 0
// Versión 1: Busca el Departamento dado un objeto Departamento
int VectorDepartamento :: BuscarDepartamento(const Departamento &obj) const
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

// Versión 2: Busca el Departamento según el campo clave ********
int VectorDepartamento :: BuscarDepartamento(const string &cadena) const
{
    int indice = 0;
    for (int i = 1; i <= Totalutilizados(); i++)
    {
        if ((*this)[i].GetId_Dpto() == cadena)
        {
            indice = i;
        }
    }

    return indice;
}

/***************************************************************************/
// Aniade Departamento al final del vector 
void VectorDepartamento :: AniadeDepartamento(const Departamento &obj)
{
    if ((*this) && obj)
    {
        cerr << "Error: Se ha intentado añadir un Departamento que ya existe"\
             << endl;
        exit(1);
    }
    total_utilizados++;

    (*this)[Totalutilizados()] = obj;

    Redimensionar();
}

/***************************************************************************/
// Elimina Departamento del vector
// PRE: 1 <= indice <= Totalutilizados()
void VectorDepartamento :: EliminaDepartamento(int indice)
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
// Parámetros: otro (referencia), Departamento que sirve de modelo. 
// PRE: num_casillas > 0
void VectorDepartamento :: ReservaMemoria(const int num_casillas)
{
    if (num_casillas < 0)
    {
        cerr << "Error: El número de casillas debe ser mayor que 0" << endl;
        exit(1);
    }
    
	vector_privado = new Departamento[num_casillas]; 
	capacidad = num_casillas; 
}

/***********************************************************************/
// LIBERARMEMORIA
void VectorDepartamento :: LiberarMemoria()
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
// Iguala capacidad a total_utilizados (no recomendable, mejor usar redimensionar,
// (Más que nada para no tener total_utilizados siempre "pegado" a capacidad)
void VectorDepartamento :: Reajustar()
{
    if (Totalutilizados() < Capacidad())
    {
        capacidad = Totalutilizados();
        // Copio el vector en uno temporal
        Departamento *tmp = new Departamento[Totalutilizados()];

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
void VectorDepartamento :: Redimensionar (void)
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
        Departamento * tmp = new Departamento[capacidad];

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
// PRE: 0 <= indice < total_utilizados
Departamento & VectorDepartamento :: Valor(int indice) const
{
    return vector_privado[indice];
}

/***********************************************************************/
// comprobacion_indice: Comprueba si el índice es válido
// PRE: 0 <= indice < total_utilizados
void VectorDepartamento :: comprobacion_indice_totalutilizados(const int indice) const
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
// PRE: 0 <= indice < capacidad
void VectorDepartamento :: comprobacion_indice_capacidad(const int indice) const
{
    if (!indice_valido_capacidad(indice))
    {
        cerr << "Error en sobrecarga [] no-const: índice fuera de rango" << endl;
        cerr << "El índice debe estar entre 1 y " << Capacidad() << endl;
        cerr << "El índice introducido es: " << indice << endl;
        exit(1);
    }
}

bool VectorDepartamento ::  indice_valido_usados(const int indice) const
{
    return (indice >= 1 && indice <= Totalutilizados());
}

bool VectorDepartamento ::  indice_valido_capacidad(const int indice) const
{
    return (indice >= 1 && indice <= Capacidad());
}
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

