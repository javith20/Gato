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
    if(tablero.getJugador1Turno()){
        tablero.setPos(0,-1);
        QString ceroCero = "X";
        ui->posCeroCero->setText(ceroCero);
        tablero.setJugador1(false);
        tablero.setJugador2(true);
        //ui->posCeroCero->setDisabled();
    }
    else if(tablero.getJugador2Turno()){
        tablero.setPos(0,1);
        QString ceroCero = "O";
        ui->posCeroCero->setText(ceroCero);
        tablero.setJugador2(false);
        tablero.setJugador1(true);
    }
}

void MainWindow::on_posCeroUno_clicked()
{
    if(tablero.getJugador1Turno()){
        tablero.setPos(1,-1);
        QString ceroUno = "X";
        ui->posCeroUno->setText(ceroUno);
        tablero.setJugador1(false);
        tablero.setJugador2(true);
    }
    else if(tablero.getJugador2Turno()){
        tablero.setPos(1,1);
        QString ceroUno = "O";
        ui->posCeroUno->setText(ceroUno);
        tablero.setJugador1(true);
        tablero.setJugador2(false);
    }
}

void MainWindow::on_posCeroDos_clicked()
{
    if(tablero.getJugador1Turno()){
        tablero.setPos(2,-1);
        QString ceroDos = "X";
        ui->posCeroDos->setText(ceroDos);
        tablero.setJugador1(false);
        tablero.setJugador2(true);
    }
    else if(tablero.getJugador2Turno()){
        tablero.setPos(2,1);
        QString ceroDos = "O";
        ui->posCeroDos->setText(ceroDos);
        tablero.setJugador1(true);
        tablero.setJugador2(false);
    }
}

void MainWindow::on_posUnoCero_clicked()
{
    if(tablero.getJugador1Turno()){
        tablero.setPos(3,-1);
        QString unoCero = "X";
        ui->posUnoCero->setText(unoCero);
        tablero.setJugador1(false);
        tablero.setJugador2(true);
    }
    else if(tablero.getJugador2Turno()){
        tablero.setPos(3,1);
        QString unoCero = "O";
        ui->posUnoCero->setText(unoCero);
        tablero.setJugador1(true);
        tablero.setJugador2(false);
    }
}

void MainWindow::on_posUnoUno_clicked()
{
    if(tablero.getJugador1Turno()){
        tablero.setPos(4,-1);
        QString cerocero = "X";
        ui->posUnoUno->setText(cerocero);
        tablero.setJugador1(false);
        tablero.setJugador2(true);
    }
    else if(tablero.getJugador2Turno()){
        tablero.setPos(4,1);
        QString cerocero = "O";
        ui->posUnoUno->setText(cerocero);
        tablero.setJugador1(true);
        tablero.setJugador2(false);
    }
}

void MainWindow::on_posUnoDos_clicked()
{
    if(tablero.getJugador1Turno()){
        tablero.setPos(5,-1);
        QString cerocero = "X";
        ui->posUnoDos->setText(cerocero);
        tablero.setJugador1(false);
        tablero.setJugador2(true);
    }
    else if(tablero.getJugador2Turno()){
        tablero.setPos(5,1);
        QString cerocero = "O";
        ui->posUnoDos->setText(cerocero);
        tablero.setJugador1(true);
        tablero.setJugador2(false);
    }
}

void MainWindow::on_posDosCero_clicked()
{
    if(tablero.getJugador1Turno()){
        tablero.setPos(6,-1);
        QString cerocero = "X";
        ui->posDosCero->setText(cerocero);
        tablero.setJugador1(false);
        tablero.setJugador2(true);
    }
    else if(tablero.getJugador2Turno()){
        tablero.setPos(6,1);
        QString cerocero = "O";
        ui->posDosCero->setText(cerocero);
        tablero.setJugador1(true);
        tablero.setJugador2(false);
    }
}

void MainWindow::on_posDosUno_clicked()
{
    if(tablero.getJugador1Turno()){
        tablero.setPos(7,-1);
        QString cerocero = "X";
        ui->posDosUno->setText(cerocero);
        tablero.setJugador1(false);
        tablero.setJugador2(true);
    }
    else if(tablero.getJugador2Turno()){
        tablero.setPos(7,1);
        QString cerocero = "O";
        ui->posDosUno->setText(cerocero);
        tablero.setJugador1(true);
        tablero.setJugador2(false);
    }
}

void MainWindow::on_posDosDos_clicked()
{
    if(tablero.getJugador1Turno()){
        tablero.setPos(8,-1);
        QString cerocero = "X";
        ui->posDosDos->setText(cerocero);
        tablero.setJugador1(false);
        tablero.setJugador2(true);
    }
    else if(tablero.getJugador2Turno()){
        tablero.setPos(8,1);
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

}

void MainWindow::on_radioButton_clicked()
{

}

void MainWindow::on_pushButton_2_clicked()
{
    if(tablero.revisarGanador()==0){
                    int k;
                    k=tablero.computadoraMueve();
                    tablero.setPos(k,1);
                    if(k == 0){
                        on_posCeroCero_clicked();
                    }
                    else if(k == 1){
                        on_posCeroUno_clicked();
                    }
                    else if(k == 2){
                        on_posCeroDos_clicked();
                    }
                    else if(k == 3){
                        on_posUnoCero_clicked();
                    }
                    else if(k == 4){
                        on_posUnoUno_clicked();
                    }
                    else if(k == 5){
                        on_posUnoDos_clicked();
                    }
                    else if(k == 6){
                        on_posDosCero_clicked();
                    }
                    else if(k == 7){
                        on_posDosUno_clicked();
                    }
                    else if(k == 8){
                        on_posDosDos_clicked();
                    }

                    if (tablero.revisarGanador() != 0){
                        cout<<"Ganó computadora";
                    }
                }
}
