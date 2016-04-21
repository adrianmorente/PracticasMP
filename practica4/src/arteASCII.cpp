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
    string img_salida;         //nombre parcial de las imagenes de salida
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

    entrada.open(nombre_grises);
    char salida1[LONG];
    char salida2[LONG];
    char salida3[LONG];
    char salida4[LONG];

    //Leemos el fichero de grises (comprobando errores) -->
    if(entrada){
        entrada.getline(aux, 80);    //ignoramos la primera linea
        entrada >> n_cadenas;        //capturamos el numero de cadenas de <nombre_grises>
        if(!entrada){
            cerr << "Error de lectura del fichero de caracteres...\n";
        }
        //Aqui leemos el resto del fichero y almacenamos en los ficheros de salida
        //while(!entrada.eof()){
        //}
        entrada.getline(salida1, LONG);
        entrada.getline(salida2, LONG);
        entrada.getline(salida3, LONG);
        entrada.getline(salida4, LONG);

        entrada.close();
    }
    else{
        cerr << "Error de apertura del fichero de caracteres...\n";
    }

    //Leemos la imagen de entrada y creamos los ficheros ASCII correspondientes
    if(!origen.leerImagen(nombre_imagen)){
        cout << "Error leyendo imagen " << nombre_imagen << "...";
        return 1;
    }

    cout << "\n\n" << salida1;


    return 0;
}
