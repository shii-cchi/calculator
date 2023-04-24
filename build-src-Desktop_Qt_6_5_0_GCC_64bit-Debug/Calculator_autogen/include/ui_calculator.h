/********************************************************************************
** Form generated from reading UI file 'calculator.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATOR_H
#define UI_CALCULATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *result_window;
    QPushButton *pushButton_sin;
    QPushButton *pushButton_lg;
    QPushButton *pushButton_ln;
    QPushButton *pushButton_sqrt;
    QPushButton *pushButton_bracket_1;
    QPushButton *pushButton_bracket_2;
    QPushButton *pushButton_pow;
    QPushButton *pushButton_cos;
    QPushButton *pushButton_mod;
    QPushButton *pushButton_divide;
    QPushButton *pushButton_minus;
    QPushButton *pushButton_7;
    QPushButton *pushButton_asin;
    QPushButton *pushButton_5;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_mult;
    QPushButton *pushButton_6;
    QPushButton *pushButton_tan;
    QPushButton *pushButton_4;
    QPushButton *pushButton_atan;
    QPushButton *pushButton_1;
    QPushButton *pushButton_plus;
    QPushButton *pushButton_acos;
    QPushButton *pushButton_dot;
    QPushButton *pushButton_2;
    QPushButton *pushButton_0;
    QPushButton *pushButton_unary;
    QPushButton *pushButton_equal;
    QPushButton *pushButton_3;
    QPushButton *pushButton_delete_all;
    QPushButton *pushButton_delete_1;
    QPushButton *pushButton_graph;
    QPushButton *pushButton_credit;
    QPushButton *pushButton_x;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(425, 306);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        result_window = new QLabel(centralwidget);
        result_window->setObjectName("result_window");
        result_window->setGeometry(QRect(0, 0, 425, 60));
        QFont font;
        font.setPointSize(16);
        result_window->setFont(font);
        result_window->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	qproperty-alignment: 'AlignVCenter | AlignRight';\n"
"	border-bottom: 1px solid gray;\n"
"}\n"
"\n"
"background-color: white;"));
        pushButton_sin = new QPushButton(centralwidget);
        pushButton_sin->setObjectName("pushButton_sin");
        pushButton_sin->setGeometry(QRect(0, 102, 70, 40));
        pushButton_sin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(222, 221, 218);\n"
"}"));
        pushButton_lg = new QPushButton(centralwidget);
        pushButton_lg->setObjectName("pushButton_lg");
        pushButton_lg->setGeometry(QRect(0, 61, 70, 40));
        pushButton_lg->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(222, 221, 218);\n"
"}"));
        pushButton_ln = new QPushButton(centralwidget);
        pushButton_ln->setObjectName("pushButton_ln");
        pushButton_ln->setGeometry(QRect(71, 61, 70, 40));
        pushButton_ln->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(222, 221, 218);\n"
"}"));
        pushButton_sqrt = new QPushButton(centralwidget);
        pushButton_sqrt->setObjectName("pushButton_sqrt");
        pushButton_sqrt->setGeometry(QRect(142, 61, 70, 40));
        pushButton_sqrt->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(222, 221, 218);\n"
"}"));
        pushButton_bracket_1 = new QPushButton(centralwidget);
        pushButton_bracket_1->setObjectName("pushButton_bracket_1");
        pushButton_bracket_1->setGeometry(QRect(142, 102, 70, 40));
        pushButton_bracket_1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(222, 221, 218);\n"
"}"));
        pushButton_bracket_2 = new QPushButton(centralwidget);
        pushButton_bracket_2->setObjectName("pushButton_bracket_2");
        pushButton_bracket_2->setGeometry(QRect(213, 102, 70, 40));
        pushButton_bracket_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(222, 221, 218);\n"
"}"));
        pushButton_pow = new QPushButton(centralwidget);
        pushButton_pow->setObjectName("pushButton_pow");
        pushButton_pow->setGeometry(QRect(284, 102, 70, 40));
        pushButton_pow->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(222, 221, 218);\n"
"}"));
        pushButton_cos = new QPushButton(centralwidget);
        pushButton_cos->setObjectName("pushButton_cos");
        pushButton_cos->setGeometry(QRect(0, 143, 70, 40));
        pushButton_cos->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(222, 221, 218);\n"
"}"));
        pushButton_mod = new QPushButton(centralwidget);
        pushButton_mod->setObjectName("pushButton_mod");
        pushButton_mod->setGeometry(QRect(213, 61, 70, 40));
        pushButton_mod->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(222, 221, 218);\n"
"}"));
        pushButton_divide = new QPushButton(centralwidget);
        pushButton_divide->setObjectName("pushButton_divide");
        pushButton_divide->setGeometry(QRect(355, 102, 70, 40));
        pushButton_divide->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(222, 221, 218);\n"
"}"));
        pushButton_minus = new QPushButton(centralwidget);
        pushButton_minus->setObjectName("pushButton_minus");
        pushButton_minus->setGeometry(QRect(355, 184, 70, 40));
        pushButton_minus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(222, 221, 218);\n"
"}"));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(142, 143, 70, 40));
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(246, 245, 244);\n"
"}"));
        pushButton_asin = new QPushButton(centralwidget);
        pushButton_asin->setObjectName("pushButton_asin");
        pushButton_asin->setGeometry(QRect(71, 102, 70, 40));
        pushButton_asin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(222, 221, 218);\n"
"}"));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(213, 184, 70, 40));
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(246, 245, 244);\n"
"}"));
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(213, 143, 70, 40));
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(246, 245, 244);\n"
"}"));
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(284, 143, 70, 40));
        pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(246, 245, 244);\n"
"}"));
        pushButton_mult = new QPushButton(centralwidget);
        pushButton_mult->setObjectName("pushButton_mult");
        pushButton_mult->setGeometry(QRect(355, 143, 70, 40));
        pushButton_mult->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(222, 221, 218);\n"
"}"));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(284, 184, 70, 40));
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(246, 245, 244);\n"
"}"));
        pushButton_tan = new QPushButton(centralwidget);
        pushButton_tan->setObjectName("pushButton_tan");
        pushButton_tan->setGeometry(QRect(0, 184, 70, 40));
        pushButton_tan->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(222, 221, 218);\n"
"}"));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(142, 184, 70, 40));
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(246, 245, 244);\n"
"}"));
        pushButton_atan = new QPushButton(centralwidget);
        pushButton_atan->setObjectName("pushButton_atan");
        pushButton_atan->setGeometry(QRect(71, 184, 70, 40));
        pushButton_atan->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(222, 221, 218);\n"
"}"));
        pushButton_1 = new QPushButton(centralwidget);
        pushButton_1->setObjectName("pushButton_1");
        pushButton_1->setGeometry(QRect(142, 225, 70, 40));
        pushButton_1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(246, 245, 244);\n"
"}"));
        pushButton_plus = new QPushButton(centralwidget);
        pushButton_plus->setObjectName("pushButton_plus");
        pushButton_plus->setGeometry(QRect(355, 225, 70, 40));
        pushButton_plus->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(222, 221, 218);\n"
"}"));
        pushButton_acos = new QPushButton(centralwidget);
        pushButton_acos->setObjectName("pushButton_acos");
        pushButton_acos->setGeometry(QRect(71, 143, 70, 40));
        pushButton_acos->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(222, 221, 218);\n"
"}"));
        pushButton_dot = new QPushButton(centralwidget);
        pushButton_dot->setObjectName("pushButton_dot");
        pushButton_dot->setGeometry(QRect(284, 266, 70, 40));
        pushButton_dot->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(222, 221, 218);\n"
"}"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(213, 225, 70, 40));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(246, 245, 244);\n"
"}"));
        pushButton_0 = new QPushButton(centralwidget);
        pushButton_0->setObjectName("pushButton_0");
        pushButton_0->setGeometry(QRect(213, 266, 70, 40));
        pushButton_0->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(246, 245, 244);\n"
"}"));
        pushButton_unary = new QPushButton(centralwidget);
        pushButton_unary->setObjectName("pushButton_unary");
        pushButton_unary->setGeometry(QRect(142, 266, 70, 40));
        pushButton_unary->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(222, 221, 218);\n"
"}"));
        pushButton_equal = new QPushButton(centralwidget);
        pushButton_equal->setObjectName("pushButton_equal");
        pushButton_equal->setGeometry(QRect(355, 266, 70, 40));
        pushButton_equal->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: white;\n"
"	background-color: rgb(51, 209, 122);\n"
"}"));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(284, 225, 70, 40));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(246, 245, 244);\n"
"}"));
        pushButton_delete_all = new QPushButton(centralwidget);
        pushButton_delete_all->setObjectName("pushButton_delete_all");
        pushButton_delete_all->setGeometry(QRect(284, 61, 70, 40));
        pushButton_delete_all->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: white;\n"
"	background-color: rgb(231, 8, 8);\n"
"}"));
        pushButton_delete_1 = new QPushButton(centralwidget);
        pushButton_delete_1->setObjectName("pushButton_delete_1");
        pushButton_delete_1->setGeometry(QRect(355, 61, 70, 40));
        pushButton_delete_1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: white;\n"
"	background-color: rgb(231, 8, 8);\n"
"}"));
        pushButton_graph = new QPushButton(centralwidget);
        pushButton_graph->setObjectName("pushButton_graph");
        pushButton_graph->setGeometry(QRect(71, 225, 70, 40));
        pushButton_graph->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(222, 221, 218);\n"
"}"));
        pushButton_credit = new QPushButton(centralwidget);
        pushButton_credit->setObjectName("pushButton_credit");
        pushButton_credit->setGeometry(QRect(0, 266, 141, 40));
        pushButton_credit->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: white;\n"
"	background-color: rgb(53, 132, 228);\n"
"}"));
        pushButton_x = new QPushButton(centralwidget);
        pushButton_x->setObjectName("pushButton_x");
        pushButton_x->setGeometry(QRect(0, 225, 70, 40));
        pushButton_x->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(222, 221, 218);\n"
"}"));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        result_window->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_sin->setText(QCoreApplication::translate("MainWindow", "sin", nullptr));
        pushButton_lg->setText(QCoreApplication::translate("MainWindow", "log", nullptr));
        pushButton_ln->setText(QCoreApplication::translate("MainWindow", "ln", nullptr));
        pushButton_sqrt->setText(QCoreApplication::translate("MainWindow", "sqrt", nullptr));
        pushButton_bracket_1->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        pushButton_bracket_2->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
        pushButton_pow->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
        pushButton_cos->setText(QCoreApplication::translate("MainWindow", "cos", nullptr));
        pushButton_mod->setText(QCoreApplication::translate("MainWindow", "mod", nullptr));
        pushButton_divide->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        pushButton_minus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        pushButton_asin->setText(QCoreApplication::translate("MainWindow", "asin", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        pushButton_mult->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        pushButton_tan->setText(QCoreApplication::translate("MainWindow", "tan", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        pushButton_atan->setText(QCoreApplication::translate("MainWindow", "atan", nullptr));
        pushButton_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pushButton_plus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        pushButton_acos->setText(QCoreApplication::translate("MainWindow", "acos", nullptr));
        pushButton_dot->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        pushButton_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_unary->setText(QCoreApplication::translate("MainWindow", "+/-", nullptr));
        pushButton_equal->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        pushButton_delete_all->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        pushButton_delete_1->setText(QCoreApplication::translate("MainWindow", "<-", nullptr));
        pushButton_graph->setText(QCoreApplication::translate("MainWindow", "graph", nullptr));
        pushButton_credit->setText(QCoreApplication::translate("MainWindow", "credit", nullptr));
        pushButton_x->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATOR_H
