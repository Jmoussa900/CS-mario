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
    //mario->TheInfo();
    mario->setMario(100,100);
    scene->addItem(mario);
    mario->setFlag(QGraphicsItem::ItemIsFocusable);
    mario->setFocus();
    mario->TheInfo();
<<<<<<< HEAD
    Cloud* cloud = new Cloud();
    scene->addItem(cloud);
    createObstacle(1);
=======
    //createObstacle(level);
>>>>>>> 9ee38dd145faba01f671c790d3caae48ab2e1d3c
    //created a timer that runs every 3000 millisecond to release the obstacles
    obstacleTimer = new QTimer();
    disconnect(obstacleTimer, &QTimer::timeout, nullptr, nullptr);
    connect(obstacleTimer, &QTimer::timeout, this, [this]() {
        this->createObstacle(level);


    });
    obstacleTimer->start(3000);

    connect(mario, SIGNAL(lifeEnded()),
                this, SLOT(levelEnded()));

    levelTimer = new QTimer(this);
    connect(levelTimer, &QTimer::timeout, this, &Game::checkLevelCompletion);
    levelTimer->start(20000);



<<<<<<< HEAD
    /*if(mario->getCollides()){
        scene->clear();
        QCoreApplication::quit();
        qApp->exit();
    }*/

    zoombie = new Monster();
    scene->addItem(zoombie);
=======
    zoombie=new Monster();
>>>>>>> 9ee38dd145faba01f671c790d3caae48ab2e1d3c
    //zoombie->setPos(550, 300);
    //scene->addItem(zoombie);
    //zoombie->setZValue(10);

};

void Game::keyPressEvent(QKeyEvent *event) {  //Make the info boc move with the health
    mario->keyPressEvent(event); // Let Mario handle movement
    centerOn(mario);             // Center view to Mario

    scene->setSceneRect(mario->x() - 100, 0, 800, 600); //This moves the scene instead of moving mario
}


<<<<<<< HEAD
void Game::endGame()
{
    QMessageBox::information(nullptr,"END","Game Over!!! Try again later");
    //Game();
    qApp->quit();
}
=======
//void Game::endGame()
//{
  //  QMessageBox::information(nullptr,"END","Game Over!!! Try again later");
  //  Game();
//}
>>>>>>> 9ee38dd145faba01f671c790d3caae48ab2e1d3c



void Game::levelEnded()
{
    emptyScene();
    QMessageBox::information(nullptr,"End of Level", "Level was not finished successfully \nTry again");
    mario->setMario(100,100);
    mario->TheInfo();
    levelTimer->start(20000);
}

void Game::checkLevelCompletion()
{
    if(mario->getHealth()>0){
        nextLevel();
    }
 // levelTimer->stop();     // Stop the timer until next level starts
}

void Game::createObstacle(int num)
{
    if(num==1){
        mario->createEnemy();
    }
  else  if(num==2 && zoombie){
        scene->addItem(zoombie);
        zoombie->setPos(550,300);
        zoombie->setZValue(10);
        zoombie->timer();
    }
   else if(num==3){
        QMessageBox::information(nullptr,"END","Congrulatulations Game has ended \n Your Score: "+QString::number(mario->getScore()));
        obstacleTimer->stop();
    }
}

void Game::nextLevel()
{
<<<<<<< HEAD
    QMessageBox::information(nullptr,"Congrtulations", "You have successfully finished Level "+ QString::number(level++) +" \nThe next Level will open now \n Score: "+QString::number(mario->getScore()));
    levelTimer->start(50000);//reset the timer for the next level
    disconnect(obstacleTimer, &QTimer::timeout, nullptr, nullptr);
=======
    emptyScene();
    QMessageBox::information(nullptr,"Congrtulations", "You have successfully finished Level "+ QString::number(level) +" \nThe next Level will open now \n Score: "+QString::number(mario->getScore()));
    levelTimer->start(20000);//reset the timer for the next level
    mario->setLevel(++level);
>>>>>>> 9ee38dd145faba01f671c790d3caae48ab2e1d3c
    connect(obstacleTimer, &QTimer::timeout, this, [this]() {
                            this->createObstacle(level);
                             });
}

void Game::emptyScene()
{
 if(level==2){
        zoombie->setStop();
        scene->removeItem(zoombie);
    }
}

Game::~Game()
{
    delete zoombie;
    delete mario;
}
