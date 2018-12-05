#ifndef BIKE_H
#define BIKE_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include "Gamemap.h"

class Bike:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int direction = 6;
    short id;
    QGraphicsScene * scene;

public:
    GameMap * mapPointer;
    Bike(QGraphicsScene* parent=0, GameMap* mapPointer=0, short id=0);
    void keyPressEvent(QKeyEvent * event);
public slots:
    void Move();
};

#endif
