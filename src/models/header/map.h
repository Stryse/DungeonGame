#ifndef MAP_H
#define MAP_H

#include <QObject>
#include <QVector>
#include <QPoint>

#include "abstractgameblock.h"

class Map : public QObject
{
    Q_OBJECT

public:
    explicit Map(QObject *parent = nullptr);

    //Direction type
    enum class Direction { UP,DOWN,LEFT,RIGHT };

    //Getter Setter
    QString getMapName() const;
    QPoint getInitialCoords() const;
    Direction getInitialDirection() const;
    AbstractGameBlock* getGameBlock(int row, int col) const;
    void loadMapFromFile(const QString& filePath);
    bool isInMapBounds(int row, int col) const;
    int getSize() const;



signals:

private:
    QString mapName;
    QVector<QVector<AbstractGameBlock*>> blockFieldData;
    QPoint initialCoords;
    Direction initialDirection;
    int size;

};

#endif // MAP_H
