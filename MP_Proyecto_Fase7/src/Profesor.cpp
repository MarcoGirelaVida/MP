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
                      Categoria('A')
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
                      Categoria('A')
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
                                string la_fecha, char la_categoria)
                    : DNI(nullptr), Nombre(nullptr), Apellidos(nullptr),\
                      Categoria('A')
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
                      Categoria('A')
    {
        string dni, nombre, apellidos, fechanacimiento, categoria;
        string hasta_salto_de_linea;
        istringstream flujo(linea);

        // Tomo la linea hasta el primer salto de linea
        // Porque los datos deben estar en una única linea
        if (getline(flujo, hasta_salto_de_linea))
        {
            istringstream flujo2(hasta_salto_de_linea);

            // Leo los datos separados por los delimitadores
            if (getline(flujo2, dni, delimitador)){
            if (getline(flujo2, categoria, delimitador)){
            if (getline(flujo2, nombre, delimitador)){
            if (getline(flujo2, apellidos, delimitador)){
            if (getline(flujo2, fechanacimiento, delimitador)){

                // Si todo ha ido bien, guardo los datos
                setDni(dni);
                setNombre(nombre);
                setApellidos(apellidos);
                setFechaNacimiento(fechanacimiento);
		char categoria_char = categoria[0];
                setCategoria(categoria_char);
            }
            else{
                cerr << "Error: No se ha guardado el Profesor porque"
                     << " la linea solo contenía 4 elementos, deben ser 5" << endl;
                }
            }
            else{
                cerr << "Error: No se ha guardado el Profesor porque"
                        << " la linea solo contenía 3 elementos, deben ser 5" << endl;
                }
            }
            else{
                cerr << "Error: No se ha guardado el Profesor porque"
                        << " la linea solo contenía 2 elementos, deben ser 5" << endl;
                }
            }
            else{
                cerr << "Error: No se ha guardado el Profesor porque"
                        << " la linea solo contenía un elemento, deben ser 5" << endl;
                }
            }
            else{
                cerr << "Error: No se ha guardado el Profesor porque"
                    << " la linea no contenía elementos" << endl;
            } 
        }
    /*
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
    */
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
        string dni = "VACIO";
        if (DNI != nullptr)
        {
            dni = DNI;
        }
        
        return dni;
    }

//...........................................................................
    string Profesor :: getNombre() const
    {
        string nombre = "VACIO";
        if (Nombre != nullptr)
        {
            nombre = Nombre;
        }
        
        return nombre;
    }

//...........................................................................
    string Profesor :: getApellidos() const
    {
        string apellidos = "VACIO";
        if (Apellidos != nullptr)
        {
            apellidos = Apellidos;
        }
        
        return apellidos;
    }

//...........................................................................
    string Profesor :: getFechaNacimiento() const
    {
        return FechaNacimiento.ToString();
    }

//...........................................................................
    char Profesor :: getCategoria() const
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
            TodoNulo();
        }
        
        if (!contiene_delimitadores(arg_DNI))
        {
            stoptr(arg_DNI, DNI);
        }
        else
        {
            cerr << "Error: El DNI no puede contener el delimitador" << endl;
            TodoNulo();
        }
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
    void Profesor :: setCategoria(char arg_Categoria)
    {
        if (arg_Categoria < (int) 'A' || arg_Categoria > (int) 'E')
        {
            cerr << "Error: La categoria debe estar entre A y E" << endl;
            TodoNulo();
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

        if(getline(flujo, linea))
        {
            otro = Profesor(linea);
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
            if (strlen(DNI) || strlen(Nombre) || strlen(Apellidos) ||
            FechaNacimiento.getMes() || FechaNacimiento.getDia())

            {
                cadena += (string) DNI + delimitador;
                cadena += delimitador + Categoria;
                cadena += FormatString(((string)Nombre + delimitador \
                            + (string)Apellidos),32);
                cadena += delimitador +FechaNacimiento.ToString(mes_string);
                cadena += delimitador + "\n";
            }

            else    {cadena += "PROFESOR VACIO";}
        }
        else    {cadena += "PROFESOR VACIO";}
        

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

    /*************************************************************************/
	// TODONULO: Pone todos los atributos a nulo
    
    void Profesor :: TodoNulo (void)
    {
        string nulo = "NULO";
        stoptr(nulo, DNI);
        stoptr(nulo, Nombre);
        stoptr(nulo, Apellidos);
        Categoria = 'A';
        FechaNacimiento = Fecha();
    }
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
