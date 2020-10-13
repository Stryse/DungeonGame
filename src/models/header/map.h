#ifndef MAP_H
#define MAP_H

#include <QVector>
#include <QPoint>

#include "abstractgameblock.h"

class Map : public QObject
{

public:
    explicit Map(const QString& mapName,
                 const QVector<QVector<AbstractGameBlock*>>& dataGrid,
                 const QPoint& initCoords,int direction);

    //Direction type
    enum class Direction { UP,DOWN,LEFT,RIGHT };
    using GameBlockGrid = QVector<QVector<AbstractGameBlock*>>;

    //Getter Setter
    QString getMapName() const;
    QPoint getInitialCoords() const;
    Direction getInitialDirection() const;

    AbstractGameBlock* getGameBlock(int row, int col) const;
    AbstractGameBlock* getGameBlock(const QPoint& point) const;

    bool isInMapBounds(int row, int col) const;
    bool isInMapBounds(const QPoint& point) const;

    int getSize() const;

private:
    QString mapName;
    GameBlockGrid blockFieldData;
    QPoint initialCoords;
    Direction initialDirection;
    int size;

};

#endif // MAP_H
