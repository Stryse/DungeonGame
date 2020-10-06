#include "startblock.h"
#include <QDebug>


StartBlock::StartBlock()
{

}

QString StartBlock::getLightTexturePath(const AbstractGameBlock::LightLevel& lightlevel) const
{
    switch (lightlevel)
    {
        case AbstractGameBlock::LightLevel::LIT:
            return QString(":/resources/img/blocks/trapdoor_lit.jpg");
        break;

        case AbstractGameBlock::LightLevel::HALF_LIT:
            return QString(":/resources/img/blocks/trapdoor_half_lit.png");
        break;

        case AbstractGameBlock::LightLevel::UNLIT:
            return QString(":/resources/img/blocks/wall_unlit.jpg");
        break;

        default:
            return QString(":/resources/img/blocks/invalid_block.png");
        break;
    }
}

void StartBlock::DoPlayerExit(const Player& player)
{
    RoadBlock::DoPlayerExit(player);
    qDebug() << "Start block left...";
}
