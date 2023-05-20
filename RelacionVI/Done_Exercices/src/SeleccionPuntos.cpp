/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 5
//
// Fichero: SeleccionPuntos.cpp
//
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>

#include "Punto2D.h"
#include "SecuenciaPunto2D.h"

using namespace std;

/***************************************************************************/
/***************************************************************************/

int main (int argc, char **argv)
{
	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 
	cerr.setf(ios::fixed);		// Notación de punto fijo para los reales
	cerr.setf(ios::showpoint);	// Mostrar siempre decimales 

	char dimension;  
	int valor_umbral;

	//.......................................................................
	// Comprobación de argumentos

	// Número de argumentos
	if (argc != 3) {
		cerr << endl; 
		cerr << "Error: numero incorrecto de argumentos." << endl; 
		cerr << "Formato: " << argv[0] << " <x|y> <valor>" << endl; 		
		cerr << endl;
		exit (1);  
	} 

	// validez de argv[1] (dimension) 
	bool error_argv1 = false; 

	if (strlen(argv[1]) != 1) error_argv1 = true; 
	else {
		dimension = toupper(argv[1][0]); 
		if (dimension != 'X' && dimension != 'Y') error_argv1 = true; 
	}
	if (error_argv1) {
		cerr << endl; 
		cerr << "Error: el primer argumento debe ser X|x|Y|y." << endl; 
		cerr << endl;
		exit (2);  
	}

	// validez de argv[2] (valor) 

	istringstream flujo_int (argv[2]); 

	flujo_int >> valor_umbral;

	if (flujo_int.fail()) {
		cerr << endl; 
		cerr << "Error: el segundo argumento debe ser un numero entero." << endl; 
		cerr << endl;
		exit (3);  
	}


	cerr << endl; 
	cerr << "Seleccionando los puntos con coordenada " << dimension 
	     << " mayor que " << setw(3) << valor_umbral << endl; 
	cerr << endl; 


	//.......................................................................
	// Procesar puntos 

	SecuenciaPunto2D leidos;

	// "Leer" secuencia
	cin >> leidos; 


	int num_leidos = leidos.TotalUtilizados(); // Tamaño de la secuencia

	// Mostrar Secuencia leida 

	cerr << endl; 
	cerr << "Se han leido " << setw(3) << num_leidos << " puntos." << endl; 
	cerr << endl;  	     
	cerr << "Puntos leidos: " << leidos.ToString() << endl; 
	cerr << endl;  

	// Procesar cad apunto de la secuencia 

	SecuenciaPunto2D seleccion;

	for (int pos=1; pos<=num_leidos; pos++) {

		Punto2D punto_pos = leidos[pos];

		if ((dimension=='X' && punto_pos.GetX() >= valor_umbral) || 
			(dimension=='Y' && punto_pos.GetY() >= valor_umbral))
	
			seleccion.Aniade(punto_pos);
	}

	//.......................................................................
	// "Escribir" secuencia
	
	cout << seleccion << endl; 
	

	return 0; 
}

/***************************************************************************/
/***************************************************************************/
