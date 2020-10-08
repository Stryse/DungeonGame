#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QPixmap>
#include <QString>

class Player : public QObject
{
    Q_OBJECT
public:
    //CTOR
    explicit Player(QObject *parent,const QPixmap& portrait,
                    const QString& pName, int strength = 1, int intellct = 1, int stamina = 1);
    ~Player();

public:
    const QPixmap& getPortrait() const;
    QString getPlayerName() const;
    int getStrength() const;

signals:

private:

    const QPixmap portrait;
    QString playerName;
    int strength;
    int intellect;
    int stamina;

};

#endif // PLAYER_H
