/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
//
// (C) FRANCISCO JOSÉ CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
// 
// Fichero: main_MP_Proyecto_Fase5.cpp
//
// Función main del proyecto. 
//
// Proyecto. FASE 05. 
//
/***************************************************************************/
/***************************************************************************/

#define DEBUG_DEPARTAMENTOS
#define DEBUG_PROFESORES
#define DEBUG_ENCARGOS
#define DEBUG_ADSCRIPCIONES


#define DEBUG_DEPARTAMENTOS_DETALLE_FASE5
/*#define DEBUG_PROFESORES_DETALLE
#define DEBUG_ENCARGOS_DETALLE
#define DEBUG_ADSCRIPCIONES_DETALLE
*/

/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>

#include "Fecha.h"
#include "Departamento.h"
#include "Profesor.h"
#include "Encargo.h"
#include "Adscripcion.h"

#include "VectorDepartamento.h"
#include "VectorProfesor.h"
#include "VectorEncargo.h"
#include "VectorAdscripcion.h"

#include "utils.h"

using namespace std;


/***************************************************************************/
/***************************************************************************/

string Cabecera (const char * titulo);

/***************************************************************************/
/***************************************************************************/

int main()
{
    cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales

	int cont_departamentos = 0;
	int cont_profesores = 0;
	int cont_encargos = 0;
	int cont_adscripciones = 0;


	// Terminador para los datos leidos/escritos 
	const string TERMINADOR = "FIN";

	// Cada linea del fichero se lee en un dato string. 
	string linea;


	//......................................................................
	// DEPARTAMENTOS

	// Crear vector dinámico de objetos "Departamento" (inicialmente vacío). 
	VectorDepartamento departamentos; 


	cout << Cabecera ("DEPARTAMENTOS:");

	getline(cin, linea); // Lectura adelantada

	while (linea != TERMINADOR) {
		
		cont_departamentos++; // Un departamento más (no se leyó TERMINADOR)	
			

		Departamento un_departamento (linea);
		departamentos += un_departamento;
		// Leer la siguiente linea 
		getline(cin, linea); 
		
	} // while (linea != TERMINADOR)
	

	#ifdef DEBUG_DEPARTAMENTOS
	cout << "Total Departamentos = "<< setw(3) << cont_departamentos << endl; 
	cout << endl; 
	#endif

	cout << endl; 
	cout << "Capacidad = " << setw(3) << departamentos.Capacidad() << ". ";
	cout << "Totalutilizados = " << setw(3) <<  departamentos.Totalutilizados() << endl;
	cout << departamentos.Serializar() << endl;
	cout << endl; 


	#ifdef DEBUG_DEPARTAMENTOS_DETALLE_FASE5

	cout << endl; 
	cout << "******************************************************" << endl; 
	cout << "******************************************************" << endl; 
	cout << endl; 

	// ..................................................................
	// OPERATOR +

	cout << endl; 
	cout << "departamentos antes de adiciones:" << endl; 
	cout << "Capacidad = " << setw(3) << departamentos.Capacidad() << ". ";
	cout << "Totalutilizados = " << setw(3) <<  departamentos.Totalutilizados() << endl;
	cout << departamentos.Serializar() << endl;
	cout << endl; 
	

	Departamento nuevo_depto; 

	nuevo_depto.SetId_Dpto ("NUEVO1");
	nuevo_depto.SetNombre  ("NUEVO DEPARTAMENTO 1");


	cout << "Aniado " <<  nuevo_depto.ToString() << endl; 

	departamentos = departamentos + nuevo_depto;

	nuevo_depto.SetId_Dpto ("NUEVO2");
	nuevo_depto.SetNombre  ("NUEVO DEPARTAMENTO 2");


	cout << "Aniado " <<  nuevo_depto.ToString() << endl; 
	
	departamentos = nuevo_depto + departamentos;

	cout << endl; 
	cout << "departamentos despues de adiciones:" << endl; 
	cout << "Capacidad = " << setw(3) << departamentos.Capacidad() << ". ";
	cout << "Totalutilizados = " << setw(3) <<  departamentos.Totalutilizados() << endl;
	cout << departamentos.Serializar() << endl;
	cout << endl; 
	

	cout << "Intento aniadir " <<  nuevo_depto.ToString() << endl; 

	//departamentos = departamentos + nuevo_depto;

	cout << endl; 
	cout << "departamentos despues intentar adicion de uno existente:" << endl; 
	cout << "Capacidad = " << setw(3) << departamentos.Capacidad() << ". ";
	cout << "Totalutilizados = " << setw(3) <<  departamentos.Totalutilizados() << endl;
	cout << departamentos.Serializar() << endl;
	cout << endl; 



	VectorDepartamento otro_vector; 
	cout << "Creado otro_vector" << endl; 

	cout << endl; 
	cout << "Capacidad = " << setw(3) << otro_vector.Capacidad() << ". ";
	cout << "Totalutilizados = " << setw(3) <<  otro_vector.Totalutilizados() << endl;
	cout << otro_vector.Serializar() << endl;
	cout << endl; 

	nuevo_depto.SetId_Dpto ("OTRO1");
	nuevo_depto.SetNombre  ("OTRO DEP 1");
	cout << "Aniado " <<  nuevo_depto.ToString() << endl; 
	otro_vector = otro_vector + nuevo_depto;

	nuevo_depto.SetId_Dpto ("OTRO2");
	nuevo_depto.SetNombre  ("OTRO DEP 2");
	cout << "Aniado " <<  nuevo_depto.ToString() << endl; 
	otro_vector = otro_vector + nuevo_depto;

	nuevo_depto.SetId_Dpto ("OTRO3");
	nuevo_depto.SetNombre  ("OTRO DEP 3");
	cout << "Aniado " <<  nuevo_depto.ToString() << endl; 
	otro_vector = otro_vector + nuevo_depto;

	nuevo_depto.SetId_Dpto ("OTRO4");
	nuevo_depto.SetNombre  ("OTRO DEP 4");
	cout << "Aniado " <<  nuevo_depto.ToString() << endl; 
	otro_vector = otro_vector + nuevo_depto;

	nuevo_depto.SetId_Dpto ("OTRO5");
	nuevo_depto.SetNombre  ("OTRO DEP 5");
	cout << "Aniado " <<  nuevo_depto.ToString() << endl; 
	otro_vector = otro_vector + nuevo_depto;

	nuevo_depto.SetId_Dpto ("OTRO6");
	nuevo_depto.SetNombre  ("OTRO DEP 6");
	cout << "Aniado " <<  nuevo_depto.ToString() << endl; 
	otro_vector = otro_vector + nuevo_depto;

	cout << endl; 
	cout << "Capacidad = " << setw(3) << otro_vector.Capacidad() << ". ";
	cout << "Totalutilizados = " << setw(3) <<  otro_vector.Totalutilizados() << endl;
	cout << otro_vector.Serializar() << endl;
	cout << endl; 


	VectorDepartamento suma; 
	
	suma = departamentos + otro_vector;

	cout << endl; 
	cout << "Capacidad = " << setw(3) << suma.Capacidad() << ". ";
	cout << "Totalutilizados = " << setw(3) <<  suma.Totalutilizados() << endl;
	cout << suma.Serializar() << endl;
	cout << endl; 


	// ..................................................................
	// OPERATOR -

	// [VectorDepartamento] - [string] 

	cout << "Borrando " <<  "OTRO1" << endl; 

	VectorDepartamento suma_reducido = suma - "OTRO1";  

	cout << endl; 
	cout << "Capacidad = " << setw(3) << suma_reducido.Capacidad() << ". ";
	cout << "Totalutilizados = " << setw(3) <<  suma_reducido.Totalutilizados() << endl;
	cout << suma_reducido.Serializar() << endl;
	cout << endl; 


	cout << "Borrando " <<  "OTRO5" << endl; 

	suma_reducido = suma_reducido - "OTRO5"; 

	cout << endl; 
	cout << "Capacidad = " << setw(3) << suma_reducido.Capacidad() << ". ";
	cout << "Totalutilizados = " << setw(3) <<  suma_reducido.Totalutilizados() << endl;
	cout << suma_reducido.Serializar() << endl;
	cout << endl; 


	// [VectorDepartamento] - [Departamento] 


	Departamento dep_borrar ("NUEVO1", ""); 

	cout << "Borrando " <<  dep_borrar.ToString() << endl; 
	
	suma_reducido = suma_reducido - dep_borrar; 

	cout << endl; 
	cout << "Capacidad = " << setw(3) << suma_reducido.Capacidad() << ". ";
	cout << "Totalutilizados = " << setw(3) <<  suma_reducido.Totalutilizados() << endl;
	cout << suma_reducido.Serializar() << endl;
	cout << endl; 


	// [VectorDepartamento] - [VectorDepartamento] 

	cout << endl; 
	cout << "Borrando de un vector:" << endl;
	cout << otro_vector.Serializar() << endl; 
	cout << endl; 

	VectorDepartamento resta_VD = suma_reducido - otro_vector; 

	cout << endl; 
	cout << "Resultado: " << endl;	
	cout << "Capacidad = " << setw(3) << resta_VD.Capacidad() << ". ";
	cout << "Totalutilizados = " << setw(3) <<  resta_VD.Totalutilizados() << endl;
	cout << resta_VD.Serializar() << endl;
	cout << endl; 


	cout << endl; 
	cout << "Borrando de un vector:" << endl;
	cout << departamentos.Serializar() << endl; 
	cout << endl; 

	resta_VD = resta_VD - departamentos; 

	cout << endl; 
	cout << "Resultado: " << endl;	
	cout << "Capacidad = " << setw(3) << resta_VD.Capacidad() << ". ";
	cout << "Totalutilizados = " << setw(3) <<  resta_VD.Totalutilizados() << endl;
	cout << resta_VD.Serializar() << endl;
	cout << endl; 


	// ..................................................................
	// OPERATOR *

	cout << endl; 
	cout << "departamentos: " << endl;	
	cout << "Capacidad = " << setw(3) << departamentos.Capacidad() << ". ";
	cout << "Totalutilizados = " << setw(3) <<  departamentos.Totalutilizados() << endl;
	cout << departamentos.Serializar() << endl;
	cout << endl; 

	cout << endl; 
	cout << "otro_vector: " << endl;	
	cout << "Capacidad = " << setw(3) << otro_vector.Capacidad() << ". ";
	cout << "Totalutilizados = " << setw(3) <<  otro_vector.Totalutilizados() << endl;
	cout << otro_vector.Serializar() << endl;
	cout << endl; 

	cout << endl; 
	cout << "suma: " << endl;	
	cout << "Capacidad = " << setw(3) << suma.Capacidad() << ". ";
	cout << "Totalutilizados = " << setw(3) <<  suma.Totalutilizados() << endl;
	cout << suma.Serializar() << endl;
	cout << endl; 

	VectorDepartamento inter1 = departamentos * otro_vector;

	cout << "departamentos * otro_vector: " << endl;	

	cout << endl; 
	cout << "Capacidad = " << setw(3) << inter1.Capacidad() << ". ";
	cout << "Totalutilizados = " << setw(3) <<  inter1.Totalutilizados() << endl;
	cout << inter1.Serializar() << endl;
	cout << endl; 


	VectorDepartamento inter2 = suma * otro_vector;

	cout << "suma * otro_vector: " << endl;	

	cout << endl; 
	cout << "Capacidad = " << setw(3) << inter2.Capacidad() << ". ";
	cout << "Totalutilizados = " << setw(3) <<  inter2.Totalutilizados() << endl;
	cout << inter2.Serializar() << endl;
	cout << endl; 

	VectorDepartamento inter3 = otro_vector * suma;

	cout << "otro_vector * suma: " << endl;	

	cout << endl; 
	cout << "Capacidad = " << setw(3) << inter3.Capacidad() << ". ";
	cout << "Totalutilizados = " << setw(3) <<  inter3.Totalutilizados() << endl;
	cout << inter3.Serializar() << endl;
	cout << endl; 

	VectorDepartamento prueba2(Departamento("(CCIA)", ""));
	cout << "Prueba2: " << prueba2.Serializar();
	VectorDepartamento inter4 = (departamentos * prueba2);

	cout << "departamentos * VectorDepartamento(Departamento(\"CCIA\",\"\")";	
	cout << endl; 

	cout << endl; 
	cout << "Capacidad = " << setw(3) << inter4.Capacidad() << ". ";
	cout << "Totalutilizados = " << setw(3) <<  inter4.Totalutilizados() << endl;
	cout << inter4.Serializar() << endl;
	cout << endl; 


	// ..................................................................
	// OPERATOR &&


	cout << endl; 
	cout << "departamentos: " << endl;	
	cout << "Capacidad = " << setw(3) << departamentos.Capacidad() << ". ";
	cout << "Totalutilizados = " << setw(3) <<  departamentos.Totalutilizados() << endl;
	cout << departamentos.Serializar() << endl;
	cout << endl; 

	cout << endl; 
	cout << "otro_vector: " << endl;	
	cout << "Capacidad = " << setw(3) << otro_vector.Capacidad() << ". ";
	cout << "Totalutilizados = " << setw(3) <<  otro_vector.Totalutilizados() << endl;
	cout << otro_vector.Serializar() << endl;
	cout << endl; 

	cout << endl; 
	cout << "suma: " << endl;	
	cout << "Capacidad = " << setw(3) << suma.Capacidad() << ". ";
	cout << "Totalutilizados = " << setw(3) <<  suma.Totalutilizados() << endl;
	cout << suma.Serializar() << endl;
	cout << endl; 

	cout << "departamentos && suma: "  
	     << boolalpha << (departamentos && suma) << endl;
	cout << "suma && departamentos: "  
	     << boolalpha << (suma && departamentos) << endl;
	cout << "departamentos && otro_vector: "  
	     << boolalpha << (departamentos && otro_vector) << endl;
	cout << "otro_vector && departamentos: "  
	     << boolalpha << (otro_vector && departamentos) << endl;
	cout << "otro_vector && suma: "  
	     << boolalpha << (otro_vector && suma) << endl;
	cout << "suma && otro_vector: "  
	     << boolalpha << (suma && otro_vector) << endl;
	cout << endl; 

	Departamento buscado_esta ("(CCIA)", "");
	Departamento buscado_no_esta ("(PEPE)", "");

	cout << "buscado_esta: " << buscado_esta.ToString() << endl;	
	cout << "buscado_no_esta: " << buscado_no_esta.ToString() << endl;	
	cout << endl; 

	cout << "departamentos && buscado_esta: "  
	     << boolalpha <<(bool) (departamentos && buscado_esta) << endl;
	cout << "departamentos && buscado_no_esta: " 
	     << boolalpha <<(bool) (departamentos && buscado_no_esta) << endl;
	cout << endl; 

	cout << "buscado_esta && departamentos: "  
	     << boolalpha <<(bool) (buscado_esta && departamentos) << endl;
	cout << "buscado_no_esta && departamentos: " 
	     << boolalpha <<(bool) (buscado_no_esta && departamentos) << endl;
	cout << endl; 


	// ..................................................................
	// OPERATOR += y -= 

	cout << endl; 
	cout << "otro_vector: " << endl;	
	cout << "Capacidad = " << setw(3) << otro_vector.Capacidad() << ". ";
	cout << "Totalutilizados = " << setw(3) <<  otro_vector.Totalutilizados() << endl;
	cout << otro_vector.Serializar() << endl;
	cout << endl; 


	cout << endl; 
	cout << "departamentos: " << endl;	
	cout << "Capacidad = " << setw(3) << departamentos.Capacidad() << ". ";
	cout << "Totalutilizados = " << setw(3) <<  departamentos.Totalutilizados() << endl;
	cout << departamentos.Serializar() << endl;
	cout << endl; 


	cout << "otro_vector += departamentos" << endl;	

	otro_vector += departamentos; 

	cout << endl; 
	cout << "otro_vector: " << endl;	
	cout << "Capacidad = " << setw(3) << otro_vector.Capacidad() << ". ";
	cout << "Totalutilizados = " << setw(3) <<  otro_vector.Totalutilizados() << endl;
	cout << otro_vector.Serializar() << endl;
	cout << endl; 


	Departamento otro_nuevo_depto ("OTRO7", "OTRO DEP 7"); 

	cout << "otro_nuevo_depto: " << otro_nuevo_depto.ToString() << endl;	

	cout << "otro_vector += otro_nuevo_depto" << endl;	

	otro_vector += otro_nuevo_depto; 

	cout << endl; 
	cout << "otro_vector: " << endl;	
	cout << "Capacidad = " << setw(3) << otro_vector.Capacidad() << ". ";
	cout << "Totalutilizados = " << setw(3) <<  otro_vector.Totalutilizados() << endl;
	cout << otro_vector.Serializar() << endl;
	cout << endl; 



	cout << "otro_vector -= \"NUEVO1\"" << endl;	
	cout << "otro_vector -= \"NUEVO2\"" << endl;	

	otro_vector -= "NUEVO1"; 
	otro_vector -= "NUEVO2";
	 
	cout << endl; 
	cout << "otro_vector: " << endl;	
	cout << "Capacidad = " << setw(3) << otro_vector.Capacidad() << ". ";
	cout << "Totalutilizados = " << setw(3) <<  otro_vector.Totalutilizados() << endl;
	cout << otro_vector.Serializar() << endl;
	cout << endl; 

	
	Departamento ultimo = otro_vector[otro_vector.Totalutilizados()];

	cout << "ultimo: " << ultimo.ToString() << endl;	

	cout << "otro_vector -= ultimo" << endl;	

	otro_vector -= ultimo; 
	 
	cout << endl; 
	cout << "otro_vector: " << endl;	
	cout << "Capacidad = " << setw(3) << otro_vector.Capacidad() << ". ";
	cout << "Totalutilizados = " << setw(3) <<  otro_vector.Totalutilizados() << endl;
	cout << otro_vector.Serializar() << endl;
	cout << endl; 


	cout << "otro_vector -= departamentos" << endl;	

	otro_vector -= departamentos; 
	 
	cout << endl; 
	cout << "otro_vector: " << endl;	
	cout << "Capacidad = " << setw(3) << otro_vector.Capacidad() << ". ";
	cout << "Totalutilizados = " << setw(3) <<  otro_vector.Totalutilizados() << endl;
	cout << otro_vector.Serializar() << endl;
	cout << endl; 

	cout << endl; 
	cout << "otro_vector: " << endl;	
	cout << "Capacidad = " << setw(3) << otro_vector.Capacidad() << ". ";
	cout << "Totalutilizados = " << setw(3) <<  otro_vector.Totalutilizados() << endl;
	cout << otro_vector.Serializar() << endl;
	cout << endl; 

	cout << endl; 
	cout << "******************************************************" << endl; 
	cout << "******************************************************" << endl; 
	cout << endl; 

	#endif


	//......................................................................
	// PROFESORES

	// Crear vector dinámico de objetos "Profesor" (inicialmente vacío). 
	VectorProfesor profesores; 

/*
	cout << Cabecera ("PROFESORES:");

	getline(cin, linea); // Lectura adelantada

	while (linea != TERMINADOR) {
		
		cont_profesores++; // Un profesor más (no se leyó TERMINADOR)	
			

		Profesor un_profesor (linea);

		profesores += un_profesor;

		// Leer la siguiente linea 
		getline(cin, linea); 
		
	} // while (linea != TERMINADOR)


	#ifdef DEBUG_PROFESORES
	cout << "Total Profesores = "<< setw(3) << cont_profesores << endl; 
	cout << endl; 
	#endif

	cout << endl; 
	cout << "Capacidad = " << setw(3) << profesores.Capacidad() << ". ";
	cout << "Totalutilizados = " << setw(3) <<  profesores.Totalutilizados() << endl;
	cout << profesores.Serializar() << endl;
	cout << endl; 
*/


	#ifdef DEBUG_PROFESORES_DETALLE_FASE5

	#endif



	// CATEGORIAS
/* 
	// Crear vector dinámico de objetos "Encargo" (inicialmente vacío). 
	VectorEncargo encargos; 


	cout << Cabecera ("ENCARGOS:");

	getline(cin, linea); // Lectura adelantada

	while (linea != TERMINADOR) {
		
		cont_encargos++; // Un encargo más (no se leyó TERMINADOR)	
			

		Encargo un_encargo (linea);

		encargos += un_encargo;

		// Leer la siguiente linea 
		getline(cin, linea); 
		
	} // while (linea != TERMINADOR)
	

	#ifdef DEBUG_ENCARGOS
	cout << "Total Encargos = "<< setw(3) << cont_encargos << endl; 
	cout << endl; 
	#endif
	
	cout << endl; 
	cout << "Capacidad = " << setw(3) << encargos.Capacidad() << ". ";
	cout << "Totalutilizados = " << setw(3) <<  encargos.Totalutilizados() << endl;
	cout << encargos.Serializar() << endl;
	cout << endl; 
*/

	#ifdef DEBUG_ENCARGOS_DETALLE_FASE5

	#endif




/*

	// ADSCRIPCIONES
	 
	// Crear vector dinámico de objetos "Adscripcion" (inicialmente vacío). 
	VectorAdscripcion adscripciones; 

	cout << Cabecera ("ADSCRIPCION DE PROFESORES A DEPARTAMENTOS:");

	getline(cin, linea); // Lectura adelantada

	while (linea != TERMINADOR) {
		
		cont_adscripciones++; // Una adscripción más (no se leyó TERMINADOR)	


		Adscripcion una_adscripcion (linea);

		adscripciones += una_adscripcion;

		// Leer la siguiente linea 
		getline(cin, linea); 
		
	} // while (linea != TERMINADOR) 


	#ifdef DEBUG_ADSCRIPCIONES
	cout << "Total Adscripciones = "<< setw(3) << cont_adscripciones << endl; 
	cout << endl; 
	#endif

	cout << endl; 
	cout << "Capacidad = " << setw(3) << adscripciones.Capacidad() << ". ";
	cout << "Totalutilizados = " << setw(3) <<  adscripciones.Totalutilizados() << endl;
	cout << adscripciones.Serializar() << endl;
	cout << endl; 

*/
	#ifdef DEBUG_ADSCRIPCIONES_DETALLE_FASE5

	#endif


	return 0;
}

/***************************************************************************/
/***************************************************************************/

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

/***************************************************************************/
/***************************************************************************/
