/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 1
//
// Definiciones de funciones que gestionan cadenas cl�sicas de manera similar 
// a las funciones de cstring.  
// Declaraciones en: MiCadenaClasica.h	
//
// Fichero: MiCadenaClasica.cpp
//
/***************************************************************************/
/***************************************************************************/

#include "MiCadenaClasica.h"
#include <cctype>

using namespace std;

/***************************************************************************/
/***************************************************************************/
// Longitud de una cadena. 
// Par�metros: 
//		cadena, puntero a la cadena (direcci�n del primer car�cter)
// Devuelve:
//		N�mero de caracteres de la cadena 

int longitud_cadena (const char *cadena)
{
	const char *p;
	for (p=cadena; *p != '\0'; p++); // Buuscar el car�cter '\0'
	
	return (p-cadena);
}


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

int compara_cadenas (const char *cad1, const char *cad2)
{
	bool sigo = true; 

	while ((sigo) && (*cad1 != '\0') && (*cad2 != '\0')) 
		if (*cad1 == *cad2) {
			cad1++;
			cad2++;
		} 
		else sigo = false; 

	return (*cad1 - *cad2); 
}

/***************************************************************************/
/***************************************************************************/
// Determina si una cadena es válida con respcto a otra
// Recibe:
//			c1: El inicio de la cadena movil
//			c2: El inicio de la cadena base
// Devuelve:
//			true si es una direccion valida
//			false si es una direccion invalida

bool es_valida( const char * c1, const char * c2)
{
	bool esvalida = true
	int lc2 = longitud_cadena(c2) + 1
	
	if (c1 >= c2 - lc2 || c1 <= c2 + lc2)
	{
		esvalida = false
	}
	
	return esvalida;
}

/***************************************************************************/
/***************************************************************************/
// Copia dos cadenas
// Recibe: 
//		puntero al inicio de la cadena dentino
//		puntero al inicio de la cadena origen
// Devuelve:
//		puntero al inicio de la cadena destino

char * copiar_cadena( char * dest, const char * orig)
{
		if(!es_valida(dest, orig))
	{
		exit(1);
	}

	const char * po = orig;
	char * pd = dest;
	for (po <= orig+longitud_cadena(orig)+1; po++, pd++)
	{
		*pd = *po;
	}
	
	return dest;
}

/***************************************************************************/
/***************************************************************************/
// Copia e invierte una cadena en un origen dado
// Recibe: 
//		Un puntero a donde queremos guardar la cadena invertida
//		Un puntero a la cadena que queremos invertir
// Devuelve:
//		Un puntero al inicio de la cadena invertida

char * inviertir_cadena (char * dest, const char * orig);
{
	if(!es_valida(dest, orig))
	{
		exit(1);
	}

	const char * po = orig + longitud_cadena(orig) + 1;
	char * pd = dest;

	for (po >= orig; po--, pd++)
	{
		*pd = *po;
	}
	
	return resultado;
}

/***************************************************************************/
/***************************************************************************/
// Determina si una cadena es un palíndromo.
// Recibe:
//			El inicio de una cadena de caracteres
// Devuelve:
//			true si es un palíndromo
//			false si no lo es

bool es_palindromo( const char * inic)
{
	bool espalindromo = false;
	const char * cadena_invertida;
	cadena_invertida = inviertir_cadena(inic+longitud_cadena(inic)+1,inic);

	if (!compara_cadenas(cadena_invertida, inic))
	{
		espalindromo = true;
	}
	
	return espalindromo;
}

/***************************************************************************/
/***************************************************************************/
// Encuentra 
// Recibe:
//			El inicio de una cadena de caracteres
// Devuelve:
//			true si es un palíndromo
//			false si no lo es

int encuentra_palabras (char ** palabras, const char * cadena);
{

}
