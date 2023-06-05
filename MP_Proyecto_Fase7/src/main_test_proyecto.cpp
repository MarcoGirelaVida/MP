#include <iostream>
#include <fstream>
#include <iomanip>

#include "Departamento.h"
#include "VectorDepartamento.h"

#include "Adscripcion.h"
#include "VectorAdscripcion.h"

#include "Encargo.h"
#include "VectorEncargo.h"

#include "Profesor.h"
#include "VectorProfesor.h"

using namespace std;






// DECLARACION FUNCIONES
double potencial_docente_departamento(string Id_Depto,\
								   VectorDepartamento& departamentos,\
								   VectorAdscripcion& adscripciones,\
								   VectorEncargo& encargos,\
								   VectorProfesor& profesores);

int contar_prof_departamento(string Id_Depto, VectorAdscripcion& adscripciones);

string Cabecera (const char * titulo);

bool fichero_correcto (string nombre_fichero);






int main(int argc, char * argv[]){


    // Compruebo el número de argumentos

    if (argc < 3){

        cerr << "EL número de argumentos es incorrecto." << endl;
        cerr << "Uso: " << argv[0] << " <fichero_potencial> <IDs>" << endl;
        return 1;

    }

    // Antes de hacer ningún cálculo, hay que abrir los ficheros de datos,
    // y para eso, necesitamos un fichero con los nombres válido

    fichero_correcto(argv[1]);

    // Ahora vamos leyendo los ficheros
    // Hasta saber como, supongo que están en orden y sin estar repetidos


/******************************************************************************/
/***************************FASE LECTURA***************************************/
/******************************************************************************/
    ifstream fi;
    fi.open(argv[1]);

    if (!fi){

        cerr << "No se ha podido abrir el fichero " << argv[1] << endl;
        return (1);

    }

	// LEO LA CABECERA
    string linea;
    getline(fi,linea);
	if (linea != "GESTION_DOCENTE")
	{
		cerr << "Error: No se ha encontrado la cabecera del fichero cfg\n"; 
	}

    // IGNORO COMENTARIOS

    while (linea.at(0) == '#'){

        getline(fi,linea);


    }

    string clase;
    string fichero;
    string ficheroEncargos;
    string ficheroAdscripciones;
    string ficheroDepartamentos;
    string ficheroProfesores;


    do{


        clase = linea.substr(1,linea.find(']') - 1);
        fichero = linea.substr(linea.find(' ') + 1, string::npos);

        if (clase == "DEPARTAMENTOS"){

            ficheroDepartamentos = fichero;

        }

        else if (clase == "ENCARGOS"){

            ficheroEncargos = fichero;

        }

        else if (clase == "ADSCRIPCIONES"){

            ficheroAdscripciones = fichero;

        }

        else if (clase == "PROFESORES"){

            ficheroProfesores = fichero;

        }

    
    }while (getline(fi,linea));

    VectorDepartamento departamentos (ficheroDepartamentos);
    VectorAdscripcion adscripciones (ficheroAdscripciones);
    VectorEncargo encargos (ficheroEncargos);
    VectorProfesor profesores (ficheroProfesores);

/***********************FIN FASE LECTURA***************************************/


/******************************************************************************/
/**********************FASE DE CÁLCULO Y SERIALIZACIÓN*************************/
/******************************************************************************/

    // Primero me piden que calcule el potencial

    // Debo recorrer cada departamento y comprobar qué profesores pertenecen
    // a el, para comprobar que tipo de encargos tiene, y sumarlo al total


    // Vector que almacenará el potencial docente
    int tam_potencial = argc-2;
    double potencial_docente[tam_potencial];
    int prof_por_dep[tam_potencial];

    for (int i=3; i <= argc ; i++)
	{
        string Id_Depto = argv[i-1];
		bool existe_departamento = (departamentos && Id_Depto);
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2);

        cout << "DEPARTAMENTO " << departamentos[i-2].GetId_Dpto() << " --> ";

		if (existe_departamento)
		{
			potencial_docente[i-3] = potencial_docente_departamento(Id_Depto,\
												departamentos, adscripciones,\
												encargos, profesores);

			prof_por_dep[i-3]=contar_prof_departamento(Id_Depto, adscripciones);
		
			cout << " Num.Profesores = " << setw(3) << prof_por_dep[i-3]\
				 << "   Potencial =   " << potencial_docente[i-3] << endl;
		}
		else
        {
			cerr << "Error: El departamento no existe\n";	
		}

		cout << endl;
		
    }

    return 0;

}



// FUNCIONES COMPLEMENTARIAS

int contar_prof_departamento(string Id_Depto, VectorAdscripcion& adscripciones)
{
	int num_profesores = 0;
	for (int j=1; j<=adscripciones.Totalutilizados(); j++)
	{
	    // Si el profesor pertenece a ese departamento lo añado
	    if(adscripciones[j].getIdDepartamento() == Id_Depto)
		{
			num_profesores++;
	    }
	}
	
	return num_profesores;
}



double potencial_docente_departamento(string Id_Depto,\
								   VectorDepartamento& departamentos,\
								   VectorAdscripcion& adscripciones,\
								   VectorEncargo& encargos,\
								   VectorProfesor& profesores)
{
	double potencial_docente = 0;

    // Recorro el vector de Adscripciones en busca de aquellos profesores
    // que pertenezcan a este departamento

    for (int j=1; j<=adscripciones.Totalutilizados(); j++)
	{
        // Si el profesor pertenece a ese departamento,
        // compruebo su encargo

        if(adscripciones[j].getIdDepartamento() == Id_Depto)
		{

            string dni_profesor = adscripciones[j].getDniProfesor();
            
            // Ahora busco al profesor con dicho dni y 
            // extraigo su encargo

            for (int k=1; k<=profesores.Totalutilizados(); k++)
			{                
                if (profesores[k].getDni() == dni_profesor)
				{
                    // Obtengo el número de encargo
                    // y compruebo su valor

                    int num_categoria = profesores[k].getCategoria();

                    for (int l=1; l<=encargos.Totalutilizados(); l++)
					{
                        // Extraigo el valor y lo sumo al total
                        if (encargos[l].getCategoria() == num_categoria)
						{
                            potencial_docente += encargos[l].getCreditos();
                        }
                    }   
                }
            }
        }
    }

	return potencial_docente;
}


string Cabecera (const char * titulo)
{
	const int TAM_GUIONES = 70; 
	char guiones[TAM_GUIONES]; 

	memset (guiones, '-', TAM_GUIONES-1); 
	guiones[TAM_GUIONES-1] = '\0'; 

	string cad_guiones (guiones); 

	string cad;

	cad = cad + cad_guiones + "\n";
	cad = cad + titulo + "\n";
	cad = cad + cad_guiones + "\n";

	return cad; 
}



bool fichero_correcto (string nombre_fichero)
{

    bool fichero_correcto = false;
    ifstream fichero;

    fichero.open(nombre_fichero);

    if (!fichero){

        cerr << "No se ha podido abrir el fichero " << nombre_fichero << endl;
        exit (1);

    }

    string cabecera;
    getline(fichero, cabecera);

    if (cabecera == "GESTION_DOCENTE")
        fichero_correcto = true;

    fichero.close();

    return fichero_correcto;

}
