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
    mapName          = stream.readLine();
    initialCoords    = QPoint(stream.readLine().toInt(),stream.readLine().toInt());
    initialDirection = static_cast<Direction>(stream.readLine().toInt());
    stream >> size;

    blockFieldData.resize(size);
    for(int row = 0; row < size; ++row)
    {
        blockFieldData[row].resize(size);
        for(int col = 0; col < size; ++col)
        {
            QString type = stream.read(1);
            blockFieldData[row][col] = (AbstractGameBlock::create(type));
        }
    }

    stream.flush();
    infile.close();
}

Map::Direction Map::getInitialDirection() const
{
    return initialDirection;
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
