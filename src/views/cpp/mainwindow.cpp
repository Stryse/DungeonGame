#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "playerdataaccessimpl.h"
#include "mapdataaccessimpl.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , charCreateUI(nullptr)
{
    ui->setupUi(this);
    //connect(ui->newgameBtn,&QPushButton::clicked,this,&MainWindow::openNewGame);
    connect(ui->charcreateBtn,&QPushButton::clicked,this,&MainWindow::openCharacterCreation);
    connect(ui->quitBtn,&QPushButton::clicked,this,&QMainWindow::close);
    connect(ui->loadGameBtn,&QPushButton::clicked,this,&MainWindow::openLoadGame);
}

MainWindow::~MainWindow()
{
    delete gameLoader;
    delete charCreateUI;
    delete ui;
}

void MainWindow::openCharacterCreation()
{
    //Open Character creation
    charCreateUI = new CharacterCreation(this);
    charCreateUI->setAttribute(Qt::WA_DeleteOnClose);
    updateViewPort(charCreateUI);
}

void MainWindow::openLoadGame()
{
    gameLoader = new GameLoader(this,new PlayerDataAccessImpl(),new MapDataAccessImpl());
    gameLoader->setAttribute(Qt::WA_DeleteOnClose);
    updateViewPort(gameLoader);
}

void MainWindow::showMenu()
{
    charCreateUI = nullptr;
    gameLoader = nullptr;
    ui->menuWidget->show();
}

void MainWindow::updateViewPort(QWidget *w)
{
    //Close Menu
    ui->menuWidget->hide();

    //Add Widget
    ui->viewPortLayout->addWidget(w,1,1,Qt::AlignCenter);

    // Back to menu if destroyed
    connect(w,&QWidget::destroyed,this,&MainWindow::showMenu);
    w->show();
}
