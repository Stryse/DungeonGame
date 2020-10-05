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
    void DoPlayerEnter(const Player&) override;
    void DoPlayerExit (const Player&) override;
    bool isLightBlocking() const override;

};

#endif // WALLBLOCK_H
