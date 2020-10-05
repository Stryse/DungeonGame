#ifndef LIGHTFILLER_H
#define LIGHTFILLER_H

#include <QObject>
#include <QVector>
#include <QQueue>
#include <QPoint>
#include "map.h"
#include "abstractgameblock.h"

class LightFiller : public QObject
{
    Q_OBJECT
public:

    explicit LightFiller(QObject *parent, const Map& targetMap, int depth);

    void lightFill(const QPoint& location,const AbstractGameBlock::LightLevel& oldValue,
                                          const AbstractGameBlock::LightLevel& newValue);

private:

    struct Node{
        QPoint location;
        int level;
    };

    void findNeighbours(const QPoint& location,const AbstractGameBlock::LightLevel& oldValue);
    QVector<QPoint> filled;
    QVector<QPoint> neighbourLocs;
    const Map& targetMap;
    int depth;

};

#endif // LIGHTFILLER_H
