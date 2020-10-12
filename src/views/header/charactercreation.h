#ifndef CHARACTERCREATION_H
#define CHARACTERCREATION_H

#include <QWidget>
#include <QPixmap>
#include "charactercreationmodel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class char_create_widget; }
QT_END_NAMESPACE


class CharacterCreation : public QWidget
{
    Q_OBJECT

public:
    //CTOR
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
    void connectPlayerName();
    void connectPlayerPortrait();
    void connectPlayerStrength();
    void connectPlayerIntellect();
    void connectPlayerStamina();

};

#endif // CHARACTERCREATION_H
