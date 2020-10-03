#ifndef PAINTEDWIDGET_H
#define PAINTEDWIDGET_H

#include <QWidget>
#include <QPixmap>

class PaintedWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PaintedWidget(QWidget *parent);

    const QPixmap &getPixmap() const;
    void setPixmap(const QString& path);

signals:

protected:
    void paintEvent(QPaintEvent *);

private:
    QPixmap pixmap;

};

#endif // PAINTEDWIDGET_H
