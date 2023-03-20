/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// MARCO GIRELA VIDA
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
		if (*cad1 == *cad2)
		{
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
	bool esvalida = true;
	int lc2 = longitud_cadena(c2)+1;
	
	if(c1 >= c2 - lc2 || c1 <= c2 + lc2)
	{
		esvalida = false;
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

	const char * po = orig;
	
	for (char * pd = dest; po <= orig+longitud_cadena(orig); po++, pd++)
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

char * inviertir_cadena (char * dest, const char * orig)
{
	for (const char*po=orig+longitud_cadena(orig)-1; po >= orig; po--, dest++)
	{
		*dest = *po;
	}

	*(dest) = '\0';
	
	return (dest - longitud_cadena(orig));
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
	char resultado[50]; // Reservo suficiente espacio para guardar la invertido
	bool espalindromo = false;

	inviertir_cadena(resultado,inic); // Invierto inic y la guardo en resultado

	if (!compara_cadenas(resultado, inic)) // Si da 0 son iguales->Espalindromo
	{
		espalindromo = true;
	}
	
	return espalindromo;
}

/***************************************************************************/
/***************************************************************************/
// Encuentra palabras
// Recibe:
//			El inicio de una cadena de caracteres
// Devuelve:
//			El número de palabras contenidas en esa cadena de caraceteres
//			Almacena en la cadena las inciales de cada palabra.
//		
// Nota: Tras más de 2 horas intentando arreglar una cosa me he dado por
// vencido, por lo que he tenido que hacer una "chapuza" para que funcione
// correctamente. Si me toca defender mi proyecto pongo esta nota como 
// recordatorio para preguntarle al respecto y explicarle la situción.

int encuentra_palabras (char ** palabras, char * cadena)
{
	int num_palabras = 0;
	char * fin_cadena = &(*cadena) + longitud_cadena(cadena); // incluye el \0
	char ** inicio_palabras = &(*palabras); // guardo el inicio del array palabras

	// Pongo un if para la primera palabra, que no necesariamente
	// está precedida por un espacio.
	if (*(cadena) != ' ')
	{
		*(palabras) = &(*cadena);
		*(palabras)++;
		num_palabras++;
		cadena++;
	}
	
	// Pongo un while que va identificando cada palabra.
	// Para ello busco espacios y compruebo que en el caracter sucesivo
	// hay un caracter (no hay un espacio), si es así, es que hay una palabra.

	// Nótese que resto 1 al fin_cadena.
	// El primero para quitar el \0 y el segundo porque
	// si hay un espacio en el último término del array es imposible
	// que haya una palabra detrás.
	while (cadena < fin_cadena - 1 && num_palabras <= 20)
	{
		if (*(cadena) == ' ' && *(cadena+1) != ' ')
		{
			*(palabras) = cadena+1;
			palabras++;
			num_palabras++;
		}
		cadena++;
	}

	// Devuelvo los punteros "cadena" y "palabras" a su inicio.
	// cadena = &(*cadena) - (&(*fin_cadena) - 1);
	palabras = &(*inicio_palabras);

	return num_palabras;
}
