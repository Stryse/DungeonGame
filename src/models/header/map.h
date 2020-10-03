#ifndef MAP_H
#define MAP_H

#include <QObject>
#include <QPoint>

class Map : public QObject
{
    Q_OBJECT
public:
    explicit Map(QObject *parent = nullptr);

    //Direction type
    enum class Direction { UP,DOWN,LEFT,RIGHT };

    QPoint getInitialCoords() const;
    Direction getInitialDirection() const;


signals:

private:
    QPoint initialCoords;
    Direction initialDirection;

};

#endif // MAP_H
