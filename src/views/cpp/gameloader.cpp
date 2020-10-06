#include "gameloader.h"
#include "ui_gameloader.h"
#include <QPainter>

GameLoader::GameLoader(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameLoader)
{
    ui->setupUi(this);
}

void GameLoader::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

GameLoader::~GameLoader()
{
    delete ui;
}
