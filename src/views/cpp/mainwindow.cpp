#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , charCreateUI(nullptr)
{
    ui->setupUi(this);
    connect(ui->charcreateBtn,&QPushButton::clicked,this,&MainWindow::openCharacterCreation);
    connect(ui->quitBtn,&QPushButton::clicked,this,&QMainWindow::close);
}

MainWindow::~MainWindow()
{
    delete charCreateUI;
    delete ui;
}

void MainWindow::openCharacterCreation()
{
    //Close Menu
    ui->menuWidget->hide();

    //Open Character creation
    charCreateUI = new CharacterCreation(this);

    ui->viewport->insertWidget(0,charCreateUI,Qt::AlignHCenter);
    charCreateUI->setAttribute(Qt::WA_DeleteOnClose);
    charCreateUI->show();

    //Show menu again if closed
    connect(charCreateUI,&QWidget::destroyed,this,&MainWindow::showMenu);
}

void MainWindow::showMenu()
{
    charCreateUI = nullptr;
    ui->menuWidget->show();
}
