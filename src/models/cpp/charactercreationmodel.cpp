#include "charactercreationmodel.h"
#include <QDebug>

CharacterCreationModel::CharacterCreationModel(QObject *parent,IPlayerDataAccess* playerDataAccess)
    : QObject(parent)
    , maxSkillPoints(8)
    , playerStrength(0)
    , playerIntellect(0)
    , playerStamina(1)
    , playerDataAccess(playerDataAccess)
{

}


//SETTER
void CharacterCreationModel::setPlayerName(const QString& value)
{
    playerName = value;
}

void CharacterCreationModel::setPlayerPortraitPath(const QString& value)
{
    playerPortraitPath = value;
}

int CharacterCreationModel::addPointStrength(int value)
{
    if(maxSkillPoints+value > 0 && playerStrength+value >= 0)
    {
        playerStrength += value;
        qDebug() << playerStrength;
        maxSkillPoints -= value;
    }
    return playerStrength;
}

int CharacterCreationModel::addPointIntellect(int value)
{
    if(maxSkillPoints+value > 0 && playerIntellect+value >= 0)
    {
        playerIntellect += value;
        maxSkillPoints  -= value;
    }
    return playerIntellect;
}

int CharacterCreationModel::addPointStamina(int value)
{
    if(maxSkillPoints+value > 0 && playerStamina+value >= 1)
    {
        playerStamina  += value;
        maxSkillPoints -= value;
    }
    return playerStamina;
}

//GETTER
IPlayerDataAccess* CharacterCreationModel::getPlayerDataAccess() const
{
    return playerDataAccess;
}

int CharacterCreationModel::getMaxSkillPoints() const
{
    return maxSkillPoints;
}

QString CharacterCreationModel::getPlayerName() const
{
    return playerName;
}

int CharacterCreationModel::getPlayerStrength() const
{
    return playerStrength;
}

int CharacterCreationModel::getPlayerIntellect() const
{
    return playerIntellect;
}

int CharacterCreationModel::getPlayerStamina() const
{
    return playerStamina;
}
