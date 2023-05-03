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
        : capacidad(la_capacidad), total_utilizados(0), vector_privado(nullptr)
{}

/************************************************************************/
// Constructor de copia
// Parámetros: otro (referencia), Encargo que sirve de modelo. 
VectorEncargo :: VectorEncargo(const VectorEncargo &otro)
{
    CopiarDatos(otro);
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
int VectorEncargo :: Totalutilizados() const
{
    return total_utilizados;
}

int VectorEncargo :: Capacidad() const
{
    return capacidad;
}

int VectorEncargo :: EstaVacia() const
{
    return (total_utilizados == 0);
}

/*************************************************************************/
// Métodos get
Encargo VectorEncargo :: getEncargo(int indice) const
{
    return vector_privado[indice];
}

/***************************************************************************/
// Métodos set
void VectorEncargo :: setEncargo(int indice, Encargo &obj)
{
    vector_privado[indice] = obj;
}

/***************************************************************************/
// Método ToString
void VectorEncargo :: Serializar() const
{
    for (int i = 0; i < Totalutilizados(); i++)
    {
        int numero = i + 1;
        string cadena_inicial = to_string(numero) + ".- ";
        cout << vector_privado[i].ToString(cadena_inicial);
    }
}

/***********************************************************************/
// Sobrecarga del operador de asignación para copia profunda.
// Parámetros: otro (referencia), Encargo que sirve de modelo. 
VectorEncargo & VectorEncargo :: operator=(const VectorEncargo &otro)
{
    CopiarDatos(otro);
    return *this;
}

/***********************************************************************/
// Sobrecarga del [].
// Parámetros: indice del elemento a consultar (total_utilizados => indice > 0 ). 
Encargo & VectorEncargo :: operator[](int indice) const
{
    return vector_privado[indice - 1];
}

/***********************************************************************/
// Sobrecarga del ().
// Parámetros: indice del elemento a modificar (total_utilizados => indice > 0 ). 
Encargo & VectorEncargo :: operator[](int indice)
{
    return vector_privado[indice - 1];
}

/***********************************************************************/
// Sobrecarga del ().
// Parámetros: indice del elemento a consultar (total_utilizados => indice > 0 ). 
Encargo & VectorEncargo :: operator()(int indice) const
{
    return vector_privado[indice - 1];
}

/***********************************************************************/
// Sobrecarga del ().
// Parámetros: indice del elemento a modificar (total_utilizados => indice > 0 ). 
Encargo & VectorEncargo :: operator()(int indice)
{
    return vector_privado[indice - 1];
}

/***************************************************************************/
// Aniade Encargo al final del vector
void VectorEncargo :: AniadeEncargo(Encargo &obj)
{
    total_utilizados++;
    Redimensionar();

    vector_privado[Totalutilizados()-1] = obj;

    cout << obj.ToString("Leido: ");
}

/***************************************************************************/
// Inserta Encargo en el vector
void VectorEncargo :: InsertaEncargo(Encargo &obj, int indice)
{
    total_utilizados++;
    Redimensionar();

    for (int i = Totalutilizados() - 1; i > indice; i--)
    {
        vector_privado[i] = vector_privado[i-1];
    }

    vector_privado[indice] = obj;
}

/***************************************************************************/
// Elimina Encargo del vector
void VectorEncargo :: EliminaEncargo(int indice)
{
    for (int indice; indice < Totalutilizados(); indice++)
    {
        vector_privado[indice] = vector_privado[indice+1];
    }

    total_utilizados--;

    Redimensionar();
}

/***************************************************************************/
// Elimina todos los Encargos del vector
void VectorEncargo :: EliminaTodos()
{
    LiberarMemoria();
}

/***************************************************************************/
// Extrae Encargo del vector 
Encargo VectorEncargo :: ExtraeEncargo(int indice)
{
    Encargo obj;

    obj = getEncargo(indice);
    EliminaEncargo(indice);

    return obj;
}

/***************************************************************************/
// Iguala capacidad a total_utilizados (no recomendable, mejor usar redimensionar)
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

        for (int i = 0; i < otro.Totalutilizados(); i++)
        {
            vector_privado[i] = otro.getEncargo(i);
        }

        total_utilizados = otro.Totalutilizados();
    }

    Redimensionar();
}

/***********************************************************************/
// RESERVAMEMORIA
// Pide memoria para guardar una copia de los datos de "otro"
// Parámetros: otro (referencia), Encargo que sirve de modelo. 
void VectorEncargo :: ReservaMemoria(const int num_casillas)
{
	vector_privado = new Encargo[num_casillas]; 
	capacidad = num_casillas; 
}

/***********************************************************************/
// LIBERARMEMORIA
void VectorEncargo :: LiberarMemoria()
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
    

    if (haceralgo)
    {
        #ifdef DEBUG_SECUENCIA
        cout << endl;
        cout << "REDIMENSIONADO HASTA --> " << capacidad << " CASILLAS" << endl;
        cout << endl;
        #endif
        
        // Pedir memoria para el nuevo almacen 
        Encargo * tmp = new Encargo[capacidad]; 

        // Copiar los datos 
        for (int i = 0; i < Totalutilizados()-1; i++)
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

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

