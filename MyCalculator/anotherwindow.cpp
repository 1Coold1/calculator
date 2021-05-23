#include "anotherwindow.h"
#include "ui_window2.h"

anotherwindow::anotherwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::anotherwindow)
{
    ui->setupUi(this);
}

anotherwindow::~anotherwindow()
{
    delete ui;
}

void anotherwindow::on_pushButton_clicked()
{
    this->close();      // Закрываем окно
    emit firstWindow(); // И вызываем сигнал на открытие главного окна
}
