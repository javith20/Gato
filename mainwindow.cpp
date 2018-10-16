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
    if(tablero.getJugador1()){
        QString ceroCero = "X";
        ui->posCeroCero->setText(ceroCero);
        tablero.setJugador1(false);
        tablero.setJugador2(true);
    }
    else if(tablero.getJugador2()){
        QString ceroCero = "O";
        ui->posCeroCero->setText(ceroCero);
        tablero.setJugador2(false);
        tablero.setJugador1(true);
    }
}

void MainWindow::on_posCeroUno_clicked()
{
    tablero.setPos(0,1);
    if(tablero.getJugador1()){
        QString ceroUno = "X";
        ui->posCeroUno->setText(ceroUno);
        tablero.setJugador1(false);
        tablero.setJugador2(true);
    }
    else if(tablero.getJugador2()){
        QString ceroUno = "O";
        ui->posCeroUno->setText(ceroUno);
        tablero.setJugador1(true);
        tablero.setJugador2(false);
    }
}

void MainWindow::on_posCeroDos_clicked()
{
    tablero.setPos(0,1);
    if(tablero.getJugador1()){
        QString ceroDos = "X";
        ui->posCeroDos->setText(ceroDos);
        tablero.setJugador1(false);
        tablero.setJugador2(true);
    }
    else if(tablero.getJugador2()){
        QString ceroDos = "O";
        ui->posCeroDos->setText(ceroDos);
        tablero.setJugador1(true);
        tablero.setJugador2(false);
    }
}

void MainWindow::on_posUnoCero_clicked()
{
    tablero.setPos(1,0);
    if(tablero.getJugador1()){
        QString unoCero = "X";
        ui->posUnoCero->setText(unoCero);
        tablero.setJugador1(false);
        tablero.setJugador2(true);
    }
    else if(tablero.getJugador2()){
        QString unoCero = "O";
        ui->posUnoCero->setText(unoCero);
        tablero.setJugador1(true);
        tablero.setJugador2(false);
    }
}

void MainWindow::on_posUnoUno_clicked()
{
    tablero.setPos(1,1);
    if(tablero.getJugador1()){
        QString cerocero = "X";
        ui->posUnoUno->setText(cerocero);
        tablero.setJugador1(false);
        tablero.setJugador2(true);
    }
    else if(tablero.getJugador2()){
        QString cerocero = "O";
        ui->posUnoUno->setText(cerocero);
        tablero.setJugador1(true);
        tablero.setJugador2(false);
    }
}

void MainWindow::on_posUnoDos_clicked()
{
    tablero.setPos(1,2);
    if(tablero.getJugador1()){
        QString cerocero = "X";
        ui->posUnoDos->setText(cerocero);
        tablero.setJugador1(false);
        tablero.setJugador2(true);
    }
    else if(tablero.getJugador2()){
        QString cerocero = "O";
        ui->posUnoDos->setText(cerocero);
        tablero.setJugador1(true);
        tablero.setJugador2(false);
    }
}

void MainWindow::on_posDosCero_clicked()
{
    tablero.setPos(2,0);
    if(tablero.getJugador1()){
        QString cerocero = "X";
        ui->posDosCero->setText(cerocero);
        tablero.setJugador1(false);
        tablero.setJugador2(true);
    }
    else if(tablero.getJugador2()){
        QString cerocero = "O";
        ui->posDosCero->setText(cerocero);
        tablero.setJugador1(true);
        tablero.setJugador2(false);
    }
}

void MainWindow::on_posDosUno_clicked()
{
    tablero.setPos(2,1);
    if(tablero.getJugador1()){
        QString cerocero = "X";
        ui->posDosUno->setText(cerocero);
        tablero.setJugador1(false);
        tablero.setJugador2(true);
    }
    else if(tablero.getJugador2()){
        QString cerocero = "O";
        ui->posDosUno->setText(cerocero);
        tablero.setJugador1(true);
        tablero.setJugador2(false);
    }
}

void MainWindow::on_posDosDos_clicked()
{
    tablero.setPos(2,2);
    if(tablero.getJugador1()){
        QString cerocero = "X";
        ui->posDosDos->setText(cerocero);
        tablero.setJugador1(false);
        tablero.setJugador2(true);
    }
    else if(tablero.getJugador2()){
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
}


void MainWindow::on_pushButton_clicked()
{
    if(tablero.isLlenoDiagonal())
    {
        cout<<"Ganó Diagonal"<<endl;
    }

}
