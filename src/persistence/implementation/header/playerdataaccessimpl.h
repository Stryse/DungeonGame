#ifndef PLAYERDATAACCESSIMPL_H
#define PLAYERDATAACCESSIMPL_H

//TODO load resources from resource virtual folder
#define PLAYERDATA_FOLDER "./Players/PlayerData/"
#define PLAYERPORTRAIT_FOLDER "./Players/Portraits/"
#define INBUILDS_PORTRAITS ":/resources/img/player/"
#define DEFAULT_PLAYER_NAME "Játékos"
#define DEFAULT_PLAYER_PORTRAIT ":/resources/img/player/amonguscyan.png"

#include <QDir>
#include <QString>
#include "iplayerdataaccess.h"


class PlayerDataAccessImpl : public IPlayerDataAccess
{
public:
    PlayerDataAccessImpl();
    virtual ~PlayerDataAccessImpl();

    bool isAvailable() const override;
    bool loadPlayers(QVector<Player*>& target) const override;
    QStringList loadAvailablePortraits(QVector<QPixmap>& target) const override;

private:
    bool loadDefaultPlayer(QVector<Player*>& target) const;
    bool loadPortraitsFromFolder(QVector<QPixmap>& target, const QString& folder) const;
};

#endif // PLAYERDATAACCESSIMPL_H
