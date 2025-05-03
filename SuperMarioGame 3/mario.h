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
    void setScore();
    int getWidth();
    int getHeight();
    int getScore();

public:
    void keyPressEvent(QKeyEvent * event);
public slots:
    void createEnemy();
    void updatePosition();
    void enemyAvoided();
    void setLevel(int l);
signals:
    void lifeEnded();
private:
    int maxLife;
    int health;
    int level;
    int width,height;
    int pos_y;
    int score;
    QGraphicsTextItem * info;
    int velocityY;
    bool isJumping;
    QTimer * timer;
};

#endif // MARIO_H
