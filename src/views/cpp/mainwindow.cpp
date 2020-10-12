#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gameloader.h"
#include "gamefieldui.h"
#include "victoryscreen.h"
#include "charactercreation.h"
#include <QDebug>

//This class is managing different windows that appear in viewport
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // CONNECT NEW GAME (GameLoader)
    connect(ui->newgameBtn,&QPushButton::clicked,[=](){
            GameLoaderUI* gameLoader = new GameLoaderUI(this);

            //Connect Gamefield -- Managed by GameLoader
            connect(gameLoader,&GameLoaderUI::gameLoaded,[=](GameFieldUI* gameField){
                    GameFieldUI* gameFieldUI = gameField;
                    gameFieldUI->setParent(this);
                    gameLoader->close();

                    //Connect Victory Screen -- Managed by GameField
                    connect(gameFieldUI,&GameFieldUI::showVictoryScreen,[=](VictoryScreen* victoryS){
                            VictoryScreen* victoryScreen = victoryS;
                            victoryScreen->setParent(this);
                            gameFieldUI->close();
                            changeWindow(victoryScreen);
                    });
                    changeWindow(gameFieldUI);
            });
            changeWindow(gameLoader);
    });

    // Connect Character Creation
    connect(ui->charcreateBtn,&QPushButton::clicked,this,[=](){
            changeWindow(new CharacterCreation(this));
    });

    // Connect Quit
    connect(ui->quitBtn,&QPushButton::clicked,this,&QMainWindow::close);
}

MainWindow::~MainWindow()
{
    qDebug() << "Mainwindow closed and deallocated";
    delete ui;
}

//Displays window in viewport
void MainWindow::changeWindow(QWidget* window)
{
    window->setAttribute(Qt::WA_DeleteOnClose);

    //Close Menu
    ui->menuWidget->hide();

    //Add Widget
    ui->viewPortLayout->addWidget(window,1,1,Qt::AlignCenter);

    // Back to menu if destroyed, deallocate
    auto destroyConnection = connect(window,&QWidget::destroyed,[=](){ ui->menuWidget->show();});
    connect(this,&QWidget::destroyed,[=](){ disconnect(destroyConnection); });
    window->setFocus();
    window->show();
}
