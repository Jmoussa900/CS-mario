/*#ifndef FALLITEM_H
#define FALLITEM_H

class fallitem
{
public:
    fallitem();
};

#endif // FALLITEM_H*/
#ifndef FALLINGITEM_H
#define FALLINGITEM_H

#include <QObject>
#include <QGraphicsPixmapItem>

class FallingItem : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit FallingItem(QGraphicsItem *parent = nullptr);

    void advance(int step) override;

private:
    int speed;
};

#endif // FALLINGITEM_H

