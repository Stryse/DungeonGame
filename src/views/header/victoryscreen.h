#ifndef VICTORYSCREEN_H
#define VICTORYSCREEN_H

#include <QDialog>
#include <QTime>
#include "player.h"


namespace Ui {
    class VictoryScreen;
}

class VictoryScreen : public QDialog
{
    Q_OBJECT

public:
    explicit VictoryScreen(QWidget *parent, const Player& player, const QTime& playtime);
    ~VictoryScreen();

private:
    Ui::VictoryScreen *ui;
    const Player player;
    const QTime playTime;

};

#endif // VICTORYSCREEN_H
