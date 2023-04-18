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
    string separador =\
    "--------------------------------------------------------------\n";

//.......................................................................
        // Leo el primer bloque (departamento)

        cout << separador << "DEPARTAMENTOS: \n" << separador;
        int contador_dep = 0;

        getline(cin, linea);
        do
        {
            Departamento d(linea, '*');
            cout << d.ToString();
            contador_dep++;

        }while(getline(cin,linea) && linea != "FIN");

        cout << "Total Departamentos = " << contador_dep << endl << endl;


//.......................................................................
        // Leo el segundo bloque  (profesor)

        cout << separador << "PROFESORES: \n" << separador;
        int contador_prof = 0;

        getline(cin, linea);
        do
        {
            Profesor p(linea, '*');
            cout << p.ToString();
            contador_prof++;

        }while(getline(cin,linea) && linea != "FIN");

        cout << "Total Profesores = " << contador_prof << endl << endl;


//.......................................................................
        // Leo el tercer bloque (encargo)

        cout << separador << "ENCARGOS: \n" << separador;
        int contador_enc = 0;
        
        getline(cin, linea);
        do
        {
            Encargo e(linea, '*');
            cout << e.ToString();
            contador_enc++;

        }while(getline(cin,linea) && linea != "FIN");

        cout << "Total Encargos = " << contador_enc << endl << endl;


//.......................................................................
        // Leo el cuarto bloque (adscripción)

        cout << separador\
        << "ADSCRIPCIONES DE PROFESORES A DEPARTAMENTOS: \n"\
        << separador;
        int contador_ads = 0;
        
        getline(cin, linea);
        do
        {
            Adscripcion a(linea, '*');
            cout << a.ToString();
            contador_ads++;

        }while(getline(cin,linea) && linea != "FIN");

        cout << "Total Adscripciones = " << contador_ads << endl << endl;

}
