#ifndef GAMEFIELDUI_H
#define GAMEFIELDUI_H

#include <QDialog>
#include <QVector>
#include <QPixmap>
#include <QMap>

#include "abstractgameblockwidget.h"
#include "gamelogicmodel.h"
#include "victoryscreen.h"

namespace Ui {
class GameFieldUI;
}

class GameFieldUI : public QDialog
{
    Q_OBJECT

public:
    //CTOR
    explicit GameFieldUI(QWidget *parent, GameLogicModel* game);
    ~GameFieldUI();

signals:
    void showVictoryScreen(VictoryScreen* victoryScreen);

protected:
    void keyPressEvent(QKeyEvent* event);

private:
    //FIELDS
    Ui::GameFieldUI *ui;
    QVector<QVector<AbstractGameBlockWidget*>> blockField;
    QPixmap* playerPortrait;

    GameLogicModel* game;

    //Methods
    void loadBlockField();
};

#endif // GAMEFIELDUI_H
