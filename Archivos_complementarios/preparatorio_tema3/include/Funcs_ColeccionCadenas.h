/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 2
//	
// Declaración de las funciones para gestionar una colección de cadenas 
// clásicas que se almacenan consecutivamente en memoria.  
//
// Fichero: Funcs_ColeccionCadenas.h
// 
/***************************************************************************/

#ifndef FUNCS_COLECCIONCADENAS
#define FUNCS_COLECCIONCADENAS

/***************************************************************************/
/***************************************************************************/

typedef struct {

	char * lineas; 	// Puntero para acceder a los datos
	int usados;		// Num. casillas usadas

} ColeccionCadenas;

/***************************************************************************/
/***************************************************************************/
// Crear colección de cadenas.
// Devuelve: el dato ColeccionCadenas creado (vacío).
// POST: El número de casillas usadas es 0.

ColeccionCadenas CreaColeccionCadenas (void);

/***************************************************************************/
/***************************************************************************/
// Inicializar colección de cadenas.
// Argumentos: 
// 		v (referencia), la colección de cadenas que se va a inicializar. 
// Devuelve: el dato ColeccionCadenas creado (vacío).
// POST: El número de casillas usadas es 0.

void InicializaColeccionCadenas (ColeccionCadenas & v);

/***************************************************************************/
/***************************************************************************/
// Calcula el número de casillas usadas de una colección de cadenas.
// Argumentos: v (referencia), la colección que se va a consultar.
// Devuelve: el número de casillas usadas de una colección de cadenas.

int CadenasEnColeccionCadenas  (const ColeccionCadenas & v);

/***************************************************************************/
/***************************************************************************/
// Añade una cadena a una colección de cadenas.
// Argumentos: 	
//		v (referencia), referencia a la colección que se va a modificar. 
//		cadena, cadena que se va a añadir. 

void AniadeCadenaColeccionCadenas (ColeccionCadenas & v, char * cadena);

/***************************************************************************/
/***************************************************************************/
// Obtiene una copia de una cadena. 
// Argumentos: 	
// 		cadena, dirección de memoria donde se copiará la cadena de interés.
//		v (referencia), referencia al vector que se va a consultar. 
//		indice, índice (número) de la cadena que se va a consultar. 
// PRE: 0 <= indice < CadenasEnColeccionCadenas(v)

void ExtraeCadenaColeccionCadenas (char * & cadena, 
	                               const ColeccionCadenas & v, int indice);

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
	                                 int & cl, int & cv, int & cp);

/***************************************************************************/
/***************************************************************************/
// Mostrar contenido de la colección de cadenas.
// Argumentos: 	
//		v (referencia), colección de cadenas. 

void MostrarColeccionCadenas (const ColeccionCadenas & v);

/***************************************************************************/
/***************************************************************************/
// Libera la memoria ocupada por la colección de cadenas.
// Argumentos: 	
//		v (referencia), colección de cadenas. 
// POST: lineas = 0 Y num_lineas = 0

void LiberaMemoriaColeccionCadenas (ColeccionCadenas & v);

/***************************************************************************/
/***************************************************************************/
// Calcula el número de bytes que ocupan las cadenas.
// Argumentos: 	
//		v (referencia), colección de cadenas. 

int BytesColeccionCadenas (const ColeccionCadenas & v); 

/***************************************************************************/
/***************************************************************************/

#endif
