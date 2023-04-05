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
// Fichero con la definición de las funciones asociadas el tipo Matriz2D
//
// Matriz2D: Matriz 2D dinamica de datos int en la que cada 
// fila es un vector dinamico independiente. 
//
// Tipo básico descrito en el video dedicado a la implementación de Matriz2D
//
// Declaraciones en: Matriz2D.h
//
// Fichero: Matriz2D.cpp
//
/***************************************************************************/
/***************************************************************************/

#include "Matriz2D.h"

#include <string>
#include <cstring>
#include <iostream>
using namespace std; 

/***************************************************************************/
/***************************************************************************/
// FUNCION PRIVADA
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

Matriz2D ReservaMemoria (int nfils, int ncols)
{
	Matriz2D matriz; 

	// Por defecto, matriz vacía
	matriz.datos = 0;
	matriz.fils  = 0;
	matriz.cols  = 0;

	// Solo si se cumplen las precondiciones se reserva memoria 
	if (nfils>0 && ncols>0)
	{
		// Actualizo los campos de la matriz
		matriz.fils = nfils;
		matriz.cols = ncols;

		// "matriz" apuntará a un vector de punteros a cada filas
		matriz.datos = new int * [nfils];

		// El primer elemento de matriz.datos apuntará al inicio de la "super-fila"
		// Esta será una super-fila de nfilas*ncols TipoBases (en este caso int)
		matriz.datos[0] = new TipoBase [nfils*ncols];

		// Asigno a cada fila su posición de inicio
		// (numero de la fila * numero de columnas)
		for (int f=1; f<nfils; f++)
		{
			matriz.datos[f] = &matriz.datos[0][f*ncols];
		}
	}

	return (matriz);
}

/***************************************************************************/
/***************************************************************************/
// FUNCION PRIVADA
// Libera la memoria ocupada por una matriz dinámica. 
// Parámetros: 
//		matriz (referencia), la matriz que va a "liberarse". 
// POST: La matriz queda vacía (todos sus campos a cero)

void LiberaMemoria (Matriz2D & matriz)
{
	if (matriz.datos)
	{
		// Libero la "super-fila"
		delete [] matriz.datos[0];

 		// Liberar el vector de punteros
 		delete [] matriz.datos; 
   
		// La matriz debe quedar "vacía" --> la referencia "matriz" pone a 0 
		// el puntero que da acceso al vector de punteros a filas
		matriz.datos = nullptr;
		matriz.fils  = 0;
		matriz.cols  = 0;
	}
}

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

Matriz2D CreaMatriz (int nfils, int ncols, TipoBase valor)
{
	// Pedir memoria para los datos
	Matriz2D matriz = ReservaMemoria (nfils, ncols); 
	
	//.........................................................................
	// Inicializo las casillas de la matriz
	Ecualiza (matriz, valor);

	return (matriz); 
}

/***************************************************************************/
/***************************************************************************/
// "Destruye" una matriz dinámica y la deja en un estado no útil (vacía). 
// Parámetros: 
//		matriz (referencia), la matriz que va a "destruirse". 
// POST: La matriz queda vacía (todos sus campos a cero)

void DestruyeMatriz (Matriz2D & matriz)
{
	// Libero la memoria reservada para los datos
	LiberaMemoria (matriz);
}

/***************************************************************************/
/***************************************************************************/
// Devuelve un string con el resultado de "serializar" una matriz.
// Parámetros: matriz (referencia), la matriz que va a serializarse. 

string ToString (const Matriz2D & matriz)
{
	string cad;

	string delimitador = "..................................";

	cad = "\n" + delimitador + "\n";
	cad += "Filas = " + to_string(matriz.fils) + 
	      ", Columnas = " + to_string (matriz.cols) + "\n\n";
	
	for (int f=0; f<matriz.fils; f++) {
		cad += "Fila " + to_string(f) + " --> ";
		
		for (int c=0; c<matriz.cols; c++) 
			cad += to_string(matriz.datos[f][c]) + "  ";
		cad += "\n";
	}

	cad += delimitador + "\n\n";

	return (cad);
}

/***************************************************************************/
/***************************************************************************/


/***************************************************************************/
/***************************************************************************/
// Devuelve el número de filas/columnas de la matriz.
// Parámetros: matriz (referencia), la matriz que se va a consultar. 

int NumFilas (const Matriz2D & matriz)
{
	return (matriz.fils);
}

/***************************************************************************/
/***************************************************************************/

int NumColumnas (const Matriz2D & matriz)
{
	return (matriz.cols);
}

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

TipoBase & Valor (const Matriz2D & matriz, int num_fila, int num_columna)
{
	return (matriz.datos[num_fila][num_columna]);
}	

/***************************************************************************/
/***************************************************************************/
// Consultar el estado vacía/ocupada.
// Devuelve true si la matriz está vacía.
bool EstaVacia (const Matriz2D & matriz)
{
	return (matriz.datos == 0);
}

/***************************************************************************/
/***************************************************************************/
// Descarta todos los valores de la matriz. 
// Deja la matriz en estado “vacía”.
// La matriz sigue “activa”.
// Use esta función si tiene previsto seguir usando la matriz.
void EliminaTodos (Matriz2D & matriz)
{
	// Si la matriz no está vacía
	if (!EstaVacia(matriz))
	{
		matriz.datos = nullptr;
		matriz.fils = 0;
		matriz.cols = 0;
	}
}

/***************************************************************************/
/***************************************************************************/
// Ecualizar. Cambia todos los todos valores de la matriz por valor.
void Ecualiza (Matriz2D & matriz, TipoBase valor)
{
	// Solo si los argumentos son validos
	if (matriz.cols>0 && matriz.fils>0)
	{
		int ndatos = matriz.fils*matriz.cols;

		// Si valor es 0, uso memset para inicializar dado que es mejor.
		if (!valor)
		{
			memset(matriz.datos[0], 0, (ndatos) * sizeof(TipoBase));
		}
		else
		{
			// Dado que estamos en matriz 1D uso un solo bucle.
			// Lo he hecho por "lucimiento", pero realmente es mejor
			// dos bucles ya que aplica tanto a matrices de tipo uno como dos
			for (int i = 0; i < ndatos; i++) {matriz.datos[0][i] = valor;}
		}
	}
}

/***************************************************************************/
/***************************************************************************/
// Copia profunda. Hace una copia profunda de origen en destino.
void Clona (Matriz2D & destino, const Matriz2D & origen)
{
	// Limpio la matriz destino (me da igual lo que hubiese)
	LiberaMemoria(destino);

	// Creo una matriz nueva con las mismas dimensiones que la matriz origen
	destino = CreaMatriz(origen.fils, origen.cols);

	// Copio los datos de la matriz origen en la matriz destino
	memcpy(destino.datos[0], origen.datos[0],
			(origen.fils*origen.cols)*sizeof(TipoBase));
}

/***************************************************************************/
/***************************************************************************/
// Comparación.
// Devuelve true si las matrices una y otra son exactamente iguales.
// Tanto en dimensiones como contenidos.
bool SonIguales (const Matriz2D & una, const Matriz2D & otra)
{
	bool lo_son = true;

	// Si las matrices no tienen las mismas dimensiones, no son iguales
	if (una.fils != otra.fils || una.cols != otra.cols)
	{
		lo_son = false;
	}

	// Si las matrices tienen las mismas dimensiones, comparo los datos
	// Comparo los datos, si no da 0, son distintas.
	else if(memcmp(una.datos[0], otra.datos[0],
		(una.fils*una.cols) * sizeof(TipoBase)))
	{
		lo_son = false;
	}
	
	return (lo_son);
}

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
int fila_inic, int col_inic, int num_filas, int num_cols)
{
	//.........................................................................
	// Compruebo que el número de fil/col de resultado
	// son iguales o mayores a las que quiero extraer
	if (fila_inic > original.fils || col_inic > original.cols)
	{
		exit(1);
	}
	
	//.........................................................................
	// Si el número de filas o columnas solicitadas es excesivo, se adapta
	if (num_filas > original.fils - fila_inic)
	{
		num_filas = (original.fils - fila_inic)+1;
	}
	
	if (num_cols > original.cols - col_inic)
	{
		num_cols = (original.cols -fila_inic)+1;
	}

	// Dado el (posible) nuevo Nº de cols/fils, recreo la matriz resultado
	//(También lo hago por si el usuario no reservase suficiente espacio)
	LiberaMemoria(resultado);
	resultado = CreaMatriz(num_filas, num_cols);

	//.........................................................................
	// Extraigo la submatriz y la pego
	// Para ello voy fila por fila (desde fila_inic)
	// copiando num_cols a partir de col_inic en la fila i de matriz resultado

	for (int i = 0; i < num_filas; i++)
	{
		memcpy (resultado.datos[i],
				&original.datos[(fila_inic-1)+i][col_inic-1],
				sizeof(TipoBase)*num_cols);
	}
}

/***************************************************************************/
/***************************************************************************/
//Eliminar fila/Columuna. Elimina la fila/columna solicitada
void EliminaFila (Matriz2D & matriz, int num_fila)
{
	// Uso la función "memmove" para sobreescribir sobre el fragmento a borrar
	memmove(matriz.datos[num_fila-1], matriz.datos[num_fila],
			matriz.cols*(matriz.fils-(num_fila))*sizeof(TipoBase));

	// Debido a que voy a liberar la memoria de matriz, almaceno los nfils/cols
	int nuevo_nfils = matriz.fils - 1;
	int nuevo_ncols = matriz.cols;

	// Copio la matriz en un vector temporal
	TipoBase * v_tmp = new TipoBase [nuevo_nfils*nuevo_ncols];
	memcpy(v_tmp, matriz.datos[0], nuevo_nfils*nuevo_ncols*sizeof(TipoBase));

	// Rehago matriz con el tamaño adecuado
	LiberaMemoria(matriz);
	matriz = CreaMatriz(nuevo_nfils, nuevo_ncols);

	// Copio el contenido de tmp a matriz y libero tmp
	memcpy(matriz.datos[0], v_tmp, nuevo_nfils*nuevo_ncols*sizeof(TipoBase));
	delete [] v_tmp;
}

//.............................................................................
void EliminaColumna (Matriz2D & matriz, int num_col)
{
	// Debido a que voy a liberar la memoria de matriz, almaceno los nfils/cols
	int nuevo_nfils = matriz.fils;
	int nuevo_ncols = matriz.cols - 1;

	// Copio la matriz en un vector temporal
	TipoBase * v_tmp = new TipoBase [nuevo_nfils*nuevo_ncols];

/*	Tras un rato pensando he concluido que el método más eficiente
	(con menor número de llamadas a memcpy/memmove...) para
	hacer el traspaso de datos a tmp es el siguiente:

	Imagínese que quiero borrar la tercera columna de una matriz 5x4
	He marcado con un * los componentes del a tercera columna (a omitir)

	matriz.datos = | 1 2 3* 4 | 5 6 7* 8 | 9 1 2* 3 | 4 5 6* 7 | 8 9 1* 2 |
					 ---    -------    -------    -------    -------   ---
					 INI	  B1          B2         B3         B4     FIN

	Observe que para copiar el contenido de matriz.datos sin la tercera columna
	lo que debemos hacer es copiar:
	1. El fragmento inicial (INI) de tamaño n_cols-(n_cols-col_a_eliminar)
	2. n-1 Bloques (Bn) (fíjese como hay 5 filas y 4 bloques) de tamaño n_cols-1
	3. El fragmento final (FIN) de tamaño n_cols-col_a_eliminar

*/
	// Pego el fragmento inicial en v_tmp:
	memcpy(v_tmp, matriz.datos[0],
		(matriz.cols-(matriz.cols-(num_col-1)))*sizeof(TipoBase));
	// Inicializo un contador que me indica por dónde voy en v_tmp
	int contador = (matriz.cols-(matriz.cols-(num_col-1)));

	// Pego nfils-1 bloques intermedios en v_tmp
	for (int i = 0; i < matriz.fils - 1; i++)
	{
		memcpy(&v_tmp[contador], &matriz.datos[i][num_col],
		(matriz.cols-1)*sizeof(TipoBase));
		contador += matriz.cols-1;
	}

	// Pego el fragmento final en v_tmp:
	memcpy(&v_tmp[contador], &matriz.datos[matriz.fils-1][num_col],
			(matriz.cols-num_col)*sizeof(TipoBase));

	// Rehago matriz con el tamaño adecuado
	LiberaMemoria(matriz);
	matriz = ReservaMemoria(nuevo_nfils, nuevo_ncols);
	
	// Copio el contenido de tmp a matriz y libero tmp
	memcpy(matriz.datos[0], v_tmp, nuevo_nfils*nuevo_ncols*sizeof(TipoBase));
	delete [] v_tmp;
}

/***************************************************************************/
/***************************************************************************/
// Espejo horizontal.
// Cambia de orden las filas de matriz (la primera pasa a ser la última y
// la última la primera, la segunda la penúltima y la penúltima la segunda etc)
void EspejoHorizontal (Matriz2D & matriz)
{
	TipoBase * fila_tmp = new TipoBase [matriz.cols];

	for (int i = 0; i < matriz.fils/2; i++)
	{
		// Guardo la fila i en fila_tmp
		memcpy(fila_tmp, matriz.datos[i], matriz.cols*sizeof(TipoBase));
		// Copio la fila nfils-i en la fila i
		memcpy(matriz.datos[i], matriz.datos[(matriz.fils-1)-i], matriz.cols*sizeof(TipoBase));
		// Copio la fila i (fila_tmp) en la fila nfils-i
		memcpy(matriz.datos[(matriz.fils-1)-i], fila_tmp, matriz.cols*sizeof(TipoBase));
	}

	delete [] fila_tmp;
}

//Espejo vertical. Cambia de orden las columnas de matriz (la primera
//pasa a ser la última y la última la primera, la segunda la penúltima y la
//penúltima la segunda, etc.).

void EspejoVertical (Matriz2D & matriz)
{
	for (int i = 0; i < matriz.fils; i++)
	{
		// Invierto los elementos (columnas) de la fila i 
		for (int j = 0; j < matriz.cols/2; j++)
		{
			TipoBase tmp;
			tmp = matriz.datos[i][j];
			matriz.datos[i][j] = matriz.datos[i][(matriz.cols-1)-j];
			matriz.datos[i][(matriz.cols-1)-j] = tmp;
		}
	} // Itero por las filas de la matriz
}

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
