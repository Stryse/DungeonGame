#include "endblock.h"
#include <QDebug>

EndBlock::EndBlock()
{

}

QString EndBlock::getLightTexturePath(const AbstractGameBlock::LightLevel& lightlevel) const
{
    switch (lightlevel)
    {
        case AbstractGameBlock::LightLevel::LIT:
            return QString(":/resources/img/blocks/exit_lit.jpg");
        break;

        case AbstractGameBlock::LightLevel::HALF_LIT:
            return QString(":/resources/img/blocks/exit_half_lit.jpg");
        break;

        case AbstractGameBlock::LightLevel::UNLIT:
            return QString(":/resources/img/blocks/exit_unlit.jpg");
        break;

        default:
            return QString(":/resources/img/blocks/invalid_block.png");
        break;
    }
}

void EndBlock::DoPlayerEnter(const Player& player)
{
    RoadBlock::DoPlayerEnter(player);
    qDebug() << "WIN";
}
