#include "lightfiller.h"

LightFiller::LightFiller(QObject *parent, const Map& targetMap, int depth)
    : QObject(parent)
    , targetMap(targetMap)
    , depth(depth)
{
}

void LightFiller::lightFill(const QPoint& location, const AbstractGameBlock::LightLevel& oldValue, const AbstractGameBlock::LightLevel& newValue)
{
    //Clear previous fill
    for(auto& node : filled)
        targetMap.getGameBlock(node)->setLightLevel(oldValue);

    if(newValue == oldValue)
        return;

    //BFS Fill
    QQueue<QPoint> nodesToProcess;
    nodesToProcess.enqueue(location);
    targetMap.getGameBlock(location)->setLightLevel(newValue);
    filled.push_back(location);

    for(int i = 0; i <= depth && nodesToProcess.size() > 0; ++i)
    {
        QPoint current = nodesToProcess.dequeue();
        findNeighbours(current,oldValue);
        for(auto& neighbour : neighbourLocs)
        {
            targetMap.getGameBlock(neighbour)->setLightLevel(newValue);
            nodesToProcess.enqueue(neighbour);
            filled.push_back(neighbour);
        }
    }
}

void LightFiller::findNeighbours(const QPoint& location, const AbstractGameBlock::LightLevel& oldValue)
{
    neighbourLocs.clear();
    QVector<QPoint> directionsBases { {0 , 1},{ 1 , 0} ,
                                      {0 ,-1},{-1 , 0} ,
                                      {1 , 1},{ 1 ,-1} ,
                                      {-1, 1},{-1 ,-1}};

    for(const auto& direction : directionsBases)
    {
        QPoint neighbourLoc = location + direction;
        if(targetMap.isInMapBounds(neighbourLoc) // In game space
           && targetMap.getGameBlock(neighbourLoc)->getLightLevel() == oldValue //Hasn't changed
           && !targetMap.getGameBlock(neighbourLoc)->isLightBlocking()) // doesn't block light
        {
            neighbourLocs.push_back(neighbourLoc);
        }
    }
}
