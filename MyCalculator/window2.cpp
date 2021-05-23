#include "window2.h"
#include "ui_window2.h"
#include "QMessageBox"

window2::window2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::window2)
{
    ui->setupUi(this);

    QIcon winIcon(":/img/Icons/icon.png");
    this->setWindowIcon(winIcon);

    ui->rus1->setChecked(true);
    ui->rus2->setChecked(true);
    ui->year->setChecked(true);

    connect(ui->plus,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->minus,SIGNAL(clicked()),this,SLOT(operations()));

    connect(ui->rus1,SIGNAL(clicked()),this,SLOT(date_format()));
    connect(ui->usa1,SIGNAL(clicked()),this,SLOT(date_format()));
    connect(ui->angl1,SIGNAL(clicked()),this,SLOT(date_format()));
    connect(ui->rus2,SIGNAL(clicked()),this,SLOT(date_format()));
    connect(ui->usa2,SIGNAL(clicked()),this,SLOT(date_format()));
    connect(ui->angl2,SIGNAL(clicked()),this,SLOT(date_format()));

    ui->plus->setCheckable(true);
    ui->minus->setCheckable(true);
}

window2::~window2()
{
    delete ui;
}

void window2::on_pushButton_clicked()
{
    this->close();      // Закрываем окно
    emit firstWindow(); // И вызываем сигнал на открытие главного окна
}

void window2::date_format()
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

void window2::operations()
{
    QPushButton *button = (QPushButton *)sender();
    button->setChecked(true);
}

void window2::on_equal_clicked()
{
    QDateTime date=ui->data1->dateTime();
    QDate datemin(1752,9,14);
    QDate datemax(9999,12,31);
    qint64 add = ui->lineEdit->text().toInt();
    if (add<0) {QMessageBox::warning(this,"Ошибка","Введено отрицательное число");} else
        if (add==0) {QMessageBox::warning(this,"Ошибка","Введен ноль или сторонние символы");} else {
    if(ui->plus->isChecked()) {
        if (ui->year->isChecked()){
        ui->data2->setDateTime(date.addYears(add));
        if (ui->data2->date()==datemax) QMessageBox::warning(this,"Ошибка","Достигнут предел даты");
        ui->plus->setChecked(false);
        } else if (ui->month->isChecked()) {
            ui->data2->setDateTime(date.addMonths(add));
            if (ui->data2->date()==datemax) QMessageBox::warning(this,"Ошибка","Достигнут предел даты");
            ui->plus->setChecked(false);
        } else if (ui->day->isChecked()) {
            ui->data2->setDateTime(date.addDays(add));
            if (ui->data2->date()==datemax) QMessageBox::warning(this,"Ошибка","Достигнут предел даты");
            ui->plus->setChecked(false);
        } else if (ui->hour->isChecked()) {
            ui->data2->setDateTime(date.addSecs(add*3600));
            if (ui->data2->date()==datemax) QMessageBox::warning(this,"Ошибка","Достигнут предел даты");
            ui->plus->setChecked(false);
        }
        else if (ui->min->isChecked()) {
            ui->data2->setDateTime(date.addSecs(add*60));
            if (ui->data2->date()==datemax) QMessageBox::warning(this,"Ошибка","Достигнут предел даты");
            ui->plus->setChecked(false);
        }  else if (ui->sec->isChecked()) {
            ui->data2->setDateTime(date.addSecs(add));
            if (ui->data2->date()==datemax) QMessageBox::warning(this,"Ошибка","Достигнут предел даты");
            ui->plus->setChecked(false);
        } else if (ui->week->isChecked()) {
            ui->data2->setDateTime(date.addDays(add*7));
            if (ui->data2->date()==datemax) QMessageBox::warning(this,"Ошибка","Достигнут предел даты");
            ui->plus->setChecked(false);
        }
    }
    else if (ui->minus->isChecked()) {
        if (ui->year->isChecked()){
        ui->data2->setDateTime(date.addYears(-add));
        if (ui->data2->date()==datemin) QMessageBox::warning(this,"Ошибка","Достигнут предел даты");
        ui->minus->setChecked(false);
        } else if (ui->month->isChecked()) {
            ui->data2->setDateTime(date.addMonths(-add));
            if (ui->data2->date()==datemin) QMessageBox::warning(this,"Ошибка","Достигнут предел даты");
            ui->minus->setChecked(false);
        } else if (ui->day->isChecked()) {
            ui->data2->setDateTime(date.addDays(-add));
            if (ui->data2->date()==datemin) QMessageBox::warning(this,"Ошибка","Достигнут предел даты");
            ui->minus->setChecked(false);
        } else if (ui->hour->isChecked()) {
            ui->data2->setDateTime(date.addSecs(-add*3600));
            if (ui->data2->date()==datemin) QMessageBox::warning(this,"Ошибка","Достигнут предел даты");
            ui->minus->setChecked(false);
        }
        else if (ui->min->isChecked()) {
            ui->data2->setDateTime(date.addSecs(-add*60));
            if (ui->data2->date()==datemin) QMessageBox::warning(this,"Ошибка","Достигнут предел даты");
            ui->minus->setChecked(false);
        }  else if (ui->sec->isChecked()) {
            ui->data2->setDateTime(date.addSecs(-add));
            if (ui->data2->date()==datemin) QMessageBox::warning(this,"Ошибка","Достигнут предел даты");
            ui->minus->setChecked(false);
        } else if (ui->week->isChecked()) {
            ui->data2->setDateTime(date.addDays(-add*7));
            if (ui->data2->date()==datemin) QMessageBox::warning(this,"Ошибка","Достигнут предел даты");
            ui->minus->setChecked(false);
        }
    }
        }
}

