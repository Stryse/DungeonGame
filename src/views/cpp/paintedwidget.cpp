#include "paintedwidget.h"
#include <QPainter>

PaintedWidget::PaintedWidget(QWidget *parent)
    : QWidget(parent)
{
}

void PaintedWidget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.drawPixmap(geometry().x()-20,geometry().y()-20,geometry().width(),geometry().height(),pixmap);
}

const QPixmap &PaintedWidget::getPixmap() const
{
    return pixmap;
}

void PaintedWidget::setPixmap(const QString& path)
{
    pixmap.load(path);
}
