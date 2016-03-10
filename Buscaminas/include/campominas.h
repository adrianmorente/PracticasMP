#ifndef CAMPOMINAS_H_
#define CAMPOMINAS_H_

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include "tablero.h"
using namespace std;

/*--------------------------------------------------------------*/

inline int GetRandom(int minimo, int maximo);

/*--------------------------------------------------------------*/

class Campominas{
private:
	Tablero juego;
	int minas;
	bool estado;
	
public:
	Campominas(int fila1, int columna1, int nminas);
	bool Estado();
	bool CheckVictoria();
	void PrettyPrint();
	void Imprimir();
	void Menu();
};

/*--------------------------------------------------------------*/

#endif