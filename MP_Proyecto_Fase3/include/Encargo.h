/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// AUTOR: MARCO GIRELA VIDA
// GRUPO: 1ºB
// FECHA: 08/04/2023
//
// PROYECTO FASE 1
//
// Fichero: Encargo.h
/*****************************************************************************/

#ifndef ENCARGO_H
#define ENCARGO_H

#include <string>

using namespace std;

/***************************************************************************/
/***************************************************************************/

class Encargo
{
    private:
        int categoria = 0;  // Categoría del profesor (valor entre 1 y 5)
        double creditos = 0; // Créditos asociados a la categoría

        static const char DELIMITADOR_ENCARGO = '*';

    public:
        /*********************************************************************/
        //-------------------------CONSTRUCTORES----------------------------//
        /*********************************************************************/
        // Constructor sin argumentos. 
        // Inicializa todos los campos a valor nulo.
        // Necesario para crear arrays o matrices de objetos Encargo.

        Encargo (void);


        /*********************************************************************/
        // Constructor desde un string.
        // Compone un dato Encargo a patir de un dato string. 
        // Parámetros: linea, el dato string del que se extraen los valores.
        // 			   delimitador, el caracter que delimita los campos. 
                        
        Encargo (string linea, char delimitador=DELIMITADOR_ENCARGO);

        /*********************************************************************/
        // Constructor desde dos int, double.
        // Parámetros: la_categoría, int con la categoría del Encargo. 
        //             los_creditos, double con creditos del Encargo. 

        Encargo (int la_categoria, double los_creditos); 

        /*********************************************************************/
        // Constructor de copia
        // Parámetros: otro (referencia), objeto que sirve de modelo. 

        Encargo (const Encargo & otro);


        /*********************************************************************/
        // Destructor.
        // ~Encargo (void);

        
	/*************************************************************************/
	//--------------------------- MÉTODOS -----------------------------------//
	/*************************************************************************/
        // Métodos get

        int getCategoria() const;
        int getCreditos() const;

        /***************************************************************************/
        // Métodos set

        void setCategoria(int cat);
        void setCreditos(double cred);

        /***************************************************************************/
        // Método ToString

        string ToString();

        /***********************************************************************/
	// Sobrecarga del operador de asignación para copia profunda.
	// Parámetros: otro (referencia), objeto que sirve de modelo. 

	Encargo & operator = (const Encargo & otro);

	/*************************************************************************/
	//------------------------MÉTODOS PRIVADOS-------------------------------//
	/*************************************************************************/
	// Copiar datos desde otro objeto de la clase
	// Parámetros: otro (referencia), objeto que sirve de modelo. 
	//
	// PRE: Se ha reservado memoria para los datos

	void CopiarDatos (const Encargo & otro);

};
#endif