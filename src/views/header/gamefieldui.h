#ifndef GAMEFIELDUI_H
#define GAMEFIELDUI_H

#include <QWidget>
#include <QMap>

namespace Ui {
class GameFieldUI;
}

// TYPEDEFS
using KeyFunction = void (*(Qt::Key));

class GameModel; // TODO: remove forward declaration

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
    Ui::GameFieldUI *ui;
    GameModel* game;
};

#endif // GAMEFIELDUI_H
