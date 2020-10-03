#include "gamefieldui.h"
#include "ui_gamefieldui.h"

#include <QKeyEvent>
#include <QDebug>

GameFieldUI::GameFieldUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameFieldUI)
{
    ui->setupUi(this);
    setFocus();
}

GameFieldUI::~GameFieldUI()
{
    delete ui;
}

// Navigation keys are mapped through shortcuts
void GameFieldUI::keyPressEvent(QKeyEvent* event)
{
    switch (event->key())
    {
        case Qt::Key::Key_Escape:
        qDebug() << "ESCAPE pressed";
        break;

        default:
        qDebug() << "Unhandled key press";
        break;
    }
}
