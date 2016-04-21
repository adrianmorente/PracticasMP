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
    char nombre_imagen[50000];
    char nombre_grises[50];
    char grises[200];
    char img_salida[50000];
    char arteASCII[50000];
    ifstream entrada;
    Imagen origen;

    int n_cadenas; //numero de cadenas que hay en <nombre_grises>
    char aux[100];

    cout << "imagen de entrada (imagenes/<nombre>.pgm): ";
    cin >> nombre_imagen;
    cout << "fichero de cadenas: ";
    cin >> nombre_grises;
    cout << "fichero de salida: ";
    cin >> img_salida;

    ofstream salida(img_salida);


    entrada.open(nombre_grises);

    if(entrada){
        entrada.getline(aux, 80);    //ignoramos la primera linea
        entrada >> n_cadenas;        //capturamos el numero de cadenas de <nombre_grises>
        if(!entrada){
            cerr << "Error de lectura del fichero de caracteres...\n";
        }
        while(entrada){
            entrada >> imagen;
        }
        entrada.close();
    }
    else{
        cerr << "Error de apertura del fichero de caracteres...\n";
    }

    if(!origen.leerImagen(nombre_imagen)){
        cout << "Error leyendo imagen " << nombre_imagen << "...";
        return 1;
    }

    cout << "\nLa imagen en arte ASCII es:\n";
    if(origen.aArteASCII(grises, arteASCII, 50000))
        cout << arteASCII;
    else
        cout << "La conversion no ha sido posible" << endl;

    return 0;
}
