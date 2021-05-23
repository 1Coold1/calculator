#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "window1.h"
#include "window2.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    window1 *okno1;
    window2 *okno2;

private slots:
    void on_menu1_clicked();
    void on_menu2_clicked();
};



#endif // MAINWINDOW_H
