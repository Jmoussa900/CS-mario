#ifndef STARTPAGE_H
#define STARTPAGE_H
#include "game.h"
#include <QMainWindow>

namespace Ui {
class startpage;
}

class startpage : public QMainWindow
{
    Q_OBJECT

public:
    explicit startpage(QWidget *parent = nullptr);
    ~startpage();

private slots:
    void on_pushButton_start_clicked();
    void endGame();


private:
    Ui::startpage *ui;
    Game * game;
};

#endif // STARTPAGE_H
