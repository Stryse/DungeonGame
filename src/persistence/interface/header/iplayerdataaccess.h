#ifndef PLAYERDATAACCESS_H
#define PLAYERDATAACCESS_H

#include <QVector>
#include <QStringList>
#include "player.h"

class IPlayerDataAccess
{
public:

    //Input
    virtual ~IPlayerDataAccess(){}
    virtual bool isAvailable() const = 0;
    virtual bool loadPlayers(QVector<Player*>& target) const = 0;
    virtual QStringList loadAvailablePortraits(QVector<QString>& target) const = 0;

    //Output
    virtual bool savePlayer(const Player& player) const = 0;
};

#endif // PLAYERDATAACCESS_H
