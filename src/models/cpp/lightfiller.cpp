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

    //===========================================  BFS Fill ========================================//
    QQueue<Node> nodesToProcess;
    nodesToProcess.enqueue({location,0});
    targetMap.getGameBlock(location)->setLightLevel(newValue);
    filled.push_back(location);

    while(nodesToProcess.size() > 0)
    {
        Node current = nodesToProcess.dequeue();
        if(current.level > depth-1) // depth level will be processed last
            continue;

        findNeighbours(current.location,oldValue);
        for(auto& neighbour : neighbourLocs)
        {
            targetMap.getGameBlock(neighbour) //Litting with level value texture
                    ->setLightLevel(static_cast<AbstractGameBlock::LightLevel>(current.level+(int)oldValue+1));

            if(!targetMap.getGameBlock(neighbour)->isLightBlocking()) //Process children if not light blocking
                nodesToProcess.enqueue({neighbour,current.level+1});

            filled.push_back(neighbour); // Register as changed
        }
    }
}

void LightFiller::findNeighbours(const QPoint& location, const AbstractGameBlock::LightLevel& oldValue)
{
    neighbourLocs.clear();
    QVector<QPoint> directionsVectors { {0 , 1},{ 1 , 0} ,
                                        {0 ,-1},{-1 , 0} ,
                                        {1 , 1},{ 1 ,-1} ,
                                        {-1, 1},{-1 ,-1}};

    for(const auto& direction : directionsVectors)
    {
        QPoint neighbourLoc = location + direction;
        if(targetMap.isInMapBounds(neighbourLoc) // In game space
           && targetMap.getGameBlock(neighbourLoc)->getLightLevel() == oldValue) //Hasn't already changed
        {
            neighbourLocs.push_back(neighbourLoc);
        }
    }
}
