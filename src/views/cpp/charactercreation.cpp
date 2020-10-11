#include "charactercreation.h"
#include "ui_character_creation.h"

#include <QDebug>
#include <QStyleOption>
#include <QPainter>
#include <QPixmap>

#include "playerdataaccessimpl.h"

CharacterCreation::CharacterCreation(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::char_create_widget)
    , charCreateModel(new CharacterCreationModel(this, new PlayerDataAccessImpl()))
    , activePortraitInd(0)
{
    ui->setupUi(this);

    //Load Portraits
    charCreateModel->getPlayerDataAccess()->loadAvailablePortraits(playerPortraitsPaths);

    //Display player properties
    ui->portrait->setPixmap(playerPortraitsPaths[0]);
    ui->SkillpointsLabel->setText(QString("Skill points: %0").arg(charCreateModel->getMaxSkillPoints()));

    //CONNECT DATA ENTRY
    //Playername
    connect(ui->pnameEdit,&QLineEdit::textChanged,
            charCreateModel,[=](const QString& text){

        ui->createBtn->setEnabled(text != "" && text[0] != ' ');
        charCreateModel->setPlayerName(text);
    });

    //Player portrait
    connectPLayerPortrait();

    //Skill points
    connectPlayerStrength();
    connectPlayerIntellect();
    connectPlayerStamina();

    //CONNECT ACTION BUTTONS
    //Cancel
    connect(ui->cancelBtn,&QPushButton::clicked,this,&QWidget::close);

    //Create
    connect(ui->createBtn,&QPushButton::clicked,this,[=](){
            charCreateModel->getPlayerDataAccess()
                           ->savePlayer(*charCreateModel->makePlayer());
            close();
    });

    qDebug() << "Character creation opened";
}

CharacterCreation::~CharacterCreation()
{
    qDebug() << "Character creation window closed and deallocated";
    delete charCreateModel;
    delete ui;
}

void CharacterCreation::connectPlayerStrength()
{
    //STRENGTH increment
    connect(ui->incStrength,&QPushButton::clicked,this,[=](){
        ui->strengthLabel->setText(QString::number(charCreateModel->addPointStrength(1)));
        ui->SkillpointsLabel->setText(QString("Skill points: %0")
                .arg(QString::number(charCreateModel->getMaxSkillPoints())));
    });

    //STRENGTH decrement
    connect(ui->decStrength,&QPushButton::clicked,this,[=](){
        ui->strengthLabel->setText(QString::number(charCreateModel->addPointStrength(-1)));
        ui->SkillpointsLabel->setText(QString("Skill points: %0")
                .arg(QString::number(charCreateModel->getMaxSkillPoints())));
    });
}

void CharacterCreation::connectPlayerIntellect()
{
    //INTELLECT increment
    connect(ui->incIntellct,&QPushButton::clicked,this,[=](){
        ui->intellectLabel->setText(QString::number(charCreateModel->addPointIntellect(1)));
        ui->SkillpointsLabel->setText(QString("Skill points: %0")
                .arg(QString::number(charCreateModel->getMaxSkillPoints())));
    });
    //INTELLECT decrement
    connect(ui->decIntellct,&QPushButton::clicked,this,[=](){
        ui->intellectLabel->setText(QString::number(charCreateModel->addPointIntellect(-1)));
        ui->SkillpointsLabel->setText(QString("Skill points: %0")
                .arg(QString::number(charCreateModel->getMaxSkillPoints())));
    });
}

void CharacterCreation::connectPlayerStamina()
{
    //STAMINA increment
    connect(ui->incStamina,&QPushButton::clicked,this,[=](){
        ui->staminaLabel->setText(QString::number(charCreateModel->addPointStamina(1)));
        ui->SkillpointsLabel->setText(QString("Skill points: %0")
                .arg(QString::number(charCreateModel->getMaxSkillPoints())));
    });

    //STAMINA decrement
    connect(ui->decStamina,&QPushButton::clicked,this,[=](){
        ui->staminaLabel->setText(QString::number(charCreateModel->addPointStamina(-1)));
        ui->SkillpointsLabel->setText(QString("Skill points: %0")
                .arg(QString::number(charCreateModel->getMaxSkillPoints())));
    });

}

void CharacterCreation::connectPLayerPortrait()
{
    //Next
    connect(ui->nextBtn,&QPushButton::clicked,this,[=](){
        activePortraitInd = ((++activePortraitInd % playerPortraitsPaths.size()) + playerPortraitsPaths.size()) % playerPortraitsPaths.size();
        ui->portrait->setPixmap(playerPortraitsPaths[activePortraitInd]);

        charCreateModel->setPlayerPortraitPath(playerPortraitsPaths[activePortraitInd]);
        ui->portrait->update();
    });
    //Prev
    connect(ui->prevBtn,&QPushButton::clicked,this,[=](){
        activePortraitInd = ((--activePortraitInd % playerPortraitsPaths.size()) + playerPortraitsPaths.size()) % playerPortraitsPaths.size();
        ui->portrait->setPixmap(playerPortraitsPaths[activePortraitInd]);

        charCreateModel->setPlayerPortraitPath(playerPortraitsPaths[activePortraitInd]);
        ui->portrait->update();
    });
}

void CharacterCreation::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
