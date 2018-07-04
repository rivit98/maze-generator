#ifndef CELL_H
#define CELL_H

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
    static const int size = 15;
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

#endif // CELL_H
