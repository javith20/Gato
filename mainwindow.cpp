#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
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
    if (tablero.revisarGanador() != 0 && tablero.revisarGanador() != 2)
        QMessageBox::information(this, tr("Juego terminado"),tr("Ha ganado"));
    else if (tablero.revisarGanador() == 2)
        QMessageBox::information(this, tr("Juego terminado"),tr("Es un empate"));
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
    if (tablero.revisarGanador() != 0 && tablero.revisarGanador() != 2)
        QMessageBox::information(this, tr("Juego terminado"),tr("Ha ganado"));
    else if (tablero.revisarGanador() == 2)
        QMessageBox::information(this, tr("Juego terminado"),tr("Es un empate"));
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
    if (tablero.revisarGanador() != 0 && tablero.revisarGanador() != 2)
        QMessageBox::information(this, tr("Juego terminado"),tr("Ha ganado"));
    else if (tablero.revisarGanador() == 2)
        QMessageBox::information(this, tr("Juego terminado"),tr("Es un empate"));
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
    if (tablero.revisarGanador() != 0 && tablero.revisarGanador() != 2)
        QMessageBox::information(this, tr("Juego terminado"),tr("Ha ganado"));
    else if (tablero.revisarGanador() == 2)
        QMessageBox::information(this, tr("Juego terminado"),tr("Es un empate"));
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
    if (tablero.revisarGanador() != 0 && tablero.revisarGanador() != 2)
        QMessageBox::information(this, tr("Juego terminado"),tr("Ha ganado"));
    else if (tablero.revisarGanador() == 2)
        QMessageBox::information(this, tr("Juego terminado"),tr("Es un empate"));
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
    if (tablero.revisarGanador() != 0 && tablero.revisarGanador() != 2)
        QMessageBox::information(this, tr("Juego terminado"),tr("Ha ganado"));
    else if (tablero.revisarGanador() == 2)
        QMessageBox::information(this, tr("Juego terminado"),tr("Es un empate"));
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
    if (tablero.revisarGanador() != 0 && tablero.revisarGanador() != 2)
        QMessageBox::information(this, tr("Juego terminado"),tr("Ha ganado"));
    else if (tablero.revisarGanador() == 2)
        QMessageBox::information(this, tr("Juego terminado"),tr("Es un empate"));
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
    if (tablero.revisarGanador() != 0 && tablero.revisarGanador() != 2)
        QMessageBox::information(this, tr("Juego terminado"),tr("Ha ganado"));
    else if (tablero.revisarGanador() == 2)
        QMessageBox::information(this, tr("Juego terminado"),tr("Es un empate"));
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
    if (tablero.revisarGanador() != 0 && tablero.revisarGanador() != 2)
        QMessageBox::information(this, tr("Juego terminado"),tr("Ha ganado"));
    else if (tablero.revisarGanador() == 2)
        QMessageBox::information(this, tr("Juego terminado"),tr("Es un empate"));
}

void MainWindow::on_iniciarButton_clicked()
{
    if(tablero.getVsCPU() && tablero.getJugador1VsMaquinaSeleccionado()){
        on_pushButton_2_clicked();
    }
    else if(tablero.getVsCPU() && tablero.getJugador2VsMaquinaSeleccionado()){
        on_pushButton_2_clicked();
    }
    else if(tablero.getVsCPU() && (!tablero.getJugador1VsMaquinaSeleccionado() && !tablero.getJugador2VsMaquinaSeleccionado())){
        QMessageBox::information(this, tr("Error"),tr("No se ha seleccionado jugador vs PC"));
    }
    tablero.setJugador1(true);
    tablero.setJugador2(false);
    tablero.setJugador1Figura('X');
    tablero.setJugador2Figura('O');
}

void MainWindow::on_radioButton_clicked()
{
    if(!tablero.getVsCPU()){
        tablero.setVsCPU(true);
        ui->radioButton_2->setEnabled(true);
        ui->radioButton_3->setEnabled(true);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    if(tablero.getVsCPU()){
        if(tablero.revisarGanador()==0){
            int k;
            k=tablero.computadoraMueve();
            tablero.setPos(k,1);
            switch(k){
            case 0:
                on_posCeroCero_clicked();
                break;
            case 1:
                on_posCeroUno_clicked();
                break;
            case 2:
                on_posCeroDos_clicked();
                break;
            case 3:
                on_posUnoCero_clicked();
                break;
            case 4:
                on_posUnoUno_clicked();
                break;
            case 5:
                on_posUnoDos_clicked();
                break;
            case 6:
                on_posDosCero_clicked();
                break;
            case 7:
                on_posDosUno_clicked();
                break;
            case 8:
                on_posDosDos_clicked();
                break;
            }

            if (tablero.revisarGanador() != 0 && tablero.revisarGanador() != 2)
                QMessageBox::information(this, tr("Juego terminado"),tr("Ha ganado la PC"));
            else if (tablero.revisarGanador() == 2)
                QMessageBox::information(this, tr("Juego terminado"),tr("Es un empate"));
        }
    }
}



void MainWindow::on_radioButton_2_clicked(bool checked)
{
  if(!tablero.getJugador2VsMaquinaSeleccionado() && checked)
  {
      tablero.setJugador1VsMaquinaSeleccionado(true);
      ui->radioButton_3->setDisabled(true);
  }
  else
      ui->radioButton_3->setEnabled(true);
}

void MainWindow::on_radioButton_3_clicked(bool checked)
{
   if(!tablero.getJugador1VsMaquinaSeleccionado()){
       tablero.setJugador2VsMaquinaSeleccionado(true);
       ui->radioButton_2->setDisabled(true);
   }
   else
       ui->radioButton_3->setEnabled(true);
}
