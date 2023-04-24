#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include <QtCharts>
#include <QSplineSeries>
#include <QValueAxis>

#include "graph.h"
#include "credit.h"

extern "C" {
    #include "calc.h"
}

#define MAX_Y 100000000

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Graph *graph_window;
    Credit *credit_window;

    int check_valid_data(QString data);
    char *qstring_to_char(QString qstr);
    QSplineSeries *get_series(QString data);
    QString get_new_window(QString button_text, int flag);

private slots:
    void click_numbers();
    void on_pushButton_delete_all_clicked();
    void on_pushButton_delete_1_clicked();
    void on_pushButton_dot_clicked();
    void click_operators();
    void click_bracket();
    void on_pushButton_pow_clicked();
    void click_func();
    void on_pushButton_unary_clicked();
    void on_pushButton_equal_clicked();
    void on_pushButton_graph_clicked();
    void on_pushButton_credit_clicked();
};
#endif // CALCULATOR_H
