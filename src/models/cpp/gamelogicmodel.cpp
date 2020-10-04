#include "gamelogicmodel.h"

GameLogicModel::GameLogicModel(QObject *parent,const Map& map,const Player& player)
    : QObject(parent)
    , activeMap(map)
    , player(player)
    , playerCoords(activeMap.getInitialCoords())
    , playerDirection(activeMap.getInitialDirection())
{
}

const Player &GameLogicModel::getPlayer() const
{
    return player;
}

const Map &GameLogicModel::getActiveMap() const
{
    return activeMap;
}
