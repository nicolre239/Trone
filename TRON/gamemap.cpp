#include "Gamemap.h"
#include <QDebug>
#include "step.h"

GameMap::GameMap()
{
    endGameFlag = 0;
    for (int i = 0; i < 800/20; i++)
        for (int j = 0; j < 800/20; j++)
        {
            this -> mapMatrix[i][j] = 0;
            this -> mapViewMatrix[i][j] = new Step(0);
            qDebug()<<i<<"+"<<j<<"="<<mapViewMatrix[i][j]->id;
        }
}

void GameMap::setPixel(int x, int y, short direction, short id)
{
    if (this -> mapMatrix[x][y] == 1)
    {
        endGameFlag = id;
        return;
    }

    this -> mapMatrix[x][y] = 1;
    if (id == 1)
     this -> mapViewMatrix[x][y]->setPixmap(QPixmap(":/images/Player1.png"));
    else if (id == 2)
       this -> mapViewMatrix[x][y]->setPixmap(QPixmap(":/images/Player2.png"));
    else
        this -> mapViewMatrix[x][y]->setPixmap(QPixmap(":/images/Field.png"));
}

Step* GameMap::GetMapView(int x, int y)
{
    return this->mapViewMatrix[x][y];
}

short GameMap::GetEndGameFlag()
{
    return endGameFlag;
}


