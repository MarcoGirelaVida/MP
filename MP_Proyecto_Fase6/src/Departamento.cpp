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
// Declaraciones en: Departamento.h
//
// Fichero: Departamento.cpp
//
/***************************************************************************/
/***************************************************************************/

#include "Departamento.h"


using namespace std;

/*************************************************************************/
//-------------------------CONSTRUCTORES---------------------------------//
/*************************************************************************/
// Constructor por defecto

    Departamento :: Departamento()
                        : Id_depto(nullptr), Nombre(nullptr)
    {   
        SetNombre();
        SetId_Dpto();
    }

/************************************************************************/
// Constructor desde dos string.
// Parámetros: el_id_depto, string con el id del departamento. 
//             el_nombre, string con el nombre del departamento. 

    Departamento :: Departamento(string el_id_depto, string el_nombre)
                        : Id_depto(nullptr), Nombre(nullptr)
    {
        SetId_Dpto(el_id_depto);
        SetNombre(el_nombre);
    }

/************************************************************************/
// Constructor de copia
// Parámetros: otro (referencia), objeto que sirve de modelo. 

    Departamento :: Departamento(const Departamento & otro)
                        : Id_depto(nullptr), Nombre(nullptr)
    {
        // Copiar datos ya reserva/libera memoria
        CopiarDatos(otro);
    }

/*************************************************************************/
// Constructor desde un string.
// Compone un dato Encargo a patir de un dato string. 
// Parámetros: linea, el dato string del que se extraen los valores.
// 			   delimitador, el caracter que delimita los campos. 
        
    Departamento :: Departamento(string linea, char delimitador)
                        : Id_depto(nullptr), Nombre(nullptr)
    {
        string id, nombre;
        istringstream flujo(linea);

        // Leo el primer elemento del string (id)
        getline(flujo, id, delimitador);

        //.....................................................................
        // Leo el segundo elemento del string (nombre)
        getline(flujo, nombre, delimitador);

        SetId_Dpto(id);
        SetNombre(nombre);
    }

/***************************************************************************/
// Destructor
    Departamento :: ~Departamento()
    {
        LiberarMemoria(); 
    }

/*************************************************************************/
//----------------------------MÉTODOS------------------------------------//
/*************************************************************************/
// Métodos get, dado que no quiero modificarlos, los declaro como const

    string Departamento :: GetNombre() const
    {
        string nombre = "SIN_NOMBRE";
        if (Nombre != nullptr)
        {
            nombre = Nombre;
        }
        
        return nombre;
    }


    string Departamento :: GetId_Dpto() const
    {
        string id = "SIN_ID";
        if (Id_depto != nullptr)
        {
            id = Id_depto;
        }

        return id;
    }

/***************************************************************************/
// Métodos set

    void Departamento :: SetNombre(string nombre)
    {stoptr(nombre, Nombre);}


    void Departamento :: SetId_Dpto(string id)
    {stoptr(id, Id_depto);}

/***************************************************************************/
// OPERATOR >> 
// Lee un dato Departamento desde un flujo de entrada.
// Parámetros: flujo, referencia a un flujo de entrada.
//             otro, referencia a un objeto de la clase Departamento. 

    istream & operator >> (istream & flujo, Departamento & otro)
    {
        cerr << "Estoy en operator>> de Departamento" << endl;
        string linea;
        bool continua = true;
        int i = 0;

        while(getline(flujo, linea) && continua)
        {
            i++;
            if (linea[0] != '#')
            {
                otro = Departamento(linea);
                continua = false;
            }
            else
            {
                continua = true;
            }
        }
        cerr << "He salido de operator>> de Departamento" << endl;
        return flujo;
    }

/***************************************************************************/
// OPERATOR <<
// Escribe un dato Departamento en un flujo de salida.
// Parámetros: flujo, referencia a un flujo de salida.
//             otro, referencia a un objeto de la clase Departamento. 

    ostream & operator << (ostream & flujo, const Departamento & otro)
    {
        flujo << otro.ToString();
        return flujo;
    }

/***************************************************************************/
// Método ToString

    string Departamento :: ToString(string cadena_inicial, char delimitador) const
    {   
        string cadena = cadena_inicial;

        if (Id_depto || Nombre)
        {
            if (strlen(Id_depto) || strlen(Nombre))
            {
                cadena += (string) Id_depto + delimitador;
                cadena += (string) Nombre + delimitador + "\n";
            }
            else    {cadena += "DEPARTAMENTO VACIO\n";}
        }
        else    {cadena += "DEPARTAMENTO NO INICALIZADO\n";}
        

        return cadena;
    }

/***********************************************************************/
// Sobrecarga del operador de asignación para copia profunda.
// Parámetros: otro (referencia), objeto que sirve de modelo. 
    Departamento & Departamento :: operator = (const Departamento & otro)
    {
        if (this != &otro)
        {
            // Copiar datos ya reserva/libera memoria
            CopiarDatos(otro);
        }

        return *this;
    }

/***********************************************************************/
// Sobrecarga del operador == para comprobar si un departamento es igual 
// a otro (tiene la misma clave primaria)

    bool Departamento :: operator == (const Departamento & otro) const
    {
        bool son_iguales = false;

        if (this != &otro)
        {
            if (GetId_Dpto() == otro.GetId_Dpto())
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
// PRE: Se ha reservado memoria para los datos

    void Departamento :: CopiarDatos (const Departamento & otro)
    {
        // Los métodos set ya se encargan de liberar y reservar memoria
        SetId_Dpto(otro.GetId_Dpto());
        SetNombre(otro.GetNombre());
    }

/***********************************************************************/
// Pide memoria para guardar una copia de los datos de "otro"
// Parámetros: otro (referencia), objeto que sirve de modelo. 

    void Departamento :: ReservarMemoria (const Departamento & otro)
    {
        LiberarMemoria();
        Nombre = new char [otro.GetNombre().size() + 1];
        Id_depto = new char [otro.GetId_Dpto().size() + 1];
    }


/***********************************************************************/
// Libera memoria

    void Departamento :: LiberarMemoria (void)
    {
        if (Nombre)
        {
            delete [] Nombre;
            Nombre = nullptr;
        }

        if (Id_depto)
        {
            delete [] Id_depto;
            Id_depto = nullptr;  
        }   
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

    string Departamento :: FormaPalabra (string cad_fuente, int pos, \
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
