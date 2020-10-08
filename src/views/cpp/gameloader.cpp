#include "gameloader.h"
#include "ui_gameloader.h"
#include <QPainter>
#include <QDebug>

GameLoader::GameLoader(QWidget *parent, IPlayerDataAccess* pdataImpl, IMapDataAccess* mapdataImpl) :
    QWidget(parent),
    ui(new Ui::GameLoader),
    playerDataAccess(pdataImpl),
    activePlayerInd(0),
    mapDataAccess(mapdataImpl)
{
    ui->setupUi(this);

    if(playerDataAccess->isAvailable() && playerDataAccess->loadPlayers(players))
    {
        qDebug() << "Players are Loaded";
        setSelectedPlayer(0);
    }

    if(mapDataAccess->isAvailable() && mapDataAccess->loadMaps(maps))
    {
        qDebug() << "Maps are Loaded";
    }

    populateMapTable();

    connect(ui->nextBtn,&QPushButton::clicked,this,[=](){
        setSelectedPlayer((++activePlayerInd) % players.size());
    });
    connect(ui->prevBtn,&QPushButton::clicked,this,[=](){
        setSelectedPlayer((--activePlayerInd % players.size() + players.size()) % players.size());
    });
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

void GameLoader::populateMapTable()
{
    ui->maps->setRowCount(maps.size());
    ui->maps->setHorizontalHeaderLabels(QStringList({"Pálya név","Nehézség","Méret"}));
    ui->maps->horizontalHeader()->show();

    int row = 0;
    for(auto& map : maps)
    {
        QTableWidgetItem* mapNameItem = new QTableWidgetItem(map->getMapName());
        QTableWidgetItem* mapDifficultyItem = new QTableWidgetItem("Könnyű");
        QTableWidgetItem* mapSizeItem = new QTableWidgetItem(QString("%0x%0").arg(QString::number(map->getSize())));

        ui->maps->setItem(row,0,mapNameItem);
        ui->maps->setItem(row,1,mapDifficultyItem);
        ui->maps->setItem(row,2,mapSizeItem);
        ++row;
    }
}

GameLoader::~GameLoader()
{
    delete ui;
    delete playerDataAccess;
    delete mapDataAccess;
    for(auto& p : players) delete p;
    for(auto& m : maps) delete m;
    qDebug() << "Game loader closed and deallocated";
}
