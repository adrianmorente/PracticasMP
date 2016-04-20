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
    char img_salida[100000];
    ifstream entrada;
    ofstream salida;
    Imagen origen;

    cout << "imagen de entrada (imagenes/<nombre>.pgm): ";
    cin >> imagen;
    cout << "fichero de cadenas: ";
    cin >> grises;
    cout << "fichero de salida: ";
    cin >> img_salida;

    int n_cadenas; //numero de cadenas que hay en grises.txt
    char aux[100];
    entrada.open(imagen);
    if(entrada){
        entrada >> aux;    //ignoramos la primera linea
        entrada >> n_cadenas;
        if(!entrada){
            cerr << "Error de lectura del fichero...\n";
        }
        while(entrada){
            entrada >> imagen;
        }
        entrada.close();
    }
    else{
        cerr << "Error de apertura del fichero...\n";
    }

    return 0;
}
