#include "player.h"

Player::Player(QObject *parent,QPixmap* portrait)
    : QObject(parent)
    , portrait(portrait)
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
