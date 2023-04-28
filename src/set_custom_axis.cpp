#include "set_custom_axis.h"
#include "ui_set_custom_axis.h"

SetCustomAxis::SetCustomAxis(MainWindow *parent) :
    QDialog(parent),
    ui(new Ui::SetCustomAxis)
{
    ui->setupUi(this);
}

SetCustomAxis::~SetCustomAxis()
{
    delete ui;
}

void SetCustomAxis::on_pushButton_apply_clicked()
{
    bool x_1, x_2, y_1, y_2;
    int max_x = ui->max_x->text().toInt(&x_1, 10);
    int min_x = ui->min_x->text().toInt(&x_2, 10);
    int max_y = ui->max_y->text().toInt(&y_1, 10);
    int min_y = ui->min_y->text().toInt(&y_2, 10);

    if (x_1 && x_2 && y_1 && y_2 && max_x > min_x && max_y > min_y && max_x <= MAX_XY && min_x >= -MAX_XY && max_y <= MAX_XY && min_y >= -MAX_XY)
    {
        qobject_cast<MainWindow*>(parent())->plot_graph(max_x, min_x, max_y, min_y);

        //this->close();
        set_default();
    }
    else
    {
        ui->label_err->setText("Ошибка ввода");
    }
}


void SetCustomAxis::on_pushButton_cancel_clicked()
{
    this->close();
    set_default();
}

void SetCustomAxis::set_default()
{
    ui->label_err->setText("");
    ui->max_x->setText("1000");
    ui->min_x->setText("-1000");
    ui->max_y->setText("1000");
    ui->min_y->setText("-1000");
}
