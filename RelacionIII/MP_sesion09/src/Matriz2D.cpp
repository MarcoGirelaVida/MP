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

#include <cstring>
#include <iostream>
using namespace std; 


/***************************************************************************/
/*---------------------------CONSTRUCTORES/DESTRUCTOR----------------------*/
/***************************************************************************/
// Constructor sin argumentos, que crea una matriz vacía.
Matriz2D :: Matriz2D(void) : datos(nullptr), fils(0), cols(0)
{}

/***************************************************************************/
// Constructor con 1 argumento: Crea una matriz cuadrada con el número de filas
// y columnas indicado en el argumento.

Matriz2D :: Matriz2D(int n)
				: datos(nullptr), fils(0), cols(0)
{
	// Pedir memoria para los datos
	ReservaMemoria (n, n);
}

/***************************************************************************/
// Constructor con 2 argumentos
// Parámetros:
//		nfils, número de filas de la matriz (por defecto 0).
//		ncols, número de columnas de la matriz (por defecto 0).
// PRE: nfils >= 0 && ncols >= 0

Matriz2D :: Matriz2D(int nfils, int ncols)
				: datos(nullptr), fils(0), cols(0)
{
	// Pedir memoria para los datos
	ReservaMemoria (nfils, ncols);
}

/***************************************************************************/
// Constructor con 3 argumentos
// El contenido de las "fils"x"cols" casillas se ecualiza a "valor"
// Parámetros:
//		nfils, número de filas de la matriz (por defecto 0).
//		ncols, número de columnas de la matriz (por defecto 0).
//		valor, valor común que se copiará en las casillas (por defecto 0). 
// PRE: nfils >= 0 && ncols >= 0 

Matriz2D :: Matriz2D(int nfils, int ncols, TipoBase valor)
				 : datos(nullptr), fils(0), cols(0)
{
	// Pedir memoria para los datos
	ReservaMemoria (nfils, ncols); 
	
	//.........................................................................
	// Inicializo las casillas de la matriz
	Ecualiza (valor); 
}

/***************************************************************************/
// Constructor de copia

Matriz2D :: Matriz2D(Matriz2D &otra)
				: datos(nullptr), fils(0), cols(0)
{
	CopiarDatos(otra);
}

/***************************************************************************/
// Destructor de la clase Matriz2D

Matriz2D :: ~Matriz2D (void)
{
	// Libero la memoria reservada para los datos
	LiberaMemoria ();
}

/***************************************************************************/
/*-----------------------------MÉTODOS PÚBLICOS------------------------*/
/***************************************************************************/
// Sobrecarga del operador de asignación
Matriz2D & Matriz2D :: operator = (const Matriz2D & otro)
{
	// Si la matriz destino es distinta de la matriz origen
	if (this != &otro)
	{
		CopiarDatos (otro);
	}

	return *this;
}


/***************************************************************************/
// Devuelve un string con el resultado de "serializar" una 
// Parámetros: matriz (referencia), la matriz que va a serializarse. 

string Matriz2D :: ToString (string Cadena, int empiezaen) const
{
	string cad;

	string delimitador = "..................................";

	cad = "\n" + delimitador + "\n";

	cad += "Filas = " + to_string(fils) + 
	      ", Columnas = " + to_string (cols) + "\n\n";
	
	for (int f=0; f<fils; f++)
	{
		cad += Cadena + " " + to_string(empiezaen+f) + " --> ";
		
		for (int c=0; c<cols; c++) 
			cad += to_string(datos[f][c]) + "  ";
		cad += "\n";
	}

	cad += delimitador + "\n\n";

	return (cad);
}

/***************************************************************************/
// Devuelve el número de filas/columnas de la 
// Parámetros: matriz (referencia), la matriz que se va a consultar. 

int Matriz2D :: NumFilas () const
{
	return (fils);
}

int Matriz2D :: NumColumnas () const
{
	return (cols);
}


/***************************************************************************/
// Método para acceder a un elemento de la matriz, dadas sus coordenadas (índi-
// ces). El método puede actuar como lvalue ó rvalue.
// Parámetros: matriz (referencia), la matriz. 
//			   num_fila, número de fila.
//			   num_columna, número de columna.
// PRE: 0<=num_fila<NumFilas(m)
// PRE: 0<=num_columna<NumColumnas(m)
// Permite procesar la matriz como un array (matriz tipo 2)

TipoBase & Matriz2D :: Valor (const int num_fila, const int num_columna)
{
	// El primer if es para que se pueda procesar la matriz como tipo dos
	if (num_fila!=0)
	{
		if (num_fila < 0 || num_fila >= fils || 
		num_columna < 0 || num_columna >= cols)
		{
			cerr << "Error: Acceso a una posición no válida de la matriz" << endl;
			exit(1);
		}
	}
	
	return (datos[num_fila][num_columna]);
}	

TipoBase & Matriz2D :: Valor (const int num_fila, const int num_columna) const
{
	// El primer if es para que se pueda procesar la matriz como tipo dos
	if (num_fila!=0)
	{
		if (num_fila < 0 || num_fila >= fils || 
		num_columna < 0 || num_columna >= cols)
		{
			cerr << "Error: Acceso a una posición no válida de la matriz" << endl;
			exit(1);
		}
	}
	
	return (datos[num_fila][num_columna]);
}

/***************************************************************************/
// Consultar el estado vacía/ocupada.
// Devuelve true si la matriz está vacía.
bool Matriz2D :: EstaVacia () const
{
	return (datos == nullptr);
}


/***************************************************************************/
// Descarta todos los valores de la  
// Deja la matriz en estado “vacía”.
// La matriz sigue “activa”.
// Use esta función si tiene previsto seguir usando la 
void Matriz2D :: EliminaTodos ()
{
	// Si la matriz no está vacía
	if (!EstaVacia())
	{	
		// Libero la memoria reservada para los datos
		LiberaMemoria ();
		datos = nullptr;
		fils = 0;
		cols = 0;
	}
}


/***************************************************************************/
// Ecualizar. Cambia todos los todos valores de la matriz por valor.
void Matriz2D :: Ecualiza (TipoBase valor)
{
	// Solo si los argumentos son validos
	if (cols>0 && fils>0)
	{
		int ndatos = fils*cols;

		// Si valor es 0, uso memset para inicializar dado que es mejor.
		if (!valor)
		{
			memset(datos[0], 0, (ndatos) * sizeof(TipoBase));
		}
		else
		{
			// Dado que estamos en matriz 1D uso un solo bucle.
			// Lo he hecho por "lucimiento", pero realmente es mejor
			// dos bucles ya que aplica tanto a matrices de tipo uno como dos
			for (int i = 0; i < ndatos; i++)
				datos[0][i] = valor;
		}
	}
}


/***************************************************************************/
// Copia profunda. Hace una copia profunda de origen en destino.
void Matriz2D :: CopiarDatos (const Matriz2D & otra)
{
	// Limpio la matriz destino (me da igual lo que hubiese)
	LiberaMemoria();

	// Reservo memoria para la matriz destino
	ReservaMemoria(otra.NumFilas(), otra.NumColumnas());

	// Copio los datos de la matriz origen en la matriz destino
	memcpy(datos[0], &otra.Valor(0,0), (otra.NumFilas()*cols)*sizeof(TipoBase));
}


/***************************************************************************/
// Comparación.
// Devuelve true si las matrices una y otra son exactamente iguales.
// Tanto en dimensiones como contenidos.
bool Matriz2D :: EsIgualA (const Matriz2D & otra) const
{
	bool lo_son = true;

	// Si las matrices no tienen las mismas dimensiones, no son iguales
	if (fils != otra.NumFilas() || cols != otra.NumColumnas() )
	{
		lo_son = false;
	}

	// Si las matrices tienen las mismas dimensiones, comparo los datos
	// Comparo los datos, si no da 0, son distintas.
	int i = 0;
	while (i<fils*cols && lo_son)
	{
		if (datos[0][i] != otra.Valor(0,i))
		{
			lo_son = false;
		}
		i++;
	}
	
	return (lo_son);
}


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
Matriz2D Matriz2D :: SubMatriz (int fila_inic, int col_inic,\
								 int num_filas, int num_cols)
{

	//.........................................................................
	// Si el número de filas o columnas solicitadas es excesivo, se adapta
	if (num_filas > fils - fila_inic)
	{
		num_filas = (fils - fila_inic)+1;
	}
	
	if (num_cols > cols - col_inic)
	{
		num_cols = (cols -fila_inic)+1;
	}

	// Declaro la nueva matriz
	Matriz2D resultado(num_filas, num_cols);

	//.........................................................................
	// Extraigo la submatriz y la pego
	// Para ello voy fila por fila (desde fila_inic)
	// copiando num_cols a partir de col_inic en la fila i de matriz resultado

	for (int i = 0; i < num_filas; i++)
	{
		memcpy (&resultado.Valor(i),
				&datos[(fila_inic-1)+i][col_inic-1],
				sizeof(TipoBase)*num_cols);
	}

	return resultado;
}

/****************************************************************************/
// Método para añadir una fila. La fila nueva (una dato Secuencia) debe tener el
// mismo número de casillas que columnas tenga la matriz

void Matriz2D :: Aniade (const Secuencia & fila_nueva)
{
	// Compruebo que la fila a añadir tiene el mismo número de columnas
	if (fila_nueva.TotalUtilizados() != cols)
	{
		cerr << "Error: La fila a añadir no tiene el mismo número de columnas\
 que la matriz" << endl;
		 exit(1);
	}

	// Guardo los datos de la matriz original en un vector dinámico
	TipoBase * tmp = new TipoBase[fils*cols];
	memcpy(tmp, datos[0], fils*cols*sizeof(TipoBase));

	// Reservo memoria para la nueva matriz
	ReservaMemoria(fils+1, cols);

	// Copio los datos de tmp a la original y le añado la nueva fila
	memcpy(datos[0], tmp, fils*cols*sizeof(TipoBase));
	delete [] tmp;
	memcpy(datos[fils-1], &fila_nueva.Valor(0), cols*sizeof(TipoBase));
}

/****************************************************************************/
// Método para insertar una fila en una posición dada. La fila nueva (una dato
//Secuencia) debe tener el mismo número de casillas que columnas tenga la
//matriz. La posición indicada será la posición que tendrá la fila después de la
//inserción.
void Matriz2D :: Inserta (int indice, const Secuencia & fila_nueva)
{
	// Compruebo que la fila a añadir tiene el mismo número de columnas
	if (fila_nueva.TotalUtilizados() != cols)
	{
		cerr << "Error: La fila a añadir no tiene el mismo número de columnas\
		 que la matriz" << endl;
		 exit(1);
	}
	
	// Guardo los datos de la matriz original en un vector dinámico
	TipoBase *tmp = new TipoBase[fils*cols];
	memcpy(tmp, datos[0], fils*cols*sizeof(TipoBase));

	// Reservo memoria para la nueva matriz
	ReservaMemoria(fils+1, cols);

	// Copio el primer fragmento en la matriz original
	memcpy(datos[0], &tmp[(indice-1)*cols], (indice-1)*cols*sizeof(TipoBase));
	memcpy(datos[indice-1], &fila_nueva.Valor(0), cols*sizeof(TipoBase));
	memcpy(datos[indice], &tmp[(indice-1)*cols],\
										(fils-indice)*cols*sizeof(TipoBase));
	delete [] tmp;

}

/***************************************************************************/
/***************************************************************************/
//Eliminar fila/Columuna. Elimina la fila/columna solicitada
void Matriz2D :: EliminaFila (int num_fila)
{
	// Uso la función "memmove" para sobreescribir sobre el fragmento a borrar
	memmove(datos[num_fila-1], datos[num_fila],
			cols*(fils-(num_fila))*sizeof(TipoBase));

	// Debido a que voy a liberar la memoria de matriz, almaceno los nfils/cols
	int nuevo_nfils = fils - 1;
	int nuevo_ncols = cols;

	// Copio la matriz en un vector temporal
	TipoBase * v_tmp = new TipoBase [nuevo_nfils*nuevo_ncols];
	memcpy(v_tmp, datos[0], nuevo_nfils*nuevo_ncols*sizeof(TipoBase));

	// Rehago matriz con el tamaño adecuado
	LiberaMemoria();
	ReservaMemoria(nuevo_nfils, nuevo_ncols);

	// Copio el contenido de tmp a matriz y libero tmp
	memcpy(datos[0], v_tmp, nuevo_nfils*nuevo_ncols*sizeof(TipoBase));
	delete [] v_tmp;
}

//.............................................................................
void Matriz2D :: EliminaColumna (int num_col)
{
	// Debido a que voy a liberar la memoria de matriz, almaceno los nfils/cols
	int nuevo_nfils = fils;
	int nuevo_ncols = cols - 1;

	// Copio la matriz en un vector temporal
	TipoBase * v_tmp = new TipoBase [nuevo_nfils*nuevo_ncols];

/*	Tras un rato pensando he concluido que el método más eficiente
	(con menor número de llamadas a memcpy/memmove...) para
	hacer el traspaso de datos a tmp es el siguiente:

	Imagínese que quiero borrar la tercera columna de una matriz 5x4
	He marcado con un * los componentes del a tercera columna (a omitir)

	datos = | 1 2 3* 4 | 5 6 7* 8 | 9 1 2* 3 | 4 5 6* 7 | 8 9 1* 2 |
					 ---    -------    -------    -------    -------   ---
					 INI	  B1          B2         B3         B4     FIN

	Observe que para copiar el contenido de datos sin la tercera columna
	lo que debemos hacer es copiar:
	1. El fragmento inicial (INI) de tamaño n_cols-(n_cols-col_a_eliminar)
	2. n-1 Bloques (Bn) (fíjese como hay 5 filas y 4 bloques) de tamaño n_cols-1
	3. El fragmento final (FIN) de tamaño n_cols-col_a_eliminar

*/
	// Pego el fragmento inicial en v_tmp:
	memcpy(v_tmp, datos[0], (cols-(cols-(num_col-1)))*sizeof(TipoBase));

	// Inicializo un contador que me indica por dónde voy en v_tmp
	int contador = (cols-(cols-(num_col-1)));

	// Pego nfils-1 bloques intermedios en v_tmp
	for (int i = 0; i < fils - 1; i++)
	{
		memcpy(&v_tmp[contador], &datos[i][num_col],(cols-1)*sizeof(TipoBase));
		contador += cols-1;
	}

	// Pego el fragmento final en v_tmp:
	memcpy(&v_tmp[contador], &datos[fils-1][num_col],(cols-num_col)*sizeof(TipoBase));

	// Rehago matriz con el tamaño adecuado
	LiberaMemoria();
	ReservaMemoria(nuevo_nfils, nuevo_ncols);
	
	// Copio el contenido de tmp a matriz y libero tmp
	memcpy(datos[0], v_tmp, nuevo_nfils*nuevo_ncols*sizeof(TipoBase));

	delete [] v_tmp;
}

/***************************************************************************/
/***************************************************************************/
// Espejo horizontal.
// Cambia de orden las filas de matriz (la primera pasa a ser la última y
// la última la primera, la segunda la penúltima y la penúltima la segunda etc)
void Matriz2D :: EspejoHorizontal ()
{
	TipoBase * fila_tmp = new TipoBase [cols];

	for (int i = 0; i < fils/2; i++)
	{
		// Guardo la fila i en fila_tmp
		memcpy(fila_tmp, datos[i], cols*sizeof(TipoBase));

		// Copio la fila nfils-i en la fila i
		memcpy(datos[i], datos[(fils-1)-i], cols*sizeof(TipoBase));

		// Copio la fila i (fila_tmp) en la fila nfils-i
		memcpy(datos[(fils-1)-i], fila_tmp, cols*sizeof(TipoBase));
	}

	delete [] fila_tmp;
}

//Espejo vertical. Cambia de orden las columnas de matriz (la primera
//pasa a ser la última y la última la primera, la segunda la penúltima y la
//penúltima la segunda, etc.).

void Matriz2D :: EspejoVertical ()
{
	for (int i = 0; i < fils; i++)
	{
		// Invierto los elementos (columnas) de la fila i 
		for (int j = 0; j < cols/2; j++)
		{
			TipoBase tmp;
			tmp = datos[i][j];
			datos[i][j] = datos[i][(cols-1)-j];
			datos[i][(cols-1)-j] = tmp;
		}
	} // Itero por las filas de la matriz
}

/***************************************************************************/
/*---------------------------MÉTODOS PRIVADOS------------------------------*/
/***************************************************************************/
// Reserva memoria para los datos de una matriz dinámica con "nfils" filas 
// y "ncols" columnas. 
// El contenido de las "nfils"x"ncols" casillas queda INDEFINIDO.
// Parámetros:
//		nfils, número de filas de la 
//		ncols, número de columnas de la  
// Devuelve: un dato Matriz2D con memoria reservada.
// 		El contenido de las "fils"x"cols" casillas queda indefinido. 
//
// PRE: nfils >= 0 && ncols >= 0
// NOTA: Tanto "nfils" como "nols" deben ser estrictamente positivos para poder 
// 		 disponer de una matriz no vacía. Si alguno de los dos valores fuera 0  
//		 no se reserva memoria, y la matriz queda vacía. 

void Matriz2D :: ReservaMemoria (int nfils, int ncols)
{

	// Por defecto, matriz vacía
	datos = nullptr;
	fils  = 0;
	cols  = 0;

	// Solo si se cumplen las precondiciones se reserva memoria 
	if (nfils>0 && ncols>0)
	{
		// Actualizo los campos de la matriz
		fils = nfils;
		cols = ncols;

		// "matriz" apuntará a un vector de punteros a cada filas
		datos = new int * [nfils];

		// El primer elemento de datos apuntará al inicio de la "super-fila"
		// Esta será una super-fila de nfilas*ncols TipoBases (en este caso int)
		datos[0] = new TipoBase [nfils*ncols];

		// Asigno a cada fila su posición de inicio
		// (numero de la fila * numero de columnas)
		for (int f=1; f<nfils; f++)
		{
			datos[f] = &datos[0][f*ncols];
		}
	}
}


/***************************************************************************/
// Libera la memoria ocupada por una matriz dinámica. 
// Parámetros: 
//		matriz (referencia), la matriz que va a "liberarse". 
// POST: La matriz queda vacía (todos sus campos a cero)

void Matriz2D :: LiberaMemoria ()
{
	if (!EstaVacia())
	{
		// Libero la "super-fila"
		delete [] datos[0];

 		// Liberar el vector de punteros
 		delete [] datos; 
   
		// La matriz debe quedar "vacía" --> la referencia "matriz" pone a 0 
		// el puntero que da acceso al vector de punteros a filas
		datos = nullptr;
		fils  = 0;
		cols  = 0;
	}
}
////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
