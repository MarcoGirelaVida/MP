/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// AUTOR: MARCO GIRELA VIDA
// GRUPO: 1ºB
// FECHA: 08/04/2023
//
// PROYECTO FASE 4
//
//  Fichero main del proyecto.+
//  Se encarga de leer un archivo de texto y mostrar los datos leidos.
//
// Fichero: main_MP_Proyecto_Fase04.cpp
//
/***************************************************************************/
/***************************************************************************/
#include <iostream>

#include "VectorDepartamento.h"
#include "VectorProfesor.h"
#include "VectorEncargo.h"
#include "VectorAdscripcion.h"

using namespace std;

int main()
{
    string linea;
    string TERMINADOR = "FIN";
    string separador =\
    "--------------------------------------------------------------\n";

// Inicializo los múltiples vectores
	VectorDepartamento vdep;
	VectorProfesor vprof;
	VectorEncargo venc;
	VectorAdscripcion vads;

/*****************************************************************************/
//--------------------------LECTURA DE DATOS------------------------------//
/*****************************************************************************/
//.......................................................................
        // Leo el primer bloque (departamento)

        cout << separador << "DEPARTAMENTOS: \n" << separador;
        int contador_dep = 0;
        getline(cin, linea);

        while( linea != TERMINADOR)
        {	
            Departamento d(linea, '*');
			vdep.AniadeDepartamento(d);
            // Leo la siguiente linea
            getline(cin,linea);
        }

        cout << "Total Departamentos = " << vdep.Totalutilizados() << endl << endl;

//.......................................................................
        // Leo el segundo bloque  (profesor)

        cout << separador << "PROFESORES: \n" << separador;
        int contador_prof = 0;

        getline(cin, linea);

        while( linea != TERMINADOR)
        {
            Profesor p(linea, '*');
            vprof.AniadeProfesor(p);
            
            getline(cin,linea);
        }

        cout << "Total Profesores = " << vprof.Totalutilizados() << endl << endl;


//.......................................................................
        // Leo el tercer bloque (encargo)

        cout << separador << "ENCARGOS: \n" << separador;
        
        getline(cin, linea);

        while( linea != TERMINADOR)
        {
            Encargo e(linea, '*');
			venc.AniadeEncargo(e);
	
            getline(cin,linea);
        }

        cout << "Total Encargos = " << venc.Totalutilizados() << endl << endl;


//.......................................................................
        // Leo el cuarto bloque (adscripción)

        cout << separador\
        << "ADSCRIPCIONES DE PROFESORES A DEPARTAMENTOS: \n"\
        << separador;
        
        getline(cin, linea);
        while( linea != TERMINADOR)
        {
            Adscripcion a(linea, '*');
            vads.AniadeAdscripcion(a);

            getline(cin,linea);
        }

        cout << "Total Adscripciones = " << vads.Totalutilizados() << endl << endl;

/*****************************************************************************/
//--------------------------FIN LECTURA DE DATOS------------------------------//
/*****************************************************************************/


/*****************************************************************************/
//--------------------------MOSTRAR DATOS-------------------------------------//
/*****************************************************************************/
//.......................................................................
        // Muestro el primer bloque (departamento)

        cout << separador << "DEPARTAMENTOS: \n" << separador;
		cout << "Capacidad =  " << vdep.Capacidad() \
			 << ".  Usados =  " << vdep.Totalutilizados()\
			 << endl;
			
        vdep.Serializar();
		cout << endl;

//.......................................................................
        // Muestro el segundo bloque  (profesor)

        cout << separador << "PROFESORES: \n" << separador;
		cout << "Capacidad =  " << vprof.Capacidad() \
			 << ".  Usados =  " << vprof.Totalutilizados()\
			 << endl;
			
        vprof.Serializar();
		cout << endl;

//.......................................................................
        // Muestro el tercer bloque (encargo)

        cout << separador << "ENCARGOS: \n" << separador;
		cout << "Capacidad =  " << venc.Capacidad() \
			 << ".  Usados =  " << venc.Totalutilizados()\
			 << endl;
			
        venc.Serializar();
		cout << endl;

//.......................................................................
        // Muestro el cuarto bloque (adscripción)

        cout << separador\
        << "ADSCRIPCIONES DE PROFESORES A DEPARTAMENTOS: \n"\
        << separador;
        
		cout << "Capacidad =  " << vads.Capacidad() \
			 << ".  Usados =  " << vads.Totalutilizados()\
			 << endl;
			
		vads.Serializar();
		cout << endl;

/*****************************************************************************/
//--------------------------FIN MOSTRAR DATOS------------------------------//
/*****************************************************************************/

	return 0;
}
