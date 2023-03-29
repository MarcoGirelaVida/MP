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
#include <fstream>
#include <sstream>

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


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

int main()
{
/***************************************************************************/
/***************************************************************************/
// IMPORTANDO ARCHIVO .TXT A LA MATRIZ

    //Abro el archivo
    ifstream archivo("inflacion.txt");

    // Declaro vector de paises.
    const int columnas = 5;
    const char * ppaises[columnas];

    // Leo primera fila del archivo y almaceno el nombre de los paises
    string linea;
    getline(archivo, linea);
    istringstream siguiente_elemento(linea);

    for (int j = 0; j < columnas; j++)
    {
        siguiente_elemento >> *(ppaises[j]);
    }

    // Declaro vector de años
    const int filas = 23;
    int anios[filas];

    // Declaro m_IPC para almacenar números
    double m_IPC[filas][columnas-1];

    // Leer filas restantes del archivo y almacenar en la m_IPC
    for (int i = 0; i < filas; i++)
    {
        // Leo la siguiente linea y la "meto" en siguiente
        getline(archivo, linea);
        istringstream siguiente_elemento(linea);

        // Mete el primer valor de cada columna en anios
        siguiente_elemento >> anios[i];

        for (int j = 0; j < columnas - 1; j++)
        {
            siguiente_elemento >> m_IPC[i][j];
        }
    }

    // Cierro el archivo.
    archivo.close();

/***************************************************************************/
/***************************************************************************/

    
}

