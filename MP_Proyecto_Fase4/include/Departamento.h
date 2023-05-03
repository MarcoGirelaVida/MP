/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// AUTOR: MARCO GIRELA VIDA
// GRUPO: 1ºB
// FECHA: 08/04/2023
//
// PROYECTO FASE 3
//
// Fichero: Departamento.h
/*****************************************************************************/

#ifndef DEPARTAMENTO
#define DEPARTAMENTO

#include <string>

using namespace std;

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
// Clase: Departamento
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

class Departamento {

private: 

	char * Id_depto;	
	char * Nombre;

	// Delimitador del final de un campo en una línea de datos
	static const char DELIMITADOR_DEPARTAMENTO = '*';

public : 

	/*************************************************************************/
	//-------------------------CONSTRUCTORES---------------------------------//
	/*************************************************************************/
	// Constructor sin argumentos. 
	// Inicializa todos los campos a valor nulo (cadena vacía).
	// Necesario para crear arrays o matrices de objetos Departamento.

	Departamento (void);

	/************************************************************************/
	// Constructor desde dos string.
	// Parámetros: el_id_depto, string con el id del departamento. 
	//             el_nombre, string con el nombre del departamento. 

	Departamento (string el_id_depto, string el_nombre); 


	/************************************************************************/
	// Constructor desde un string.
	// Compone un dato Departamento a patir de un dato string. 
	// Parámetros: linea, el dato string del que se extraen los valores.
	// 			   delimitador, el caracter que delimita los campos. 
					
	Departamento (string linea, char delimitador=DELIMITADOR_DEPARTAMENTO);

	/************************************************************************/
	// Constructor de copia
	// Parámetros: otro (referencia), objeto que sirve de modelo. 

	Departamento (const Departamento & otro);

	/************************************************************************/
	// Destructor.

	~Departamento (void);


	/*************************************************************************/
	//----------------------------MÉTODOS------------------------------------//
	/*************************************************************************/
	// Métodos Get

	string GetId_Dpto (void) const;
	string GetNombre  (void) const;

	/************************************************************************/
	// Métodos Set

	void   SetId_Dpto (string el_id_depto = "");
	void   SetNombre  (string el_nombre = "");

	/***********************************************************************/
	// Sobrecarga del operador de asignación para copia profunda.
	// Parámetros: otro (referencia), objeto que sirve de modelo. 

	Departamento & operator = (const Departamento & otro);

	/***********************************************************************/
	// Serializa un dato "Departamento"

	string ToString (string cadena_inicial = "") const; 


private: 	
		   
	/*************************************************************************/
	//------------------------MÉTODOS PRIVADOS-------------------------------//
	/*************************************************************************/
	// Copiar datos desde otro objeto de la clase
	// Parámetros: otro (referencia), objeto que sirve de modelo. 
	//
	// PRE: Se ha reservado memoria para los datos

	void CopiarDatos (const Departamento & otro);

	/***********************************************************************/
	// Pide memoria para guardar una copia de los datos de "otro"
	// Parámetros: otro (referencia), objeto que sirve de modelo. 

	void ReservarMemoria (const Departamento & otro);


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
							char delimitador=DELIMITADOR_DEPARTAMENTO); 
	
};

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

#endif
