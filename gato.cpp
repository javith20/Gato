#include "gato.h"

Gato::Gato()
{

}
void Gato::setPos(int fila,int columna){
    if (Matriz[fila][columna] == 0)
        Matriz[fila][columna] = 1;
}


int Gato::getJugador1(){
    return this->jugador1;
}

int Gato::getJugador2(){
    return this->jugador2;
}

void Gato::setJugador1(bool enTurno){
    this->jugador1 = enTurno;
}

void Gato::setJugador2(bool enTurno){
    this->jugador2 = enTurno;
}

bool Gato::isLlenoHorizontal(){
    int cont = 0;
    for(int fila = 0; fila < 3; fila++)
    {
        cont=0;
        for(int columna=0;columna < 3; columna++)
            if (this->Matriz[fila][columna] == 1)
            {
                cont++;
                if( cont == 3 )
                    return true;
            }
    }

    return false;
}

bool Gato::isLlenoVertical(){
    int cont = 0;
    for(int columna = 0; columna < 3; columna++)
    {
        cont=0;
        for(int fila=0;fila < 3; fila++)
            if (this->Matriz[fila][columna] == 1)
            {
                cont++;
                if( cont == 3 )
                    return true;
            }
    }

    return false;
}

bool Gato::isLlenoDiagonal()
{
    int cont = 0;
    if(this->Matriz[1][1] == 1)
    {
        cont++;
        if(this->Matriz[0][0] == 1)
            cont++;
        if(this->Matriz[2][2] == 1)
            cont++;
        if( cont == 3 )
            return true;
        }
    cont=0;
    if(this->Matriz[0][2] == 1)
    {
            cont++;
        if(this->Matriz[2][2] == 1)
            cont++;
        if(this->Matriz[2][0] == 1)
            cont++;
        if( cont == 3 )
            return true;
    }
    else
    {
        return false;
    }
}
