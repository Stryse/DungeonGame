#include "charactercreation.h"
#include "ui_character_creation.h"

CharacterCreation::CharacterCreation(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::char_create_widget)
{
    ui->setupUi(this);
}

void CharacterCreation::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
