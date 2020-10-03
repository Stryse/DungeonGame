#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , charCreateUI(nullptr)
{
    ui->setupUi(this);
    connect(ui->newgameBtn,&QPushButton::clicked,this,&MainWindow::openNewGame);
    connect(ui->charcreateBtn,&QPushButton::clicked,this,&MainWindow::openCharacterCreation);
    connect(ui->quitBtn,&QPushButton::clicked,this,&QMainWindow::close);
}

MainWindow::~MainWindow()
{
    delete charCreateUI;
    delete gameUI;
    delete ui;
}

void MainWindow::openNewGame()
{
    //Open Character creation
    gameUI = new GameFieldUI(this);
    gameUI->setAttribute(Qt::WA_DeleteOnClose);
    updateViewPort(gameUI);
}

void MainWindow::openCharacterCreation()
{
    //Open Character creation
    charCreateUI = new CharacterCreation(this);
    charCreateUI->setAttribute(Qt::WA_DeleteOnClose);
    updateViewPort(charCreateUI);
}

void MainWindow::showMenu()
{
    charCreateUI = nullptr;
    gameUI = nullptr;
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
