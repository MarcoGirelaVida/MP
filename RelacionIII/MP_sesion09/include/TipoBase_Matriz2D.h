/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// Fichero de cabecera asociado al tipo base de la clase "Secuencia"
//
// Fichero: TipoBase_Secuencia.h
//
/***************************************************************************/

#ifndef TIPOBASE_MATRIZ2D
#define TIPOBASE_MATRIZ2D

/***************************************************************************/
// Definiciones de tipos

typedef int TipoBase;	// Tipo de los datos de la matriz
typedef struct {

	TipoBase ** datos;	// Puntero a vector de punteros a los datos

	int fils;			// Num. de filas
	int cols; 			// Num. de columnas
} Matriz2D;

/***************************************************************************/
// Constantes globales
const TipoBase VALOR_DEF = 0; // Valor por defecto de los datos de la matriz


#endif

/***************************************************************************/
