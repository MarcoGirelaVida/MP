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
// Declaraciones en: Profesor.h
//
// Fichero: Profesor.cpp
//
/***************************************************************************/
/***************************************************************************/

#include <cstring>
#include <iostream>

#include "Profesor.h"
#include "Fecha.h"
#include "utils.h"

using namespace std;

/*************************************************************************/
//-------------------------CONSTRUCTORES---------------------------------//
/*************************************************************************/
// Constructor por defecto

    Profesor :: Profesor()
                    : DNI(nullptr), Nombre(nullptr), Apellidos(nullptr),\
                      Categoria(0)
    {
        setDni();
        setNombre();
        setApellidos();
        FechaNacimiento = Fecha();
    }

/************************************************************************/
// Constructor de copia
// Parámetros: otro (referencia), objeto que sirve de modelo. 

    Profesor :: Profesor(const Profesor & otro)
                    : DNI(nullptr), Nombre(nullptr), Apellidos(nullptr),\
                      Categoria(0)
    {
        // Copiar datos ya reserva/libera memoria
        CopiarDatos(otro);
    }

/************************************************************************/
// Constructor desde 5 string.
// Parámetros: el_DNI, string con el id del DNI. 
//             el_nombre, string con el nombre. 
//             el_apellidos, string con los apellidos.
//             la_fecha, string con la fecha de nacimiento.
//             la_categoria, int con la categoria.

    Profesor :: Profesor(string el_DNI, string el_nombre, string el_apellidos,\
                                string la_fecha, int la_categoria)
                    : DNI(nullptr), Nombre(nullptr), Apellidos(nullptr),\
                      Categoria(0)
    {
        setDni(el_DNI);
        setNombre(el_nombre);
        setApellidos(el_apellidos);
        setFechaNacimiento(la_fecha);
        setCategoria(la_categoria);
    }

/*************************************************************************/
// Constructor desde un string.
// Compone un dato Encargo a patir de un dato string. 
// Parámetros: linea, el dato string del que se extraen los valores.
// 			   delimitador, el caracter que delimita los campos. 
        
    Profesor :: Profesor(string linea, char delimitador)
                    : DNI(nullptr), Nombre(nullptr), Apellidos(nullptr),\
                      Categoria(0)
    {

        string dni, nombre, apellidos, fechanacimiento, categoria;
        string tmp = "";
        int i = 0;

        // Leo el DNI
        while(linea[i] != delimitador)  {tmp += linea[i]; i++;}

        // Almaceno el DNI en un string temporal
        dni = tmp;
        tmp = ""; i++;

        //.....................................................................
        // Leo el nombre
        while(linea[i] != delimitador)  {tmp += linea[i]; i++;}

        // Almaceno el nombre en un string temporal
        nombre = tmp;
        tmp = ""; i++;

        //.....................................................................
        // Leo los apellidos
        while(linea[i] != delimitador)  {tmp += linea[i]; i++;}

        // Almaceno los apellidos en un string temporal
        apellidos = tmp;
        tmp = ""; i++;

        //.....................................................................
        // Leo la fecha de nacimiento
        while(linea[i] != delimitador)  {tmp += linea[i]; i++;}

        // Almaceno la fecha en un string temporal
        fechanacimiento = tmp;
        tmp = ""; i++;

        //.....................................................................
        // Leo la categoria
        while(linea[i] != delimitador)  {tmp += linea[i]; i++;}

        // Almaceno la categoria en un string temporal
        categoria = tmp;
        tmp = ""; i++;
    
        //.....................................................................
        // Asigno los valores leidos a los atributos de la clase
        setDni(dni);
        setNombre(nombre);
        setApellidos(apellidos);
        setFechaNacimiento(fechanacimiento);
        setCategoria(stoi(categoria));
    }

/***************************************************************************/
// Destructor

    Profesor :: ~Profesor()
    {
        LiberarMemoria();
    }

/*************************************************************************/
//----------------------------MÉTODOS------------------------------------//
/*************************************************************************/
// Métodos get: Devuelven el valor de los atributos

    string Profesor :: getDni() const
    {
        return DNI;
    }

//...........................................................................
    string Profesor :: getNombre() const
    {
        return Nombre;
    }

//...........................................................................
    string Profesor :: getApellidos() const
    {
        return Apellidos;
    }

//...........................................................................
    string Profesor :: getFechaNacimiento() const
    {
        return FechaNacimiento.ToString();
    }

//...........................................................................
    int Profesor :: getCategoria() const
    {
        return Categoria;
    }

/***************************************************************************/
/***************************************************************************/
// Métodos set: Modifican el valor de los atributos

    void Profesor :: setDni(string arg_DNI)
    {
        if (!(arg_DNI.length() == 9 || arg_DNI.size() == 0))
        {
            cout << "Error: El DNI debe tener 9 caracteres" << endl;
            exit(1);
        }
        
        stoptr(arg_DNI, DNI);
    }

//...........................................................................
    void Profesor :: setNombre(string arg_nombre)
    {
        stoptr(arg_nombre, Nombre);
    }

//...........................................................................
    void Profesor :: setApellidos(string arg_Apellidos)
    {
        stoptr(arg_Apellidos, Apellidos);
    }

//...........................................................................
    void Profesor :: setFechaNacimiento(string arg_FechaNacimiento)
    {
        //La comprobación de la validez de este argumento ya se hace en clase Fecha
        FechaNacimiento.setFecha(arg_FechaNacimiento);
    }

//...........................................................................
    void Profesor :: setCategoria(int arg_Categoria)
    {
        if (arg_Categoria < 1 || arg_Categoria > 5)
        {
            cerr << "Error: La categoria debe estar entre 1 y 5" << endl;
            exit(1);
        }
        
        Categoria = arg_Categoria;
    }


/***************************************************************************/
/***************************************************************************/
// Método ToString: Devuelve una cadena con los valores de los atributos

    string Profesor :: ToString(bool mes_string, string cadena_inicial) const
    {
        string cadena = cadena_inicial;

        // Solo mostrará una linea completamente vacía si los atributos son nullptr,
        // si son \0 se mostrará como "" sin más.
        if (DNI && Nombre && Apellidos)
        {
            if (strlen(DNI) || strlen(Nombre) || strlen(Apellidos) || Categoria ||
            FechaNacimiento.getMes() || FechaNacimiento.getDia())

            {
                cadena += (string) DNI + " ";
                cadena += FormatString(((string)Apellidos + ", " \
                            + (string) Nombre),32);
                cadena += FechaNacimiento.ToString(mes_string);
                cadena += "   " + to_string(Categoria);
                cadena += "\n";
            }

            else    {cadena += "PROFESOR VACIO";}
        }
        else    {cadena += "PROFESOR NO INICIALIZADO";}
        

        return cadena;
    }

//***************************************************************************/
/****************************************************************************/
// Sobrecarga del operador de asignación para copia profunda.
// Parámetros: otro (referencia), objeto que sirve de modelo. 

	Profesor& Profesor :: operator = (const Profesor & otro)
    {
        if (this != &otro)
        {
            // CopiarDatos ya se encarga de reservar/liberar memoria
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

    void Profesor :: CopiarDatos (const Profesor & otro)
    {
        // Los métodos set ya se encargan de reservar/liberar memoria
        setDni(otro.getDni());
        setNombre(otro.getNombre());
        setApellidos(otro.getApellidos());
        setFechaNacimiento(otro.getFechaNacimiento());
        setCategoria(otro.getCategoria());
    }

/***********************************************************************/
// Pide memoria para guardar una copia de los datos de "otro"
// Parámetros: otro (referencia), objeto que sirve de modelo. 

    void Profesor :: ReservarMemoria (const Profesor & otro)
    {
        LiberarMemoria();
        DNI = new char[otro.getDni().size() + 1];
        Nombre = new char[otro.getNombre().size() + 1];
        Apellidos = new char[otro.getApellidos().size() + 1];
    }

/***********************************************************************/
// Libera memoria

    void Profesor :: LiberarMemoria (void)
    {
        if (DNI) {delete[] DNI;}
        DNI = nullptr;

        if (Nombre) {delete[] Nombre;}
        Nombre = nullptr;

        if (Apellidos) {delete[] Apellidos;}
        Apellidos = nullptr;
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

    string Profesor :: FormaPalabra (string cad_fuente, int pos,\
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