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
    CopiarDatos(otro);
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

/*************************************************************************/
// Métodos get
Departamento VectorDepartamento :: getDepartamento(int indice) const
{
    return vector_privado[indice];
}

/***************************************************************************/
// Métodos set
void VectorDepartamento :: setDepartamento(int indice, Departamento &obj)
{
    if (BuscarDepto(obj) != -1)
    {
        cerr << "Error: El departamento ya existe" << endl;
        exit(1);
    }

    vector_privado[indice] = obj;
}

/***************************************************************************/
// Método ToString
string VectorDepartamento :: Serializar() const
{
    string cad;

    for (int i = 0; i < Totalutilizados(); i++)
    {
        int numero = i + 1;
        string cadena_inicial = to_string(numero) + ".- ";
        cad += vector_privado[i].ToString(cadena_inicial) + "\n";
    }
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
    return Valor(indice-1);
}

/***********************************************************************/
// Sobrecarga del ().
// Parámetros: indice del elemento a modificar (total_utilizados => indice > 0 ). 
Departamento & VectorDepartamento :: operator[](int indice)
{
    return Valor(indice-1);
}

/***********************************************************************/
// Sobrecarga del ().
// Parámetros: indice del elemento a consultar (total_utilizados => indice > 0 ). 
Departamento & VectorDepartamento :: operator()(int indice) const
{
    return (*this)[indice-1];
}

/***********************************************************************/
// Sobrecarga del ().
// Parámetros: indice del elemento a modificar (total_utilizados => indice > 0 ). 
Departamento & VectorDepartamento :: operator()(int indice)
{
    return (*this)[indice-1];
}

/***************************************************************************/
// Método BuscarDepto: Recibe un departamento y lo busca en el vector
// Si está, devuelve el índice donde está almacenado, sino, devuelve -1
int VectorDepartamento :: BuscarDepto(Departamento dep) const
{
    int indice = -1;

    for (int i = 0; i < Totalutilizados(); i++)
    {
        if (vector_privado[i] == dep)
        {
            indice = i;
        }
    }

    return indice;
}

/***************************************************************************/
// Aniade Departamento al final del vector 
void VectorDepartamento :: AniadeDepartamento(Departamento &obj)
{
    if (BuscarDepto(obj) != -1)
    {
        cerr << "Error: Se ha intentado añadir un departamento que ya existe"\
             << endl;
        exit(1);
    }
    
    total_utilizados++;
    Redimensionar();

    setDepartamento(Totalutilizados()-1, obj);

    cout << obj.ToString("Leido: ");
}

/***************************************************************************/
// Inserta Departamento en el vector
void VectorDepartamento :: InsertaDepartamento(Departamento &obj, int indice)
{
    if (BuscarDepto(obj) != -1)
    {
        cerr << "Error: Se ha intentado insertar un departamento que ya existe"\
             << endl;
        exit(1);
    }
    
    total_utilizados++;
    Redimensionar();

    for (int i = Totalutilizados() - 1; i > indice; i--)
    {
        vector_privado[i] = vector_privado[i-1];
    }

    setDepartamento(indice, obj);
}

/***************************************************************************/
// Elimina Departamento del vector
// PRE: 0 <= indice < Totalutilizados()
void VectorDepartamento :: EliminaDepartamento(int indice)
{
    comprobacion_indice(indice);

    for (int indice; indice < Totalutilizados(); indice++)
    {
        vector_privado[indice] = vector_privado[indice+1];
    }

    total_utilizados--;

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
// PRE: 0 <= indice < Totalutilizados()
Departamento VectorDepartamento :: ExtraeDepartamento(int indice)
{
    comprobacion_indice(indice);
    
    Departamento obj;

    obj = getDepartamento(indice);
    EliminaDepartamento(indice);

    return obj;
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
        LiberarMemoria();
        ReservaMemoria(otro.Capacidad());

        for (int i = 0; i < otro.Totalutilizados(); i++)
        {
            vector_privado[i] = otro.getDepartamento(i);
        }

        total_utilizados = otro.Totalutilizados();
    }

    // Redimensiono para no estár "ajustado" entre capacidad y total_utilizados
    Redimensionar();
}

/***********************************************************************/
// RESERVAMEMORIA
// Pide memoria para guardar una copia de los datos de "otro"
// Parámetros: otro (referencia), Departamento que sirve de modelo. 
// PRE: num_casillas > 0
void VectorDepartamento :: ReservaMemoria(const int num_casillas)
{
    if (num_casillas <= 0)
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
    if (vector_privado)
	{ 
		delete [] vector_privado;

		vector_privado = nullptr;
		capacidad = 0; 
		total_utilizados = 0;
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
    

    if (haceralgo)
    {
        #ifdef DEBUG_SECUENCIA
        cout << endl;
        cout << "REDIMENSIONADO HASTA --> " << capacidad << " CASILLAS" << endl;
        cout << endl;
        #endif

        // Pedir memoria para el nuevo almacen 
        Departamento * tmp = new Departamento[capacidad]; 

        // Copiar los datos 
        for (int i = 0; i < Totalutilizados() - 1; i++)
        {
            tmp[i] = vector_privado[i]; // El operador = debe estar correctamente implementado
        }

        // Liberar la memoria del antiguo almacén
        delete [] vector_privado; 

        // Reasignacion del puntero "vector_privado" para que referencie 
        // a la nueva zona de memoria ampliada y con los datos copiados. 
        vector_privado = tmp; 
    }
}

/***********************************************************************/
// VALOR: Devuelve el valor de la Adscripcion en la posición "indice"
// Puede funcionar como lvalue y como rvalue
// PRE: 0 <= indice < total_utilizados
Departamento & VectorDepartamento :: Valor(int indice) const
{
    comprobacion_indice(indice);
    
    return vector_privado[indice];
}

/***********************************************************************/
// comprobacion_indice: Comprueba si el índice es válido
// PRE: 0 <= indice < total_utilizados
void VectorDepartamento :: comprobacion_indice(int indice) const
{
    if (indice < 0 || indice >= Totalutilizados())
    {
        cerr << "Error en la función Valor: índice fuera de rango" << endl;
        exit(1);
    }
}
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

