#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(click_numbers()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(click_numbers()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(click_numbers()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(click_numbers()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(click_numbers()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(click_numbers()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(click_numbers()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(click_numbers()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(click_numbers()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(click_numbers()));

    connect(ui->pushButton_delete_all,SIGNAL(clicked()),this,SLOT(click_delete()));
    connect(ui->pushButton_delete_1,SIGNAL(clicked()),this,SLOT(click_delete()));

    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(click_plus_minus_mult_divide()));
    connect(ui->pushButton_minus,SIGNAL(clicked()),this,SLOT(click_plus_minus_mult_divide()));
    connect(ui->pushButton_mult,SIGNAL(clicked()),this,SLOT(click_plus_minus_mult_divide()));
    connect(ui->pushButton_divide,SIGNAL(clicked()),this,SLOT(click_plus_minus_mult_divide()));

    connect(ui->pushButton_bracket_1,SIGNAL(clicked()),this,SLOT(click_bracket()));
    connect(ui->pushButton_bracket_2,SIGNAL(clicked()),this,SLOT(click_bracket()));

    connect(ui->pushButton_lg,SIGNAL(clicked()),this,SLOT(click_func()));
    connect(ui->pushButton_ln,SIGNAL(clicked()),this,SLOT(click_func()));
    connect(ui->pushButton_sqrt,SIGNAL(clicked()),this,SLOT(click_func()));
    connect(ui->pushButton_sin,SIGNAL(clicked()),this,SLOT(click_func()));
    connect(ui->pushButton_cos,SIGNAL(clicked()),this,SLOT(click_func()));
    connect(ui->pushButton_tan,SIGNAL(clicked()),this,SLOT(click_func()));
    connect(ui->pushButton_asin,SIGNAL(clicked()),this,SLOT(click_func()));
    connect(ui->pushButton_acos,SIGNAL(clicked()),this,SLOT(click_func()));
    connect(ui->pushButton_atan,SIGNAL(clicked()),this,SLOT(click_func()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::click_numbers()
{
    QPushButton *button = (QPushButton *)sender();
    QString new_result_window;
    if (ui->result_window->text() == "0")
    {
        new_result_window = button->text();
    }
    else
    {
        new_result_window = ui->result_window->text() + button->text();
    }
    ui->result_window->setText(new_result_window);
}

void MainWindow::click_delete()
{
    QPushButton *button = (QPushButton *)sender();
    if (button->text() == "C")
    {
        ui->result_window->setText("0");
    }

    if (button->text() == "<-")
    {
        if (ui->result_window->text().length() > 1)
        {
            QString new_window = ui->result_window->text();
            if (new_window.last(1) == "(")
            {
                new_window = ui->result_window->text().chopped(1);
                while (new_window.last(1) != "(" && new_window.last(1) != " ")
                {
                    if (new_window.length() == 1)
                    {
                        new_window = "0";
                        break;
                    }
                    else
                    {
                        new_window = new_window.chopped(1);
                    }
                }
                ui->result_window->setText(new_window);
            }
            else
            {
                new_window = new_window.chopped(1);
                if (new_window.last(1) == " ")
                {
                   new_window = new_window.chopped(1);
                }
                ui->result_window->setText(new_window);
            }
        }
        else if (ui->result_window->text().length() == 1)
        {
            ui->result_window->setText("0");
        }
    }
}

void MainWindow::on_pushButton_dot_clicked()
{
    ui->result_window->setText(ui->result_window->text() + ".");
}

void MainWindow::click_plus_minus_mult_divide()
{
    QString new_result_window;
    QPushButton *button = (QPushButton *)sender();
    new_result_window = " " + button->text() + " ";
    ui->result_window->setText(ui->result_window->text() + new_result_window);
}

void MainWindow::click_bracket()
{
    QPushButton *button = (QPushButton *)sender();
    if (button->text() == "(")
    {
        if (ui->result_window->text() == "0")
        {
           ui->result_window->setText(button->text());
        }
        else
        {
           ui->result_window->setText(ui->result_window->text() + button->text());
        }
    }
    else
    {
        ui->result_window->setText(ui->result_window->text() + button->text());
    }
}

void MainWindow::on_pushButton_pow_clicked()
{
    if (ui->result_window->text().last(1) != "^")
    {
        ui->result_window->setText(ui->result_window->text() + "^");
    }
}

void MainWindow::on_pushButton_mod_clicked()
{
    QString new_result_window;
    QPushButton *button = (QPushButton *)sender();
    new_result_window = " " + button->text() + " ";
    ui->result_window->setText(ui->result_window->text() + new_result_window);
}

void MainWindow::click_func()
{
    QString new_result_window;
    QPushButton *button = (QPushButton *)sender();
    new_result_window = button->text() + "(";
    if (ui->result_window->text() == "0")
    {
        ui->result_window->setText(new_result_window);
    }
    else
    {
        ui->result_window->setText(ui->result_window->text() + new_result_window);
    }
}

void MainWindow::on_pushButton_x_clicked()
{
    QPushButton *button = (QPushButton *)sender();
    QString new_result_window;
    if (ui->result_window->text() == "0")
    {
        new_result_window = button->text();
    }
    else
    {
        new_result_window = ui->result_window->text() + button->text();
    }
    ui->result_window->setText(new_result_window);
}

void MainWindow::on_pushButton_unary_clicked()
{
    if (ui->result_window->text() == "0")
    {
        ui->result_window->setText("-");
    }
    else
    {
        ui->result_window->setText(ui->result_window->text() + "-");
    }
}

void MainWindow::on_pushButton_equal_clicked()
{
    double result;
//    char str [ui->result_window->text().length()];
//    for (int i = 0; i < ui->result_window->text().length(); i++)
//    {
//        str[i] = ui->result_window->text()[i].toLatin1();
//    }
    QByteArray arr = ui->result_window->text().toLocal8Bit();
    char *str = arr.data();
    result = calculate(str);
    ui->result_window->setText(QString::number(result));
}










