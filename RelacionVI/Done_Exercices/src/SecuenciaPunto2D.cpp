/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// Clase "SecuenciaPunto2D"
//
// Representación: array dinámico para alojar los datos en el Heap.
// Los datos son de tipo "Punto2D"
//
// Definición de la clase "SecuenciaPunto2D".
// Declaraciones en SecuenciaPunto2D.
// 
// Fichero: SecuenciaPunto2D.cpp
//
/***************************************************************************/

#include <cstring>
#include <string>
#include <iostream>

#include "SecuenciaPunto2D.h"
#include "Punto2D.h"

using namespace std;


/***********************************************************************/
// Constructores.
// Si se llama sin argumentos crea una secuencia con capacidad = TAMANIO.
// Si se llama con un argumento, su valor será la capacidad inicial. 
// POST: La secuencia creada estará vacía (EstaVacia()== true)

SecuenciaPunto2D :: SecuenciaPunto2D (int la_capacidad)
	: capacidad (la_capacidad), 
	  total_utilizados (0) 
{
	ReservarMemoria (capacidad);
}

/***********************************************************************/
// Constructor de copia

SecuenciaPunto2D :: SecuenciaPunto2D (const SecuenciaPunto2D & otro)
{
	ReservarMemoria (otro.capacidad);
	CopiarDatos (otro);
}

/***********************************************************************/
// Destructor 

SecuenciaPunto2D :: ~SecuenciaPunto2D (void)
{
	LiberarMemoria();
}

/***********************************************************************/
// Devuelve el número de casillas ocupadas

int SecuenciaPunto2D :: TotalUtilizados (void) const
{
	return (total_utilizados);
}

/***********************************************************************/
// Devuelve el número de casillas disponibles

int SecuenciaPunto2D :: Capacidad (void) const
{
	return (capacidad);
}

/***********************************************************************/
// Devuelve "true" si la secuencia está vacía (total_utilizados == 0)

bool SecuenciaPunto2D :: EstaVacia (void) const 
{
	return (total_utilizados == 0);
}

/***********************************************************************/
// "Vacía" completamente la secuencia
// POST: EstaVacia() == true 
// POST: Capacidad() == TAMANIO.

void SecuenciaPunto2D :: EliminaTodos()
{
	LiberarMemoria();		// La secuencia queda vacía
	ReservarMemoria (TAMANIO);	// Capacidad = TAMANIO
}

/***********************************************************************/
// Añade un elemento ("nuevo") a la secuencia.
// El nuevo elemento se coloca al final del vector.
//
// Se redimensionará el vector dinámico de datos si no tuviera suficiente 
// espacio disponible.

void SecuenciaPunto2D :: Aniade (const Punto2D & nuevo)
{
	// Comprobar si hay que redimensionar el array dinámico

	if (total_utilizados == capacidad) 
		Redimensionar ();

	// Añadir al final del array dinámico y actualizar "total_utilizados"
	vector_privado [total_utilizados] = nuevo;
	total_utilizados++;
}

/***********************************************************************/
// Eliminar el contenido de la "casilla" cuya posición es "indice".
// Parámetros: 
//      indice, posición del elemento que se borra.  
//
// PRE: 1 <= indice <= total_utilizados

void SecuenciaPunto2D :: Elimina (int indice)
{
    if ((indice >= 1) && (indice <= total_utilizados)) {

		// "Desplazar" los valores desde la casilla siguiente a "indice" 
		// hasta el final una posición a la izquierda 

		memmove (&vector_privado[indice-1], &vector_privado[indice], 
                 (total_utilizados-indice)*sizeof(Punto2D));
 
		// Actualizar "total_utilizados"
        total_utilizados--;
    }
}
   
/***********************************************************************/
// Devuelve una referencia al elemento de la casilla "indice"
// Parámetros: 
//      indice, posición del elemento al que se accede.  
// 
// PRE: 1 <= indice <= total_utilizados

Punto2D & SecuenciaPunto2D :: operator [] (const int indice)
{
    return (el_valor(indice));
}

Punto2D & SecuenciaPunto2D :: operator [] (const int indice) const
{
    return (el_valor(indice));
}

/***********************************************************************/
// Copia profunda.
// Parámetros: 
//      otra (referencia), objeto que sirve de modelo para la copia. 

SecuenciaPunto2D & SecuenciaPunto2D::operator = (const SecuenciaPunto2D & otro)
{
	if (this != &otro) {
		LiberarMemoria(); // La secuencia queda vacía
		ReservarMemoria (otro.capacidad);
		CopiarDatos (otro);
	}
	return (*this);
}

/***********************************************************************/
// Compone un string con todos los caracteres que están
// almacenados en la secuencia y lo devuelve.

string SecuenciaPunto2D :: ToString()
{
    string cadena;

	cadena = "{ ";

	if (total_utilizados>0) cadena = cadena + vector_privado[0].ToString(); 

    for (int i=1; i<total_utilizados; i++) {

		cadena = cadena + ", " + vector_privado[i].ToString();
	}

	cadena = cadena + " }";

    return (cadena);
}


/***************************************************************************/
/***************************************************************************/
// Sobrecarga de los operadores >> y << 

istream & operator >> (istream & in,  SecuenciaPunto2D & sec)
{
	Punto2D punto_leido;	

	while (cin >> punto_leido)
		sec.Aniade (punto_leido);

	return in; 
}

ostream & operator << (ostream & out, const SecuenciaPunto2D & sec)
{
	for (int pos=0; pos<sec.total_utilizados; pos++) {

		out << sec.vector_privado[pos] << endl;
	}

	return out; 
}

/***************************************************************************/
/***************************************************************************/



/***************************************************************************/
/***************************************************************************/
// MÉTODOS PRIVADOS DE LA CLASE Secuencia
/***************************************************************************/
/***************************************************************************/

/***************************************************************************/
// Pide memoria para guardar "num_casillas" datos	

void SecuenciaPunto2D :: ReservarMemoria (const int num_casillas)
{
	vector_privado = new Punto2D[num_casillas]; 
	capacidad = num_casillas; 
}

/***************************************************************************/
// Libera memoria

void SecuenciaPunto2D :: LiberarMemoria (void)
{
	if (vector_privado) { 

		delete [] vector_privado;

		vector_privado = nullptr;
		capacidad = 0; 
		total_utilizados = 0;
	}
}

/***************************************************************************/
// Copiar datos desde otro objeto de la clase
// PRE: Se ha reservado memoria para los datos

void SecuenciaPunto2D :: CopiarDatos (const SecuenciaPunto2D & otro)
{
	// Copia los valores de los campos privados desde "otro" 
	capacidad = otro.capacidad;  
	total_utilizados = otro.total_utilizados;	

	// Copiar los valores de los datos
	memcpy (vector_privado, otro.vector_privado,  
		    total_utilizados*sizeof(Punto2D));
}

/***************************************************************************/
// Redimensiona el vector dinámico y copia los datos en el nuevo almacén.  

void SecuenciaPunto2D :: Redimensionar (void)
{
	int nueva_capacidad = capacidad + TAM_BLOQUE;  

	// Pedir memoria para el nuevo almacen 
	Punto2D * tmp = new Punto2D[nueva_capacidad]; 

	// Copiar los datos 
	memcpy (tmp, vector_privado, total_utilizados*sizeof(Punto2D)); 

	// Liberar la memoria del antiguo almacén
	delete [] vector_privado; 

	// Reasignacion del puntero "vector_privado" para que referencie 
	// a la nueva zona de memoria ampliada y con los datos copiados. 
	vector_privado = tmp; 

	capacidad = nueva_capacidad;
}

/***********************************************************************/
// Método PRIVADO compartido por: 
//      Punto2D & Valor (const int indice);
//      Punto2D & Valor (const int indice) const;
// para evitar la duplicidad de código.
// 
// Devuelve una referencia a un dato Punto2D de la secuencia.
// dado su posición. 
//
// PRE: 1 <= indice <= total_utilizados

Punto2D & SecuenciaPunto2D :: el_valor (int indice) const
{
    return (vector_privado[indice-1]);
}

/***************************************************************************/
/***************************************************************************/
