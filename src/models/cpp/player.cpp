#include "player.h"

Player::Player(QObject *parent,const QString& portrait,
                    const QString& pName,int strength, int intellct, int stamina)
    : QObject(parent)
    , portraitPath(portrait)
    , playerName(pName),strength(strength),intellect(intellct),stamina(stamina)
{

}

Player::~Player()
{
}

QString Player::getPlayerName() const
{
    return playerName;
}

int Player::getStrength() const
{
    return strength;
}

const QString& Player::getPortrait() const
{
    return portraitPath;
}
