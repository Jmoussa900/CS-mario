#include "startpage.h"
#include "ui_startpage.h"

startpage::startpage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::startpage)
{
    ui->setupUi(this);
}
void startpage::endGame()
{
    if (game) {
        game->hide();  // Hide the game window
        delete game;
        game = nullptr;
    }
    QMessageBox::information(this,"END","CONGRATULATIONS, you conquered this level!!!!");
}

startpage::~startpage()
{
    delete ui;
}

void startpage::on_pushButton_start_clicked()
{
    game = new Game();
    hide();
    game->show();
 //   QTimer::singleShot(70000, this, SLOT(endGame()));
}

