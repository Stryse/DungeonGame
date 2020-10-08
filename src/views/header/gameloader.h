#ifndef GAMELOADER_H
#define GAMELOADER_H

#include <QDialog>
#include <QVector>
#include <QPaintEvent>
#include "player.h"
#include "iplayerdataaccess.h"
#include "imapdataaccess.h"

namespace Ui {
    class GameLoader;
}

class GameLoader : public QDialog
{
    Q_OBJECT

public:
    explicit GameLoader(QWidget *parent,IPlayerDataAccess* pdataImpl, IMapDataAccess* mapdataImpl);
    ~GameLoader();

protected:
    void paintEvent(QPaintEvent *);

private:
    Ui::GameLoader* ui;
    IPlayerDataAccess* playerDataAccess;
    QVector<Player*> players;
    int activePlayerInd;

    IMapDataAccess* mapDataAccess;
    QVector<Map*> maps;

    void populateMapTable();

private slots:
    void setSelectedPlayer(int playerInd);
};

#endif // GAMELOADER_H
