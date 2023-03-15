/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 1
//
// Fichero: I_Ley_Dhondt.cpp
//
/*	El sistema d'Hondt es un método que se utiliza para asignar escaños en 
   	sistemas de representación proporcional por listas electorales.

	Reparto:
		Tras escrutar todos los votos, se calculan cocientes sucesivos para 
		cada lista electoral. La fórmula de los cocientes es:

	    cociente = V_i / (S_i + 1)

	donde: 

    	V_i representa el número total de votos recibidos por el partido i, 
    	S_i representa el número de escaños que ha obtenido hasta el momento 
			el partido i (inicialmente 0 para cada lista).

	El número de votos recibidos por cada lista se divide sucesivamente por 
	cada uno de los divisores, desde 1 hasta el número total de escaños 
	a repartir. Cada escaño se asigna al partido cuyo cociente sea máximo. 
	La asignación de cada escaño se determina hallando el máximo de los 
	cocientes y asignando a cada uno un escaño, hasta que éstos se agoten
	
	Ejemplo:
	Supongamos unas elecciones a las que se presentan 5 partidos, 
	entre los que deben repartirse 7 escaños

		    Partido A       Partido B      Partido C    Partido D   Partido E
	Votos 	340000          280000         160000       60000 		15000

	Escaño
 	   1   *(340/1) 340     (280/1) 280    (160/1) 160  (60/1) 60 	(15/1) 15
 	   2    (340/2) 170    *(280/1) 280    (160/1) 160  (60/1) 60 	(15/1) 15
 	   3   *(340/2) 170     (280/2) 140    (160/1) 160  (60/1) 60 	(15/1) 15
 	   4    (340/3) 113.3   (280/2) 140   *(160/1) 160  (60/1) 60 	(15/1) 15
 	   5    (340/3) 113.3  *(280/2) 140    (160/2)  80  (60/1) 60 	(15/1) 15
 	   6   *(340/3) 113.3   (280/3)  93.3  (160/2)  80  (60/1) 60 	(15/1) 15
 	   7    (340/4)  85    *(280/3)  93.3  (160/2)  80  (60/1) 60 	(15/1) 15
 	
	Escaños asignados: Partido A = 3, Partido B = 3 y Partido C = 1
*/
/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include <iomanip>

using namespace std; 

/***************************************************************************/
/***************************************************************************/
// Tipos de datos. 

// La informacion de cada partido se guarda en un struct "Partido".  
struct Partido {
	char sigla;		// "Nombre" del partido
	long votos;		// Votos recibidos
	int escagnos;	// Escaños conseguidos
};

/***************************************************************************/
/***************************************************************************/
// Inicializa un array de datos "Partido" con su nombre* y lee los votos 
// obtenidos por cada partido.
// *En esta versión el "nombre" es simplemente una letra: A,B, ....
//
// Parámetros: 
// 		datos, dirección  de memoria del array de datos "Partido".
// 		num_partidos, número de partidos de la circunscripción (número de 
//			casillas del array de datos de tipo "Partido", al que se accede 
//			por el puntero "datos").
/***************************************************************************/
/***************************************************************************/
void LeerEscrutinio (Partido * datos, int num_partidos); 

/***************************************************************************/
/***************************************************************************/
// Calcula los escaños que se asignan a cada partido con la Ley D'Hont.  
// 
// Los votos de cada partido están en un array de datos "Partido" al que se 
// accede a través de "p_datos".
//
// Parámetros: 
// 		p_datos, dirección  de memoria del array de datos "Partido".
// 		num_partidos, número de partidos de la circunscripción (número de 
//			casillas del array de datos de tipo "Partido", al que se accede 
//			por el puntero "datos").
// 		num_escagnos, número de escaños a repartir.
/***************************************************************************/
/***************************************************************************/
void CalcularEscanios (Partido * datos,int num_partidos,int num_escagnos);

/***************************************************************************/
/***************************************************************************/
// Muestra el resultado (asignación de escaños).  
// Los escaños calculados están en un array de datos de tipo "Partido".
//
// Parámetros: 
// 		p_datos, dirección  de memoria del array de datos "Partido".
// 		num_partidos, número de partidos de la circunscripción (número de 
//			casillas del array de datos de tipo "Partido", al que se accede 
//			por el puntero "datos").
/***************************************************************************/
/***************************************************************************/
void MostrarResultado (Partido * datos, int num_partidos);

/***************************************************************************/
/***************************************************************************/

int main()
{
	// La información de los partidos se guarda en un array de datos "Partido"
	const int  CAPACIDAD = 20;
	Partido resultado[CAPACIDAD];

    int num_partidos; 	// Numero de partidos presentados	
	int num_escagnos;	// Numero de escaños a asignar

	/***********************************************************************/
	// Lectura de datos
    
    cout << endl; 

    do{
		cout << "Num. de escagnos = ";
		cin >> num_escagnos;
	} while (num_escagnos<=0);

    cout << endl; 

	do{
		cout << "Num. de partidos = ";
		cin >> num_partidos;
	} while ((num_partidos<=0)||(num_partidos>CAPACIDAD));

	cout << endl;


	LeerEscrutinio (resultado, num_partidos); 


	/***********************************************************************/
	// Cálculo

	CalcularEscanios (resultado, num_partidos, num_escagnos); 


    /***********************************************************************/
 	// Presentación del resultado   
  
	MostrarResultado (resultado, num_partidos); 

	
	return 0;
}

/***************************************************************************/
/***************************************************************************/
// Inicializa un array de datos "Partido" con su nombre* y lee los votos 
// obtenidos por cada partido.
// *En esta versión el "nombre" es simplemente una letra: A,B, ....
//
// Parámetros: 
// 		datos, dirección  de memoria del array de datos "Partido".
// 		num_partidos, número de partidos de la circunscripción (número de 
//			casillas del array de datos de tipo "Partido", al que se accede 
//			por el puntero "datos").
/***************************************************************************/
/***************************************************************************/

void LeerEscrutinio (Partido * datos, int num_partidos)
{
    cout << "Introducir el numero de votos de cada partido." << endl;

    for (int partido = 0; partido < num_partidos; partido++) {

		long los_votos_partido_p;
		
		cout << endl; 
 
		do {
			cout << "\tPartido " << (char)('A'+ partido) << " : ";
           	cin >>  los_votos_partido_p;

		} while (los_votos_partido_p < 0);       
            
        datos[partido].votos = los_votos_partido_p;
        datos[partido].sigla = 'A'+ partido;
 		datos[partido].escagnos = 0;    
    }
}

/***************************************************************************/
/***************************************************************************/
// Calcula los escaños que se asignan a cada partido con la Ley D'Hont.  
// 
// Los votos de cada partido están en un array de datos "Partido" al que se 
// accede a través de "p_datos".
//
// Parámetros: 
// 		p_datos, dirección  de memoria del array de datos "Partido".
// 		num_partidos, número de partidos de la circunscripción (número de 
//			casillas del array de datos de tipo "Partido", al que se accede 
//			por el puntero "datos").
// 		num_escagnos, número de escaños a repartir.
/***************************************************************************/
/***************************************************************************/

void CalcularEscanios (Partido * datos,int num_partidos,int num_escagnos)
{
	int partido_max, max;
	    
	// Cada escaño "e" se asigna de acuerdo al mayor cociente entre votos y 
	// escaños ya conseguidos más uno.
	// Esto es, el partido "p" para el que el cociente entre los votos totales 
	// conseguidos (p_datos[p].voto) y el número de escaños que le han 
	// sido asignados hasta ese momento (p_datos[p].escagnos) más uno 
	// sea mayor consigue el escaño "e"
	
    for (int e = 0; e < num_escagnos; e++) {
    	
    	max = -1; // Primer máximo
    	
    	// El máximo se calcula entre todos los partidos
    	
        for (int p = 0; p < num_partidos; p++) {
		
			// Cociente para el partido "p"
			double coc_p = datos[p].votos/(datos[p].escagnos+1);
			
			if (coc_p > max ) {
				max = coc_p;
                partido_max = p; 
			}
		}

		// Asignación el eacaño al partido "p"
		datos[partido_max].escagnos++;
    }
}

/***************************************************************************/
/***************************************************************************/
// Muestra el resultado (asignación de escaños).  
// Los escaños calculados están en un array de datos de tipo "Partido".
//
// Parámetros: 
// 		p_datos, dirección  de memoria del array de datos "Partido".
// 		num_partidos, número de partidos de la circunscripción (número de 
//			casillas del array de datos de tipo "Partido", al que se accede 
//			por el puntero "datos").
/***************************************************************************/
/***************************************************************************/

void MostrarResultado (Partido * datos, int num_partidos)
{
    cout << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "Distribucion de escagnos: " << endl;
    cout << endl;

    for (int p = 0; p < num_partidos; p++) {
        cout << "\tPartido " << datos[p].sigla;
 	    cout << " ("<< setw(9) << datos[p].votos <<" votos) -->";
		cout << setw(3) << datos[p].escagnos << " Escagnos" << endl;
	}

    cout << "----------------------------------------------------" << endl;
    cout << endl;		
} 

/***************************************************************************/
/***************************************************************************/
