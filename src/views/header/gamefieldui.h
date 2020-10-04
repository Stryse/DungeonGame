#ifndef GAMEFIELDUI_H
#define GAMEFIELDUI_H

#include <QWidget>
#include <QVector>
#include <QPixmap>
#include "abstractgameblockwidget.h"
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

    QPixmap roadTexture;
    QPixmap wallTexture;

    QVector<AbstractGameBlockWidget*> blockTypes;
    QVector<QVector<AbstractGameBlockWidget*>> blockField;
    GameLogicModel* game;


    void loadBlockTypes();
    void loadBlockField();
};

#endif // GAMEFIELDUI_H
