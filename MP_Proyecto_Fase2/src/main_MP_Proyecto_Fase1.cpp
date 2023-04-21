/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// AUTOR: MARCO GIRELA VIDA
// GRUPO: 1ºB
// FECHA: 08/04/2023
//
// PROYECTO FASE 1
//
//  Fichero main del proyecto.+
//  Se encarga de leer un archivo de texto y mostrar los datos leidos.
//
// Fichero: main_MP_Prooyecto_Fase01.cpp
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include <cstring>
#include <string>


#include "Departamento.h"
#include "Profesor.h"
#include "Encargo.h"
#include "Adscripcion.h"
#include "utils.h"
#include "Fecha.h"  

using namespace std;

int main()
{
    string linea;
    string TERMINADOR = "FIN";
    string separador =\
    "--------------------------------------------------------------\n";

//.......................................................................
        // Leo el primer bloque (departamento)

        cout << separador << "DEPARTAMENTOS: \n" << separador;
        int contador_dep = 0;

        getline(cin, linea);

        while( linea != TERMINADOR)
        {
            contador_dep++;

            Departamento d(linea, '*');
            cout << d.ToString();

            // Leo la siguiente linea
            getline(cin,linea);
        }

        cout << "Total Departamentos = " << contador_dep << endl << endl;


//.......................................................................
        // Leo el segundo bloque  (profesor)

        cout << separador << "PROFESORES: \n" << separador;
        int contador_prof = 0;

        getline(cin, linea);

        while( linea != TERMINADOR)
        {
            contador_prof++;

            Profesor p(linea, '*');
            cout << p.ToString(true);
            
            getline(cin,linea);
        }

        cout << "Total Profesores = " << contador_prof << endl << endl;


//.......................................................................
        // Leo el tercer bloque (encargo)

        cout << separador << "ENCARGOS: \n" << separador;
        int contador_enc = 0;
        
        getline(cin, linea);

        while( linea != TERMINADOR)
        {
            contador_enc++;

            Encargo e(linea, '*');
            cout << e.ToString();
            
            getline(cin,linea);
        }

        cout << "Total Encargos = " << contador_enc << endl << endl;


//.......................................................................
        // Leo el cuarto bloque (adscripción)

        cout << separador\
        << "ADSCRIPCIONES DE PROFESORES A DEPARTAMENTOS: \n"\
        << separador;
        int contador_ads = 0;
        
        getline(cin, linea);
        while( linea != TERMINADOR)
        {
            contador_ads++;

            Adscripcion a(linea, '*');
            cout << a.ToString();

            getline(cin,linea);
        }

        cout << "Total Adscripciones = " << contador_ads << endl << endl;

}
