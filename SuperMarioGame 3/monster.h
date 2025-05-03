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
    void setStop();
    void timer();
private:
    QTimer * shootTimer;
    bool stop;
};



#endif // MONSTER_H
