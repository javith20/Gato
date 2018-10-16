#ifndef GATO_H
#define GATO_H
#include<iostream>

class Gato
{
public:
    Gato();
    void setPos(int fila,int columna);
    bool isLlenoHorizontal();
    bool isLlenoVertical();
    bool isLlenoDiagonal();
    int  getJugador1();
    int  getJugador2();
    void setJugador1(bool enTurno);
    void setJugador2(bool enTurno);

private:
    int Matriz[3][3]={{0,0,0},{0,0,0},{0,0,0}};
    bool jugador1;
    bool jugador2;
};


#endif // GATO_H
