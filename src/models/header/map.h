#ifndef MAP_H
#define MAP_H

#include <QObject>
#include <QPoint>
#include <QVector>
#include "abstractgameblockwidget.h"

class Map : public QObject
{
    Q_OBJECT
public:
    explicit Map(QObject *parent = nullptr);

    //Direction type
    enum class Direction { UP,DOWN,LEFT,RIGHT };

    //Getter Setter
    QPoint getInitialCoords() const;
    Direction getInitialDirection() const;
    int getSize() const;


signals:

private:
    QPoint initialCoords;
    Direction initialDirection;
    int size;

};

#endif // MAP_H
