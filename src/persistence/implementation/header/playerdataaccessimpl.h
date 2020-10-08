#ifndef PLAYERDATAACCESSIMPL_H
#define PLAYERDATAACCESSIMPL_H

#define PLAYERDATA_FOLDER "./Players/PlayerData/"
#define PLAYERPORTRAIT_FOLDER "./Players/Portraits/"
#define DEFAULT_PLAYER_NAME "Játékos"
#define DEFAULT_PLAYER_PORTRAIT ":/resources/img/player/amonguscyan.png"

#include <QDir>
#include <QString>
#include "iplayerdataaccess.h"


class PlayerDataAccessImpl : public IPlayerDataAccess
{
public:
    PlayerDataAccessImpl();
    bool isAvailable() const override;
    bool loadPlayers(QVector<Player*>& target) const override;
    bool loadAvailablePortraits(QVector<QPixmap*>& target) const override;

private:
    void loadDefaultPlayer(QVector<Player*>& target) const;
};

#endif // PLAYERDATAACCESSIMPL_H
