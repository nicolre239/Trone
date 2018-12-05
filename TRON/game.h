#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QObject>
#include "Bike.h"
#include <QString>

class Game: public QGraphicsView{
Q_OBJECT
private:
    bool focusOn;
public:
    Game(QWidget * parent=0);
    void keyPressEvent(QKeyEvent * event);
    QGraphicsScene * scene;
    Bike * player1;
    Bike * player2;
    void DisplayGameOverWindow(QString str);
    void drawPanel(int x, int y, int width, int height, QColor color, double opacity);

    void GameOver(short id);
public slots:
    void CheckIntersection();
};

#endif
