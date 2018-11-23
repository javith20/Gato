#include "gato.h"
using namespace  std;

//Código fuertemente influenciado, algoritmo minimax extraído y modificado de: https://gist.github.com/amul-mehta/9ad947f41067cdbe2556

Gato::Gato()
{

}

int Gato::revisarGanador()
{
    unsigned gana[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    int contadorEspaciosLlenos = 0, i;
    for(i = 0; i < 8; ++i)
        if(tablero[gana[i][0]] != 0 && tablero[gana[i][0]] == tablero[gana[i][1]] && tablero[gana[i][1]] == tablero[gana[i][2]])
            return tablero[gana[i][2]];
        if(tablero[i] != 0)
            contadorEspaciosLlenos++;
    if(contadorEspaciosLlenos == 9)
        return 2;  //Se retorna 2 si hay empate
    return 0;  //Se retorna 0 si no ha ganado nadie
}

int Gato::minimax( int player)
{
    int ganador = revisarGanador();
    if(ganador != 0)
        return ganador*player;
    int movimiento = -1;
    int puntaje = -2;

    for(int i = 0; i < 9; i++) {
        if(tablero[i] == 0) {
            tablero[i] = player;
            int estePuntaje = -minimax(player*-1);
            if(estePuntaje > puntaje) {
                puntaje = estePuntaje;
                movimiento = i;
            }
            //Se reinicia el vector, para que no quede el movimiento de prueba colocado
            tablero[i] = 0;
        }
    }
    if(movimiento == -1)
        return 0;
    return puntaje;
}

int Gato::computadoraMueve() {
    int movimiento = -1;
    int puntaje = -2;    //Con afan de que si se da un puntaje menor, el movimiento no vale la pena
    for(int i = 0; i < 9; ++i) {
        if(tablero[i] == 0) {
            tablero[i] = 1;
            int puntajeTemporal = -minimax(-1);   //Se recorre el árbol de posibilidades con el algoritmo minimax
            tablero[i] = 0;
            if(puntajeTemporal > puntaje) {
                puntaje = puntajeTemporal;
                movimiento = i;
            }
        }
    }
    return movimiento;   //Al recorrer todo el árbol minimax, logramos devolver un movimiento basado en los puntajes
}

void Gato::limpiarTablero(){
    int tableroLimpio[9] = {0};
    tablero[9] = tableroLimpio[9];
}

char Gato::getPos(){
    return 'c';
}

void Gato::setPos(int pos, int figura){
    this->tablero[pos] = figura;
}

char Gato::getJugador1(){
    return this->jugador1.simbolo;
}

char Gato::getJugador2(){
    return this->jugador2.simbolo;
}

bool Gato::getJugador1Turno(){
    return this->jugador1.turno;
}

bool Gato::getJugador2Turno(){
    return this->jugador2.turno;
}

bool Gato::getJugador1VsMaquinaSeleccionado(){
    return this->jugador1VsMaquinaSeleccionado;
}

void Gato::setJugador1VsMaquinaSeleccionado(bool estado){
    this->jugador1VsMaquinaSeleccionado = estado;
}

bool Gato::getJugador2VsMaquinaSeleccionado(){
    return this->jugador2VsMaquinaSeleccionado;
}

void Gato::setJugador2VsMaquinaSeleccionado(bool estado){
    this->jugador2VsMaquinaSeleccionado = estado;
}

char Gato::getJugadorEnTurnoAnterior(){
    if(!this->jugador1.turno)
        return this->jugador1.simbolo;
    return this->jugador2.simbolo;

}


void Gato::setJugador1(bool enTurno){
    this->jugador1.turno = enTurno;
}

void Gato::setJugador2(bool enTurno){
    this->jugador2.turno = enTurno;
}

void Gato::setJugador1Figura(char figura){
    this->jugador1.simbolo = figura;
}

void Gato::setJugador2Figura(char figura){
    this->jugador2.simbolo = figura;
}

bool Gato::getVsCPU(){
    return this->VsCPU;
}

void Gato::setVsCPU(bool estado){
    this->VsCPU = estado;
}

bool Gato::getTurnoDeLaPC(){
    return this->turnoCPU;
}

void Gato::setTurnoDeLaPC(bool estado){
    this->turnoCPU = estado;
}

