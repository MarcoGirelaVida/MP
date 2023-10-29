/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// Definición de la clase Punto2D
// Declaraciones en: Punto2D.h 
//
// Fichero: Punto2D.cpp
//
/***************************************************************************/

#include <cctype>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>

#include "Punto2D.h"
#include "Utils.h"

using namespace std;


/***************************************************************************/
/***************************************************************************/
// Constructor sin argumentos.
//
// MUY IMPORTANTE: Nos vemos obligados a escribir este constructor por la
// clase "ColeccionPuntos2D": cuando actúa el constructor sin argumentos 
// de esa clase crea un vector de objetos "Punto2D" y cada elemento del  
// vector se crea usando este constructor. 
// No hace nada útil, pero debe estar.

Punto2D :: Punto2D (void) { }

/***************************************************************************/
/***************************************************************************/
// Constructor con argumentos.
//
// Parámetros: abscisaPunto y ordenadaPunto, la abscisa y ordenada, 
// 		respectivamente del punto que se está creando.

Punto2D :: Punto2D (int abscisaPunto, int ordenadaPunto)
{
	SetCoordenadas (abscisaPunto, ordenadaPunto);
}

/***********************************************************************/
/***********************************************************************/
// Constructor con argumentos.
//
// Parámetros: cad, cadena que representa a un punto. 

Punto2D :: Punto2D (string cad)
{
	x = stoi(cad.substr(1,2));	 
	y = stoi(cad.substr(4,2));	 
}

/***************************************************************************/
/***************************************************************************/
// Métodos Get: Devuelven las coordenadas x e y, repectivamente. 

int Punto2D :: GetX (void) const
{
	return (x);
}
int Punto2D :: GetY (void) const
{
	return (y);
}

/***************************************************************************/
/***************************************************************************/
// Métodos Set: Fijan las coordenadas. 
//
// Parámetros: abscisaPunto y ordenadaPunto, la abscisa y ordenada, 
// 		respectivamente del punto que se está modificando.

void Punto2D :: SetX (int abscisaPunto)
{
	x = abscisaPunto;
}
void Punto2D :: SetY (int ordenadaPunto)
{
	y = ordenadaPunto;
}
void Punto2D :: SetCoordenadas (int abscisaPunto, int ordenadaPunto)
{
	SetX (abscisaPunto);
	SetY (ordenadaPunto);
}

/***************************************************************************/
/***************************************************************************/
// Calcula si dos puntos son iguales 
//
// Parámetros: otro (referencia), el punto que se quiere comparar con el 
//		objeto implícito. 
// Devuelve: true, si se consideran iguales los dos objetos. 

bool Punto2D :: operator == (const Punto2D & otro) const
{
	return ((x==otro.x) && (y==otro.y));
}

/***************************************************************************/
/***************************************************************************/
// Calcula si dos puntos son distintos 
//
// Parámetros: otro (referencia), el punto que se quiere comparar con el 
//		objeto implícito. 
// Devuelve: true, si se consideran distintos los dos objetos. 

bool Punto2D :: operator != (const Punto2D & otro) const
{
	return (!(*this == otro));
}

/***************************************************************************/
/***************************************************************************/
// Calcula la distancia Euclídea del punto (objeto implícito) a otro que 
// se recibe como argumento. 
//
// Parámetros: otro(referencia), el punto respecto al cual que se quiere 
//		calcular la distancia euclídea.
// Devuelve: la distancia entre los dos puntos. 

double Punto2D :: DistanciaEuclidea (const Punto2D & otro) const
{
	double dif_x = pow (x - otro.x, 2);
	double dif_y = pow (y - otro.y, 2);

	return (sqrt(dif_x + dif_y));
}

/***************************************************************************/
/***************************************************************************/
// Serializa un dato "Punto2D".

string Punto2D :: ToString (void) const 
{
	return ("["+FormatInt(x,2) + "," + FormatInt(y,2)+"]");	
}

/***************************************************************************/
/***************************************************************************/
// Sobrecarga de los operadores >> y << 

istream & operator >> (istream & in,  Punto2D & el_punto)
{

	string cad;
	in >> cad; 

	if (!in.eof()) {
		Punto2D punto_leido (cad);
		el_punto = punto_leido;
	}

	return in; 
}

ostream & operator << (ostream & out, const Punto2D & el_punto)
{
	out << el_punto.ToString();
	return out; 
}

/***************************************************************************/
/***************************************************************************/


