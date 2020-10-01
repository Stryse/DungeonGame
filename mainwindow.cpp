#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->charcreateBtn,&QPushButton::clicked,this,&MainWindow::openCharacterCreation);
    connect(ui->quitBtn,&QPushButton::clicked,this,&QMainWindow::close);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openCharacterCreation()
{
    //Close Menu
    ui->menuWidget->hide();

    //Open Character creation
    charCreateUI = new CharacterCreation(ui->centralwidget);

    ui->viewport->insertWidget(0,charCreateUI,Qt::AlignHCenter);
    charCreateUI->setAttribute(Qt::WA_DeleteOnClose);
    charCreateUI->show();

    //Show menu again if closed
    connect(charCreateUI,&QWidget::destroyed,this,[=](){ ui->menuWidget->show(); });
}
