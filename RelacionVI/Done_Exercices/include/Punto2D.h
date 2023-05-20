/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//	
//	Declaración de la clase Punto2D
//  Definiciones en: Punto2D.cpp 
//
//	Fichero: Punto2D.h
//
/***************************************************************************/

#ifndef PUNTO2D
#define PUNTO2D

#include <iostream>
#include <string>

#include "Utils.h"

using namespace std;
 
 
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

class Punto2D {
	
private:
	
	// La pareja (x,y) son las coordenadas de un punto en un espacio 2D

	int x;
	int y;

public:
	
	/***********************************************************************/
	/***********************************************************************/
	// Constructor sin argumentos.
	//
	// MUY IMPORTANTE: Nos vemos obligados a escribir este constructor por la
	// clase "ColeccionPuntos2D": cuando actúa el constructor sin argumentos 
	// de esa clase crea un vector de objetos "Punto2D" y cada elemento del  
	// vector se crea usando este constructor. 
	// No hace nada útil, pero debe estar.
		
	Punto2D (void);

	/***********************************************************************/
	/***********************************************************************/
	// Constructor con argumentos.
	//
	// Parámetros: cad, cadena que representa a un punto. 
	
	Punto2D (string cad);

	/***********************************************************************/
	/***********************************************************************/
	// Constructor con argumentos.
	//
	// Parámetros: abscisaPunto y ordenadaPunto, la abscisa y ordenada, 
	// 		respectivamente del punto que se está creando.
	
	Punto2D (int abscisaPunto, int ordenadaPunto);

	/***********************************************************************/
	/***********************************************************************/
	// Métodos Get: Devuelven las coordenadas x e y, repectivamente. 

	int GetX (void) const;
	int GetY (void) const;

	/***********************************************************************/
	/***********************************************************************/
	// Métodos Set: Fijan las coordenadas. 
	//
	// Parámetros: abscisaPunto y ordenadaPunto, la abscisa y ordenada, 
	// 		respectivamente del punto que se está modificando.

	void SetX (int abscisaPunto);
	void SetY (int abscisaPunto);
	void SetCoordenadas (int abscisaPunto, int ordenadaPunto);
	
	/***********************************************************************/
	/***********************************************************************/
	// Métodos que calculan si dos datos Punto2D son iguales o distintos

	bool operator == (const Punto2D & otro) const;
	bool operator != (const Punto2D & otro) const;

	/***********************************************************************/
	/***********************************************************************/
	// Calcula la distancia Euclídea del punto (objeto implícito) a otro que 
	// se recibe como argumento. 
	//
	// Parámetros: otro(referencia), el punto respecto al cual que se quiere 
	//		calcular la distancia euclídea.
	// Devuelve: la distancia entre los dos puntos.

	double DistanciaEuclidea (const Punto2D & otro) const;

	/***********************************************************************/
	/***********************************************************************/
	// Devuelve la representación en una cadena de un dato "Punto2D"
	
	string ToString (void) const;

	/***********************************************************************/
	/***********************************************************************/
	// Sobrecarga de los operadores >> y << 

	friend istream & operator >> (istream & in,  Punto2D & el_punto); 
	friend ostream & operator << (ostream & out, const Punto2D & el_punto);  

	/***********************************************************************/
	/***********************************************************************/

};

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

#endif
