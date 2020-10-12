#include "gameloader.h"
#include "ui_gameloader.h"
#include <QPainter>
#include <QDebug>
#include "playerdataaccessimpl.h"
#include "mapdataaccessimpl.h"
#include "gamelogicmodel.h"

//Loads map and player and constructs game instance
GameLoaderUI::GameLoaderUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameLoader),
    model(new GameLoaderModel(this,new PlayerDataAccessImpl(),new MapDataAccessImpl()))
{
    //CONSTRUCT UI
    ui->setupUi(this);
    displaySelectedPlayer();
    populateMapTable();


    //CONNECT TABLE WIDGET SELCTION
    connect(ui->maps,&QTableWidget::itemClicked,this,[=](){
        ui->playBtn->setEnabled(true);
        model->setActiveMap(ui->maps->currentRow());
    });


    //CONNECT BUTTONS
    //Portrait
    connect(ui->nextBtn,&QPushButton::clicked,[=](){ model->nextPlayer(); displaySelectedPlayer();});
    connect(ui->prevBtn,&QPushButton::clicked,[=](){ model->prevPlayer(); displaySelectedPlayer();});
    //Navigation
    connect(ui->cancelBtn,&QPushButton::clicked,this,&QWidget::close);
    connect(ui->playBtn,  &QPushButton::clicked,this,[=](){

        GameLogicModel* gameInstance = model->createGame(nullptr);
        GameFieldUI* gameField = new GameFieldUI(nullptr,gameInstance);
        gameInstance->setParent(gameField);

        emit gameLoaded(gameField);
    });
}

//Updates UI With selected player
void GameLoaderUI::displaySelectedPlayer()
{
    ui->playerNameLabel->setText(model->getActivePlayer()->getPlayerName());
    ui->playerPortraitWidget->setPixmap(model->getActivePlayer()->getPortrait());
    ui->playerPortraitWidget->update();
}

void GameLoaderUI::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void GameLoaderUI::populateMapTable()
{
    ui->maps->setRowCount(model->getMaps().size());
    ui->maps->setHorizontalHeaderLabels(QStringList({"Pálya név","Nehézség","Méret"}));
    ui->maps->horizontalHeader()->show();

    int row = 0;
    foreach(const auto& map, model->getMaps())
    {
        QTableWidgetItem* mapNameItem = new QTableWidgetItem(map->getMapName());
        QTableWidgetItem* mapDifficultyItem = new QTableWidgetItem((map->getSize() < 15 ? "Könnyű" : "Nehéz"));
        QTableWidgetItem* mapSizeItem = new QTableWidgetItem(QString("%0x%0").arg(QString::number(map->getSize())));

        ui->maps->setItem(row,0,mapNameItem);
        ui->maps->setItem(row,1,mapDifficultyItem);
        ui->maps->setItem(row,2,mapSizeItem);
        ++row;
    }
}

GameLoaderUI::~GameLoaderUI()
{
    delete ui;
    delete model;
    qDebug() << "Game loader closed and deallocated";
}
