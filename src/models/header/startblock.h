#ifndef STARTBLOCK_H
#define STARTBLOCK_H

#include <roadblock.h>
#include <QObject>

class StartBlock : public RoadBlock
{
public:
    StartBlock();
    QString getLightTexturePath(const LightLevel& lightlevel) const override;
    void DoPlayerExit(const Player& player) override;

};

#endif // STARTBLOCK_H
