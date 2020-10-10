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
        //readPlayerPortrait          =PLAYERPORTRAIT_FOLDER + readPlayerPortrait;

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

QStringList PlayerDataAccessImpl::loadAvailablePortraits(QVector<QString>& target) const
{
    QStringList portraitPaths;
    loadPortraitsFromFolder(target,PLAYERPORTRAIT_FOLDER);
    loadPortraitsFromFolder(target,INBUILDS_PORTRAITS);
    return portraitPaths;
}

bool PlayerDataAccessImpl::savePlayer(const Player& player) const
{
    QFile saveFile(QString("%0%1.txt").arg(PLAYERDATA_FOLDER,player.getPlayerName()));
    if (!saveFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Couldn't save player to" << saveFile.fileName();
        return false;
    }

    QTextStream stream(&saveFile);
    stream << player.getPlayerName() << '\n';
    stream << player.getStrength()   << '\n';
    stream << player.getIntellect()  << '\n';
    stream << player.getStamina()    << '\n';
    stream << player.getPortrait();

    stream.flush();
    saveFile.close();

    qDebug() << "Player saved to " << saveFile.fileName();
    return true;
}

bool PlayerDataAccessImpl::loadDefaultPlayer(QVector<Player*>& target) const
{
    Player* defaultPlayer = new Player(nullptr,DEFAULT_PLAYER_PORTRAIT,DEFAULT_PLAYER_NAME);
    target.push_back(defaultPlayer);

    return defaultPlayer != nullptr;
}

bool PlayerDataAccessImpl::loadPortraitsFromFolder(QVector<QString>& target, const QString& folder) const
{
    QDir playerPortraitDir(folder);
    if(!playerPortraitDir.exists()){ qDebug() << "Player portrait dir not found!"; return false; }

    QStringList playerPortraits = playerPortraitDir.entryList(QStringList() << "*.png",QDir::Files);
    foreach(const auto& filename,playerPortraits)
    {
        qDebug() << "Found PlayerPortrait: "<< filename;
        target.push_back(playerPortraitDir.filePath(filename));
    }
    return playerPortraits.size() > 0;
}
