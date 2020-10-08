#include "gamefieldui.h"
#include "ui_gamefieldui.h"

#include <QPainter>
#include <QBrush>
#include <QPalette>
#include <QSizePolicy>
#include <QKeyEvent>
#include <QDebug>

GameFieldUI::GameFieldUI(QWidget *parent, GameLogicModel* game) :
    QWidget(parent),
    ui(new Ui::GameFieldUI),
    game(game)
{
    ui->setupUi(this);

    // UPDATE UI WITH GAME DATA
    ui->playerPortraitWidget->setPixmap(game->getPlayer().getPortrait());
    ui->playerNameLabel->setText(game->getPlayer().getPlayerName());
    ui->mapNameLabel->setText(game->getActiveMap().getMapName());
    loadBlockField();
    setFocus();

    // CONNECT UI EVENTS TO GAME LOGIC
    connect(this,SIGNAL(UIReady()),game,SLOT(onUIReady()));
    connect(ui->navUp,&QPushButton::clicked,[=](){ game->movePlayer(Map::Direction::UP);});
    connect(ui->navDown,&QPushButton::clicked,[=](){ game->movePlayer(Map::Direction::DOWN);});
    connect(ui->navLeft,&QPushButton::clicked,[=](){ game->movePlayer(Map::Direction::LEFT);});
    connect(ui->navRight,&QPushButton::clicked,[=](){ game->movePlayer(Map::Direction::RIGHT);});

    emit UIReady();
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

void GameFieldUI::loadBlockField()
{
    blockField.clear();
    int mapSize = game->getActiveMap().getSize();

    blockField.resize(mapSize);
    for(int row = 0; row < mapSize; ++row)
    {
        blockField[row].resize(mapSize);
        for(int col = 0; col < mapSize; ++col)
        {
            QString lit = loadLightTexture(row,col,AbstractGameBlock::LightLevel::LIT);
            QString unlit = loadLightTexture(row,col,AbstractGameBlock::LightLevel::UNLIT);
            QString halflit = loadLightTexture(row,col,AbstractGameBlock::LightLevel::HALF_LIT);

            blockField[row][col] = new AbstractGameBlockWidget(this,
                                                               blockTextures[lit],
                                                               blockTextures[unlit],
                                                               blockTextures[halflit],
                                                               *game->getActiveMap().getGameBlock(row,col));

            ui->gameFieldGrid->addWidget(blockField[row][col],row,col);
        }
    }
}

QString GameFieldUI::loadLightTexture(int row, int col,const AbstractGameBlock::LightLevel& lightlevel)
{
    QString texturePath = game->getActiveMap().getGameBlock(row,col)
                              ->getLightTexturePath(lightlevel);

    if(!blockTextures.contains(texturePath))
        blockTextures.insert(texturePath,QPixmap(texturePath));

    return texturePath;
}
