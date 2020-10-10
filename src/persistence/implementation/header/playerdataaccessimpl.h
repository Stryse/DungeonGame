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

    //Input
    bool isAvailable() const override;
    bool loadPlayers(QVector<Player*>& target) const override;
    QStringList loadAvailablePortraits(QVector<QString>& target) const override;

    //Output
    bool savePlayer(const Player& player) const override;

private:
    bool loadDefaultPlayer(QVector<Player*>& target) const;
    bool loadPortraitsFromFolder(QVector<QString>& target, const QString& folder) const;
};

#endif // PLAYERDATAACCESSIMPL_H
