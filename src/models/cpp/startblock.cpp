#include "startblock.h"
#include <QDebug>


StartBlock::StartBlock() : RoadBlock()
{
    PopulateTextures();
}

StartBlock::~StartBlock(){}

void StartBlock::PopulateTextures()
{
    textures[LightLevel::UNLIT]    = ":/resources/img/blocks/wall_unlit.jpg";
    textures[LightLevel::LIT]      = ":/resources/img/blocks/trapdoor_lit.jpg";
    textures[LightLevel::HALF_LIT] = ":/resources/img/blocks/trapdoor_half_lit.png";
}

void StartBlock::DoPlayerExit(const Player& player)
{
    RoadBlock::DoPlayerExit(player);
    emit startLeft();
    qDebug() << "Start block left...";
}
