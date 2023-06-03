/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// AUTOR: MARCO GIRELA VIDA
// GRUPO: 1ºB
// FECHA: 08/04/2023
//
// PROYECTO FASE 3
//
// Fichero: Adscripcion.h
/*****************************************************************************/

#ifndef ADSCRIPCION_H
#define ADSCRIPCION_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstring>
#include "utils.h"

using namespace std;

/***************************************************************************/
/***************************************************************************/
// Clase "Adscripcion"
class Adscripcion
{

private:
        char * DNI;
        char * Id_depto;

        static const char DELIMITADOR_ADS = '*';

public:
        /*********************************************************************/
        //-------------------------CONSTRUCTORES----------------------------//
        /*********************************************************************/
        // Constructor sin argumentos. 
        // Inicializa todos los campos a valor nulo (cadena vacía).
        // Necesario para crear arrays o matrices de objetos Adscripcion.

        Adscripcion (void);

        /*********************************************************************/
        // Constructor desde un string.
        // Compone un dato Adscripcion a patir de un dato string. 
        // Parámetros: linea, el dato string del que se extraen los valores.
        // 			   delimitador, el caracter que delimita los campos. 
                        
        Adscripcion (string linea, char delimitador=DELIMITADOR_ADS);

        /*********************************************************************/
        // Constructor desde dos string.
        // Parámetros: el_DNI, string con el id del Adscripcion. 
        //             Id_depto, string con el nombre del Adscripcion. 

        Adscripcion (string el_id_depto, string el_DNI); 


        /*********************************************************************/
        // Constructor de copia
        // Parámetros: otro (referencia), objeto que sirve de modelo. 

        Adscripcion (const Adscripcion & otro);

        /*********************************************************************/
        // Destructor.

        ~Adscripcion (void);

        /*********************************************************************/
        //-------------------------MÉTODOS-----------------------------------//
        /*********************************************************************/
        // Métodos get

        string getDniProfesor() const;

        string getIdDepartamento() const;

        /*********************************************************************/
        // Métodos set

        void setDniProfesor(string dni = "");

        void setIdDepartamento(string id = "");

        /***************************************************************************/
        // OPERATOR >> 
        // Lee un dato Adscripcion desde un flujo de entrada.
        // Parámetros: flujo, referencia a un flujo de entrada.
        //             otro, referencia a un objeto de la clase Adscripcion. 

        friend istream & operator >> (istream & flujo, Adscripcion & otro);

        /***************************************************************************/
        // OPERATOR <<
        // Escribe un dato Adscripcion en un flujo de salida.
        // Parámetros: flujo, referencia a un flujo de salida.
        //             otro, referencia a un objeto de la clase Adscripcion. 

        friend ostream & operator << (ostream & flujo, const Adscripcion & otro);
        
        /*********************************************************************/
        // Método ToString

        string ToString(string cadena_inical = "", char delimitador = DELIMITADOR_ADS) const;

        /***********************************************************************/
        // Sobrecarga del operador == para comprobar si un Adscripcion es igual 
        // a otro (tiene la misma clave primaria)

        bool operator == (const Adscripcion & otro) const;

        /***********************************************************************/
	// Sobrecarga del operador de asignación para copia profunda.
	// Parámetros: otro (referencia), objeto que sirve de modelo. 

        Adscripcion & operator = (const Adscripcion & otro);

private: 	
		   
	/*************************************************************************/
	//------------------------MÉTODOS PRIVADOS-------------------------------//
	/*************************************************************************/
	// Copiar datos desde otro objeto de la clase
	// Parámetros: otro (referencia), objeto que sirve de modelo. 
	//
	// PRE: Se ha reservado memoria para los datos

	void CopiarDatos (const Adscripcion & otro);

        /***********************************************************************/
	// Pide memoria para guardar una copia de los datos de "otro"
	// Parámetros: otro (referencia), objeto que sirve de modelo. 

	void ReservarMemoria (const Adscripcion & otro);

        /***********************************************************************/
	// Libera memoria
	
	void LiberarMemoria (void);

        /***********************************************************************/
	// Compone y devuelve un dato string a partir de otro, tomando los 
	// caracteres desde una posición dada hasta encontrar un carácter dado.
	// Parámetros: cad_fuente, string desde donde se extrae la palabra.
	//			   pos, posición inicial.
	//			   delimitador, carácter que marca el final.
	//
	// PRE: 0 <= pos 
	// PRE: "cad_fuente" es correcta.

	string FormaPalabra (string cad_fuente, int pos, 
		                 char delimitador=DELIMITADOR_ADS);
        
        /*************************************************************************/
	// TODONULO: Pone todos los atributos a nulo
    
        void TodoNulo (void);
};
#endif