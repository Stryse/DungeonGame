#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <charactercreation.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //CTOR
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

      signals:

private slots:
    void openCharacterCreation();
    void showMenu();
private:

    Ui::MainWindow *ui;
    CharacterCreation* charCreateUI;

};
#endif // MAINWINDOW_H
