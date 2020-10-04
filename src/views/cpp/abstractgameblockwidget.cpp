#include "abstractgameblockwidget.h"
#include <QPainter>

AbstractGameBlockWidget::AbstractGameBlockWidget(      QWidget *parent,
                                                 const QPixmap& litTexture,
                                                 const QPixmap& unlitTexture,
                                                 /*const*/ AbstractGameBlock& blockData,
                                                 QPixmap* playerTexture)
    :PaintedWidget(parent,litTexture)
    ,litTexture(litTexture), unlitTexture(unlitTexture),playerTexture(playerTexture)
    ,blockData(blockData)
{
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

void AbstractGameBlockWidget::setPlayerTexture(QPixmap *portrait)
{
    playerTexture = portrait;
}

void AbstractGameBlockWidget::paintEvent(QPaintEvent* event)
{
    if(!blockData.getHasPlayer())
        PaintedWidget::paintEvent(event);
    else
    {
        PaintedWidget::paintEvent(event);
        QPainter p(&getPixmap());
        QPixmap scaledPortrait = playerTexture->scaledToWidth(getPixmap().width()*0.8,Qt::SmoothTransformation);
        int x = (getPixmap().width()-scaledPortrait.width()) / 2;
        int y = (getPixmap().height()-scaledPortrait.height()) / 2;
        p.drawPixmap(x,y,scaledPortrait.width(),scaledPortrait.height(),scaledPortrait);
        update();
    }
}

void AbstractGameBlockWidget::playerEntered(const Player* player)
{
    blockData.setHasPlayer(true);
    //playerTexture = player->getPortrait();
}
