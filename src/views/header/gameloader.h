#ifndef GAMELOADER_H
#define GAMELOADER_H

#include <QWidget>
#include <QPaintEvent>
#include "gameloadermodel.h"
#include "gamefieldui.h"

namespace Ui {
    class GameLoader;
}

//Loads map and player and constructs game instance
class GameLoaderUI : public QWidget
{
    Q_OBJECT

public:
    //CTOR
    explicit GameLoaderUI(QWidget *parent = nullptr);
    ~GameLoaderUI();

signals:
    //Emits game instance
    void gameLoaded(GameFieldUI* gameField);

private:
    Ui::GameLoader* ui;
    GameLoaderModel* model;

    //GameLoader
    void populateMapTable();
    void displaySelectedPlayer();

protected:
    void paintEvent(QPaintEvent *);
};

#endif // GAMELOADER_H
