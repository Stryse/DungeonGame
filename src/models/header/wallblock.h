#ifndef WALLBLOCK_H
#define WALLBLOCK_H

#include <abstractgameblock.h>
#include <QObject>

class WallBlock : public AbstractGameBlock
{
public:
    WallBlock();

    // AbstractGameBlock interface
public:
    QString getLightTexturePath(const LightLevel &lightlevel) const override;
};

#endif // WALLBLOCK_H
