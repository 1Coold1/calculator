#ifndef WINDOW1_H
#define WINDOW1_H

#include <QDialog>

namespace Ui {
class window1;
}

class window1 : public QDialog
{
Q_OBJECT

public:
explicit window1(QWidget *parent = nullptr);
~window1();

signals:
void firstWindow(); // Сигнал для первого окна на открытие

private slots:
void on_pushButton_clicked();
void date_format();
void on_equal_clicked();

private:
Ui::window1 *ui;
};

#endif // WINDOW1_H
