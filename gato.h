#ifndef GATO_H
#define GATO_H


class Gato
{
public:
    Gato();
    void setPos(int fila,int columna);
    bool isLlenoHorizontal();
    bool isLlenoVertical();
    bool isLlenoDiagonal();
private:
    int Matriz[3][3]={{1,0,1},{1,1,0},{1,0,0}};
};


#endif // GATO_H
