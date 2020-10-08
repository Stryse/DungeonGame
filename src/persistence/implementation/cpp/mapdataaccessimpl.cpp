#include "mapdataaccessimpl.h"
#include <QDir>
#include <QDebug>

MapDataAccessImpl::MapDataAccessImpl()
{
    QDir().mkpath(MAPDATA_FOLDER);
    QDir().mkpath(MAPDATA_FOLDER);
}

MapDataAccessImpl::~MapDataAccessImpl()
{}

bool MapDataAccessImpl::isAvailable() const
{
    return true;
}

bool MapDataAccessImpl::loadMaps(QVector<Map*>& target) const
{
    return loadMapsFromDirectory(target,MAPDEFAULT_FOLDER) ||
           loadMapsFromDirectory(target,MAPDATA_FOLDER);
}

bool MapDataAccessImpl::loadMapsFromDirectory(QVector<Map*>& target, const QString& dirPath) const
{
    //Checking Map directory
    QDir mapDataDir(dirPath);
    if(!mapDataDir.exists()){ qDebug() << "Map data dir not found!"; return false; }

    //Read Map files
    QStringList mapDataFiles = mapDataDir.entryList(QStringList() << "*.txt",QDir::Files);
    for(auto& filename : mapDataFiles)
    {
        qDebug() << "Found MapData: "<< filename;
        Map* map = loadMapFromFile(mapDataDir.filePath(filename));
        if(map) target.push_back(map);
    }
    return target.size() > 0;
}

Map* MapDataAccessImpl::loadMapFromFile(const QString& filePath) const
{
    QFile file(filePath);
    if(!file.open(QFile::ReadOnly | QIODevice::Text)){
        qDebug() << "Error opening file: " << file.fileName();
        return nullptr;
    }

    QTextStream stream(&file);

    // READ Map name
    QString mapName = stream.readLine();

    // Read Initial Player Coords
    int coordX; int coordY;
    stream >> coordX; stream >> coordY;
    QPoint initialCoords = QPoint(coordX,coordY);

    // Read Initial Player Direction
    int direction; stream >> direction;

    // Read Map size
    int size; stream >> size;

    //Populating blockFieldData from file
    Map::GameBlockGrid blockFieldData;

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
    file.close();

    return new Map(mapName,blockFieldData,initialCoords,direction);
}
