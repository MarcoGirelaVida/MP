/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// AUTOR: MARCO GIRELA VIDA
// GRUPO: 1ºB
// FECHA: xx/04/2023
//
// RELACION DE PROBLEMAS 2
//
// Pruebas sobre el tipo Matriz2D
//
// Matriz2D: Matriz 2D dinamica de datos "TipoBase" en la que cada 
//           fila es un vector dinamico independiente.
//
// Declaraciones en: Matriz2D.h
//
// Fichero: II_Demo-Matriz2D.cpp
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
	Matriz2D m = CreaMatriz (num_filas, num_cols);

	for (int f=0; f<m.fils; f++) 
		for (int c=0; c<m.cols; c++) 
			m.datos[f][c] = ((10*(f+1))+c+1);
		
	cout << "Matriz rellena: ";
	cout << ToString (m);

	//......................................................................
	// Destruye la matriz
	
	DestruyeMatriz (m);





	// .....................................................................
	// Creación de una matriz (todas las casillas a cero) y mostrala 

	Matriz2D m0 = CreaMatriz (num_filas, num_cols);

	cout << "Matriz con todos 0: ";
	cout << ToString (m0);

	// .....................................................................
	// Creación de una matriz (todas las casillas a 9) y mostrala 

	Matriz2D m9 = CreaMatriz (num_filas, num_cols, 9);

	cout << "Matriz con todos 9: ";
	cout << ToString (m9);

	// .....................................................................
	// Creación de una matriz vacia (0x0, todas las casillas a 0) y mostrala 

	Matriz2D m_vacia = CreaMatriz ();

	cout << "Matriz vacia: ";
	cout << ToString (m_vacia);

	// .....................................................................
	// Compruebo si está vacía

	cout << "¿Está vacía?: ";
	cout << EstaVacia(m_vacia) << endl << endl;


	// .....................................................................
	// Destruye las matrices 

	DestruyeMatriz (m0);
	DestruyeMatriz (m9);
	DestruyeMatriz (m_vacia);

	// .....................................................................
	// Creación de una matriz 5x8  
	Matriz2D mbase = CreaMatriz (5, 8);

	for (int f=0; f<mbase.fils; f++) 
		for (int c=0; c<mbase.cols; c++) 
			mbase.datos[f][c] = ((10*(f+1))+c+1);
		
	cout << "Matriz base de 5x8: ";
	cout << ToString (mbase);



	//......................................................................
	// Intento crear una submatriz de 4x3 hecha con las filas 3 col 5 
	// de una matriz 5x8. Dado que no es posible, deberá devolver una de 3x3

	// Inicializo la matriz a un valor menor del que he pedido en Submatriz
	Matriz2D submatriz = CreaMatriz(2,2);

	SubMatriz(submatriz, mbase, 3, 5, 4, 3);

	cout << "Submatriz inicializada a 2x2 solicitada a 4x3 y \
que debe devolver una de 3x3: ";
	cout << ToString (submatriz);

	//......................................................................
	// Destruye la matriz
	DestruyeMatriz (submatriz);

	//......................................................................
	// Elimino la cuarta fila de mbase
	EliminaFila(mbase, 4);

	cout << "Matriz base sin la fila 4: ";
	cout << ToString (mbase);

	//......................................................................
	// Elimino la cuarta columna de mbase
	EliminaColumna(mbase, 4);

	cout << "Matriz base sin la columna 4: ";
	cout << ToString (mbase);

	//......................................................................
	// Espejo verticalmente la matrizbase
	EspejoVertical(mbase);

	cout << "Matriz base reflejada verticalmente: ";
	cout << ToString (mbase);

	//......................................................................
	// Espejo horizontalmente matrizbase
	EspejoHorizontal(mbase);

	cout << "Matriz base reflejada horizontalmente: ";
	cout << ToString (mbase);

	//......................................................................
	// Clon de matriz base
	Matriz2D matrizclonada = CreaMatriz();
	Clona(matrizclonada, mbase);

	cout << "Clon de matriz base: ";
	cout << ToString (matrizclonada);

	//......................................................................
	// Compruebo si el clon y el original son iguales

	cout << "¿Es el clon igual a su madre?: ";
	cout << SonIguales(matrizclonada, mbase) << endl << endl;

	//......................................................................
	// Destruye la matriz
	DestruyeMatriz (submatriz);

	return 0; 
}

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
