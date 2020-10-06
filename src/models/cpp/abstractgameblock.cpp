#include "abstractgameblock.h"
#include "roadblock.h"
#include "wallblock.h"
#include "endblock.h"

AbstractGameBlock::AbstractGameBlock(QObject *parent)
    : QObject(parent),hasPlayer(0),lightLevel(AbstractGameBlock::LightLevel::UNLIT)
{
}

AbstractGameBlock *AbstractGameBlock::create(const QString& type)
{
    if      (type == 'R') return new RoadBlock();
    else if (type == 'W') return new WallBlock();
    else if (type == 'E') return new EndBlock();

    return nullptr;
}

bool AbstractGameBlock::getHasPlayer() const
{
    return hasPlayer;
}

void AbstractGameBlock::setHasPlayer(bool value)
{
    hasPlayer = value;
}

AbstractGameBlock::LightLevel AbstractGameBlock::getLightLevel() const
{
    return lightLevel;
}

void AbstractGameBlock::setLightLevel(const AbstractGameBlock::LightLevel& value)
{
    if(lightLevel != value)
    {
        lightLevel = value;
        emit lightLevelChanged(lightLevel);
    }
}
