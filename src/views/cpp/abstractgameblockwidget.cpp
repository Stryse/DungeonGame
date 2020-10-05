#include "abstractgameblockwidget.h"
#include <QPainter>

AbstractGameBlockWidget::AbstractGameBlockWidget(      QWidget *parent,
                                                 const QPixmap& litTexture,
                                                 const QPixmap& unlitTexture,
                                                 const AbstractGameBlock& blockData)
    :PaintedWidget(parent,litTexture) // TODO: set to Unlit
    ,litTexture(litTexture), unlitTexture(unlitTexture)
    ,blockData(blockData)
{
    connect(&blockData,SIGNAL(playerEntered(const Player&)),this,SLOT(onPlayerEntered(const Player&)));
    connect(&blockData,SIGNAL(playerExited(const Player&)),this,SLOT(onPlayerExited(const Player&)));
}

AbstractGameBlockWidget::AbstractGameBlockWidget(const AbstractGameBlockWidget &other)
    :PaintedWidget(other.parentWidget()
    ,other.litTexture),litTexture(other.litTexture),unlitTexture(other.unlitTexture),playerTexture(other.playerTexture)
    ,blockData(other.blockData)
{
}

AbstractGameBlockWidget AbstractGameBlockWidget::operator=(const AbstractGameBlockWidget &other)
{
    return AbstractGameBlockWidget(other);
}

const QPixmap &AbstractGameBlockWidget::getLitTexture() const
{
    return litTexture;
}

const QPixmap &AbstractGameBlockWidget::getUnlitTexture() const
{
    return unlitTexture;
}

void AbstractGameBlockWidget::lit()
{
    setPixmap(litTexture);
}

void AbstractGameBlockWidget::unlit()
{
    setPixmap(unlitTexture);
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
    playerTexture = player.getPortrait();
    update();
}

void AbstractGameBlockWidget::onPlayerExited(const Player&)
{
    lit();
    update();
}
