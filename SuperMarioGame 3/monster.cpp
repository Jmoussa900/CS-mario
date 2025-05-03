#include "monster.h"
#include <QGraphicsScene>
#include <stdlib.h> // rand() -> to generate really large integer
#include <QDebug>

Monster::Monster(QGraphicsItem* parent) {
    QPixmap zoombie(":/images/zoombie.jpg");
    zoombie = zoombie.scaledToWidth(200);
    zoombie = zoombie.scaledToHeight(200);
    // zoombie = zoombie.scaled(200, 200, Qt::KeepAspectRatio, Qt::FastTransformation);
    setPixmap(zoombie);
    stop=false;
    shootTimer = new QTimer(this);
    //  QTimer * collisioncheck = new QTimer(this);
    //  connect(collisioncheck, &QTimer::timeout, this, &Enemy::collision);
    //    collisioncheck->start(50);
    // Check for collision every 50ms

}

void Monster::shoot()
{
    Bullet* bullet = new Bullet();
    int x= 370 +rand()%101;
    bullet->setPos(500, x);
    scene()->addItem(bullet);
    if(stop){
        shootTimer->stop();
        scene()->removeItem(bullet);
    }
}

void Monster::setStop()
{
    stop=true;
}

void Monster::timer()
{
    connect(shootTimer, &QTimer::timeout, this, &Monster::shoot);
    shootTimer->start(1000);
}
