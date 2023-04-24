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

#include "TipoBase_Matriz2D.h"
#include <string>
using namespace std; 

class Matriz2D
{
private:

    TipoBase ** matriz = nullptr;  // Puntero a vector de punteros a los datos

public:


/***************************************************************************/
// Constructor sin argumentos, que crea una matriz vacía.
    Matriz2D(void);


/***************************************************************************/
// Constructor con 1 argumento: Crea una matriz cuadrada con el número de filas
// y columnas indicado en el argumento.

    Matri2D(int n=0);


/***************************************************************************/
// Constructor con 2 argumentos
// Parámetros:
//		nfils, número de filas de la matriz (por defecto 0).
//		ncols, número de columnas de la matriz (por defecto 0).
// PRE: nfils >= 0 && ncols >= 0

    Matriz2D(int nfils=0, int ncols=0);


/***************************************************************************/
// Constructor con 3 argumentos
// El contenido de las "fils"x"cols" casillas se ecualiza a "valor"
// Parámetros:
//		nfils, número de filas de la matriz (por defecto 0).
//		ncols, número de columnas de la matriz (por defecto 0).
//		valor, valor común que se copiará en las casillas (por defecto 0). 
// PRE: nfils >= 0 && ncols >= 0 

    Matriz2D(int nfils=0, int ncols=0, TipoBase valor=VALOR_DEF);

/***************************************************************************/
// Constructor de copia

    Matriz2D(Matriz2D &otra);

/***************************************************************************/
// Destructor de la clase Matriz2D

    ~Matriz2D (void);


/***************************************************************************/
/***************************************************************************/
// Devuelve un string con el resultado de "serializar" una matriz.
// Parámetros: matriz (referencia), la matriz que va a serializarse. 

    string ToString (const Matriz2D & matriz, string Cadena="Fila", int empiezaen=0);


/***************************************************************************/
// Sobrecarga del operador de asignación
    Matriz2D & operator = (const Matriz2D & otro);


/***************************************************************************/
// Métodos de consulta de las dimensiones de la matriz.
    int NumFilas () const;
    int NumColumnas () const;


/***************************************************************************/
// Método para acceder a un elemento de la matriz, dadas sus coordenadas (índi-
// ces). El método puede actuar como lvalue ó rvalue.
// Parámetros: matriz (referencia), la matriz. 
//			   num_fila, número de fila.
//			   num_columna, número de columna.
// PRE: 0<=num_fila<NumFilas(m)
// PRE: 0<=num_columna<NumColumnas(m)

    TipoBase & Valor (int num_fila, int num_columna); 


/***************************************************************************/
// Método que consulta si la matriz está vacía
    bool EstaVacia (void) const;


/***************************************************************************/
// Descarta todos los valores de la matriz. 
// Deja la matriz en estado “vacía”.
// La matriz sigue “activa”.
// Use esta función si tiene previsto seguir usando la matriz.
    void EliminaTodos (void);


/***************************************************************************/
// Ecualizar. Cambia todos los todos valores de la matriz por valor.
    void Ecualiza (TipoBase valor=VALOR_DEF);


/***************************************************************************/
// Copia profunda. Hace una copia profunda de origen en destino.
    void Clona (const Matriz2D & origen);


/***************************************************************************/
// Comparación.
// Devuelve true si las matrices una y otra son exactamente iguales.
// Tanto en dimensiones como contenidos.
    bool EsIgualA (const Matriz2D & otra) const;


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
/****************************************************************************
// Método para añadir una fila. La fila nueva (una dato Secuencia) debe tener el
// mismo número de casillas que columnas tenga la matriz

    void Aniade (const Secuencia & fila_nueva);

/****************************************************************************
// Método para insertar una fila en una posición dada. La fila nueva (una dato
Secuencia) debe tener el mismo número de casillas que columnas tenga la
matriz. La posición indicada será la posición que tendrá la fila después de la
inserción.
/***************************************************************************/
//Eliminar fila. Elimina la fila num_fila de la matriz matriz.
    void EliminaFila (Matriz2D & matriz, int num_fila);

//Eliminar columna. Elimina la columna num_col de la matriz matriz.
    void EliminaColumna (Matriz2D & matriz, int num_col);


/***************************************************************************/
// Espejo horizontal.
// Cambia de orden las filas de matriz (la primera pasa a ser la última y
// la última la primera, la segunda la penúltima y la penúltima la segunda etc)
    void EspejoHorizontal (Matriz2D & matriz);

//Espejo vertical. Cambia de orden las columnas de matriz (la primera
//pasa a ser la última y la última la primera, la segunda la penúltima y la
//penúltima la segunda, etc.).
    void EspejoVertical (Matriz2D & matriz);

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

    Matriz2D ReservaMemoria (int nfils, int ncols);

/***************************************************************************/
// Libera la memoria ocupada por una matriz dinámica. 
// Parámetros: 
//		matriz (referencia), la matriz que va a "liberarse". 
// POST: La matriz queda vacía (todos sus campos a cero)

    void LiberaMemoria (Matriz2D & matriz);
};