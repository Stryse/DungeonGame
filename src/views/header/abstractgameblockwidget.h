#ifndef ABSTRACTGAMEBLOCKWIDGET_H
#define ABSTRACTGAMEBLOCKWIDGET_H

#include "paintedwidget.h"
#include "abstractgameblock.h"

class AbstractGameBlockWidget : public PaintedWidget
{
    Q_OBJECT

public:
    explicit AbstractGameBlockWidget(QWidget *parent, const QPixmap& litTexture, const QPixmap& unlitTexture);
    AbstractGameBlockWidget(const AbstractGameBlockWidget& other);
    AbstractGameBlockWidget operator=(const AbstractGameBlockWidget& other);

    const QPixmap &getLitTexture() const;
    const QPixmap &getUnlitTexture() const;
    //void lit();
    //void unlit();

signals:


private:
    const QPixmap& litTexture;
    const QPixmap& unlitTexture;
    AbstractGameBlock* blockData;
};

#endif // ABSTRACTGAMEBLOCKWIDGET_H
