#ifndef PAINTEDWIDGET_H
#define PAINTEDWIDGET_H

#include <QWidget>
#include <QPixmap>

class PaintedWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PaintedWidget(QWidget* parent);
    explicit PaintedWidget(QWidget* parent,const QPixmap& pixmap);

    const QPixmap &getPixmap() const;
    QPixmap &getPixmap();
    void setPixmap(const QString& path);
    void setPixmap(const QPixmap& pxmap);

signals:

protected:
    void paintEvent(QPaintEvent *);

private:
    QPixmap pixmap;

};

#endif // PAINTEDWIDGET_H
