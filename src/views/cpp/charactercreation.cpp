#include "charactercreation.h"
#include "ui_character_creation.h"

#include <QDebug>
#include <QStyleOption>
#include <QPainter>
#include "playerdataaccessimpl.h"

CharacterCreation::CharacterCreation(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::char_create_widget)
    , charCreateModel(new CharacterCreationModel(this, new PlayerDataAccessImpl()))
{
    ui->setupUi(this);

    //Load Portraits
    charCreateModel->getPlayerDataAccess()->loadAvailablePortraits(playerPortraits);

    //Display player properties
    ui->portrait->setPixmap(playerPortraits[0]);
    displayPlayerProperties();

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

void CharacterCreation::displayPlayerProperties()
{
    ui->strengthLabel->setText(QString::number(charCreateModel->getPlayerStrength()));
    ui->intellectLabel->setText(QString::number(charCreateModel->getPlayerIntellect()));
    ui->staminaLabel->setText(QString::number(charCreateModel->getPlayerStamina()));
}
