#include "Bike.h"
#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>
#include <step.h>
#include "Gamemap.h"
#include <QDebug>

Bike::Bike(QGraphicsScene *parent, GameMap *mapPointer, short id){

    if (id == 1)
        setPixmap(QPixmap(":/images/Player1.png"));
    else
        setPixmap(QPixmap(":/images/Player2.png"));

    this -> mapPointer = mapPointer;
    this -> id = id;
    this -> scene = parent;

    QTimer * timer  = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(Move()));

    timer->start(150);
}

void Bike::keyPressEvent(QKeyEvent *event)
{
    if (this->id == 1)
    switch (event->key())
    {
    case Qt::Key_Left:
        this->direction = 4;
        break;

    case Qt::Key_Right:
        this->direction = 6;
        break;

    case Qt::Key_Down:
        this->direction = 2;
        break;

    case Qt::Key_Up:
        this->direction = 8;
        break;
    }

    else if (this->id == 2)
    switch (event->key())
    {
    case Qt::Key_A:
        this->direction = 4;
        break;

    case Qt::Key_D:
        this->direction = 6;
        break;

    case Qt::Key_S:
        this->direction = 2;
        break;

    case Qt::Key_W:
        this->direction = 8;
        break;
    }

}

void Bike::Move()
{
    switch(this->direction)
    {
    case 4:
        if (pos().x() > 0)
        setPos(x() - 20, y());
        break;

    case 6:
        if (pos().x() + 20 < 800)
        setPos(x() + 20, y());
        break;

    case 2:
        if (pos().y() + 20 < 800)
        setPos(x(), y() + 20);
        break;

    case 8:
        if (pos().y() > 0)
        setPos(x(), y() - 20);
        break;

    }

    this -> mapPointer -> setPixel(x()/20, y()/20, this -> direction, this->id);

}
