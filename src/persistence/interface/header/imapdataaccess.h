#ifndef IMAPDATAACCESS_H
#define IMAPDATAACCESS_H

#include <QVector>
#include <QPixmap>
#include "map.h"

class IMapDataAccess
{
public:
    virtual bool isAvailable() const = 0;
    virtual bool loadMaps(QVector<Map*>& target) const = 0;
};

#endif // IMAPDATAACCESS_H
