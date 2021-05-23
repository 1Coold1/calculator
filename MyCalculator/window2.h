#ifndef WINDOW2_H
#define WINDOW2_H

#include <QDialog>

namespace Ui {
class window2;
}

class window2 : public QDialog
{
    Q_OBJECT

public:
    explicit window2(QWidget *parent = nullptr);
    ~window2();

signals:
    void firstWindow();  // Сигнал для первого окна на открытие

private slots:
    void on_pushButton_clicked();
    void date_format();
    void operations();
    void on_equal_clicked();

private:
    Ui::window2 *ui;
};

#endif // WINDOW2_H
