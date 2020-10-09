#ifndef CHARACTERCREATIONMODEL_H
#define CHARACTERCREATIONMODEL_H

#include <QObject>
#include <QString>
#include "iplayerdataaccess.h"

class CharacterCreationModel : public QObject
{
    Q_OBJECT
public:
    explicit CharacterCreationModel(QObject *parent, IPlayerDataAccess* playerDataAccess);

    //GETER
    QString getPlayerName() const;
    int getPlayerStrength() const;
    int getPlayerIntellect() const;
    int getPlayerStamina() const;

    //SETTER
    void setPlayerName(const QString& value);
    void setPlayerPortraitPath(const QString& value);
    void setPlayerStrength(int value);
    void setPlayerIntellect(int value);
    void setPlayerStamina(int value);
    IPlayerDataAccess* getPlayerDataAccess() const;

private:

    //Player
    QString playerName;
    QString playerPortraitPath;
    int playerStrength;
    int playerIntellect;
    int playerStamina;

    //I/O
    IPlayerDataAccess* playerDataAccess;
};

#endif // CHARACTERCREATIONMODEL_H
