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
    int minimax(int board[3][3], int player,char figura);
    void setPos(int fila,int columna);
    void setPos(int fila,int columna, char figura);
    int getPos(int fila,int columna);
    char getPosFigura(int fila,int columna);
    bool isLlenoHorizontal(char figura);
    bool isLlenoVertical(char figura);
    bool isLlenoDiagonal(char figura);
    int getMovimientoComputador(int pos);
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
    int revisarGanador(char figura);
    void movimientoComputador(char figura);
    void comenzarJuego();

private:
    int Matriz[3][3]={{0,0,0},{0,0,0},{0,0,0}};
    char MatrizSimbolos[3][3]={{'0','0','0'},{'0','0','0'},{'0','0','0'}};
    int movimientoPC[2]={0,0};
    bool VsCPU = false;
};


#endif // GATO_H
