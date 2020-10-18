#ifndef MAPDATAACCESSMOCK_H
#define MAPDATAACCESSMOCK_H
#include "imapdataaccess.h"

class MapDataAccessMock : public IMapDataAccess
{
public:
    MapDataAccessMock();

    // IMapDataAccess interface
public:
    bool isAvailable() const override;
    bool loadMaps(QVector<Map*>& target) const override;
};

#endif // MAPDATAACCESSMOCK_H
