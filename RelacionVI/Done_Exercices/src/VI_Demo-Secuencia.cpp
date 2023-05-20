/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 6
//
// Demostración de la funcionalidad de la clase "Secuencia"
// Incluye: 
//		* constructor de copia
//		* destructor
//		* Operador =
// 		* Operadores de acceso
//		* Operadores varios
//		* Operadores de E/S
//		* Constructor desde fichero y métodos de E/S
//
// Fichero: VI_Demo-Secuencia.cpp
//
/***************************************************************************/

#include <iostream>
#include <iomanip>

#include "Secuencia.h"

using namespace std; 

/***********************************************************************/
/***********************************************************************/

int main (void)
{
	
	// Constructor con un argumento
	Secuencia almacen (3);
		 
	cout << endl;
	cout << almacen.ToString ("almacen: ") << endl;
	cout << "CAPACIDAD: " << almacen.Capacidad() << endl;
	cout << "OCUPADOS = " << almacen.TotalUtilizados() << endl;
	cout << endl;

	if (almacen.EstaVacia()) 
		cout << "Esta vacio. " << endl;
	else 
		cout << "NO esta vacio." << endl;
	cout << endl;
	

	// ******************************************************************

	const char * const nombre1 = "data/datos_secuencia.txt";

	almacen.LeerSecuencia (nombre1);
			
	cout << "almacen desde " << nombre1 << ":  " << endl;
	cout << almacen.ToString () << endl;

	cout << "CAPACIDAD: " << almacen.Capacidad() << endl;
	cout << "OCUPADOS = " << almacen.TotalUtilizados() << endl;
	cout << endl;


	if (almacen.EstaVacia()) 
		cout << "Esta vacio. " << endl;
	else 
		cout << "NO esta vacio." << endl; 
	cout << endl;


	// Modificar almacen

	TipoBaseSecuencia tmp = almacen[1];
	almacen[1] = almacen[almacen.TotalUtilizados()];
	almacen[almacen.TotalUtilizados()] = tmp;

	cout << endl;
	cout << almacen.ToString ("almacen modificado: ") << endl;

	cout << "CAPACIDAD: " << almacen.Capacidad() << endl;
	cout << "OCUPADOS = " << almacen.TotalUtilizados() << endl;
	cout << endl;


	// Guardar "almacen"

	const char * const nombre2 = "data/almacen.txt";

	cout << endl;
	cout << "Guardando almacen en " << nombre2 << endl;
	cout << endl;

	almacen.EscribirSecuencia (nombre2);


	// Crear otro_almacen 

	Secuencia otro_almacen;

	cout << endl;
	cout << otro_almacen.ToString ("otro_almacen tras crearlo: ") << endl;
	
	otro_almacen += 99;
	otro_almacen += 88;

	cout << endl;
	cout << otro_almacen.ToString ("otro_almacen tras aniadir 99 y 88: ")<<endl;


	otro_almacen.LeerSecuencia (nombre2);

	cout << endl;
	cout << "otro_almacen tras leer desde " << nombre2 << ": " << endl;
	cout << otro_almacen.ToString () << endl;

	cout <<  endl;
	if (otro_almacen != almacen) 
		cout << "Ha habido algun problema guardando o leyendo datos." << endl;
	else 
		cout << "Perfecto: el contenido de almacen se ha guardado ";
		cout << "correctamente y se ha leido correctamente." << endl;
	cout <<  endl;


	cout << endl;
	cout << "Prueba del operador << con \"otro_almacen\"" << endl;
	cout << otro_almacen << endl;
	cout << endl;


	return 0;
}

/***********************************************************************/
/***********************************************************************/
