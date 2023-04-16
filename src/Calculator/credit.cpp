#include "credit.h"
#include "ui_credit.h"

Credit::Credit(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Credit)
{
    ui->setupUi(this);
}

Credit::~Credit()
{
    delete ui;
}

void Credit::on_run_count_clicked()
{
    if (!ui->credit_sum->text().isEmpty() && !ui->credit_term->text().isEmpty() && !ui->credit_percent->text().isEmpty())
    {
        QString credit_data = ui->credit_sum->text() + " " + ui->credit_term->text() + " " + ui->credit_percent->text();
//        QByteArray arr = credit_data.toLocal8Bit();
//        char *str = arr.data();
//        credit_calculate(str);
    }
}

