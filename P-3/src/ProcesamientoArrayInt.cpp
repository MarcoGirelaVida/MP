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



/*********************************************************************/
// Muestra un vector dado 
// PRE: 

void MuestraVector (const char *msg, int *p, int n_datos, int datos_linea)
{

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
//
// PRE:

void OrdenaSeleccion (int *v, int pos_inic, int pos_fin)
{

}



/*********************************************************************/
//
// PRE:

void OrdenaInsercion (int *v, int pos_inic, int pos_fin)
{

}



/*********************************************************************/
//
// PRE:

void OrdenaIntercambio (int *v, int pos_inic, int pos_fin)
{

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
/*********************************************************************/