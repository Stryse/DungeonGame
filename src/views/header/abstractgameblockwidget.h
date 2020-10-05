#ifndef ABSTRACTGAMEBLOCKWIDGET_H
#define ABSTRACTGAMEBLOCKWIDGET_H

#include "paintedwidget.h"
#include "abstractgameblock.h"
#include "player.h"

class AbstractGameBlockWidget : public PaintedWidget
{
    Q_OBJECT

public:
    explicit AbstractGameBlockWidget(QWidget *parent, const QPixmap& litTexture,
                                     const QPixmap& unlitTexture,const QPixmap& halfLitTexture,const AbstractGameBlock& blockData);

             AbstractGameBlockWidget(const AbstractGameBlockWidget& other);
             AbstractGameBlockWidget operator=(const AbstractGameBlockWidget& other);

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    const QPixmap& litTexture;
    const QPixmap& unlitTexture;
    const QPixmap& halfLitTexture;

    // TODO make it pointer
    QPixmap playerTexture;
    const AbstractGameBlock& blockData;

// TODO: MAKE PRIVATE
public slots:
    void onPlayerEntered(const Player& player);
    void onPlayerExited(const Player&);
    void onLightLevelChanged(const AbstractGameBlock::LightLevel& lightlevel);

};

#endif // ABSTRACTGAMEBLOCKWIDGET_H
