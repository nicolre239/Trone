#include "Game.h"
#include <QTimer>
#include <QBrush>
#include <QImage>
#include "Gamemap.h"
#include <QTimer>
#include <QKeyEvent>
#include "step.h"
#include <QString>
#include <QGraphicsTextItem>
#include "Bike.h"
#include <QDebug>

Game::Game(QWidget *parent){

    this -> focusOn = 0;
    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,800); // make the scene 800x600 instead of infinity by infinity (default)
    //setBackgroundBrush(QBrush(QImage(":/images/Field.png")));

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,800);

    GameMap *sceneMap = new GameMap();
    Step * temp;

    for (int i = 0; i < 800/20; i++)
        for (int j = 0; j < 800/20; j++)
        {
            temp = new Step(0);
            temp -> setPos(i*20, j*20);
            scene -> addItem(temp);
            sceneMap -> mapViewMatrix[i][j] = temp;
        }

    // create the player1
    player1 = new Bike(0, sceneMap, 1);
    player1->setPos(0, 780); // TODO generalize to always be in the middle bottom of screen
    // make the player1 focusable and set it to be the current focus
    player1->setFlag(QGraphicsItem::ItemIsFocusable);
    // add the player1 to the scene
    scene->addItem(player1);

    // create the player2
    player2 = new Bike(0, sceneMap, 2);
    player2->setPos(0, 0); // TODO generalize to always be in the middle bottom of screen
    // make the player1 focusable and set it to be the current focus
    player2->setFlag(QGraphicsItem::ItemIsFocusable);
    // add the player1 to the scene
    scene->addItem(player2);

    scene->setFocus();

    QTimer * timer  = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(CheckIntersection()));

    timer->start(5);

    show();
}

void Game::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_W:
        case Qt::Key_A:
        case Qt::Key_S:
        case Qt::Key_D:
        player2->keyPressEvent(event);
        break;

    case Qt::Key_Left:
        case Qt::Key_Right:
        case Qt::Key_Down:
        case Qt::Key_Up:
        player1->keyPressEvent(event);
        break;
    default:
        break;
    }
}

void Game::drawPanel(int x, int y, int width, int height, QColor color, double opacity){
    // draws a panel at the specified location with the specified properties
    QGraphicsRectItem* panel = new QGraphicsRectItem(x,y,width,height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    panel->setBrush(brush);
    panel->setOpacity(opacity);
    scene->addItem(panel);
}

void Game::DisplayGameOverWindow(QString textToDisplay){
    // disable all scene items
    for (size_t i = 0, n = scene->items().size(); i < n; i++){
        scene->items()[i]->setEnabled(false);
    }


    scene->removeItem(player1);
    scene->removeItem(player2);

    // pop up semi transparent panel
    drawPanel(0,0,800,800,Qt::black,0.65);

    // draw panel
    drawPanel(200,200,400,400,Qt::lightGray,0.75);

    // create text annoucning winner
    QGraphicsTextItem* overText = new QGraphicsTextItem(textToDisplay);
    overText->setPos(375,250);
    scene->addItem(overText);

}

void Game::GameOver(short id)
{
    QString message, message2;
    message = "GAME OVER!";
    if (id == 1)
        message2 = "Player RED Wins!";
    else
        message2 = "Player VIOLET Wins!";

    message+="\n";
    message+=message2;
    DisplayGameOverWindow(message);
}

void Game::CheckIntersection()
{
    if (this->player1->mapPointer->GetEndGameFlag() != 0)
        GameOver(this->player1->mapPointer->GetEndGameFlag());
}

