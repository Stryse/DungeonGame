#ifndef PLAYERDATAACCESSIMPL_H
#define PLAYERDATAACCESSIMPL_H

#define PLAYERDATA_FOLDER "./Players/PlayerData/"
#define PLAYERPORTRAIT_FOLDER "./Players/Portraits/"
#define DEFAULT_PLAYER_NAME "Játékos"
#define DEFAULT_PLAYER_PORTRAIT ":/resources/img/player/amonguscyan.png"

#include <QDir>
#include <QString>
#include "playerdataaccess.h"


class PlayerDataAccessImpl : public PlayerDataAccess
{
public:
    PlayerDataAccessImpl();
    bool isAvailable() const override;
    bool loadPlayers(QVector<Player*>& target) const override;
    bool laodAvailablePortraits(QVector<QPixmap*>& target) const override;
};

#endif // PLAYERDATAACCESSIMPL_H
