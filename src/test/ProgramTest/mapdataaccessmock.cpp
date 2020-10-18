#include "mapdataaccessmock.h"
#include "endblock.h"
#include <QPoint>

MapDataAccessMock::MapDataAccessMock()
{

}

bool MapDataAccessMock::isAvailable() const
{
    return true;
}

bool MapDataAccessMock::loadMaps(QVector<Map*>& target) const
{
    //MAP NO WALL | 3 x 3
    QVector<QVector<AbstractGameBlock*>> blockData;
    blockData.resize(3);
    for(int i = 0; i < 3; ++i)
    {
        blockData[i].resize(3);
        for(int j = 0; j < 3; ++j)
        {
            blockData[i][j] = AbstractGameBlock::create("R");
        }
    }
    delete blockData[2][0]; blockData[2][0] = AbstractGameBlock::create("S");
    delete blockData[0][2]; blockData[0][2] = AbstractGameBlock::create("E");


    Map* mapnowall = new Map("NOWALL_TEST",blockData,QPoint(1,1),0);
    target.push_back(mapnowall);

    //Map ALL WALL | 5 x 5
    QVector<QVector<AbstractGameBlock*>> blockData2;
    blockData2.resize(5);
    for(int i = 0; i < 5; ++i)
    {
        blockData2[i].resize(5);
        for(int j = 0; j < 5; ++j)
        {
            blockData2[i][j] = AbstractGameBlock::create("W");
        }
    }
    delete blockData2[2][2]; blockData2[2][2] = AbstractGameBlock::create("R");

    Map* mapallwall = new Map("ALLWALL_TEST",blockData2,QPoint(2,2),0);
    target.push_back(mapallwall);


    //Map Test winning condition | 3 x 3
    QVector<QVector<AbstractGameBlock*>> blockData3;
    blockData3.resize(3);
    for(int i = 0; i < 3; ++i)
    {
        blockData3[i].resize(3);
        for(int j = 0; j < 3; ++j)
        {
            blockData3[i][j] = AbstractGameBlock::create("R");
        }
    }
    delete blockData3[2][0]; blockData3[2][0] = AbstractGameBlock::create("S");
    delete blockData3[0][2]; blockData3[0][2] = AbstractGameBlock::create("E");


    Map* mapwin = new Map("WIN_TEST",blockData3,QPoint(1,1),0);
    target.push_back(mapwin);


    return true;
}
