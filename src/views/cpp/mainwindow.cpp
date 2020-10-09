#include "mainwindow.h"
#include "gameloader.h"
#include "charactercreation.h"
#include "ui_mainwindow.h"
#include "playerdataaccessimpl.h"
#include "mapdataaccessimpl.h"
#include "gamefieldui.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connect New Game
    connect(ui->newgameBtn,&QPushButton::clicked,this,[=](){
        GameLoader* gameLoader = new GameLoader(this,new PlayerDataAccessImpl(),new MapDataAccessImpl());
        connect(gameLoader,&GameLoader::gameLoaded,this,[=](GameLogicModel* game){
            gameLoader->close();
            changeWindow(new GameFieldUI(this,game));
    });
        changeWindow(gameLoader);
    });
    // Connect Character Creation
    connect(ui->charcreateBtn,&QPushButton::clicked,this,[=](){
            changeWindow(new CharacterCreation(this));
    });
    // Connect Load Game //TODO new game doesn't work here
    connect(ui->loadGameBtn,&QPushButton::clicked,this,[=](){
            changeWindow(new GameLoader(this,new PlayerDataAccessImpl(),new MapDataAccessImpl()));
    });
    // Connect Quit
    connect(ui->quitBtn,&QPushButton::clicked,this,&QMainWindow::close);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeWindow(QDialog* window)
{
    window->setAttribute(Qt::WA_DeleteOnClose);
    //Close Menu
    ui->menuWidget->hide();

    //Add Widget
    ui->viewPortLayout->addWidget(window,1,1,Qt::AlignCenter);

    // Back to menu if destroyed, deallocate
    connect(window,&QWidget::destroyed,this,[=](){ ui->menuWidget->show(); });
    window->setFocus();
    window->exec();
}
