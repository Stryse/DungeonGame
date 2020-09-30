#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "charactercreation.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->charcreateBtn,&QPushButton::clicked,this,&MainWindow::openCharacterCreation);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openCharacterCreation()
{
    ui->menuWidget->hide();
    CharacterCreation* charCreate = new CharacterCreation(ui->centralwidget);
    ui->viewport->insertWidget(0,charCreate,Qt::AlignHCenter);
    charCreate->show();
}

