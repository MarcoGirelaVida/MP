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
//  
// 
//
// Declaraciones en: Encargo.h
//
// Fichero: Encargo.cpp
//
/***************************************************************************/
/***************************************************************************/

#include "Encargo.h"

using namespace std;

/*************************************************************************/
//-------------------------CONSTRUCTORES---------------------------------//
/*************************************************************************/
// Constructor por defecto

    Encargo :: Encargo()
                    : categoria(0), creditos(0)
    {}

/*************************************************************************/
// Constructor desde un string.
// Compone un dato Encargo a patir de un dato string. 
// Parámetros: linea, el dato string del que se extraen los valores.
// 			   delimitador, el caracter que delimita los campos. 
        
    Encargo :: Encargo(string linea, char delimitador)
                    : categoria(0), creditos(0)
    {
            string cat, cred;
            istringstream flujo(linea);

            // Leo el primer elemento del string (categoria)
            getline(flujo, cat, delimitador);

            //.....................................................................
            // Leo el segundo elemento del string (creditos)
            getline(flujo, cred, delimitador);

            // Almaceno los datos obtenidos en los atributos
            categoria = stoi(cat);
            creditos = stod(cred);
    }

/*********************************************************************/
// Constructor desde dos int, double.
// Parámetros: la_categoría, int con la categoría del Encargo. 
//             los_creditos, double con creditos del Encargo. 

    Encargo :: Encargo (int la_categoria, double los_creditos)
                    : categoria(0), creditos(0)
    {
        setCategoria(la_categoria);
        setCreditos(los_creditos);
    }

/*********************************************************************/
// Constructor de copia
// Parámetros: otro (referencia), objeto que sirve de modelo. 

        Encargo :: Encargo (const Encargo & otro)
                    : categoria(0), creditos(0)
        {
            CopiarDatos(otro);
        }


/*************************************************************************/
//----------------------------MÉTODOS------------------------------------//
/*************************************************************************/
// Métodos get, ya que no quiero modificarlos los declaro como const

    int Encargo :: getCategoria() const
    {return categoria;}


    int Encargo :: getCreditos() const
    {return creditos;}

/***************************************************************************/
// Métodos set

    void Encargo :: setCategoria(int cat)
    {
        if (cat < 1 || cat > 5)
        {
            cerr << "Error: La categoria debe estar entre 1 y 5" << endl;
            exit(1);
        }
        categoria = cat;
    }

    void Encargo :: setCreditos(double cred)
    {
        if (cred < 0)
        {
            cerr << "Error: Los creditos deben ser positivos" << endl;
            exit(1);
        }
        creditos = cred;
    }

/***************************************************************************/
// OPERATOR >> 
// Lee un dato Encargo desde un flujo de entrada.
// Parámetros: flujo, referencia a un flujo de entrada.
//             otro, referencia a un objeto de la clase Encargo. 

    istream & operator >> (istream & flujo, Encargo & otro)
    {
        string linea;
        bool continua = true;

        while(getline(flujo, linea) && continua)
        {
            if (linea[0] != '#')
            {
                otro = Encargo(linea);
                continua = false;
            }
            else
            {
                continua = true;
            }
        }
        

        return flujo;
    }

/***************************************************************************/
// OPERATOR <<
// Escribe un dato Encargo en un flujo de salida.
// Parámetros: flujo, referencia a un flujo de salida.
//             otro, referencia a un objeto de la clase Encargo. 

    ostream & operator << (ostream & flujo, const Encargo & otro)
    {
        flujo << otro.ToString();
        return flujo;
    }

/***************************************************************************/
// Método ToString

    string Encargo :: ToString(string cadena_inicial, char delimitador) const
    {
        string cadena = cadena_inicial;

        if (categoria || creditos)
        {
            // Formateo los decimales
            string cred = FormatDouble(creditos,4,2);

            cadena += to_string(categoria) + delimitador;
            cadena += FormatString(cred, 5 ,TipoAlineacion::AlinDerecha);
            cadena += delimitador;
            cadena += "\n";
        }
        else {cadena += "ENCARGO VACIO\n";}
        
        return cadena;
    }
    
/***********************************************************************/
// Sobrecarga del operador de asignación para copia profunda.
// Parámetros: otro (referencia), objeto que sirve de modelo. 

    Encargo & Encargo :: operator = (const Encargo & otro)
    {
        if (this != &otro)
        {
            CopiarDatos(otro);
        }
        return *this;
    }
    
/***********************************************************************/
// Sobrecarga del operador == para comprobar si un departamento es igual 
// a otro (tiene la misma clave primaria)

    bool Encargo :: operator == (const Encargo & otro) const
    {
        bool son_iguales = false;

        if (this != &otro)
        {
            if (getCategoria() == otro.getCategoria())
            {
                son_iguales = true;
            }
        }
        else
        {
            son_iguales = true;
        }
        

        return son_iguales;
    }

/*************************************************************************/
//------------------------MÉTODOS PRIVADOS-------------------------------//
/*************************************************************************/
// Copiar datos desde otro objeto de la clase
// Parámetros: otro (referencia), objeto que sirve de modelo. 
//

    void Encargo :: CopiarDatos (const Encargo & otro)
    {

        setCategoria(otro.getCategoria());
        setCreditos(otro.getCreditos());
    }
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
