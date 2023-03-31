/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// AUTOR: MARCO GIRELA VIDA
// GRUPO: 1ºB
// FECHA: xx/03/2023
//
// RELACION DE PROBLEMAS 2
//
// Fichero: FuncsVectorDinamico.h
//
/***************************************************************************/
/***************************************************************************/

#ifndef FUNCS_VECT_DIN
#define FUNCS_VECT_DIN

#include <string>
using namespace std;

// Capacidad inicial
const int TAM_INICIAL = 10;
// Tamanio del bloque para redimensionar (modalidad EnBloques)
const int TAM_BLOQUE = 5;
// Tipo de los datos almacenados (en este caso, int)
typedef int TipoBase;

// He asociado un número a cada elemento del enum
// (1, de uno en uno; 2, en bloques; 3 duplicando)
enum class TipoRedimension {DeUnoEnUno=1,EnBloques=2,Duplicando=3};


typedef struct {
	TipoBase * datos; // Puntero para acceder a los datos
	int usados; // Num. casillas usadas
	int capacidad; // Num. casillas reservadas

	// PRE: 0 <= usados <= capacidad
	// Inicialmente, capacidad = TAM_INICIAL

	TipoRedimension tipo_redim; // Modelo de crecimiento

} VectorDinamico;




/***************************************************************************/
/***************************************************************************/
// Crear vector dinámico
// Argumentos: capacidad_inicial, número de casillas con las que se crea el vector.
// Devuelve: el vector dinámico creado.
// POST: El número de casillas usadas es 0
//       El número de casillas reservadas es "capacidad_inicial"

VectorDinamico CreaVectorDinamico (int cap_inic=TAM_INICIAL, \
	TipoRedimension tipo=TipoRedimension::EnBloques);




/***************************************************************************/
/***************************************************************************/
// Libera la memoria ocupada por un vector dinámico
// Argumentos: v (referencia) El vector que se va liberar.
// POST: El número de casillas usadas es 0
//       El número de casillas reservadas es 0

void DestruyeVectorDinamico (VectorDinamico & v);




/***************************************************************************/
/***************************************************************************/
// Calcula el n�mero de casillas usadas de un vector din�mico.
// Argumentos: v, el vector que se va a consultar.
// Devuelve: el n�mero de casillas usadas de un vector din�mico

int  UsadosVectorDinamico (const VectorDinamico & v);



/***************************************************************************/
/***************************************************************************/
// Calcula el n�mero de casillas reservadas de un vector din�mico.
// Argumentos: v, el vector que se va a consultar.
// Devuelve: el n�mero de casillas reservadas de un vector din�mico

 int CapacidadVectorDinamico (const VectorDinamico & v);




/***************************************************************************/
/***************************************************************************/
// Deja el vector dinámico vacío
// Argumentos: v (referencia) El vector que se va "vaciar"
// POST: El número de casillas usadas es 0

bool EstaVacioVectorDinamico (const VectorDinamico & v);



/***************************************************************************/
/***************************************************************************/
// Deja el vector dinámico vacío
// Argumentos: v (referencia) El vector que se va "vaciar"
// POST: El número de casillas usadas es 0

void EliminaTodosVectorDinamico (VectorDinamico & v);




/*****************************************************************************/
/*****************************************************************************/
// Inicializa el vector dinámico, sustituyendo el contenido de todas
// las casillas usadas por el valor "valor".
// PRE: El vector debe existir

void EcualizaVectorDinamico (VectorDinamico & v, const TipoBase valor);




/***************************************************************************/
/***************************************************************************/
// Consulta y modifica el valor de una casilla dada. Si se utiliza como 
// rvalue se emplea para consultar el valor de la casilla "num_casilla". 
// Si se utiliza como lvalue se emplea para modificar el valor de la 
// casilla num_"casilla".
// 
// Argumentos: 	
//		v (referencia), referencia al vector. 
//		num_casilla, número de casilla (índice) en la que estamos interesados.
//
// PRE: 0<=num_casilla<UsadosVectorDinamico(v)

TipoBase & ValorVectorDinamico (VectorDinamico & v, const int num_casilla);	


/***************************************************************************/
/***************************************************************************/
// Hace una copia profunda de origen en destino
// Si no tiene capacidad suficiente, destruye el vector y vuelve 
// a pedir memoria nueva adaptada al tamaño de origen

void ClonaVectorDinamico (VectorDinamico & destino, \
						  const VectorDinamico & origen);




/***************************************************************************/
/***************************************************************************/
// Serializa un dato de tipo "VectorDinamico"
// Argumentos: v (referencia), el vector que se va a serializar.

string ToString (const VectorDinamico & v);



/***************************************************************************/
/***************************************************************************/
// Añade un valor al vector dinámico
// Argumentos: 	
//		v (referencia), referencia al vector que se va a modificar. 
//		valor, valor que se va a añadir al vector. 
// NOTA: Si no hay espacio libre, la función pide espacio adicional usando 
//		 la función RedimensionaVectorDinamico. 

void AniadeVectorDinamico (VectorDinamico &v, const int valor);



/***************************************************************************/
/***************************************************************************/
// Inserta un valor en la casilla del vector dinámico dada
// Argumentos: 	
//		v (referencia), referencia al vector que se va a modificar. 
//		valor, valor que se va a añadir al vector. 
//		num_casilla, casilla donde se va a añadir el valor
// NOTA: Si no hay espacio libre, la función pide espacio adicional usando 
//		 la función RedimensionaVectorDinamico. 
// PRE: 0<=num_casilla<UsadosVectorDInamico(v)

void InsertaVectorDinamico (VectorDinamico &v, const TipoBase valor, \
						   const int num_casilla);



/***************************************************************************/
/***************************************************************************/
// ELimina un valor de la casilla del vector dinámico dada
// Argumentos: 	
//		v (referencia), referencia al vector que se va a modificar. 
//		num_casilla, casilla donde se va a eliminarse el valor 

void EliminaVectorDinamico (VectorDinamico &v, const int num_casilla);




/***************************************************************************/
/***************************************************************************/
// Redimensiona el vector dinámico "v" de acuerdo al tipo de redimensión 
// registrado en "v". 
// Además, copia todos los datos en el nuevo vector.  
// Argumentos: 	
//		v (referencia), referencia al vector que se va a redimensionar. 
			
void  RedimensionaVectorDinamico (VectorDinamico & v);


/***************************************************************************/
/***************************************************************************/
// Redimensiona un vector dinámico para que no haya espacio libre.
// Copia todos los datos en el nuevo vector.
// Argumentos: 	
//		v (referencia), referencia al vector que se va a reajustar. 
// POST: capacidad = usados

void  ReajustaVectorDinamico (VectorDinamico & v);

/***************************************************************************/
/***************************************************************************/
// Transforma una cadena de caracteres a Tipobase
TipoBase TransformaATipoBase(char * valor);


#endif