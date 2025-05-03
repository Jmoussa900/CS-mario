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

/*void Monster::shoot()
{
    Bullet* bullet = new Bullet();
    int x= 370 +rand()%101;
    bullet->setPos(500, x);
<<<<<<< HEAD
    //scene()->addItem(bullet);

}*/
void Monster::shoot()
{
    Bullet* bullet = new Bullet();
    int x = 370 + rand() % 101;
    bullet->setPos(500, x);

    if (scene()) {
        scene()->addItem(bullet);
    } else {
        qDebug() << "Error: Monster::shoot() called but Monster is not in a scene.";
        delete bullet;  // Prevent memory leak
    }
=======
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
>>>>>>> 9ee38dd145faba01f671c790d3caae48ab2e1d3c
}

