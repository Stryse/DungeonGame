#include "map.h"

Map::Map(QObject *parent) : QObject(parent)
{
    size = 12;
    initialCoords = {0,0};
    initialDirection = Direction::UP;
}

Map::Direction Map::getInitialDirection() const
{
    return initialDirection;
}

int Map::getSize() const
{
    return size;
}

QPoint Map::getInitialCoords() const
{
    return initialCoords;
}
