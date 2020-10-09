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
    explicit GameLogicModel(QObject *parent,const Map& map,const Player& player);

public:
    //Getters
    const Player& getPlayer() const;
    const Map &getActiveMap() const;

signals:
    void moved();
    void timeTicked(const QTime& time);
    void gameEnded (const QTime& time);

public slots:
    void startGame();
    void movePlayer(const Map::Direction& direction);
    void onPlayerEntered();
    void onPlayerExited();

private:
//FIELDS
    //Game
    bool   started;
    QTimer gameTimer;
    QTime  gameTime;

    //Map
    const Map& activeMap; // MIGHT NEED POINTER
    LightFiller lightFiller;

    //Player
    const Player& player;
    QPoint playerCoords;
    Map::Direction playerDirection;

//METHODS

    //Player
    bool placePlayer(const QPoint& newPos, const QPoint& oldPos);

    //Game
    void connectBlockEvents();
    void endGame();

};

#endif // GAMELOGICMODEL_H
