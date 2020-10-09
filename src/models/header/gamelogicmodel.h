#ifndef GAMELOGICMODEL_H
#define GAMELOGICMODEL_H

#include <QObject>
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

signals:
    void moved();

public slots:
    void movePlayer(const Map::Direction& direction);

private slots:
    void onUIReady();

private:
//FIELDS

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

};

#endif // GAMELOGICMODEL_H
