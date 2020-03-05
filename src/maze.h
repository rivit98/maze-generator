#pragma once

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QStack>
#include <QThread>
#include <QTimer>
#include <QTime>

#include "cell.h"


class Maze : public QGraphicsView
{
    Q_OBJECT
public slots:
    void generate();

public:
    Maze();
    Cell * getFreeNeighbour(Cell * curr);
    void removeWalls(Cell * c, Cell *n);


    static const int width = 120;
    static const int height = 60;
    static const int speed = 20;
    Cell* grid[width][height];
    QStack<Cell *> history;
    Cell * current_cell = nullptr;
    Cell * next = nullptr;
    QTimer *timer;

};
