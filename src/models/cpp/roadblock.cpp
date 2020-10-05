#include "roadblock.h"

RoadBlock::RoadBlock()
{

}

QString RoadBlock::getLightTexturePath(const AbstractGameBlock::LightLevel &lightlevel) const
{
    switch (lightlevel)
    {
        case AbstractGameBlock::LightLevel::LIT:
            return QString(":/resources/img/blocks/road.jpg");
        break;

        case AbstractGameBlock::LightLevel::HALF_LIT:
            return QString(":/resources/img/blocks/road.jpg");
        break;

        case AbstractGameBlock::LightLevel::UNLIT:
            return QString(":/resources/img/blocks/wall.jpg");
        break;

        default:
            return QString(":/resources/img/blocks/invalid_block.png");
        break;
    }
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

//void RoadBlock::setLightLevel(const AbstractGameBlock::LightLevel& value)
//{
//    if(lightLevel != value)
//    {
//        lightLevel = value;
//        emit AbstractGameBlock::lightLevelChanged(lightLevel);
//    }
//}
