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
// Fichero: RedMetro.cpp
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
#include "RedMetro.h"

//#define DEBUG

using namespace std;


/***************************************************************************/
// Calcula si dos datos double son iguales 

bool SonIguales (double uno, double otro) 
{
	return (fabs(uno-otro)<UMBRAL_IGUALES);
}

/***************************************************************************/


/***************************************************************************/
// Constructor sin argumentos (crea una red vacía)

RedMetro :: RedMetro (void) : num_lineas(0), lineas(0) { }

/***************************************************************************/
// Constructor de copia

RedMetro :: RedMetro (const RedMetro & otra)
{
	ReservarMemoria (otra.num_lineas);
	CopiarDatos (otra);
}

/***************************************************************************/
// Destructor

RedMetro :: ~RedMetro(void)
{
	LiberarMemoria ();
}

/***************************************************************************/
// Indica si una red está vacía.

bool RedMetro :: EstaVacia (void)
{
	return (num_lineas==0);
}

/***************************************************************************/
/***************************************************************************/
// Devuelve el número de líneas

int RedMetro :: GetNumLineas (void) const
{
	return (num_lineas);
}

/***************************************************************************/
// Devuelve el número total de paradas

int RedMetro :: GetNumTotalParadas (void) const
{
	int indice_mayor = 1;

	for (int l=0; l<num_lineas; l++) {

		Linea la_linea = lineas[l];

		int paradas_linea = la_linea.GetNumParadas();

		for (int p=1; p<=paradas_linea; p++) {
				
			InfoParada ip = la_linea.GetInfoParada (p); 

			int indice_parada = ip.GetIndice();

			if (indice_parada > indice_mayor) 
				indice_mayor = indice_parada;

		} // for p

	} // for l

	return (indice_mayor);
}

/***************************************************************************/
// Copia profunda

void RedMetro :: Clona (const RedMetro & orig)
{		
	LiberarMemoria ();
	ReservarMemoria (orig.num_lineas);
	CopiarDatos (orig);
}

/***************************************************************************/
// Devuelve una Linea, dado su número

Linea RedMetro :: GetLinea (int num_linea) const
{
	return (lineas[num_linea-1]); 
}

/***************************************************************************/
// Añade una Linea a la red

void RedMetro :: AniadeLinea (const Linea & nueva_linea)
{
	#ifdef DEBUG_RED_METRO
	cerr << "Aniadiendo linea " << endl;
	cerr << "Num.lineas antes = " << num_lineas << endl;
	#endif

	Linea * tmp = new Linea[num_lineas+1];

	for (int l=0; l<num_lineas; l++) 
		//tmp[l] = lineas[l];  // Operator = de la clase "Linea"
		tmp[l].Clona (lineas[l]); 

	//tmp[num_lineas] = nueva_linea;    // Operator = de la clase "Linea"
	tmp[num_lineas].Clona (nueva_linea);    

	delete [] lineas;

	lineas = tmp;
	num_lineas++;

	#ifdef DEBUG_RED_METRO
	cerr << "Linea aniadida" << endl;
	cerr << "Num.lineas despues = " << num_lineas << endl;
	#endif
}

/***************************************************************************/
// Lee de un flujo de entrada (cin) el contenido de una red.

void RedMetro :: FromText (void)
{
	// Limpiar el objeto: Liberar memoria reservada previamente
	LiberarMemoria();
	
	const int MAX_CADENA = 100;
	char cadena[MAX_CADENA];

	cin.getline(cadena, MAX_CADENA);	// Lectura palabra mágica

	if (!strcmp(cadena, "METRO")) {

		int el_num_lineas;
		cin >> el_num_lineas;

		#ifdef DEBUG_RED_METRO
		cout << endl;
		cout << "Lineas a leer = " << el_num_lineas << endl;
		cout << endl;
		#endif

		for (int l=1; l<=el_num_lineas; l++) {

			#ifdef DEBUG_RED_METRO
			cout << endl;
			cout << "--> leyendo linea " << l << endl;
			cout << endl;
			#endif

			Linea linea_nueva;
			linea_nueva.FromText();

			#ifdef DEBUG_RED_METRO
			cout << endl;
			cout << "Linea " << l << ": " << endl;
			linea_nueva.ToText();
			cout << endl;
			#endif

			AniadeLinea (linea_nueva);

		} // linea

	} // if (!strcmp(cadena, "METRO"))

}

/***************************************************************************/
// Serialización

string RedMetro :: ToString (void) const
{
	string cad;

	cad = cad + to_string(num_lineas) + "\n";

	for (int l=1; l<=num_lineas; l++) {		

		Linea la_linea = GetLinea(l);// lineas[l-1]; 

		cad = cad + la_linea.ToString();  

	}

	return (cad);
}

/***************************************************************************/
// Calcula un valor de calidad para la RedMetro

double RedMetro :: ValorCalidad (void) const
{
	int cont_paradas_total = 0; 
	int cont_paradas_no_activas_total = 0; 

	for (int l=0; l<num_lineas; l++) {

		Linea la_linea = lineas[l];

		int paradas_linea = la_linea.GetNumParadas();
	
		// Contar paradas no activas de la linea
		int cont_paradas_no_activas = 0;		

		for (int p=1; p<=paradas_linea; p++) {
				
			InfoParada ip = la_linea.GetInfoParada (p); 

			if (!ip.EstaActiva())   // Operator () de "Linea"
				cont_paradas_no_activas++; 
		}

		// Acumular contadores
		cont_paradas_total += paradas_linea;
		cont_paradas_no_activas_total+=cont_paradas_no_activas;
	}

	// Calcular valor de calidad	
	int cont_paradas = cont_paradas_total-cont_paradas_no_activas_total; 
	double valor = 0.7*cont_paradas + 0.3*num_lineas;
	
	return (valor);
}

/***************************************************************************/
// Permita obtener la parada (su índice) en la que confluyen el mayor 
// número de líneas, independientemente de si están activas o no.

int RedMetro :: MejorConectada (void) const
{

	int num_total_paradas = GetNumTotalParadas();
	int * lineas_pasan = new int [num_total_paradas];

	for (int p=0;p<num_total_paradas; p++) 
		lineas_pasan[p] = 0;


	for (int l=0; l<num_lineas; l++) {

		Linea la_linea = lineas[l];

		int paradas_linea = la_linea.GetNumParadas();

		for (int p=1; p<=paradas_linea; p++) {
				
			InfoParada ip = la_linea.GetInfoParada (p); 

			int indice_parada = ip.GetIndice();
			lineas_pasan[indice_parada-1]++;


		} // for p

	} // for l

	int num_paradas_mejor_conectada = lineas_pasan[0];
	int indice_mejor_conectada = 1;

	for (int p=2; p<=num_total_paradas; p++) {

		if (lineas_pasan[p-1] > num_paradas_mejor_conectada) {

			num_paradas_mejor_conectada = lineas_pasan[p-1];
			indice_mejor_conectada = p;
		}

	} // for p

	return (indice_mejor_conectada);

}

/***************************************************************************/
/***************************************************************************/
// MÉTODOS PRIVADOS
/***************************************************************************/
/***************************************************************************/

void RedMetro :: ReservarMemoria (int el_num_lineas)
{
	lineas = new Linea[el_num_lineas];
}

/***************************************************************************/

void RedMetro :: LiberarMemoria ()
{
	if (lineas) 
		delete [] lineas; 
	
	lineas = 0;
	num_lineas = 0;
}
/***************************************************************************/

void RedMetro :: CopiarDatos (const RedMetro & otra)
{
	num_lineas = otra.num_lineas;
	
	for (int l=0; l<num_lineas; l++) 
		lineas[l] = otra.lineas[l];  // Operator = de la clase "Linea"
}


/***************************************************************************/
/***************************************************************************/
// FUNCIONES EXTERNAS
/***************************************************************************/
/***************************************************************************/

void MuestraRed (const char * mensaje, RedMetro & red) 
{

	cout << mensaje << endl;

	cout << "\tNum de lineas: " << red.GetNumLineas() << endl;			
	cout << "\tNum total paradas: " << red.GetNumTotalParadas() << endl;

	for (int l=1; l<=red.GetNumLineas(); l++) {

		Linea la_linea = red.GetLinea (l);

		int paradas_linea = la_linea.GetNumParadas();
	
		cout << "\tLinea " << l << ". " << paradas_linea << " paradas.";
		cout << " --> ";

		for (int p=1; p<=paradas_linea; p++) {
				
			InfoParada la_parada = la_linea.GetInfoParada(p); 

			int indice_parada = la_parada.GetIndice();
			bool operativa_parada = la_parada.EstaActiva();

			cout << setw(3) << indice_parada << "(";
			cout << (operativa_parada ? "S":"N") << ") ";
		}

		cout << endl;

	}

}

/***************************************************************************/

