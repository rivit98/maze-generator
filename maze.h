#ifndef MAZE_H
#define MAZE_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QStack>
#include <QThread>
#include <QTimer>


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


    static const int width = 50;
    static const int height = 50;
    static const int speed = 25;
    Cell* grid[width][height];
    QStack<Cell *> history;
    Cell * current_cell = nullptr;
    Cell * next = nullptr;
    QTimer *timer;

};

#endif // MAZE_H
