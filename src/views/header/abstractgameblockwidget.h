#ifndef ABSTRACTGAMEBLOCKWIDGET_H
#define ABSTRACTGAMEBLOCKWIDGET_H

#include <QMap>
#include "paintedwidget.h"
#include "abstractgameblock.h"
#include "player.h"

class AbstractGameBlockWidget : public PaintedWidget
{
    Q_OBJECT

public:
    explicit AbstractGameBlockWidget(QWidget *parent,const AbstractGameBlock& blockData);

private:
    const AbstractGameBlock& blockData;
    QMap<AbstractGameBlock::LightLevel, QPixmap> textures;
    QPixmap playerTexture;

// TODO: MAKE PRIVATE
public slots:
    void onPlayerEntered(const Player& player);
    void onPlayerExited(const Player&);
    void onLightLevelChanged(const AbstractGameBlock::LightLevel& lightlevel);

protected:
    void loadTextures();
    void paintEvent(QPaintEvent* event) override;
};

#endif // ABSTRACTGAMEBLOCKWIDGET_H
