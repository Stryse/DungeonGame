#include "gamefieldui.h"
#include "ui_gamefieldui.h"

#include <QPainter>
#include <QBrush>
#include <QPalette>

#include <QKeyEvent>
#include <QDebug>

GameFieldUI::GameFieldUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameFieldUI)
{
    ui->setupUi(this);

    QPixmap portrait(":/resources/img/player/amonguscyan.png");
    Player p(this,&portrait,"Cyan",1,2,3);

    ui->playerPortraitWidget->setPixmap(portrait);
    ui->playerNameLabel->setText(p.getPlayerName());

    setFocus();
}

GameFieldUI::~GameFieldUI()
{
    delete ui;
    qDebug() << "Gamefield window closed and deallocated";
}

// Navigation keys are mapped through shortcuts
void GameFieldUI::keyPressEvent(QKeyEvent* event)
{
    switch (event->key())
    {
        case Qt::Key::Key_Escape:
        qDebug() << "ESCAPE pressed";
        close();
        break;

        default:
        qDebug() << "Unhandled key press";
        break;
    }
}
