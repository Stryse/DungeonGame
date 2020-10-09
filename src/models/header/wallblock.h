#ifndef WALLBLOCK_H
#define WALLBLOCK_H

#include <abstractgameblock.h>
#include <QObject>

class WallBlock : public AbstractGameBlock
{
    Q_OBJECT

public:
    WallBlock();
    virtual ~WallBlock();

    // AbstractGameBlock interface
public:
    void PopulateTextures() override;
    void DoPlayerEnter(const Player&) override;
    void DoPlayerExit (const Player&) override;
    bool isLightBlocking() const override;

};

#endif // WALLBLOCK_H
