#ifndef CUSTOM_AXIS_H
#define CUSTOM_AXIS_H

#include <QDialog>

#include "calculator.h"
#include "ui_calculator.h"

class MainWindow;

namespace Ui {
class CustomAxis;
}

class CustomAxis : public QDialog
{
    Q_OBJECT

public:
    explicit CustomAxis(MainWindow *parent = nullptr);
    ~CustomAxis();

private slots:
    void on_pushButton_apply_clicked();
    void on_pushButton_cancel_clicked();

private:
    Ui::CustomAxis *ui;

    void set_default();
};

#endif // CUSTOM_AXIS_H
