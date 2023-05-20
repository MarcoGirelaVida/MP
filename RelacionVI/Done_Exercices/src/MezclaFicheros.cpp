/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 6
// 
// Programa que recibe como parámetros tres nombres de ficheros de texto.
// Los dos primeros ficheros contienen números reales y están ordenados.
// El programa tomará los datos de esos ficheros y los irá copiando 
// ordenadamente en el tercer fichero. 
// Al finalizar el programa el último fichero está también ordenado.
//
// MezclaFicheros <fich1> <fich2> <fich3>
// 
//		<fich1>	Es el nombre de un fichero de texto (que ya existe).
//				Contiene números reales, separados por espacios, 
//				tabuladores y saltos de línea. 
//				Los valores están ordenados. 
//		<fich2>	Es el nombre de otro fichero de texto (que ya existe).
//				Contiene números reales, separados por espacios, 
//				tabuladores y saltos de línea. 
//				Los valores están ordenados. 
//		<fich3>	Es el nombre del fichero resultado.
//				Será un fichero de texto. 
//				Contendrá números reales, cada uno en una línea. 
//				Los valores están ordenados. 
//
// Fichero: MezclaFicheros.cpp
//
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;

/***************************************************************************/
/***************************************************************************/

int main (int argc, char **argv)
{
	
	// Comprobar numero de argumentos  

	if (argc != 4) {
		cerr << "Error: Numero de argumentos incorrecto." << endl;
		cerr << "Formato: " << argv[0] << " <fich1> <fich2> <fich3>" << endl;
		cerr << "   donde en <fich1> y <fich2> estan (ordenados) " << endl;
		cerr << "   los datos y <fich3> guardara el resultado." << endl;
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
	ofstream fo (argv[3]);
	if (!fo) {
		cerr << "Error: No pudo crearse " << argv[3] << endl;
		exit (4);
	}

	fo.setf (ios::showpoint);
	fo.setf (ios::fixed); 

	const int ANCHO = 9;
	const int DECS  = 4;

	double num1;	// para leer numeros de fi1
	double num2;	// para leer numeros de fi2

	int cont = 0;	// Contador de datos escritos

	fi1 >> num1;	// lectura adelantada 
	fi2 >> num2;	// lectura adelantada 

	// Procesar los dos ficheros de entrada mientras queden numeros 
	// en ambos ficheros. Cuando uno se agote, se procesará el otro. 

	while ( (!(fi1.eof())) && (!(fi2.eof())) ) {

		// Los dos ficheros contenian al menos un dato y fue posible  
		// leerlos (uno de cada fichero) en "num1" y "num2".

		// Calcular el menor y escribirlo en "fo"

		if (num1 < num2) { // escribir "num1"
			fo  << setw(ANCHO) << setprecision(DECS) << num1 << endl; 
			fi1 >> num1;	// leer el siguiente de "fi1"		 
		}
		else { // escribir "num2"
			fo  << setw(ANCHO) << setprecision(DECS) << num2 << endl;  
			fi2 >> num2;	// leer el siguiente de "fi2"
		}

		cont++; // Incrementar el contador de datos escritos

	} // while ( (!(fi1.eof())) && (!(fi2.eof())) )


	// Solo quedan datos en uno de los dos ficheros: 
	// copiar los que quedan, tal cual están, en el resultado. 

	if (fi1.eof()) // Se terminó "fi1" --> leer de "fi2" y copiar 
		while ( !(fi2.eof()) ) {
			fo  << setw(ANCHO) << setprecision(DECS) << num2 << endl; 
			cont++;
			fi2 >> num2;	// leer el siguiente de "fi2"
		}
	else // fi2.eof() --> leer de "fi1" y copiar 
		while ( !(fi1.eof()) ) {
			fo  << setw(ANCHO) << setprecision(DECS) << num1 << endl;
			cont++;
			fi1 >> num1;	// leer el siguiente de "fi1"
		}

		cout << "\nEscritos " << cont << " datos en: " << argv[3] << endl;
		cout << endl;

	// finalizacion: cierre de flujos 

	fi1.close();
	fi2.close();
	fo.close();

	return (0);
}

/***************************************************************************/
/***************************************************************************/
