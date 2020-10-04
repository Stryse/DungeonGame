#ifndef ROADBLOCK_H
#define ROADBLOCK_H

#include <abstractgameblock.h>
#include <QObject>

class RoadBlock : public AbstractGameBlock
{
public:
    RoadBlock();

    // AbstractGameBlock interface
public:
    QString getLightTexturePath(const LightLevel &lightlevel) const override;
};

#endif // ROADBLOCK_H