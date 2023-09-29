/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 3
//
// Examen ordinario 2017/2018 (1)
//
// Fichero: RedMetro.h
//
/***************************************************************************/

#ifndef RED_METRO
#define RED_METRO

//#define DEBUG_RED_METRO

#include <iostream>
#include <string>

#include "InfoParada.h"
#include "Linea.h"

using namespace std;

/***************************************************************************/

const double UMBRAL_IGUALES = 1e-6;
bool SonIguales (double uno, double otro);

/***************************************************************************/

/////////////////////////////////////////////////////////////////////////////

class RedMetro 
{                   
    
private:                  

    int num_lineas;   // Número de lineas de la red  
    Linea * lineas;   // linea[i]: info. linea                        

public:                        

	/***********************************************************************/
	// Constructor sin argumentos (crea una red vacía), constructor de
	// copia y destructor

	RedMetro (void); 
	RedMetro (const RedMetro & otra); 
	~RedMetro(void);

	/***********************************************************************/
	// Indica si una red está vacía.

	bool EstaVacia (void);

	/***********************************************************************/
	// Devuelve el número de líneas,
	
	int GetNumLineas (void)  const;
	
	// Devuelve el número total de paradas
	
	int GetNumTotalParadas (void) const;

	/***********************************************************************/
	// Copia profunda

	void Clona (const RedMetro & orig);

	/***********************************************************************/
	// Devuelve una Linea, dado su número 
	
	Linea GetLinea (int num_linea) const;

	// Añade una Linea a la red

	void AniadeLinea (const Linea & nueva_linea);

	/***********************************************************************/
	// Lee de un flujo de entrada (cin) el contenido de una red.
	
	void FromText (void);

	/***********************************************************************/
	// Serialización

	string ToString (void) const;

	/***********************************************************************/
	// Permita obtener la parada (su índice) en la que confluyen el mayor 
	// número de líneas, independientemente de si están activas o no.

	int MejorConectada (void) const;	

	/***********************************************************************/
	// Calcula un valor de calidad para la RedMetro

	double ValorCalidad (void) const;

	/***********************************************************************/

private:
	
	/***********************************************************************/
	// Petición / liberación de memoria
	void ReservarMemoria (int el_num_lineas);
	void LiberarMemoria (void); 

	/***********************************************************************/
    // Copiar datos desde otro objeto de la clase
	void CopiarDatos (const RedMetro & otro);

	/***********************************************************************/
};
   
/////////////////////////////////////////////////////////////////////////////

/***************************************************************************/

void MuestraRed (const char * mensaje, RedMetro & red); 

/***************************************************************************/

#endif
