#ifndef MAPDATAACCESSIMPL_H
#define MAPDATAACCESSIMPL_H

#define MAPDATA_FOLDER "./Players/PlayerData/"
#define MAPDEFAULT_FOLDER ":/resources/maps/"

#include <imapdataaccess.h>
#include <QFile>

class MapDataAccessImpl : public IMapDataAccess
{
public:
    MapDataAccessImpl();
    virtual ~MapDataAccessImpl();

public:
    bool isAvailable() const override;
    bool loadMaps(QVector<Map*>& target) const override;

private:

    bool loadMapsFromDirectory(QVector<Map*>& target, const QString& dirPath) const;
    Map* loadMapFromFile(const QString& filePath) const;
};

#endif // MAPDATAACCESSIMPL_H
