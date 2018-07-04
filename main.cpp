#include <QApplication>
#include "maze.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Maze * m = new Maze();
    m->show();

    return a.exec();
}
