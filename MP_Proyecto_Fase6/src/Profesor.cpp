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

#include "Profesor.h"

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
        istringstream flujo(linea);

        // Leo el DNI
        getline(flujo, dni, delimitador);

        //.....................................................................
        // Leo el nombre
        getline(flujo, nombre, delimitador);

        //.....................................................................
        // Leo los apellidos
        getline(flujo, apellidos, delimitador);

        //.....................................................................
        // Leo la fecha de nacimiento
        getline(flujo, fechanacimiento, delimitador);

        //.....................................................................
        // Leo la categoria
        getline(flujo, categoria, delimitador);

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
// OPERATOR >> 
// Lee un dato Profesor desde un flujo de entrada.
// Parámetros: flujo, referencia a un flujo de entrada.
//             otro, referencia a un objeto de la clase Profesor. 

    istream & operator >> (istream & flujo, Profesor & otro)
    {
        string linea;
        bool continua = true;

        while(getline(flujo, linea) && continua)
        {
            if (linea[0] != '#')
            {
                otro = Profesor(linea);
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
// Escribe un dato Profesor en un flujo de salida.
// Parámetros: flujo, referencia a un flujo de salida.
//             otro, referencia a un objeto de la clase Profesor. 

    ostream & operator << (ostream & flujo, const Profesor & otro)
    {
        flujo << otro.ToString();
        return flujo;
    }

/***************************************************************************/
// Método ToString: Devuelve una cadena con los valores de los atributos

    string Profesor :: ToString(bool mes_string, string cadena_inicial, char delimitador) const
    {
        string cadena = cadena_inicial;

        // Solo mostrará una linea completamente vacía si los atributos son nullptr,
        // si son \0 se mostrará como "" sin más.
        if (DNI && Nombre && Apellidos)
        {
            if (strlen(DNI) || strlen(Nombre) || strlen(Apellidos) || Categoria ||
            FechaNacimiento.getMes() || FechaNacimiento.getDia())

            {
                cadena += (string) DNI + delimitador;
                cadena += FormatString(((string)Nombre + delimitador \
                            + (string)Apellidos),32);
                cadena += FechaNacimiento.ToString(mes_string);
                cadena += delimitador + to_string(Categoria);
                cadena += delimitador + "\n";
            }

            else    {cadena += "PROFESOR VACIO";}
        }
        else    {cadena += "PROFESOR NO INICIALIZADO";}
        

        return cadena;
    }

/***********************************************************************/
// Sobrecarga del operador == para comprobar si un Profesor es igual 
// a otro (tiene la misma clave primaria)

    bool Profesor :: operator == (const Profesor & otro) const
    {
        bool son_iguales = false;

        if (this != &otro)
        {
            if (getDni() == otro.getDni())
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