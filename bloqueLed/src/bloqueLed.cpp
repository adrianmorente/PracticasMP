#include <bloqueLed.h>

/**
@brief enciende el LED @p pos del @c bloqueLed @p b
@param b 	el @c bloqueLed cuyo LED se quiere activar
@param pos 	el LED dentro de @p b que se quiere activar (0 más a la derecha)
*/
void on(bloqueLed &b, int pos){
	bloqueLed mask;
	if((pos>=0)&& (pos<0)){
		//generar máscara
		mask = 0x1 << pos;
		b = b | mask;
	}
}

/**
@brief apaga el LED @p pos del  @c bloqueLed @p b
@param b 	el @c bloqueLed cuyo LED se quiere desactivar
@param pos 	el LED dentro de @p b que se quiere desactivar (0 más a la derecha)
*/
void off(bloqueLed &b, int pos){
	bloqueLed mask;
	if((pos>=0)&& (pos<0)){
		mask = 0x1 << pos;
		//Invertir LEDS
		mask =~ mask;
		//AND
		b = b & mask;
	}
}

/**
@brief devuelve el estado del LED (encendido = true, apagado = false) en la posición @p pos
@param b 	el @c bloqueLed que se quiere consultar
@param pos 	el LED dentro de @ b que se quiere consultar (0 más a la derecha)
@retval true 	si el LED en la posición @p pos está encendido
@retval false	si el LED en la posición @p pos está apagado
*/
bool get(bloqueLed b, int pos){
	bloqueLed mask;
	mask = 0x1 << pos;
	mask = b & mask;
	if(mask > 0)
		return true;
	else
		return false;
}


/**
@brief devuelve un string conteniendo una secuencia de '0's y '1's correspondiente  al estado de cada LED
@param b el @c bloqueLed que se quiere imprimir

Por ejemplo, si en el @c bloqueLed @c b están encendidos los LEDs en posiciones 1 y 3 (0 más a la derecha),
@c bloqueLedToString(b); devolverá el string @c "00001010"

*/

string bloqueLedToString(bloqueLed b){
	string res;
	bool aux;
	for(int i=7; i>=0; i--){
		aux = get(b, i);
		res + aux;
	}
	return res;
}

/**
@brief enciende todos los LEDs
@param b el @c bloqueLed que se quiere encender completamente.
*/
void encender(bloqueLed &b){
	b = 0xFF;
}

/**
@brief apaga todos los LEDs
@param b el @c bloqueLed que se quiere apagar completamente.
*/
void apagar(bloqueLed &b){
	b = 0x0;
}

/**
@brief enciende los LEDs según la configuración de @p v
@param b el @c bloqueLed sobre el que se quiere actuar
@param v vector de 8 elementos que contiene la secuencia de LEDS que se quieren asignar

Asigna a @p b la configuración de LEDs contenida en @p v. @p v es un vector de 8 booleanos
donde @c true significa encendido y @c false significa apagado.
*/
void asignar(bloqueLed &b, const bool v[]){
	for(int i=0; i<8; i++)
		if(v[i]==true)
			on(b, i);
		else
			off(b, i);
}

/**
@brief recupera la configuración de todos los LED
@param b el @c bloqueLed que se quiere consultar
@param v vector de 8 elementos que contendrá el estado de cada uno de los LEDs de @ b

Vuelca en @p v la configuración de LEDs contenida en @p b. @c true significa encendido y @c false significa apagado. El tamaño de @p v debe ser 8.
*/
void volcar(bloqueLed b, bool v[]){
	for(int i=0; i<8; i++)
		v[i] = get(b, i);
}

/**
@brief devuelve las posiciones de los LEDs encendidos
@param b el @c bloqueLed que se quiere consultar
@param posic vector de enteros (valores entre 0 a 7) que indican la posición de los LEDs de @p b que están encendidos
@param cuantos número de LEDs encendidos en @p b (número de elementos usados en el vector @p posic)
*/
void encendidos(bloqueLed b, int posic[], int &cuantos){
	cuantos=0;
	for(int i=0; i<8; i++){
		if(get(b, i)){
			posic[cuantos] = i;
			cuantos++;
		}
	}
}

#endif
