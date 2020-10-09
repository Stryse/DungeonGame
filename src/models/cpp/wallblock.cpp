#include "wallblock.h"

WallBlock::WallBlock() : AbstractGameBlock()
{
    PopulateTextures();
}

WallBlock::~WallBlock(){}

void WallBlock::PopulateTextures()
{
    textures[LightLevel::UNLIT]    = ":/resources/img/blocks/wall_unlit.jpg";
    textures[LightLevel::LIT]      = ":/resources/img/blocks/wall.jpg";
    textures[LightLevel::HALF_LIT] = ":/resources/img/blocks/wall_half_lit.jpg";
}

void WallBlock::DoPlayerEnter(const Player&){}
void WallBlock::DoPlayerExit(const Player&){}
bool WallBlock::isLightBlocking() const { return true; }
