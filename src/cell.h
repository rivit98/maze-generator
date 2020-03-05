#pragma once

#include <QGraphicsLineItem>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QGraphicsRectItem>


class Cell
{
private:
    bool visited;
    int idx;
    int idy;
public:
    static const int size = 14;
    QGraphicsLineItem *w; //up
    QGraphicsLineItem *d; //right
    QGraphicsLineItem *s; //down
    QGraphicsLineItem *a; //left
    QGraphicsRectItem *rect;


    Cell(int x, int y, QGraphicsScene *s);
    bool isVisited() const;
    void setVisited();
    void getIndexes(int &, int &) const;
    void mark();
    void unmark();
};
