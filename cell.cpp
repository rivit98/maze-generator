#include "cell.h"
#include <QPainter>
#include <QDebug>

Cell::Cell(int x, int y, QGraphicsScene *scene)
{
    visited = false;
    idx = x;
    idy = y;
    x *= size;
    y *= size;

    rect = new QGraphicsRectItem(x,y,size,size); //for marking
    rect->setBrush(QBrush(QColor(255, 0, 0), Qt::SolidPattern));
    rect->setPen(Qt::NoPen);
    rect->hide();

    w = new QGraphicsLineItem (x, y, x+size, y);
    d = new QGraphicsLineItem (x+size, y, x+size, y+size);
    s = new QGraphicsLineItem (x, y+size, x+size, y+size);
    a = new QGraphicsLineItem (x, y, x, y+size);

    scene->addItem(w);
    scene->addItem(s);
    scene->addItem(a);
    scene->addItem(d);
    scene->addItem(rect);
}

bool Cell::isVisited() const
{
    return visited;
}

void Cell::setVisited()
{
    visited = true;
}

void Cell::getIndexes(int & x, int & y) const
{
    x = idx;
    y = idy;
}

void Cell::mark()
{
    rect->show();
}

void Cell::unmark()
{
    rect->hide();
}

