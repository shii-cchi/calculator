/********************************************************************************
** Form generated from reading UI file 'graph.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPH_H
#define UI_GRAPH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Graph
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Graph)
    {
        if (Graph->objectName().isEmpty())
            Graph->setObjectName("Graph");
        Graph->resize(800, 600);
        centralwidget = new QWidget(Graph);
        centralwidget->setObjectName("centralwidget");
        Graph->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Graph);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        Graph->setMenuBar(menubar);
        statusbar = new QStatusBar(Graph);
        statusbar->setObjectName("statusbar");
        Graph->setStatusBar(statusbar);

        retranslateUi(Graph);

        QMetaObject::connectSlotsByName(Graph);
    } // setupUi

    void retranslateUi(QMainWindow *Graph)
    {
        Graph->setWindowTitle(QCoreApplication::translate("Graph", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Graph: public Ui_Graph {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPH_H
