#ifndef GAMEFIELDUI_H
#define GAMEFIELDUI_H

#include <QWidget>
#include <QVector>
#include <QPixmap>
#include <QMap>

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

    QMap<QString,QPixmap> blockTextures; // Collective store for textures
    QVector<QVector<AbstractGameBlockWidget*>> blockField;
    GameLogicModel* game;

    void loadBlockField();
    QString loadLightTexture(int row, int col,const AbstractGameBlock::LightLevel& lightlevel);
};

#endif // GAMEFIELDUI_H
