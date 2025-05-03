/*#include "cloud.h"

cloud::cloud() {}*/
#include "Cloud.h"
#include "fallitem.h"
#include <QGraphicsScene>
#include <QDebug>

Cloud::Cloud(QGraphicsItem *parent)
    : QObject(), QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/cloud.jpg").scaled(100, 60));
    setPos(100, 300);  // Position at top of scene

    spawnTimer = new QTimer(this);
    connect(spawnTimer, &QTimer::timeout, this, &Cloud::spawnFallingItem);
    spawnTimer->start(2000); // Spawn every 2 seconds
}

void Cloud::spawnFallingItem()
{
    FallingItem* item = new FallingItem();
    // Position below the cloud, randomize horizontal position a bit
    int offsetX = rand() % static_cast<int>(boundingRect().width());
    item->setPos(x() + offsetX, y() + boundingRect().height());

    if (scene()) {
        scene()->addItem(item);
    } else {
        qDebug() << "CloudObstacle not in scene yet!";
        delete item;
    }
}
