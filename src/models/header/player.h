#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QPixmap>
#include <QString>

// TODO REMOVE QOBJECT
class Player : public QObject
{
    Q_OBJECT

public:
    //CTOR
    explicit Player(QObject *parent,const QString& portrait,
                    const QString& pName, int strength = 1, int intellct = 1, int stamina = 1);

    explicit Player(const Player& other);

    ~Player();

public:
    const QString& getPortrait() const;
    const QString& getPlayerName() const;
    int getStrength() const;
    int getIntellect() const;
    int getStamina() const;



signals:

private:

    const QString portraitPath;
    QString playerName;
    int strength;
    int intellect;
    int stamina;

};

#endif // PLAYER_H
