
#include <iostream>
#include "MiCadenaClasica.h"

using namespace std;


int main(){

    const int TAM = 80;
    char cad[TAM] = "Hola que tal";
    char cad2[TAM] = "Hola que tal";
    char palindromo[TAM] = "farigiraf";
    char a_copiar[TAM];
    char a_invertir[TAM];


    int longitud = longitud_cadena(cad);

    cout << "La longitud de la cadena es: " << longitud << endl;

    int iguales = compara_cadenas(cad, cad2);

    cout << "Aquí pondrá 0 porque son iguales las cadenas cad y cad2: ";
    cout << iguales << endl;

    cout << "Es palíndromo " << palindromo << " ?" << endl;

    if (es_palindromo(palindromo))
        cout << "es palindromo" << endl;
    else
        cout << "no es palindromo" << endl;

    copiar_cadena(a_copiar, palindromo);

    cout << "He copiado la cadena palindromo, y ahora a_copiar es: " << a_copiar;
    cout << endl;

    inviertir_cadena(a_invertir, cad);

    cout << "La cadena a_invertir es: " << a_invertir;

    return(0);

}