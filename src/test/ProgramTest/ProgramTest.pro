QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_testprogram.cpp \
    ../../models/cpp/abstractgameblock.cpp \
    ../../models/cpp/charactercreationmodel.cpp \
    ../../models/cpp/endblock.cpp \
    ../../models/cpp/gameloadermodel.cpp \
    ../../models/cpp/gamelogicmodel.cpp \
    ../../models/cpp/lightfiller.cpp \
    ../../models/cpp/map.cpp \
    ../../models/cpp/player.cpp \
    ../../models/cpp/roadblock.cpp \
    ../../models/cpp/startblock.cpp \
    ../../models/cpp/wallblock.cpp \
    mapdataaccessmock.cpp

INCLUDEPATH += \
    ../../views/header \
    ../../views/header/generated \
    ../../models/header \
    ../../persistence/header \
    ../../persistence/interface/header/ \
    ../../persistence/implementation/header/

HEADERS += \
    ../../models/header/abstractgameblock.h \
    ../../models/header/charactercreationmodel.h \
    ../../models/header/endblock.h \
    ../../models/header/gameloadermodel.h \
    ../../models/header/gamelogicmodel.h \
    ../../models/header/lightfiller.h \
    ../../models/header/map.h \
    ../../models/header/player.h \
    ../../models/header/roadblock.h \
    ../../models/header/startblock.h \
    ../../models/header/wallblock.h \
    mapdataaccessmock.h
