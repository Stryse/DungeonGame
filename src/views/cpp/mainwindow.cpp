#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "playerdataaccessimpl.h"
#include "mapdataaccessimpl.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //connect(ui->newgameBtn,&QPushButton::clicked,this,&MainWindow::openNewGame);
    connect(ui->charcreateBtn,&QPushButton::clicked,this,&MainWindow::openCharacterCreation);
    connect(ui->quitBtn,&QPushButton::clicked,this,&QMainWindow::close);
    connect(ui->loadGameBtn,&QPushButton::clicked,this,&MainWindow::openLoadGame);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openCharacterCreation()
{
    CharacterCreation* charCreateUI = new CharacterCreation(this);
    charCreateUI->setAttribute(Qt::WA_DeleteOnClose);
    updateViewPort(charCreateUI);
}

void MainWindow::openLoadGame()
{
    GameLoader* gameLoader = new GameLoader(this,new PlayerDataAccessImpl(),new MapDataAccessImpl());
    gameLoader->setAttribute(Qt::WA_DeleteOnClose);
    updateViewPort(gameLoader);
}

void MainWindow::showMenu()
{
    ui->menuWidget->show();
}

void MainWindow::updateViewPort(QDialog *w)
{
    //Close Menu
    ui->menuWidget->hide();

    //Add Widget
    ui->viewPortLayout->addWidget(w,1,1,Qt::AlignCenter);

    // Back to menu if destroyed, deallocate
    connect(w,&QWidget::destroyed,this,&MainWindow::showMenu);
    w->exec();
}
