#include "Game.h"

Game::Game(QWidget *parent){
    //Created Scene
    scene=new QGraphicsScene();
    scene->setSceneRect(0, 0, 800, 600);
    setFixedSize(800,600);
    setScene(scene);
    //Put the background picture of the game & stopped the scrolling option
    QPixmap backgroundImage(":/images/background.png");
    backgroundImage = backgroundImage.scaled(scene->width(), scene->height(),
                                             Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    scene->setBackgroundBrush(backgroundImage);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    level=1;
    //created the player and put focus on it so the buttons can control it
    mario = new Mario();
    mario->setMario(100,100);
    scene->addItem(mario);
    mario->setFlag(QGraphicsItem::ItemIsFocusable);
    mario->setFocus();
    mario->TheInfo();
    createObstacle(1);
    //created a timer that runs every 3000 millisecond to release the obstacles
    obstacleTimer = new QTimer();
    connect(obstacleTimer, &QTimer::timeout, this, [this]() {
        this->createObstacle(level);
    });
    obstacleTimer->start(3000);

    connect(mario, SIGNAL(lifeEnded()),
                this, SLOT(levelEnded()));

    levelTimer = new QTimer(this);
    connect(levelTimer, &QTimer::timeout, this, &Game::checkLevelCompletion);
    levelTimer->start(50000);

    if(mario->getCollides()){
        scene->clear();
        QCoreApplication::quit();
        qApp->exit();
    }
    zoombie=new Monster();
    //zoombie->setPos(550, 300);
    //scene->addItem(zoombie);
    //zoombie->setZValue(10);

};

void Game::keyPressEvent(QKeyEvent *event) {
    mario->keyPressEvent(event); // Let Mario handle movement
    centerOn(mario);             // Center view to Mario

    scene->setSceneRect(mario->x() - 100, 0, 800, 600); //This moves the scene instead of moving mario
}


void Game::endGame()
{
    QMessageBox::information(nullptr,"END","Game Over!!! Try again later");
    Game();
}



void Game::levelEnded()
{
    QMessageBox::information(nullptr,"End of Level", "Level was not finished successfully \nTry again");
    mario->setMario(100,100);
    mario->TheInfo();
    levelTimer->start(50000);
}

void Game::checkLevelCompletion()
{
    if(mario->getHealth()>0){
        nextLevel();
    }
    levelTimer->stop();     // Stop the timer until next level starts

}

void Game::createObstacle(int num)
{
    if(num==1){
        mario->createEnemy();
    }
    if(num==2 && zoombie){
        scene->addItem(zoombie);
        zoombie->setPos(550, 300);
        zoombie->setZValue(10);
    }
}

void Game::nextLevel()
{
    QMessageBox::information(nullptr,"Congrtulations", "You have successfully finished Level "+ QString::number(level++) +" \nThe next Level will open now \n Score: "+QString::number(mario->getScore()));
    levelTimer->start(50000);//reset the timer for the next level
    connect(obstacleTimer, &QTimer::timeout, this, [this]() {
                            this->createObstacle(level);
                             });
}

Game::~Game()
{
    delete zoombie;
    delete mario;
}


