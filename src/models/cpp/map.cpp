#include "map.h"
#include <QFile>
#include <QTextStream>


Map::Map(const QString& mapName,
         const QVector<QVector<AbstractGameBlock*>>& dataGrid,
         const QPoint& initCoords,int direction)
    :mapName(mapName)
    ,blockFieldData(dataGrid)
    ,initialCoords(initCoords)
    ,initialDirection(static_cast<Map::Direction>(direction))
    ,size(blockFieldData.size())
{

}

bool Map::isInMapBounds(int row, int col) const
{
    return row >= 0 && row < size && col >= 0 && col < size;
}

bool Map::isInMapBounds(const QPoint& point) const
{
    return isInMapBounds(point.y(),point.x());
}

Map::Direction Map::getInitialDirection() const
{
    return initialDirection;
}

AbstractGameBlock *Map::getGameBlock(int row, int col) const
{
    return blockFieldData[row][col];
}

AbstractGameBlock* Map::getGameBlock(const QPoint& point) const
{
    return getGameBlock(point.y(),point.x());
}

int Map::getSize() const
{
    return size;
}

QString Map::getMapName() const
{
    return mapName;
}

QPoint Map::getInitialCoords() const
{
    return initialCoords;
}
