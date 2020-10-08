#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "charactercreation.h"
#include "gamefieldui.h"
#include "gameloader.h"

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

private slots:
    void openCharacterCreation();
    void openLoadGame();
    void showMenu();
    void updateViewPort(QDialog* w);
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
