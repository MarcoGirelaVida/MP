/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// 
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 6
//
// Programa que busca una cadena en una serie de ficheros de texto.
// La cadena a buscar y los ficheros en los que buscar se proporcionan
// en la línea de órdenes.
//
// Uso: Busca <Palabra> <Fich1> [<Fich2>...<Fichn>]
//			<Palabra>	Palabra a buscar en los ficheros.
//			<Fich1>...	Son los nombres de los ficheros donde se 
//						va a buscar <Palabra>.
//						<Fich2>...<Fichn> son opcionales.
// Cada vez que encuentre la cadena buscada, debe indicar el fichero
// en el que es localizada, el número de línea, y la línea completa 
// que la contiene. 
//
// Por ejemplo, la ejecución de:
//		Busca Olga fich1 fich2 fich3.
//
// busca la cadena "Olga" en los ficheros llamados "fich1",
// "fich2" y "fich3". Un ejemplo de salida de este programa es:
//		fich1 (línea 33): Mi amiga Olga ha aprobado MP aunque no se
//		fich3 (línea 2): ya se lo dije ayer a Olga, pero ni caso
//		fich3 (línea 242): finalmente, Olga se puso a estudiar
//
// Las restricciones que se imponían a este programa son:
//	1)	El número de ficheros que se pueden proporcionar es ilimitado.
//	1)	Cada uno de los ficheros sólo puede ser leído una única vez, y 
//		no pueden copiarse completo en memoria. 
//	2)	Se desconoce a priori el número de líneas del fichero. 
//	3)	Las líneas del fichero tiene una longitud indeterminada, aunque 
//		nunca mayor de 500. 
//
// Fichero: Busca.cpp
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

int	Busca (const char *nombre_fich, const char * palabra);

/***************************************************************************/
/***************************************************************************/

int main (int argc, char **argv)
{
	// Comprobar numero de argumentos  

	if (argc < 3) {
		cerr << "Error: Num. de params. erroneo\n";
		cerr << "Uso: " << argv[0]<< " <Palabra> <Fich1> ";
		cerr << "[<Fich2>...<Fichn>]\n\n";
		exit (1);
	}

	// Para cada uno de los ficheros cuyo nombre se suministra en 
	// la línea de órdenes:  

	for (int i=2; i<=argc-1; i++) {

		// Comprobar si existe/puede abrirse el fichero actual

		if (!ExisteFichero(argv[i])) {

			cerr << "\nError: no puedo abrir " << argv[i] << "\n\n";
			// El programa no detiene su ejecucion: continua con el 
			// siguiente fichero de la lista proporcionada.
		}
		else {

			int num_apariciones = Busca (argv[i], argv[1]);
			cout << "--> Se localizaron " << setw (3) << num_apariciones  
				 << " apariciones de |" << argv[1] << " | en el fichero " 
				 << argv[i] << endl;
		} 

	} // for (int i=2; i<=argc-1; i++) 

	return 0;
}

/***************************************************************************/
/***************************************************************************/

int	Busca (const char *nombre_fich, const char * palabra)
{
	const int MAX = 500;
	char cad[MAX];		// Para leer cada una de las lineas

	int num_linea = 0;	// Numero de linea
	int num_veces = 0;	// Numero de apariciones

	ifstream f;				// Se supone que se ha comprobado la existencia 
	f.open (nombre_fich);	// y disponibilidad del fichero

	f.getline (cad, MAX); // Lectura adelantada

	while (!(f.eof())) {

		num_linea++;	

		if (strstr(cad, palabra)) {	 // "palabra" esta en "cad"

			num_veces++;

			cout << setw (10) << nombre_fich << " (linea " << setw (3) 
				 << num_linea << "): " << cad << endl;
		}

		f.getline (cad, MAX); // Lectura de una nueva linea

	} //while (!(f.eof())) 

	f.close();

	return (num_veces);
}

/***************************************************************************/
/***************************************************************************/
