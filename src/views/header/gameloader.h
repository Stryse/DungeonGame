#ifndef GAMELOADER_H
#define GAMELOADER_H

#include "paintedwidget.h"

namespace Ui {
    class GameLoader;
}

class GameLoader : public QWidget
{
    Q_OBJECT

public:
    explicit GameLoader(QWidget *parent = nullptr);
    ~GameLoader();

protected:
    void paintEvent(QPaintEvent *);

private:
    Ui::GameLoader *ui;
};

#endif // GAMELOADER_H
