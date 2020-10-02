#ifndef GAMEFIELDUI_H
#define GAMEFIELDUI_H

#include <QWidget>

namespace Ui {
class GameFieldUI;
}

class GameFieldUI : public QWidget
{
    Q_OBJECT

public:
    explicit GameFieldUI(QWidget *parent = nullptr);
    ~GameFieldUI();

private:
    Ui::GameFieldUI *ui;
};

#endif // GAMEFIELDUI_H
