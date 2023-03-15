/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 1
//
// Fichero: Ley_Dhondt_sin_modularizar.cpp
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

int main()
{
	// La informacion de cada partido se guarda en un struct
	struct Partido {
    	char sigla;		// "Nombre" del partido
    	long votos;		// Votos recibidos
    	int escagnos;	// Escaños conseguidos
    };
	
	// La información de los partidos se guarda en un array de datos "Partido"
	const int  CAPACIDAD = 20;
	Partido resultado[CAPACIDAD];


    int num_partidos; 	// Numero de partidos presentados	
	int num_escagnos;	// Numero de escaños a asignar
	
	//***********************************************************************
	// Lectura de datos
    
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


    cout << "Introducir el numero de votos de cada partido." << endl;

    for (int p = 0; p < num_partidos; p++) {

		long los_votos_partido_p;
		
		cout << endl; 

		do{
			cout << "\tPartido " << (char)('A'+ p) << " : ";
           	cin >>  los_votos_partido_p;
		} while (los_votos_partido_p < 0);       
            
        resultado[p].votos = los_votos_partido_p;
        resultado[p].sigla = 'A'+ p;
 		resultado[p].escagnos = 0;    
    }


	//***********************************************************************
	// Cálculo
	
	int partido_max, max;
	    
	// Cada escaño "e" se asigna de acuerdo al mayor cociente entre votos y 
	// escaños ya conseguidos más uno.
	// Esto es, el partido "p" para el que el cociente entre los votos totales 
	// conseguidos (distribucion[p].voto) y el número de escaños que le han 
	// sido asignados hasta ese momento (distribucion[p].escagnos) más uno 
	// sea mayor consigue el escaño "e"
	
    for (int e = 0; e < num_escagnos; e++) {
    	
    	max = -1; // Primer máximo
    	
    	// El máximo se calcula entre todos los partidos
    	
        for (int p = 0; p < num_partidos; p++) {
		
			// Cociente para el partido "p"
			double coc_p = resultado[p].votos/(resultado[p].escagnos+1);
			
			if (coc_p > max ) {
				max = coc_p;
                partido_max = p; 
			}
		}

		// Asignación el eacaño al partido "p"
		resultado[partido_max].escagnos++;
    }
    
    
	//***********************************************************************
 	// Presentación del resultado   

    cout << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "Distribucion de escagnos: " << endl;
    cout << endl;
    
    for (int p = 0; p < num_partidos; p++) {
        cout << "\tPartido " << resultado[p].sigla;
 	    cout << " ("<< setw(8) << resultado[p].votos <<" votos) -->";
		cout << setw(3) << resultado[p].escagnos << " Escagnos" << endl;
	}
	
    cout << "----------------------------------------------------" << endl;
    cout << endl;	

	return 0;
}

/***************************************************************************/
/***************************************************************************/