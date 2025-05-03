#include "recobstacles.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>

RecObstacles::RecObstacles(QGraphicsItem* parent) {
    //   Setting the size of the obstacles
    setRect(0,0,50,50);
    QPen redPen(Qt::red);
    redPen.setWidth(3);
    QBrush redBrush(Qt::red);
    setPen(redPen);
    setBrush(redBrush);

    //  Setting the postion of the obstacles within the view dimensions
    setPos(800,455);

    //   Moving the obstacle to the left automatically every 20 milli second
   QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT (move()));
    timer->start(20);
}

//void RecObstacles::stop()
//{
  //  timer->stop();
//}

// Function move: move the obstacle from right to left until it gets out of frame it is deleted
/*void RecObstacles:: move()
{
    setPos(x()-5,y());
    if(x() + rect().width() < 0)//from chatgpt because i did not know the conidition to make them come properly
    {
        scene()->removeItem(this);
        delete this;
    }
}*/

void RecObstacles::move() {
    setPos(x() - 5, y());

    if (x() + rect().width() < 0) {
        emit avoided();  // enemy passed Mario without collision
        scene()->removeItem(this);
        delete this;
    }
}


