#ifndef ABSTRACTGAMEBLOCK_H
#define ABSTRACTGAMEBLOCK_H

#include <QObject>

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


signals:

private:
    bool hasPlayer;
    LightLevel lightLevel;
};

#endif // ABSTRACTGAMEBLOCK_H
