/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 5
//
// Fichero: PuntoMedio.cpp
//
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>

#include "Punto2D.h"
#include "SecuenciaPunto2D.h"

using namespace std;

/***************************************************************************/
/***************************************************************************/

int main (void)
{

	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales 

	//.......................................................................


	SecuenciaPunto2D leidos;

	// "Leer" secuencia
	cin >> leidos; 

	// "Escribir" secuencia
	cout << leidos << endl; 
	

	/*
	// Si se "lee"/"escribe" punto a punto

	Punto2D punto_leido;	
	while (cin >> punto_leido) 
		leidos.Aniade (punto_leido);

	for (int pos=1; pos<=leidos.TotalUtilizados(); pos++) 
		cout << leidos[pos] << endl;
	

	*/
	// Tamaño de la secuencia

	int num_leidos = leidos.TotalUtilizados(); 


	// Mostrar Secuencia

	cerr << endl; 
	cerr << "Se han leido " << setw(3) << num_leidos << " puntos." << endl; 
	cerr << endl;  	     
	cerr << "Puntos leidos: " << leidos.ToString() << endl; 
	cerr << endl;  




	// Calcular y mostrar punto medio

	Punto2D punto_medio (0,0);	

	for (int pos=1; pos<=num_leidos; pos++) {

		Punto2D punto_pos = leidos[pos];

		punto_medio.SetCoordenadas (punto_medio.GetX()+punto_pos.GetX(), 
									punto_medio.GetY()+punto_pos.GetY());
	}

	punto_medio.SetCoordenadas (punto_medio.GetX()/num_leidos, 
								punto_medio.GetY()/num_leidos);
	cerr << endl;  	     
	cerr << "Punto medio: " << punto_medio.ToString() << endl; 
	cerr << endl;  


	return 0; 
}

/***************************************************************************/
/***************************************************************************/
