#ifndef CREDIT_H
#define CREDIT_H

#include <QMainWindow>

extern "C" {
    #include "credit_calc.h"
}

namespace Ui {
class Credit;
}

class Credit : public QMainWindow
{
    Q_OBJECT

public:
    explicit Credit(QWidget *parent = nullptr);
    ~Credit();

private slots:
    void on_run_count_clicked();

private:
    Ui::Credit *ui;

    void clear();
    QString get_credit_type();
    char *qstring_to_char(QString qstr);
    int fields_is_empty();
};

#endif // CREDIT_H
