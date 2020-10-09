#include "endblock.h"
#include <QDebug>

EndBlock::EndBlock() : RoadBlock()
{
    PopulateTextures();
}

EndBlock::~EndBlock()
{}

void EndBlock::PopulateTextures()
{
    textures[LightLevel::UNLIT]    = ":/resources/img/blocks/exit_unlit.jpg";
    textures[LightLevel::LIT]      = ":/resources/img/blocks/exit_lit.jpg";
    textures[LightLevel::HALF_LIT] = ":/resources/img/blocks/exit_half_lit.jpg";
}
