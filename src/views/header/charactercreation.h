#ifndef CHARACTERCREATION_H
#define CHARACTERCREATION_H

#include <QDialog>
#include <QPixmap>
#include <QScopedPointer>

QT_BEGIN_NAMESPACE
namespace Ui { class char_create_widget; }
QT_END_NAMESPACE

class CharacterCreation : public QDialog
{
    Q_OBJECT
public:
    explicit CharacterCreation(QWidget *parent = nullptr);
    virtual ~CharacterCreation() override;

signals:

protected:
    void paintEvent(QPaintEvent *);

private:
    Ui::char_create_widget *ui;

    QVector<QPixmap> playerPortraits;
};

#endif // CHARACTERCREATION_H
