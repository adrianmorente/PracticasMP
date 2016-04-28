#include <string>
#include <fstream>
#include "lista.h"

using namespace std;

Lista::Lista(){
    cabecera = 0;
}

Lista::Lista(string valor){
    cabecera = new Celda;
    cabecera->datos = valor;
    cabecera->siguiente = 0;
}


void Lista::destruir(){
    if(cabecera!=0){
        Celda *siguiente_celda = cabecera->siguiente;
        while(siguiente_celda!=0){
            Celda *a_borrar = siguiente_celda->siguiente;
            delete siguiente_celda;
            siguiente_celda=a_borrar;
        }
        delete cabecera;
        cabecera->siguiente=0;
    }
}

void Lista::insertar(string valor){
    Celda *nueva = new Celda;
    nueva->datos = valor;
    nueva->siguiente = 0;
    Celda *aux = new Celda;
    aux = cabecera->siguiente;
    while(aux!=0)
        aux = aux->siguiente;
    //estoy al final: inserto
    aux->siguiente = nueva;
}

string Lista::getCelda(int pos) const{
    Celda *aux = cabecera;
    int i=0;
    while(i < pos){
        i++;
        aux = aux->siguiente;
    }
    return aux->datos;
}

int Lista::longitud() const{
    Celda *aux = cabecera;
    int i=1;
    while(aux != 0){
        i++;
        aux = aux->siguiente;
    }
    return i;
}

/**
 * @brief Construye una lista de celdas enlazadas a partir de la informacion
 * contenida en un fichero.
 * @param nombreFichero ruta del fichero de texto con el contenido de las datos
 * a insertar en la lista
 * @retval true si ha tenido éxito en la lectura y el formato es el correcto
 * @retval false si se ha producido algún error en la lectura
 *
 * Lee desde disco los elementos almacenados en @a nombreFichero y los guarda
 * en la lista. La función debe asegurarse de que la estructura sigue un patron
 * determinado, y se ha de crear la lista con el numero de elementos que contenga.
 */
bool Lista::leerLista(const char nombrefichero[]){
    destruir();
    ifstream fin;
	fin.open(nombrefichero);
	if(!fin){
		return false;
	}else{
		string grises;
		int lineas;
		getline(fin,grises); //la primera linea se ignora
		fin >> lineas; //leo el numero de datos de grises
		getline(fin,grises); //leer salto de linea
		if (!fin){
			return false;
		}else {
			int i = 0;
			getline(fin,grises); //leer cadena de caracteres
			while ((i < lineas)&&(fin)){
				if (grises != ""){
					insertar(grises);
					i++;
				}
				getline(fin,grises); //leer cadena de caracteres
			}
            // if(i!=lineas){
            //     destruir();
            //     return false;
            // }
		}
		fin.close();
	}
	return true;
}
