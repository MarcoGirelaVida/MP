/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// MARCO GIRELA VIDA
//
// RELACION DE PROBLEMAS 1
//
// Declaraciones de funciones que gestionan cadenas cl�sicas de manera similar 
// a las funciones de cstring 
// Definiciones en: MiCadenaClasica.cpp	
//
// Fichero: MiCadenaClasica.h
// 
/***************************************************************************/
/***************************************************************************/

#ifndef MI_CADENA_CLASICA
#define MI_CADENA_CLASICA

/*
PROTOTIPOS DE LAS FUNCIONES: 

int  longitud_cadena (const char *cadena);
int  comparar_cadenas (const char *cad1, const char *cad2);
bool es_palindromo (const char *cadena);
bool es_palindromo_rec (const char *cadena, int izda, int dcha);
char * copiar_cadena (char *copia, const char *original);
char * encadenar_cadena (char *resultado, const char *otra);
char * extraer_cadena (char *sub, const char * cadena, int p, int l);

char * inviertir_cadena (char *cad_invertida, const char * cadena);
 
*/

/***************************************************************************/
/***************************************************************************/
// Longitud de una cadena. 
// Par�metros: 
//		cadena, puntero a la cadena (direcci�n del primer car�cter)
// Devuelve:
//		N�mero de caracteres de la cadena 

int longitud_cadena (const char *cadena);


/***************************************************************************/
/***************************************************************************/
// Compara dos cadenas
// Recibe: 
//		cad1 y cad2, punteros a las cadenas que se van a comparar
//			(direcci�n del primer car�cter de cada una de ellas)
// Devuelve:
//		0, si las dos cadenas son iguales
//		un valor positivo, si cad1 > cad2
//		un valor negativo, si cad1 < cad2

int compara_cadenas (const char *cad1, const char *cad2);

/***************************************************************************/
/***************************************************************************/
// Determina si una cadena es válida con respcto a otra
// Recibe:
//			c1: El inicio de la cadena movil
//			c2: El inicio de la cadena base
// Devuelve:
//			true si es una direccion valida
//			false si es una direccion invalida

bool es_valida( const char * c1, const char * c2);

/***************************************************************************/
/***************************************************************************/
// Copia dos cadenas
// Recibe: 
//		puntero al inicio de la cadena dentino
//		puntero al inicio de la cadena origen
// Devuelve:
//		puntero al inicio de la cadena destino

char * copiar_cadena( char * dest, const char * orig);

/***************************************************************************/
/***************************************************************************/
// Copia e invierte una cadena en un origen dado
// Recibe: 
//		Un puntero a donde queremos guardar la cadena invertida
//		Un puntero a la cadena que queremos invertir
// Devuelve:
//		Un puntero al inicio de la cadena invertida

char * inviertir_cadena (char * dest, const char * orig);

/***************************************************************************/
/***************************************************************************/
// Determina si una cadena es un palíndromo.
// Recibe:
//			El inicio de una cadena de caracteres
// Devuelve:
//			true si es un palíndromo
//			false si no lo es

bool es_palindromo( const char * inic);

/***************************************************************************/
/***************************************************************************/
// Encuentra palabras
// Recibe:
//			El inicio de una cadena de caracteres
// Devuelve:
//			El número de palabras contenidas en esa cadena de caraceteres
//			Almacena en la cadena las inciales de cada palabra.
//			

int encuentra_palabras (char ** palabras, char * cadena);

#endif
