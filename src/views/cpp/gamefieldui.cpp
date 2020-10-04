#include "gamefieldui.h"
#include "ui_gamefieldui.h"

#include <QPainter>
#include <QBrush>
#include <QPalette>
#include <QSizePolicy>
#include <QKeyEvent>
#include <QDebug>

GameFieldUI::GameFieldUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameFieldUI)
{
    ui->setupUi(this);

    QPixmap portrait(":/resources/img/player/amonguscyan.png");


    // TODO: change to gamedata
    Player p(this,&portrait,"Cyan",1,2,3);
    ui->playerPortraitWidget->setPixmap(portrait);
    ui->playerNameLabel->setText(p.getPlayerName());

    // TODO: DELETE object creation here
    Map m(this);
    game = new GameLogicModel(this,m,p);
    loadBlockTypes();
    loadBlockField();

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

void GameFieldUI::loadBlockTypes()
{
    wallTexture = QPixmap(":/resources/img/blocks/wall.jpg");
    roadTexture = QPixmap(":/resources/img/blocks/road.jpg");
    blockTypes.push_back(new AbstractGameBlockWidget(nullptr,roadTexture,wallTexture));
    blockTypes.push_back(new AbstractGameBlockWidget(nullptr,wallTexture,wallTexture));
}

void GameFieldUI::loadBlockField()
{
    int mapSize = game->getActiveMap().getSize();
    blockField.resize(mapSize);
    for(int row = 0; row < mapSize; ++row)
    {
        blockField[row].resize(mapSize);
        for(int col = 0; col < mapSize; ++col)
        {
            blockField[row][col] = new AbstractGameBlockWidget(this,roadTexture,wallTexture);
            ui->gameFieldGrid->addWidget(blockField[row][col],row,col);
        }
    }
}
