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
    connect(ui->pushButton_x,SIGNAL(clicked()),this,SLOT(click_numbers()));

    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(click_operators()));
    connect(ui->pushButton_minus,SIGNAL(clicked()),this,SLOT(click_operators()));
    connect(ui->pushButton_mult,SIGNAL(clicked()),this,SLOT(click_operators()));
    connect(ui->pushButton_divide,SIGNAL(clicked()),this,SLOT(click_operators()));
    connect(ui->pushButton_mod,SIGNAL(clicked()),this,SLOT(click_operators()));

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
    if (ui->result_window->text() == "0" || ui->result_window->text() == "Calculation Error")
    {
        new_result_window = button->text();
    }
    else
    {
        new_result_window = ui->result_window->text() + button->text();
    }
    ui->result_window->setText(new_result_window);
}

void MainWindow::on_pushButton_delete_all_clicked() 
{
    ui->result_window->setText("0");
}

void MainWindow::on_pushButton_delete_1_clicked() 
{
    QString window = ui->result_window->text();
    if (window == "Calculation Error")
    {
        window = "0";
    }
    if (window.length() > 1)
    {
        do {
            window = window.chopped(1);
        } while (window.last(1) != "(" && window.last(1) != " " && window.length() > 1);

        if (window.last(1) == " ")
        {
            window = window.chopped(1);
        }
    }
    if (window.length() == 1)
    {
        window = "0";
    }
    ui->result_window->setText(window);
}

void MainWindow::on_pushButton_dot_clicked()
{
    if (ui->result_window->text() == "Calculation Error")
    {
        ui->result_window->setText(",");
    }
    else
    {
        ui->result_window->setText(ui->result_window->text() + ",");
    }
}

void MainWindow::click_operators()
{
    QString new_result_window;
    QPushButton *button = (QPushButton *)sender();
    new_result_window = " " + button->text() + " ";
    if (ui->result_window->text() == "Calculation Error")
    {
        ui->result_window->setText(new_result_window);
    }
    else
    {
        ui->result_window->setText(ui->result_window->text() + new_result_window);
    }
}

void MainWindow::click_bracket()
{
    QPushButton *button = (QPushButton *)sender();
    if (ui->result_window->text() == "0" || ui->result_window->text() == "Calculation Error")
    {
        ui->result_window->setText(button->text());
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
        if (ui->result_window->text() == "Calculation Error")
        {
            ui->result_window->setText("^");
        }
        else
        {
            ui->result_window->setText(ui->result_window->text() + "^");
        }
    }
}

void MainWindow::click_func()
{
    QString new_result_window;
    QPushButton *button = (QPushButton *)sender();
    new_result_window = button->text() + "(";
    if (ui->result_window->text() == "0" || ui->result_window->text() == "Calculation Error")
    {
        ui->result_window->setText(new_result_window);
    }
    else
    {
        ui->result_window->setText(ui->result_window->text() + new_result_window);
    }
}

void MainWindow::on_pushButton_unary_clicked()
{
    if (ui->result_window->text() == "0" || ui->result_window->text() == "Calculation Error")
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
    if (ui->result_window->text() == "Calculation Error")
    {
        ui->result_window->setText("0");
    }

    if (ui->result_window->text().indexOf('x') == -1) {
        double result = 0;
        QByteArray arr = ui->result_window->text().toLocal8Bit();
        char *str = arr.data();

        int status = calculate(str, &result);
        if (status) {
            ui->result_window->setText(QString::number(result, 'f', 7));
        } else {
            ui->result_window->setText("Calculation Error");
        }
    }
}

void MainWindow::on_pushButton_graph_clicked() {
    QSplineSeries *series = new QSplineSeries();
}






