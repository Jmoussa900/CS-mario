#ifndef GAME_H
#define GAME_H
#include  <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "mario.h"
#include "monster.h"
#include <QTimer>
#include <QMessageBox>
#include <iostream>
#include "cloud.h"
using namespace std;
class Game:public QGraphicsView{
    Q_OBJECT
public:
    Game(QWidget * parent=0);
    void endGame();
    void createObstacle(int num);
    void nextLevel();
    ~Game();
public slots:
    void levelEnded();

private slots:
    void checkLevelCompletion();

protected:
    void keyPressEvent(QKeyEvent *event) override;

private:
    QGraphicsScene * scene;
    Mario * mario;
    int level;
    QTimer* levelTimer;
    QTimer * obstacleTimer;
    Monster * zoombie=nullptr;
    Cloud* cloud;

};
#endif // GAME_H
