#include "maze.h"
#include <QDebug>
#include <QTime>

Maze::Maze() : QGraphicsView()
{
    qsrand(QTime::currentTime().msec());

    const int pixels = Cell::size;
    QGraphicsScene *s = new QGraphicsScene();
    s->setSceneRect(0, 0, width*pixels, height*pixels);
    s->setBackgroundBrush(QBrush(QColor(161, 171, 186), Qt::SolidPattern));
    setScene(s);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(width*pixels, height*pixels);

    //setup grid and prepare first cell
    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            grid[i][j] = new Cell(i, j, s);
        }
    }

    current_cell = grid[0][0];
    current_cell->setVisited();
    current_cell->mark();
    history.push(current_cell);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(generate()));
    timer->start(speed);
}

void Maze::generate()
{
    next = getFreeNeighbour(current_cell);
    if(next != nullptr)
    {
        current_cell->unmark();
        next->mark();
        history.push(next);
        next->setVisited();
        removeWalls(current_cell, next);
        current_cell = next;
    }
    else if(!history.isEmpty())
    {
        //backtracing
        current_cell->unmark();
        current_cell = history.pop();
        current_cell->mark();
    }
    else if(history.isEmpty())
    {
        //end
        timer->stop();
        current_cell->unmark();
    }
}

void Maze::removeWalls(Cell * c, Cell *n)
{
    int cx, cy, nx, ny;
    c->getIndexes(cx, cy);
    n->getIndexes(nx, ny);

    switch(cx-nx)
    {
    case 1:
        c->a->hide();
        n->d->hide();
        //scene()->removeItem(n->d);
        //scene()->removeItem(c->a);
        break;
    case -1:
        c->d->hide();
        n->a->hide();
        /*remove*/
        //scene()->removeItem(c->d);
        //scene()->removeItem(n->a);
        break;
    }

    switch(cy-ny)
    {
    case 1:
        c->w->hide();
        n->s->hide();
        //scene()->removeItem(c->w);
        //scene()->removeItem(n->s);
        break;
    case -1:
        c->s->hide();
        n->w->hide();
        //scene()->removeItem(c->s);
        //scene()->removeItem(n->w);
        break;
    }
}

Cell * Maze::getFreeNeighbour(Cell * curr)
{
    int curX, curY;
    QVector<Cell *> available;
    curr->getIndexes(curX, curY);

    if(curX > 0 && !grid[curX-1][curY]->isVisited()) //left
    {
        available.push_back(grid[curX-1][curY]);
    }
    if(curX < width-1 && !grid[curX+1][curY]->isVisited()) // right
    {
        available.push_back(grid[curX+1][curY]);
    }
    if(curY > 0 && !grid[curX][curY-1]->isVisited())
    {
        available.push_back(grid[curX][curY-1]);
    }
    if(curY < height-1 && !grid[curX][curY+1]->isVisited())
    {
        available.push_back(grid[curX][curY+1]);
    }

    int len = available.size();
    if(len)
    {
        return available[qrand() % len];
    }

    return nullptr;
}
