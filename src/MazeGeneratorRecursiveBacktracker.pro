TEMPLATE = app
TARGET = maze

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


HEADERS += \
    cell.h \
    maze.h

SOURCES += \
    cell.cpp \
    main.cpp \
    maze.cpp
