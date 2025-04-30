#ifndef MONSTER_H
#define MONSTER_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include "bullet.h"
#include <QTimer>
class Monster: public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Monster(QGraphicsItem* parent = 0);
    void shoot();

};



#endif // MONSTER_H
