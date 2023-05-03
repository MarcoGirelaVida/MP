/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 2
//
// Definición de las funciones para gestionar una colección de cadenas 
// clásicas que se almacenan consecutivamente en memoria. 
//  
// Fichero: Funcs_ColeccionCadenas.cpp
//
/***************************************************************************/

#include <iostream> 
#include <iomanip> 
#include <cstring>

#include "ColeccionCadenas.h"

using namespace std;

/***************************************************************************/
/***************************************************************************/
// Constructor sin argumentos

ColeccionCadenas :: ColeccionCadenas (void) : usados(0), lineas(nullptr)
{}

/***************************************************************************/
/***************************************************************************/
// Constructor de copia

ColeccionCadenas :: ColeccionCadenas (ColeccionCadenas & v) : usados(0), lineas(nullptr)
{
	LiberaMemoria ();

	for (int i = 0; i < v.CadenasEnColeccionCadenas(); i++)
	{
		char * tmp = nullptr;
		v.ExtraeCadena(tmp, i);
		AniadeCadena(tmp);
	}
	
}

/***************************************************************************/
/***************************************************************************/
// Destructor
ColeccionCadenas :: ColeccionCadenas()
{
	LiberaMemoria();
}

/***************************************************************************/
/***************************************************************************/
// Calcula el número de casillas usadas de una colección de cadenas.
// Argumentos: v (referencia), la colección que se va a consultar.
// Devuelve: el número de casillas usadas de una colección de cadenas.

int ColeccionCadenas :: CadenasEnColeccionCadenas  () const
{
	return (usados);
}

/***************************************************************************/
/***************************************************************************/
// Añade una cadena a una colección de cadenas.
// Argumentos: 	
//		v (referencia), referencia a la colección que se va a modificar. 
//		cadena, cadena que se va a añadir. 

void ColeccionCadenas :: AniadeCadena (char * cadena)
{
	// Reservar memoria para el nuevo "supervector" apuntado por "tmp" y 
	// copiar el contenido del antiguo (apuntado por lineas)

	int tam_actual = Bytes();	

	int nuevo_tam  = tam_actual + strlen(cadena) + 1;


	// El nuevo "supervector" tendrá capacidad para añadir "cadena"  

	char * tmp = new char[nuevo_tam]; 

	// Copiar el contenido actual
	memcpy (tmp, lineas, tam_actual);

	// Copiar al final de "tmp", a continuación del contenido que había 
	// anteriormente y que acaba de ser copiado, el contenido de "cadena"
	memcpy (tmp+tam_actual, cadena, strlen(cadena)+1); // +1 copia el '\0' 


	// Liberar el "supervector" (obsoleto) en lineas
	delete [] lineas;


	// Actualizar estructura de datos 
	
	lineas = tmp;	// Enlazar nuevo "supervector"
	usados++; 	// Actualizar el contador
}

/***************************************************************************/
/***************************************************************************/
// Obtiene una copia de una cadena. 
// Argumentos: 	
// 		cadena, dirección de memoria donde se copiará la cadena de interés.
//		v (referencia), referencia al vector que se va a consultar. 
//		indice, índice (número) de la cadena que se va a consultar. 
// PRE: 0 <= indice < CadenasEnColeccionCadenas(v)

void ColeccionCadenas :: ExtraeCadena (char * & cadena, int indice) const
{ 
	char * cad = lineas; // "cad" está al principio de la primera cadena.
	
	// Saltar cadenas anteriores a la de la posición "indice"

	for (int pos=0; pos<indice; pos++) {

		// Actualizamos "cad" para que apunte a la siguiente cadena.
		cad = cad + strlen(cad)+1; // +1 por el '\0';
	}


	// Reservar memoria y copiar en ella el contenido de la cadena 
	// La petición se realiza a traves d ela referencia "cadena"

	cadena = new char[strlen(cad)+1]; 
	memcpy (cadena, cad, strlen(cad)+1);
}

/***************************************************************************/
/***************************************************************************/
// Calcula el número de líneas totales y vacías, además del número de 
// párrafos en "lineas".
// Argumentos: 	
//		v (referencia),  colección de cadenas donde se consulta.  
//		cl (referencia), número de líneas. 
//		cv (referencia), número de líneas vacías.
//		cp (referencia), número de párrafos.

void ColeccionCadenas :: CalculosLineas (int & cl, int & cv, int & cp) const
{
	// Número de líneas (trivial)

	cl = usados;


	char * cad; 

	// Número de líneas vacías

	cad = lineas; // Nos colocamos al principio

	cv = 0;

	for (int l=0; l<usados; l++) {

		int long_cad = strlen(cad);

		if (long_cad==0) cv++;

		// Actualizamos "cad" para que apunte a la siguiente cadena.

		cad = cad + long_cad + 1; // +1 por el '\0';
	}


	// Número de párrafos

	cad = lineas; // Nos colocamos al principio
	
	cp = 0;

	bool en_parrafo = false;

	for (int l=0; l<usados; l++) {

		int long_cad = strlen(cad);

		if (long_cad==0 && en_parrafo) // fin de párrafo
			en_parrafo = false;	
	
		if (long_cad!=0 && !en_parrafo) { // nuevo párrafo
			en_parrafo = true;
			cp++;
		}

		cad = cad + long_cad + 1; // +1 por el '\0';
	}

}

/***************************************************************************/
/***************************************************************************/
// Mostrar contenido de la colección de cadenas.
// Argumentos: 	
//		v (referencia), colección de cadenas. 

void ColeccionCadenas :: Mostrar () const
{
	cout << endl; 
	cout << "Usados    = " << usados << endl; 	
	cout << endl; 


	char * cad = lineas; // "cad" está al principio de la primera cadena.
	
	// Para cada cadena (usados)

	for (int l=0; l<usados; l++) {

		cout << "[" << setw(4) << l << "] " <<"|"<< cad <<"|"<< endl;

		// Actualizamos "cad" para que apunte a la siguiente cadena.

		cad = cad + strlen(cad)+1; // +1 por el '\0';

	}

	cout << endl; 
}


/***************************************************************************/
/***************************************************************************/
// Calcula el número de bytes que ocupan las cadenas.
// Argumentos: 	
//		v (referencia), colección de cadenas. 

int ColeccionCadenas :: Bytes () const
{
	int num_bytes = 0;

	char * cad = lineas; // "cad" está al principio de la primera cadena.

	// Para cada cadena (usados)

	for (int l=0; l<usados; l++) {
		
		// Actualizo el número de bytes ocupados. Como "cad" apunta al 
		// inicio de una cadena, strlen(cad) devuelve el número de bytes 
		// (caracteres) de "cad". Se suma 1 por el '\0'.  

		num_bytes = num_bytes + strlen(cad)+1; // +1 por el '\0'.

		// Actualizamos "cad" para que apunte a la siguiente cadena.

		cad = lineas + num_bytes; 
	}

	return num_bytes; 
}

/***************************************************************************/
/***************************************************************************/
// Libera la memoria ocupada por la colección de cadenas.
// Argumentos: 	
//		v (referencia), colección de cadenas. 
// POST: lineas = 0 Y num_lineas = 0

void ColeccionCadenas :: LiberaMemoria ()
{
	if (lineas) {
					
		delete [] lineas;

		usados = 0;
		lineas = nullptr; 
	}
}

/***************************************************************************/
/***************************************************************************/
