#include "gameloader.h"
#include "ui_gameloader.h"
#include <QPainter>

GameLoader::GameLoader(QWidget *parent, PlayerDataAccess* pdataImpl, MapDataAccess* mapdataImpl) :
    QWidget(parent),
    ui(new Ui::GameLoader),
    activePlayerInd(0),
    playerDataAccess(pdataImpl),
    mapDataAccess(mapdataImpl)
{
    ui->setupUi(this);

    if(playerDataAccess->isAvailable() && playerDataAccess->loadPlayers(players))
        setSelectedPlayer(0);

    connect(ui->nextBtn,&QPushButton::clicked,this,[=](){ setSelectedPlayer((++activePlayerInd) % players.size()); });
    connect(ui->prevBtn,&QPushButton::clicked,this,[=](){ setSelectedPlayer((--activePlayerInd) % players.size()); });
    connect(ui->maps,&QTableWidget::itemClicked,this,[=](){ ui->playBtn->setEnabled(true); });
    connect(ui->cancelBtn,&QPushButton::clicked,this,&QWidget::close);

}

void GameLoader::setSelectedPlayer(int playerInd)
{
    activePlayerInd = playerInd;
    ui->playerNameLabel->setText(players[activePlayerInd]->getPlayerName());
    ui->playerPortraitWidget->setPixmap(players[activePlayerInd]->getPortrait());
    ui->playerPortraitWidget->update();
}

void GameLoader::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

GameLoader::~GameLoader()
{
    delete ui;
}
