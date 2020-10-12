#include "gamelogicmodel.h"
#include <QDebug>
#include "endblock.h"

GameLogicModel::GameLogicModel(QObject *parent,Map* map,Player* player)
    : QObject(parent)
    , started(false)
    , paused(false)
    , gameTime(0,0,0,0)
    , activeMap(map)
    , lightFiller(this,*activeMap,2)
    , player(player)
    , playerCoords(activeMap->getInitialCoords())
    , playerDirection(activeMap->getInitialDirection())
{
    connectBlockEvents();

    lightFiller.lightFill(playerCoords,AbstractGameBlock::LightLevel::UNLIT,
                          AbstractGameBlock::LightLevel::LIT);
}

GameLogicModel::~GameLogicModel()
{
    delete player;
    delete activeMap;
}

const Player &GameLogicModel::getPlayer() const
{
    return *player;
}

const Map &GameLogicModel::getActiveMap() const
{
    return *activeMap;
}

void GameLogicModel::movePlayer(const Map::Direction& direction)
{
    if(!paused)
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

        if(!started && success)
        {
            started = true;
            startGame();
        }
    }
}

void GameLogicModel::onPlayerEntered()
{
    //If entered block is endblock, game ends
    if(qobject_cast<EndBlock*>(sender()) != nullptr)
        endGame();
}

void GameLogicModel::onPlayerExited()
{}

const Map::Direction& GameLogicModel::getPlayerDirection() const
{
    return playerDirection;
}

const QPoint& GameLogicModel::getPlayerCoords() const
{
    return playerCoords;
}

void GameLogicModel::startGame()
{
    started = true;
    connect(&gameTimer,&QTimer::timeout,this,[=](){
        gameTime = gameTime.addSecs(1);
        emit timeTicked(gameTime);
    });

    gameTimer.setInterval(1000);
    gameTimer.start();
}

bool GameLogicModel::placePlayer(const QPoint& newPos, const QPoint& oldPos)
{
    if(activeMap->isInMapBounds(newPos.y(),newPos.x()))
    {
        //Performing enter
        activeMap->getGameBlock(newPos.y(),newPos.x())->DoPlayerEnter(*player);

        //Update position if entered to a new block successfully, leaving old block
        if(activeMap->getGameBlock(newPos.y(),newPos.x())->getHasPlayer() //Block accepted entering
           && (oldPos.x() != newPos.x() || oldPos.y() != newPos.y()))
        {
            activeMap->getGameBlock(oldPos.y(),oldPos.x())->DoPlayerExit(*player);
            playerCoords = {newPos.x(),newPos.y()};
            lightFiller.lightFill(playerCoords,AbstractGameBlock::LightLevel::UNLIT,AbstractGameBlock::LightLevel::LIT);
            return true; // Position changed
        }
    }
    return false; //Position unchanged
}

void GameLogicModel::connectBlockEvents()
{
    for(int row = 0; row < activeMap->getSize(); ++row)
        for(int col = 0; col < activeMap->getSize(); ++col)
        {
            connect(activeMap->getGameBlock(row,col),&AbstractGameBlock::playerEntered,
                                               this,&GameLogicModel::onPlayerEntered);
        }
}

void GameLogicModel::endGame()
{
    gameTimer.stop();
    qDebug() << "Game ended!";
    emit gameEnded(*player,gameTime);
}

void GameLogicModel::pause()
{
    paused = (paused) ? false : true;

    if  (paused) gameTimer.stop();
    else         gameTimer.start();
}
