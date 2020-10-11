#ifndef GAMELOADERMODEL_H
#define GAMELOADERMODEL_H

#include <QObject>
#include "iplayerdataaccess.h"
#include "imapdataaccess.h"
#include "gamelogicmodel.h"

class GameLoaderModel : public QObject
{
    Q_OBJECT
public:
    explicit GameLoaderModel(QObject *parent, IPlayerDataAccess* playerDataAccess,IMapDataAccess* mapDataAccess);

    //Getter
    Player* getActivePlayer() const;
    const QVector<Map*>& getMaps() const;

    //Setter
    void setActiveMap(int ind);

    //Methods
    void nextPlayer();
    void prevPlayer();

    //Game factory
    GameLogicModel* createGame(QObject* parent);

private:
    //Player
    IPlayerDataAccess* playerDataAccess;
    QVector<Player*> players;
    int activePlayerInd;

    //Map
    IMapDataAccess* mapDataAccess;
    QVector<Map*> maps;
    int activeMapInd;

};

#endif // GAMELOADERMODEL_H
