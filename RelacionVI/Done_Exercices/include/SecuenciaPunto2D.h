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
// Declaración de la clase "SecuenciaPunto2D".
// Definiciones en: SecuenciaPunto2D.cpp
// 
// Fichero: SecuenciaPunto2D.h
//
/***************************************************************************/

#ifndef CLASS_SECUENCIA_PUNTO2D
#define CLASS_SECUENCIA_PUNTO2D

#include <string>

#include "SecuenciaPunto2D.h"
#include "Punto2D.h"

using namespace std;

/////////////////////////////////////////////////////////////////////////////

class SecuenciaPunto2D {

private:
 
	// Núm.casillas disponibles (capacidad) por defecto
    static const int TAMANIO = 2; 

    // Número de casillas para redimensionar
    static const int TAM_BLOQUE = 3; 

	// "vector_privado" es un puntero a un array dinámico de 
	// datos "Punto2D"
    Punto2D * vector_privado;

    // PRE: 0 <= capacidad
    int capacidad; // Núm.casillas ocupadas

    // PRE: 0 <= total_utilizados <= capacidad
    int total_utilizados; // Núm.casillas ocupadas

public:

    /***********************************************************************/
    // Constructores.
    // Si se llama sin argumentos crea una secuencia con capacidad = TAMANIO.
    // Si se llama con un argumento, su valor será la capacidad inicial. 
    // POST: La secuencia creada estará vacía (EstaVacia()== true)

    SecuenciaPunto2D (int la_capacidad=TAMANIO);
	
    /***********************************************************************/
    // Constructor de copia

    SecuenciaPunto2D (const SecuenciaPunto2D & otro);

    /***********************************************************************/
    // Destructor 

    ~SecuenciaPunto2D (void);

    /***********************************************************************/
    // Devuelve el número de casillas ocupadas

    int TotalUtilizados (void) const;

    /***********************************************************************/
    // Devuelve el número de casillas disponibles

    int Capacidad (void) const;

    /***********************************************************************/
    // Devuelve "true" si la secuencia está vacía (total_utilizados == 0)

	bool EstaVacia (void) const;

    /***********************************************************************/
    // "Vacía" completamente la secuencia
	// POST: Capacidad() == TAMANIO.
	// POST: EstaVacia() == true 

	void EliminaTodos();

    /***********************************************************************/
    // Añade un elemento ("nuevo") a la secuencia.
    // El nuevo elemento se coloca al final del vector.
    // Parámetros: 
    //      nuevo (referencia), objeto que se añade. 
    //
    // Se redimensionará el vector dinámico de datos si no tuviera suficiente 
    // espacio disponible.   
    
    void Aniade (const Punto2D & nuevo);
    
    /***********************************************************************/
    // Eliminar el contenido de la "casilla" cuya posición es "indice".
    // Parámetros: 
    //      indice, posición del elemento que se borra.  
    //
    // PRE: 1 <= indice <= total_utilizados

    void Elimina (int indice);

    /***********************************************************************/
    // Devuelve una referencia al elemento de la casilla "indice"
    // Parámetros: 
    //      indice, posición del elemento al que se accede.  
    //    
    // PRE: 1 <= indice <= total_utilizados

    Punto2D & operator [] (const int indice);
    Punto2D & operator [] (const int indice) const;

    /***********************************************************************/
    // Copia profunda.
    // Parámetros: 
    //      otra (referencia), objeto que sirve de modelo para la copia. 

    SecuenciaPunto2D & operator = (const SecuenciaPunto2D & otra);

    /***********************************************************************/
    // Compone un string con todos los caracteres que estÃ¡n
    // almacenados en la secuencia y lo devuelve.

    string ToString();

    /***********************************************************************/
    /***********************************************************************/
    // Sobrecarga de los operadores >> y << 

    friend istream & operator >> (istream & in,  SecuenciaPunto2D & sec); 
    friend ostream & operator << (ostream & out, const SecuenciaPunto2D & sec);  

    /***********************************************************************/
    /***********************************************************************/

private:

    /***********************************************************************/
	// Pide memoria para guardar "num_casillas" datos	

	void ReservarMemoria (const int num_casillas);

    /***********************************************************************/
	// Libera memoria

	void LiberarMemoria (void);

    /***********************************************************************/
	// Copiar datos desde otro objeto de la clase
	// PRE: Se ha reservado memoria para los datos

	void CopiarDatos (const SecuenciaPunto2D & otro); 

	/***********************************************************************/
    // Redimensiona el vector dinámico y copia los datos en el nuevo almacén.  

	void Redimensionar (void);

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

    Punto2D & el_valor (int indice) const;

    /***********************************************************************/
    /***********************************************************************/

};

/////////////////////////////////////////////////////////////////////////////

#endif