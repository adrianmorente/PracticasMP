#include <iostream>
#include "bloqueLed.h"
using namespace std;

int main()
{
    bloqueLed b;
    int posiciones[8];
    int size;
    bool inicial[] = {1,0,1,0,0,0,0,0};

    apagar(b);
    cout << "\nBloque apagado LEDs: ";
    cout << bloqueLedToString(b) << endl;


    cout << "\nInicializo el bloque a partir de un vector de bool ";
    asignar(b,inicial);
    cout << bloqueLedToString(b)<< endl;
    cout << "\nAhora enciendo los LEDs 0, 1 y 2 con la funcion on \n";
    on(b,0);
    cout << bloqueLedToString(b)<< endl;
    on(b,1);
    cout << bloqueLedToString(b)<< endl;
    on(b,2);
    cout << bloqueLedToString(b)<< endl;

    cout << "\nLos LEDs encendidos estan en las posiciones: ";
    encendidos(b,posiciones, size);
    for(int i=0; i< size; i++)
        cout << posiciones[i] << ",";

    cout << endl;

    cout << "\nTodos encendidos: ";
    encender(b);
    cout << bloqueLedToString(b)<< endl;

    cout << "Todos apagados: ";
    apagar(b);
    cout << bloqueLedToString(b)<< endl;

    cout << "\nAhora la animacion\nEjemplo 1:\n";
    encender(b);
    cout << bloqueLedToString(b) << endl;
    off(b, 7);
    cout << bloqueLedToString(b) << endl;
    on(b, 7);   off(b, 6);
    cout << bloqueLedToString(b) << endl;
    on(b, 6);   off(b, 5);
    cout << bloqueLedToString(b) << endl;
    on(b, 5);   off(b, 4);
    cout << bloqueLedToString(b) << endl;
    on(b, 4);   off(b, 3);
    cout << bloqueLedToString(b) << endl;
    on(b, 3);   off(b, 2);
    cout << bloqueLedToString(b) << endl;
    on(b, 2);   off(b, 1);
    cout << bloqueLedToString(b) << endl;
    on(b, 1);   off(b, 0);
    cout << bloqueLedToString(b) << endl;


    cout << "\nAhora la animacion\nEjemplo 2: \n";
    encender(b);
    cout << bloqueLedToString(b) << endl;
    off(b, 7);  off(b, 0);
    cout << bloqueLedToString(b) << endl;
    off(b, 6);  off(b, 1);
    cout << bloqueLedToString(b) << endl;
    off(b, 5);  off(b, 2);
    cout << bloqueLedToString(b) << endl;
    apagar(b);
    cout << bloqueLedToString(b) << endl;
    on(b, 4);   on(b, 3);
    cout << bloqueLedToString(b) << endl;
    on(b, 5);   on(b, 2);
    cout << bloqueLedToString(b) << endl;
    on(b, 6);   on(b, 1);
    cout << bloqueLedToString(b) << endl;
    on(b, 7);   on(b, 0);
    cout << bloqueLedToString(b) << endl;


}
