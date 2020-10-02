#include "gamefieldui.h"
#include "ui_gamefieldui.h"

GameFieldUI::GameFieldUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameFieldUI)
{
    ui->setupUi(this);
}

GameFieldUI::~GameFieldUI()
{
    delete ui;
}
