#include "victoryscreen.h"
#include "ui_victoryscreen.h"
#include <QDebug>

VictoryScreen::VictoryScreen(QWidget *parent, const Player& player, const QTime& playtime) :
    QDialog(parent)
    ,ui(new Ui::VictoryScreen)
    ,player(player)
    ,playTime(playtime)
{
    ui->setupUi(this);
    ui->portrait->setPixmap(player.getPortrait());
    ui->timeLabel->setText(QString("Köridő: %0").arg(playTime.toString("mm:ss")));
    connect(ui->backToMainMenuBtn,&QPushButton::clicked,this,&QDialog::close);
}

VictoryScreen::~VictoryScreen()
{
    qDebug() << "Victory screen closed and deallocated";
    delete ui;
}
