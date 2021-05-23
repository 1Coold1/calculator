#ifndef ANOTHERWINDOW_H
#define ANOTHERWINDOW_H

#include <QWidget>

namespace Ui {
class anotherwindow;
}

class anotherwindow : public QWidget
{
    Q_OBJECT

public:
    explicit anotherwindow(QWidget *parent = 0);
    ~anotherwindow();

signals:
    void firstWindow();  // Сигнал для первого окна на открытие

private slots:
    // Слот-обработчик нажатия кнопки
    void on_pushButton_clicked();

private:
    Ui::anotherwindow *ui;
};

#endif // ANOTHERWINDOW_H
