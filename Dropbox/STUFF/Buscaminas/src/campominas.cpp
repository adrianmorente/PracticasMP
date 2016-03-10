#include "tablero.h"
#include "campominas.h"
using namespace std;

/*--------------------------------------------------------------*/

inline int GetRandom(int minimo, int maximo){
	minimo--;
	maximo--;
	double u01 = rand()/(RAND_MAX+1.0);
	return minimo+(maximo-minimo+1)*u01;
}

/*--------------------------------------------------------------*/

Campominas::Campominas(int fila1, int columna1, int nminas){
	juego.Inicializar(fila1, columna1);

	int i=0;
	while(i < nminas){
		int pos_x, pos_y;
		pos_x = GetRandom(0, juego.ConsultaFilas());
		pos_y = GetRandom(0, juego.ConsultaColumnas());
		if(!juego.GetBomba(pos_x, pos_y)){
			juego.SetBomba(pos_x, pos_y);
			i++;
		}
	}	
	minas = nminas;
	estado=true;
}

bool Campominas::Estado(){
	return estado;
}

bool Campominas::CheckVictoria(){
	bool victoria = true;
	for(int i=0; i<juego.ConsultaFilas(); i++){
		for(int j=0; j<juego.ConsultaColumnas(); j++){
			if(juego.GetAbierta(i, j) && juego.GetBomba(i, j)){
				victoria=false;
			}
		}
	}

	for(int i=0; i<juego.ConsultaFilas(); i++){
		for(int j=0; j<juego.ConsultaColumnas() && victoria==true; j++){
			if(!juego.GetAbierta(i, j) && !juego.GetBomba(i, j))
				victoria=false;
		}
	}

	return victoria;
}

void Campominas::PrettyPrint(){
		
	system("clear");
	cout << "  ";
	for(int i=0; i<juego.ConsultaColumnas(); i++)
		cout << "   " << i;
	cout << "\n\n";	

	for(int i=0; i<juego.ConsultaFilas(); i++){
		cout << i << "  |";
		for(int j=0; j<juego.ConsultaColumnas(); j++){
			if(juego.GetAbierta(i, j)){			// CASILLA ABIERTA
				if(juego.GetBomba(i, j))			// ABIERTA Y CON BOMBA
					cout << " X |";
				else if(!juego.GetBomba(i, j) && juego.JuntoAMina(i, j)==0)	// ABIERTA Y SIN BOMBA
					cout << "   |";
				else if(!juego.GetBomba(i, j) && juego.JuntoAMina(i, j)>0)	// ABIERTA, CON BOMBA ALREDEDOR
					cout << " " << juego.JuntoAMina(i, j) << " |";
			}
			else if(!juego.GetAbierta(i, j)){		// CASILLA CERRADA
				if(juego.GetMarcada(i, j))			// CERRADA Y MARCADA
					cout << " $ |";
				else if(!juego.GetMarcada(i, j))	// CERRADA Y SIN MARCAR
					cout << " * |";
			}
		}
		cout << "\n";
	}
}

void Campominas::Imprimir(){
	for(int i=0; i<juego.ConsultaColumnas(); i++)
		cout << "   " << i;
	cout << "\n\n";

	for(int i=0; i<juego.ConsultaFilas(); i++){
		cout << i << "  |";
		for(int j=0; j<juego.ConsultaColumnas(); j++){
			if(juego.GetBomba(i, j))
				cout << " X |";
			else
				cout << "   |";
		}
		cout << "\n";
	}
}

void Campominas::Menu(){
	char opcion;
	int fil, col;
		
	while(opcion!='a' && opcion!='m' && opcion!='r' && opcion!='s'){
		cout << "\n\nElige tu accion (y di posicion si es necesaria): "
		 << "\n\n\t[a] AbrirCasilla: fila columna"
		 << "\n\t[m] MarcarCasilla: fila columna"
		 << "\n\t[r] MostrarJuegoResuelto:"
		 << "\n\t[s] -- Abandonar juego --\n\n--> ";

		cin >> opcion;
		if(opcion=='a' || opcion=='m'){
			cin >> fil;
			cin >> col;

			while(fil>juego.ConsultaFilas() || col>juego.ConsultaColumnas()){
				cout << "Introduce dimensiones (fila columna) correctas: ";
				cin >> fil;
				cin >> col;
			}
		}
	}

	if(opcion=='a' || opcion=='A'){
		juego.AbrirCasilla(fil, col);
		PrettyPrint();
		if(juego.GetBomba(fil, col)==true){
			cout << "\nUNA MINA. Has perdido...\n\n";
			estado=false;
			cout << "JUEGO RESUELTO: \n\n";
			Imprimir();
			cout << "\n\n";
		}
	}
	else if(opcion=='m' || opcion=='M')
		juego.SetMarcada(fil,col);

	else if(opcion=='r' || opcion=='R'){
		char stop;
		if(estado==true)
			cout << "EL JUEGO NO HA TERMINADO. NO HAGAS TRAMPAS..."
				 << "\n¿Seguro que quieres imprimir el tablero y finalizar el juego? [S]; ";
			cin >> stop;
		if(stop=='S' || stop=='s'){
			Imprimir();
			estado=false;
		}
	}

	else if(opcion=='s' || opcion=='S'){
		estado=false;
		cout << "Juego detenido sin finalizar... \n";
	}

	else
		cout << "Opción incorrecta... \n";
}

/*--------------------------------------------------------------*/