#ifndef CHARACTERCREATION_H
#define CHARACTERCREATION_H

#include <QObject>
#include <QWidget>
#include <QStyleOption>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class char_create_widget; }
QT_END_NAMESPACE

class CharacterCreation : public QWidget
{
    Q_OBJECT
public:
    explicit CharacterCreation(QWidget *parent = nullptr);
    ~CharacterCreation();

signals:

protected:
    void paintEvent(QPaintEvent *);

private:
    Ui::char_create_widget *ui;

};

#endif // CHARACTERCREATION_H
