/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 6
//
// Programa que crea un fichero a partir de otro, copiando su contenido
// y añadiendo al principio de cada línea, su número.
// Recibe los nombres de dos ficheros de texto de la línea de órdenes.
//
// NumeraLineas <fich_in> <fich_out>
//
//		<fich_in>	Es el nombre de un fichero de texto (que ya existe).
//		<fich_out>	Es el nombre del fichero de texto que se va a crear.
//
// Fichero: NumeraLineas.cpp
//
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

/***************************************************************************/
/***************************************************************************/

int main (int argc, char **argv)
{
	// Comprobar numero de argumentos  

	if (argc !=3) {
		cerr << "Error: Numero de argumentos incorrecto." << endl;
		cerr << "Formato: " << argv[0] << " <fich_in> <fich_out>" << endl;
		exit (1);
	}

	// Asociacion de flujos a ficheros

	ifstream fi (argv[1]);
	if (!fi) {
		cerr << "Error: No pudo abrirse " << argv[1] << endl;
		exit (2);
	}
	ofstream fo (argv[2]);
	if (!fo) {
		cerr << "Error: No pudo crearse " << argv[2] << endl;
		exit (3);
	}

	// INICIO de la zona específica. Solución usando string 

	string cad;		// para leer/escribir cada linea
	int cont = 0;	// numero de linea


	getline (fi,cad);	// lectura adelantada (string)

	while (!fi.eof()) {

		// Escribe en "fo" num.linea + cadena (string)
		fo << setw(4) << ++cont << "  " << cad << endl;

		getline (fi,cad);	// nueva lectura (string)
	}

	// FIN de la zona específica. Solución usando string 

	// finalizacion: cierre de flujos 

	fo.close();
	fi.close();

	return 0;

/* 
	// Solución alternativa, usando cadenas "clásicas" estilo C.

	// INICIO de la zona específica. Solución usando cadenas "C"

	const int MAX=256;	// para leer/escribir cada linea
	char cad[MAX];		// (version para cadena C)

	int cont = 0;	// numero de linea

	fi.getline (cad, MAX);	// lectura adelantada (cadena C)

	while (!fi.eof()) {

		// Escribe en "fo" num.linea + cadena (cadena C)
		fo << setw(4) << ++cont << "  " << cad << endl;

		fi.getline(cad, MAX);	// nueva lectura (cadena C)
	}

	// FIN de la zona específica. Solución usando cadenas "C"
*/
}

/***************************************************************************/
/***************************************************************************/
