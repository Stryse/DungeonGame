#include "abstractgameblock.h"
#include "roadblock.h"
#include "wallblock.h"
#include "endblock.h"
#include "startblock.h"

//CTOR
AbstractGameBlock::AbstractGameBlock(QObject *parent)
    : QObject(parent),hasPlayer(0),lightLevel(AbstractGameBlock::LightLevel::UNLIT)
{}

AbstractGameBlock::~AbstractGameBlock()
{}

//Static Factory
AbstractGameBlock *AbstractGameBlock::create(const QString& type)
{
    if      (type == 'R') return new RoadBlock();
    else if (type == 'W') return new WallBlock();
    else if (type == 'E') return new EndBlock();
    else if (type == 'S') return new StartBlock();

    return nullptr;
}


//Getter
bool AbstractGameBlock::getHasPlayer() const
    { return hasPlayer; }

AbstractGameBlock::LightLevel AbstractGameBlock::getLightLevel() const
    { return lightLevel; }


//Setter
void AbstractGameBlock::setHasPlayer(bool value)
    { hasPlayer = value; }

void AbstractGameBlock::setLightLevel(const AbstractGameBlock::LightLevel& value)
{
    if(lightLevel != value)
    {
        lightLevel = value;
        emit lightLevelChanged(lightLevel);
    }
}


//Virtual methods with implementation
QString AbstractGameBlock::getLightTexturePath(const AbstractGameBlock::LightLevel& lightlevel) const
{
    if(textures.contains(lightlevel))
        return textures.value(lightlevel);
    else
        return ":/resources/img/blocks/invalid_block.png"; //Default texture
}
