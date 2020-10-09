#ifndef GAMELOADER_H
#define GAMELOADER_H

#include <QDialog>
#include <QVector>
#include <QPaintEvent>
#include "player.h"
#include "iplayerdataaccess.h"
#include "imapdataaccess.h"
#include "gamelogicmodel.h"

namespace Ui {
    class GameLoader;
}

class GameLoader : public QDialog
{
    Q_OBJECT

public:
    explicit GameLoader(QWidget *parent,IPlayerDataAccess* pdataImpl, IMapDataAccess* mapdataImpl);
    ~GameLoader();

signals:
    void gameLoaded(GameLogicModel* gameInstance);


private:
    Ui::GameLoader* ui;
    IPlayerDataAccess* playerDataAccess;
    QVector<Player*> players;
    int activePlayerInd;

    IMapDataAccess* mapDataAccess;
    QVector<Map*> maps;
    Map* activeMap;

    void populateMapTable();

private slots:
    void setSelectedPlayer(int playerInd);

protected:
    void paintEvent(QPaintEvent *);
};

#endif // GAMELOADER_H
