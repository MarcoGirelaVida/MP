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
// Crea un Departamento copia del Departamento proporcionado como argumento ("otro")
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
//Constructor.Construye un Departamento VectorDepartamento a partir de la información guardada en un
//fichero de texto llamado nombre.
//Son válidas las mismas consideraciones que en el método de lectura: si el fichero
//indicado no fuera del tipo esperado, el vector quedará vacío
VectorDepartamento :: VectorDepartamento(const string & nombre)
        : capacidad(0), total_utilizados(0), vector_privado(nullptr)
{
    RecuperarVectorDepartamento(nombre);
}
 
/************************************************************************/
// Destructor
VectorDepartamento :: ~VectorDepartamento()
{
    LiberarMemoria();
}

/*************************************************************************/
//----------------------------MÉTODOS------------------------------------//
/*************************************************************************/
// Métodos de acceso a los campos de la clase
// Totalutilizados: Devuelve el número de elementos utilizados
int VectorDepartamento :: Totalutilizados() const
{
    return total_utilizados;
}

// Capacidad: Devuelve la capacidad actual del vector
int VectorDepartamento :: Capacidad() const
{
    return capacidad;
}

// EstaVacia: Devueve true si totalutilizados es 0 y false en caso contrario
int VectorDepartamento :: EstaVacia() const
{
    return (Totalutilizados() == 0);
}

/***************************************************************************/
// Métodos set
// Sustituye el elemento "indice" del vector por el Departamento proporcionado
// Difiere de la sobrecarga = de la clase Departamento en que este método
// comprueba que el Departamento proporcionado no se encuentre en la cadena
// Es el método que recomiendo usar a la hora de alterar los elementos del vector
// PRE: 1 <= indice <= totalutilizados
void VectorDepartamento :: setDepartamento(int indice, const Departamento &obj)
{
    if ((*this) && obj)
    {
        cerr << "Error: El Departamento: " << obj.GetId_Dpto() << " ya existe"
             << endl;
    }
    else
    {
        (*this)[indice] = obj;
    }
    

}

/***************************************************************************/
// OPERATOR >>:
// Lee del flujo de entrada los datos de un VectorDepartamento
// Parámetros: flujo (referencia), flujo de entrada desde el que se leen los datos
//             v_obj (referencia), VectorDepartamento en el que se guardan los datos
// PRE: El formato de los datos debe ser el siguiente:
//      - Palabra clave: "DepartamentoES"
//      - Departamentoes (una por linea)
//      - Comentarios, deben empezar por el caracter '#'
//      - Fin de datos, se sobreentenderá por el fin del flujo de entrada
istream & operator>> (istream &flujo, VectorDepartamento &v_obj)
{
    string linea;
    Departamento obj;

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
// Escribe en el flujo de salida los datos de un VectorDepartamento
// Parámetros: flujo (referencia), flujo de salida en el que se escriben los datos
//             v_obj (referencia constante), VectorDepartamento del que se leen los datos
// PRE: El formato de los datos debe ser el siguiente:
//      - Palabra clave: "DepartamentoES"
//      - Departamentoes (una por linea)
//      - Comentarios, deben empezar por el caracter '#'
//      - Fin de datos, se sobreentenderá por el fin del flujo de entrada
ostream & operator<< (ostream &flujo, const VectorDepartamento &v_obj)
{
    for (int i = 1; i <= v_obj.Totalutilizados(); i++)
    {
        flujo << v_obj[i];;
    }

    return flujo;
}

/***************************************************************************/
// Método ToString
// Devuelve un string con la serialización de los Departamentos del vector implícito
string VectorDepartamento :: ToString() const
{
    string cad;

    for (int i = 1; i <= Totalutilizados(); i++)
    {
        int numero = i;
        string cadena_inicial = to_string(numero) + ".- ";
        cad += (*this)[i].ToString(cadena_inicial, ' ') + "\n";
    }

    return cad;
}

/***************************************************************************/
//Método de escritura. Guarda un dato Departamento en un fichero de texto llamado nombre.
//Notas:
//• Si el vector está vacío no se crea el fichero.
//• El vector no se modifica.
void VectorDepartamento :: GuardarVectorDepartamento (const string & nombre) const
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
        
        fo << "DEPARTAMENTOS" << endl;
        fo << (*this);
        
    }
}

/***************************************************************************/
//Método de lectura. Lee un dato Departamento de un fichero de texto llamado nombre.
//Notas:
//• El vector siempre se modifica.
//• Si el fichero indicado no fuera un fichero del tipo esperado, el vector quedará
//vacío.
void VectorDepartamento :: RecuperarVectorDepartamento (const string & nombre)
{
    ifstream fi(nombre);
    string linea;

    if (!fi)
    {
        cerr << "Error: No se pudo abrir el archivo: " << nombre << endl;
        exit(1);
    }

    EliminaTodos();

    getline(fi, linea);

    if (linea != "DEPARTAMENTOS")
    {
        cerr << "Error: No se ha encontrado lo palabra clave" << endl;
        exit(1);
    }

    char inicial;
    inicial = fi.peek();

    while (inicial == '#')
    {
        getline(fi, linea);
	inicial = fi.peek();
    }
    

    fi >> (*this);
}
 
/***********************************************************************/
// Sobrecarga del operador de asignación para copia profunda.
// Realiza una copia profunda de los datos de otro en el Departamento implícito.
// Parámetros: otro (referencia), Departamento que sirve de modelo. 
VectorDepartamento & VectorDepartamento :: operator=(const VectorDepartamento &otro)
{ 
    CopiarDatos(otro);
    return *this;
}

/***********************************************************************/
// Sobrecarga del [].
// Parámetros: indice del elemento a consultar (total_utilizados => indice => 1)
Departamento & VectorDepartamento :: operator[](int indice) const
{
    comprobacion_indice_totalutilizados(indice);
    return Valor(indice-1);
}

/***********************************************************************/
// Sobrecarga del ().
// Parámetros: indice del elemento a modificar (total_utilizados => indice > 0)
Departamento & VectorDepartamento :: operator[](int indice)
{
    comprobacion_indice_capacidad(indice);
    return Valor(indice-1);
}

/***********************************************************************/
// Sobrecarga del ().
// Parámetros: indice del elemento a consultar (total_utilizados => indice > 0)
Departamento & VectorDepartamento :: operator()(int indice) const
{
    return (*this)[indice];
}

/***********************************************************************/
// Sobrecarga del ().
// Parámetros: indice del elemento a modificar (total_utilizados => indice > 0)
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
//Elimina de una copia del Departamento implícito los datos Departamento cuyo
//campo clave esté presente en los datos Departamento
//del Departamento explícito.
//si Departamento no se encuentra en el Departamento implícito no se hará nada 
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
//valor incluido en el Departamento Departamento.
//si Departamento no se encuentra en el Departamento implícito no se hará nada 
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
//si Departamento no se encuentra en el Departamento implícito no se hará nada 
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
// Devuelve un int con el indice del VectorDepartamento que
// contiene al dato Departamento.
// Si no está contenido, devuelve 0.
int operator&& (const VectorDepartamento &v_obj,\
                        const Departamento &obj)
{
    return v_obj.BuscarDepartamento(obj);
}
// Versión 3: [Departamento] && [VectorDepartamento]
// Devuelve un int con el indice del VectorDepartamento que
// contiene al dato Departamento.
// Si no está contenido, devuelve 0.
int operator&& (const Departamento &obj,\
                        const VectorDepartamento &v_obj)
{
    return v_obj && obj;
}

// Versión 4: [VectorDepartamento] && [string]
// Devuelve un int con el indice del VectorDepartamento que
// contiene al dato Departamento cuyo campo clave coincide con el string.
// Si no está contenido, devuelve 0.
int operator&& (const VectorDepartamento &v_obj,\
                        const string &cadena)
{
    return v_obj.BuscarDepartamento(cadena);
}

// Versión 5: [string] && [VectorDepartamento]
// Devuelve un int con el indice del VectorDepartamento que
// contiene al dato Departamento cuyo campo clave coincide con el string.
// Si no está contenido, devuelve 0.
int operator&& (const string &cadena,\
                        const VectorDepartamento &v_obj)
{
    return v_obj && cadena;
}
/***************************************************************************/
// Operator +=
// Versión 1: [VectorDepartamento] += [VectorDepartamento]
// Todos los valores del Departamento explícito se añaden (en el mismo orden en
// el que están en el Departamento explícito) al Departamento implícito 
// no se añadirá Departamento a VectorDepartamento si ya está dentro
VectorDepartamento & VectorDepartamento :: operator+= (const VectorDepartamento & v_obj)
{
   *this = *this + v_obj;
    
    return *this;
}

// Versión 2: [VectorDepartamento] += [Departamento]
//Añade un dato Departamento al final del Departamento implícito.
// no se añadirá Departamento a VectorDepartamento si ya está dentro
VectorDepartamento & VectorDepartamento :: operator+= (const Departamento & obj)
{
    (*this).AniadeDepartamento(obj);
    return (*this);
}

/***************************************************************************/
// Operador -=:
// Versión 1: [VectorDepartamento] -= [VectorDepartamento]
//Elimina del Departamento implícito los datos Departamento que
// esté presente en los datos Departamento del Departamento
//explícito.
//si Departamento no se encuentra en el Departamento implícito no se hará nada 
VectorDepartamento & VectorDepartamento :: operator-= (const VectorDepartamento & v_obj)
{

    for (int i = 1; i <= v_obj.Totalutilizados(); i++)
    {
        (*this) -= v_obj[i];
    }

    return *this;
}

//Versión 2: [VectorDepartamento] -= [Departamento]
//Elimina del Departamento implícito el dato Departamento
//si Departamento no se encuentra en el Departamento implícito no se hará nada 
VectorDepartamento & VectorDepartamento :: operator-= (const Departamento & obj)
{
    (*this) -= ((*this) && obj);

    return *this;
}

//Versión 3: [VectorDepartamento] -= [string]
//Elimina del Departamento implícito el dato Departamento cuyo campo clave
//sea igual al string dado
//si Departamento no se encuentra en el Departamento implícito no se hará nada 
VectorDepartamento & VectorDepartamento :: operator-= (const string & obj)
{
    (*this) -= ((*this) && obj);

    return *this;
}

//Versión 4: [VectorDepartamento] -= [int]
//Elimina del Departamento implícito el dato Departamento cuyo indice sea int
//si Departamento no se encuentra en el Departamento implícito no se hará nada 
VectorDepartamento & VectorDepartamento :: operator-= (const int & indice)
{
    if (indice_valido_usados(indice))
    {
        EliminaDepartamento(indice);
    }

    return *this;
}


/***************************************************************************/
// INSERTADEPARTAMENTO
// Inserta Departamento en el vector
// Parámetros: Departamento a insertar y posición en la que insertarlo
// PRE: 1 <= indice <= Totalutilizados()
// PRE: El Departamento no existe en el vector
void VectorDepartamento :: InsertaDepartamento(Departamento &obj, int indice)
{
    // Realmente el método set ya hace esta comprobación, pero hasta llegar a
    // el se altera por completo el vector, asi que hago la comprobación por dos
    if ((*this) && obj)
    {
        cerr << "Error: Se ha intentado insertar un Departamento que ya existe"\
             << endl;
        exit(1);
    }
    
    total_utilizados++;

    // Le hago hueco al elemento para introducirlo
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

    // Redimensionar hace que se ajuste capacidad al tamaño mínimo
    ReservaMemoria(TAMANIO);
}

/***************************************************************************/
// EXTRAEDEPARTAMENTO
// Extrae Departamento del vector
// Elimina el Departamento indice del vector y lo devuelve
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
//
// PRE: Se ha reservado memoria para los datos
void VectorDepartamento :: CopiarDatos(const VectorDepartamento &otro)
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
// BUSCARDEPARTAMENTO
// Método BuscarDepartamento: Recibe un Departamento y lo busca en el vector
// Si está, devuelve el índice donde está almacenado, sino, devuelve 0
// Versión 1: Busca el Departamento dado un Departamento Departamento
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
// ANIADEDEPARTAMENTO
// Aniade Departamento al final del vector 
// Dicho Departamento no puede estar repetido
// Parámetros: obj (referencia), Departamento que se va a añadir.
void VectorDepartamento :: AniadeDepartamento(const Departamento &obj)
{
    if ((*this) && obj)
    {
        cerr << "Error: El Departamento: " << obj.GetId_Dpto() << " ya existe"
             << endl;
    }
    else if (obj.GetId_Dpto() == "VACIO" || obj.GetId_Dpto() == "NULO")
    {
        cerr << "Error: Departamento VACIO, no se añadirá" << endl;
    }
    else
    {
        total_utilizados++;

        (*this)[Totalutilizados()] = obj;

        Redimensionar();
    }
}

/***************************************************************************/
// ELIMINADEPARTAMENTO
// Elimina Departamento del vector
// Parámetros: indice, int que indica el índice del Departamento
// PRE: 1 <= indice <= Totalutilizados()
void VectorDepartamento :: EliminaDepartamento(int indice)
{
    if(indice_valido_usados(indice))
    {
        // "Desplazar" los valores desde la casilla siguiente a "indice" 
        // hasta el final una posición a la izquierda
		memmove (&(*this)[indice-1], &(*this)[indice], 
                 (Totalutilizados()-indice)*sizeof(Departamento));

        total_utilizados--;
        Redimensionar();
    }
}

/***********************************************************************/
// RESERVAMEMORIA
// Pide memoria para guardar una copia de los datos de "otro"
// Parámetros: num_casillas: Número de casillas que se desean reservar. 
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
// Libera la memoria dinámica reservada para el vector
void VectorDepartamento :: LiberarMemoria()
{
    if (vector_privado != nullptr)
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
// VALOR: Devuelve el valor de la Departamento en la posición "indice"
// Puede funcionar como lvalue y como rvalue
// Es el único método que usa y debe usar el índice "real" (desde 0)
// PRE: 0 <= indice < total_utilizados
Departamento & VectorDepartamento :: Valor(int indice) const
{
    return vector_privado[indice];
}

/***********************************************************************/
// comprobacion_indice: Comprueba si el índice es válido
// En caso que lo sea, devuelve un mensaje de error y termina el programa
// PRE: 1 <= indice <= total_utilizados
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
// En caso que lo sea, devuelve un mensaje de error y termina el programa
// PRE: 1 <= indice <= capacidad
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

/***********************************************************************/
// Indice_valido_usados: Comprueba si el índice es válido
// Devuelve true si el índice está entre 1 y total_utilizados
// Devuelve false en caso contrario
bool VectorDepartamento ::  indice_valido_usados(const int indice) const
{
    return (indice >= 1 && indice <= Totalutilizados());
}

/***********************************************************************/
// Indice_valido_capacidad: Comprueba si el índice es válido
// Devuelve true si el índice está entre 1 y capacidad
// Devuelve false en caso contrario
bool VectorDepartamento ::  indice_valido_capacidad(const int indice) const
{
    return (indice >= 1 && indice <= Capacidad());
}
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

