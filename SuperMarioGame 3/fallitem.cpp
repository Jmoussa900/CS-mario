/*#include "fallitem.h"

fallitem::fallitem() {}*/
#include "fallitem.h"
#include "Mario.h"
#include <QGraphicsScene>
#include <QList>
#include <QDebug>

FallingItem::FallingItem(QGraphicsItem *parent)
    : QObject(), QGraphicsPixmapItem(parent), speed(5)
{
    setPixmap(QPixmap(":/images/obstacle.png").scaled(30, 30));
}

void FallingItem::advance(int step)
{
    if (!step)
        return;

    setPos(x(), y() + speed);

    // Remove if out of scene bounds
    if (scene() && y() > scene()->height()) {
        scene()->removeItem(this);
        delete this;
        return;
    }

    // Check collision with Mario
    QList<QGraphicsItem*> colliding = collidingItems();
    for (QGraphicsItem* item : colliding) {
        Mario* mario = dynamic_cast<Mario*>(item);
        if (mario) {
            mario->setHealth(); // Decrease Mario's health
            scene()->removeItem(this);
            delete this;
            break;
        }
    }
}

