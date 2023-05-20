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
#include "Secuencia.h"
#include <string>
using namespace std; 

class Matriz2D
{
private:

	TipoBase ** datos;	// Puntero a vector de punteros a los datos

	int fils;			// Num. de filas
	int cols; 			// Num. de columnas

    // PRE: fils >= 0 Y cols >= 0
    // PRE: Si fils = 0 entonces cols = 0
public:


/***************************************************************************/
/*---------------------------CONSTRUCTORES/DESTRUCTOR----------------------*/
/***************************************************************************/
// Constructor sin argumentos, que crea una matriz vacía.
    Matriz2D(void);


/***************************************************************************/
// Constructor con 1 argumento: Crea una matriz cuadrada con el número de filas
// y columnas indicado en el argumento.
// Parametros: n = número de filas y columnas de la matriz.
    Matriz2D(int n);


/***************************************************************************/
// Constructor con 2 argumentos
// Parámetros:
//		nfils, número de filas de la matriz (por defecto 0).
//		ncols, número de columnas de la matriz (por defecto 0).
// PRE: nfils >= 0 && ncols >= 0

    Matriz2D(int nfils, int ncols);


/***************************************************************************/
// Constructor con 3 argumentos
// El contenido de las "fils"x"cols" casillas se ecualiza a "valor"
// Parámetros:
//		nfils, número de filas de la matriz.
//		ncols, número de columnas de la matriz.
//		valor, valor común que se copiará en las casillas . 
// PRE: nfils >= 0 && ncols >= 0 

    Matriz2D(int nfils, int ncols, TipoBase valor);

/***************************************************************************/
// Constructor de copia
// Copia los datos de la matriz "otra" en la matriz a crear
    Matriz2D(const Matriz2D &otra);

/***************************************************************************/
// Destructor de la clase Matriz2D
    ~Matriz2D (void);


/***************************************************************************/
/*-----------------------------MÉTODOS PÚBLICOS------------------------*/
/***************************************************************************/
// Sobrecarga del operador de asignación
// Copia los datos de otro en la matriz implicita
    Matriz2D & operator = (const Matriz2D & otro);
    Matriz2D & operator = (TipoBase valor);
    
/***************************************************************************/
// Sobrecarga del operador () para usarlo como rvalue o lvalue
// Parámetros: Posición del elemento (fils, cols) a consultar o modificar.
// Devuelve: referencia al dato al que se accede.
// PRE: 0<fila<=NumFilas(m) && 0<columna<=NumColumnas(m)
int& operator()(const int fila, const int columna);
int& operator()(const int fila, const int columna) const;

/***************************************************************************/
// Sobrecarga de los operadores == y !=
// Versión 1: Compara si dos matrices son iguales/distintas
// Versión 2: Compara si una matriz es igual/distinta a un valor común
// Devuelve:bool que determina si las dimensiones y elementos de ambas matrices
// son iguales o no.
bool operator ==(const Matriz2D &otra) const;
bool operator !=(const Matriz2D &otra) const;

bool operator ==(const int valor) const;
bool operator !=(const int valor) const;

/***************************************************************************/
// Sobrecarga de los operadores unarios + y -
// Operador +: Devuelve la matriz implícita sin modificar
Matriz2D operator + (void) const;

// Operador -: Se invierten los valores de la matriz implítica
Matriz2D operator - (void) const;

/***************************************************************************/
// Sobrecarga de los operadores binarios + y -
// Si los dos operadores son de tipo Matriz2D sólo se hará la suma
// o la resta si las dos matrices tienen las mismas dimensiones.
// Si no fuera así, devolverá una matriz vacía.

// Operador +: Matriz2D + Matriz2D
// Devuelve una matriz con la suma de los elementos de ambas matrices
// No se modifica ninguno de los operandos ni la matriz implícita
friend Matriz2D operator + (const Matriz2D m1, const Matriz2D & m2);

// Operador +: Matriz2D + TipoBaseMatriz2D (o viceversa)
// Devuelve una matriz producto de la suma de los elementos de m1 con lo que
// sería una matriz con las dimensiones de m1 y con todos sus elementos iguales
// a valor.
// No se modifica ninguno de los operandos ni la matriz implícita
friend Matriz2D operator + (const Matriz2D m1, const TipoBase valor);

friend Matriz2D operator + (const TipoBase valor, const Matriz2D m1);

// Operador -: Matriz2D - Matriz2D
// Devuelve una matriz con la resta de los elementos de ambas matrices
// No se modifica ninguno de los operandos ni la matriz implícita
friend Matriz2D operator - (const Matriz2D & m1, const Matriz2D & m2);

// Operador -: Matriz2D - TipoBaseMatriz2D (o viceversa)
// Devuelve una matriz producto de la resta de los elementos de m1 con lo que
// sería una matriz con las dimensiones de m1 y con todos sus elementos iguales
// a valor.
// No se modifica ninguno de los operandos ni la matriz implícita
friend Matriz2D operator - (const Matriz2D m1, const TipoBase valor);

friend Matriz2D operator - (const TipoBase valor, const Matriz2D m1);

/***************************************************************************/
// Sobrecarga de los operadores combinados += y -=:
// Operador +=: Devuelve la matriz implícita a la que se le suman los elementos
// de la matriz "otra"
Matriz2D & operator += (const Matriz2D & otra);

// Operador -=:Devuelve la matriz implícita a la que se le restan los elementos
// de la matriz "otra"
Matriz2D & operator -= (const Matriz2D & otra);

/***************************************************************************/
// Sobrecarga del operador *
// Matriz2D * int: Devuelve una matriz con los valores de la
// matriz implícita multiplicados por el valor int
// No se madifican los valores de la matriz implícita
friend Matriz2D operator * (const Matriz2D & original, const TipoBase valor);

friend Matriz2D operator * (const TipoBase valor, const Matriz2D & original);

// Matriz2D * Matriz2D: Devuelve una matriz con los valores de la
// matriz implícita multiplicados por los valores de la matriz "otra"
// No se madifican los valores de ninguno de los operandos
// friend Matriz2D & operator * (const Matriz2D & m1, const Matriz2D & m2);

/***************************************************************************/
// Devuelve un string con el resultado de "serializar" una 
// Parámetros: matriz (referencia), la matriz que va a serializarse. 
// Parámetros: Cadena: Texto que se pondrá al inicio de cada fila.
// "Fila" por defecto
// Parámetros: empiezaen: Número de fila en la que se empezará a serializar.
// 1 por defecto.
    string ToString (string Cadena="Fila", int empiezaen=1) const;


/***************************************************************************/
// Métodos de consulta de las dimensiones de la matriz.
    int NumFilas () const;
    int NumColumnas () const;

/***************************************************************************/
// Consultar el estado vacía/ocupada.
// Devuelve true si la matriz está vacía.
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
// Comparación.
// Devuelve true si las matrices una y otra son exactamente iguales.
// Tanto en dimensiones como contenidos.
    bool EsIgualA (const Matriz2D & otra) const;


/***************************************************************************/
/*
Sub
Extrae una submatriz de original y la deja en resultado.
La submatriz resultado es una zona rectangular de
original que empieza en la casilla (fila_inic, col_inic) y que
tiene (un máximo de) num_filas filas y num_cols columnas.

La función construirá y “rellenará” una matriz vacía. Lo mismo ocurre
si la casilla inicial fuera, por ejemplo, la casilla 2 (fila), -2 (columna).
*/
// PRE: 0 < fila_inic <= fils y 0 < col_inic <= cols
    Matriz2D SubMatriz (int fila_inic, int col_inic,
                        int num_filas, int num_cols);

/****************************************************************************/
// Método para añadir una fila. La fila nueva (una dato Secuencia) debe tener el
// mismo número de casillas que columnas tenga la matriz

    void Aniade (const Secuencia & fila_nueva);

/****************************************************************************/
// Método para insertar una fila en una posición dada. La fila nueva (una dato
//Secuencia) debe tener el mismo número de casillas que columnas tenga la
//matriz. La posición indicada será la posición que tendrá la fila después de la
//inserción.
//PRE: 0 < indice <= fils
    void Inserta (int indice, const Secuencia & fila_nueva);

/***************************************************************************/
//Eliminar fila. Elimina la fila num_fila de la matriz matriz.
//PRE: 0 < num_fila <= fils
    void EliminaFila (int num_fila);

//Eliminar columna. Elimina la columna num_col de la matriz matriz.
// PRE: 0 < num_col <= cols
    void EliminaColumna (int num_col);


/***************************************************************************/
// Espejo horizontal.
// Cambia de orden las filas de matriz (la primera pasa a ser la última y
// la última la primera, la segunda la penúltima y la penúltima la segunda etc)
    void EspejoHorizontal ();

//Espejo vertical. Cambia de orden las columnas de matriz (la primera
//pasa a ser la última y la última la primera, la segunda la penúltima y la
//penúltima la segunda, etc.).
    void EspejoVertical ();

private:

/***************************************************************************/
/*---------------------------MÉTODOS PRIVADOS------------------------------*/
/***************************************************************************/
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

    void ReservaMemoria (int nfils, int ncols);

/***************************************************************************/
// Libera la memoria ocupada por una matriz dinámica. 
// Parámetros: 
//		matriz (referencia), la matriz que va a "liberarse". 
// POST: La matriz queda vacía (todos sus campos a cero)

    void LiberaMemoria ();

/***************************************************************************/
// Copia profunda. Hace una copia profunda de origen en destino.
    void CopiarDatos(const Matriz2D & otra);

/***************************************************************************/
// Método para acceder a un elemento de la matriz, dadas sus coordenadas (índi-
// ces). El método puede actuar como lvalue ó rvalue.
// Parámetros: matriz (referencia), la matriz. 
//			   num_fila, número de fila.
//			   num_columna, número de columna.
// PRE: 0<=num_fila<NumFilas(m)
// PRE: 0<=num_columna<NumColumnas(m)
// Permite procesar la matriz como un array. (matriz tipo 2)

    TipoBase & Valor (const int num_fila = 0, const int num_columna = 0) const;
};
#endif