/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 2
//
// Fichero: II_Demo-VectorDinamico.cpp
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>

#include "Funcs_ColeccionCadenas.h"
#include "FuncsVectorDinamicostring.h"

using namespace std; 

// Me imagino que ninguna linea tendrá + de 100 caracteres
const int MAX_LINEA = 100;

/***************************************************************************/
/***************************************************************************/
int main ()
{
    int ultima_linea = 0;
    int num_lineas_no_vacias = 0;
    int num_parrafos = 0;
    ColeccionCadenas v = CreaColeccionCadenas();
	//.......................................................................
	// INPUT: Rellenar "v": se termina al encontrar EOF en cin 

	string cadena; // Para leer cada una de las cadenas 

    while (getline (cin, cadena))
    {   
		// Reservar memoria para la cadena cl�sica. 
		// Se necesita un car�cter m�s que la longitud de "cadena". 
		// La longitud de "cadena" se calcula con el m�todo "length" de string

		int long_cadena = cadena.length();
		char * cadena_nueva = new char [long_cadena+1];

		strcpy(cadena_nueva, cadena.c_str());	

        AniadeCadenaColeccionCadenas (v, cadena_nueva); 

        MostrarColeccionCadenas (v);

        // Libero cadena_nueva
		delete [] cadena_nueva;
    }

    CalculosLineasColeccionCadenas(v, ultima_linea, num_lineas_no_vacias,
                                    num_parrafos);

    // OUTPUT: Muestro la información del fichero al usuario                         
    cout << "Num parrafos: " << num_parrafos << endl;
    cout << "Num lineas: " << ultima_linea << endl;
    cout << "Num lineas vacias: " << num_lineas_no_vacias << endl;
    cout << endl;

/***************************************************************************/
// PROCESAMIENTO: Se va a pasar todo el contenido de v a v_dinamico

    // Creo un vector dinámico con redimensión de 1en1 para ocupar lo justo
    // Aquí es donde se guardará la unión de todas las lineas.
    VectorDinamico v_dinamico = CreaVectorDinamico(1,
                                TipoRedimension::DeUnoEnUno);
    
    // For para ir linea por línea cogiendo el contenido
    for (int i = 0; i < ultima_linea; i++)
    {
        // Guardo el contenido de cada linea en el vector tmp
        // Además lo inicializo en cada iteración, para poder
        // borrarlo y no ocupar espacio innecesario.
        char * tmp = new char[MAX_LINEA];
        ExtraeCadenaColeccionCadenas(tmp, v, i);
        int tam_tmp = 0;

        // Calculo el número de caracteres usados de tmp
        char * p_tmp = tmp;
        while (*p_tmp != '\0')
        {
            p_tmp++;
            tam_tmp++;
        }

        // Añado el contenido de tmp a v_dinamico
        for (int i = 0; i <= tam_tmp; i++)
        {
            AniadeVectorDinamico(v_dinamico, (TipoBase) tmp[i]);
        }
        
        // Libero la memoria de tmp
        delete [] tmp;

    } // for
    
    
/***************************************************************************/
// OUTPUT: Muestro el contenido de v_dinamico al usuario
    int tam_vdin = UsadosVectorDinamico(v_dinamico);
    
    for (int i = 0; i < tam_vdin; i++)
    {
        cout << (char) ValorVectorDinamico(v_dinamico,i);
    }
    cout << endl << endl;

    DestruyeVectorDinamico(v_dinamico);
    return 0;
}