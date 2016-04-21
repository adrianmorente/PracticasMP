#include <iostream>
#include <fstream>
#include <string>
#include "byte.h"
#include "imagen.h"
#include "pgm.h"
using namespace std;

int main(){

    //const int MAX = 200000;
    const int LONG = 60;

    char nombre_imagen[LONG];     //nombre de la imagen de entrada
    char nombre_grises[LONG];        //nombre del fichero de caracteres de entrada
    string img_salida;         //nombre parcial de las imagenes de salida
    ifstream entrada;
    Imagen origen;

    int n_cadenas; //numero de cadenas que hay en <nombre_grises>
    char aux[100];
    int entero_aux;

    cout << "imagen de entrada (imagenes/<nombre>.pgm): ";
    cin >> nombre_imagen;
    cout << "fichero de cadenas (<nombre>.txt): ";
    cin >> nombre_grises;
    cout << "fichero de salida: ";
    cin >> img_salida;

    entrada.open(nombre_grises);

    //Leemos el fichero de grises (comprobando errores) -->
    if(entrada){
        entrada.getline(aux, 80);    //ignoramos la primera linea
        entrada >> n_cadenas;        //capturamos el numero de cadenas de <nombre_grises>
        if(!entrada){
            cerr << "Error de lectura del fichero de caracteres...\n";
        }
        //Aqui leemos el resto del fichero y almacenamos en los ficheros de salida
        int i=1;
        string nombre;
        while(!entrada.eof()){
            //defino el nombre del archivo de salida
            nombre = img_salida + to_string(i) + ".txt";
            ofstream fsalida(nombre);
            char auxiliar[LONG];
            entrada.getline(auxiliar, LONG);
            fsalida.close();
            i++;
        }
        entrada.close();
        entero_aux = i;
    }
    else{
        cerr << "Error de apertura del fichero de caracteres...\n";
    }

    //Leemos la imagen de entrada y creamos los ficheros ASCII correspondientes
    if(!origen.leerImagen(nombre_imagen)){
        cout << "Error leyendo imagen " << nombre_imagen << "...";
        return 1;
    }
    else if(origen.leerImagen(nombre_imagen)){
        for(int j=0; j<entero_aux; j++){
            string faux;
            faux = img_salida + to_string(entero_aux) + ".txt";
            if(origen.escribirImagen(nombre_imagen, false)){
                cout << "Imagen " << j << " creada correctamente." << endl;
            }
            else{
                cout << "Error al escribir la imagen " << j << "..." << endl;
            }
        }
    }

    return 0;
}
