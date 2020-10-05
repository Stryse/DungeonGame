#include "gamelogicmodel.h"
#include <QDebug>

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

void GameLogicModel::movePlayer(const Map::Direction& direction)
{
    bool success;
    playerDirection = direction;

    switch (direction) {
        case Map::Direction::UP:
            success = placePlayer(QPoint(playerCoords.x(),playerCoords.y()-1),playerCoords);
            qDebug() << "Player moved UP" << success << "| Facing: UP";
            break;
        case Map::Direction::DOWN:
            success = placePlayer(QPoint(playerCoords.x(),playerCoords.y()+1),playerCoords);
            qDebug() << "Player moved DOWN" << success << "| Facing: DOWN";
            break;
        case Map::Direction::LEFT:
            success = placePlayer(QPoint(playerCoords.x()-1,playerCoords.y()),playerCoords);
            qDebug() << "Player moved LEFT" << success<< "| Facing: LEFT";
            break;
        case Map::Direction::RIGHT:
            success = placePlayer(QPoint(playerCoords.x()+1,playerCoords.y()),playerCoords);
            qDebug() << "Player moved RIGHT" << success<< "| Facing: RIGHT";
            break;

        default:
            qDebug() << "Unhandled Direction in movePlayer() in gamelogicmodel.cpp";
            break;
    }
}

void GameLogicModel::onUIReady()
{
    placePlayer(playerCoords,playerCoords);
}

bool GameLogicModel::placePlayer(const QPoint& newPos, const QPoint& oldPos)
{
    if(activeMap.isInMapBounds(newPos.y(),newPos.x()))
    {
        //Performing enter
        activeMap.getGameBlock(newPos.y(),newPos.x())->DoPlayerEnter(player);

        //Update position if entered to a new block successfully, leaving old block
        if(activeMap.getGameBlock(newPos.y(),newPos.x())->getHasPlayer() //Block accepted entering
           && (oldPos.x() != newPos.x() || oldPos.y() != newPos.y()))
        {
            activeMap.getGameBlock(oldPos.y(),oldPos.x())->DoPlayerExit(player);
            playerCoords = {newPos.x(),newPos.y()};
            return true; // Position changed
        }
    }
    return false; //Position unchanged
}
