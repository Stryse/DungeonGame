#ifndef ROADBLOCK_H
#define ROADBLOCK_H

#include <abstractgameblock.h>
#include <QObject>

class RoadBlock : public AbstractGameBlock
{
    Q_OBJECT

public:
    RoadBlock();
    virtual ~RoadBlock();

    // AbstractGameBlock interface
public:
    void PopulateTextures() override;
    void DoPlayerEnter(const Player& player) override;
    void DoPlayerExit(const Player& player) override;
    bool isLightBlocking() const override;
};

#endif // ROADBLOCK_H
