/***************************************************************************/
/***************************************************************************/
// METODOLOGIA DE LA PROGRAMACION
//
// AUTOR: MARCO GIRELA VIDA
// GRUPO: 1ºB
// FECHA: 08/04/2023
//
// PROYECTO FASE 2
//
//  
// 
//
// Declaraciones en: Adscripcion.h
//
// Fichero: Adscripcion.cpp
//
/***************************************************************************/
/***************************************************************************/

#include <cstring>
#include "utils.h"
#include "Adscripcion.h"

using namespace std;

/*************************************************************************/
//-------------------------CONSTRUCTORES---------------------------------//
/*************************************************************************/
// Constructor por defecto

    Adscripcion :: Adscripcion()
                        : DNI(nullptr) , Id_depto(nullptr)
    {
        setDniProfesor();
        setIdDepartamento();
    }

/*************************************************************************/
// Constructor desde un string.
// Compone un dato Encargo a patir de un dato string. 
// Parámetros: linea, el dato string del que se extraen los valores.
// 			   delimitador, el caracter que delimita los campos. 
        
    Adscripcion :: Adscripcion(string linea, char delimitador)
                        : DNI(nullptr), Id_depto(nullptr)
    {
        string tmp = "";
        int i = 0;
        
        // Leo el primer elemento del string (dni)
        while(linea[i] != delimitador)  {tmp += linea[i]; i++;}

        // Guardo tmp en el atributo dni de la clase
        string dni = tmp;
        tmp = ""; i++;

        //.....................................................................
        // Leo el segundo elemento del string (id_dtpo)

        while(linea[i] != delimitador)  { tmp += linea[i]; i++; }

        // Guardo tmp en el atributo id_dpto de la clase
        string id = tmp;

        setDniProfesor(dni);
        setIdDepartamento(id);
    }

/*********************************************************************/
// Constructor desde dos string.
// Parámetros: el_DNI, string con el id del Adscripcion. 
//             Id_depto, string con el nombre del Adscripcion. 

    Adscripcion :: Adscripcion(string el_id_depto, string el_DNI)
                        : DNI(nullptr), Id_depto(nullptr)
    {
        setDniProfesor(el_DNI);
        setIdDepartamento(el_id_depto);
    }


/*********************************************************************/
// Constructor de copia
// Parámetros: otro (referencia), objeto que sirve de modelo. 

    Adscripcion :: Adscripcion (const Adscripcion & otro)
                        : DNI(nullptr), Id_depto(nullptr)
    {
        CopiarDatos(otro);
    }

/***************************************************************************/
// Destructor

    Adscripcion :: ~Adscripcion()
    {
        LiberarMemoria();
    }


/*************************************************************************/
//----------------------------MÉTODOS------------------------------------//
/*************************************************************************/
// Métodos get

    string Adscripcion :: getDniProfesor() const
    {return DNI;}


    string Adscripcion :: getIdDepartamento() const
    {return Id_depto;}

/***************************************************************************/
// Métodos set

    void Adscripcion :: setDniProfesor(string dni)
    {stoptr(dni, DNI);}


    void Adscripcion :: setIdDepartamento(string id)
    {stoptr(id, Id_depto);}


/***************************************************************************/
/***************************************************************************/
// Método ToString

    string Adscripcion :: ToString(string cadena_inicial)
    {   
        string cadena = cadena_inicial;
        
        if (DNI || Id_depto)
        {
            if (strlen(DNI) && strlen(Id_depto))
            {
                cadena += (string) DNI;
                cadena += " ";
                cadena += (string) Id_depto + "\n";
            }
            else    {cadena += "ADSCRIPCIÓN VACIA\n";}
        }
        else    {cadena += "ADSCRIPCIÓN NO INICIALIZADA\n";}
        
        return cadena;
    }

/***********************************************************************/
// Sobrecarga del operador de asignación para copia profunda.
// Parámetros: otro (referencia), objeto que sirve de modelo. 

    Adscripcion & Adscripcion :: operator = (const Adscripcion & otro)
    {
        if (this != &otro)
        {
            // Copiar datos llama a set, que ya se encarga de reservar y
            // liberar memoria
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
// PRE: Se ha reservado memoria para los datos

    void Adscripcion :: CopiarDatos (const Adscripcion & otro)
    {
        // La propia función set ya reserva y libera memoria
        setDniProfesor(otro.getDniProfesor());
        setIdDepartamento(otro.getIdDepartamento());
    }

/***********************************************************************/
// Pide memoria para guardar una copia de los datos de "otro"
// Parámetros: otro (referencia), objeto que sirve de modelo. 

    void Adscripcion :: ReservarMemoria (const Adscripcion & otro)
    {
        LiberarMemoria();
        DNI = new char [otro.getDniProfesor().size() + 1];
        Id_depto = new char [otro.getIdDepartamento().size() + 1];
    }

/***********************************************************************/
// Libera memoria

    void Adscripcion :: LiberarMemoria (void)
    {
        if (DNI) delete [] DNI;
        DNI = nullptr;

        if (Id_depto) delete [] Id_depto;
        Id_depto = nullptr;
    }

/***********************************************************************/
// Compone y devuelve un dato string a partir de otro, tomando los 
// caracteres desde una posición dada hasta encontrar un carácter dado.
// Parámetros: cad_fuente, string desde donde se extrae la palabra.
//			   pos, posición inicial.
//			   delimitador, carácter que marca el final.
//
// PRE: 0 <= pos 
// PRE: "cad_fuente" es correcta.

    string Adscripcion :: FormaPalabra (string cad_fuente, int pos,\
                        char delimitador)
    {
        string palabra;
        
        for (int i = pos; i < cad_fuente.size(), i != delimitador; i++)
        {
            palabra[i-pos] = cad_fuente[pos];
        }

        return palabra;
    }

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
