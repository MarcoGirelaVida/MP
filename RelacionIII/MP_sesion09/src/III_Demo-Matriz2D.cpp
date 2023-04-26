/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// AUTOR: MARCO GIRELA VIDA
// GRUPO: 1ºB
// FECHA: xx/04/2023
//
// RELACION DE PROBLEMAS 3
//
// Pruebas sobre el tipo Matriz2D
//
// Matriz2D: Matriz 2D dinamica de datos "TipoBase" en la que cada 
//           fila es un vector dinamico independiente.
//
// Declaraciones en: Matriz2D.h
//
// Fichero: III_Demo-Matriz2D.cpp
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>

#include "Matriz2D.h"

using namespace std; 

/***************************************************************************/
/***************************************************************************/

int main (void)
{
	// Lectura de las dimensiones de la matriz

	int num_filas, num_cols; 

	do  {
		cout << endl;
		cout << "Introduzca num. filas de la matriz: ";
		cin >> num_filas; 
	} while (num_filas <= 0);	

	do  {
		cout << endl;
		cout << "Introduzca num. columnas de la matriz: ";
		cin >> num_cols; 
	} while (num_cols <= 0);	

	cout << endl << endl;

	// .....................................................................
	// Creación de una matriz y rellenar sus casillas  
	Matriz2D m(num_filas, num_cols);

	for (int f=0; f<m.NumFilas(); f++) 
		for (int c=0; c<m.NumColumnas(); c++) 
			m.Valor(f,c) = ((10*(f+1))+c+1);

	cout << "Matriz rellena: ";
	cout << m.ToString();






	// .....................................................................
	// Creación de una matriz (todas las casillas a cero) y mostrala 

	Matriz2D m0(num_filas, num_cols, 0);

	cout << "Matriz con todos 0: ";
	cout << m0.ToString();

	// .....................................................................
	// Creación de una matriz (todas las casillas a 9) y mostrala 

	Matriz2D m9(num_filas, num_cols, 9);

	cout << "Matriz con todos 9: ";
	cout << m9.ToString();

	// .....................................................................
	// Creación de una matriz vacia (0x0, todas las casillas a 0) y mostrala 

	Matriz2D m_vacia;

	cout << "Matriz vacia: ";
	cout << m_vacia.ToString();

	// .....................................................................
	// Compruebo si está vacía

	cout << "¿Está vacía?: ";
	cout << m_vacia.EstaVacia() << endl << endl;

	// .....................................................................
	// Creación de una matriz 5x8  
	Matriz2D mbase(5, 8);

	for (int f=0; f<mbase.NumFilas(); f++) 
		for (int c=0; c<mbase.NumColumnas(); c++) 
			mbase.Valor(f,c) = ((10*(f+1))+c+1);
		
	cout << "Matriz base de 5x8: ";
	cout << mbase.ToString ();



	//......................................................................
	// Intento crear una submatriz de 4x3 hecha con las filas 3 col 5 
	// de una matriz 5x8. Dado que no es posible, deberá devolver una de 3x3

	// Inicializo la matriz a un valor menor del que he pedido en Submatriz
	Matriz2D submatriz(2,2);

	submatriz.SubMatriz(3, 5, 4, 3);

	cout << "Submatriz inicializada a 2x2 solicitada a 4x3 y \
que debe devolver una de 3x3: ";
	cout << submatriz.ToString ();

	//......................................................................
	// Elimino la cuarta fila de mbase
	mbase.EliminaFila(4);

	cout << "Matriz base sin la fila 4: ";
	cout << mbase.ToString ();

	//......................................................................
	// Elimino la cuarta columna de mbase
	mbase.EliminaColumna(4);

	cout << "Matriz base sin la columna 4: ";
	cout << mbase.ToString ();

	//......................................................................
	// Espejo verticalmente la matrizbase
	mbase.EspejoVertical();

	cout << "Matriz base reflejada verticalmente: ";
	cout << mbase.ToString ();

	//......................................................................
	// Espejo horizontalmente matrizbase
	mbase.EspejoHorizontal();

	cout << "Matriz base reflejada horizontalmente: ";
	cout << mbase.ToString ();

	//......................................................................	
	// Crear una secuencia para añadir como fila
    Secuencia secuencia(mbase.NumColumnas());
    
	for (int i = 0; i < mbase.NumColumnas(); i++)
		secuencia.Aniade(i*2);
	
	//......................................................................
    // Prueba del método Aniade
    mbase.Aniade(secuencia);

	cout << "Matriz base con fila añadida: ";
	cout << mbase.ToString ();

	//......................................................................
    // Prueba del método Inserta
    mbase.Inserta(1, secuencia);
	cout << "Matriz base con fila insertada en la fila 1: ";
	cout << mbase.ToString ();

	//......................................................................
	// Clon de matriz base
	Matriz2D matrizclonada = mbase;

	cout << "Clon de matriz base (operador asignación): ";
	cout << matrizclonada.ToString ();

	//......................................................................
	// Compruebo si el clon y el original son iguales

	cout << "¿Es el clon igual a su madre?: ";
	cout << matrizclonada.EsIgualA(mbase) << endl << endl;

	//......................................................................
	// Matriz con todos eliminados
	mbase.EliminaTodos();
	cout << "Matriz base con todos eliminados: ";
	cout << mbase.ToString ();

	return 0; 
}

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
