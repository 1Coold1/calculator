#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QIcon winIcon(":/img/Icons/icon.png");
    this->setWindowIcon(winIcon);

    // Инициализируем второе окно
    okno1 = new window1();
    // подключаем к слоту запуска главного окна по кнопке во втором окне
    connect(okno1, &window1::firstWindow, this, &MainWindow::show);

    // Инициализируем третье окно
    okno2 = new window2();
    // подключаем к слоту запуска главного окна по кнопке в третьем окне
    connect(okno2, &window2::firstWindow, this, &MainWindow::show);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_menu1_clicked()
{
    okno1->show();  // Показываем второе окно
    this->close();    // Закрываем основное окно

}

void MainWindow::on_menu2_clicked()
{
    okno2->show();  // Показываем третье окно
    this->close();    // Закрываем основное окно

}
