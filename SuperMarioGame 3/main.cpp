#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include<QGraphicsView>
#include <QTimer>
#include <QDebug>
#include <QBrush>
#include "startpage.h"
#include "Game.h"
#include <QTimer>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qDebug() << "Application starting...";
    //start the code by showing the main page
    startpage s;
    s.setFixedSize(800,600);
    s.show();
    return a.exec();
}
