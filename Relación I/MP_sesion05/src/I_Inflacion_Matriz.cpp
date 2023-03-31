/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// AUTOR: MARCO GIRELA VIDA
// GRUPO: 1ºB
// FECHA: xx/03/2023
//
// RELACION DE PROBLEMAS 1
//
//  
// 
//
// Declaraciones en: 
//
// Fichero: I_Inflacion_Matriz.cpp
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>

using namespace std;

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

/***************************************************************************/
// Devuelve el IPC de un año dado (fila) para un pais dado (columna).
// Parámetros: MATRIZ_IPC, dirección de inicio de la matriz de IPCs.
//             anio, el año en el que estamos interesados.
//                pais, el pais (índice) en el que estamos interesados.
// Devuelve: el valor del IPC en "anio" para el "pais"
//
// PRE: PRIMER_ANIO <= anio <= ULTIMO_ANIO
// PRE: 0  <= pais <= NUM_PAISES

const double Valor_IPC (const double MATRIZ_IPC[][NUM_PAISES], 
                        int anio, int pais);

/***************************************************************************/
// Devuelve el nombre de un pais, dado su indice.
// El aray está relacionado con las columnas de la matriz IPC.
// Parámetros: VECTOR_PAISES, inicio del array de nombres de paises,  
//                            num_pais, índice del pais.
// Devuelve: el nombre del pais.
//
// PRE: PRE: 0  <= pais <= NUM_PAISES

const char * NombrePais (const char * VECTOR_PAISES[], int pais);

/***************************************************************************/
/***************************************************************************/
// Calcula el IPC medio de un pais en un periodo dado
// Parámetros: MATRIZ_IPC, dirección de inicio de la matriz de IPCs.
//             el_pais, el número de pais.
//               los_anios, el número de anios del periodo.
//               el_primer_anio, el primer año del periodo.
// Devuelve: el IPC medio del pais "el_pais" en  "los_anios" anios.
//
// PRE: 0 <= el_pais < NUM_PAISES
// PRE: PRIMER_ANIO <= el_primer_anio <= ULTIMO_ANIO-los_anios+1 
// PRE: MIN_NUM_ANIOS <= los_anios <= MAX_NUM_ANIOS 


double CalculaMedia_PaisPeriodo (const double MATRIZ_IPC [][NUM_PAISES], 
                             int el_pais, int los_anios, int el_primer_anio);

const int NUM_PAISES = 4;
// Tras mucho tiempo probando cosas, no he encontrado
// otra solución para que no me digan "NUM_PAISES" is undefined sin tener
// que modificar las cabeceras que nos pide en el ejercicio para las funciones.
// Asi que no me ha quedado otra opción.
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

int main(int argc, char **argv)
{
/*****************************************************************************/
// DECLARACIÓN DE LA MATRIZ Y OTRAS VARIABLES
    const double IPC[] [NUM_PAISES]= 
    { 
    { 2.7,  1.07,  1.6,  2.1}, // 2022
    { 4.0,  1.69,  2.4,  2.3}, 
    { 2.6,  1.25,  1.9,  2.0}, 
    { 3.2,  1.64,  3.3,  2.4}, 
    { 3.7,  1.92,  3.4,  2.2}, 
    { 2.7,  2.97,  2.5,  1.9}, 
    { 4.2,  2.12,  4.1,  3.1}, 
    { 1.4,  3.11,  0.1,  1.6}, 
    { 0.8,  2.83,  2.7,  0.9}, 
    { 3.0,  3.73,  1.5,  2.2}, 
    { 2.4,  4.20,  3.0,  2.8}, 
    { 2.9,  2.71,  1.7,  2.2}, 
    { 0.3,  2.00,  1.5,  0.8}, 
    {-1.0,  0.55,  0.8, -0.2}, 
    { 0.0,  2.23,  0.7,  0.2}, 
    { 1.6,  1.60,  2.1,  1.1}, 
    { 1.1,  2.90,  2.1,  1.3}, 
    { 1.2,  2.10,  1.9,  1.5}, 
    { 0.8,  1.30,  2.3,  1.3}, 
    {-0.5,  0.60,  1.4, -0.3},
    { 6.5,  5.40,  7.0,  5.0} //2001
    };
    const char * PAISES[] = { "ESPANIA",  "INGLATERRA", "EEUU",  "ZONA EURO"};

    int num_anios = 0;
    int max_anio = 0;
    int anio_inic = 0;
    double Mayor_IPC = 0;
    int Mayor_pais = 0;
    double Menor_IPC = 100; 
    int Menor_pais = 0;
    double IPC_pais = 0;
    const int NUM_PAISES = 0;

/*****************************************************************************/
// COMPRBACIÓN VALIDEZ DE LOS ARGUMENTOS MAIN
    if (argc > 2)
    {
        cerr << "Error: demasiados argumentos" << endl;
        exit (1);
    }

    if (argc > 1)
    {
        num_anios = atoi(argv[1]);
    }

	// Comprobar la validez de "usados"
	if (num_anios < 2 || num_anios > 5)
    {
        cerr << "Error, numero de años incorrecto. "; 
        cerr << "Debe ser entre 2 y 5" << endl << endl;
        exit (1);
    }

    // Adapto la decisión del usuario al problema

    if (num_anios == 2)
        max_anio = 2020;

    else if (num_anios == 3)
        max_anio = 2019;

    else if (num_anios == 4)
        max_anio = 2018;
    
    else
        max_anio = 2017;


	// Fin comprobación argumentos
/*****************************************************************************/

    // INPUT: Se solicita el pais inicial
    cout << "Año inicial ( 2001-" << max_anio << "): ";
    cin >> anio_inic;

    while (anio_inic < 2001 || anio_inic > max_anio)
    {

        cout << "Introduzca una opción válida: ";
        cin >> anio_inic;

    }
    cout << endl << endl;

/*****************************************************************************/
// PROCESAMIENTO: Se llama a la funcion CalcularMedia para hallar
// los paises con mayor y menor IPC

    // MAYOR IPC

    for (int i = 0; i < 4; i++)
    {
        IPC_pais = CalculaMedia_PaisPeriodo(IPC, i, num_anios, anio_inic);

        if (IPC_pais > Mayor_IPC){
            Mayor_IPC = IPC_pais;
            Mayor_pais = i;
        }
    }
/*...........................................................................*/
    // MENOR IPC

    for (int i = 0; i < 4; i++){
    
        IPC_pais = CalculaMedia_PaisPeriodo(IPC, i, num_anios, anio_inic);

        if (IPC_pais < Menor_IPC){
            Menor_IPC = IPC_pais;
            Menor_pais = i;
        }

    }

/*****************************************************************************/
    
    // OUTPUT: Se muestran el mayor/menor IPC con sus paises


    cout << "MAYOR IPC MEDIO" << endl;
    cout << "Media: " << Mayor_IPC << endl;
    cout << "Pais: " << NombrePais(PAISES, Mayor_pais) << endl;
    cout << "Años: " << anio_inic << " - ";
    cout << anio_inic + num_anios - 1 << endl << endl;



    cout << "MENOR IPC MEDIO" << endl;
    cout << "Media: " << Menor_IPC << endl;
    cout << "Pais: " << NombrePais(PAISES, Menor_pais) << endl;
    cout << "Años: " << anio_inic << " - ";
    cout << anio_inic + num_anios - 1 << endl << endl;
}

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

/***************************************************************************/
// Devuelve el IPC de un año dado (fila) para un pais dado (columna).
// Parámetros: MATRIZ_IPC, dirección de inicio de la matriz de IPCs.
//             anio, el año en el que estamos interesados.
//                pais, el pais (índice) en el que estamos interesados.
// Devuelve: el valor del IPC en "anio" para el "pais"
//
// PRE: PRIMER_ANIO <= anio <= ULTIMO_ANIO
// PRE: 0  <= pais <= NUM_PAISES

const double Valor_IPC (const double MATRIZ_IPC[][NUM_PAISES], 
                        int anio, int pais)
{
    return MATRIZ_IPC[anio-2001][pais];
}

/*********************************************************************/
// Devuelve el nombre de un pais, dado su indice.
// El aray está relacionado con las columnas de la matriz IPC.
// Parámetros: VECTOR_PAISES, inicio del array de nombres de paises,  
//                            num_pais, índice del pais.
// Devuelve: el nombre del pais.
//
// PRE: PRE: 0  <= pais <= NUM_PAISES

const char * NombrePais (const char * VECTOR_PAISES[], int pais)
{
    /*
    while (*VECTOR_PAISES[pais] != '\0')
    {
        cout << *VECTOR_PAISES[pais];
        VECTOR_PAISES[pais]++;
    }
    */
    return VECTOR_PAISES[pais];
}

/***************************************************************************/
/***************************************************************************/
// Calcula el IPC medio de un pais en un periodo dado
// Parámetros: MATRIZ_IPC, dirección de inicio de la matriz de IPCs.
//             el_pais, el número de pais.
//               los_anios, el número de anios del periodo.
//               el_primer_anio, el primer año del periodo.
// Devuelve: el IPC medio del pais "el_pais" en  "los_anios" anios.
//
// PRE: 0 <= el_pais < NUM_PAISES
// PRE: PRIMER_ANIO <= el_primer_anio <= ULTIMO_ANIO-los_anios+1 
// PRE: MIN_NUM_ANIOS <= los_anios <= MAX_NUM_ANIOS 

double CalculaMedia_PaisPeriodo (const double MATRIZ_IPC [][NUM_PAISES], 
                             int el_pais, int los_anios, int el_primer_anio)
{
    double sumatoria = 0;

    for (int i=0; i < los_anios; i++)
    {
        sumatoria += Valor_IPC(MATRIZ_IPC, el_primer_anio+i, el_pais);
    }

    return(sumatoria/los_anios);
}