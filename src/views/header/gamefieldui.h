#ifndef GAMEFIELDUI_H
#define GAMEFIELDUI_H

#include <QWidget>
#include <QMap>
#include "gamelogicmodel.h"


namespace Ui {
class GameFieldUI;
}

class GameFieldUI : public QWidget
{
    Q_OBJECT

public:
    //CTOR
    explicit GameFieldUI(QWidget *parent = nullptr);
    ~GameFieldUI();

public:

protected:
    void keyPressEvent(QKeyEvent* event);

private:
    //FIELDS
    Ui::GameFieldUI *ui;
    GameLogicModel* game;

};

#endif // GAMEFIELDUI_H
