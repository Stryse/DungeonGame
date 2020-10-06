QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/main.cpp \
    src/models/cpp/abstractgameblock.cpp \
    src/models/cpp/endblock.cpp \
    src/models/cpp/gamelogicmodel.cpp \
    src/models/cpp/lightfiller.cpp \
    src/models/cpp/map.cpp \
    src/models/cpp/player.cpp \
    src/models/cpp/roadblock.cpp \
    src/models/cpp/wallblock.cpp \
    src/views/cpp/abstractgameblockwidget.cpp \
    src/views/cpp/charactercreation.cpp \
    src/views/cpp/gamefieldui.cpp \
    src/views/cpp/mainwindow.cpp \
    src/views/cpp/paintedwidget.cpp

HEADERS += \
    src/models/header/abstractgameblock.h \
    src/models/header/endblock.h \
    src/models/header/gamelogicmodel.h \
    src/models/header/lightfiller.h \
    src/models/header/map.h \
    src/models/header/player.h \
    src/models/header/roadblock.h \
    src/models/header/wallblock.h \
    src/views/header/abstractgameblockwidget.h \
    src/views/header/charactercreation.h \
    src/views/header/gamefieldui.h \
    src/views/header/mainwindow.h \
    src/views/header/paintedwidget.h

FORMS += \
    src/views/ui/character_creation.ui \
    src/views/ui/gamefieldui.ui \
    src/views/ui/mainwindow.ui

UI_DIR = $$PWD/src/views/header/generated

INCLUDEPATH += \
    src/views/header \
    src/views/header/generated \
    src/models/header \
    src/persistence/header

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES += \
    .gitignore \
    resources/img/backgrounds/brick_background.png \
    resources/img/backgrounds/char_creat_background.jpg
