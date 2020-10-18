#include <QtTest>
#include <QSignalSpy>
#include <QDebug>
#include "gamelogicmodel.h"
#include "player.h"
#include "imapdataaccess.h"
#include "mapdataaccessmock.h"
#include "roadblock.h"
#include "wallblock.h"
#include "startblock.h"
#include "endblock.h"

class TestProgram : public QObject
{
    Q_OBJECT

public:
    TestProgram();
    ~TestProgram();

private slots:
    //noWall map
    void test_case_noWall_init();
    void test_case_noWall_light();
    void test_case_noWall_moveSucc();
    void test_case_noWall_moveFail();

    //allWall map <<- player cannot move in this map
    void test_case_allWall_init();
    void test_case_allWall_light();
    void test_case_allWall_moveFail();

    //test Win
    void test_case_winCond();

private:
    Player* test_player;
    IMapDataAccess* mapDataAccess;
    GameLogicModel* game_nowall;
    GameLogicModel* game_allwall;
    GameLogicModel* game_testWin;
};

TestProgram::TestProgram()
{
    QVector<Map*> testMaps;
    mapDataAccess = new MapDataAccessMock();
    mapDataAccess->loadMaps(testMaps);


    test_player = new Player(this,"","Test Player",1,1,1);
    game_nowall = new GameLogicModel(this,testMaps[0],test_player);

    test_player = new Player(this,"","Test Player",1,1,1);
    game_allwall = new GameLogicModel(this,testMaps[1],test_player);

    test_player = new Player(this,"","Test Player",1,1,1);
    game_testWin = new GameLogicModel(this,testMaps[2],test_player);
}

TestProgram::~TestProgram()
{
    delete mapDataAccess;
    delete game_nowall;
    delete game_allwall;
    delete game_testWin;
}

void TestProgram::test_case_noWall_init()
{
    //TEST INTACT GAME INSTANCE
    int startCount = 0;
    int endCount   = 0;

    for(int i = 0; i < game_nowall->getActiveMap().getSize(); ++i)
    {
        for(int j = 0; j < game_nowall->getActiveMap().getSize(); ++j)
        {
            RoadBlock* test_road = qobject_cast<RoadBlock*>(game_nowall->getActiveMap().getGameBlock(i,j));
            WallBlock* test_wall = qobject_cast<WallBlock*>(game_nowall->getActiveMap().getGameBlock(i,j));
            StartBlock* test_start = qobject_cast<StartBlock*>(game_nowall->getActiveMap().getGameBlock(i,j));
            EndBlock* test_end = qobject_cast<EndBlock*>(game_nowall->getActiveMap().getGameBlock(i,j));

            QVERIFY(test_road || test_wall || test_start || test_end);

            if(test_start)
                ++startCount;

            if(test_end)
                ++endCount;
        }
    }
    QVERIFY(game_nowall->getActiveMap().getSize() == 3);
    QVERIFY(startCount > 0);
    QVERIFY(endCount > 0);
    //ENDOFTEST
}

void TestProgram::test_case_noWall_light()
{
    for(int i = 0; i < game_nowall->getActiveMap().getSize(); ++i)
    {
        for(int j = 0; j < game_nowall->getActiveMap().getSize(); ++j)
        {
            QVERIFY(game_nowall->getActiveMap().getGameBlock(i,j)->getLightLevel() == AbstractGameBlock::LightLevel::LIT);
        }
    }
}

void TestProgram::test_case_noWall_moveSucc()
{
    //TEST PLAYERMOVE ON SUCCESS
    //UP
    QPoint old_pos = game_nowall->getPlayerCoords();
    game_nowall->movePlayer(Map::Direction::UP);
    QVERIFY(game_nowall->getPlayerCoords() == old_pos + QPoint(0,-1));

    //Down
    old_pos = game_nowall->getPlayerCoords();
    game_nowall->movePlayer(Map::Direction::DOWN);
    QVERIFY(game_nowall->getPlayerCoords() == old_pos + QPoint(0,1));

    //Left
    old_pos = game_nowall->getPlayerCoords();
    game_nowall->movePlayer(Map::Direction::LEFT);
    QVERIFY(game_nowall->getPlayerCoords() == old_pos + QPoint(-1,0));

    //Right
    old_pos = game_nowall->getPlayerCoords();
    game_nowall->movePlayer(Map::Direction::RIGHT);
    QVERIFY(game_nowall->getPlayerCoords() == old_pos + QPoint(1,0));
}

void TestProgram::test_case_noWall_moveFail()
{
    //TEST PLAYERMOVE ON FAILURE <-- Out of bounds
    //Move to left bound
    game_nowall->movePlayer(Map::Direction::LEFT);

    //Try moving out of bound
    QPoint old_pos = game_nowall->getPlayerCoords();
    game_nowall->movePlayer(Map::Direction::LEFT);
    QVERIFY(old_pos == game_nowall->getPlayerCoords()); //old pos must be same as new

    //Move to right bound
    game_nowall->movePlayer(Map::Direction::RIGHT);
    game_nowall->movePlayer(Map::Direction::RIGHT);

    //Try moving out of bound
    old_pos = game_nowall->getPlayerCoords();
    game_nowall->movePlayer(Map::Direction::RIGHT);
    QVERIFY(old_pos == game_nowall->getPlayerCoords()); //old pos must be same as new

    //Move to up bound
    game_nowall->movePlayer(Map::Direction::UP);

    //Try moving out of bound
    old_pos = game_nowall->getPlayerCoords();
    game_nowall->movePlayer(Map::Direction::UP);
    QVERIFY(old_pos == game_nowall->getPlayerCoords()); //old pos must be same as new

    //Move to bottom bound
    game_nowall->movePlayer(Map::Direction::DOWN);
    game_nowall->movePlayer(Map::Direction::DOWN);

    //Try moving out of bound
    old_pos = game_nowall->getPlayerCoords();
    game_nowall->movePlayer(Map::Direction::DOWN);
    QVERIFY(old_pos == game_nowall->getPlayerCoords()); //old pos must be same as new

}

void TestProgram::test_case_allWall_init()
{
    //TEST INTACT GAME INSTANCE
    int startCount = 0;
    int endCount   = 0;

    for(int i = 0; i < game_allwall->getActiveMap().getSize(); ++i)
    {
        for(int j = 0; j < game_allwall->getActiveMap().getSize(); ++j)
        {
            RoadBlock* test_road = qobject_cast<RoadBlock*>(game_allwall->getActiveMap().getGameBlock(i,j));
            WallBlock* test_wall = qobject_cast<WallBlock*>(game_allwall->getActiveMap().getGameBlock(i,j));
            StartBlock* test_start = qobject_cast<StartBlock*>(game_allwall->getActiveMap().getGameBlock(i,j));
            EndBlock* test_end = qobject_cast<EndBlock*>(game_allwall->getActiveMap().getGameBlock(i,j));

            QVERIFY(test_road || test_wall || test_start || test_end);

            if(test_start)
                ++startCount;

            if(test_end)
                ++endCount;
        }
    }
    QVERIFY(game_allwall->getActiveMap().getSize());
    QVERIFY(startCount == 0);
    QVERIFY(endCount == 0);
    //ENDOFTEST
}

void TestProgram::test_case_allWall_light()
{
    //Test Lit part
    for(int i = 1; i < game_allwall->getActiveMap().getSize()-1; ++i)
    {
        for(int j = 1; j < game_allwall->getActiveMap().getSize()-1; ++j)
        {
            QVERIFY(game_allwall->getActiveMap().getGameBlock(i,j)->getLightLevel() == AbstractGameBlock::LightLevel::LIT);
        }
    }

    //Test Unlit part
    for(int j = 0; j < game_allwall->getActiveMap().getSize();++j)
        QVERIFY(game_allwall->getActiveMap().getGameBlock(0,j)->getLightLevel() == AbstractGameBlock::LightLevel::UNLIT);

    for(int j = 4; j < game_allwall->getActiveMap().getSize();++j)
        QVERIFY(game_allwall->getActiveMap().getGameBlock(4,j)->getLightLevel() == AbstractGameBlock::LightLevel::UNLIT);

    QVERIFY(game_allwall->getActiveMap().getGameBlock(1,0)->getLightLevel() == AbstractGameBlock::LightLevel::UNLIT);
    QVERIFY(game_allwall->getActiveMap().getGameBlock(1,4)->getLightLevel() == AbstractGameBlock::LightLevel::UNLIT);

    QVERIFY(game_allwall->getActiveMap().getGameBlock(2,0)->getLightLevel() == AbstractGameBlock::LightLevel::UNLIT);
    QVERIFY(game_allwall->getActiveMap().getGameBlock(2,4)->getLightLevel() == AbstractGameBlock::LightLevel::UNLIT);

    QVERIFY(game_allwall->getActiveMap().getGameBlock(3,0)->getLightLevel() == AbstractGameBlock::LightLevel::UNLIT);
    QVERIFY(game_allwall->getActiveMap().getGameBlock(3,4)->getLightLevel() == AbstractGameBlock::LightLevel::UNLIT);
}

void TestProgram::test_case_allWall_moveFail()
{
    //TEST PLAYERMOVE ON FAILURE
    //UP
    QPoint old_pos = game_allwall->getPlayerCoords();
    game_allwall->movePlayer(Map::Direction::UP);
    QVERIFY(game_allwall->getPlayerCoords() == old_pos);

    //Down
    old_pos = game_allwall->getPlayerCoords();
    game_allwall->movePlayer(Map::Direction::DOWN);
    QVERIFY(game_allwall->getPlayerCoords() == old_pos);

    //Left
    old_pos = game_allwall->getPlayerCoords();
    game_allwall->movePlayer(Map::Direction::LEFT);
    QVERIFY(game_allwall->getPlayerCoords() == old_pos);

    //Right
    old_pos = game_allwall->getPlayerCoords();
    game_allwall->movePlayer(Map::Direction::RIGHT);
    QVERIFY(game_allwall->getPlayerCoords() == old_pos);
}

void TestProgram::test_case_winCond()
{
    QSignalSpy signalSpy(game_testWin,&GameLogicModel::gameEnded);
    QVERIFY(signalSpy.isValid());

    //Move to endblock
    game_testWin->movePlayer(Map::Direction::UP);
    game_testWin->movePlayer(Map::Direction::RIGHT);

    //VERIFY gameEnded signal was emitted once
    QCOMPARE(signalSpy.count(),1);
}

QTEST_APPLESS_MAIN(TestProgram)

#include "tst_testprogram.moc"
