#ifndef GAMELOGICMODEL_H
#define GAMELOGICMODEL_H

#include <QObject>
#include <QTime>

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
    const Player& getPlayer() const;
    const Map &getActiveMap() const;
    QPoint getPlayerCoords() const;

signals:
    void moved();

public slots:
    void movePlayer(const Map::Direction& direction);

private:
//FIELDS

    //Map
    const Map& activeMap; // MIGHT NEED POINTER
    LightFiller lightFiller;
    //Player
    const Player& player;
    QPoint playerCoords;
    Map::Direction playerDirection;

    //Game
    bool started;
    QTime gameTime;

//METHODS

    //Player
    bool placePlayer(const QPoint& newPos, const QPoint& oldPos);

    //Game
    void StartGame();

};

#endif // GAMELOGICMODEL_H
