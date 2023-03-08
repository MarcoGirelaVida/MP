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