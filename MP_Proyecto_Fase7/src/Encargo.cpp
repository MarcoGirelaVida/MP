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
        string cat, cred, hasta_salto_de_linea;
        istringstream flujo(linea);

        // Tomo la linea hasta el primer salto de linea
        // Porque los datos deben estar en una única linea
        if (getline(flujo, hasta_salto_de_linea))
        {
            istringstream flujo2(hasta_salto_de_linea);

            // Leo hasta el primer delimitador (presunto id)
            if  (getline(flujo2, cat, delimitador)){
            if  (getline(flujo2, cred, delimitador)){

                // Si todo ha ido bien, guardo los datos
                setCategoria(cat[0]);
                setCreditos(stod(cred));
            }
            else{
                    cerr << "Error: No se ha guardado la Encargo porque"
                         << " la linea solo contenía un elemento, deben ser 2" << endl;

            }}
            else{
                    cerr << "Error: No se ha guardado el Encargo porque"
                         << " la linea no contenía elementos" << endl;
            } 
        }
        /*
            string cat, cred;
            istringstream flujo(linea);

            // Leo el primer elemento del string (categoria)
            getline(flujo, cat, delimitador);

            //.....................................................................
            // Leo el segundo elemento del string (creditos)
            getline(flujo, cred, delimitador);

            // Almaceno los datos obtenidos en los atributos
            setCategoria(stoi(cat));
            setCreditos(stod(cred));
        */
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

    char Encargo :: getCategoria() const
    {return categoria;}


    double Encargo :: getCreditos() const
    {return creditos;}

/***************************************************************************/
// Métodos set

    void Encargo :: setCategoria(char cat)
    {
        if (cat < (int) 'A' || cat > (int) 'E')
        {
            //cerr << "Error: La categoria debe estar entre 1 y 5" << endl;
            TodoNulo();
        }
        categoria = cat;
    }

    void Encargo :: setCreditos(double cred)
    {
        if (cred < 0)
        {
            cerr << "Error: Los creditos deben ser positivos" << endl;
            TodoNulo();
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

        if(getline(flujo, linea))
        {
            otro = Encargo(linea);
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

/*************************************************************************/
// TODONULO: Pone todos los atributos a 0

    void Encargo :: TodoNulo()
    {
        setCategoria(0);
        setCreditos(0);
    }
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
