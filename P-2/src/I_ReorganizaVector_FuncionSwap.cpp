/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// RELACION DE PROBLEMAS 1
//
// Fichero: I_ReorganizaVector.cpp
//
// En esta versión que se proporciona al estudiante NO se modulariza la 
// clase GeneradorAleatorioEnteros. 
// TAREA: Deberá construir una nueva versión de este programa modularizando 
// 	 	 la clase GeneradorAleatorioEnteros.
//
/***************************************************************************/
/***************************************************************************/

#include <iostream> 
#include <iomanip> 

#include <random>  // Necesario para la clase GeneradorAleatorioEnteros
#include <chrono> 

using namespace std;

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

class GeneradorAleatorioEnteros
{  
private:
	
   mt19937 generador_mersenne;    // Mersenne twister
   uniform_int_distribution<int>  distribucion_uniforme;
   
   /************************************************************************/
   long long Nanosec(){
      return (chrono::high_resolution_clock::now().
              time_since_epoch().count());
   }
   /************************************************************************/ 

public:
	
   /************************************************************************/	
   GeneradorAleatorioEnteros()
      :GeneradorAleatorioEnteros(0, 1){
   }
   
   /************************************************************************/  
   GeneradorAleatorioEnteros(int min, int max) {
      const int A_DESCARTAR = 70000;
      // ACM TOMS Volume 32 Issue 1, March 2006
      
      auto semilla = Nanosec();
      generador_mersenne.seed(semilla);
      generador_mersenne.discard(A_DESCARTAR);
      distribucion_uniforme = uniform_int_distribution<int> (min, max);
   }
   
   /************************************************************************/
   int Siguiente(){
      return (distribucion_uniforme(generador_mersenne));
   }
   /************************************************************************/
};

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

/***************************************************************************/
// Muestra el contenido de un vector, con los datos alineados  
// Parámetros:
// 	p, dirección de memoria del inicio el vector.  
//	num_datos, número de casillas ocupadas del vector.
//	num_datos_linea, número de valores que se muestran en cada línea. 

void MuestraVector (int *p, int num_datos, int num_datos_linea)
{
	for (int i=0; i<num_datos; i++) {

		char separador = (((i+1)%num_datos_linea)==0) ? '\n':' ';
		cout <<setw(4)<< *(p+i) << separador;
	}
}

/***************************************************************************/

/***************************************************************************/
// Intercambia el valor de dos valores enteros. Se recibe su dirección.  
// Recibe:
// 		p1, dirección de memoria del primer valor  
// 		p2, dirección de memoria del segundo valor  

void swap (int *p1, int *p2)
{
	int tmp = *p1; 
	*p1 = *p2;
	*p2 = tmp; 
}

/***************************************************************************/

/***************************************************************************/
/***************************************************************************/

int main(void)
{
	const int TOPE = 20;			// Num. de casillas del vector 
	const int MAX_LINE = 10;		// Num. maximo de enteros por linea


	// Crear e inicializar el objeto generador de números aleatorios.

	GeneradorAleatorioEnteros generador (0, 100);
	

	//***********************************************************************
	// Iniciar el vector aleatoriamente
	//***********************************************************************	

	int v[TOPE]; // Vector de enteros

	for (int i=0; i<TOPE; i++) 
      v[i] = generador.Siguiente();
      

	//***********************************************************************
	// Mostrar el vector inicial	
	//***********************************************************************

	cout << endl; 
	cout << "Vector inicial:" << endl;
	MuestraVector (v, TOPE, MAX_LINE);


	//***********************************************************************
	// Reorganizar el vector
	//***********************************************************************

	cout << "Se va a reorganizar tomando como referencia el valor " 
         << *v << " que ocupa la posicion 0" << endl;


	// El puntero "izda" apunta al segundo elemento del vector. 
    // Va a cambiar de valor, "desplazándose" hacia a la derecha
	
	int * izda = v+1;         

	// El puntero "dcha" apunta al ultimo elemento útil del vector. 
    // Va a cambiar de valor, "desplazándose" hacia a la izquierda

	int * dcha = v+(TOPE-1);  


	// Cuando se cruzan los punteros (izda>dcha) se termina el proceso 

	while (izda <= dcha) {

		// Buscar un valor mayor que el primero 
		while ((izda <= dcha) && (*izda<=*v)) izda++;

		// Buscar un valor menor que el primero
		while ((izda<=dcha) && (*dcha>=*v)) dcha--;

		// Si no se han cruzado los punteros, intercambiar los valores
		// apuntados por "izda" y "dcha" 

		if (izda < dcha) {

			// La función swap necesita las direcciones de los datos, y éstas 
			// están en los punteros "izda" y "dcha"

			swap (izda, dcha); 

			// Los valores apuntados por "izda" y "dcha" ya están colocados. 
			// Para la siguiente iteración modificamos "izda" y "dcha"

			izda++;
			dcha--;

		} // if (izda < dcha) 

	} // while (izda <= dcha)



	// Colocar el primero (*v) en su sitio, para que los menores (o iguales) 
	// queden a su izquierda y los mayores a su derecha.
	// Su lugar lo determina el puntero "dcha" --> intercambiamos el valor 
	// del primero (*v) por el apuntado por "dcha". 
	// Basta con intercambiar los valores de la casilla 0 (su dirección es 
	// &v[0] ó simplemente v) con el referenciado por el puntero "dcha" 

	swap (v, dcha); 


	//***********************************************************************
	// Mostrar el vector reorganizado
	//***********************************************************************

	cout << endl;
	cout << "Vector final reorganizado sobre el valor " << *dcha 
		 << ", que queda en pos= " << dcha-v <<":" << endl;
	MuestraVector (v, TOPE, MAX_LINE);

	
	return 0;
}
