#ifndef ABSTRACTGAMEBLOCK_H
#define ABSTRACTGAMEBLOCK_H

#include <QObject>
#include "player.h"

class AbstractGameBlock : public QObject
{
    Q_OBJECT
public:

    explicit AbstractGameBlock(QObject *parent = nullptr);
    static AbstractGameBlock* create(const QString& type);
    enum class LightLevel { UNLIT,HALF_LIT,LIT  };


    bool getHasPlayer() const;
    void setHasPlayer(bool value);

    LightLevel getLightLevel() const;
    void setLightLevel(const LightLevel &value);

    // TODO return by ref
    virtual QString getLightTexturePath(const LightLevel& lightlevel) const = 0;
    virtual void DoPlayerEnter(const Player& player) = 0;
    virtual void DoPlayerExit (const Player& player) = 0;


signals:
    void playerEntered(const Player& player);
    void playerExited (const Player& player);

private:
    bool hasPlayer;
    LightLevel lightLevel;
};

#endif // ABSTRACTGAMEBLOCK_H
