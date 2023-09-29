/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 3
//
// Demostración de la funcionalidad de la clase SecuenciaEnteros
//		* constructor de copia
//		* destructor
//
// Fichero: III_Demo-Secuencia.cpp
//
/***************************************************************************/

#include <iostream>
#include <iomanip>

#include "TipoBase_Secuencia.h"
#include "Secuencia.h"

using namespace std; 

/***********************************************************************/
/***********************************************************************/

int main (void)
{
	
	// Constructor con un argumento
	Secuencia almacen (3);
		 
	cout << "almacen: " << endl;
	cout << almacen.ToString () << endl;
	cout << "CAPACIDAD: " << almacen.Capacidad() << endl;
	cout << "OCUPADOS = " << almacen.TotalUtilizados() << endl;
	cout << endl;

	if (almacen.EstaVacia()) 
		cout << "Esta vacio. " << endl;
	else 
		cout << "NO esta vacio." << endl;
	cout << endl;
	

	// ******************************************************************

	TipoBaseSecuencia valor;

	cout << "Introducir un valor (para finalizar, un negativo): ";
	cin >> valor;

	while (valor >= 0) {

		almacen.Aniade (valor);

		cout << "--> CAPACIDAD: " << almacen.Capacidad() << endl;
		cout << "--> OCUPADOS = " << almacen.TotalUtilizados() << endl;

		cout << "Introducir un valor (para finalizar, un negativo): ";
		cin >> valor;
	}

			
	cout << "almacen: " << endl;
	cout << almacen.ToString () << endl;
	cout << "CAPACIDAD: " << almacen.Capacidad() << endl;
	cout << "OCUPADOS = " << almacen.TotalUtilizados() << endl;
	cout << endl;


	if (almacen.EstaVacia()) 
		cout << "Esta vacio. " << endl;
	else 
		cout << "NO esta vacio." << endl; 
	cout << endl;

	
	// ******************************************************************
	// Prueba de constructor de copia
	
	Secuencia copia_almacen (almacen);


	cout << "copia_almacen: " << endl;
	cout << copia_almacen.ToString () << endl;
	cout << "CAPACIDAD: " << almacen.Capacidad() << endl;
	cout << "OCUPADOS = " << almacen.TotalUtilizados() << endl;
	cout << endl;
		
	if (copia_almacen.EstaVacia()) 
		cout << "Esta vacio. " << endl;
	else 
		cout << "NO esta vacio." << endl;
	cout << endl;	
	
	// Prueba de constructor sin argumentos
	
	Secuencia otro_almacen;
	
	cout << "Se acaba de crear otro_almacen (const. sin args): " << endl;
	cout << otro_almacen.ToString () << endl;
	cout << "CAPACIDAD: " << otro_almacen.Capacidad() << endl;
	cout << "OCUPADOS = " << otro_almacen.TotalUtilizados() << endl;
	cout << endl;

	if (otro_almacen.EstaVacia()) 
		cout << "otro_almacen SI esta vacio. " << endl;
	else 
		cout << "otro_almacen NO esta vacio." << endl;
	cout << endl;


	// ******************************************************************
	// Prueba de clonacion
	
	otro_almacen.Clona (almacen);

	cout << "Se acaba de clonar \"almacen\" en \"otro_almacen\" ";
	cout << "(otro_almacen.Clona (almacen)): " << endl;

	cout << "otro_almacen: " << endl;
	cout << otro_almacen.ToString () << endl;
	cout << "CAPACIDAD: " << otro_almacen.Capacidad() << endl;
	cout << "OCUPADOS = " << otro_almacen.TotalUtilizados() << endl;
	cout << endl;

	if (otro_almacen.EstaVacia()) 
		cout << "otro_almacen SI esta vacio. " << endl;
	else 
		cout << "otro_almacen NO esta vacio." << endl;
	cout << endl;

	// ******************************************************************
	// Pruebas de Valor()

	int num_valores = otro_almacen.TotalUtilizados();
	
	cout << endl; 
	cout << "Valores del almacen clonado: " << endl;

//	for (int pos=0; pos<num_valores; pos++) { // ANTIGUA
	for (int pos=1; pos<=num_valores; pos++) {
		cout << "Casilla " << setw(3) << pos << ": " 
		     << setw(3) << otro_almacen.Valor(pos) << endl; 
	}
	cout << endl; 

	cout << "Cambiando valores del almacen clonado." << endl;

//	for (int pos=0; pos<num_valores; pos++) { // ANTIGUA
	for (int pos=1; pos<=num_valores; pos++) {
		otro_almacen.Valor(pos) = 100*otro_almacen.Valor(pos); 
	}
	cout << endl; 

	cout << "almacen clonado modificado: " << endl;
	cout << otro_almacen.ToString () << endl;
	cout << endl; 

	// ******************************************************************

	return (0);
}

/***********************************************************************/
/***********************************************************************/
