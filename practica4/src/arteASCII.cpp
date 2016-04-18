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
    char nombre_imagen[131072];
    char nombre_grises[60];
    char nombre_txt[60];
    char arteASCII[131072];
    char aux[80];
    ifstream entrada;

    Imagen origen;

    cout << "Introduce el nombre de la imagen de entrada: ";
    cin >> nombre_imagen;

    cout << "Introduce el nombre del archivo que contiene los elementos de grises: ";
    cin >> nombre_grises;

    cout << "Introduce el nombre del .txt de salida: ";
    cin >> nombre_txt;

    entrada.open(nombre_imagen);
    if(entrada){
        entrada >> lee_linea(aux, 80);    //ignoramos la primera linea
        entrada >> n_cadenas;
        while(entrada){
            //entrada de datos
        }
        entrada.close();
    }
    else{
        cerr << "Error de apertura del fichero...\n";
    }

    cout << "\nLa imagen en arte ASCII es:\n";
    if(origen.aArteASCII(grises, arteASCII, 131072))
        cout << arteASCII;
    else
        cout << "La conversion no ha sido posible" << endl;

    return 0;
}
