#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <QObject>
#include "step.h"

class GameMap:public QObject
{
    Q_OBJECT
private:
    bool mapMatrix[40][40];
    short endGameFlag;
public:
    Step * mapViewMatrix[40][40];
    GameMap();
    void setPixel(int x, int y, short direction, short id);
    Step *GetMapView(int x, int y);
    short GetEndGameFlag();
};

#endif
