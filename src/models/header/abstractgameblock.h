#ifndef ABSTRACTGAMEBLOCK_H
#define ABSTRACTGAMEBLOCK_H

#include <QObject>
#include <QString>
#include <QMap>
#include "player.h"

class AbstractGameBlock : public QObject
{
    Q_OBJECT

    //CTOR
protected:
    explicit AbstractGameBlock(QObject *parent = nullptr);
public:
    virtual ~AbstractGameBlock();

    //Static factory
    static AbstractGameBlock* create(const QString& type);

    //Types
    enum class LightLevel { UNLIT = 0, LIT, HALF_LIT};
    Q_ENUM(LightLevel)

    //Getter
    bool getHasPlayer() const;
    LightLevel getLightLevel() const;

    //Setter
    void setHasPlayer(bool value);
    void setLightLevel(const LightLevel& value);

    //Interface methods
    virtual void PopulateTextures() = 0; //TODO MAKE IT PROTECTED
    virtual void DoPlayerEnter(const Player& player) = 0;
    virtual void DoPlayerExit (const Player& player) = 0;
    virtual bool isLightBlocking() const = 0;

    //Virtual methods with implementation
    virtual QString getLightTexturePath(const LightLevel& lightlevel) const;

signals:
    void playerEntered(const Player& player);
    void playerExited (const Player& player);
    void lightLevelChanged(const AbstractGameBlock::LightLevel& lightLevel);

private:
    bool hasPlayer;
    LightLevel lightLevel;

protected:
    QMap<LightLevel,QString> textures;
};

#endif // ABSTRACTGAMEBLOCK_H
