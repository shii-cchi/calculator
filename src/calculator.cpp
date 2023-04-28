#include "calculator.h"
#include "ui_calculator.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Калькулятор");
    graph_window = new Graph();
    credit_window = new Credit();
    set_custom_axis = new SetCustomAxis(this);
//    set_custom_axis->setMainWindow(this);

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
    if (window == "Ошибка ввода")
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
    QString button_text = ".";
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
    if (ui->result_window->text().last(1) == " " || ui->result_window->text().last(1) == "(" || ui->result_window->text().last(1) == "0")
    {
        QString button_text = "-";
    	ui->result_window->setText(get_new_window(button_text, 2));
    }
}

void MainWindow::on_pushButton_equal_clicked()
{
    if (ui->result_window->text() == "Ошибка ввода")
    {
        ui->result_window->setText("0");
    }

    QString data = ui->result_window->text().replace(".", ",");

    if (data.indexOf('x') == -1) {
        double result = 0;
        char *str_data = qstring_to_char(data);

        int status = calculate(str_data, &result);
        if (status) {
            ui->result_window->setText(QString::number(result, 'f', 7));
        } else {
            ui->result_window->setText("Ошибка ввода");
        }
    }
}

void MainWindow::on_pushButton_graph_clicked() {
    if (ui->result_window->text().indexOf('x') != -1)
    {
        set_custom_axis->show();
        int apply = 0;
        //here is place for making set_axis window
    }
}

void MainWindow::on_pushButton_credit_clicked()
{
    credit_window->show();
}

QString MainWindow::get_new_window(QString button_text, int flag)
{
    QString new_window;
    if (flag == 2 && (ui->result_window->text() == "0" || ui->result_window->text() == "Ошибка ввода"))
    {
        new_window = button_text;
    }
    else if (flag == 1 && ui->result_window->text() == "Ошибка ввода")
    {
        new_window = button_text;
    }
    else
    {
        new_window = ui->result_window->text() + button_text;
    }
    return new_window;
}

int MainWindow::check_valid_data(QString data)
{
    char *str_x = qstring_to_char(data);
    double res = 0;
    int status = calculate(str_x, &res);
    if (!status)
    {
        ui->result_window->setText("Ошибка ввода");
    }
    return status;
}

char* MainWindow::qstring_to_char(QString qstr)
{
    QByteArray arr = qstr.toLocal8Bit();
    char *str = arr.data();
    return str;
}

void MainWindow::plot_graph(int max_x, int min_x, int max_y, int min_y)
{
    QString data = ui->result_window->text().replace(".", ",");

    int status = check_valid_data(data);
    if (status)
    {
        QChart *chart = new QChart();
        chart->legend()->hide();
        chart->addSeries(get_series(data, max_x, min_x, max_y, min_y));
        chart->createDefaultAxes();

        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        graph_window->setCentralWidget(chartView);
        graph_window->show();
    }
}

QSplineSeries* MainWindow::get_series(QString data, int max_x, int min_x, int max_y, int min_y)
{
    QSplineSeries *series = new QSplineSeries();
    int min = -1000, max = 1000;
    
    if (data.indexOf("sin") != -1 || data.indexOf("cos") != -1)
    {
    	min = -100;
    	max = 100;
    }

    for (int i = min; i <= max; i+=1)
    {
        QString tmp = data;
        char *str_without_x = qstring_to_char(tmp.replace('x', "(" + QString::number(i) + ")"));

        double res = 0;
        calculate(str_without_x, &res);

        if (res >= -MAX_Y && res <= MAX_Y)
        {
            series->append(i, res);
        }
    }
    return series;
}
