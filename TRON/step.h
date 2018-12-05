#ifndef STEP_H
#define STEP_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Step:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Step(int id = 0);
    int id;
};

#endif
