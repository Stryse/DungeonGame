#include "abstractgameblock.h"
#include "roadblock.h"
#include "wallblock.h"

AbstractGameBlock::AbstractGameBlock(QObject *parent)
    : QObject(parent),hasPlayer(0),lightLevel(AbstractGameBlock::LightLevel::UNLIT)
{
}

AbstractGameBlock *AbstractGameBlock::create(const QString& type)
{
    if      (type == 'R') return new RoadBlock();
    else if (type == 'W') return new WallBlock();

    return nullptr;
}

bool AbstractGameBlock::getHasPlayer() const
{
    return hasPlayer;
}

AbstractGameBlock::LightLevel AbstractGameBlock::getLightLevel() const
{
    return lightLevel;
}

void AbstractGameBlock::setLightLevel(const LightLevel &value)
{
    lightLevel = value;
}
