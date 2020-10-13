#ifndef GAMELOGICMODEL_H
#define GAMELOGICMODEL_H

#include <QObject>
#include <QTime>
#include <QTimer>

#include "player.h"
#include "map.h"
#include "lightfiller.h"

class GameLogicModel : public QObject
{
    Q_OBJECT

public:

    //CTOR
    explicit GameLogicModel(QObject *parent,Map* map,Player* player);
    ~GameLogicModel();

public:
    //Getters
    const Player& getPlayer() const;
    const Map &getActiveMap() const;
    const QPoint& getPlayerCoords() const;
    const Map::Direction& getPlayerDirection() const;

signals:
    void timeTicked(const QTime& time);
    void gameEnded (const Player& player,const QTime& time);

public slots:
    void startGame();
    void movePlayer(const Map::Direction& direction);
    void onPlayerEntered();
    void onPlayerExited();

private:
//FIELDS
    //Game
    bool   started;
    bool   paused;
    QTimer gameTimer;
    QTime  gameTime;

    //Map
    Map* activeMap;
    LightFiller lightFiller;

    //Player
    Player* player;
    QPoint playerCoords;
    Map::Direction playerDirection;

//METHODS

    //Player
    bool placePlayer(const QPoint& newPos, const QPoint& oldPos);

    //Game
    void connectBlockEvents();
    void endGame();

public:
    void pause();

};

#endif // GAMELOGICMODEL_H
