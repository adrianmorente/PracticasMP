#ifndef TABLERO_H_
#define TABLERO_H_

#include <iostream>
#include <cstdlib>
#include <unistd.h>
using namespace std;

/*--------------------------------------------------------------*/

struct Casilla{
	bool bomba;
	bool abierta;
	bool marcada;
};

/*--------------------------------------------------------------*/

class Tablero{
private:
	static const int TAM=20;
	Casilla datos[TAM][TAM];
	int filas_util,columnas_util;

public:	
	void Inicializar(int fila, int columna);
	bool GetBomba(int fila, int columna);
	bool GetAbierta(int fila, int columna);
	bool GetMarcada(int fila, int columna);
	int JuntoAMina(int fila, int columna);
	void AbrirCasilla(int fil, int col);
	void SetBomba(int fila, int columna);
	void SetMarcada(int fila, int columna);
	int ConsultaFilas();
	int ConsultaColumnas();
};

/*--------------------------------------------------------------*/

#endif