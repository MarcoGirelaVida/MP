/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// AUTOR: MARCO GIRELA VIDA
// GRUPO: 1ºB
// FECHA: 08/04/2023
//
// PROYECTO FASE 3
//
// Fichero: Profesor.h
/*****************************************************************************/

#ifndef PROFESOR_H
#define PROFESOR_H

#include <string>
#include "Fecha.h"

using namespace std;

/***************************************************************************/
/***************************************************************************/
class Profesor
{

private:

    char * DNI = nullptr;
    char * Nombre = nullptr;
    char * Apellidos = nullptr;
    Fecha FechaNacimiento;
    int Categoria;

    // Delimitador del final de un campo en una línea de datos
	static const char DELIMITADOR_PROFESOR = '*';

public:

    /*************************************************************************/
    //-------------------------CONSTRUCTORES---------------------------------//
    /*************************************************************************/
    // Constructor sin argumentos. 
    // Inicializa todos los campos a valor nulo (cadena vacía).
    // Necesario para crear arrays o matrices de objetos Profesor.

    Profesor (void);

    /************************************************************************/
    // Constructor de copia
    // Parámetros: otro (referencia), objeto que sirve de modelo. 

    Profesor (const Profesor & otro);

    /************************************************************************/
    // Constructor desde 5 string.
    // Parámetros: el_DNI, string con el id del DNI. 
    //             el_nombre, string con el nombre. 
    //             el_apellidos, string con los apellidos.
    //             la_fecha, string con la fecha de nacimiento.
    //             la_categoria, int con la categoria.

    Profesor (string el_DNI, string el_nombre, string el_apellidos,
                                string la_fecha, int la_categoria); 

    /************************************************************************/
    // Constructor desde un string.
    // Compone un dato Profesor a patir de un dato string. 
    // Parámetros: linea, el dato string del que se extraen los valores.
    // 			   delimitador, el caracter que delimita los campos. 
                    
    Profesor (string linea, char delimitador=DELIMITADOR_PROFESOR);


    /************************************************************************/
    // Destructor
    ~Profesor();


    /*************************************************************************/
    //----------------------------MÉTODOS------------------------------------//
    /*************************************************************************/
    // Métodos get

    string getDni() const;
    string getNombre() const;
    string getApellidos() const;
    string getFechaNacimiento() const;
    int getCategoria() const;

    /***************************************************************************/
    // Métodos set

    void setDni(string arg_DNI = "");
    void setNombre(string arg_Nombre = "");
    void setApellidos(string arg_Apellidos = "");
    void setFechaNacimiento(string arg_fechanacimiento = "");
    void setCategoria(int arg_categoria);

    /***************************************************************************/
    // Método ToString

    string ToString(bool mes_string = false) const;

    /***********************************************************************/
	// Sobrecarga del operador de asignación para copia profunda.
	// Parámetros: otro (referencia), objeto que sirve de modelo. 

	Profesor & operator = (const Profesor & otro);

private: 	
		   
	/*************************************************************************/
	//------------------------MÉTODOS PRIVADOS-------------------------------//
	/*************************************************************************/
    // Copiar datos desde otro objeto de la clase
    // Parámetros: otro (referencia), objeto que sirve de modelo. 
    //
    // PRE: Se ha reservado memoria para los datos

    void CopiarDatos (const Profesor & otro);

    /***********************************************************************/
    // Pide memoria para guardar una copia de los datos de "otro"
    // Parámetros: otro (referencia), objeto que sirve de modelo. 

    void ReservarMemoria (const Profesor & otro);

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
                            char delimitador=DELIMITADOR_PROFESOR); 

};
#endif