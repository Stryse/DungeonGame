#include "charactercreation.h"
#include "ui_character_creation.h"

#include <QDebug>
#include <QStyleOption>
#include <QPainter>

CharacterCreation::CharacterCreation(QWidget *parent, IPlayerDataAccess* playerDataAccess)
    : QDialog(parent)
    , ui(new Ui::char_create_widget)
    , playerDataAccess(playerDataAccess)
{
    ui->setupUi(this);
    playerDataAccess->loadAvailablePortraits(playerPortraits);
    ui->portrait->setPixmap(playerPortraits[0]);

    connect(ui->cancelBtn,&QPushButton::clicked,this,&QWidget::close);
    qDebug() << "Character creation opened";
}

CharacterCreation::~CharacterCreation()
{
    qDebug() << "Character creation window closed and deallocated";
    delete ui;
}

void CharacterCreation::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
