#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsScene>
#include <QDebug>

#include "mario.h"

class Bullet: public QObject, public QGraphicsRectItem
{

    Q_OBJECT
public:
    Bullet();

public slots:
    void move();
private:
};

#endif // BULLET_H
