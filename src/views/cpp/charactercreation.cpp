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
    ui->SkillpointsLabel->setText(QString("Skill points: %0").arg(charCreateModel->getMaxSkillPoints()));
    displayPlayerProperties();

    //Connect data entry
    //STRENGTH
    connect(ui->incStrength,&QPushButton::clicked,this,[=](){
        ui->strengthLabel->setText(QString::number(charCreateModel->addPointStrength(1)));
        ui->SkillpointsLabel->setText(QString::number(charCreateModel->getMaxSkillPoints()));
    });
    connect(ui->decStrength,&QPushButton::clicked,this,[=](){
        ui->strengthLabel->setText(QString::number(charCreateModel->addPointStrength(-1)));
        ui->SkillpointsLabel->setText(QString::number(charCreateModel->getMaxSkillPoints()));
    });

    //INTELLECT
    connect(ui->incIntellct,&QPushButton::clicked,this,[=](){
        ui->intellectLabel->setText(QString::number(charCreateModel->addPointIntellect(1)));
        ui->SkillpointsLabel->setText(QString::number(charCreateModel->getMaxSkillPoints()));
    });
    connect(ui->decIntellct,&QPushButton::clicked,this,[=](){
        ui->intellectLabel->setText(QString::number(charCreateModel->addPointIntellect(-1)));
        ui->SkillpointsLabel->setText(QString::number(charCreateModel->getMaxSkillPoints()));
    });

    //STAMINA
    connect(ui->incStamina,&QPushButton::clicked,this,[=](){
        ui->staminaLabel->setText(QString::number(charCreateModel->addPointStamina(1)));
        ui->SkillpointsLabel->setText(QString::number(charCreateModel->getMaxSkillPoints()));
    });
    connect(ui->decStamina,&QPushButton::clicked,this,[=](){
        ui->staminaLabel->setText(QString::number(charCreateModel->addPointStamina(-1)));
        ui->SkillpointsLabel->setText(QString::number(charCreateModel->getMaxSkillPoints()));
    });


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
