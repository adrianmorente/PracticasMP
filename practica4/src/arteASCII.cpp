#include <iostream>
#include <fstream>
#include <string>
#include "byte.h"
#include "imagen.h"
#include "pgm.h"
using namespace std;

void lee_linea(char c[], int tamano){
    do{
        cin.getline(c, tamano);
    }while(c[0] == '\0');   //while(longitud(c)==0);
}

int main(){
    char imagen[100000];
    char grises[100];
    char salida[100000];
    ifstream entrada;

    Imagen origen;

    cout << "imagen de entrada: ";
    cin >> imagen;
    cout << "fichero de cadenas: ";
    cin >> grises;
    cout << "fichero de salida: ";
    cin >> salida;

    // entrada.open(imagen);
    // if(entrada){
    //     entrada >> lee_linea(aux, 80);    //ignoramos la primera linea
    //     entrada >> n_cadenas;
    //     while(entrada){
    //         //entrada de datos
    //     }
    //     entrada.close();
    // }
    // else{
    //     cerr << "Error de apertura del fichero...\n";
    // }
    //
    // cout << "\nLa imagen en arte ASCII es:\n";
    // if(origen.aArteASCII(grises, arteASCII, 131072))
    //     cout << arteASCII;
    // else
    //     cout << "La conversion no ha sido posible" << endl;

    return 0;
}
