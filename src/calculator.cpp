#include "calculator.h"
#include "ui_calculator.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    graph_window = new Graph();
    credit_window = new Credit();

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
    QString button_text = button->text();
    ui->result_window->setText(get_new_window(button_text, 2));
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
    QString button_text = ",";
    ui->result_window->setText(get_new_window(button_text, 1));
}

void MainWindow::click_operators()
{
    QPushButton *button = (QPushButton *)sender(); 
    QString button_text = " " + button->text() + " ";
    ui->result_window->setText(get_new_window(button_text, 1));
}

void MainWindow::click_bracket()
{
    QPushButton *button = (QPushButton *)sender();
    QString button_text = button->text();
    ui->result_window->setText(get_new_window(button_text, 2));
}

void MainWindow::on_pushButton_pow_clicked()
{
    if (ui->result_window->text().last(1) != "^")
    {
        QString button_text = "^";
        ui->result_window->setText(get_new_window(button_text, 1));
    }
}

void MainWindow::click_func()
{
    QPushButton *button = (QPushButton *)sender();
    QString button_text = button->text() + "(";
    ui->result_window->setText(get_new_window(button_text, 2));
}

void MainWindow::on_pushButton_unary_clicked()
{
    QString button_text = "-";
    ui->result_window->setText(get_new_window(button_text, 2));
}

void MainWindow::on_pushButton_equal_clicked()
{
    if (ui->result_window->text() == "Calculation Error")
    {
        ui->result_window->setText("0");
    }

    if (ui->result_window->text().indexOf('x') == -1) {
        double result = 0;
        char *str_data = qstring_to_char(ui->result_window->text());

        int status = calculate(str_data, &result);
        if (status) {
            ui->result_window->setText(QString::number(result, 'f', 7));
        } else {
            ui->result_window->setText("Calculation Error");
        }
    }
}

void MainWindow::on_pushButton_graph_clicked() {
    if (ui->result_window->text().indexOf('x') != -1)
    {
        int status = check_valid_data();
        if (status)
        {
            QChart *chart = new QChart();
            chart->legend()->hide();
            chart->addSeries(get_series());
            chart->createDefaultAxes();
            chart->setTitle("Graph");

            QChartView *chartView = new QChartView(chart);
            chartView->setRenderHint(QPainter::Antialiasing);

            graph_window->setCentralWidget(chartView);
            graph_window->show();
        }
    }
}

void MainWindow::on_pushButton_credit_clicked()
{
    credit_window->show();
}

QString MainWindow::get_new_window(QString button_text, int flag)
{
    QString new_window;
    if (flag == 2 && (ui->result_window->text() == "0" || ui->result_window->text() == "Calculation Error"))
    {
        new_window = button_text;
    }
    else if (flag == 1 && ui->result_window->text() == "Calculation Error")
    {
        new_window = button_text;
    }
    else
    {
        new_window = ui->result_window->text() + button_text;
    }
    return new_window;
}

int MainWindow::check_valid_data()
{
    char *str_x = qstring_to_char(ui->result_window->text());
    double res = 0;
    int status = calculate(str_x, &res);
    if (!status)
    {
        ui->result_window->setText("Calculation Error");
    }
    return status;
}

char* MainWindow::qstring_to_char(QString qstr)
{
    QByteArray arr = qstr.toLocal8Bit();
    char *str = arr.data();
    return str;
}

QSplineSeries* MainWindow::get_series()
{
    QSplineSeries *series = new QSplineSeries();

    for (int i = -1000; i <= 1000; i+=1)
    {
        QString tmp = ui->result_window->text().replace('x', "(" + QString::number(i) + ")");
        char *str_without_x = qstring_to_char(tmp);

        double res = 0;
        calculate(str_without_x, &res);

        if (res >= -100000000 && res <= 100000000)
        {
            series->append(i, res);
        }
    }
    return series;
}

