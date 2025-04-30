#ifndef RECOBSTACLES_H
#define RECOBSTACLES_H
#include <QGraphicsRectItem>
#include <QObject>
#include <iostream>
using namespace std;


class RecObstacles: public QObject , public QGraphicsRectItem
{ Q_OBJECT
public:
    RecObstacles(QGraphicsItem* parent = 0);

public slots:
    void move();
signals:
    void avoided();
};
#endif // RECOBSTACLES_H
