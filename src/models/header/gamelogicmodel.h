#ifndef GAMELOGICMODEL_H
#define GAMELOGICMODEL_H

#include <QObject>
#include "player.h"
#include "map.h"

class GameLogicModel : public QObject
{
    Q_OBJECT
public:

    //CTOR
    explicit GameLogicModel(QObject *parent,const Map& map,const Player& player);

public:
    const Player& getPlayer() const;

signals:
    void moved();

private slots:

private:
//FIELDS

    //Map
    const Map& activeMap; // MIGHT NEED POINTER

    //Player
    const Player& player;
    QPoint playerCoords;
    Map::Direction playerDirection;

};

#endif // GAMELOGICMODEL_H
