


typedef unsigned char bloqueLed ;
// enciende el led pos del bloqueLed b
void on(bloqueLed &b, int pos);
// apaga el led pos del bloqueLed b
void off(bloqueLed &b, int pos);
// devuelve el estado del LED pos //(encendido = true, apagado = false)
bool get(bloqueLed b, int pos) ; / / enciende todos los leds
void encender(bloqueLed &b) ; / / apaga todos los leds
void apagar(bloqueLed &b) ;
//enciende los leds segu ́n la configuracion de v. // el taman ́o de v debe ser 8
void asignar ( bloqueLed &b , const bool v [ ] ) ; //asigna en v el estado de cada LED
void volcar(bloqueLed b, bool v[]) ;
// devuelve en posic un vector con las posiciones
// de los leds que esta ́n encendidos.
// En cuantos se devuelve el nu ́mero de leds encendidos //(nu ́mero de elementos ocupados en el vector posic).
void encendidos(bloqueLed b, int posic [] , int &cuantos) ;
// devuelve un string con una secuencia de 0’s y 1’s // correspondiente al estado de cada LED. Se debe
// implementar utilizando la funcio ́n ”get”
string bloqueLedToString(bloqueLed b) ;