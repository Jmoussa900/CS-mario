#include "monster.h"
#include <QGraphicsScene>
#include <stdlib.h> // rand() -> to generate really large integer
#include <QTimer>
#include <QDebug>

Monster::Monster(QGraphicsItem* parent) {
    QPixmap zoombie(":/images/zoombie.jpg");
    zoombie = zoombie.scaledToWidth(200);
    zoombie = zoombie.scaledToHeight(200);
    // zoombie = zoombie.scaled(200, 200, Qt::KeepAspectRatio, Qt::FastTransformation);
    setPixmap(zoombie);
    QTimer * shootTimer = new QTimer(this);
    connect(shootTimer, &QTimer::timeout, this, &Monster::shoot);
    shootTimer->start(1000);
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
}

