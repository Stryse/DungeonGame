#include "player.h"

Player::Player(QObject *parent,const QString& portrait,
                    const QString& pName,int strength, int intellct, int stamina)
    : QObject(parent)
    , portraitPath(portrait)
    , playerName(pName),strength(strength),intellect(intellct),stamina(stamina)
{

}

Player::Player(const Player& other)
    :portraitPath(other.portraitPath),playerName(other.playerName),strength(other.strength)
    ,intellect(other.intellect),stamina(other.stamina)
{

}

Player::~Player()
{
}

const QString& Player::getPlayerName() const
{
    return playerName;
}

int Player::getStrength() const
{
    return strength;
}

int Player::getIntellect() const
{
    return intellect;
}

int Player::getStamina() const
{
    return stamina;
}

const QString& Player::getPortrait() const
{
    return portraitPath;
}
