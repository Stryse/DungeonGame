#include "charactercreation.h"
#include "ui_character_creation.h"

#include <QDebug>

CharacterCreation::CharacterCreation(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::char_create_widget)
{
    ui->setupUi(this);
    connect(ui->cancelBtn,&QPushButton::clicked,this,&QWidget::close);
}

CharacterCreation::~CharacterCreation()
{
    delete ui;
    qDebug() << "Character creation window closed and deallocated\n";
}

void CharacterCreation::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
