#ifndef GRAPH_H
#define GRAPH_H

#include <QMainWindow>

namespace Ui {
class Graph;
}

class Graph : public QMainWindow
{
    Q_OBJECT

public:
    explicit Graph(QWidget *parent = nullptr);
    ~Graph();

private:
    Ui::Graph *ui;
};

#endif // GRAPH_H
