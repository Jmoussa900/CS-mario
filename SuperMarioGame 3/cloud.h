#ifndef CLOUDOBSTACLE_H
#define CLOUDOBSTACLE_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>

class Cloud : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
     Cloud(QGraphicsItem *parent = nullptr);

public slots:
    void spawnFallingItem();

private:
    QTimer* spawnTimer;
};

#endif

