#ifndef GAMELOADER_H
#define GAMELOADER_H

#include <QDialog>
#include <QPaintEvent>
#include "gameloadermodel.h"
#include "gamefieldui.h"

namespace Ui {
    class GameLoader;
}

class GameLoader : public QDialog
{
    Q_OBJECT

public:
    explicit GameLoader(QWidget *parent = nullptr);
    ~GameLoader();

signals:
    void gameLoaded(GameFieldUI* gameField);

private:
    Ui::GameLoader* ui;
    GameLoaderModel* model;

    void populateMapTable();
    void displaySelectedPlayer();

protected:
    void paintEvent(QPaintEvent *);
};

#endif // GAMELOADER_H
