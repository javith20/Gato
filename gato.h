#ifndef GATO_H
#define GATO_H
#include<iostream>

class Gato
{

    struct jugador{
        bool turno;
        char simbolo;
    }jugador1, jugador2;

public:
    Gato();
    int revisarGanador();
    int minimax( int player);
    int computadoraMueve();
    char getPos();
    void setPos(int pos, int figura);
    char getJugador1();
    char getJugador2();
    char getJugador1Turno();
    char getJugador2Turno();
    void setJugador1(bool enTurno);
    void setJugador2(bool enTurno);
    void setJugador1Figura(char figura);
    void setJugador2Figura(char figura);
    bool getVsCPU();
    void setVsCPU(bool estado);


private:
    int movimientoPC[2]={0,0};
    int tablero[9]={0};
    bool VsCPU = false;
};


#endif // GATO_H
