#include "gato.h"

Gato::Gato()
{

}
void Gato::setPos(int fila,int columna){
    if (Matriz[fila][columna] ==0)
        Matriz[fila][columna] = 1;
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

bool Gato::isLlenoVertical(){
    int cont = 0;
    if(this->Matriz[1][1] == 1){
        cont++;
        if(this->Matriz[0][0] == 1)
            cont++;
        if(this->Matriz[2][2] == 1)
            cont++;
        if( cont == 3 )
            return true;
        }
       cont=1;
       if(this->Matriz[0][2] == 1)
           cont++;
       if(this->Matriz[2][2] == 1)
           cont++;

    }

}
