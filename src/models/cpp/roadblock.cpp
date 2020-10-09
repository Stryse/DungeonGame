#include "roadblock.h"

RoadBlock::RoadBlock() : AbstractGameBlock()
{
    PopulateTextures();
}

RoadBlock::~RoadBlock(){}

void RoadBlock::PopulateTextures()
{
    textures[LightLevel::UNLIT]    = ":/resources/img/blocks/wall_unlit.jpg";
    textures[LightLevel::LIT]      = ":/resources/img/blocks/road.jpg";
    textures[LightLevel::HALF_LIT] = ":/resources/img/blocks/road_half_lit.jpg";
}

void RoadBlock::DoPlayerEnter(const Player& player)
{
    setHasPlayer(true);
    emit AbstractGameBlock::playerEntered(player);
}

void RoadBlock::DoPlayerExit(const Player& player)
{
    setHasPlayer(false);
    emit AbstractGameBlock::playerExited(player);
}

bool RoadBlock::isLightBlocking() const
{
    return false;
}
