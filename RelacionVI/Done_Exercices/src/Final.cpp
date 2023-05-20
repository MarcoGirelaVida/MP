/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 6
//
// Programa que muestra las últimas líneas de un fichero de texto.
//
// Uso: Final <NumLineas> [<Fich>]
//			<NumLineas>	Número de líneas (máximo) que se muestran.
//			<Fich>		Fichero del que se van a mostrar las líneas. 
//						Es opcional: si no se indica ningún fichero 
//						se toman los datos de cin.
//
// Por ejemplo, la ejecución de: 
//		final 15 datos.txt
//
// mostrará las últimas 15 líneas del fichero "datos.txt". 
// Si el fichero tiene menos de 15 líneas, se mostrarán todas. 
//
// Las restricciones que se imponían a este programa son:
//	1)	El número de ficheros que se pueden proporcionar es ilimitado.
//	1)	Cada uno de los ficheros sólo puede ser leído una única vez, y 
//		no pueden copiarse completo en memoria. 
//	2)	Se desconoce a priori el número de líneas del fichero. 
//	3)	Las líneas del fichero tiene una longitud indeterminada, aunque 
//		nunca mayor de 500. 
//
// Fichero: Final.cpp
// 
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>

#include "Utils.h"

using namespace std;

/***************************************************************************/
/***************************************************************************/

void Tail  (istream & in, const int);

/***************************************************************************/
/***************************************************************************/

int main (int argc, char **argv)
{
	// Comprobar número y validez de argumentos  

	if ((argc < 2) || (argc > 3)) {
		cerr << "Error: Num. de params. erroneo\n";
		cerr << "Uso: " << argv[0]<< " <num_lineas> [<fich>]\n\n";
		exit (1);
	}

	int num_lineas_mostrar = atoi (argv[1]);
	if (num_lineas_mostrar <= 0) {
		cerr << "Error: El número de lineas debe ser >=0\n";
		exit (2);
	}

	if (argc == 2) {
		Tail (cin, num_lineas_mostrar);
	}
	else {

		// Comprobar si existe/puede abrirse el fichero 

		if (!ExisteFichero(argv[2])) {
			cerr << "\nError: no puedo abrir " << argv[2] << "\n\n";
			exit (3);
		}

		ifstream f (argv[2]);

		Tail (f, num_lineas_mostrar);

		f.close();
	}

	return (0);
}

/***************************************************************************/
/***************************************************************************/
// Construye un estructura de datos que guarda las últimas 
// "num_lineas_mostrar" leídas del flujo "in". 
// Finalmente llama a la función "PintaLineas()" para mostrarlas.  

void Tail (istream & in, const int num_lineas_mostrar)
{
	const int MAX = 500;
	char cad[MAX];		// Para leer cada una de las lineas

	// Declaracion y reserva de la estructura de datos que va a guardar las 
	// últimas líneas leídas. Se reserva y libera espacio para cada linea 
	// en el momento de su lectura y registro

	char ** ultimas = new char * [num_lineas_mostrar]; // vector de char *

	int primera, ultima;	// indices de la primera y ultima linea 
							// de las guardadas en "ultimas" 

	// Lectura de las primeras "num_lineas_mostrar" lineas

	int num_linea = 0;		// Numero de linea
	primera = ultima = 0;	// Iniciación de índices

	in.getline (cad, MAX); // Lectura adelantada

	while (!(in.eof()) && (num_linea < num_lineas_mostrar)) {

		ultimas[num_linea] = new char[strlen(cad) + 1];
		strcpy (ultimas[num_linea], cad);

		ultima = num_linea;
		num_linea++;	

		in.getline (cad, MAX); // Lectura de una nueva linea
	}


	// Se han leido un máximo de "num_lineas" límeas. 
	//	*	Si en "in" hubieran menos líneas, in.eof() sería TRUE.
	//  *	Si hubieran más líneas, la última lectura tuvo éxito y 
	//		esa línea debe pasar a ser la última y la primera debe 
	///		descartarse (la segunda ocupa su lugar). A continuación se 
	//		lee otra línea, y se sigue hasta agotar el flujo "in"

	while (!(in.eof())) {

		// Se ha podido leer una nueva linea (cad) que debe guardarse en
		// "ultimas" sustituyendo a la que estaba en la posicion siguiente
		// a la "ultima" (que es la "primera").
		// Se deben actualizar las posiciones "primera" y "ultima", que
		// seran las posiciones siguientes a las que tenian anteriormente
		// a la sustitucion.

		primera = (primera + 1) % num_lineas_mostrar;	// Posicion siguiente
		ultima = (ultima + 1) % num_lineas_mostrar;		// Posicion siguiente

		delete [] ultimas[ultima]; // Liberar la memoria de la antigua cadena

		ultimas[ultima] = new char[strlen(cad) + 1];  // Pedir memoria y
		strcpy (ultimas[ultima], cad);				  // copiar correctamente

		num_linea++;	

		in.getline (cad, MAX); // Lectura de una nueva linea
	}

	// Se acabó el flujo: mostrar el resultado

	for (int i = primera; i != ultima; i = ((i+1) % num_lineas_mostrar))
		cout << ultimas[i] << endl;

	cout << ultimas[ultima] << endl;		// Debe mostrarse la última
}

/***************************************************************************/
/***************************************************************************/
