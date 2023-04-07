#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void click_delete();
    void on_pushButton_dot_clicked();
    void click_plus_minus_mult_divide();
    void click_bracket();
    void on_pushButton_pow_clicked();
    void on_pushButton_mod_clicked();
    void click_func();
    void on_pushButton_x_clicked();
    void on_pushButton_unary_clicked();
    void on_pushButton_equal_clicked();
};
#endif // MAINWINDOW_H
