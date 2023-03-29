/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 2
//
// Fichero: II_DemoColeccionCadenas.cpp
//
/*	
	Programa que lee una secuencia indeterminada de cadenas de caracteres 
	(termina al encontrar en la lectura el fin de fichero) y las guarda en 
	memoria (incluidas las líneas vacías) en un array de caracteres, 
	una cadena tras otra, consecutivamente. Se guardan los terminadores '\0'.

	Cada vez que se lee una nueva cadena, se añade a la estructura dinámica 
	(redimensión básica, se reserva el espacio mínimo preciso, se pide memoria 
	para los caracteres ya guardados más los de la cadena nueva), que se 
	guarda a continuación de que ocupaba la última posición.

	El programa mostrará el número total de líneas, líneas no vacías y 
	párrafos. Finalmente calculará cual es la cadena más larga entre todas 
	las guardadas.
*/
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>

#include "Funcs_ColeccionCadenas.h"

using namespace std;

/***************************************************************************/
/***************************************************************************/

int main()
{
	//.......................................................................
	// En "v" se guardarán las cadenas leidas. 

	ColeccionCadenas v = CreaColeccionCadenas ();


	//.......................................................................
	// Rellenar "v": se termina al encontrar EOF en cin 

	string cadena; // Para leer cada una de las cadenas 

	while (getline (cin, cadena)) {

		
		// Reservar memoria para la cadena clásica. 
		// Se necesita un carácter más que la longitud de "cadena". 
		// La longitud de "cadena" se calcula con el método "length" de string

		int long_cadena = cadena.length();
		char * cadena_nueva = new char [long_cadena+1];


		// VERSIÓN 1 (nivel: principiante)
		/*
			1) Copiar carácter a carácter desde el string a la cadena clásica
			2) Añadir el '\0'
		*/

		// 1. Copiar carácter a carácter desde el string a la cadena clásica
		for (int pos=0; pos<long_cadena; pos++) 
			cadena_nueva[pos] = cadena.at(pos);	

		// 2. Añadir el '\0'
		cadena_nueva[long_cadena] = '\0';


		// VERSIÓN 2 (nivel: experto)
		/*
			Usar el método c_str() de la clase string para obtener una 
			cadena clásica desde un dato string (por supuesto con el '\0')

			Por ejemplo, la línea 
				cout << "|" << cadena.c_str() << "|" << endl; 
			envía a cout el resultado de la conversión (entre barras)
		
			En este problema bastaría con escribir la instrucción: 

			strcpy(cadena_nueva, cadena.c_str());	
		*/

		// "cadena_nueva" nos lleva a una zona del Heap reservada e 
		// inicializada correctamente. Pasamos esa dirección a la función 
		// "AniadeVectorDinamico" para que añada la nueva cadena a "v".

		AniadeCadenaColeccionCadenas (v, cadena_nueva); 

		MostrarColeccionCadenas (v);

		delete [] cadena_nueva;

	} // while


	//.......................................................................
	// Mostrar ocupación y contenido de "v" 

	cout << endl;
	cout << "Casillas usadas = " << CadenasEnColeccionCadenas(v) << endl;  
	cout << endl; 

	//.......................................................................
	// Mostrar contenido de "v"

	MostrarColeccionCadenas (v); 

	//.......................................................................
	// Cálculos sobre "lineas"

	int n_lineas, n_vacias, n_parrafos;

	CalculosLineasColeccionCadenas (v, n_lineas, n_vacias, n_parrafos);

	//.......................................................................
	// Mostrar resultados

	cout << endl; 
	cout << "CALCULOS SOBRE LAS LINEAS LEIDAS" << endl; 
	cout << endl;

	cout << "Num. total lineas  = " << setw(3) << n_lineas << endl;
	cout << "Num. lineas vacias = " << setw(3) << n_vacias << endl;
	cout << "Num. parrafos      = " << setw(3) << n_parrafos << endl;
	cout << endl;

	//.......................................................................
	// Procesar el contenido de "v" (calcular la cadena más larga)

	int num_cadenas = CadenasEnColeccionCadenas(v);

	if (num_cadenas > 0) {

		cout << endl; 
		cout << "Calculando la mayor cadena de las " 
		     << setw(3) << num_cadenas << " guardadas" << endl; 
		cout << endl; 

		char * una_cadena; 

		// La primera cadena será la primera mayor

		ExtraeCadenaColeccionCadenas (una_cadena, v, 0);

		int pos_cadena_mayor = 0; 
		int long_cadena_mayor = strlen(una_cadena);

		delete [] una_cadena;


		// Procesar el resto de las cadenas

		for (int n=1; n<num_cadenas; n++) {

			ExtraeCadenaColeccionCadenas (una_cadena, v, n);

			int long_una_cadena = strlen(una_cadena);

			// Si procede, actualizar los datos de la cadena mayor

			if (long_una_cadena > long_cadena_mayor) {
				pos_cadena_mayor = n; 
				long_cadena_mayor = long_una_cadena;
			}

			delete [] una_cadena;			
		}

		// Nos quedamos con la mayor cadena (su posición es "pos_cadena_mayor")

		ExtraeCadenaColeccionCadenas (una_cadena, v, pos_cadena_mayor);

		cout << endl; 
		cout << "Posicion de la mayor cadena = " 
		     << setw(3) << pos_cadena_mayor << endl; 
		cout << "Contenido:  " << una_cadena << endl; 
		cout << "Longitud =  " << strlen(una_cadena) << endl; 
		cout << endl; 

		delete [] una_cadena;			
	}
	else {
		cout << endl; 
		cout << "No hay cadenas guardadas." << endl; 	
		cout << endl; 
	}

	//......................................................................
	// Liberar la memoria ocupada por "lineas"

	cout << endl;
	cout << "Liberando memoria .... " ;

	LiberaMemoriaColeccionCadenas (v); 

	cout << "Memoria liberada";
	cout << endl;

	//.......................................................................

	return 0;
}

/***************************************************************************/
/***************************************************************************/