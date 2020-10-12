#ifndef PAINTEDWIDGET_H
#define PAINTEDWIDGET_H

#include <QWidget>
#include <QPixmap>

//Widget with painted background
class PaintedWidget : public QWidget
{
    Q_OBJECT
public:

    //CTOR
    explicit PaintedWidget(QWidget* parent);
    explicit PaintedWidget(QWidget* parent,const QPixmap& pixmap);

    //GETTER
    const QPixmap &getPixmap() const;
    QPixmap &getPixmap();

    //SETTER
    void setPixmap(const QString& path);
    void setPixmap(const QPixmap& pxmap);

protected:
    void paintEvent(QPaintEvent *);

private:
    QPixmap pixmap;

};

#endif // PAINTEDWIDGET_H
