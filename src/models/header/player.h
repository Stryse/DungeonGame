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
    explicit Player(QObject *parent, QPixmap* portrait);

public:
    QPixmap* getPortrait() const;
    QString getPlayerName() const;
    int getStrength() const;


signals:

private:

    QPixmap* portrait;
    QString playerName;
    int strength;
    int intellect;
    int stamina;

};

#endif // PLAYER_H
