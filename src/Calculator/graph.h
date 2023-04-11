#ifndef GRAPH_H
#define GRAPH_H

#include <QMainWindow>
#include <QtCharts>
#include <QSplineSeries>

QT_BEGIN_NAMESPACE
namespace Ui { class Graph; }
QT_END_NAMESPACE

class Graph : public QMainWindow
{
    Q_OBJECT

public:
    explicit Graph(QWidget *parent = nullptr);
    ~Graph();

signals:
    void firstWindow();

private:
    Ui::Graph *ui;
};

#endif // GRAPH_H
