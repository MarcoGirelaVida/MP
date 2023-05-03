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

#include <cstring>
#include <iostream>

#include "Encargo.h"
#include "utils.h"

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
            string tmp = "";
            int i = 0;
            
            // Leo el primer elemento del string (categoria)
            while(linea[i] != delimitador)  { tmp += linea[i]; i++;}
            i++;

            // Almaceno tmp en el atributo categoria de la clase
            categoria = stoi(tmp);
            tmp = "";
        
            // Leo el segundo elemento del string (creditos)
            while(linea[i] != delimitador)  { tmp += linea[i]; i++;}
        
            // Almaceno tmp en el atributo creditos de la clase
            creditos = stod(tmp);
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
// Método ToString

    string Encargo :: ToString()
    {
        string cadena = "";

        if (categoria || creditos)
        {
            // Formateo los decimales
            string cred = FormatDouble(creditos,4,2);

            cadena += " " + to_string(categoria) + " ";
            cadena += FormatString(cred, 5 ,TipoAlineacion::AlinDerecha);
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
