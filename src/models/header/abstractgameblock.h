#ifndef ABSTRACTGAMEBLOCK_H
#define ABSTRACTGAMEBLOCK_H

#include <QObject>

class AbstractGameBlock : public QObject
{
    Q_OBJECT
public:

    explicit AbstractGameBlock(QObject *parent = nullptr);
    static AbstractGameBlock* create(const QString& type);

    bool getHasPlayer() const;

signals:

private:
    bool hasPlayer;

};

#endif // ABSTRACTGAMEBLOCK_H
