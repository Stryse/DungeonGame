#include "abstractgameblockwidget.h"
#include <QPainter>
#include <QMetaEnum>

AbstractGameBlockWidget::AbstractGameBlockWidget(QWidget *parent, const AbstractGameBlock& blockData)
    :PaintedWidget(parent)
    ,blockData(blockData)
{
    loadTextures();
    onLightLevelChanged(blockData.getLightLevel());

    //PLAYER ENTER EVENT
    connect(&blockData,SIGNAL(playerEntered(const Player&)),
                  this,SLOT(onPlayerEntered(const Player&)));

    //PLAYER EXIT EVENT
    connect(&blockData,SIGNAL(playerExited(const Player&)),
                  this,SLOT(onPlayerExited(const Player&)));

    //LIGHT LEVEL CHANGED EVENT
    connect(&blockData,SIGNAL(lightLevelChanged(const AbstractGameBlock::LightLevel&)),
                  this,SLOT(onLightLevelChanged(const AbstractGameBlock::LightLevel&)));
}


//===SLOTS
void AbstractGameBlockWidget::onPlayerEntered(const Player& player)
{
    playerTexture = QPixmap(player.getPortrait());
    update();
}

void AbstractGameBlockWidget::onPlayerExited(const Player&)
{
    onLightLevelChanged(AbstractGameBlock::LightLevel::UNLIT);
    update();
}

void AbstractGameBlockWidget::onLightLevelChanged(const AbstractGameBlock::LightLevel& lightlevel)
{
    setPixmap(textures.value(lightlevel));
    update();
}

void AbstractGameBlockWidget::loadTextures()
{
    QMetaEnum e = QMetaEnum::fromType<AbstractGameBlock::LightLevel>();
    for(int i = 0; i < e.keyCount(); ++i)
    {
        AbstractGameBlock::LightLevel textureType = static_cast<AbstractGameBlock::LightLevel>(e.value(i));
        textures[textureType] = QPixmap(blockData.getLightTexturePath(textureType));
    }
}


//===OVERRIDE EVENTS
void AbstractGameBlockWidget::paintEvent(QPaintEvent* event)
{
    if(!blockData.getHasPlayer())
        PaintedWidget::paintEvent(event);
    else
    {
        // Draw Widget Background
        PaintedWidget::paintEvent(event);

        // Draw Player Portrait onto background
        QPainter p(&getPixmap());
        QPixmap scaledPortrait = playerTexture.scaledToWidth(getPixmap().width()*0.8,Qt::SmoothTransformation);
        int x = (getPixmap().width()-scaledPortrait.width()) / 2;
        int y = (getPixmap().height()-scaledPortrait.height()) / 2;
        p.drawPixmap(x,y,scaledPortrait.width(),scaledPortrait.height(),scaledPortrait);
        update();
    }
}
