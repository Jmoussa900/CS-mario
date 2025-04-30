#ifndef MARIO_H
#define MARIO_H
#include <QObject>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QTimer>
#include <QList>
#include <QPixmap>
#include <QMessageBox>
#include "recobstacles.h"
using namespace std;

class Mario: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Mario(QGraphicsItem * parent=0);
    void Collision();
    void TheInfo();
    void setMario(int w, int h);
    int getHealth();
    void setHealth();
    bool getCollides();
    void setScore();
    int getWidth();
    int getHeight();
    void setWidth(int w);
    void setHeight(int h);
    int getScore();

public:
    void keyPressEvent(QKeyEvent * event);
public slots:
    void createEnemy();
    void updatePosition();
    void enemyAvoided();
signals:
    void lifeEnded();
private:
    int maxLife;
    int health;
    int width,height;
    int pos_y;
    int score;
    QGraphicsTextItem * info;
    int velocityY;
    bool isJumping;
    bool collides;
    QTimer * timer;
};

#endif // MARIO_H
