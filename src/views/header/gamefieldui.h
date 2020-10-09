#ifndef GAMEFIELDUI_H
#define GAMEFIELDUI_H

#include <QDialog>
#include <QVector>
#include <QPixmap>
#include <QMap>

#include "abstractgameblockwidget.h"
#include "gamelogicmodel.h"

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

protected:
    void keyPressEvent(QKeyEvent* event);

private:
    //FIELDS
    Ui::GameFieldUI *ui;

    QMap<QString,QPixmap> blockTextures; // Collective store for textures
    QPixmap* playerPortrait;
    QVector<QVector<AbstractGameBlockWidget*>> blockField;
    GameLogicModel* game;
    void loadBlockField();
};

#endif // GAMEFIELDUI_H
