#include "player.h"

Player::Player(QObject *parent, QPixmap* portrait,
                    const QString& pName,int strength, int intellct, int stamina)
    : QObject(parent)
    , portrait(portrait)
    , playerName(pName),strength(strength),intellect(intellct),stamina(stamina)
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

QPixmap *Player::getPortrait() const
{
    return portrait;
}
