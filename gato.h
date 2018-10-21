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

    bool getJugador1Turno();
    bool getJugador2Turno();

    bool getJugador1VsMaquinaSeleccionado();
    bool setJugador1VsMaquinaSeleccionado(bool estado);

    bool getJugador2VsMaquinaSeleccionado();
    bool setJugador2VsMaquinaSeleccionado(bool estado);

    char getJugadorEnTurnoAnterior();

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
    bool jugador1VsMaquinaSeleccionado = false;
    bool jugador2VsMaquinaSeleccionado = false;
};


#endif // GATO_H
