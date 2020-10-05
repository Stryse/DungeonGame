#include "lightfiller.h"
#include <QDebug>

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

    //Return if no change or negative depth
    if(newValue == oldValue || depth < 0)
        return;

    //BFS Fill
    QQueue<Node> nodesToProcess;
    nodesToProcess.enqueue({location,0});
    targetMap.getGameBlock(location)->setLightLevel(newValue);
    filled.push_back(location);

    // TODO: FIX THIS SHIT, need to calculate distance from loc and bound it
    while(nodesToProcess.size() > 0)
    {
        Node current = nodesToProcess.dequeue();
        if(current.level > depth-1) // depth level will be processed last
            continue;

        findNeighbours(current.location,oldValue);
        for(auto& neighbour : neighbourLocs)
        {
            targetMap.getGameBlock(neighbour)
                    ->setLightLevel(static_cast<AbstractGameBlock::LightLevel>(current.level+(int)oldValue+1));

            nodesToProcess.enqueue({neighbour,current.level+1});
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
