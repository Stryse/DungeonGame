#include "charactercreation.h"
#include "ui_character_creation.h"

#include <QDebug>
#include <QStyleOption>
#include <QPainter>
#include "playerdataaccessimpl.h"

CharacterCreation::CharacterCreation(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::char_create_widget)
{
    ui->setupUi(this);
    QScopedPointer<IPlayerDataAccess> pDataAccess(new PlayerDataAccessImpl());


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
