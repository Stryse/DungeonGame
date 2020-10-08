#include "playerdataaccessimpl.h"

#include <QFile>
#include <QDir>
#include <QDebug>
#include <QTextStream>

PlayerDataAccessImpl::PlayerDataAccessImpl()
{
    QDir().mkpath(PLAYERDATA_FOLDER);
    QDir().mkpath(PLAYERPORTRAIT_FOLDER);
}

bool PlayerDataAccessImpl::isAvailable() const
{ return true; }

bool PlayerDataAccessImpl::loadPlayers(QVector<Player*>& target) const
{
    //Adding a default player
    // TODO check nullptr decide who's owner
    Player* defaultPlayer = new Player(nullptr,QPixmap(DEFAULT_PLAYER_PORTRAIT),DEFAULT_PLAYER_NAME);
    target.push_back(defaultPlayer);

    QDir playerDataDir(QString(PLAYERDATA_FOLDER));
    if(!playerDataDir.exists()){ qDebug() << "Player data dir not found!"; return false; }

    QDir playerPortraitDir(PLAYERPORTRAIT_FOLDER);
    if(!playerPortraitDir.exists()){ qDebug() << "Player portrait dir not found"; return false; }

    //Read PlayerData
    QStringList playerDataBuffer = playerDataDir.entryList(QStringList() << "*.txt",QDir::Files);
    for(auto& filename : playerDataBuffer)
    {
        qDebug() << "Found PlayerData: "<< filename;

        QFile file(playerDataDir.filePath(filename));
        if(!file.open(QFile::ReadOnly)){
            qDebug() << "Error opening file: " << file.fileName();
            return false;
        }

        QTextStream stream(&file);
        QString readPlayerName;     stream >> readPlayerName;
        int readStrength;           stream >> readStrength;
        int readIntellect;          stream >> readIntellect;
        int readStamina;            stream >> readStamina;
        QString readPlayerPortrait; stream >> readPlayerPortrait;
        readPlayerPortrait = PLAYERPORTRAIT_FOLDER + readPlayerPortrait;

        target.push_back(new Player(nullptr,QPixmap(readPlayerPortrait),
                                    readPlayerName,readStrength,readIntellect,readStamina));
        stream.flush();
        file.close();

        qDebug() << readPlayerName << readStrength << readIntellect << readStamina << readPlayerPortrait;
    }
    return true;
}

bool PlayerDataAccessImpl::laodAvailablePortraits(QVector<QPixmap*>& target) const
{
    return true;
}
