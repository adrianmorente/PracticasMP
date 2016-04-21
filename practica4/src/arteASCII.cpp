#include <iostream>
#include <fstream>
#include <string>
#include "byte.h"
#include "imagen.h"
#include "pgm.h"
using namespace std;

int main(){

    const int MAX = 200000;
    const int LONG = 60;

    char nombre_imagen[LONG];     //nombre de la imagen de entrada
    char nombre_grises[LONG];        //nombre del fichero de caracteres de entrada
    char grises[MAX];                       //contenido del fichero de caracteres
    char img_salida[MAX];         //contenido de la imagen de salida
    char arteASCII[MAX];           //contenido de la imagen ASCII de salida
    ifstream entrada;
    Imagen origen;

    int n_cadenas; //numero de cadenas que hay en <nombre_grises>
    char aux[100];

    cout << "imagen de entrada (imagenes/<nombre>.pgm): ";
    cin >> nombre_imagen;
    cout << "fichero de cadenas (<nombre>.txt): ";
    cin >> nombre_grises;
    cout << "fichero de salida (<nombre>.pgm): ";
    cin >> img_salida;

    ofstream salida(img_salida);

    entrada.open(nombre_grises);

    //Leemos el fichero de grises (comprobando errores) -->
    if(entrada){
        entrada.getline(aux, 80);    //ignoramos la primera linea
        entrada >> n_cadenas;        //capturamos el numero de cadenas de <nombre_grises>
        cout << "nº cadenas: " << n_cadenas;
        if(!entrada){
            cerr << "Error de lectura del fichero de caracteres...\n";
        }
        //Aqui leemos el resto del fichero y almacenamos en los ficheros de salida
        while(!entrada.eof()){

            entrada.getline()
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
    if(origen.aArteASCII(grises, arteASCII, MAX))
        cout << arteASCII;
    else
        cout << "La conversion no ha sido posible" << endl;

    return 0;
}
