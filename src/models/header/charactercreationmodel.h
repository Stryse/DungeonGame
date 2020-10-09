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
    int getMaxSkillPoints() const;

    //SETTER
    void setPlayerName(const QString& value);
    void setPlayerPortraitPath(const QString& value);
    int addPointStrength(int value);
    int addPointIntellect(int value);
    int addPointStamina(int value);
    IPlayerDataAccess* getPlayerDataAccess() const;


private:

    //Character creation
    int maxSkillPoints;

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
