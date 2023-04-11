#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts>
#include <QSplineSeries>

extern "C" {
    #include "calc.h"
}

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
};
#endif // MAINWINDOW_H
