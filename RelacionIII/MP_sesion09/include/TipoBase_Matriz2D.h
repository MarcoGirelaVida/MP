/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// AUTOR: MARCO GIRELA VIDA
// GRUPO: 1ºB
// FECHA: xx/04/2023
//
// RELACION DE PROBLEMAS 2
//
// Fichero: TipoBase_Matriz2D.h
/*****************************************************************************/

#ifndef TIPOBASE_MATRIZ2D
#define TIPOBASE_MATRIZ2D

/***************************************************************************/
// Definiciones de tipos

typedef int TipoBase;	// Tipo de los datos de la matriz
typedef struct
{

	TipoBase ** datos;	// Puntero a vector de punteros a los datos

	int fils;			// Num. de filas
	int cols; 			// Num. de columnas
} Matriz2D;

/***************************************************************************/
// Constantes globales
const TipoBase VALOR_DEF = 0; // Valor por defecto de los datos de la matriz


#endif

/***************************************************************************/
