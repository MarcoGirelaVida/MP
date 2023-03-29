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

#include "Funcs_ColeccionCadenas.h"

using namespace std;

/***************************************************************************/
/***************************************************************************/
// Crear colección de cadenas.
// Devuelve: el dato ColeccionCadenas creado (vacío).
// POST: El número de casillas usadas es 0.

ColeccionCadenas CreaColeccionCadenas (void)
{
	ColeccionCadenas nuevo; 

	nuevo.usados = 0;
	nuevo.lineas = nullptr;

	return (nuevo); 
}

/***************************************************************************/
/***************************************************************************/
// Inicializar colección de cadenas.
// Argumentos: 
// 		v (referencia), la colección de cadenas que se va a inicializar. 
// Devuelve: el dato ColeccionCadenas creado (vacío).
// POST: El número de casillas usadas es 0.

void InicializaColeccionCadenas (ColeccionCadenas & v)
{
	LiberaMemoriaColeccionCadenas (v);
}

/***************************************************************************/
/***************************************************************************/
// Calcula el número de casillas usadas de una colección de cadenas.
// Argumentos: v (referencia), la colección que se va a consultar.
// Devuelve: el número de casillas usadas de una colección de cadenas.

int CadenasEnColeccionCadenas  (const ColeccionCadenas & v)
{
	return (v.usados);
}

/***************************************************************************/
/***************************************************************************/
// Añade una cadena a una colección de cadenas.
// Argumentos: 	
//		v (referencia), referencia a la colección que se va a modificar. 
//		cadena, cadena que se va a añadir. 

void AniadeCadenaColeccionCadenas (ColeccionCadenas & v, char * cadena)
{
	// Reservar memoria para el nuevo "supervector" apuntado por "tmp" y 
	// copiar el contenido del antiguo (apuntado por v.lineas)

	int tam_actual = BytesColeccionCadenas  (v);	

	int nuevo_tam  = tam_actual + strlen(cadena) + 1;


	// El nuevo "supervector" tendrá capacidad para añadir "cadena"  

	char * tmp = new char[nuevo_tam]; 

	// Copiar el contenido actual
	memcpy (tmp, v.lineas, tam_actual);

	// Copiar al final de "tmp", a continuación del contenido que había 
	// anteriormente y que acaba de ser copiado, el contenido de "cadena"
	memcpy (tmp+tam_actual, cadena, strlen(cadena)+1); // +1 copia el '\0' 


	// Liberar el "supervector" (obsoleto) en v.lineas
	delete [] v.lineas;


	// Actualizar estructura de datos 
	
	v.lineas = tmp;	// Enlazar nuevo "supervector"
	v.usados++; 	// Actualizar el contador
}

/***************************************************************************/
/***************************************************************************/
// Obtiene una copia de una cadena. 
// Argumentos: 	
// 		cadena, dirección de memoria donde se copiará la cadena de interés.
//		v (referencia), referencia al vector que se va a consultar. 
//		indice, índice (número) de la cadena que se va a consultar. 
// PRE: 0 <= indice < CadenasEnColeccionCadenas(v)

void ExtraeCadenaColeccionCadenas (char * & cadena, 
	                               const ColeccionCadenas & v, int indice)
{ 
	char * cad = v.lineas; // "cad" está al principio de la primera cadena.
	
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

void CalculosLineasColeccionCadenas (const ColeccionCadenas & v, 
	                                 int & cl, int & cv, int & cp)
{
	// Número de líneas (trivial)

	cl = v.usados;


	char * cad; 

	// Número de líneas vacías

	cad = v.lineas; // Nos colocamos al principio

	cv = 0;

	for (int l=0; l<v.usados; l++) {

		int long_cad = strlen(cad);

		if (long_cad==0) cv++;

		// Actualizamos "cad" para que apunte a la siguiente cadena.

		cad = cad + long_cad + 1; // +1 por el '\0';
	}


	// Número de párrafos

	cad = v.lineas; // Nos colocamos al principio
	
	cp = 0;

	bool en_parrafo = false;

	for (int l=0; l<v.usados; l++) {

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

void MostrarColeccionCadenas (const ColeccionCadenas & v)
{
	cout << endl; 
	cout << "Usados    = " << v.usados << endl; 	
	cout << endl; 


	char * cad = v.lineas; // "cad" está al principio de la primera cadena.
	
	// Para cada cadena (v.usados)

	for (int l=0; l<v.usados; l++) {

		cout << "[" << setw(4) << l << "] " <<"|"<< cad <<"|"<< endl;

		// Actualizamos "cad" para que apunte a la siguiente cadena.

		cad = cad + strlen(cad)+1; // +1 por el '\0';

	}

	cout << endl; 
}

/***************************************************************************/
/***************************************************************************/
// Libera la memoria ocupada por la colección de cadenas.
// Argumentos: 	
//		v (referencia), colección de cadenas. 
// POST: lineas = 0 Y num_lineas = 0

void LiberaMemoriaColeccionCadenas (ColeccionCadenas & v)
{
	if (v.lineas) {
					
		delete [] v.lineas;

		v.usados = 0;
		v.lineas = nullptr; 
	}
}

/***************************************************************************/
/***************************************************************************/
// Calcula el número de bytes que ocupan las cadenas.
// Argumentos: 	
//		v (referencia), colección de cadenas. 

int BytesColeccionCadenas (const ColeccionCadenas & v)
{
	int num_bytes = 0;

	char * cad = v.lineas; // "cad" está al principio de la primera cadena.

	// Para cada cadena (v.usados)

	for (int l=0; l<v.usados; l++) {
		
		// Actualizo el número de bytes ocupados. Como "cad" apunta al 
		// inicio de una cadena, strlen(cad) devuelve el número de bytes 
		// (caracteres) de "cad". Se suma 1 por el '\0'.  

		num_bytes = num_bytes + strlen(cad)+1; // +1 por el '\0'.

		// Actualizamos "cad" para que apunte a la siguiente cadena.

		cad = v.lineas + num_bytes; 
	}

	return num_bytes; 
}


/***************************************************************************/
/***************************************************************************/
