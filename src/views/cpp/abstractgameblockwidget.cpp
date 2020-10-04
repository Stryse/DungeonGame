#include "abstractgameblockwidget.h"

AbstractGameBlockWidget::AbstractGameBlockWidget(QWidget *parent, const QPixmap& litTexture, const QPixmap& unlitTexture)
    :PaintedWidget(parent,litTexture), litTexture(litTexture), unlitTexture(unlitTexture)
{
}

AbstractGameBlockWidget::AbstractGameBlockWidget(const AbstractGameBlockWidget &other)
    :PaintedWidget(other.parentWidget(),other.litTexture),litTexture(other.litTexture),unlitTexture(other.unlitTexture)
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
