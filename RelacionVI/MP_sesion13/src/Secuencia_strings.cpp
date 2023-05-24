/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// Clase "Secuencia"
//
// Representación: array dinámico para alojar los datos en el Heap.
// Los datos son de tipo "TipoBaseSecuencia"
//
// Definición de la clase Secuencia (versión 1).
// Declaraciones en Secuencia.h
//
// Incluye: 
//		* constructor de copia
//		* destructor
// 
// Fichero: Secuencia.cpp
//
/***************************************************************************/

#include "Secuencia_string.h"
#include "TipoBase_Secuencia_string.h"

#include <cstring>
#include <string>
#include <iostream>
using namespace std;


/***********************************************************************/
// Constructores.
// Si se llama sin argumentos crea una secuencia con capacidad = TAMANIO.
// Si se llama con un argumento, su valor será la capacidad inicial. 
// POST: La secuencia creada estará vacía (EstaVacia()== true)

Secuencia_string :: Secuencia_string (int la_capacidad)
	: capacidad (la_capacidad), 
	  total_utilizados (0) 
{
	ReservarMemoria (capacidad);
}

/***********************************************************************/
// Constructor de copia

Secuencia_string :: Secuencia_string (const Secuencia_string & otro)
{
	ReservarMemoria (otro.capacidad);
	CopiarDatos (otro);
}

/***********************************************************************/
// Destructor 

Secuencia_string :: ~Secuencia_string (void)
{
	LiberarMemoria();
}

/***********************************************************************/


/***********************************************************************/
// Devuelve el número de casillas ocupadas

int Secuencia_string :: TotalUtilizados (void) const
{
	return (total_utilizados);
}

/***********************************************************************/
// Devuelve el número de casillas disponibles

int Secuencia_string :: Capacidad (void) const
{
	return (capacidad);
}

/***********************************************************************/
// Devuelve "true" si la secuencia está vacía (total_utilizados == 0)

bool Secuencia_string :: EstaVacia (void) const 
{
	return (total_utilizados == 0);
}

/***********************************************************************/
// "Vacía" completamente la secuencia
// POST: EstaVacia() == true 
// POST: Capacidad() == TAMANIO.

void Secuencia_string :: EliminaTodos()
{
	LiberarMemoria();		// La secuencia queda vacía
	ReservarMemoria (TAMANIO);	// Capacidad = TAMANIO
}

/***********************************************************************/
// Devuelve una referencia al elemento de la casilla "indice"
// Parámetros: 
//      indice, Numero de casilla a la que se accede. 
// PRE: 0 <= indice < TotalUtilizados()
// (NUEVA) PRE: 1 <= indice <= TotalUtilizados()

TipoBaseSecuencia & Secuencia_string :: Valor (const int indice)
{
    return (el_valor(indice));
}

TipoBaseSecuencia & Secuencia_string :: Valor (const int indice) const
{
    return (el_valor(indice));
}

/***********************************************************************/
// Copia profunda.
// Parámetros: 
//      otra (referencia), objeto que sirve de modelo para la copia. 

void Secuencia_string :: Clona (const Secuencia_string & otro)
{
	// PRECAUCIÓN: No evitamos la autoasignación

	LiberarMemoria(); // La secuencia queda vacía
	ReservarMemoria (otro.capacidad);
	CopiarDatos (otro);
}

/***********************************************************************/
// Añade un elemento ("nuevo") a la secuencia.
// Parámetros: 
//      nuevo, valor que se añade a la secuencia.
// El nuevo elemento se coloca al final del vector.
// Se redimensionará el vector dinámico de datos si no tuviera suficiente 
// espacio disponible.

void Secuencia_string :: Aniade (TipoBaseSecuencia nuevo)
{
	// Comprobar si hay que redimensionar el array dinámico

	int umbral_redimension = (PORC_PETICION*capacidad)/100;

	// cout << "umbral_redimension = " << umbral_redimension << endl;

	if (total_utilizados >= umbral_redimension) 
		Redimensionar ();

	// Añadir al final del array dinámico y actualizar "total_utilizados"
	vector_privado [total_utilizados] = nuevo;
	total_utilizados++;
}

/***********************************************************************/
// Inserta el valor "nuevo" en la posición dada por "indice".
// Parámetros: 
//      nuevo, valor que se añade a la secuencia.
// "Desplaza" todos los enteros una posición a la derecha antes de 
// copiar en "indice" en valor "nuevo".
// PRE: 0 <= indice < TotalUtilizados()
//
// Se redimensionará el vector dinámico de datos si no tuviera suficiente 
// espacio disponible.

void Secuencia_string :: Inserta (int indice, TipoBaseSecuencia nuevo)
{
	// Comprobar si hay que redimensionar el array dinámico

	int umbral_redimension = (PORC_PETICION*capacidad)/100;

	// cout << "umbral_redimension = " << umbral_redimension << endl;

	if (total_utilizados >= umbral_redimension) 
		Redimensionar ();

	// "Desplazar" los valores desde la casilla "indice" hasta el final 
	// una posición a la derecha
	memmove (&vector_privado[indice+1], &vector_privado[indice], 
                 total_utilizados-indice*sizeof(TipoBaseSecuencia)); 

	// Escribir "nuevo" en la casilla "indice" y actualizar "total_utilizados"
	vector_privado [indice] = nuevo;
	total_utilizados++;
}

/***********************************************************************/
// Eliminar el contenido de la "casilla" cuya posición es "indice".
// Parámetros: 
//      indice, Numero de casilla a la que se accede. 
// PRE: 0 <= indice < TotalUtilizados()
// 
/* 
	Una consecuencia de la eliminación podría ser la reducción de la 
	capacidad de la secuencia. Esto ocurrirá cuando el número de casillas 
	usadas es inferior al "PROC_REDUCCION" de la capacidad actual.

	El número de casillas finales no será fijo, sino que será un "PORC_EXTRA" 
	superior a la ocupación de la secuencia después de la eliminación. 
*/

void Secuencia_string :: Elimina (int indice)
{
    if ((indice >= 0) && (indice < total_utilizados)) {

		// "Desplazar" los valores desde la casilla siguiente a "indice" 
		// hasta el final una posición a la izquierda 

		memmove (&vector_privado[indice], &vector_privado[indice+1], 
                 (total_utilizados-indice-1)*sizeof(TipoBaseSecuencia));
 
		// Actualizar "total_utilizados"
        total_utilizados--;
    }

}
   
/***********************************************************************/
// Compone un string con todos los caracteres que están
// almacenados en la secuencia y lo devuelve.

string Secuencia_string :: ToString() const
{
    string cadena;

	cadena = "[ ";

    for (int i=0; i<total_utilizados; i++) {

		#ifdef STRING
        cadena = cadena + "  " + vector_privado[i];
		#else
		#ifdef CHAR
        cadena = cadena + "  " + vector_privado[i];
		#else
		#ifdef DOUBLE
        cadena = cadena + "  " + to_string(vector_privado[i]);
		#endif
		#endif
		#endif
	}

	cadena = cadena + "]";

    return (cadena);
}

/***************************************************************************/
/***************************************************************************/
// MÉTODOS PRIVADOS DE LA CLASE Secuencia
/***************************************************************************/
/***************************************************************************/

/***************************************************************************/
// Pide memoria para guardar "num_casillas" datos	
// PRE: 0 <= num_casillas
 
void Secuencia_string :: ReservarMemoria (const int num_casillas)
{
	vector_privado = new TipoBaseSecuencia[num_casillas]; 
	capacidad = num_casillas; 
}

/***************************************************************************/
// Libera memoria

void Secuencia_string :: LiberarMemoria (void)
{
	if (vector_privado)
	{ 

		delete [] vector_privado;

		vector_privado = nullptr;
		capacidad = 0; 
		total_utilizados = 0;
	}
}

/***************************************************************************/
// Copiar datos desde otro objeto de la clase
// PRE: Se ha reservado memoria para los datos

void Secuencia_string :: CopiarDatos (const Secuencia_string & otro)
{
	// Copia los valores de los campos privados desde "otro" 
	capacidad = otro.capacidad;  
	total_utilizados = otro.total_utilizados;	

	// Copiar los valores de los datos
	memcpy (vector_privado, otro.vector_privado, 
            total_utilizados*sizeof(TipoBaseSecuencia));
}

/***************************************************************************/
// Redimensiona el vector dinámico y copia los datos en el nuevo almacén.  
//
// Pedirá memoria adicional si el número de casillas usadas es superior al 
// "PROC_PETICION" de la capacidad actual. El número de casillas adicionales 
// será el "PORC_CRECIMIENTO" de la capacidad actual (no será un valor fijo). 

void Secuencia_string :: Redimensionar (void)
{
	int casillas_adicionales = (PORC_CRECIMIENTO*capacidad)/100;

	int minimo = MIN_CRECIMIENTO;
 	capacidad += max(casillas_adicionales,minimo);


	#ifdef DEBUG_SECUENCIA
	cout << endl;
	cout << "REDIMENSIONADO HASTA --> " << capacidad << " CASILLAS" << endl;
	cout << endl;
	#endif
	
	// Pedir memoria para el nuevo almacen 
	TipoBaseSecuencia * tmp = new TipoBaseSecuencia[capacidad]; 

	// Copiar los datos 
	memcpy (tmp, vector_privado, total_utilizados*sizeof(TipoBaseSecuencia)); 

	// Liberar la memoria del antiguo almacén
	delete [] vector_privado; 

	// Reasignacion del puntero "vector_privado" para que referencie 
	// a la nueva zona de memoria ampliada y con los datos copiados. 
	vector_privado = tmp; 
}

/***********************************************************************/
// Método PRIVADO compartido por: 
//      TipoBaseSecuencia & Valor (const int indice);
//      TipoBaseSecuencia & Valor (const int indice) const;
// para evitar la duplicidad de código.
// 
// Devuelve una referencia a un dato TipoBaseSecuencia de la secuencia.
// dado su posición. 
//
// PRE: 0 <= indice < TotalUtilizados()
// (NUEVA) PRE: 1 <= indice <= TotalUtilizados()


TipoBaseSecuencia & Secuencia_string :: el_valor (int indice) const
{
    return (vector_privado[indice]);
}

/***************************************************************************/
