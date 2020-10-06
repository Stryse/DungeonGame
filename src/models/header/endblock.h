#ifndef ENDBLOCK_H
#define ENDBLOCK_H

#include <roadblock.h>
#include <QObject>

class EndBlock : public RoadBlock
{

public:
    EndBlock();
    QString getLightTexturePath(const LightLevel &lightlevel) const override;
    void DoPlayerEnter(const Player& player) override;
};

#endif // ENDBLOCK_H
