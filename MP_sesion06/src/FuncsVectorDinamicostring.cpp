/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// AUTOR: MARCO GIRELA VIDA
// GRUPO: 1ºB
// FECHA: xx/03/2023
//
// RELACION DE PROBLEMAS 2
//
// Implementaci�n de las funciones b�sicas de gesti�n del tipo "VectorDinamico".
// Declaraciones en VectorDinamico_basico.h
//  
// Fichero: VectorDinamico_basico.cpp
//
/***************************************************************************/
/***************************************************************************/


#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>

#include "FuncsVectorDinamicostring.h"

using namespace std; 


/***************************************************************************/
/***************************************************************************/
// Crear vector dinámico
// Argumentos: cap_inic, número de casillas con las que se crea el vector.
// Devuelve: el vector dinámico creado.
// POST: El número de casillas usadas es 0
//       El número de casillas reservadas es "capacidad_inicial"

VectorDinamico CreaVectorDinamico (int cap_inic, TipoRedimension tipo)
{
	VectorDinamico nuevo;

	// Reserva de memoria dinámica
	nuevo.datos = new TipoBase[cap_inic]; 

	// Iniciar capacidad y ocupación
	nuevo.capacidad = cap_inic;
	nuevo.usados = 0;

	// Inicialización del tipo de redimension
	nuevo.tipo_redim = tipo;

	return (nuevo);
}


/***************************************************************************/
/***************************************************************************/
// Libera la memoria ocupada por un vector dinámico
// Argumentos: v (referencia) El vector que se va liberar.
// POST: El número de casillas usadas es 0
//       El número de casillas reservadas es 0

void DestruyeVectorDinamico (VectorDinamico & v) 
{
	// Si le vector no está vacío, se libera la memoria.
	if (v.datos)
		delete [] v.datos;

	// Modificar las propiedades de "v" para que quede "vacío"
	v.datos = nullptr; 
	v.usados = 0;
	v.capacidad = 0;
}


/***************************************************************************/
/***************************************************************************/
// Calcula el número de casillas usadas de un vector dinámico.
// Argumentos: v, el vector que se va a consultar.
// Devuelve: el número de casillas usadas de un vector dinámico

int  UsadosVectorDinamico (const VectorDinamico & v) 
{
	return (v.usados);
}	


/***************************************************************************/
/***************************************************************************/
// Calcula el n�mero de casillas reservadas de un vector din�mico.
// Argumentos: v, el vector que se va a consultar.
// Devuelve: el n�mero de casillas reservadas de un vector din�mico

 int CapacidadVectorDinamico (const VectorDinamico & v) 
{
	return (v.capacidad);
}	


/***************************************************************************/
/***************************************************************************/
// Deja el vector dinámico vacío
// Argumentos: v (referencia) El vector que se va "vaciar"
// POST: El número de casillas usadas es 0

bool EstaVacioVectorDinamico (const VectorDinamico & v) 
{
	bool vacio = true;

	if (v.usados)
		vacio = false;

	return(vacio);
}


/***************************************************************************/
/***************************************************************************/
// Deja el vector dinámico vacío
// Argumentos: v (referencia) El vector que se va "vaciar"
// POST: El número de casillas usadas es 0

void EliminaTodosVectorDinamico (VectorDinamico & v) 
{
	// Hago que .datos apunte al inicio de v
	v.datos -= v.usados;
	
	// "vacío" el vector.
	v.usados = 0;
}


/*****************************************************************************/
/*****************************************************************************/
// Inicializa el vector dinámico, sustituyendo el contenido de todas
// las casillas usadas por el valor "valor".
// PRE: El vector debe existir

void EcualizaVectorDinamico (VectorDinamico & v, const TipoBase valor)
{
	// Método clásico para el resto de casos
	{
		for (int i = 0; i < v.usados; i++) {v.datos[i] = valor;}
	}
}


/***************************************************************************/
/***************************************************************************/
// Consulta y modifica el valor de una casilla dada. Si se utiliza como 
// rvalue se emplea para consultar el valor de la casilla "num_casilla". 
// Si se utiliza como lvalue se emplea para modificar el valor de la 
// casilla num_"casilla".
// 
// Argumentos: 	
//		v (referencia), referencia al vector. 
//		num_casilla, número de casilla (índice) en la que estamos interesados.
//
// PRE: 0<=num_casilla<UsadosVectorDinamico(v)

TipoBase &ValorVectorDinamico (VectorDinamico & v,const int num_casilla) 
{
	return *(v.datos+num_casilla);
}	


/***************************************************************************/
/***************************************************************************/
// Hace una copia profunda de origen en destino
// Si no tiene capacidad suficiente, destruye el vector y vuelve 
// a pedir memoria nueva adaptada al tamaño de origen

void ClonaVectorDinamico (VectorDinamico & destino,
						  const VectorDinamico & origen)
{
	// Si destino no es suficientemente grande, se rehace correctamente.
	if (destino.capacidad < origen.capacidad)
	{
		DestruyeVectorDinamico(destino);
		destino = CreaVectorDinamico(origen.capacidad, origen.tipo_redim);
	}

	// Copio los datos del vector origen a destino
	memcpy(destino.datos, origen.datos, sizeof(TipoBase)*origen.usados);
	destino.usados = origen.usados;
}

/***************************************************************************/
/***************************************************************************/
// Añade un valor al vector dinámico
// Argumentos: 	
//		v (referencia), referencia al vector que se va a modificar. 
//		valor, valor que se va a añadir al vector. 
// NOTA: Si no hay espacio libre, la función pide espacio adicional usando 
//		 la función RedimensionaVectorDinamico. 

void AniadeVectorDinamico (VectorDinamico &v, const TipoBase valor)
{
	// Redimensiona si así se requiere
	if (v.usados >= v.capacidad)
	{ 
		RedimensionaVectorDinamico(v);
	}

	// Se añade
	v.datos[v.usados] = valor;
	v.usados++;
}




/***************************************************************************/
/***************************************************************************/
// Inserta un valor en la casilla del vector dinámico dada
// Argumentos: 	
//		v (referencia), referencia al vector que se va a modificar. 
//		valor, valor que se va a añadir al vector. 
//		num_casilla, casilla donde se va a añadir el valor
// NOTA: Si no hay espacio libre, la función pide espacio adicional usando 
//		 la función RedimensionaVectorDinamico. 
// PRE: 0<=num_casilla<UsadosVectorDInamico(v)

void InsertaVectorDinamico (VectorDinamico &v, const TipoBase valor,
						   const int num_casilla)
{
	// Si la casilla donde se quiere insertar no está dentro del espacio
	// reservado, se amplía usados hasta que sea suficiente.
	if (num_casilla > v.usados)
	{
		//sumo 1 porque usados empieza a contar por 1 y "num_casillas" por 0
		v.usados = num_casilla+1;
	}
	
	// Redimensiona si el vector no tiene suficiente capacidad
	if (v.usados >= v.capacidad)
	{
		RedimensionaVectorDinamico(v);
	}

	TipoBase * pcasilla = v.datos+num_casilla;
	// Se desplaza parte del vector para hacer espacio.
	memmove(pcasilla+1, pcasilla, (v.usados-num_casilla)*sizeof(TipoBase));

	// Se inserta el valor exigido.
	*(pcasilla) = valor;
	v.usados++;
}


/***************************************************************************/
/***************************************************************************/
// ELimina un valor de la casilla del vector dinámico dada
// Argumentos: 	
//		v (referencia), referencia al vector que se va a modificar. 
//		num_casilla, casilla donde se va a eliminarse el valor 

void EliminaVectorDinamico (VectorDinamico &v, const int num_casilla)
{
	TipoBase * pcasilla = v.datos+num_casilla;

    memmove(pcasilla, pcasilla+1, (v.usados-num_casilla-1)*sizeof(TipoBase));

	v.usados--;
}


/***************************************************************************/
/***************************************************************************/
// Redimensiona el vector dinámico "v" de acuerdo al tipo de redimensi�n 
// registrado en "v". 
// Además, copia todos los datos en el nuevo vector.  
// Argumentos: 	
//		v (referencia), referencia al vector que se va a redimensionar. 
			
void RedimensionaVectorDinamico (VectorDinamico & v)
{
	// He aplicado la misma metodología que aplicamos
	// para lo argumentos del main, por legibilidad
	// (los elseif quedan feos).
	// No obstante el método "uno por uno" no será
	// un valor por default, simplemente va primero.
	// Esto se debe a la naturaleza del enum, donde
	// siempre se tendrá uno de los 3 valores.
	int nueva_capacidad = v.capacidad + 1;

	if ((int)v.tipo_redim > 1)
	{
		int nueva_capacidad = v.capacidad + TAM_BLOQUE;
		
		if ((int)v.tipo_redim > 2)
		{
			int nueva_capacidad = v.capacidad*2;
		}
	}
	// (No sé qué hace, pero estaba en el de base, asi que lo dejo)
    #ifdef DEBUG_FUNCS_VECTOR_DINAMICO_BASICO
	cout << endl;
	cout << "REDIMENSIONADO HASTA --> "<<nueva_capacidad << " CASILLAS"<< endl;
	cout << endl;
	#endif

	// Pedir memoria para el nuevo almacen 
	TipoBase * tmp = new TipoBase[nueva_capacidad]; 

	// Copia de los datos:
	memcpy (tmp, v.datos, v.usados*sizeof(TipoBase)); 
	
	// Liberar la memoria del antiguo almac�n
	delete [] v.datos; 

	// Actualizar vector din�mico redimensionado
	v.datos = tmp;
	v.capacidad = nueva_capacidad;
}


/***************************************************************************/
/***************************************************************************/
// Redimensiona un vector dinámico para que no haya espacio libre.
// Copia todos los datos en el nuevo vector.
// Argumentos: 	
//		v (referencia), referencia al vector que se va a reajustar. 
// POST: capacidad = usados

void  ReajustaVectorDinamico (VectorDinamico & v)
{
	int nueva_capacidad = v.usados;

	cout << endl;
	cout << "REAJUSTANDO HASTA --> "<<nueva_capacidad << " CASILLAS"<< endl;
	cout << endl;

	// Pedir memoria para el nuevo almacen 
	TipoBase * tmp = new TipoBase[nueva_capacidad]; 


	// Copio los datos
	memcpy (tmp, v.datos, v.usados*sizeof(TipoBase)); 
	
	// Liberar la memoria del antiguo almac�n
	delete [] v.datos; 

	// Actualizar vector din�mico redimensionado

	v.datos = tmp;
	v.capacidad = nueva_capacidad;
	// v.usados se mantiene como estaba
}

/***************************************************************************/
/***************************************************************************/
// Transforma una cadenad e caracteres a Tipobase
/*
TipoBase TransformaATipoBase(char * valor)
{
    return static_cast<TipoBase>(atoi(valor));
}
*/