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
        string dni, id, hasta_salto_de_linea;
        istringstream flujo(linea);

        // Tomo la linea hasta el primer salto de linea
        // Porque los datos deben estar en una única linea
        if (getline(flujo, hasta_salto_de_linea))
        {
            istringstream flujo2(hasta_salto_de_linea);

            // Leo hasta el primer delimitador (presunto id)
            if  (getline(flujo2, dni, delimitador)){
            if  (getline(flujo2, id, delimitador)){

                // Si todo ha ido bien, guardo los datos
                setDniProfesor(dni);
                setIdDepartamento(id);

            }
            else{
                    cerr << "Error: No se ha guardado la Adscripcion porque"
                         << " la linea solo contenía un elemento, deben ser 2" << endl;

            }}
            else{
                cerr << "Error: No se ha guardado la Adscripcion porque"
                     << " la linea no contenía elementos" << endl;
            } 
        }

    /*
        string dni, id;
        istringstream flujo(linea);

        // Leo el primer elemento del string (dni)
        getline(flujo, dni, delimitador);

        //.....................................................................
        // Leo el segundo elemento del string (id_dtpo)
        getline(flujo, id, delimitador);

        //.....................................................................ç
        // Asigno los valores a los atributos
        setDniProfesor(dni);
        setIdDepartamento(id);
    */
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
    {        
        string dni = "VACIO";
        if (DNI != nullptr)
        {
            dni = DNI;
        }
        
        return dni;
    }


    string Adscripcion :: getIdDepartamento() const
    {
        string id = "VACIO";
        if (Id_depto != nullptr)
        {
            id = Id_depto;
        }

        return id;
    }

/***************************************************************************/
// Métodos set

    void Adscripcion :: setDniProfesor(string arg_DNI)
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


    void Adscripcion :: setIdDepartamento(string id)
    {
        if (!contiene_delimitadores(id))
        {
            stoptr(id, Id_depto);
        }
        else
        {
            cerr << "Error: No se ha guardado el Departamento porque" 
                 << " contenía espacios, tabuladores u otros en el ID"
                 << endl;
            TodoNulo();
        }
    }


/***************************************************************************/
// OPERATOR >> 
// Lee un dato Adscripcion desde un flujo de entrada.
// Parámetros: flujo, referencia a un flujo de entrada.
//             otro, referencia a un objeto de la clase Adscripcion. 

    istream & operator >> (istream & flujo, Adscripcion & otro)
    {
        string linea;
        bool continua = true;

        if(getline(flujo, linea))
        {
            otro = Adscripcion(linea);
        }
        
        return flujo;
    }

/***************************************************************************/
// OPERATOR <<
// Escribe un dato Adscripcion en un flujo de salida.
// Parámetros: flujo, referencia a un flujo de salida.
//             otro, referencia a un objeto de la clase Adscripcion. 

    ostream & operator << (ostream & flujo, const Adscripcion & otro)
    {
        flujo << otro.ToString();
        return flujo;
    }

/***************************************************************************/
// Método ToString

    string Adscripcion :: ToString(string cadena_inicial, char delimitador) const
    {   
        string cadena = cadena_inicial;
        
        if (DNI || Id_depto)
        {
            if (strlen(DNI) && strlen(Id_depto))
            {
                cadena += (string) DNI;
                cadena += delimitador;
                cadena += (string) Id_depto + delimitador + "\n";
            }
            else    {cadena += "ADSCRIPCIÓN VACIA\n";}
        }
        else    {cadena += "ADSCRIPCIÓN NO INICIALIZADA\n";}
        
        return cadena;
    }

/***********************************************************************/
// Sobrecarga del operador == para comprobar si un Adscripcion es igual 
// a otro (tiene la misma clave primaria)

    bool Adscripcion :: operator == (const Adscripcion & otro) const
    {
        bool son_iguales = false;

        if (this != &otro)
        {
            if (getDniProfesor() == otro.getDniProfesor())
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

    /*************************************************************************/
	// TODONULO: Pone todos los atributos a nulo
    
    void Adscripcion :: TodoNulo (void)
    {
        string nulo = "NULO";
        stoptr(nulo, DNI);
        stoptr(nulo, Id_depto);
    }
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
