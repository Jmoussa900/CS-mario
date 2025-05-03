#ifndef GAME_H
#define GAME_H
#include  <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "mario.h"
#include "monster.h"
#include <QTimer>
#include <QMessageBox>
using namespace std;

class Game:public QGraphicsView{
    Q_OBJECT
public:
    Game(QWidget * parent=0);
    //void endGame();
    void createObstacle(int num);
    void nextLevel();
    void emptyScene();
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

};
#endif // GAME_H
