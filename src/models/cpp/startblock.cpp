#include "startblock.h"
#include <QDebug>


StartBlock::StartBlock() : RoadBlock()
{
    PopulateTextures();
}

StartBlock::~StartBlock(){}

void StartBlock::PopulateTextures()
{
    textures[LightLevel::UNLIT]    = ":/resources/img/blocks/trapdoor_unlit.jpg";
    textures[LightLevel::LIT]      = ":/resources/img/blocks/trapdoor_lit.jpg";
    textures[LightLevel::HALF_LIT] = ":/resources/img/blocks/trapdoor_half_lit.png";
}

void StartBlock::DoPlayerExit(const Player& player)
{
    // Closing Trapdoor
    closeTrapdoor();
    emit updateTextures();

    //Exiting
    RoadBlock::DoPlayerExit(player);
    qDebug() << "Start block left...";
}

void StartBlock::closeTrapdoor()
{
    textures[LightLevel::UNLIT]    = ":/resources/img/blocks/trapdoor_unlit.jpg";
    textures[LightLevel::LIT]      = ":/resources/img/blocks/trapdoor_closed_lit.jpg";
    textures[LightLevel::HALF_LIT] = ":/resources/img/blocks/trapdoor_closed_half_lit.jpg";
}
