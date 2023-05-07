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
// Declaraciones en: VectorObjeto.h
//
// Fichero: VectorObjeto.cpp
//
/***************************************************************************/
/***************************************************************************/

#include "VectorObjeto.h"

using namespace std;

/*************************************************************************/
//-------------------------CONSTRUCTORES---------------------------------//
/*************************************************************************/
/***********************************************************************/
// Constructor
// Si se llama sin argumentos crea una secuencia con capacidad = TAMANIO.
// Si se llama con un argumento, su valor será la capacidad inicial. 
// POST: La secuencia creada estará vacía (EstaVacia()== true)

VectorObjeto :: VectorObjeto(int la_capacidad)
        : capacidad(0), total_utilizados(0), vector_privado(nullptr)
{
    ReservaMemoria(la_capacidad);
}

/************************************************************************/
// Constructor de copia
// Parámetros: otro (referencia), Objeto que sirve de modelo. 
VectorObjeto :: VectorObjeto(const VectorObjeto &otro)
{
    CopiarDatos(otro);
}

/************************************************************************/
// Destructor
VectorObjeto :: ~VectorObjeto()
{
    LiberarMemoria();
}

/*************************************************************************/
//----------------------------MÉTODOS------------------------------------//
/*************************************************************************/
// Métodos de acceso a los campos de la clase
int VectorObjeto :: Totalutilizados() const
{
    return total_utilizados;
}

int VectorObjeto :: Capacidad() const
{
    return capacidad;
}

int VectorObjeto :: EstaVacia() const
{
    return (total_utilizados == 0);
}

/*************************************************************************/
// Métodos get
Objeto VectorObjeto :: getObjeto(int indice) const
{
    return vector_privado[indice];
}

/***************************************************************************/
// Métodos set
void VectorObjeto :: setObjeto(int indice, Objeto &obj)
{
    vector_privado[indice] = obj;
}

/***************************************************************************/
// Método ToString
string VectorObjeto :: Serializar() const
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
// Sobrecarga del [].
// Parámetros: indice del elemento a consultar (total_utilizados => indice > 0 ). 
Objeto & VectorObjeto :: operator[](int indice) const
{
    return Valor(indice-1);
}

/***********************************************************************/
// Sobrecarga del ().
// Parámetros: indice del elemento a modificar (total_utilizados => indice > 0 ). 
Objeto & VectorObjeto :: operator[](int indice)
{
    return Valor(indice-1);
}

/***********************************************************************/
// Sobrecarga del ().
// Parámetros: indice del elemento a consultar (total_utilizados => indice > 0 ). 
Objeto & VectorObjeto :: operator()(int indice) const
{
    return (*this)[indice-1];
}

/***********************************************************************/
// Sobrecarga del ().
// Parámetros: indice del elemento a modificar (total_utilizados => indice > 0 ). 
Objeto & VectorObjeto :: operator()(int indice)
{
    return (*this)[indice-1];
}
/***************************************************************************/
// Aniade Objeto al final del vector
void VectorObjeto :: AniadeObjeto(Objeto &obj)
{
    total_utilizados++;
    Redimensionar();

    vector_privado[Totalutilizados()-1] = obj;

    cout << obj.ToString("Leido: ");
}

/***************************************************************************/
// Inserta Objeto en el vector
void VectorObjeto :: InsertaObjeto(Objeto &obj, int indice)
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
// Elimina Objeto del vector
void VectorObjeto :: EliminaObjeto(int indice)
{
    for (int indice; indice < Totalutilizados(); indice++)
    {
        vector_privado[indice] = vector_privado[indice+1];
    }

    total_utilizados--;

    Redimensionar();
}

/***************************************************************************/
// Elimina todos los Objetos del vector
void VectorObjeto :: EliminaTodos()
{
    LiberarMemoria();
}

/***************************************************************************/
// Extrae Objeto del vector 
Objeto VectorObjeto :: ExtraeObjeto(int indice)
{
    Objeto obj;

    obj = getObjeto(indice);
    EliminaObjeto(indice);

    return obj;
}

/***************************************************************************/
// Iguala capacidad a total_utilizados (no recomendable, mejor usar redimensionar)
void VectorObjeto :: Reajustar()
{
    if (Totalutilizados() < Capacidad())
    {
        capacidad = Totalutilizados();
        // Copio el vector en uno temporal
        Objeto *tmp = new Objeto[Totalutilizados()];

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
// Copiar datos desde otro Objeto de la clase
// Parámetros: otro (referencia), Objeto que sirve de modelo. 
//
// PRE: Se ha reservado memoria para los datos
void VectorObjeto :: CopiarDatos(const VectorObjeto &otro)
{
    if (this != &otro)
    {
        LiberarMemoria();
        ReservaMemoria(otro.Capacidad());

        for (int i = 0; i < otro.Totalutilizados(); i++)
        {
            vector_privado[i] = otro.getObjeto(i);
        }

        total_utilizados = otro.Totalutilizados();
    }

    Redimensionar();
}

/***********************************************************************/
// RESERVAMEMORIA
// Pide memoria para guardar una copia de los datos de "otro"
// Parámetros: otro (referencia), Objeto que sirve de modelo. 
void VectorObjeto :: ReservaMemoria(const int num_casillas)
{
	vector_privado = new Objeto[num_casillas]; 
	capacidad = num_casillas; 
}

/***********************************************************************/
// LIBERARMEMORIA
void VectorObjeto :: LiberarMemoria()
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
void VectorObjeto :: Redimensionar (void)
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
        Objeto * tmp = new Objeto[capacidad]; 

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

/***********************************************************************/
// VALOR: Devuelve el valor de la Adscripcion en la posición "indice"
// Puede funcionar como lvalue y como rvalue
// PRE: 0 <= indice < total_utilizados
Objeto & VectorObjeto :: Valor(int indice) const
{
    if (indice < 0 || indice >= Totalutilizados())
    {
        cerr << "Error en la función Valor: índice fuera de rango" << endl;
        exit(1);
    }
    
    return vector_privado[indice];
}
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
