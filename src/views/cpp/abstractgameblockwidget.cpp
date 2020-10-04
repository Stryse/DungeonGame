#include "abstractgameblockwidget.h"

AbstractGameBlockWidget::AbstractGameBlockWidget(      QWidget *parent,
                                                 const QPixmap& litTexture,
                                                 const QPixmap& unlitTexture,
                                                 const AbstractGameBlock& blockData)
    :PaintedWidget(parent,litTexture)
    ,litTexture(litTexture), unlitTexture(unlitTexture)
    ,blockData(blockData)
{
}

AbstractGameBlockWidget::AbstractGameBlockWidget(const AbstractGameBlockWidget &other)
    :PaintedWidget(other.parentWidget()
    ,other.litTexture),litTexture(other.litTexture),unlitTexture(other.unlitTexture)
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
