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
};

#endif // ENDBLOCK_H
