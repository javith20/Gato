#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_posCeroCero_clicked()
{
    tablero.setPos(0,0);
    if(tablero.getJugador1Turno()){
        tablero.setPos(0,0,'X');
        QString ceroCero = "X";
        ui->posCeroCero->setText(ceroCero);
        tablero.setJugador1(false);
        tablero.setJugador2(true);
        //ui->posCeroCero->setDisabled();
    }
    else if(tablero.getJugador2Turno()){
        tablero.setPos(0,0,'O');
        QString ceroCero = "O";
        ui->posCeroCero->setText(ceroCero);
        tablero.setJugador2(false);
        tablero.setJugador1(true);
    }
}

void MainWindow::on_posCeroUno_clicked()
{
    if(tablero.getJugador1Turno()){
        tablero.setPos(0,1,'X');
        QString ceroUno = "X";
        ui->posCeroUno->setText(ceroUno);
        tablero.setJugador1(false);
        tablero.setJugador2(true);
    }
    else if(tablero.getJugador2Turno()){
        tablero.setPos(0,1,'O');
        QString ceroUno = "O";
        ui->posCeroUno->setText(ceroUno);
        tablero.setJugador1(true);
        tablero.setJugador2(false);
    }
}

void MainWindow::on_posCeroDos_clicked()
{
    if(tablero.getJugador1Turno()){
        tablero.setPos(0,2,'X');
        QString ceroDos = "X";
        ui->posCeroDos->setText(ceroDos);
        tablero.setJugador1(false);
        tablero.setJugador2(true);
    }
    else if(tablero.getJugador2Turno()){
        tablero.setPos(0,2,'O');
        QString ceroDos = "O";
        ui->posCeroDos->setText(ceroDos);
        tablero.setJugador1(true);
        tablero.setJugador2(false);
    }
}

void MainWindow::on_posUnoCero_clicked()
{
    if(tablero.getJugador1Turno()){
        tablero.setPos(1,0,'X');
        QString unoCero = "X";
        ui->posUnoCero->setText(unoCero);
        tablero.setJugador1(false);
        tablero.setJugador2(true);
    }
    else if(tablero.getJugador2Turno()){
        tablero.setPos(1,0,'O');
        QString unoCero = "O";
        ui->posUnoCero->setText(unoCero);
        tablero.setJugador1(true);
        tablero.setJugador2(false);
    }
}

void MainWindow::on_posUnoUno_clicked()
{
    if(tablero.getJugador1Turno()){
        tablero.setPos(1,1,'X');
        QString cerocero = "X";
        ui->posUnoUno->setText(cerocero);
        tablero.setJugador1(false);
        tablero.setJugador2(true);
    }
    else if(tablero.getJugador2Turno()){
        tablero.setPos(1,1,'O');
        QString cerocero = "O";
        ui->posUnoUno->setText(cerocero);
        tablero.setJugador1(true);
        tablero.setJugador2(false);
    }
}

void MainWindow::on_posUnoDos_clicked()
{
    tablero.setPos(1,2);
    if(tablero.getJugador1Turno()){
        tablero.setPos(1,2,'X');
        QString cerocero = "X";
        ui->posUnoDos->setText(cerocero);
        tablero.setJugador1(false);
        tablero.setJugador2(true);
    }
    else if(tablero.getJugador2Turno()){
        tablero.setPos(1,2,'O');
        QString cerocero = "O";
        ui->posUnoDos->setText(cerocero);
        tablero.setJugador1(true);
        tablero.setJugador2(false);
    }
}

void MainWindow::on_posDosCero_clicked()
{
    if(tablero.getJugador1Turno()){
        tablero.setPos(2,0,'X');
        QString cerocero = "X";
        ui->posDosCero->setText(cerocero);
        tablero.setJugador1(false);
        tablero.setJugador2(true);
    }
    else if(tablero.getJugador2Turno()){
        tablero.setPos(2,0,'O');
        QString cerocero = "O";
        ui->posDosCero->setText(cerocero);
        tablero.setJugador1(true);
        tablero.setJugador2(false);
    }
}

void MainWindow::on_posDosUno_clicked()
{
    if(tablero.getJugador1Turno()){
        tablero.setPos(2,1,'X');
        QString cerocero = "X";
        ui->posDosUno->setText(cerocero);
        tablero.setJugador1(false);
        tablero.setJugador2(true);
    }
    else if(tablero.getJugador2Turno()){
        tablero.setPos(2,1,'O');
        QString cerocero = "O";
        ui->posDosUno->setText(cerocero);
        tablero.setJugador1(true);
        tablero.setJugador2(false);
    }
}

void MainWindow::on_posDosDos_clicked()
{
    if(tablero.getJugador1Turno()){
        tablero.setPos(2,2,'X');
        QString cerocero = "X";
        ui->posDosDos->setText(cerocero);
        tablero.setJugador1(false);
        tablero.setJugador2(true);
    }
    else if(tablero.getJugador2Turno()){
        tablero.setPos(2,2,'O');
        QString cerocero = "O";
        ui->posDosDos->setText(cerocero);
        tablero.setJugador1(true);
        tablero.setJugador2(false);
    }
}

void MainWindow::on_iniciarButton_clicked()
{
    tablero.setJugador1(true); //Por default está escogiendo al jugador 1
    tablero.setJugador2(false);
    tablero.setJugador1Figura('X');
    tablero.setJugador2Figura('O');
}


void MainWindow::on_pushButton_clicked()
{
    if(tablero.getJugador1Turno()){
        if(tablero.isLlenoDiagonal(tablero.getJugador1()))  //'X' provicional
        {
            cout<<"Gana Diagonal"<<endl;
        }
        else if(tablero.isLlenoHorizontal(tablero.getJugador1()))
        {
            cout<<"Gana Horizontal"<<endl;
        }
        else if(tablero.isLlenoVertical(tablero.getJugador1()))
        {
            cout<<"Gana Vertical"<<endl;
        }
    }
    else if(tablero.getJugador2Turno()){
        if(tablero.isLlenoDiagonal(tablero.getJugador2()))  //'X' provicional
        {
            cout<<"Gana Diagonal"<<endl;
        }
        else if(tablero.isLlenoHorizontal(tablero.getJugador2()))
        {
            cout<<"Gana Horizontal"<<endl;
        }
        else if(tablero.isLlenoVertical(tablero.getJugador2()))
        {
            cout<<"Gana Vertical"<<endl;
        }
    }

}

void MainWindow::on_radioButton_clicked()
{
    if(!tablero.getVsCPU()){
        tablero.setVsCPU(true);
    }
    else{
        tablero.setVsCPU(false);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    //QString X = 'X';
    //QString O = 'O';
    tablero.movimientoComputador(tablero.getJugador2());
    int pos1 = tablero.getMovimientoComputador(0);
    int pos2 = tablero.getMovimientoComputador(1);
    if(pos1 == 0 && pos2 == 0)
        on_posCeroCero_clicked();
    else if(pos1 == 0 && pos2 == 1)
        on_posCeroUno_clicked();
    else if(pos1 == 0 && pos2 == 2)
        on_posCeroDos_clicked();
    else if(pos1 == 1 && pos2 == 0)
        on_posUnoCero_clicked();
    else if(pos1 == 1 && pos2 == 1)
        on_posUnoUno_clicked();
    else if(pos1 == 1 && pos2 == 2)
        on_posUnoDos_clicked();
    else if(pos1 == 2 && pos2 == 0)
        on_posDosCero_clicked();
    else if(pos1 == 2 && pos2 == 1)
        on_posDosUno_clicked();
    else if(pos1 == 2 && pos2 == 2)
        on_posDosDos_clicked();

    //tablero.setPos(pos1,pos2,tablero.getJugador2());
}
