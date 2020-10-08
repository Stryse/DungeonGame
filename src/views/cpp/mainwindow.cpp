#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "playerdataaccessimpl.h"
#include "mapdataaccessimpl.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->newgameBtn,&QPushButton::clicked,this,[=](){
            changeWindow(new GameLoader(this,new PlayerDataAccessImpl(),new MapDataAccessImpl()));
    });
    connect(ui->charcreateBtn,&QPushButton::clicked,this,[=](){
            changeWindow(new CharacterCreation(this));
    });
    connect(ui->quitBtn,&QPushButton::clicked,this,&QMainWindow::close);

    connect(ui->loadGameBtn,&QPushButton::clicked,this,[=](){
            changeWindow(new GameLoader(this,new PlayerDataAccessImpl(),new MapDataAccessImpl()));
    });
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
    window->exec();
}
