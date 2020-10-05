#include "map.h"
#include <QFile>
#include <QTextStream>

Map::Map(QObject *parent) : QObject(parent)
{
}

void Map::loadMapFromFile(const QString &filePath)
{
    QFile infile(filePath);
    if(!infile.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream stream(&infile);

    // READ Map name
    mapName = stream.readLine();

    // Read Initial Player Coords
    int coordX; int coordY;
    stream >> coordX; stream >> coordY;
    initialCoords = QPoint(coordX,coordY);

    // Read Initial Player Direction
    int direction; stream >> direction;
    initialDirection = static_cast<Direction>(direction);

    // Read Map size
    stream >> size;

    //Populating blockFieldData from file
    blockFieldData.resize(size);
    for(int row = 0; row < size; ++row)
    {
        blockFieldData[row].resize(size);
        for(int col = 0; col < size; ++col)
        {
            QString type; stream >> type;
            blockFieldData[row][col] = (AbstractGameBlock::create(type));
        }
    }

    stream.flush();
    infile.close();
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
