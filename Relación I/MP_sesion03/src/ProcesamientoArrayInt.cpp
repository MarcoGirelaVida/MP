/*********************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIER�A INFORMATICA
//
// AUTOR: MARCO GIRELA VIDA
// GRUPO: B
//
// PRACTICA 3 - FUNCIONES
/*	
	Funciones convenientes para el procesamiento de arrays de enteros.
*/
/*********************************************************************/

#include <iostream>
#include <random>  // para la generaci�n de n�meros pseudoaleatorios
#include <chrono>  // para la semilla

using namespace std;

/***************************************************************************/
// Clase: GeneradorAleatorioEnteros
/*
	Sirve para generar n�meros aleatorios enteros en un rango de valores.
	
	Hay crear un objeto de esta clase. Se dispone de dos constructores: 
	1) GeneradorAleatorioEnteros()
	   		El primero no tiene par�metros y establece que �nicamente se 
			van a generar ceros y unos (este constructor llama al segundo). 
	2) GeneradorAleatorioEnteros(int min, int max)
		El segundo tiene dos par�metros, "min" y "max" que delimitan el 
		rango correspondiente. 

	Finalmente, el m�todo 
	
		int Siguiente()
	
	devolver� un valor aleatorio en el rango especificado en el constructor.
*/
/***************************************************************************/
/////////////////////////////////////////////////////////////////////////////
class GeneradorAleatorioEnteros
{  
private:
	
	mt19937 generador_mersenne;    // Mersenne twister
	uniform_int_distribution<int>  distribucion_uniforme;
	
	/************************************************************************/
	
	long long Nanosec(){
		return (chrono::high_resolution_clock::now().time_since_epoch().count());
	}
	
	/************************************************************************/ 
	
public:
	
	/************************************************************************/
		
	GeneradorAleatorioEnteros() : GeneradorAleatorioEnteros(0, 1) 
	{ }
	
	/************************************************************************/  
	GeneradorAleatorioEnteros(int min, int max) {
	
		const int A_DESCARTAR = 70000;
		// ACM TOMS Volume 32 Issue 1, March 2006
		
		auto semilla = Nanosec();
		generador_mersenne.seed(semilla);
		generador_mersenne.discard(A_DESCARTAR);
		distribucion_uniforme = uniform_int_distribution<int> (min, max);
	}
	
	/************************************************************************/
	
	int Siguiente(){
	  return (distribucion_uniforme(generador_mersenne));
	}
	
	/************************************************************************/

};


/////////////////////////////////////////////////////////////////////////////


// Muestra un vector dado 
// PRE: Vector y longitud que se quiere mostrar
    void imprimirVector(int *v, int n)
    {
        cout << "El vector final queda de la siguiente manera: " << endl;
        for (int i = 0; i < n; i++)
        {
            cout << *(v+i) << " ";
        }
        cout << endl;
    }



/*********************************************************************/
// Rellena un vector con números aleatorios dado un rango.
// PRE:
//      p[]: Un puntero al inicio del vector que queremos rellenar
//      num_datos: Número de datos que queremos rellenar
//      min_aleat: Mínimo a partir del que se generan los números aleatorios
//      max_aleat: Máxima a partir del que se generan los números aleatorios.

void RellenaVector(int p[], int num_datos, int min_aleat, int max_aleat)
{
    GeneradorAleatorioEnteros generador(min_aleat, max_aleat);

    for (int i = 0; i < num_datos; ++i)
    {
        p[i] = generador.Siguiente();
    }
}



/*********************************************************************/
// En cada iteración, se selecciona la componente más pequeña del
//sub-vector derecho y se coloca al final del sub-vector izquierdo.
// PRE:
//      *v : Puntero al inicio del vector que se quiere ordenar.
//      izda : Posición de v a partir de la que se desea ordenar.
//      pos_fin : Ultima pos de v que se quiere ordenar

void OrdenaSeleccion (int *v, int izda, int pos_fin)
{

    int pos_min;
    int min;
    int intercambia;    

    for (int izda = 0 ; izda < pos_fin-1; izda++)
    {
        min = *(v+izda);
        pos_min = izda;
        for (int i = izda + 1; i < pos_fin; i++)
        {
            if (*(v+i) < min)
            {
                min = *(v+i);
                pos_min = i;
            }
        }
        intercambia = *(v+izda);
        *(v+izda) = min;
        *(v+pos_min) = intercambia;
    }
}




/*********************************************************************/
//Al igual que antes, a la izquierda se va dejando un subvector ordenado.
//Desde el final y hacia atrás, se van comparando elementos dos a dos y
//se deja a la izquierda el más pequeño (intercambiándolos).
// PRE:
//      pv: puntero a una casilla de un vector dado;
//      pos_inic: límite inferior a partir de pv desde el que se quiere buscar.
//      pos_fin: límite superior a partir de pv desde el que se quiere buscar.

void OrdenaIntercambio(int *v, int pos_inic, int pos_fin)
{
    bool cambio = true;

    for (int *i = v + pos_inic; i < (v + pos_fin) && cambio; i++)
    {
        cambio = false;

        for (int *j = v + pos_fin - 1; j > i; j--)
        {
            if (*j < *(j-1))
            {
                cambio = true;
                int temp = *j;
                *j = *(j-1);
                *(j-1) = temp;
            }
        }
    }
}




/*********************************************************************/
//  El vector se divide en dos sub-vectores: el de la izquierda ordenado,
//y el de la derecha desordenado.
//  Cogemos el primer elemento del subvector desordenado y lo insertamos
//de forma ordenada en el subvector de la izquierda (el ordenado).
// PRE:
//      pv: puntero a una casilla de un vector dado;
//      pos_inic: límite inferior a partir de pv desde el que se quiere buscar.
//      pos_fin: límite superior a partir de pv desde el que se quiere buscar.

void OrdenaInsercion (int *v, int pos_inic, int pos_fin)
{

    int a_desplazar;
    int i;

    for (int pos_inic = 1; pos_inic < pos_fin; pos_inic++)
    {
        a_desplazar = *(v+pos_inic);

        for (i = pos_inic; i > 0 && a_desplazar < *(v+i-1); i--)
            *(v+i) = *(v+i-1);

        *(v+i) = a_desplazar;
    }

}

/*********************************************************************/
// Comprueba la validez de un dato a corde a unos parametros dados
// PRE:
//      pv: puntero a una casilla de un vector dado;
//      izda: límite inferior a partir del que se puede definir.
//      dcha: límite superior a partir del que se puede definir.
bool datovalido(int dato, int izda, int dcha)
{
    if (dato >= izda)
    {
        return true;
    }
    else if (dato <= dcha)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}


/*********************************************************************/
// Devuelve un puntero al mayor val de un intervalo contenido en un vector.
// PRE:
//      pv: puntero a una casilla de un vector dado;
//      izda: límite inferior a partir de pv desde el que se quiere buscar.
//      dcha: límite superior a partir de pv desde el que se quiere buscar.

int * PosMayor(int * pv, int izda, int dcha)
{
    // Inicializo el vector 'pMayor' a la primera dirección a partir de la
    // que quiero buscar el mayor.

    int * pMayor = pv + izda;

/*  
    A lo largo del fragmento solicitado comparo el contenido de cada de
    dirección con el del mayor valor hasta el momento (almacenado en el
    puntero 'pMayor').
    Si el contenido comparado es mayor que el contenido de pMayor, este
    se actualiza.
*/
    for (int i = izda; i <= dcha; i++)
    {
        if (*(pv + i) > *pMayor)
        {
            pMayor = pv + i;
        }
    }
    return pMayor;
}
/*
Nótese que he hecho uso de la sintaxis de corchetes puesto que la
encuentro más intuitiva, no obstante podría haberlo hecho con sintaxis
de asteriscos y hubiera quedado de la siguiente manera:

int* PosMayor(int* v, int izda, int dcha)
{
    int* pMayor = v + izda;
    for (int i = izda; i <= dcha; i++)
    {
        if (*(v + i) > *pMayor)
        {
            pMayor = v + i;
        }
    }
    return pMayor;
}

*/
/*********************************************************************/