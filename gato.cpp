#include "gato.h"

using namespace  std;

static const int INFINITY = 1000000;

Gato::Gato()
{

}

int Gato::minimax(int board[3][3], int player, char figura) {

    int ganador = revisarGanador(figura); //'X'provicional
    if(ganador != 0)
        return ganador*player;
    int movimiento = 0;
    int puntuacion = -1;//Movimientos donde se pierde, es mejor no mover :p
    int i,j;
    for(i = 0; i < 3; ++i) {       //Para los movimientos
        for(j = 0; j < 3; ++j){
            if(board[i][j] == 0) {     //Si está vacío
                board[i][j] = 1;  //Intenta el movimiento
                int thisPuntuacion = -(minimax(board, player*-1,figura));
                if(thisPuntuacion > puntuacion) {
                    puntuacion = thisPuntuacion;
                    movimiento = i;
                }//Escoger la peor opción para el contrincante
                board[i][j] = 0;//Resetea el tablero después de intentar
            }
        }
    }
    if(movimiento == -1) return 0;
    return puntuacion;
}

int Gato::minimax2(int depth, bool isMax, char figura)
{
    char opponent;
    char player;
    int score = evaluarGanarCompleto(figura);  //Evaluate evalúa si alguien ya ganó o va ganando y retorna un valor depende a esto
    if(figura == 'X'){
        player = 'X';
        opponent = 'O';
    }
    else{
        player = 'O';
        opponent = 'X';
    }
    // If Maximizer has won the game return his/her
    // evaluated score
    if (score == 10)
        return score;

    // If Minimizer has won the game return his/her
    // evaluated score
    if (score == -10)
        return score;

    // If there are no more moves and no winner then
    // it is a tie
    if (quedanMovimientos()==false)   //Revisa si quedan movimientos
        return 0;

    // If this maximizer's move
    if (isMax)
    {
        int best = -1000;

        // Traverse all cells
        for (int i = 0; i<3; i++)
        {
            for (int j = 0; j<3; j++)
            {
                // Check if cell is empty
                if (getPos(i,j) == 0)
                {
                    // Make the move
                    setPos(i,j,player);

                    // Call minimax recursively and choose
                    // the maximum value
                    best = max( best,
                        minimax2(depth+1, !isMax,figura) );

                    // Undo the move
                    setPos(i,j,0);
                }
            }
        }
        return best;
    }

    // If this minimizer's move
    else
    {
        int best = 1000;

        // Traverse all cells
        for (int i = 0; i<3; i++)
        {
            for (int j = 0; j<3; j++)
            {
                // Check if cell is empty
                if (getPos(i,j)==0)
                {
                    // Make the move
                    setPos(i,j,opponent); //Opponent y player es el X o el O del contrincante

                    // Call minimax recursively and choose
                    // the minimum value
                    best = min(best,
                           minimax2(depth+1, !isMax, figura));

                    // Undo the move
                    setPos(i,j,0);
                }
            }
        }
        return best;
    }
}

void Gato::movimientoComputador(char figura) {
    int movimiento = 0;
    int movimiento2 = 0;
    int puntuacion = -1;
    int i,j;
    for(i = 0; i < 3; ++i) {
        for(j = 0; j < 3; ++j){
            if(this->Matriz[i][j] == 0) {
                this->Matriz[i][j] = 1;
                int tempPuntuacion = minimax(Matriz, 1, figura);
                this->Matriz[i][j] = 0;
                if(tempPuntuacion > puntuacion) {
                    puntuacion = tempPuntuacion;
                    movimiento = i;
                    movimiento2 = j;
                }
            }
        }

    }
    //Retorna el movimiento basado en el árbol minimax a un nodo
    //this->Matriz[movimiento][movimiento2] = 1;
    setMovimientoComputador(0, movimiento);
    setMovimientoComputador(1, movimiento2);
}

void Gato::setMovimientoComputador(int pos, int movimiento){
    movimientoPC[pos] = movimiento;
}

int Gato::getMovimientoComputador(int pos){
    return this->movimientoPC[pos];
}

void Gato::setPos(int fila,int columna){
    if (Matriz[fila][columna] == 0)
        this->Matriz[fila][columna] = 1;
}

void Gato::setPos(int fila,int columna, char figura){
    if (Matriz[fila][columna] == 0 || figura == 'X'){
        this->Matriz[fila][columna] = 1;
        this->MatrizSimbolos[fila][columna] = figura;
    }
    else if(Matriz[fila][columna] == 0 || figura == 'O'){
        this->Matriz[fila][columna] = 1;
        this->MatrizSimbolos[fila][columna] = figura;
    }
    else if(Matriz[fila][columna] == 1 && figura == 0){
        this->Matriz[fila][columna] = 0;
        this->MatrizSimbolos[fila][columna] = 0;
    }
}

int Gato::getPos(int fila,int columna){
    return this->Matriz[fila][columna];
}

char Gato::getPosFigura(int fila,int columna){
    return this->MatrizSimbolos[fila][columna];
}

char Gato::getJugador1(){
    return this->jugador1.simbolo;
}

char Gato::getJugador2(){
    return this->jugador2.simbolo;
}

char Gato::getJugador1Turno(){
    return this->jugador1.turno;
}

char Gato::getJugador2Turno(){
    return this->jugador2.turno;
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

int Gato::revisarGanador(char figura)
{
    int i,j;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            if(isLlenoDiagonal(figura))
            {
                return 1;
            }
            else if(isLlenoHorizontal(figura))
            {
                return 1;
            }
            else if(isLlenoVertical(figura))
            {
                return 1;
            }
            return 0;
    }   }
    return 0;
}

bool Gato::quedanMovimientos(){
    int contador = 1;
    for(int fila = 0; fila < 3; fila++)
    {
        for(int columna=0;columna < 3; columna++)
            if (getPos(fila, columna) == 1)
            {
                contador++;
            }
    }
    if( contador == 9 )
        return true;
    else{
        return false;
    }

}

bool Gato::isLlenoHorizontal(char figura){
    int cont = 0;
    for(int fila = 0; fila < 3; fila++)
    {
        cont=0;
        for(int columna=0;columna < 3; columna++)
            if (getPos(fila, columna) == 1 && getPosFigura(fila,columna) == figura)
            {
                cont++;
                if( cont == 3 )
                    return true;
            }
    }

    return false;
}

bool Gato::isLlenoVertical(char figura){
    int cont = 0;
    for(int columna = 0; columna < 3; columna++)
    {
        cont=0;
        for(int fila=0;fila < 3; fila++)
            if (getPos(fila, columna) == 1 && getPosFigura(fila,columna) == figura)
            {
                cont++;
                if( cont == 3 )
                    return true;
            }
    }

    return false;
}

bool Gato::isLlenoDiagonal(char figura)
{
    cout<<"figura:"<<figura<<endl;
    cout<<getPosFigura(0,0)<<getPosFigura(0,1)<<getPosFigura(0,2)<<endl;
    cout<<getPosFigura(1,0)<<getPosFigura(1,1)<<getPosFigura(1,2)<<endl;
    cout<<getPosFigura(2,0)<<getPosFigura(2,1)<<getPosFigura(2,2)<<endl;
    if(getPos(1, 1) == 1 && getPosFigura(1,1) == figura)
    {
        if(getPos(0, 0) == 1 && getPosFigura(0,0) == figura)
        {
            if(getPos(2, 2) == 1 && getPosFigura(2,2) == figura)
                return true;
        }
        else if(getPos(0, 2) == 1 && getPosFigura(1,2) == figura)
        {
            if(getPos(2, 0) == 1 && getPosFigura(2,0) == figura)
                 return true;
        }
    }
    return false;
}

int Gato::evaluarGanarCompleto(char figura){
        //Horizontal
    bool pierde = false;
    int cont = 0;
    for(int fila = 0; fila < 3; fila++)
    {
        cont=0;
        for(int columna=0;columna < 3; columna++)
            if (getPos(fila, columna) == 1 && getPosFigura(fila,columna) == figura)
            {
                cont++;
                if( cont == 3 )
                    return +10;
            }
    }
    if(pierde)
        return -10;

        //Vertical
    for(int columna = 0; columna < 3; columna++)
    {
        cont=0;
        for(int fila=0;fila < 3; fila++)
            if (getPos(fila, columna) == 1 && getPosFigura(fila,columna) == figura)
            {
                cont++;
                if( cont == 3 )
                    return +10;
            }
    }

    if(pierde)
        return -10;

     //Diagonal
    if(getPos(1, 1) == 1 && getPosFigura(1,1) == figura)
    {
        if(getPos(0, 0) == 1 && getPosFigura(0,0) == figura)
        {
            if(getPos(2, 2) == 1 && getPosFigura(2,2) == figura)
                return +10;
        }
        else if(getPos(0, 2) == 1 && getPosFigura(1,2) == figura)
        {
            if(getPos(2, 0) == 1 && getPosFigura(2,0) == figura)
                 return +10;
        }
    }
    if(pierde)
        return -10;
    return 0;
}

void Gato::comenzarJuego(){
    int turno;
    for(turno = 0 ;; turno++)
    {
        //movimientoComputador();
    }
}
