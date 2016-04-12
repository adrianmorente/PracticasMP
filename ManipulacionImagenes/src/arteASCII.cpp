#include <iostream>
#include <string>
#include "byte.h"
#include "imagen.h"
#include "pgm.h"
using namespace std;

int main(){
    string nombre_imagen;
    char c1, c2, c3, c4;

    cout << "Introduce el nombre de la imagen de entrada: ";
    cin >> nombre_imagen;

    cout << "\nVamos con los caracteres usados para el arte ASCII (0-255)." << endl;
    cout << "Introduce el caracter usado para los colores en (0-63): ";
    cin >> c1;
    cout << "Introduce el caracter usado para los colores en (64-127): ";
    cin >> c2;
    cout << "Introduce el caracter usado para los colores en (128-191): ";
    cin >> c3;
    cout << "Introduce el caracter usado para los colores en (192-255): ";
    cin >> c4;


}
