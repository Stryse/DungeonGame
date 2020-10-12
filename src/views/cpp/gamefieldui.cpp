#include "gamefieldui.h"
#include "ui_gamefieldui.h"

#include <QKeyEvent>
#include <QDebug>

GameFieldUI::GameFieldUI(QWidget *parent, GameLogicModel* game) :
    QWidget(parent),
    ui(new Ui::GameFieldUI),
    game(game)
{
    ui->setupUi(this);

    // UPDATE UI WITH GAME DATA
    ui->playerPortraitWidget->setPixmap(QPixmap(game->getPlayer().getPortrait()));
    ui->playerNameLabel->setText(game->getPlayer().getPlayerName());
    ui->mapNameLabel->setText(game->getActiveMap().getMapName());

    // CONNECT GAME TIMER TICK TO UI
    connect(game,&GameLogicModel::timeTicked,this,[=](const QTime& time){
        ui->timeLabel->setText(time.toString("mm:ss"));
    });

    //Show Victory screen on game ending
    connect(game,&GameLogicModel::gameEnded,[=](const Player& p, const QTime& t){
        VictoryScreen* victoryS = new VictoryScreen(nullptr,p,t);
        emit showVictoryScreen(victoryS);
    });

    loadBlockField();

    // CONNECT UI EVENTS TO GAME LOGIC
    connect(ui->navUp,&QPushButton::clicked,[=](){ game->movePlayer(Map::Direction::UP);});
    connect(ui->navDown,&QPushButton::clicked,[=](){ game->movePlayer(Map::Direction::DOWN);});
    connect(ui->navLeft,&QPushButton::clicked,[=](){ game->movePlayer(Map::Direction::LEFT);});
    connect(ui->navRight,&QPushButton::clicked,[=](){ game->movePlayer(Map::Direction::RIGHT);});

}

GameFieldUI::~GameFieldUI()
{
    delete game;
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

        case Qt::Key::Key_Pause:
        qDebug() << "PAUSE pressed";
        game->pause();
        ui->timeLabel->setText("PAUSED");
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
            blockField[row][col] = new AbstractGameBlockWidget(this,*game->getActiveMap().getGameBlock(row,col));
            ui->gameFieldGrid->addWidget(blockField[row][col],row,col);
        }
    }
}
