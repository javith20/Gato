#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gato.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:


    void on_posCeroCero_clicked();

    void on_posCeroUno_clicked();

    void on_posCeroDos_clicked();

    void on_posUnoCero_clicked();

    void on_posUnoUno_clicked();

    void on_posUnoDos_clicked();

    void on_posDosCero_clicked();

    void on_posDosUno_clicked();

    void on_posDosDos_clicked();

    void on_iniciarButton_clicked();

    void on_pushButton_clicked();

    void on_radioButton_clicked();

    void on_pushButton_2_clicked();

    void on_radioButton_2_clicked(bool checked);

    void on_radioButton_3_clicked(bool checked);

private:
    Ui::MainWindow *ui;
    Gato tablero;
};

#endif // MAINWINDOW_H
