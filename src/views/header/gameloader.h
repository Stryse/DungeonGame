#ifndef GAMELOADER_H
#define GAMELOADER_H

#include <QWidget>
#include <QVector>
#include <QPaintEvent>
#include "player.h"
#include "playerdataaccess.h"

class MapDataAccess;
namespace Ui {
    class GameLoader;
}

class GameLoader : public QWidget
{
    Q_OBJECT

public:
    explicit GameLoader(QWidget *parent,PlayerDataAccess* pdataImpl, MapDataAccess* mapdataImpl);
    ~GameLoader();

protected:
    void paintEvent(QPaintEvent *);

private:
    Ui::GameLoader* ui;
    QVector<Player*> players;
    int activePlayerInd;

    PlayerDataAccess* playerDataAccess;
    MapDataAccess* mapDataAccess;

private slots:
    void setSelectedPlayer(int playerInd);
};

#endif // GAMELOADER_H
