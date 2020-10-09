#include "charactercreationmodel.h"

CharacterCreationModel::CharacterCreationModel(QObject *parent,IPlayerDataAccess* playerDataAccess)
    : QObject(parent)
    , playerStrength(0)
    , playerIntellect(0)
    , playerStamina(0)
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

void CharacterCreationModel::setPlayerStrength(int value)
{
    playerStrength = value;
}

void CharacterCreationModel::setPlayerIntellect(int value)
{
    playerIntellect = value;
}

void CharacterCreationModel::setPlayerStamina(int value)
{
    playerStamina = value;
}

//GETTER
IPlayerDataAccess* CharacterCreationModel::getPlayerDataAccess() const
{
    return playerDataAccess;
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
