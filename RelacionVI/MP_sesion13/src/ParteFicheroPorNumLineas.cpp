/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// AUTOR: MARCO GIRELA VIDA
// GRUPO: 1ºB
// RELACION DE PROBLEMAS 6
//
//
// flujo_inchero: MensajesOculto-2.cpp
//
/***************************************************************************/

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
    // Compruebo la validez de los argumentos
    if (argc != 3)
    {
        cout << "Uso: " << argv[0] << " <nombre_fichero> <num_lineas_max>"
             << endl;
        exit(1);
    }

    string nombreFichero = argv[1];
    int numLineasMax = stoi(argv[2]);

    // Abro el fichero de entrada (el constructor lo abre automáticamente)
    ifstream fichero_original(nombreFichero);
    if (!fichero_original)
    {
        cerr << "Error: No se pudo abrir el fichero "
             << nombreFichero << endl;
        exit(2);
    }

    // Creo el control
    string nombreFicheroCtrl = "." + nombreFichero + ".ctrl";
    ofstream ficheroCtrl(nombreFicheroCtrl);
    if (!ficheroCtrl)
    {
        cerr << "Error: No se pudo crear el fichero de control "
             << nombreFicheroCtrl << endl;
        exit(3);
    }

    //.......................................................................//
    // Divido el fichero original en ficheros de [numLineasMax] lineas
    string linea;
    int total_lineas_leidas = 0;
    int trozos_creados = 0;

    while (total_lineas_leidas <= numLineasMax)
    {
        // Creo el fichero-trozo de salida donde se almacenarán las lineas
        trozos_creados++;
        string nombre_trozo = nombreFichero + "_" + to_string(trozos_creados);
        ofstream trozo_fichero(nombre_trozo);
        if (!ficheroCtrl)
        {
            cerr << "Error: No se pudo crear el fichero de control "
                 << nombreFicheroCtrl << endl;
            exit(3);
        }

        for (int i = 0; i < numLineasMax && getline(fichero_original, linea);\
                                                 total_lineas_leidas++, i++)
            trozo_fichero << linea << endl;
        
        trozo_fichero.close();
    }

    fichero_original.close();

    //.......................................................................//
    // Escribo el fichero de control
    ficheroCtrl << "Nombre del fichero original: " << nombreFichero << endl;
    ficheroCtrl << "Número de ficheros-trozo creados: " << trozos_creados
                << endl;

    ficheroCtrl.close();

    return 0;
}
