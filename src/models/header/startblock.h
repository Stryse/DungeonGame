#ifndef STARTBLOCK_H
#define STARTBLOCK_H

#include <roadblock.h>
#include <QObject>

class StartBlock : public RoadBlock
{
    Q_OBJECT

public:
    //CTOR
    StartBlock();
    virtual ~StartBlock();

    // AbstractGameBlock interface
    void PopulateTextures() override;
    void DoPlayerExit(const Player& player) override;
    void closeTrapdoor();

signals:
    void startLeft();

};

#endif // STARTBLOCK_H
