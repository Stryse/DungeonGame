#ifndef ENDBLOCK_H
#define ENDBLOCK_H

#include <roadblock.h>
#include <QObject>

class EndBlock : public RoadBlock
{
    Q_OBJECT

public:
    //CTOR
    EndBlock();
    virtual ~EndBlock();

    void PopulateTextures() override;
    void DoPlayerEnter(const Player& player) override;
signals:
    void endBlockEntered();
};

#endif // ENDBLOCK_H
