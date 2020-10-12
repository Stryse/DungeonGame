#ifndef GAMEFIELDUI_H
#define GAMEFIELDUI_H

#include <QWidget>
#include <QVector>
#include <QPixmap>
#include <QMap>

#include "abstractgameblockwidget.h"
#include "gamelogicmodel.h"
#include "victoryscreen.h"

namespace Ui {
class GameFieldUI;
}

class GameFieldUI : public QWidget
{
    Q_OBJECT

public:
    //CTOR
    explicit GameFieldUI(QWidget *parent, GameLogicModel* game);
    ~GameFieldUI();

signals:
    //Emits victory screen instance
    void showVictoryScreen(VictoryScreen* victoryScreen);

protected:
    //Keymapping
    void keyPressEvent(QKeyEvent* event);

private:
    //FIELDS
    //Ui
    Ui::GameFieldUI *ui;
    QVector<QVector<AbstractGameBlockWidget*>> blockField;
    QPixmap* playerPortrait;

    //Logic
    GameLogicModel* game;

    //Methods
    void loadBlockField();
};

#endif // GAMEFIELDUI_H
