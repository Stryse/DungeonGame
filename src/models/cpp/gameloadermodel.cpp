#include "gameloadermodel.h"
#include <QDebug>

GameLoaderModel::GameLoaderModel(QObject *parent,IPlayerDataAccess* playerDataAccess,IMapDataAccess* mapDataAccess)
    : QObject(parent)
    ,playerDataAccess(playerDataAccess)
    ,activePlayerInd(-1)
    ,mapDataAccess(mapDataAccess)
    ,activeMapInd(-1)
{
    if(playerDataAccess->isAvailable() && playerDataAccess->loadPlayers(players))
    {
        qDebug() << "Players are Loaded";
        activePlayerInd = 0;
    }

    if(mapDataAccess->isAvailable() && mapDataAccess->loadMaps(maps))
    {
        qDebug() << "Maps are Loaded";
        activeMapInd = 0;
    }
}

void GameLoaderModel::setActiveMap(int ind)
{
    activeMapInd = ind;
}

void GameLoaderModel::nextPlayer()
{
    activePlayerInd = (++activePlayerInd % players.size() + players.size()) % players.size();
}

void GameLoaderModel::prevPlayer()
{
    activePlayerInd = (--activePlayerInd % players.size() + players.size()) % players.size();
}

GameLogicModel* GameLoaderModel::createGame(QObject* parent)
{
    GameLogicModel* gameInstance = new GameLogicModel(parent,maps.at(activeMapInd),players.at(activePlayerInd));
    players.remove(activePlayerInd);
    maps.remove(activeMapInd);
    return gameInstance;
}

Player* GameLoaderModel::getActivePlayer() const
{
    return players.at(activePlayerInd);
}

const QVector<Map*>& GameLoaderModel::getMaps() const
{
    return maps;
}
