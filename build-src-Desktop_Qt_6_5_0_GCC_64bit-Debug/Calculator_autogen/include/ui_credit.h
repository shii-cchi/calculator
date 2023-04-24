/********************************************************************************
** Form generated from reading UI file 'credit.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREDIT_H
#define UI_CREDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Credit
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *credit_percent;
    QLabel *label_3;
    QLabel *label_6;
    QLabel *label;
    QLabel *label_5;
    QLineEdit *credit_term;
    QLineEdit *credit_sum;
    QLabel *label_2;
    QLabel *label_4;
    QRadioButton *credit_type_1;
    QRadioButton *credit_type_2;
    QLabel *label_7;
    QPushButton *run_count;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *overpayment_1;
    QLabel *total_sum_1;
    QLabel *payment_1;
    QLabel *payment_2;
    QLabel *overpayment_2;
    QLabel *total_sum_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Credit)
    {
        if (Credit->objectName().isEmpty())
            Credit->setObjectName("Credit");
        Credit->resize(500, 400);
        centralwidget = new QWidget(Credit);
        centralwidget->setObjectName("centralwidget");
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(30, 0, 441, 241));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        credit_percent = new QLineEdit(gridLayoutWidget);
        credit_percent->setObjectName("credit_percent");

        gridLayout->addWidget(credit_percent, 2, 1, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName("label_3");
        QFont font;
        font.setBold(true);
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName("label_6");

        gridLayout->addWidget(label_6, 2, 2, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName("label");
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName("label_5");

        gridLayout->addWidget(label_5, 0, 2, 1, 1);

        credit_term = new QLineEdit(gridLayoutWidget);
        credit_term->setObjectName("credit_term");

        gridLayout->addWidget(credit_term, 1, 1, 1, 1);

        credit_sum = new QLineEdit(gridLayoutWidget);
        credit_sum->setObjectName("credit_sum");

        gridLayout->addWidget(credit_sum, 0, 1, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName("label_4");
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        credit_type_1 = new QRadioButton(gridLayoutWidget);
        credit_type_1->setObjectName("credit_type_1");

        gridLayout->addWidget(credit_type_1, 3, 1, 1, 2);

        credit_type_2 = new QRadioButton(gridLayoutWidget);
        credit_type_2->setObjectName("credit_type_2");

        gridLayout->addWidget(credit_type_2, 4, 1, 1, 2);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName("label_7");

        gridLayout->addWidget(label_7, 1, 2, 1, 1);

        run_count = new QPushButton(centralwidget);
        run_count->setObjectName("run_count");
        run_count->setGeometry(QRect(350, 240, 121, 31));
        run_count->setFont(font);
        formLayoutWidget = new QWidget(centralwidget);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(30, 280, 441, 81));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        overpayment_1 = new QLabel(formLayoutWidget);
        overpayment_1->setObjectName("overpayment_1");
        overpayment_1->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, overpayment_1);

        total_sum_1 = new QLabel(formLayoutWidget);
        total_sum_1->setObjectName("total_sum_1");
        total_sum_1->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, total_sum_1);

        payment_1 = new QLabel(formLayoutWidget);
        payment_1->setObjectName("payment_1");
        payment_1->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, payment_1);

        payment_2 = new QLabel(formLayoutWidget);
        payment_2->setObjectName("payment_2");

        formLayout->setWidget(0, QFormLayout::FieldRole, payment_2);

        overpayment_2 = new QLabel(formLayoutWidget);
        overpayment_2->setObjectName("overpayment_2");

        formLayout->setWidget(1, QFormLayout::FieldRole, overpayment_2);

        total_sum_2 = new QLabel(formLayoutWidget);
        total_sum_2->setObjectName("total_sum_2");

        formLayout->setWidget(2, QFormLayout::FieldRole, total_sum_2);

        Credit->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Credit);
        statusbar->setObjectName("statusbar");
        Credit->setStatusBar(statusbar);

        retranslateUi(Credit);

        QMetaObject::connectSlotsByName(Credit);
    } // setupUi

    void retranslateUi(QMainWindow *Credit)
    {
        Credit->setWindowTitle(QCoreApplication::translate("Credit", "MainWindow", nullptr));
        label_3->setText(QCoreApplication::translate("Credit", "\320\237\321\200\320\276\321\206\320\265\320\275\321\202\320\275\320\260\321\217 \321\201\321\202\320\260\320\262\320\272\320\260", nullptr));
        label_6->setText(QCoreApplication::translate("Credit", "%", nullptr));
        label->setText(QCoreApplication::translate("Credit", "\320\241\321\203\320\274\320\274\320\260 \320\272\321\200\320\265\320\264\320\270\321\202\320\260", nullptr));
        label_5->setText(QCoreApplication::translate("Credit", "\342\202\275", nullptr));
        label_2->setText(QCoreApplication::translate("Credit", "\320\241\321\200\320\276\320\272", nullptr));
        label_4->setText(QCoreApplication::translate("Credit", "\320\242\320\270\320\277 \320\272\321\200\320\265\320\264\320\270\321\202\320\260", nullptr));
        credit_type_1->setText(QCoreApplication::translate("Credit", "\320\220\320\275\320\275\321\203\320\270\321\202\320\265\321\202\320\275\321\213\320\271", nullptr));
        credit_type_2->setText(QCoreApplication::translate("Credit", "\320\224\320\270\321\204\321\204\320\265\321\200\320\265\320\275\321\206\320\270\321\200\320\276\320\262\320\260\320\275\320\275\321\213\320\271", nullptr));
        label_7->setText(QCoreApplication::translate("Credit", "\320\273\320\265\321\202", nullptr));
        run_count->setText(QCoreApplication::translate("Credit", "\320\240\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        overpayment_1->setText(QString());
        total_sum_1->setText(QString());
        payment_1->setText(QString());
        payment_2->setText(QString());
        overpayment_2->setText(QString());
        total_sum_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Credit: public Ui_Credit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREDIT_H
