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
                                     const QPixmap& unlitTexture, /*const*/ AbstractGameBlock& blockData,
                                     QPixmap* playerTexture = nullptr);

             AbstractGameBlockWidget(const AbstractGameBlockWidget& other);
             AbstractGameBlockWidget operator=(const AbstractGameBlockWidget& other);


    const QPixmap &getLitTexture() const;
    const QPixmap &getUnlitTexture() const;
    void lit();
    void unlit();
    void setPlayerTexture(QPixmap* portrait);

signals:

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    const QPixmap& litTexture;
    const QPixmap& unlitTexture;
    QPixmap* playerTexture;
    /*const*/AbstractGameBlock& blockData;

// TODO: MAKE PRIVATE
public slots:
    void playerEntered(const Player* player);

};

#endif // ABSTRACTGAMEBLOCKWIDGET_H
