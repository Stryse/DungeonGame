#include "paintedwidget.h"
#include <QPainter>

PaintedWidget::PaintedWidget(QWidget *parent)
    : QWidget(parent)
{
}

PaintedWidget::PaintedWidget(QWidget *parent, const QPixmap &pixmap)
    : QWidget(parent), pixmap(pixmap)
{
}

void PaintedWidget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    pixmap = pixmap.scaledToWidth(width());
    const QSize pixSize = pixmap.size();
    const int x = (this->rect().width() - pixSize .width()) / 2.0;
    const int y = (this->rect().height() - pixSize .height()) / 2.0;

    p.drawPixmap(x,y,pixSize.width(),pixSize.height(),pixmap);
}

const QPixmap &PaintedWidget::getPixmap() const
{
    return pixmap;
}

void PaintedWidget::setPixmap(const QString& path)
{
    pixmap.load(path);
}

void PaintedWidget::setPixmap(const QPixmap &pxmap)
{
    pixmap = pxmap;
}
