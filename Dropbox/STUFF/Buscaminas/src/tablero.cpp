#include "tablero.h"
#include "campominas.h"
using namespace std;

/*--------------------------------------------------------------*/


bool Tablero::GetBomba(int fila, int columna){
	if(fila>=0 && fila<filas_util && columna>=0 && columna<columnas_util)
		return datos[fila][columna].bomba;
	else
		return 0;
}

bool Tablero::GetAbierta(int fila, int columna){
	if(fila>=0 && fila<filas_util && columna>=0 && columna<columnas_util)
		return datos[fila][columna].abierta;
	else
		return 0;
}

bool Tablero::GetMarcada(int fila, int columna){
	if(fila>=0 && fila<filas_util && columna>=0 && columna<columnas_util)
		return datos[fila][columna].marcada;
	else
		return 0;
}

void Tablero::SetBomba(int fila, int columna){
	datos[fila][columna].bomba=true;
}

void Tablero::SetMarcada(int fila, int columna){
	if(!GetMarcada(fila, columna))
		datos[fila][columna].marcada=true;
	else
		datos[fila][columna].marcada=false;
}

int Tablero::ConsultaFilas(){
	return filas_util;
}

int Tablero::ConsultaColumnas(){
	return columnas_util;
}

void Tablero::Inicializar(int fila, int columna){
	filas_util = fila;
	columnas_util = columna;

	for(int i=0; i<filas_util; i++){
		for(int j=0; j<columnas_util; j++){
			datos[i][j].bomba = false;
			datos[i][j].abierta = false;
			datos[i][j].marcada = false;
		}
	}
}

int Tablero::JuntoAMina(int fila, int columna){
	int n_minas=0;

	for(int i=fila-1; i<=fila+1; i++){
		for(int j=columna-1; j<=columna+1; j++){
			if(GetBomba(i, j))
				n_minas++;
		}
	}

	return n_minas;
}

void Tablero::AbrirCasilla(int fil, int col){

	if((fil>=0 && fil<filas_util && col>=0 && col<columnas_util) && !GetAbierta(fil, col) && !GetMarcada(fil, col)){
		datos[fil][col].abierta = true;
		
		if((JuntoAMina(fil, col)==0)){
			for(int i=fil-1; i<=fil+1; i++){
				for(int j=col-1; j<=col+1; j++){
					AbrirCasilla(i, j);
				}
			}
		}	
	}
}

/*--------------------------------------------------------------*/