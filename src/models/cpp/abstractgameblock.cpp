#include "abstractgameblock.h"
#include "roadblock.h"

AbstractGameBlock::AbstractGameBlock(QObject *parent) : QObject(parent)
{
}

AbstractGameBlock *AbstractGameBlock::create(const QString& type)
{
    if      (type == 'R') return new RoadBlock();
    //else if (type == 'W') return new WallBlock();

    return nullptr;
}

bool AbstractGameBlock::getHasPlayer() const
{
    return hasPlayer;
}
