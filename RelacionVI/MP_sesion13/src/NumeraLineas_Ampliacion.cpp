/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// AUTOR: MARCO GIRELA VIDA
// GRUPO: 1ºB
// RELACION DE PROBLEMAS 6
//
// Programa que crea un flujo_inchero a partir de otro, copiando su contenido
// y añadiendo al principio de cada línea, su número.
// Recibe los nombres de dos flujo_incheros de texto de la línea de órdenes.
//
// NumeraLineas <flujo_inch_in> <flujo_inch_out>
//
//		<flujo_inch_in>	Es el nombre de un flujo_inchero de texto (que ya existe).
//		<flujo_inch_out>	Es el nombre del flujo_inchero de texto que se va a crear.
//
//permita que los flujos de entrada
//y salida puedan ser, además de flujo asociados a flujo_incheros, los flujos cin y cout
//respectivamente. El programa se puede ejecutar:
//      % NumeraLineas_Ampliacion
//  Copia desde cin en cout
//      % NumeraLineas_Ampliacion flujo_inchero
//  Copia desde flujo_inchero en cout
//      % NumeraLineas_Ampliacion flujo_inchero1 flujo_inchero2
//  Copia desde flujo_inchero1 en flujo_inchero2
//
// flujo_inchero: NumeraLineas_Ampliacion.cpp
//
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

/***************************************************************************/
// Función que copia el contenido de un flujo_inchero de texto en otro,
// añadiendo al principio de cada línea, su número.
// Recibe dos flujos, uno de entrada y otro de salida.
void enumera (ostream & salida, istream & entrada);


int main(int argc, char * argv[]){


    // Compruebo los argumentos

    switch (argc)
    {
    case 1:
        // Asociación de flujos a cin y cout
        enumera(cout, cin);
        break;
        
    case 2:
        {
            // Asociación de flujos de salida a fichero
            ofstream fo; // Flujo de salida

            fo.open(argv[1]);

            if (!fo)
            {
                cerr << "Error: no pudo abrirse " << argv[1] << endl;
                exit (1);
            }

            enumera(fo, cin);

            break;
        }

    case 3:
        {
            ifstream fi; // Flujo de entrada
            fi.open(argv[1]);

            if (!fi)
            {   
                cerr << "No se ha podido abrir el fichero " << argv[1] << endl;
                exit (2);
            }

            ofstream fo; // Flujo de salida
            fo.open(argv[2]);

            if (!fo)
            {
                cerr << "No se ha podido abrir el fichero " << argv[2] << endl;
                exit (2);
            }

            enumera(fo,fi);

            fo.close();
            fi.close();

            break;
        }

    default:
        {
        cerr << "Error: Numero de argumentos incorrecto." << endl;
        cerr << "Formato: " << endl;
        cerr << "% NumeraLineas_Ampliacion" << endl;
        cerr << "% NumeraLineas_Ampliacion fichero" << endl;
        cerr << "% NumeraLineas_Ampliacion fichero1 fichero2" << endl;
        exit (1);
        }
        break;
    }

    return (0);
}

/***************************************************************************/
// Función que copia el contenido de un flujo_inchero de texto en otro,
// añadiendo al principio de cada línea, su número.
// Recibe dos flujos, uno de entrada y otro de salida.
void enumera (ostream & salida, istream & entrada)
{
    // Datos a leer/utilizar
    string cad;
    int cont=1;

    // Lectura
    while (getline(entrada, cad))
    {
        salida << setw(4) << ++cont << " " << cad << endl;
    }
}

/* INTENTO FALLIDO, PERO ME GUSTABA LA IDEA, ASI QUE NO QUIERO BORRARLO
int main (int argc, char **argv)
{
    istream* flujo_in;
    ostream* flujo_out;

    switch (argc)
    {
    case 1:
        // Asociación de flujos a cin y cout
        flujo_in = &cin;
        flujo_out = &cout;
        break;
        
    case 2:
        {
            // Asociación de flujos a flujo_inchero
            ofstream fo (argv[2]);
            if (!fo) {
                cerr << "Error: No pudo crearse " << argv[2] << endl;
                exit (3);
            }
            flujo_out = &fo;
            flujo_in = &cin;
            break;
        }
    case 3:
        {
            // Asociación de flujos a flujo_incheros
            ifstream fi (argv[1]);
            if (!fi) {
                cerr << "Error: No pudo abrirse " << argv[1] << endl;
                exit (2);
            }
            ofstream fo (argv[2]);
            if (!fo) {
                cerr << "Error: No pudo crearse " << argv[2] << endl;
                exit (3);
            }
            flujo_in = &fi;
            flujo_out = &fo;
            break;
        }

    default:
        {
        cerr << "Error: Numero de argumentos incorrecto." << endl;
        cerr << "Formato: " << endl;
        cerr << "% NumeraLineas_Ampliacion" << endl;
        cerr << "% NumeraLineas_Ampliacion fichero" << endl;
        cerr << "% NumeraLineas_Ampliacion fichero1 fichero2" << endl;
        exit (1);
        }
        break;
    }



	// INICIO de la zona especí*flujo_inca. Solución usando string 

	string cad;		// para leer/escribir cada linea
	int cont = 0;	// numero de linea


	getline (*flujo_in,cad);	// lectura adelantada (string)

	while (!(*flujo_in).eof()) {

		// Escribe en "*flujo_out" num.linea + cadena (string)
		*flujo_out << setw(4) << ++cont << "  " << cad << endl;

		getline (*flujo_in,cad);	// nueva lectura (string)
	}

	// *flujo_inN de la zona especí*flujo_inca. Solución usando string 

	// *flujo_innalizacion: cierre de flujos 

    if (argc == 2)
    {
        (ofstream)(*flujo_out);
        flujo_out.close();
    }
    else if (argc == 3)
    {
        (ofstream)(*flujo_out);
        (ifstream)(*flujo_in)
        flujo_out.close();
        flujo_in.close();
    }

	return 0;
}
*/