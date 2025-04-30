#include"bullet.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QList>
Bullet::Bullet() {
    // *******  Setting the bullets' size ********
    setRect(0,0,10,20);
    QPen blackPen(Qt::black);
    blackPen.setWidth(3);
    QBrush blackBrush(Qt::black);
    setPen(blackPen);
    setBrush(blackBrush);

    // *******  Moves the Bullets automatically ********
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT (move()));
    timer->start(50);
}

// Move function is used to 1-  move the bullet upwards
// 2- Handle the collision of the bullets with enemies
void Bullet:: move()
{
    if(!scene()){
        deleteLater();
        return;
    }//chatgpt

    QList<QGraphicsItem *> colliding_items = collidingItems();

    for (QGraphicsItem *item : colliding_items) {
        Mario *enemy = dynamic_cast<Mario *>(item);
        if(!item){continue;}//chatgpt
        while ((enemy) && (enemy->getHealth()>0)) {
            enemy->setScore();
            scene()->removeItem(this);
            enemy->setHeight(enemy->getHeight()/2);
            enemy->setWidth(enemy->getWidth()/2);
            enemy->setMario((enemy->getWidth()),(enemy->getHeight()));
            enemy->setHealth();
            this->deleteLater();// from chatgpt
            break;
            qDebug() << "Bullet hit something, deleting...";
        }
        if(enemy->getHealth()<1){

            enemy->emit lifeEnded();
        }
    }
    // if there was no collision with an Enemy, move the bullet to the left
    setPos(x()-10,y());
    // if the bullet is off the screen, destroy it
    if (pos().x() < 0){
        scene()->removeItem(this);
        this->deleteLater();
    }
}
