/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 6
//
// Programa que compara dos ficheros de texto.
//
// Imprime el número de la primera linea en la que difieren y su contenido.
// Es muy similar a diff (GNU/Linux).
//
// Diferencias <fich1> <fich2>
//
//		<fich1>	Es el nombre de un fichero de texto (que ya existe).
//		<fich2>	Es el nombre de otro fichero de texto (que ya existe).
//
// Fichero: Diferencias.cpp
//
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>

#define CON_STRING

#ifdef CON_STRING
#include <string>
#else
#include <cstring>
#endif

using namespace std;

/***************************************************************************/
/***************************************************************************/

int main (int argc, char **argv)
{
	// Comprobar numero de argumentos  

	if (argc !=3) {
		cerr << "Error: Numero de argumentos incorrecto." << endl;
		cerr << "Formato: " << argv[0] << " <fich1> <fich2>" << endl;
		exit (1);
	}

	// Asociacion de flujos a ficheros

	ifstream fi1 (argv[1]);
	if (!fi1) {
		cerr << "Error: No pudo abrirse " << argv[1] << endl;
		exit (2);
	}
	ifstream fi2 (argv[2]);
	if (!fi2) {
		cerr << "Error: No pudo abrirse " << argv[2] << endl;
		exit (3);
	}

	#ifdef CON_STRING
	string cad1;		// para leer/escribir cada linea
	string cad2;		// para leer/escribir cada linea
	#else
	const int MAX=256;	// para leer/escribir cada linea
	char cad1[MAX];		// (version para cadena)
	char cad2[MAX];		// (version para cadena)
	#endif

	int cont = 0;	// numero de linea


	#ifdef CON_STRING
	getline (fi1,cad1);	// lectura adelantada (string)
	getline (fi2,cad2);	// lectura adelantada (string)
	#else
	fi1.getline (cad1, MAX);	// lectura adelantada (cadena)
	fi2.getline (cad2, MAX);	// lectura adelantada (cadena)
	#endif

	// Cuando "sigo" sea false (se ha encontrado una diferencia) se termina 
	// la lectura, ya no será preciso seguir comparando los dos ficheros.  

	bool sigo = true; 

	// Mientras queden líneas que procesar de los dos ficheros y no se haya 
	// encontrado una diferencia hasta el momento.

	while ((!fi1.eof()) && (!fi2.eof()) && sigo) {

		cont++;

		#ifdef CON_STRING
		if (cad1 != cad2) sigo = false;       // terminar
		#else
		if (strcmp(cad1, cad2)) sigo = false; // terminar
		#endif
		else {
			#ifdef CON_STRING
			getline (fi1,cad1);	// lectura adelantada (string)
			getline (fi2,cad2);	// lectura adelantada (string)
			#else
			fi1.getline (cad1, MAX);	// lectura adelantada (cadena C)
			fi2.getline (cad2, MAX);	// lectura adelantada (cadena C)
		  	#endif
		}
	}

	bool fin1_solo = ((fi1.eof()) && (!fi2.eof())); // solo fi1 finalizado
	bool fin2_solo = ((!fi1.eof()) && (fi2.eof())); // solo fi2 finalizado
	bool dif_longitud = (fin1_solo || fin2_solo); 

	// Si los ficheros son iguales se ha terminado su lectura al mismo tiempo.
	// En este caso, "fin1_solo" y "fin2_solo" son false (ambas), por lo que 
	// "dif_longitud" es false. 


	cout << endl; 

	if (!sigo) {
		cout << "Los ficheros son diferentes:" << endl;
		cout << "(" << setw(4) << cont << ") " << setw(20) << argv[1] 
			<< ": " << cad1 << endl;
		cout << "       " << setw(20) << argv[2] 
		    << ": " << cad2 << endl;
	}
	else // No se ha encontrado diferencias enter el contenido de los 
		 // ficheros, al menos hasta donde se ha podido comparar (es posible
		 // que uno de ellos, o los dos, se haya procesado completamente)

		if (dif_longitud){
			cout << "Los ficheros son diferentes: Fin prematuro de "; 
			if (fin1_solo) 
				cout << argv[1] << endl;
			else 
				cout << argv[2] << endl;
		} 
		else 
			cout << "Los ficheros son iguales." << endl;

	// finalizacion: cierre de flujos 

	fi1.close();
	fi2.close();

	return (0);
}

/***************************************************************************/
/***************************************************************************/
