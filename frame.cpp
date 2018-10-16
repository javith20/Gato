#include "frame.h"
#include "ui_frame.h"

Frame::Frame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Frame)
{
    ui->setupUi(this);
    //sender = new mainwindow;
}

Frame::~Frame()
{
    delete ui;
}

void Frame::on_pushButton_clicked()
{
   // sender->setModal(true);
   // sender->exec();
}
