#include "wallblock.h"

WallBlock::WallBlock()
{

}

QString WallBlock::getLightTexturePath(const AbstractGameBlock::LightLevel &lightlevel) const
{
    switch (lightlevel)
    {
        case AbstractGameBlock::LightLevel::LIT:
            return QString(":/resources/img/blocks/wall.jpg");
        break;

        case AbstractGameBlock::LightLevel::HALF_LIT:
            return QString(":/resources/img/blocks/wall.jpg");
        break;

        case AbstractGameBlock::LightLevel::UNLIT:
            return QString(":/resources/img/blocks/wall.jpg");
        break;

        default:
            return QString(":/resources/img/blocks/invalid_block.png");
        break;
    }
}

void WallBlock::DoPlayerEnter(const Player&){}
void WallBlock::DoPlayerExit(const Player&){}
