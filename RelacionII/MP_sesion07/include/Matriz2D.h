/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// AUTOR: MARCO GIRELA VIDA
// GRUPO: 1ºB
// FECHA: xx/04/2023
//
// RELACION DE PROBLEMAS 2
//
// Fichero: Matriz2D.h
/*****************************************************************************/

#ifndef MATRIZ2D
#define MATRIZ2D

#include <string>
using namespace std; 


/***************************************************************************/
// Definiciones de tipos

typedef int TipoBase;	// Tipo de los datos de la matriz
typedef struct {

	TipoBase ** datos;	// Puntero a vector de punteros a los datos

	int fils;			// Num. de filas
	int cols; 			// Num. de columnas
} Matriz2D;

/***************************************************************************/
// Constantes globales
const TipoBase VALOR_DEF = 0; // Valor por defecto de los datos de la matriz

/***************************************************************************/
/***************************************************************************/
// Crea una matriz dinámica con "nfils" filas y "ncols" columnas. 
// El contenido de las "fils"x"cols" casillas se inicializa a un valor común, 
// el indicado en el parámetro "valor"
// Parámetros:
//		nfils, número de filas de la matriz (por defecto 0).
//		ncols, número de columnas de la matriz (por defecto 0).
//		valor, valor común que se copiará en las casillas (por defecto 0). 
// Devuelve: un dato de tipo Matriz2D.
//
// PRE: nfils >= 0 && ncols >= 0
// NOTA: Tanto "nfils" como "nols" deben ser estrictamente positivos para poder 
// 		 disponer de una matriz no vacía. Si alguno de los dos valores fuera 0  
//		 no se reserva memoria, y la matriz queda vacía. 

Matriz2D CreaMatriz (int nfils=0, int ncols=0, TipoBase valor=0);

/***************************************************************************/
/***************************************************************************/
// "Destruye" una matriz dinámica y la deja en un estado no útil (vacía). 
// Parámetros: 
//		matriz (referencia), la matriz que va a "destruirse". 
// POST: La matriz queda vacía (todos sus campos a cero)

void DestruyeMatriz (Matriz2D & matriz);

/***************************************************************************/
/***************************************************************************/
// PRIVADA
// Reserva memoria para los datos de una matriz dinámica con "nfils" filas 
// y "ncols" columnas. 
// El contenido de las "nfils"x"ncols" casillas queda INDEFINIDO.
// Parámetros:
//		nfils, número de filas de la matriz.
//		ncols, número de columnas de la matriz. 
// Devuelve: un dato Matriz2D con memoria reservada.
// 		El contenido de las "fils"x"cols" casillas queda indefinido. 
//
// PRE: nfils >= 0 && ncols >= 0
// NOTA: Tanto "nfils" como "nols" deben ser estrictamente positivos para poder 
// 		 disponer de una matriz no vacía. Si alguno de los dos valores fuera 0  
//		 no se reserva memoria, y la matriz queda vacía. 

//Matriz2D ReservaMemoria (int nfils, int ncols);

/***************************************************************************/
/***************************************************************************/
// PRIVADA
// Libera la memoria ocupada por una matriz dinámica. 
// Parámetros: 
//		matriz (referencia), la matriz que va a "liberarse". 
// POST: La matriz queda vacía (todos sus campos a cero)

//void LiberaMemoria (Matriz2D & matriz);

/***************************************************************************/
/***************************************************************************/
// Devuelve un string con el resultado de "serializar" una matriz.
// Parámetros: matriz (referencia), la matriz que va a serializarse. 

string ToString (const Matriz2D & matriz, string Cadena="Fila", int empiezaen=0);

/***************************************************************************/
/***************************************************************************/


/***************************************************************************/
/***************************************************************************/
// Devuelve el número de filas/columnas de la matriz.
// Parámetros: matriz (referencia), la matriz que se va a consultar. 

int NumFilas (const Matriz2D & matriz);
int NumColumnas (const Matriz2D & matriz);

/***************************************************************************/
/***************************************************************************/
// Consulta ó modifica el valor de una casilla dada. Si se utiliza como 
// rvalue se emplea para consulta. Si se utiliza como lvalue se emplea 
// para modificación.
// Parámetros: matriz (referencia), la matriz. 
//			   num_fila, número de fila.
//			   num_columna, número de columna.
// PRE: 0<=num_fila<NumFilas(m)
// PRE: 0<=num_columna<NumColumnas(m)

TipoBase & Valor (const Matriz2D & matriz, int num_fila, int num_columna); 

/***************************************************************************/
/***************************************************************************/
// Consultar el estado vacía/ocupada.
// Devuelve true si la matriz está vacía.
bool EstaVacia (const Matriz2D & matriz);

/***************************************************************************/
/***************************************************************************/
// Descarta todos los valores de la matriz. 
// Deja la matriz en estado “vacía”.
// La matriz sigue “activa”.
// Use esta función si tiene previsto seguir usando la matriz.
void EliminaTodos (Matriz2D & matriz);

/***************************************************************************/
/***************************************************************************/
// Ecualizar. Cambia todos los todos valores de la matriz por valor.
void Ecualiza (Matriz2D & matriz, TipoBase valor=VALOR_DEF);

/***************************************************************************/
/***************************************************************************/
// Copia profunda. Hace una copia profunda de origen en destino.
void Clona (Matriz2D & destino, const Matriz2D & origen);

/***************************************************************************/
/***************************************************************************/
// Comparación.
// Devuelve true si las matrices una y otra son exactamente iguales.
// Tanto en dimensiones como contenidos.
bool SonIguales (const Matriz2D & una, const Matriz2D & otra);

/***************************************************************************/
/***************************************************************************/
/*
Submatriz.
Extrae una submatriz de original y la deja en resultado.
La submatriz resultado es una zona rectangular de
original que empieza en la casilla (fila_inic, col_inic) y que
tiene (un máximo de) num_filas filas y num_cols columnas.

La función construirá y “rellenará” una matriz vacía. Lo mismo ocurre
si la casilla inicial fuera, por ejemplo, la casilla 2 (fila), -2 (columna).
*/
void SubMatriz (Matriz2D & resultado, const Matriz2D & original,
int fila_inic, int col_inic, int num_filas, int num_cols);

/***************************************************************************/
/***************************************************************************/
//Eliminar fila. Elimina la fila num_fila de la matriz matriz.
void EliminaFila (Matriz2D & matriz, int num_fila);

/***************************************************************************/
/***************************************************************************/
//Eliminar columna. Elimina la columna num_col de la matriz matriz.
void EliminaColumna (Matriz2D & matriz, int num_col);

/***************************************************************************/
/***************************************************************************/
// Espejo horizontal.
// Cambia de orden las filas de matriz (la primera pasa a ser la última y
// la última la primera, la segunda la penúltima y la penúltima la segunda etc)
void EspejoHorizontal (Matriz2D & matriz);

//Espejo vertical. Cambia de orden las columnas de matriz (la primera
//pasa a ser la última y la última la primera, la segunda la penúltima y la
//penúltima la segunda, etc.).
void EspejoVertical (Matriz2D & matriz);

#endif