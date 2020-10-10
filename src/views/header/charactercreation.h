#ifndef CHARACTERCREATION_H
#define CHARACTERCREATION_H

#include <QDialog>
#include <QPixmap>
#include "charactercreationmodel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class char_create_widget; }
QT_END_NAMESPACE

class CharacterCreation : public QDialog
{
    Q_OBJECT

public:
    explicit CharacterCreation(QWidget *parent);
    virtual ~CharacterCreation() override;

protected:
    void paintEvent(QPaintEvent *) override;

private:
    Ui::char_create_widget *ui;
    CharacterCreationModel* charCreateModel;
    QVector<QString> playerPortraitsPaths;
    int activePortraitInd;

private slots:
    void connectPLayerPortrait();
    void connectPlayerStrength();
    void connectPlayerIntellect();
    void connectPlayerStamina();

};

#endif // CHARACTERCREATION_H
