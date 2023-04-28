#ifndef SET_CUSTOM_AXIS_H
#define SET_CUSTOM_AXIS_H

#include <QDialog>

#include "calculator.h"
#include "ui_calculator.h"
class MainWindow;

namespace Ui {
class SetCustomAxis;
}

class SetCustomAxis : public QDialog
{
    Q_OBJECT

public:
    explicit SetCustomAxis(MainWindow *parent = nullptr);
//    void setMainWindow(MainWindow *mainWindow);
    ~SetCustomAxis();

private slots:
    void on_pushButton_apply_clicked();
    void on_pushButton_cancel_clicked();

private:
//    MainWindow *mainWindow;
    Ui::SetCustomAxis *ui;
};

#endif // SET_CUSTOM_AXIS_H
