#include <iostream>
#include <string>
#include "byte.h"
#include "imagen.h"
#include "pgm.h"
using namespace std;

int main(){
    char nombre_imagen[131072];
    char arteASCII[131072];
    char grises[10];
    int n_grises=-1;

    Imagen origen;

    cout << "Introduce el nombre de la imagen de entrada: ";
    cin >> nombre_imagen;

    cout << "\nVamos con los caracteres usados para el arte ASCII (0-255)." << endl;
    do{
        cout << "Introduce el numero de caracteres distintos usados (>=4 && <=10): ";
        cin >> n_grises;
    }while(n_grises<0 || n_grises >10);

    cout << "\nAhora introduce dichos caracteres (de uno en uno): ";
    for(int i=0; i<n_grises; i++){
        cout << "Caracter " << i << ": ";
        cin >> grises[i];
    }

    if(!origen.leerImagen(nombre_imagen)){
        cout << "Error leyendo imagen " << nombre_imagen << "...";
        return 1;
    }

    cout << "\nLa imagen en arte ASCII es:\n";
    if(origen.aArteASCII(grises, arteASCII, 131072))
        cout << arteASCII;
    else
        cout << "La conversion no ha sido posible" << endl;

    return 0;
}
