#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "playerdataaccessimpl.h"
#include "mapdataaccessimpl.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connect New Game
    connect(ui->newgameBtn,&QPushButton::clicked,[=](){
            GameLoader* gameLoader = new GameLoader(this);

            //Connect Opening GameField
            connect(gameLoader,&GameLoader::gameLoaded,[=](GameFieldUI* gameField){
                    GameFieldUI* gameFieldUI = gameField;
                    gameFieldUI->setParent(this);
                    gameLoader->close();

                    //Connect Victory Screen
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
