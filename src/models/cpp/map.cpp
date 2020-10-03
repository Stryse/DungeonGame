#include "map.h"

Map::Map(QObject *parent) : QObject(parent)
{

}

Map::Direction Map::getInitialDirection() const
{
    return initialDirection;
}

QPoint Map::getInitialCoords() const
{
    return initialCoords;
}
