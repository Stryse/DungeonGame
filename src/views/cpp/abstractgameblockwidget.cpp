#include "abstractgameblockwidget.h"
#include <QPainter>

AbstractGameBlockWidget::AbstractGameBlockWidget(      QWidget *parent,
                                                 const QPixmap& litTexture,
                                                 const QPixmap& unlitTexture,
                                                 const QPixmap& halfLitTexture,
                                                 const AbstractGameBlock& blockData)
    :PaintedWidget(parent,unlitTexture)
    ,litTexture(litTexture), unlitTexture(unlitTexture),halfLitTexture(halfLitTexture)
    ,blockData(blockData)
{
    connect(&blockData,SIGNAL(playerEntered(const Player&)),this,SLOT(onPlayerEntered(const Player&)));
    connect(&blockData,SIGNAL(playerExited(const Player&)),this,SLOT(onPlayerExited(const Player&)));
    connect(&blockData,SIGNAL(lightLevelChanged(const AbstractGameBlock::LightLevel&)),SLOT(onLightLevelChanged(const AbstractGameBlock::LightLevel&)));
}

AbstractGameBlockWidget::AbstractGameBlockWidget(const AbstractGameBlockWidget &other)
    :PaintedWidget(other.parentWidget()
    ,other.litTexture),litTexture(other.litTexture),unlitTexture(other.unlitTexture),halfLitTexture(other.halfLitTexture)
    ,playerTexture(other.playerTexture),blockData(other.blockData)
{
}

AbstractGameBlockWidget AbstractGameBlockWidget::operator=(const AbstractGameBlockWidget &other)
{
    return AbstractGameBlockWidget(other);
}

void AbstractGameBlockWidget::paintEvent(QPaintEvent* event)
{
    if(!blockData.getHasPlayer())
        PaintedWidget::paintEvent(event);
    else
    {
        PaintedWidget::paintEvent(event);
        // DRAW PLAYER PORTRAIT ONTO BACKGROUND

        QPainter p(&getPixmap());
        QPixmap scaledPortrait = playerTexture.scaledToWidth(getPixmap().width()*0.8,Qt::SmoothTransformation);
        int x = (getPixmap().width()-scaledPortrait.width()) / 2;
        int y = (getPixmap().height()-scaledPortrait.height()) / 2;
        p.drawPixmap(x,y,scaledPortrait.width(),scaledPortrait.height(),scaledPortrait);
        update();
    }
}

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
    // TODO MAP FUNCTION
    if(lightlevel == AbstractGameBlock::LightLevel::LIT)
        setPixmap(litTexture);
    else if(lightlevel == AbstractGameBlock::LightLevel::HALF_LIT)
        setPixmap(halfLitTexture);
    else
        setPixmap(unlitTexture);

    update();
}
