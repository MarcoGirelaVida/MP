/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 6
//
// Este programa utiliza la clase Matriz2D ampliada.  
//
// Fichero: VI_Demo-Matriz2D.cpp
//
/***************************************************************************/
/***************************************************************************/

#include "Matriz2D.h"

#include <iostream>
using namespace std;

/***************************************************************************/
/***************************************************************************/

int main(void) 
{

	const char * nombre1 = "datos_matriz/datos_5x4.txt";

	Matriz2D m1(nombre1);

	cout << "Matriz m1 leida del fichero " << nombre1 << endl; 

	if (m1.EstaVacia())
		cout << "Matriz m1 esta vacia." << endl;
	else 
		cout << "Matriz m1 NO esta vacia." << endl;

	cout << "Dimensiones de m1 = " << m1.NumFilas() << " x " 
        << m1.NumColumnas() << endl;


	cout << endl;	
	cout << m1.ToString ("Creada matriz m1 (nombre1)");
	cout << endl;	

	//........................................

	const char * nombre2 = "datos_matriz/datos_5x4_out.txt";

	cout << "Guardando m1 en el fichero " << nombre2 << endl << endl; 
	m1.EscribirMatriz2D (nombre2);

	//........................................

	Matriz2D m2 (nombre2);

	cout << "Matriz m2 leida del fichero " << nombre2 << endl; 

	if (m2.EstaVacia())
		cout << "Matriz m2 esta vacia." << endl;
	else 
		cout << "Matriz m2 NO esta vacia." << endl;

	cout << "Dimensiones de m2 = " << m2.NumFilas() << " x "
        << m2.NumColumnas() << endl;

	cout << endl;	
	cout << m2.ToString ("Creada matriz m2 (nombre2)");
	cout << endl;	
	
	//........................................

	if (m1 == m2) {
		cout << endl;	
		cout << "Se ha comprobado que m1 == m2 lo que significa que" << endl;
		cout << "se ha guardado el contenido de m1 en el fichero" << endl;  
		cout << nombre2 << " y se ha recuperado " << endl;
		cout << "correctamente ese contenido en la matriz m2" << endl;
		cout << endl;	
	}
	else {
		cout << endl;	
		cout << "Hay algun error de consistencia entre los datos" << endl;
		cout << "leidos y los guardados." << endl;
		cout << endl;	
	}

	//........................................


	Matriz2D m3;

	cout << "Se ha creado la matriz m3" << endl; 
	if (m3.EstaVacia())
		cout << "Matriz m3 esta vacia." << endl;
	else 
		cout << "Matriz m3 NO esta vacia."<< endl;
	

	cout << "Leyendo contenido de m3 (ya existe m3) del fichero " 
		 << nombre2 << endl; 

	m3.LeerMatriz2D (nombre2);

	cout << endl;	
	cout << m3.ToString ("Matriz m3 (nombre2)");
	cout << endl;	

	if ((m3 == m2) && (m3 == m1)) 
		cout << "m3 == m2 == m1--> Lectura correcta" << endl;
	else 
		cout << "m1, m2 y m3 diferentes --> Lectura incorrecta" << endl;

	cout << endl;	

	return 0;
}

/***************************************************************************/
/***************************************************************************/
