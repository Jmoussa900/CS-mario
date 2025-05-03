#include "Mario.h"
Mario::Mario(QGraphicsItem * parent) {
    width=100;
    height=100;
    level=1;
    pos_y=400;
    maxLife=5;
    health=3;
    score=0;
    velocityY=-15;
    isJumping=false;

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Mario::updatePosition);
    timer->start(25);  }

void Mario::TheInfo(){    //Function that provides all of the info about mario
    if(info){
        scene()->removeItem(info);
        delete info;
    }
    info=new QGraphicsTextItem;
    info->setFont(QFont("times",25));
    info->setDefaultTextColor(Qt::black);
    info->setPlainText("Health: "+QString::number(health)+ "   Life: "+QString::number(maxLife)+"   Level: "+QString::number(level)+"   Score: "+QString::number(score));
    info->setPos(350,50);
    scene()->addItem(info);
}

void Mario::setMario(int w, int h) //function that creates and changes the size of mario
{
    QPixmap mario(":/images/New Super Mario Bros_ 2 art.jpg");
    mario = mario.scaledToWidth(w);
    mario = mario.scaledToHeight(h);
    setPixmap(mario);
    setPos(x(),pos_y); //returns mario right where he was hit regardless where the scene is
}


void Mario::Collision(){ //function that checks for the collision between mario and the obstacles
    QList<QGraphicsItem *> collidedItems = collidingItems();
    for (QGraphicsItem *item : collidedItems) {
        RecObstacles *enemy = dynamic_cast<RecObstacles *>(item);
        if (enemy) {
            // Remove and delete the obstacles from scene so mario does not hit it again
            scene()->removeItem(enemy);
            delete enemy;
            score-=10;
            setHealth();
            return;
           // if (health <= 0) {
             //   maxLife--;
               // if (maxLife<= 0) {
                    // GameOver
                 //   QMessageBox::information(nullptr,"END","Game Over!!! Try again later");
                  //  QTimer::singleShot(200, qApp, &QCoreApplication::quit);
                   // return;}


                //else
               // {
                 //   emit lifeEnded();
                    //QMessageBox::information(nullptr,"End of Level", "Level was not finished successfully \nFinal Score: " + QString::number(score));
                   // }

                    //QTimer::singleShot(200, qApp, &QCoreApplication::quit);  // Quit after 3 seconds
                    //return;
                   // }
        }
        break;
    }
        }



void Mario::keyPressEvent(QKeyEvent *event)
{
    //  Event Handling for mario
    if(event->key()== Qt::Key_Left)
    {
        if(x()>0) // to prevent mario from getting out of the screen
        {
            setPos(x()-30,y());
        }
    }
    else if(event->key()== Qt::Key_Right)

    { if(x()+100<800) // to prevent mario from getting out of the screen
            setPos(x()+30,y());

    }
    else if(event->key()== Qt::Key_Up)
    {
        if(y()>0) //This prevents from jumping completely out of screen
        {isJumping = true;
            velocityY = -15;}
    }

}

void Mario::enemyAvoided() { //increase the score anytime mario passes an obstacle successfully
    score += 10;
    info->setPlainText("Health: " + QString::number(health) +
                       "   Life: " + QString::number(maxLife) +
                      "   Level: 1" +
                      "   Score: " + QString::number(score));
}

void Mario::setLevel(int l)
{
    level=l;
    TheInfo();
}

void Mario::updatePosition() {
//Apply the idea that mario should move up and come back to its initial position
    if (isJumping) {
        setPos(x(), y() + velocityY);
        velocityY += 1;  // Gravity pulls mario back down

        // Check if player has landed back on the ground
        if (y() >= 400) {
            setPos(x(), 400);
            isJumping = false;
            velocityY = 0;
        }
    }

    Collision();
}


void Mario::setScore()
{
    score-=100;
    pos_y+=30;
    TheInfo();
}

int Mario::getWidth()
{
    return width;
}
int Mario::getHeight(){
    return height;
}

int Mario::getScore()
{
    return score;
}

int Mario::getHealth()
{
    return health;
}

void Mario::setHealth()
{
    if(health>=1){
        health--;
        pos_y+=20;
        width *= 0.8;
        height *= 0.8;
        setMario(width,height);
        TheInfo();
    }
    if(health==0){
        health = 3;  // Reset health
        maxLife--;   // Decrease total lives
        TheInfo();
        width=100;
        height=100;
        pos_y=400;
        setMario(width,height);
        emit lifeEnded();}

    if (maxLife == 0) {
        QMessageBox::information(nullptr,"END","Game Over!!! Try again later");
        QTimer::singleShot(200, qApp, &QCoreApplication::quit);
    }
}
//CreateEnemy function used to create the obstacles
/*void Mario::createEnemy()
{ RecObstacles* enemy = new RecObstacles();
    scene()->addItem(enemy);
}*/

void Mario::createEnemy() {
    RecObstacles* enemy = new RecObstacles();
    connect(enemy, &RecObstacles::avoided, this, &Mario::enemyAvoided);  // connect the signal
    scene()->addItem(enemy);
}


