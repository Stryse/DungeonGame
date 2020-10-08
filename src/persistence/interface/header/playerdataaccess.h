#ifndef PLAYERDATAACCESS_H
#define PLAYERDATAACCESS_H

#include <QVector>
#include <QPixmap>
#include "player.h"

class PlayerDataAccess
{
public:
    virtual bool isAvailable() const = 0;
    virtual bool loadPlayers(QVector<Player*>& target) const = 0;
    virtual bool laodAvailablePortraits(QVector<QPixmap*>& target) const = 0;

};

#endif // PLAYERDATAACCESS_H
