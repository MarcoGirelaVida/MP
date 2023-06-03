/*
COPIADO DE DAVID PEREZ TOBARRA SOLO PARA PROBARLO,
En cuanto corrija mi código antigua haré yo mismo
*/

#include <iostream>
#include <fstream>

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

string Cabecera (const char * titulo);

bool fichero_correcto (string nombre_fichero);



// FUNCIÓN MAIN


int main(int argc, char * argv[]){


    // Compruebo los argumentos

    if (argc != 2){

        cerr << "EL número de argumentos es incorrecto." << endl;
        cerr << "Uso: " << argv[0] << " <fichero_potencial>" << endl;
        return 1;

    }

    // Antes de hacer ningún cálculo, hay que abrir los ficheros de datos,
    // y para eso, necesitamos un fichero con los nombres válido

    fichero_correcto(argv[1]);

    // Ahora vamos leyendo los ficheros
    // Hasta saber como, supongo que están en orden y sin estar repetidos


    ifstream fi;
    fi.open(argv[1]);

    if (!fi){

        cerr << "No se ha podido abrir el fichero " << argv[1] << endl;
        return (1);

    }

    string linea;
    getline(fi,linea); // Lectura adelantada para ignorar la cabecera

    // Leo hasta que pase los comentarios

    while (linea.at(0) == '#'){

        getline(fi,linea);


    }

    // Aqui deberíamos tener la primera linea de datos

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

    // Abro los ficheros necesarios


    VectorDepartamento departamentos (ficheroDepartamentos);

    VectorAdscripcion adscripciones (ficheroAdscripciones);

    VectorEncargo encargos (ficheroEncargos);

    VectorProfesor profesores (ficheroProfesores);


    // Primero me piden que calcule el potencial

    // Debo recorrer cada departamento y comprobar que profesores pertenecen
    // a el, para comprobar que tipo de encargos tiene, y sumarlo al total


    // Vector que almacenará el potencial docente
    int tam_potencial = departamentos.Totalutilizados();
    double potencial_docente[tam_potencial];
    int prof_por_dep[tam_potencial];

    for (int i=1; i<=departamentos.Totalutilizados(); i++){

        potencial_docente[i-1] = 0; // Inicialización
        prof_por_dep[i-1] = 0;

        string id_dep = departamentos[i].GetId_Dpto();

        // Recorro el vector de Adscripciones en busca de aquellos profesores
        // que pertenezcan a este departamento

        for (int j=1; j<=adscripciones.Totalutilizados(); j++){
            // Si el profesor pertenece a ese departamento,
            // compruebo su encargo

            // A su vez, cuento cuantos hay en cada uno

            if(adscripciones[j].getIdDepartamento() == id_dep){
                
                prof_por_dep[i-1]++;

                string dni_profesor = adscripciones[j].getDniProfesor();
                
                // Ahora busco al profesor con dicho dni y 
                // extraigo su encargo

                for (int k=1; k<=profesores.Totalutilizados(); k++){
                    
                    if (profesores[k].getDni() == dni_profesor){
                        // Obtengo el número de encargo
                        // y compruebo su valor

                        int num_categoria = profesores[k].getCategoria();

                        for (int l=1; l<=encargos.Totalutilizados(); l++){

                            // Extraigo el valor y lo sumo al total

                            if (encargos[l].getCategoria() == num_categoria){

                                potencial_docente[i-1] += \
                                encargos[l].getCreditos();

                                cout << encargos[l].getCreditos() << endl;
                            }
                        }   
                    }
                }
            }
        }
    }

    // con esto deberíamos tener ya el potencial docente de cada departamento
    // lo cual nos permitirá calcular el resto de cosas


    // calculo el potencial docente por profesor

    double potencial_docente_profesor[tam_potencial];

    for (int i=0; i<tam_potencial; i++){

        potencial_docente_profesor[i] = \
        potencial_docente[i] / prof_por_dep[i];      

    }

    // calculo la media global

    double media_global = 0;
    double valor_acumulado = 0;

    for (int i=0; i<tam_potencial; i++){

        valor_acumulado += potencial_docente[i];
        
    }

    media_global = valor_acumulado / profesores.Totalutilizados();


    cout << Cabecera("ENCARGOS") << endl << encargos.ToString() << endl;

    cout << Cabecera("DEPARTAMENTOS") << endl << departamentos.ToString() << endl;

    cout << Cabecera("PROFESORES") << endl << profesores.ToString() << endl;

    cout << Cabecera("ADSCRIPCIONES") << endl << adscripciones.ToString() << endl;

    // Por ultimo, solo queda mostrar los resultados

    cout << Cabecera("POTENCIAL DOCENTE:") << endl;

    for (int i=0; i<tam_potencial; i++){

        cout << departamentos[i+1].GetId_Dpto() << " --> Num.Profesores =   ";
        cout << prof_por_dep[i] << "   Potencial =   " << potencial_docente[i];
        cout << endl;

    }

    cout << Cabecera("MEDIAS POTENCIAL DOCENTE POR PROFESOR:") << endl;

    for (int i=0; i<tam_potencial; i++){

        cout << departamentos[i+1].GetId_Dpto() << " --> Potencial medio =   ";
        cout << potencial_docente_profesor[i] << endl;

    }


    cout << Cabecera("MEDIA GLOBAL:") << endl;

    cout << "Potencial medio global =    " << media_global << endl;

    cout << "Departamentos con potencial por encima de la media:" << endl;

    for (int i=0; i<tam_potencial; i++){

        if (potencial_docente_profesor[i] >= media_global){

            cout << departamentos[i+1].GetId_Dpto() << " ";
            cout << departamentos[i+1].GetNombre() << "      ";
            cout << "Potencial medio =    " << potencial_docente_profesor[i] << endl;

        }

    }

    cout << "Departamentos con potencial por debajo de la media:" << endl;    

        for (int i=0; i<tam_potencial; i++){

        if (potencial_docente_profesor[i] < media_global){

            cout << departamentos[i+1].GetId_Dpto() << " ";
            cout << departamentos[i+1].GetNombre() << "      ";
            cout << "Potencial medio =    " << potencial_docente_profesor[i] << endl;

        }

    }

    return 0;

}




// FUNCIONES COMPLEMENTARIAS



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