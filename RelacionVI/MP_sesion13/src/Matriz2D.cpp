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
#include "Secuencia.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
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
// Copia los datos de la matriz "otra" en la matriz a crear
Matriz2D :: Matriz2D(const Matriz2D &otra)
				 : datos(nullptr), fils(0), cols(0)
{
	CopiarDatos(otra);
}

/***************************************************************************/
//Constructor que recibe el nombre de un fichero de texto y crea una matriz
//y la rellena con los datos contenidos en el fichero de texto nombre.
Matriz2D :: Matriz2D(const char * nombre)
				 : datos(nullptr), fils(0), cols(0)
{
	// Abro el fichero proporcionado
	ifstream fi(nombre);
	if (!fi)
	{
		cerr << "Error al abrir el fichero " << nombre << endl;
		exit(1);
	}
	
	fi >> (*this);
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
// Copia los datos de otro en la matriz implicita
Matriz2D & Matriz2D :: operator = (const Matriz2D & otro)
{
	// Si la matriz destino es distinta de la matriz origen
	if (this != &otro)
	{
		CopiarDatos (otro);
	}

	return *this;
}

Matriz2D & Matriz2D :: operator = (TipoBase valor)
{
	Ecualiza(valor);

	return *this;
}

/***************************************************************************/
/***************************************************************************/
// Sobrecarga del operador () para usarlo como rvalue o lvalue
// Parámetros: Posición del elemento (fils, cols) a consultar o modificar.
// Devuelve: referencia al dato al que se accede.
// PRE: 0<fila<=NumFilas(m) && 0<columna<=NumColumnas(m)
int& Matriz2D :: operator()(const int fila, const int columna)
{
	return Valor(fila-1, columna-1);
}
int& Matriz2D :: operator()(const int fila, const int columna) const
{
	return Valor(fila-1, columna-1);
}

/***************************************************************************/
// Sobrecarga de los operadores == y !=
// Versión 1: Compara si dos matrices son iguales/distintas
// Versión 2: Compara si una matriz es igual/distinta a un valor común
// Devuelve: bool que determina si las dimensiones y elementos de ambas matrices
// son iguales o no.
bool Matriz2D :: operator==(const Matriz2D &otra) const
{
	return EsIgualA(otra);
}	

bool Matriz2D :: operator!=(const Matriz2D &otra) const
{
	return (!(*this == otra));
}

bool Matriz2D :: operator==(const int valor) const
{
	Matriz2D MatrizValor(NumFilas(), NumColumnas(), valor);
	return (*this == MatrizValor);
}	

bool Matriz2D :: operator!=(const int valor) const
{
	return (!(*this == valor));
}

/***************************************************************************/
// Sobrecarga de los operadores unarios + y -
// Operador +: Devuelve la matriz implícita sin modificar
Matriz2D Matriz2D :: operator+ (void) const
{
	return *this;
}

// Operador -: Se invierten los valores de la matriz implítica
Matriz2D Matriz2D :: operator- (void) const
{
	return ((*this) * (-1));
}

/***************************************************************************/
// Sobrecarga de los operadores binarios + y -
// Si los dos operadores son de tipo Matriz2D sólo se hará la suma
// o la resta si las dos matrices tienen las mismas dimensiones.
// Si no fuera así, devolverá una matriz vacía.

// Operador +: Matriz2D + Matriz2D
// Devuelve una matriz con la suma de los elementos de ambas matrices
// No se modifica ninguno de los operandos ni la matriz implícita
Matriz2D operator+ (const Matriz2D m1, const Matriz2D & m2)
{
	// Inicializo la matriz resultado a m1 con el constructor copia
	Matriz2D resultado(m1);

	// Sumo los valores de cada matriz uno a uno
	for (int i = 1; i <= resultado.NumFilas(); i++)
	{
		for (int j = 1; j <= resultado.NumColumnas(); j++)
		{
			resultado(i, j) += m2(i, j);
		}
	}

	// Devuelvo resultado
	return resultado;
}

// Operador +: Matriz2D + TipoBaseMatriz2D (o viceversa)
// Devuelve una matriz producto de la suma de los elementos de m1 con lo que
// sería una matriz con las dimensiones de m1 y con todos sus elementos iguales
// a valor.
// No se modifica ninguno de los operandos ni la matriz implícita
Matriz2D operator+ (const Matriz2D m1, const TipoBase valor)
{
	Matriz2D resultado(m1.NumFilas(), m1.NumColumnas(), valor);

	return (m1 + resultado);
}

Matriz2D operator+ (const TipoBase valor, const Matriz2D m1)
{
	return (m1 + valor);
}

// Operador -: Matriz2D - Matriz2D
// Devuelve una matriz con la resta de los elementos de ambas matrices
// No se modifica ninguno de los operandos ni la matriz implícita
Matriz2D operator- (const Matriz2D & m1, const Matriz2D & m2)
{
	return (m1 + (-m2));
}

// Operador -: Matriz2D - TipoBaseMatriz2D (o viceversa)
// Devuelve una matriz producto de la resta de los elementos de m1 con lo que
// sería una matriz con las dimensiones de m1 y con todos sus elementos iguales
// a valor.
// No se modifica ninguno de los operandos ni la matriz implícita
Matriz2D operator- (const Matriz2D m1, const TipoBase valor)
{
	return (m1 + (-valor));
}

Matriz2D operator - (const TipoBase valor, const Matriz2D m1)
{
	return (m1 - valor);
}

/***************************************************************************/
// Sobrecarga de los operadores combinados += y -=:
// Operador +=: Devuelve la matriz implícita a la que se le suman los elementos
// de la matriz "otra"
Matriz2D & Matriz2D :: operator+= (const Matriz2D & otra)
{
	*this = *this + otra;
	return *this;
}

// Operador -=:Devuelve la matriz implícita a la que se le restan los elementos
// de la matriz "otra"
Matriz2D & Matriz2D :: operator-= (const Matriz2D & otra)
{
	*this = *this - otra;
	return *this;
}

/***************************************************************************/
// Sobrecarga del operador *
// Matriz2D * int: Devuelve una matriz con los valores de la
// matriz implícita multiplicados por el valor int
// No se madifican los valores de la matriz implícita
Matriz2D operator* (const Matriz2D & original, const TipoBase valor)
{
	// Inicializo la matriz resultado a original con el constructor copia
	Matriz2D resultado(original);

	// Multiplico cada elemento de original por valor
	for (int i = 1; i <= resultado.NumFilas(); i++)
	{
		for (int j = 1; j <= resultado.NumColumnas(); j++)
		{
			resultado(i, j) *= valor;
		}
	}

	return resultado;
}


// Matriz2D * Matriz2D: Devuelve una matriz con los valores de la
// matriz implícita multiplicados por los valores de la matriz "otra"
// No se madifican los valores de ninguno de los operandos
// Matriz2D & operator * (const Matriz2D & m1, const Matriz2D & m2);
Matriz2D operator* (const TipoBase valor, const Matriz2D & original)
{
	return (original * valor);
}

/***************************************************************************/
// Sobrecarga del operador >> para leer una matriz desde un flujo de entrada
// Parámetros: objeto de tipo istream desde el que leer los datos de la matriz
// Parámetros: objeto de tipo Matriz2D en el que se almacenarán los datos leídos
// Devuelve: referencia al flujo de entrada
istream & operator>> (istream & in, Matriz2D & m)
{
	string flujo;

    // Leo el número de columnas
    // Si da solo un argumento da excepción
	getline(in, flujo);
	if (flujo != "MATRIZ")
	{
		cerr << "Error: no se ha encontrado la palabra MATRIZ" << endl;
		exit(1);
	}
	
	// Leo la segunda linea, que solo debe contener las dimensiones de la matriz
	getline(in, flujo);
	istringstream iss(flujo);
	// La función stoi dará excepción si no es un int
	int filas = 0;
	if(iss >> flujo){
        // La función stoi dará excepción si no es un int
        filas = stoi(flujo);
	}
    else{
        cerr << "Error: ningún argumento en la segunda linea, deben ser 2\n";
        exit(1);
    }

    // Leo el número de columnas
    // Si da solo un argumento da excepción
	int columnas = 0;
    if(iss >> flujo){
        columnas = stoi(flujo);
	}
    else{
        cerr << "Error: solo 1 argumento en la segunda linea, deben ser 2\n";
        exit(1);
    }

    // Si da más de dos argumentos en la segunda linea, da excepción
    if (iss >> flujo)
    {
        cerr << "Error: Más de dos argumentos en la segunda linea, deben ser 2"
             << endl;
        exit(1);
    }
    
    // Creo la matriz con los parámetros indicados
	cout << "Filas: " << filas << " Columnas: " << columnas << endl;
    m = Matriz2D(filas, columnas);

    // Leo los siguientes elementos y los almaceno como elementos de la matriz.
    for (int i = 1; i <= m.NumFilas(); i++)
    {
        for (int j = 1; j <= m.NumColumnas(); j++)
        {
		// Compruebo el tipo de dato y lo almaceno
		// Es una forma cutre de comprobar el tipo de dato
		// pero no se me ocurría otra
			if (in >> flujo)
			{
				#ifdef INT_MATRIZ
				{
					m(i, j) = stoi(flujo);	
				}
				#endif

				#ifdef CHAR_MATRIZ
				{
					if (flujo.size() > 1)
					{
						cerr << "Error: Solo se admiten caracteres, no palabras"
								<< endl;
						exit(1);
					}

					m(i, j) = flujo[0];
				}
				#endif
			}
			else
			{
				cerr << "Error: No se han proporcionado suficientes elementos"
						<< endl;
				exit(1);
			}
        }
    }

    if(in >> flujo)
    {
        cerr << "Error: Demasiados elementos proporcionados" << endl;
        exit(1);
    }

	return in;
}

/***************************************************************************/
// Sobrecarga del operador << para escribir una matriz en un flujo de salida
// Parámetros: objeto de tipo istream desde el que leer los datos de la matriz
// Parámetros: objeto de tipo Matriz2D del que se leerán los datos a escribir
// Devuelve: referencia al flujo de entrada
// En circunstancias normales usaría toString sin más y así no duplicaría
// código, pero en este enunciado se pide que tenga setw(6) y setfill(' ')
// que yo sepa no se pueden usar al formar un string
ostream& operator<<(ostream &out, const Matriz2D &m)
{

	out << endl << ".................................." << endl;
    out << "Filas = " << setw(6) << setfill(' ') << m.NumFilas();
    out << " , Columnas = " << setw(6) << setfill(' ') << m.NumColumnas() << endl;

    for (int i = 1; i <= m.NumFilas(); i++)
	{
        for (int j = 1; j <= m.NumColumnas(); j++)
		{
            out << setw(6) << setfill(' ') << m(i,j);
        }

        out << endl;
    }

    return out;
}

/***************************************************************************/
//Guarda en el fichero de texto nombre el contenido de la matriz. Si el
//fichero ya existiera, se reemplaza su contenido por el de la matriz. La
//matriz no se modifica. Escribe los datos por filas, esto es, cada línea
//de salida contiene los valores de una fila de la matriz delimitados por
//separadores
void Matriz2D :: EscribirMatriz2D (const char * nombre) const
{
	ifstream fichero(nombre);

	if (fichero)
	{
		cout << "CUIDADO: Se va a sobreescribir el fichero " << nombre << endl;
		cout << "¿Está seguro? (S/N): ";
		char respuesta;
		cin >> respuesta;
		respuesta = toupper(respuesta);
		
		if (respuesta != 'S')
		{
			cerr << "Operación cancelada" << endl;
			exit(1);
		}
	}


	ofstream fichero_escritura(nombre);

	fichero_escritura << "MATRIZ" << endl;

	fichero_escritura << NumFilas() << " " << NumColumnas() << endl;

	for (int f = 1; f <= NumFilas(); f++)
	{
		for (int c = 1; c <= NumColumnas(); c++)
		{
			fichero_escritura << (*this)(f, c) << " ";
		}

		fichero_escritura << endl;
	}

	fichero_escritura.close();
}

/***************************************************************************/
//Sustituye el contenido de la matriz por los valores que están en el fichero
//de texto nombre.
void Matriz2D :: LeerMatriz2D (const char * nombre)
{
	(*this) = Matriz2D(nombre);
}

/***************************************************************************/
// Devuelve un string con el resultado de "serializar" una 
// Parámetros: matriz (referencia), la matriz que va a serializarse. 
// Parámetros: Cadena: Texto que se pondrá al inicio de cada fila.
// "Fila" por defecto
// Parámetros: empiezaen: Número de fila en la que se empezará a serializar.
// 1 por defecto.
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
// Métodos de consulta de las dimensiones de la matriz.
int Matriz2D :: NumFilas () const
{
	return (fils);
}

int Matriz2D :: NumColumnas () const
{
	return (cols);
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
	for (i = 1; i <= NumFilas() && lo_son; i++)
	{
		for (int j = 1; j <= NumColumnas() && lo_son; j++)
		{
			if ((*this)(i,j) != otra(i, j))
			{
				lo_son = false;
			}
		}
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
// PRE: 0 < fila_inic <= fils y 0 < col_inic <= cols
Matriz2D Matriz2D :: SubMatriz (int fila_inic, int col_inic,\
								 int num_filas, int num_cols)
{
	fila_inic--;
	col_inic--;

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
	if (fila_nueva.TotalUtilizados() != NumColumnas())
	{
		cerr << "Error: La fila a añadir no tiene el mismo número de columnas\
que la matriz" << endl;
		 exit(1);
	}

	// Guardo los datos de la matriz original en un vector dinámico
	TipoBase * tmp = new TipoBase[NumFilas()*NumColumnas()];
	memcpy(tmp, datos[0], NumFilas()*NumColumnas()*sizeof(TipoBase));

	int num_filas = NumFilas()+1;
	int num_columnas = NumColumnas();
	// Reservo memoria para la nueva matriz
	LiberaMemoria();
	ReservaMemoria(num_filas, num_columnas);

	// Copio los datos de tmp a la original y le añado la nueva fila
	memcpy(datos[0], tmp, (NumFilas()-1)*NumColumnas()*sizeof(TipoBase));
	delete [] tmp;
	memcpy(datos[NumFilas()-1], &fila_nueva.Valor(0), NumColumnas()*sizeof(TipoBase));
}

/****************************************************************************/
// Método para insertar una fila en una posición dada. La fila nueva (una dato
//Secuencia) debe tener el mismo número de casillas que columnas tenga la
//matriz. La posición indicada será la posición que tendrá la fila después de la
//inserción.
//PRE: 0 < indice <= fils
void Matriz2D :: Inserta (int indice, const Secuencia & fila_nueva)
{
	// Compruebo que la fila a añadir tiene el mismo número de columnas
	if (fila_nueva.TotalUtilizados() != cols)
	{
		cerr << "Error: La fila a añadir no tiene el mismo número de columnas\
que la matriz" << endl;
		 exit(1);
	}

	// Compruebo que el índice es correcto
	if (indice < 1 || indice > fils)
	{
		cerr << "Error: El índice de la fila a insertar no es correcto" << endl;
		exit(1);
	}

	// Guardo los datos de la matriz original en un vector dinámico
	TipoBase *tmp = new TipoBase[fils*cols];
	memcpy(tmp, datos[0], fils*cols*sizeof(TipoBase));

	// Reservo memoria para la nueva matriz
	int num_filas = NumFilas()+1;
	int num_columnas = NumColumnas();

	LiberaMemoria();
	ReservaMemoria(num_filas, num_columnas);

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
// PRE: 0 < num_fila/num_col <= fils/cols
void Matriz2D :: EliminaFila (int num_fila)
{
	// Compruebo que el índice es correcto
	if (num_fila < 1 || num_fila > fils)
	{
		cerr << "Error: El índice de la fila a eliminar no es correcto" << endl;
		exit(1);
	}

	num_fila--;
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
	if (num_col < 1 || num_col > cols)
	{
		cerr << "Error: El número de columna a eliminar no es correcto" << endl;
		exit(1);
	}
	
	num_col--;
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
			  INI		B1			B2        B3         B4     FIN

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
// ORDENAR MATRIZ MENOR-MAYOR SEGUN COLUMNA 
// Reodena la matriz en base a la reordenación de mayor a menor de la columna
// indicada.
// Parametros: indice de la columna a ordenar (1 <= indice <= cols)
void Matriz2D :: OrdenaMatrizMenorMayor (int indice)
{
	// Compruebo que el índice es correcto
	if (indice < 1 || indice > NumColumnas())
	{
		cerr << "Error: El índice de la columna a ordenar no es correcto" << endl;
		exit(1);
	} 

	// Ordeno la columna
	// Creo un puntero temporal
	for (int i = 1; i <= NumFilas(); i++)
	{
		TipoBase * menor = &((*this)(i,indice));
		int Filadelmenor = i;

		for (int j = i+1; j <= NumFilas(); j++)
		{
			if ((*this)(j,indice) < *menor)
			{
				menor = &((*this)(j,indice));
				Filadelmenor = j;
			}
		}

		// Intercambio la fila i con la fila del menor
		if (Filadelmenor != i)
		{
			// Creo un puntero temporal
			TipoBase * tmp = datos[i];
			// Intercambio las filas
			datos[i] = datos[Filadelmenor];
			datos[Filadelmenor] = tmp;
		}
	}
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
	if (datos != nullptr)
	{
		cerr << "ERROR: No se ha liberado memoria antes de reservar memoria" << endl;
		exit(1);
	}
	
	// Solo si se cumplen las precondiciones se reserva memoria 
	if (nfils<0 || ncols<0)
	{
		cerr << "ERROR: No se puede reservar memoria para una matriz vacía" << endl;
		exit(1);
	}

	// Actualizo los campos de la matriz
	fils = nfils;
	cols = ncols;

	// "matriz" apuntará a un vector de punteros a cada filas
	datos = new TipoBase * [nfils];

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

/***************************************************************************/
// Copia profunda. Hace una copia profunda de origen en destino.

void Matriz2D :: CopiarDatos (const Matriz2D & otra)
{
	if (this != &otra)
	{
		// Limpio la matriz destino (me da igual lo que hubiese)
		LiberaMemoria();
		// Reservo memoria para la matriz destino
		ReservaMemoria(otra.NumFilas(), otra.NumColumnas());

		// Copio los datos de la matriz origen en la matriz destino
		for (int i = 1; i <= otra.NumFilas(); i++)
		{
			for (int j = 1; j <= otra.NumColumnas(); j++)
			{
				(*this)(i,j) = otra(i, j);
			}
		}
	}
	else
	{
		cerr << "Error: Copia de una matriz sobre sí misma" << endl;
		exit(1);
	}
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

TipoBase & Matriz2D :: Valor (const int num_fila, const int num_columna) const
{
	if (num_fila < 0 || num_fila >= fils || 
	num_columna < 0 || num_columna >= cols)
	{
			cerr << "Error: Acceso a una posición no válida de la matriz" << endl;

			cerr << "Se está intentando acceder a la posición: " \
			<< num_fila << ", " << num_columna << endl;

			cerr << "La matriz tiene " << fils << " filas y " <<\
			cols << " columnas" << endl;
			exit(1);
	}

	return (datos[num_fila][num_columna]);
}
////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
