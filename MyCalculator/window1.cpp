#include "window1.h"
#include "ui_window1.h"
#include "QMessageBox"

window1::window1(QWidget *parent) :
QDialog(parent),
ui(new Ui::window1)
{
ui->setupUi(this);

QIcon winIcon(":/img/Icons/icon.png");
this->setWindowIcon(winIcon);

ui->rus1->setChecked(true);
ui->rus2->setChecked(true);
ui->year->setChecked(true);

connect(ui->rus1,SIGNAL(clicked()),this,SLOT(date_format()));
connect(ui->usa1,SIGNAL(clicked()),this,SLOT(date_format()));
connect(ui->angl1,SIGNAL(clicked()),this,SLOT(date_format()));
connect(ui->rus2,SIGNAL(clicked()),this,SLOT(date_format()));
connect(ui->usa2,SIGNAL(clicked()),this,SLOT(date_format()));
connect(ui->angl2,SIGNAL(clicked()),this,SLOT(date_format()));
}

window1::~window1()
{
delete ui;
}

void window1::on_pushButton_clicked()
{
this->close(); // Закрываем окно
emit firstWindow(); // И вызываем сигнал на открытие главного окна
}

void window1::date_format()
{
    if(ui->rus1->isChecked()) {
        ui->data1->setDisplayFormat("dd.MM.yyyy HH:mm:ss");
    }
    if(ui->usa1->isChecked()) {
        ui->data1->setDisplayFormat("MM-dd-yyyy HH:mm:ss");
    }
    if(ui->angl1->isChecked()) {
        ui->data1->setDisplayFormat("dd/MM/yyyy HH:mm:ss");
    }

    if(ui->rus2->isChecked()) {
        ui->data2->setDisplayFormat("dd.MM.yyyy HH:mm:ss");
    }
    if(ui->usa2->isChecked()) {
        ui->data2->setDisplayFormat("MM-dd-yyyy HH:mm:ss");
    }
    if(ui->angl2->isChecked()) {
        ui->data2->setDisplayFormat("dd/MM/yyyy HH:mm:ss");
    }
}

void window1::on_equal_clicked()
{
    QDate date1=ui->data1->date();
    QDate date2=ui->data2->date();
    QDateTime date1_1=ui->data1->dateTime();
    QDateTime date2_2=ui->data2->dateTime();
    qint64 y, z,x1,x2,x3;
    if (date1_1<date2_2) {
        QMessageBox::warning(this,"Ошибка","Вторая дата больше первой");
    } else if (date1_1==date2_2) {
        QMessageBox::warning(this,"Ошибка","Даты равны"); } else {
    if (ui->sec->isChecked()) {
        y = QDateTime::currentDateTime().secsTo(ui->data1->dateTime());
        z = QDateTime::currentDateTime().secsTo(ui->data2->dateTime());
        y = y-z; // разница в секундах
        ui->label->setText(QString::number(y));
    } else if (ui->min->isChecked()) {
        y = QDateTime::currentDateTime().secsTo(ui->data1->dateTime());
        z = QDateTime::currentDateTime().secsTo(ui->data2->dateTime());
        y = y-z; // разница в минутах
        ui->label->setText(QString::number(y/60));
    } else if (ui->hour->isChecked()) {
        y = QDateTime::currentDateTime().secsTo(ui->data1->dateTime());
        z = QDateTime::currentDateTime().secsTo(ui->data2->dateTime());
        y = y-z; // разница в часах
        ui->label->setText(QString::number(y/3600));
    } else if (ui->day->isChecked()) {
        y = QDateTime::currentDateTime().daysTo(ui->data1->dateTime());
        z = QDateTime::currentDateTime().daysTo(ui->data2->dateTime());
        y = y-z; // разница в днях
        ui->label->setText(QString::number(y));
    } else if (ui->year->isChecked()) {
        y = date1.year();
        z = date2.year();
        y = y-z; // разница в годах
        ui->label->setText(QString::number(y));
    } else if (ui->month->isChecked()) {
        y = date1.year();
        z = date2.year();
        x1=date1.month();
        x2=date2.month();
        x3=x1-x2;
        y = y-z; // разница в месяцах
        for (int i=0; i<y;i++) {x3+=12;};
        ui->label->setText(QString::number(x3));
    } else if (ui->week->isChecked()) {
        y = QDateTime::currentDateTime().daysTo(ui->data1->dateTime());
        z = QDateTime::currentDateTime().daysTo(ui->data2->dateTime());
        y = y-z; // разница в неделях
        ui->label->setText(QString::number(y/7));
    }
    }
}
