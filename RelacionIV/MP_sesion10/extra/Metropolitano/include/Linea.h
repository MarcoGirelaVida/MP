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
// Fichero: Linea.h
//
/***************************************************************************/

#ifndef LINEA
#define LINEA

//#define DEBUG_LINEA

#include <iostream>
#include <string>

#include "InfoParada.h"

using namespace std;

//////////////////////////////////////////////////////////////////////////

class Linea 
{                                           
private:
    int num_paradas; // Num. paradas de la linea              
    InfoParada * paradas; // paradas[i]: info. de una parada de la linea

public:  
    
	/***********************************************************************/
	// Constructor sin argumentos (crea una Linea vacía), constructor de
	// copia y destructor

	Linea (void);
	Linea (const Linea & otra);    
	~Linea(void);

	/***********************************************************************/
	// Indica si una Linea está vacía.

	bool EstaVacia (void);

	/***********************************************************************/
	// Devuelve el número de paradas de una Linea
	
	int  GetNumParadas (void);

	/***********************************************************************/
	// Devuelve true si la parada "indice_parada" está en la Linea

	bool ContieneParada (int indice_parada) const;

	/***********************************************************************/
	// Devuelve true si todas las paradas de la Linea están operativas

	bool EstaTotalmenteOperativa () const;

	/***********************************************************************/
	// Copia profunda

	void Clona (const Linea & orig);

	/***********************************************************************/
	// Devuelve el objeto InfoParada cuyo número es "el_num_parada"
	
	InfoParada GetInfoParada (int el_num_parada) const;

	/***********************************************************************/
	// Añade un objeto InfoParada a la Linea
	
	void AniadeInfoParada (const InfoParada & nueva_parada);

	/***********************************************************************/
	// Lee de un flujo de entrada (cin) el contenido de una Linea

	void FromText (void);

	/***********************************************************************/
	// Serialización

	string ToString (void) const;

	/***********************************************************************/

private:
	
	/***********************************************************************/
	// Petición / liberación de memoria
	void ReservarMemoria (int el_num_paradas);
	void LiberarMemoria (void); 
	
	/***********************************************************************/
	// Copiar datos desde otro objeto de la clase
	void CopiarDatos (const Linea & otra);
	                        
};

//////////////////////////////////////////////////////////////////////////
    
#endif
