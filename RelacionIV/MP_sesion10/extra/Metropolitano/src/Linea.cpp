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
// Fichero: Linea.cpp
//
/***************************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <string>
#include <cmath>

#include "InfoParada.h"
#include "Linea.h"

//#define DEBUG

using namespace std;


/***************************************************************************/
// Constructor sin argumentos (crea una red vacía)

Linea :: Linea (void) : num_paradas (0), paradas (0) { }

/***************************************************************************/
// Constructor de copia

Linea :: Linea (const Linea & otra)
{
	ReservarMemoria (otra.num_paradas);
	CopiarDatos (otra);
}

/***************************************************************************/
// Destructor

Linea :: ~Linea(void)
{
	LiberarMemoria ();
}

/***************************************************************************/
// Indica si una Linea está vacía.

bool Linea :: EstaVacia (void)
{
	return (num_paradas==0);
}

/***************************************************************************/
// Devuelve el número de paradas de una Linea

int Linea :: GetNumParadas (void)
{
	return (num_paradas);
}

/***************************************************************************/
// Devuelve true si la parada "indice_parada" está en la Linea

bool Linea :: ContieneParada (int indice_parada) const
{
	bool sigo = true;
	int  p=0;

	while (p<num_paradas) {

		InfoParada parada = paradas[p];

		if (parada.GetIndice() == indice_parada) sigo = false;
		else p++;
	}

	return (!sigo);
}
/***************************************************************************/
// Devuelve true si todas las paradas de la Linea están operativas

bool Linea :: EstaTotalmenteOperativa () const 
{
	bool sigo = true;
	int p=0;

	while ((sigo) && (p<num_paradas)) {

		InfoParada parada = paradas[p];
			
		if (!(parada.EstaActiva())) sigo = false;
		else p++; 
				
	}

	return (sigo);

}

/***************************************************************************/
// Devuelve el objeto InfoParada cuyo número es "el_num_parada"

InfoParada Linea :: GetInfoParada (int el_num_parada) const
{
	return (paradas[el_num_parada-1]);
}

/***************************************************************************/
// Añade un objeto InfoParada a la Linea

void Linea :: AniadeInfoParada (const InfoParada & nueva_parada)
{
	#ifdef DEBUG_LINEA
	cout << "Aniadiendo parada a linea ..." << endl;
	cout << "--> Actualmente tiene " << num_paradas << " paradas." << endl;
	#endif

	InfoParada * tmp = new InfoParada[num_paradas+1];

	for (int p=0; p<num_paradas; p++) 
		tmp[p] = paradas[p];	// Sin memoria dinámica

	tmp[num_paradas] = nueva_parada;  // Sin memoria dinámica


	delete [] paradas;

	paradas = tmp;
	num_paradas++;

	#ifdef DEBUG_LINEA
	cout << "Parada aniadida a la linea" << endl;
	cout << "--> Actualmente tiene " << num_paradas << " paradas." << endl;
	#endif
}

/***************************************************************************/
// Copia profunda

void Linea :: Clona (const Linea & orig)
{		
	LiberarMemoria ();
	ReservarMemoria (orig.num_paradas);
	CopiarDatos (orig);
}

/***************************************************************************/
// Serialización

string Linea :: ToString (void) const 
{
	string cad = to_string(num_paradas) + "\n";

	for (int p=1; p<=num_paradas; p++) {		
	
		InfoParada ip = GetInfoParada(p);

		cad = cad + ip.ToString();
	}

	return cad; 
}

/***************************************************************************/
// Lee de un flujo de entrada (cin) el contenido de una Linea

void Linea :: FromText (void)  
{	
	int el_num_paradas; 
	cin >> el_num_paradas; 

	#ifdef DEBUG_LINEA
	cout << endl;
	cout << "Paradas de la linea = " << el_num_paradas  << endl;
	cout << endl;
	#endif

	for (int p=1; p<=el_num_paradas; p++) {

		#ifdef DEBUG_LINEA
		cout << endl;
		cout << "--> leyendo parada " << p << endl;
		cout << endl;
		#endif

		InfoParada parada_nueva;
		parada_nueva.FromText();

		#ifdef DEBUG_LINEA
		cout << "Parada " << p << "--> ";
		parada_nueva.ToText();
		#endif

		AniadeInfoParada (parada_nueva);

	} // parada

}


/***************************************************************************/
/***************************************************************************/

/***************************************************************************/
/***************************************************************************/
// MÉTODOS PRIVADOS
/***************************************************************************/
/***************************************************************************/

void Linea :: ReservarMemoria (int el_num_paradas)
{
	paradas = new InfoParada[el_num_paradas];
}

/***************************************************************************/

void Linea :: LiberarMemoria ()
{
	if (paradas) 
		delete [] paradas; 

	paradas = 0;
	num_paradas = 0;
}

/***************************************************************************/

void Linea :: CopiarDatos (const Linea & otra)
{
	num_paradas = otra.num_paradas;
	
	for (int p=0; p<num_paradas; p++) 
		paradas[p] = otra.paradas[p];   // Sin memoria dinámica
}

/***************************************************************************/

