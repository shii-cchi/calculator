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
    if (!ui->credit_sum->text().isEmpty() && !ui->credit_term->text().isEmpty() && !ui->credit_percent->text().isEmpty() && (ui->credit_type_1->isChecked() || ui->credit_type_2->isChecked()))
    {
        QString credit_type;
        if (ui->credit_type_1->isChecked())
        {
            credit_type = "a";
        }
        else
        {
            credit_type = "d";
        }

        QString credit_data = ui->credit_sum->text() + " " + ui->credit_term->text() + " " + ui->credit_percent->text() + " " + credit_type;
        QByteArray arr = credit_data.toLocal8Bit();
        char *str = arr.data();
        double max_payment = 0, min_payment = 0, overpayment = 0, total_sum = 0;
        int status = credit_calculate(str, &max_payment, &min_payment, &overpayment, &total_sum);
        if (status)
        {
            if (credit_type == "a")
            {
                ui->payment_2->setText(QString::number(max_payment));
            }
            else
            {
                ui->payment_2->setText(QString::number(max_payment) + "..." + QString::number(min_payment));
            }
            ui->payment_1->setText("Ежемесячный платеж: ");
            ui->overpayment_1->setText("Переплата по кредиту: ");
            ui->total_sum_1->setText("Общая выплата: ");
            ui->overpayment_2->setText(QString::number(overpayment));
            ui->total_sum_2->setText(QString::number(total_sum));
        }
        else
        {
            ui->payment_1->setText("Error");
        }
    }
}

