/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// Fichero: ProcesamientoArrayInt.h
//
/***************************************************************************/

#ifndef PROCESAMIENTO_ARRAY_INT
#define PROCESAMIENTO_ARRAY_INT

#include <string>

using namespace std;

/***************************************************************************/
/***************************************************************************/
// Muestra el contenido de un vector de datos int con los datos alineados.   
// Con más precisión, muestra la parte comprendida desde el elemento cuya 
// dirección es "p" que tiene "n_datos" elementos). 
// Se muestra con el encabezamiento dado por "msg" y en cada línea se 
// imprimen, alineados, "datos_linea" datos. 
//
// Parámetros:
//		mensaje, "título" que encabeza la presentación
// 		p, n_datos de memoria del inicio el vector  
//		n_datos, número de casillas ocupadas del vector
//		datos_linea, número de valores que se muestran en  cada línea

void  MuestraVector (string msg, int *p, int n_datos, int datos_linea);

/***************************************************************************/
/***************************************************************************/
// Rellena un vector de datos int con "n_datos" números aleatorios.  
// Se rellenarán las primeras "n_datos" casillas a partir de la dirección 
// dada en "p". 
// Los valores están comprendidos entre "min_aleat" y "max_aleat". 
//
// Parámetros:
//		p, dirección de memoria donde se empieza a rellenar. 
//		num_datos, número de casillas a rellenar.
//		min_aleat y max_aleat, mínimo y máximo valor aleatorio.  
// PRE: num_datos >= 0
// PRE: min_aleat <= max_aleatls 

void  RellenaVector (int *p, int num_datos, int min_aleat, int max_aleat);

/***************************************************************************/
/***************************************************************************/
// Ordena un vector de datos int (concretamente la parte comprendida desde 
// el elemento cuya dirección es "v"que tiene "tamanio" elementos). 
//
// Parámetros:
//		v, dirección de memoria donde empiezan los datos a procesar. 
//		tamanio, número de casillas a procesar.
// PRE: tamanio >= 0

void OrdenaSeleccion (int *v, int tamanio);
void OrdenaInsercion (int *v, int tamanio);
void OrdenaIntercambio (int *v, int tamanio);
void OrdenaIntercambioMejorado (int *v, int tamanio);

/***************************************************************************/
// Ordena un vector de datos int que empieza en la dirección "v". 
// Se considera la parte que empieza en la casilla "pos_inic" y termina en 
// la casilla "pos_fin" (desde "v").
//
// Parámetros:
//		v, dirección de memoria donde empiezan los datos a procesar. 
//		pos_inic, casilla inicial (desde "v") a procesar.
//		pos_fin, casilla final (desde "v") a procesar.
// PRE: pos_inic <= pos_fin
// PRE: pos_inic y pos_fin son correctas

void OrdenaSeleccion   (int *v, int pos_inic, int pos_fin);
void OrdenaInsercion   (int *v, int pos_inic, int pos_fin);
void OrdenaIntercambio (int *v, int pos_inic, int pos_fin);
void OrdenaIntercambioMejorado (int *v, int pos_inic, int pos_fin);

/***************************************************************************/
/***************************************************************************/
// Mezcla dos vectores.
//
// Parámetros:
//		mezcla, dirección de memoria del inicio el vector resultado  
//		v1, dirección de memoria del inicio del primer vector a mezclar  
//		util_v1, número de casillas ocupadas en "v1"
//		v2, dirección de memoria del inicio del segundo vector a mezclar  
//		util_v2, número de casillas ocupadas en "v2"
// PRE: "v1" y "v2" están ordenados
// PRE: "mezcla" tiene suficiente memoria asignada
// PRE: util_v1, util_v2 >= 0

void MezclaVectoresSimple (int *mezcla, int *v1, int util_v1, 
	                                    int *v2, int util_v2);

/***************************************************************************/
/***************************************************************************/
// Funciones de utilidad

// Intercambia los valores cuyas direcciones están en "p1" y "p2"

void Intercambia (int *p1, int *p2);	

/***************************************************************************/
/***************************************************************************/

#endif
