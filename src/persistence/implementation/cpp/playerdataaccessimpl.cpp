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

PlayerDataAccessImpl::~PlayerDataAccessImpl()
{}

bool PlayerDataAccessImpl::isAvailable() const
{ return true; }

bool PlayerDataAccessImpl::loadPlayers(QVector<Player*>& target) const
{
    loadDefaultPlayer(target);

    QDir playerDataDir(QString(PLAYERDATA_FOLDER));
    if(!playerDataDir.exists()){ qDebug() << "Player data dir not found!"; return false; }

    //Read PlayerData
    QStringList playerDataBuffer = playerDataDir.entryList(QStringList() << "*.txt",QDir::Files);
    foreach(auto& filename,playerDataBuffer)
    {
        qDebug() << "Found PlayerData: "<< filename;
        //Opening
        QFile file(playerDataDir.filePath(filename));
        if(!file.open(QFile::ReadOnly | QIODevice::Text)){
            qDebug() << "Error opening file: " << file.fileName();
            return false;
        }

        //Reading
        QTextStream stream(&file);
        QString readPlayerName;     stream >> readPlayerName;
        int readStrength;           stream >> readStrength;
        int readIntellect;          stream >> readIntellect;
        int readStamina;            stream >> readStamina;
        QString readPlayerPortrait; stream >> readPlayerPortrait;
        readPlayerPortrait          =PLAYERPORTRAIT_FOLDER + readPlayerPortrait;

        //Populating
        target.push_back(new Player(nullptr,readPlayerPortrait,
                                    readPlayerName,readStrength,readIntellect,readStamina));
        //Closing resources
        stream.flush();
        file.close();

        qDebug() << readPlayerName << readStrength << readIntellect << readStamina << readPlayerPortrait;
    }
    return true;
}

QStringList PlayerDataAccessImpl::loadAvailablePortraits(QVector<QPixmap>& target) const
{
    QStringList portraitPaths;
    return portraitPaths;
}

void PlayerDataAccessImpl::loadDefaultPlayer(QVector<Player*>& target) const
{
    //Adding a default player
    // TODO check nullptr decide who's owner
    Player* defaultPlayer = new Player(nullptr,DEFAULT_PLAYER_PORTRAIT,DEFAULT_PLAYER_NAME);
    target.push_back(defaultPlayer);
}
