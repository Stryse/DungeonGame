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
    m.loadMapFromFile(":/resources/maps/Map_01.txt");
    game = new GameLogicModel(this,m,p);
    loadBlockField();

    ui->mapNameLabel->setText(game->getActiveMap().getMapName());
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

void GameFieldUI::loadBlockField()
{
    blockField.clear(); // POSSIBLE SEGFAULT POINT

    int mapSize = game->getActiveMap().getSize();
    blockField.resize(mapSize);
    for(int row = 0; row < mapSize; ++row)
    {
        blockField[row].resize(mapSize);
        for(int col = 0; col < mapSize; ++col)
        {
            // dynamically get path of lit block image
            QString litPath = game->getActiveMap().getGameBlock(row,col)
                                  ->getLightTexturePath(AbstractGameBlock::LightLevel::LIT);
            // dynamically get path of unlit block image
            QString unlitPath = game->getActiveMap().getGameBlock(row,col)
                                  ->getLightTexturePath(AbstractGameBlock::LightLevel::UNLIT);

            // Insert Lit texture to blocktextures
            if(!blockTextures.contains(litPath))
                blockTextures.insert(litPath,QPixmap(litPath));
            // Insert Unlit texture to blocktextures
            if(!blockTextures.contains(unlitPath))
                blockTextures.insert(unlitPath,QPixmap(unlitPath));



            blockField[row][col] = new AbstractGameBlockWidget(this,
                                                               blockTextures[litPath],
                                                               blockTextures[unlitPath],
                                                               *game->getActiveMap().getGameBlock(row,col));

            ui->gameFieldGrid->addWidget(blockField[row][col],row,col);
        }
    }
}
